#pragma once

#include <JuceHeader.h>

struct FONT
{
	static const FontOptions bold() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::OverpassBold_ttf, BinaryData::OverpassBold_ttfSize) };
	}

	static const FontOptions semi() {
		return FontOptions{ Typeface::createSystemTypefaceFor(BinaryData::OverpassSemiBold_ttf, BinaryData::OverpassSemiBold_ttfSize) };
	}

	static const Font cbox(const float scale_factor) {
		return Font{ semi() }.withPointHeight(10.5f * scale_factor);
	}

	static const Font file_browser(const float scale_factor) {
		return Font{ bold() }.withPointHeight(14.0f * scale_factor);
	}

	static const Font knob(const float scale_factor) {
		return Font{ bold() }.withPointHeight(10.0f * scale_factor);
	}

	static const Font knob_txt_edit(const float scale_factor) {
		return Font{ bold() }.withPointHeight(10.0f * scale_factor);
	}

	static const Font tip() {
		return Font{ bold() }.withPointHeight(12.0f);
	}
};