#ifndef EVENTSSCREENVIEW_HPP
#define EVENTSSCREENVIEW_HPP

#include <gui_generated/eventsscreen_screen/EventsScreenViewBase.hpp>
#include <gui/eventsscreen_screen/EventsScreenPresenter.hpp>

class EventsScreenView : public EventsScreenViewBase
{
public:
    EventsScreenView();
    virtual ~EventsScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // EVENTSSCREENVIEW_HPP
