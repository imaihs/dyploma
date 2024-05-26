/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId INTERSEMIBOLD_28 = 0;
    static const touchgfx::FontId INTERSEMIBOLD_48 = 1;
    static const touchgfx::FontId INTERSEMIBOLD_150 = 2;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId INTERSEMIBOLD_28 = 0;  // inter_SemiBold_28_4bpp
    static const touchgfx::FontId INTERSEMIBOLD_48 = 1;  // inter_SemiBold_48_4bpp
    static const touchgfx::FontId INTERSEMIBOLD_150 = 2; // inter_SemiBold_150_4bpp
    static const uint16_t NUMBER_OF_FONTS = 3;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /*flashReader*/)
    {
    }

    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
