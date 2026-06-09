#pragma once

#include <JuceHeader.h>

struct FONT
{
	static const FontOptions bold() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::OVERPASSBOLD_TTF, BinaryData::OVERPASSBOLD_TTFSize) };
	}

	static const Font file_browser(const float scale_factor) {
		return Font{ bold() }.withPointHeight(14.0f * scale_factor);
	}

	static const Font disp_editor(const float scale_factor) {
		return Font{ bold() }.withPointHeight(13.0f * scale_factor);
	}
};