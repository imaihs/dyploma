#include <gui/eventsscreen_screen/EventsScreenView.hpp>
#include <gui/eventsscreen_screen/EventsScreenPresenter.hpp>

EventsScreenPresenter::EventsScreenPresenter(EventsScreenView& v)
    : view(v)
{

}

void EventsScreenPresenter::activate()
{

}

void EventsScreenPresenter::deactivate()
{

}

void EventsScreenPresenter::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    view.updateTime(hour, minute, second);
}

void EventsScreenPresenter::UIGetTime(void)
{
    model->GetTime();
}
