#define RING_BUFFER_SIZE 64

typedef struct {
    uint8_t buffer[RING_BUFFER_SIZE];
    uint16_t head;
    uint16_t tail;
} ring_buffer_t;


void ring_buffer_init(ring_buffer_t *ring_buffer)
{
    memset(ring_buffer->buffer, 0, RING_BUFFER_SIZE);
    ring_buffer->head = 0;
    ring_buffer->tail = 0;
}


bool ring_buffer_is_empty(ring_buffer_t *ring_buffer)
{
    if(ring_buffer->head == ring_buffer->tail)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ring_buffer_is_full(ring_buffer_t *ring_buffer)
{
    if((ring_buffer->tail + 1) % RING_BUFFER_SIZE == ring_buffer->head) //注意是否越界,也就是追上了head
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ring_buffer_push(ring_buffer_t *ring_buffer, uint8_t data)
{
    if(ring_buffer_is_full(ring_buffer))
    {
        return false;
    }
    else
    {
        ring_buffer->buffer[ring_buffer->tail] = data;
        ring_buffer->tail = (ring_buffer->tail + 1) % RING_BUFFER_SIZE;
        return true;
    }
}

bool ring_buffer_pop(ring_buffer_t *ring_buffer, uint8_t *data)
{
    if(ring_buffer_is_empty(ring_buffer))
    {
        return false;
    }
    else
    {
        *data = ring_buffer->buffer[ring_buffer->head];
        ring_buffer->head = (ring_buffer->head + 1) % RING_BUFFER_SIZE;
        return true;
    }
}