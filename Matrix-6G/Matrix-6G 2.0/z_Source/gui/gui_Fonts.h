#pragma once

#include <JuceHeader.h>



struct FontCreator {
	static Font createFontFromTypeface_Size_Kerning(Typeface::Ptr typeface, float size, float kerning) {
		Font font{ typeface };
		font.setSizeAndStyle(size, font.getTypefaceStyle(), 1.0f, kerning);
		return font;
	}
};

namespace FontsMenu
{
	static const Typeface::Ptr Swiss721_Bd{ Typeface::createSystemTypefaceFor(BinaryData::SWISSB_TTF, BinaryData::SWISSB_TTFSize) };
	static const Typeface::Ptr Swiss721_CndLt{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCL_TTF, BinaryData::SWISSCL_TTFSize) };

	static const Font fontFor_LabelEditors{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 16.0f, 0.0f) };
	static const Font fontFor_VoiceAndSplitSlotRadioButtons{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CndLt, 13.0f, 0.0f) };
	static const Font fontFor_TooltipText{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 13.0f, 0.0f) };
}

