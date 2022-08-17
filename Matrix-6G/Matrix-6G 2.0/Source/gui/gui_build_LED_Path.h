#pragma once

#include <JuceHeader.h>

struct LED_Path
{
	static Path buildForChar(const uint8 charNum);
	static Path buildLabelText(const String text, const int control_w, bool rightJustified = (bool)true);
	static Path buildForVertBar();
	static Path buildForSliderTab();
};