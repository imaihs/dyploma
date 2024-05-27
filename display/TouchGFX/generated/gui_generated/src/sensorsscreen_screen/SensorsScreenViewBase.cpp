/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/sensorsscreen_screen/SensorsScreenViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

SensorsScreenViewBase::SensorsScreenViewBase() :
    flexButtonCallback(this, &SensorsScreenViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 800, 480);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    goBack.setBitmaps(Bitmap(BITMAP_BACK_ICON_ID), Bitmap(BITMAP_BACK_ICON_ID));
    goBack.setBitmapXY(0, 0);
    goBack.setAction(flexButtonCallback);
    goBack.setPosition(25, 223, 50, 35);
    add(goBack);

    topPanel1.setXY(0, 0);
    add(topPanel1);

    presIcon.setXY(255, 340);
    presIcon.setBitmap(touchgfx::Bitmap(BITMAP_PRESSURE_ICON_ID));
    add(presIcon);

    humIcon.setXY(264, 240);
    humIcon.setBitmap(touchgfx::Bitmap(BITMAP_HUMIDITY_ICON_ID));
    add(humIcon);

    tempIcon.setXY(259, 140);
    tempIcon.setBitmap(touchgfx::Bitmap(BITMAP_TEMPERATURE_ICON_ID));
    add(tempIcon);

    presText.setPosition(400, 347, 300, 58);
    presText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    presText.setLinespacing(0);
    touchgfx::Unicode::snprintf(presTextBuffer1, PRESTEXTBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_0X01).getText());
    presText.setWildcard1(presTextBuffer1);
    touchgfx::Unicode::snprintf(presTextBuffer2, PRESTEXTBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_35RA).getText());
    presText.setWildcard2(presTextBuffer2);
    presText.setTypedText(touchgfx::TypedText(T_PRESSURE));
    add(presText);

    humText.setPosition(400, 247, 300, 58);
    humText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    humText.setLinespacing(0);
    touchgfx::Unicode::snprintf(humTextBuffer1, HUMTEXTBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_DIGX).getText());
    humText.setWildcard1(humTextBuffer1);
    touchgfx::Unicode::snprintf(humTextBuffer2, HUMTEXTBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_0K24).getText());
    humText.setWildcard2(humTextBuffer2);
    humText.setTypedText(touchgfx::TypedText(T_HUMIDITY));
    add(humText);

    tempText.setPosition(400, 145, 300, 58);
    tempText.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    tempText.setLinespacing(0);
    touchgfx::Unicode::snprintf(tempTextBuffer1, TEMPTEXTBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_3YWQ).getText());
    tempText.setWildcard1(tempTextBuffer1);
    touchgfx::Unicode::snprintf(tempTextBuffer2, TEMPTEXTBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_24RJ).getText());
    tempText.setWildcard2(tempTextBuffer2);
    tempText.setTypedText(touchgfx::TypedText(T_TEMPERATURE));
    add(tempText);
}

SensorsScreenViewBase::~SensorsScreenViewBase()
{

}

void SensorsScreenViewBase::setupScreen()
{
    topPanel1.initialize();
}

void SensorsScreenViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &goBack)
    {
        //GoBackInteraction
        //When goBack clicked change screen to MenuScreen
        //Go to MenuScreen with screen transition towards West
        application().gotoMenuScreenScreenSlideTransitionWest();
    }
}