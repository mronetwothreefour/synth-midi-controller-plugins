#pragma once

#include <JuceHeader.h>

class GlobalOptions
{
	ValueTree globalOptionsTree;

public:
	GlobalOptions();
	void resetAllOptionsToDefaults();

	const uint8 basicChannel();
	void setBasicChannel(const uint8 newChannel);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptions)
};