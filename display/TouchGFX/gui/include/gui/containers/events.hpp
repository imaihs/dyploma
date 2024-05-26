#ifndef EVENTS_HPP
#define EVENTS_HPP

#include <gui_generated/containers/eventsBase.hpp>

class events : public eventsBase
{
public:
    events();
    virtual ~events() {}

    virtual void initialize();
protected:
};

#endif // EVENTS_HPP
