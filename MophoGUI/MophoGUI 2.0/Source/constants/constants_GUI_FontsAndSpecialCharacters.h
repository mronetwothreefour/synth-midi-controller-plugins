#pragma once

#include <JuceHeader.h>

struct FontBuilder {
	static Font createFontFromTypeface_Size_Kerning(Typeface::Ptr typeface, float size, float kerning) {
		Font font{ typeface };
		font.setSizeAndStyle(size, font.getTypefaceStyle(), 1.0f, kerning);
		return font;
	}
};

namespace MophoConstants 
{
	namespace GUI
	{
		const Typeface::Ptr Overpass_Bold{ Typeface::createSystemTypefaceFor(BinaryData::OverpassBold_ttf, BinaryData::OverpassBold_ttfSize) };

		const Font font_BrowserText{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 18.0f, 0.0f) };
		const Font font_DisplayLabels{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 15.0f, 0.0f) };
		const Font font_KnobValueDisplays{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 15.0f, 0.0f) };
		const Font font_Labels{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.5f, 0.0f) };
		const Font font_VoiceNameEditorText{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 21.0f, 0.0f) };
		const Font font_VoiceSlotButtons{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 16.0f, 0.0f) };
		const Font font_PopupMenuItems{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.5f, 0.0f) };
		const Font font_ProgressBar{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 14.0f, 0.0f) };
		const Font font_ProgressDisplayMessage{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 21.0f, 0.0f) };
		const Font font_PulseWidthText{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 11.0f, 0.0f) };
		const Font font_SeqSteps{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 13.5f, 0.0f) };
		const Font font_Tooltips{ FontBuilder::createFontFromTypeface_Size_Kerning(Overpass_Bold, 16.0f, 0.0f) };

		const String apostrophe{ CharPointer_UTF8("\xe2\x80\x99") };
		const String openQuote{ CharPointer_UTF8("\xe2\x80\x9c") };
		const String closeQuote{ CharPointer_UTF8("\xe2\x80\x9d") };
		const String yen{ CharPointer_UTF8("\xc2\xa5") };
	};
}
