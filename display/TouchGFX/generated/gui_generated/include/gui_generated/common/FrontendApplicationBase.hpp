/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef FRONTENDAPPLICATIONBASE_HPP
#define FRONTENDAPPLICATIONBASE_HPP

#include <mvp/MVPApplication.hpp>
#include <gui/model/Model.hpp>

class FrontendHeap;

class FrontendApplicationBase : public touchgfx::MVPApplication
{
public:
    FrontendApplicationBase(Model& m, FrontendHeap& heap);
    virtual ~FrontendApplicationBase() { }

    virtual void changeToStartScreen()
    {
        gotoMenuScreenScreenNoTransition();
    }

    // MenuScreen
    void gotoMenuScreenScreenNoTransition();

    // HomeScreen
    void gotoHomeScreenScreenNoTransition();

    // SensorsScreen
    void gotoSensorsScreenScreenNoTransition();

    // EventsScreen
    void gotoEventsScreenScreenNoTransition();

    // SettingsScreen
    void gotoSettingsScreenScreenNoTransition();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // MenuScreen
    void gotoMenuScreenScreenNoTransitionImpl();

    // HomeScreen
    void gotoHomeScreenScreenNoTransitionImpl();

    // SensorsScreen
    void gotoSensorsScreenScreenNoTransitionImpl();

    // EventsScreen
    void gotoEventsScreenScreenNoTransitionImpl();

    // SettingsScreen
    void gotoSettingsScreenScreenNoTransitionImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
