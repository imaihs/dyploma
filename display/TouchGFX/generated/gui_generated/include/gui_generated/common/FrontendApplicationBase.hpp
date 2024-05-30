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
        gotoHomeScreenScreenNoTransition();
    }

    // HomeScreen
    void gotoHomeScreenScreenNoTransition();

    void gotoHomeScreenScreenSlideTransitionSouth();

    // MenuScreen
    void gotoMenuScreenScreenSlideTransitionNorth();

    void gotoMenuScreenScreenSlideTransitionWest();

    // SensorsScreen
    void gotoSensorsScreenScreenSlideTransitionEast();

    // EventsScreen
    void gotoEventsScreenScreenSlideTransitionEast();

    // SettingsScreen
    void gotoSettingsScreenScreenSlideTransitionEast();

    void gotoSettingsScreenScreenSlideTransitionWest();

    // TimeSettingsScreen
    void gotoTimeSettingsScreenScreenSlideTransitionEast();

protected:
    touchgfx::Callback<FrontendApplicationBase> transitionCallback;
    FrontendHeap& frontendHeap;
    Model& model;

    // HomeScreen
    void gotoHomeScreenScreenNoTransitionImpl();

    void gotoHomeScreenScreenSlideTransitionSouthImpl();

    // MenuScreen
    void gotoMenuScreenScreenSlideTransitionNorthImpl();

    void gotoMenuScreenScreenSlideTransitionWestImpl();

    // SensorsScreen
    void gotoSensorsScreenScreenSlideTransitionEastImpl();

    // EventsScreen
    void gotoEventsScreenScreenSlideTransitionEastImpl();

    // SettingsScreen
    void gotoSettingsScreenScreenSlideTransitionEastImpl();

    void gotoSettingsScreenScreenSlideTransitionWestImpl();

    // TimeSettingsScreen
    void gotoTimeSettingsScreenScreenSlideTransitionEastImpl();
};

#endif // FRONTENDAPPLICATIONBASE_HPP
