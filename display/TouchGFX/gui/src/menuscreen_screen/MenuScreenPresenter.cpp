#include <gui/menuscreen_screen/MenuScreenView.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

MenuScreenPresenter::MenuScreenPresenter(MenuScreenView& v)
    : view(v)
{

}

void MenuScreenPresenter::activate()
{

}

void MenuScreenPresenter::deactivate()
{

}

void MenuScreenPresenter::updateTime(unsigned hour, unsigned minute, unsigned second)
{
    view.updateTime(hour, minute, second);
}

void MenuScreenPresenter::UIGetTime(void)
{
    model->GetTime();
}