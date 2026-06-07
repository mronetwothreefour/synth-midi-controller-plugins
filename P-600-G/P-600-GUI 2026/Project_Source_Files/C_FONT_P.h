#pragma once

#include <JuceHeader.h>

namespace FONT
{
	const FontOptions bold{ Typeface::createSystemTypefaceFor(BinaryData::SWISSB_TTF, BinaryData::SWISSB_TTFSize) };
	const FontOptions cond_black{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCK_TTF, BinaryData::SWISSCK_TTFSize) };
	const FontOptions cond_light{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCL_TTF, BinaryData::SWISSCL_TTFSize) };

	const Font display_editor{ cond_black.withPointHeight(14.0f) };
	const Font display_editor_led{ bold.withPointHeight(36.0f) };
}