#pragma once

#include <JuceHeader.h>

struct FONT
{
	static const FontOptions bold() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::OVERPASSBOLD_TTF, BinaryData::OVERPASSBOLD_TTFSize) };
	}

	static const FontOptions semi() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::OVERPASSSEMIBOLD_TTF, BinaryData::OVERPASSSEMIBOLD_TTFSize) };
	}

	static const Font cbox(const float scale_factor) {
		return Font{ semi() }.withPointHeight(10.5f * scale_factor);
	}

	static const Font file_browser(const float scale_factor) {
		return Font{ bold() }.withPointHeight(12.0f * scale_factor);
	}

	static const Font knob(const float scale_factor) {
		return Font{ bold() }.withPointHeight(11.0f * scale_factor);
	}

	static const Font knob_txt_edit(const float scale_factor) {
		return Font{ bold() }.withPointHeight(11.0f * scale_factor);
	}

	static const Font pulse_w_txt(const float scale_factor) {
		return Font{ bold() }.withPointHeight(9.0f * scale_factor);
	}

	static const Font seq_step(const float scale_factor) {
		return Font{ bold() }.withPointHeight(9.5f * scale_factor);
	}

	static const Font tip() {
		return Font{ bold() }.withPointHeight(12.0f);
	}
};