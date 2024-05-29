#include <gui/settingsscreen_screen/SettingsScreenView.hpp>
#include <gui/settingsscreen_screen/SettingsScreenPresenter.hpp>

SettingsScreenPresenter::SettingsScreenPresenter(SettingsScreenView& v)
    : view(v)
{

}

void SettingsScreenPresenter::activate()
{

}

void SettingsScreenPresenter::deactivate()
{

}

void SettingsScreenPresenter::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    view.updateTime(hour, minute, second);
}

void SettingsScreenPresenter::UIGetTime(void)
{
    model->GetTime();
}