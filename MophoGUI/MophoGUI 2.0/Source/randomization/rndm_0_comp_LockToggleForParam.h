#pragma once

#include <JuceHeader.h>



class ExposedParameters;

class LockToggleForParam :
	public ToggleButton
{
	uint8 paramIndex;

public:
	LockToggleForParam() = delete;

	LockToggleForParam(uint8 paramIndex, ExposedParameters* exposedParams);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LockToggleForParam)
};