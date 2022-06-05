#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ParamRandomizationMethods :
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	ParamRandomizationMethods() = delete;

	ParamRandomizationMethods(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void randomizeAllUnlockedParameters();
	void randomizeParameter(String paramID);

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationMethods)
};