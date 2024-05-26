#ifndef SENSORS_H
#define SENSORS_H

struct temperature
{
    int temp;
    unsigned temp_float;
};

struct humidity
{
    int hum;
    unsigned hum_float;
};

struct pressure
{
    int pres;
    unsigned pres_float;
};

struct sensors
{
    struct temperature t;
    struct humidity h;
    struct pressure p;
};

struct sensors sensors_get_data(void);

#endif // SENSORS_H
