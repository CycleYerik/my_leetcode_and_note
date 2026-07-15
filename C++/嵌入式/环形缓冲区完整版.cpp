#include <iostream>
#include <cstring>
#include <cstdint>

using namespace std;


#define RB_CAP 8   /* 实际可存 7 个元素 */

typedef struct {
    uint8_t buf[RB_CAP];
    uint16_t head;
    uint16_t tail;
    /* 可选：uint16_t count;  若你用 count 判满/空，CAP 可存满 8 个，二选一写清楚 */
} ringbuf_t;

void rb_init(ringbuf_t *rb)
{
    memset(rb->buf,0,RB_CAP);
    rb->head = 0;
    rb->tail = 0;
}

bool rb_is_empty(const ringbuf_t *rb)
{
    if(rb->head == rb->tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool rb_is_full(const ringbuf_t *rb)
{
    if( (rb->tail + 1) % RB_CAP == rb->head)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/* 成功返回 true；满/空返回 false，不修改队列 */
bool rb_push(ringbuf_t *rb, uint8_t byte)
{
    if(rb_is_full(rb))
    {
        return false;
    }
    else
    {
        rb->buf[rb->tail] = byte;
        rb->tail = (rb->tail + 1 ) % RB_CAP;
        return true;
    }
}


bool rb_pop(ringbuf_t *rb, uint8_t *out_byte)
{
    if(rb_is_empty(rb))
    {
        return false;
    }
    else 
    {
        *out_byte = rb->buf[rb->head];
        rb->head = (rb->head + 1) % RB_CAP;
        return true;
    }
}