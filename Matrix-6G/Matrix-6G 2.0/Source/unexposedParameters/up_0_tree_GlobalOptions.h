#pragma once

#include <JuceHeader.h>

class GlobalOptions
{
	ValueTree globalOptionsTree;

public:
	GlobalOptions();
	void resetAllOptionsToDefaults();

	const uint8 basicChannel();
	void setBasicChannel(uint8 newChannel);
};