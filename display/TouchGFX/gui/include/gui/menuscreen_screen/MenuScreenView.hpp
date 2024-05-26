#ifndef MENUSCREENVIEW_HPP
#define MENUSCREENVIEW_HPP

#include <gui_generated/menuscreen_screen/MenuScreenViewBase.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>

class MenuScreenView : public MenuScreenViewBase
{
public:
    MenuScreenView();
    virtual ~MenuScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void homeClickHandler(const home& h, const ClickEvent& e);
    void sensorsClickHandler(const sensors& h, const ClickEvent& e);
    void eventsClickHandler(const events& h, const ClickEvent& e);
    void settingsClickHandler(const settings& h, const ClickEvent& e);
protected:
    Callback<MenuScreenView, const home&, const ClickEvent&> homeClickedCallback;
    Callback<MenuScreenView, const sensors&, const ClickEvent&> sensorsClickedCallback;
    Callback<MenuScreenView, const events&, const ClickEvent&> eventsClickedCallback;
    Callback<MenuScreenView, const settings&, const ClickEvent&> settingsClickedCallback;
};

#endif // MENUSCREENVIEW_HPP
