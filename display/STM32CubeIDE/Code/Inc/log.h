#ifndef LOG_H
#define LOG_H

#define LOG_BUFFER_SIZE 512
#define LOG_MAX_SIZE 128

void LOG(const char *format, ...);

void log_init(void);
void log_txcplt_cb(void);
void start_log_task(void);

#endif // LOG_H
