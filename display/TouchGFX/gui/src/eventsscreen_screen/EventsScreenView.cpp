#include <gui/eventsscreen_screen/EventsScreenView.hpp>

EventsScreenView::EventsScreenView()
{

}

void EventsScreenView::setupScreen()
{
    EventsScreenViewBase::setupScreen();
    presenter->UIGetTime();
}

void EventsScreenView::tearDownScreen()
{
    EventsScreenViewBase::tearDownScreen();
}

void EventsScreenView::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    topPanel1.updateTime(hour, minute, second);
}