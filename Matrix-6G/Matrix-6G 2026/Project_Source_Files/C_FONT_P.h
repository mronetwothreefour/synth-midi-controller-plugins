#pragma once

#include <JuceHeader.h>

namespace FONT
{
	const FontOptions bold{ Typeface::createSystemTypefaceFor(BinaryData::SWISSB_TTF, BinaryData::SWISSB_TTFSize) };
	const FontOptions cond_light{ Typeface::createSystemTypefaceFor(BinaryData::SWISSCL_TTF, BinaryData::SWISSCL_TTFSize) };

	const Font display_editor{ bold.withPointHeight(16.0f) };
}