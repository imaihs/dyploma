#include <gui/timesettingsscreen_screen/TimeSettingsScreenView.hpp>
#include <gui/timesettingsscreen_screen/TimeSettingsScreenPresenter.hpp>

TimeSettingsScreenPresenter::TimeSettingsScreenPresenter(TimeSettingsScreenView& v)
    : view(v)
{

}

void TimeSettingsScreenPresenter::activate()
{

}

void TimeSettingsScreenPresenter::deactivate()
{

}

void TimeSettingsScreenPresenter::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    view.updateTime(hour, minute, second);
}

void TimeSettingsScreenPresenter::peekTime(unsigned hour, unsigned minute, unsigned second)
{
    view.peekTime(hour, minute, second);
}

void TimeSettingsScreenPresenter::UIGetTime(void)
{
    model->GetTime();
}

void TimeSettingsScreenPresenter::UISetTime(unsigned hour, unsigned minute, unsigned second)
{
    model->SetTime(hour, minute, second);
}

void TimeSettingsScreenPresenter::peekDate(unsigned week, unsigned day, unsigned month, unsigned year)
{
    view.peekDate(week, day, month, year);
}

void TimeSettingsScreenPresenter::UIGetDate(void)
{
    model->GetDate();
}

void TimeSettingsScreenPresenter::UISetDate(unsigned day, unsigned month, unsigned year)
{
    model->SetDate(day, month, year);
}
