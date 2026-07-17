#pragma once

#include <JuceHeader.h>




class UnexposedParameters;

class ExposedParametersListener :
	private AudioProcessorValueTreeState::Listener,
	public Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	ExposedParametersListener() = delete;

	ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void parameterChanged(const String& parameterID, float newValue) override;
	void timerCallback() override;

public:
	~ExposedParametersListener();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersListener)
};