#ifndef EVENTSSCREENPRESENTER_HPP
#define EVENTSSCREENPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EventsScreenView;

class EventsScreenPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    EventsScreenPresenter(EventsScreenView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~EventsScreenPresenter() {}

private:
    EventsScreenPresenter();

    EventsScreenView& view;
};

#endif // EVENTSSCREENPRESENTER_HPP
