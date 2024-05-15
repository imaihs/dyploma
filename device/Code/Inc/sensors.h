#ifndef SENSORS_H
#define SENSORS_H

struct temperature
{
    int temp;
    uint8_t temp_float;
};

struct humidity
{
    int hum;
    uint8_t hum_float;
};

struct pressure
{
    int pres;
    uint8_t pres_float;
};

void start_temperature_task(void);
void start_humidity_task(void);
void start_pressure_task(void);

#endif // SENSORS_H
