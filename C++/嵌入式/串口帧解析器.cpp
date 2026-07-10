#include <stdint.h>

//帧格式 [0x55] [0xAA] [Len] [Cmd] [Data × Len] [CRC_L] [CRC_H]
//接口 void Protocol_Parser_Input(uint8_t byte);
//状态机 SOF1 → SOF2 → LEN → CMD → DATA → CRC1 → CRC2 → 回 SOF1

typedef enum {
    SOF1,
    SOF2,
    LEN,
    CMD,
    DATA,
    CRC1,
    CRC2
} ParserState_t;

const int data_buffer_size = 128;

typedef struct {
    uint8_t length;
    uint8_t cmd_command;
    uint8_t data[data_buffer_size];
    uint8_t write_index;
    uint8_t read_index;
} MyFrame_t;

ParserState_t state = SOF1;
MyFrame_t frame;

// 对 Len + Cmd + Data 做 Modbus CRC16（多项式 0xA001，初值 0xFFFF）
static uint16_t Check_CRC16(const MyFrame_t* f)
{
    uint16_t crc = 0xFFFF;
    uint8_t buf[2 + data_buffer_size];
    uint16_t n = 0;

    buf[n++] = f->length;
    buf[n++] = f->cmd_command;
    for (uint8_t i = 0; i < f->length; i++) {
        buf[n++] = f->data[i];
    }

    for (uint16_t i = 0; i < n; i++) {
        crc ^= buf[i];
        for (uint8_t b = 0; b < 8; b++) {
            if (crc & 0x0001) {
                crc = (crc >> 1) ^ 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}

// CRC 通过后的业务入口（手撕可先空实现）
void On_Frame_OK(MyFrame_t* f)
{
    (void)f;
    // 按 f->cmd_command 分发业务
}

void Protocol_Parser_Input(uint8_t byte)
{
    static uint8_t data_count = 0;
    static uint8_t CRC_low = 0;

    switch (state) {
    case SOF1:
        if (byte == 0x55) {
            state = SOF2;
        }
        // 新帧起点：清本帧缓存与计数
        data_count = 0;
        CRC_low = 0;
        frame.length = 0;
        frame.cmd_command = 0;
        frame.write_index = 0;
        break;

    case SOF2:
        if (byte == 0xAA) {
            state = LEN;
        } else if (byte == 0x55) {
            // 当前字节又是帧头第一字节，留在 SOF2 等 0xAA
            state = SOF2;
        } else {
            state = SOF1;
        }
        break;

    case LEN:
        // Len 只表示 Data 字节数；过大则丢弃重同步
        if (byte > data_buffer_size) {
            state = SOF1;
            break;
        }
        frame.length = byte;
        state = CMD;
        break;

    case CMD:
        frame.cmd_command = byte;
        // Len==0：无 Data，仍有 Cmd，然后直接进 CRC
        if (frame.length == 0) {
            state = CRC1;
        } else {
            state = DATA;
        }
        break;

    case DATA:
        // 当前 byte 一定是 Data；收满后再切到 CRC1，下一字节才是 CRC_L
        frame.data[frame.write_index++] = byte;
        data_count++;
        if (data_count >= frame.length) {
            state = CRC1;
        }
        break;

    case CRC1:
        CRC_low = byte;
        state = CRC2;
        break;

    case CRC2: {
        uint16_t recv_crc = (uint16_t)CRC_low | ((uint16_t)byte << 8);
        uint16_t calc_crc = Check_CRC16(&frame);
        if (calc_crc == recv_crc) {
            On_Frame_OK(&frame);
        }
        // 无论成败都回 SOF1，准备下一帧（粘包时下一字节继续喂）
        state = SOF1;
        break;
    }

    default:
        state = SOF1;
        break;
    }
}
