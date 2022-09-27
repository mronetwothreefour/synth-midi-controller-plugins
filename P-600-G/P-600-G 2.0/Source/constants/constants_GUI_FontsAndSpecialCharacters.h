#pragma once

#include <JuceHeader.h>

struct FontCreator {
	static Font createFontFromTypeface_Size_Kerning(Typeface::Ptr typeface, float size, float kerning) {
		Font font{ typeface };
		font.setSizeAndStyle(size, font.getTypefaceStyle(), 1.0f, kerning);
		return font;
	}
};

namespace P_600_G_Constants
{
	namespace GUI
	{
		static const Typeface::Ptr Swiss721_Bd{ Typeface::createSystemTypefaceFor(BinaryData::SWISSB_TTF, BinaryData::SWISSB_TTFSize) };
		static const Typeface::Ptr Swiss721_CndBk{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCK_TTF, BinaryData::SWISSCK_TTFSize) };
		static const Typeface::Ptr Swiss721_CndLt{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCL_TTF, BinaryData::SWISSCL_TTFSize) };

		static const Font font_BrowserText{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 16.0f, 0.0f) };
		static const Font font_KnobValueDisplay{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CndBk, 14.0f, 0.0f) };
		static const Font font_VoiceSlotRadioButtons{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CndBk, 13.0f, 0.0f) };
		static const Font font_Tooltips{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 13.0f, 0.0f) };
		static const Font font_VoiceNumAndTxTimeEditors{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 36.0f, 0.0f) };

		static const String apostrophe{ CharPointer_UTF8("\xe2\x80\x99") };
		static const String openQuote{ CharPointer_UTF8("\xe2\x80\x9c") };
		static const String closeQuote{ CharPointer_UTF8("\xe2\x80\x9d") };
	}
}
