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
	static const Typeface::Ptr Swiss721_CnBd{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCB_TTF, BinaryData::SWISSCB_TTFSize) };
	static const Typeface::Ptr Swiss721_Lt{ Typeface::createSystemTypefaceFor(BinaryData::SWISSL_TTF, BinaryData::SWISSL_TTFSize) };
	static const Typeface::Ptr Swiss721_LtCn{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCL_TTF, BinaryData::SWISSCL_TTFSize) };

	static const Font fontFor_BuildInfoText{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_Lt, 12.0f, 0.0f) };
	static const Font fontFor_ButtonText_Small{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CnBd, 14.0f, 0.0f) };
	static const Font fontFor_ButtonText_Large{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CnBd, 16.0f, 0.0f) };
	static const Font fontFor_ControlLabelText{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_LtCn, 12.0f, 0.0f) };
	static const Font fontFor_SectionHeaderText{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CnBd, 18.0f, 0.0f) };
	static const Font fontFor_SectionSubHeaderText{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CnBd, 16.0f, 0.0f) };
	static const Font fontFor_TooltipText{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_Bd, 13.0f, 0.0f) };
	static const Font fontFor_TrackingAndMatrixModNumbers{ FontCreator::createFontFromTypeface_Size_Kerning(Swiss721_CnBd, 13.0f, 0.0f) };
}

