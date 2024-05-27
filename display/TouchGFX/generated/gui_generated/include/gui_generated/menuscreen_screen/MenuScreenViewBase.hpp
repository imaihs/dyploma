/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef MENUSCREENVIEWBASE_HPP
#define MENUSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/menuscreen_screen/MenuScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <gui/containers/topPanel.hpp>

class MenuScreenViewBase : public touchgfx::View<MenuScreenPresenter>
{
public:
    MenuScreenViewBase();
    virtual ~MenuScreenViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ClickButtonTrigger >  >  settingsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ClickButtonTrigger >  >  eventsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ClickButtonTrigger >  >  sensorsButton;
    touchgfx::TextButtonStyle< touchgfx::IconButtonStyle< touchgfx::ClickButtonTrigger >  >  homeButton;
    topPanel topPanel1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<MenuScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // MENUSCREENVIEWBASE_HPP
