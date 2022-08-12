#pragma once

#include <JuceHeader.h>

struct LED_Path
{
	static Path buildForChar(const uint8 charNum);
	static Path buildChoiceNameForControl(const String choiceName, const int control_w);
	static Path buildForVertBar();
	static Path buildForSliderTab();
};