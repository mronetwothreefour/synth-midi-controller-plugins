#pragma once

#include <JuceHeader.h>

struct LED_Path
{
	static Path buildForChar(uint8 charNum);
	static Path buildForSliderTab();
};