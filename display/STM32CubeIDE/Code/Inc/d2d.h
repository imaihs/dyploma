#ifndef D2D_H
#define D2D_H

#define D2D_MAX_PKT_LEN 128

struct d2d_header
{
    uint8_t crc;
    uint8_t flags;
    uint8_t len;
    uint8_t seq;
} __attribute__((packed));

struct d2d_body
{
    uint8_t crc;
    uint8_t buf[D2D_MAX_PKT_LEN];
} __attribute__((packed));

union d2d_payload
{
    struct
    {
        struct d2d_header header;
        struct d2d_body body;
    };
    uint8_t data[sizeof(struct d2d_header) + sizeof(struct d2d_body)];
} __attribute__((packed));

void start_d2d_task(void);

#endif // D2D_H
