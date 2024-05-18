#ifndef RINGBUF_H
#define RINGBUF_H

#include "os.h"

struct ringbuf
{
    uint8_t *buff;
    size_t size;
    uint8_t *head;
    uint8_t *tail;
    uint8_t is_full;
    osMutexId_t *mutex;
};

#define CREATE_RINGBUF(_name, _size) \
    CREATE_MUTEX(_name##_mutex);     \
    uint8_t _name##_buffer[_size];   \
    struct ringbuf _name = {         \
        .buff = _name##_buffer,      \
        .size = _size,               \
        .head = _name##_buffer,      \
        .tail = _name##_buffer,      \
        .is_full = 0,                \
        .mutex = &_name##_mutex,     \
    };                               \
    void init_##_name(void)          \
    {                                \
        init_##_name##_mutex();      \
    }

size_t ringbuf_get_size(struct ringbuf *r);
size_t ringbuf_get_msg_size(struct ringbuf *r);
int ringbuf_put(struct ringbuf *r, uint8_t *in_data, size_t size);
int ringbuf_get(struct ringbuf *r, uint8_t *out_data, size_t *size);

#endif // RINGBUF_H
