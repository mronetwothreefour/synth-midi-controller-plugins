#pragma once

#include <JuceHeader.h>

namespace FONT
{
	const FontOptions bold{ Typeface::createSystemTypefaceFor(BinaryData::OVERPASSBOLD_TTF, BinaryData::OVERPASSBOLD_TTFSize) };

	const Font display_editor{ bold.withPointHeight(13.0f) };
}
