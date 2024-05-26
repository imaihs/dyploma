#ifndef SENSORS_HPP
#define SENSORS_HPP

#include <gui_generated/containers/sensorsBase.hpp>

class sensors : public sensorsBase
{
public:
    sensors();
    virtual ~sensors() {}

    virtual void initialize();
protected:
};

#endif // SENSORS_HPP
