/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SENSORSSCREENVIEWBASE_HPP
#define SENSORSSCREENVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/sensorsscreen_screen/SensorsScreenPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>
#include <gui/containers/topPanel.hpp>
#include <touchgfx/widgets/Image.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class SensorsScreenViewBase : public touchgfx::View<SensorsScreenPresenter>
{
public:
    SensorsScreenViewBase();
    virtual ~SensorsScreenViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::ImageButtonStyle< touchgfx::ClickButtonTrigger >  goBack;
    topPanel topPanel1;
    touchgfx::Image presIcon;
    touchgfx::Image humIcon;
    touchgfx::Image tempIcon;
    touchgfx::TextAreaWithTwoWildcards presText;
    touchgfx::TextAreaWithTwoWildcards humText;
    touchgfx::TextAreaWithTwoWildcards tempText;

    /*
     * Wildcard Buffers
     */
    static const uint16_t PRESTEXTBUFFER1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar presTextBuffer1[PRESTEXTBUFFER1_SIZE];
    static const uint16_t PRESTEXTBUFFER2_SIZE = 5;
    touchgfx::Unicode::UnicodeChar presTextBuffer2[PRESTEXTBUFFER2_SIZE];
    static const uint16_t HUMTEXTBUFFER1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar humTextBuffer1[HUMTEXTBUFFER1_SIZE];
    static const uint16_t HUMTEXTBUFFER2_SIZE = 5;
    touchgfx::Unicode::UnicodeChar humTextBuffer2[HUMTEXTBUFFER2_SIZE];
    static const uint16_t TEMPTEXTBUFFER1_SIZE = 5;
    touchgfx::Unicode::UnicodeChar tempTextBuffer1[TEMPTEXTBUFFER1_SIZE];
    static const uint16_t TEMPTEXTBUFFER2_SIZE = 5;
    touchgfx::Unicode::UnicodeChar tempTextBuffer2[TEMPTEXTBUFFER2_SIZE];

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<SensorsScreenViewBase, const touchgfx::AbstractButtonContainer&> flexButtonCallback;

    /*
     * Callback Handler Declarations
     */
    void flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src);

};

#endif // SENSORSSCREENVIEWBASE_HPP