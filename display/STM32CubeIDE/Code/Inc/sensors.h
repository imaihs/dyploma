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

#endif // SENSORS_H
