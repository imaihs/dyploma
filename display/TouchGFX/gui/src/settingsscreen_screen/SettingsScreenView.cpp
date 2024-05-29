#include <gui/settingsscreen_screen/SettingsScreenView.hpp>

SettingsScreenView::SettingsScreenView()
{

}

void SettingsScreenView::setupScreen()
{
    SettingsScreenViewBase::setupScreen();
    presenter->UIGetTime();
}

void SettingsScreenView::tearDownScreen()
{
    SettingsScreenViewBase::tearDownScreen();
}

void SettingsScreenView::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    topPanel1.updateTime(hour, minute, second);
}
