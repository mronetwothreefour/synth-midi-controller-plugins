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
	static const Typeface::Ptr Overpass_Bold{ Typeface::createSystemTypefaceFor(BinaryData::OverpassBold_ttf, BinaryData::OverpassBold_ttfSize) };

	static const Font fontFor_DisplayLabels{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 15.0f, 0.0f) };
	static const Font fontFor_KnobValueDisplays{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 15.0f, 0.0f) };
	static const Font fontFor_Labels{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.5f, 0.0f) };
	static const Font fontFor_PgmNameEditorText{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 21.0f, 0.0f) };
	static const Font fontFor_PgmSlotButtons{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 16.0f, 0.0f) };
	static const Font fontFor_PopupMenuItems{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.5f, 0.0f) };
	static const Font fontFor_ProgressBar{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.0f, 0.0f) };
	static const Font fontFor_ProgressDisplayMessage{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 21.0f, 0.0f) };
	static const Font fontFor_PulseWidthText{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 11.0f, 0.0f) };
	static const Font fontFor_SeqSteps{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 13.5f, 0.0f) };
	static const Font fontFor_Tooltips{ FontCreator::createFontFromTypeface_Size_Kerning(Overpass_Bold, 16.0f, 0.0f) };
};
