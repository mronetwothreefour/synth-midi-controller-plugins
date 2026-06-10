#pragma once

#include <JuceHeader.h>

struct FONT
{
	static const FontOptions bold() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::SWISSB_TTF, BinaryData::SWISSB_TTFSize) };
	}

	static const FontOptions cond_black() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCK_TTF, BinaryData::SWISSCK_TTFSize) };
	}

	static const FontOptions cond_light() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCL_TTF, BinaryData::SWISSCL_TTFSize) };
	}

	static const Font file_browser(const float scale_factor) {
		return Font{ bold() }.withPointHeight(14.0f * scale_factor);
	}

	static const Font knob(const float scale_factor) {
		return Font{ cond_black() }.withPointHeight(12.0f * scale_factor);
	}

	static const Font txt_edit_led(const float scale_factor) {
		return Font{ bold() }.withPointHeight(34.0f * scale_factor);
	}
};
