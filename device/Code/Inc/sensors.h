#ifndef SENSORS_H
#define SENSORS_H

struct temperature {
    int temp;
    uint8_t temp_float;
};

void start_temperature_task(void);

#endif // SENSORS_H
