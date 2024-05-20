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

struct sensors
{
    struct temperature t;
    struct humidity h;
    struct pressure p;
};

void start_temperature_task(void);
void start_humidity_task(void);
void start_pressure_task(void);
struct sensors get_sensors_data(void);
void init_sensors_mutex(void);

#endif // SENSORS_H
