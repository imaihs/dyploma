#include <gui/homescreen_screen/HomeScreenView.hpp>
#include <gui/homescreen_screen/HomeScreenPresenter.hpp>

HomeScreenPresenter::HomeScreenPresenter(HomeScreenView& v)
    : view(v)
{

}

void HomeScreenPresenter::activate()
{

}

void HomeScreenPresenter::deactivate()
{

}

void HomeScreenPresenter::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    view.updateTime(hour, minute, second);
}

void HomeScreenPresenter::UIGetTime(void)
{
    model->GetTime();
}

void HomeScreenPresenter::updateDate(unsigned week, unsigned day, unsigned month, unsigned year)
{
    view.updateDate(week, day, month, year);
}

void HomeScreenPresenter::UIGetDate(void)
{
    model->GetDate();
}