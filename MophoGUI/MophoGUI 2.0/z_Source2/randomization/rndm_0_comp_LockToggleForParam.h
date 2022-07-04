#pragma once

#include <JuceHeader.h>



class ExposedParameters;
class RandomizationOptions;
class UnexposedParameters;

class LockToggleForParam :
	public ToggleButton
{
	uint8 paramIndex;
	RandomizationOptions* randomization;

public:
	LockToggleForParam() = delete;

	LockToggleForParam(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LockToggleForParam)
};