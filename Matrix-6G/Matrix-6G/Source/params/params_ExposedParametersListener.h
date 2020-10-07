#pragma once

#include <JuceHeader.h>




class MidiOptions;
class UnexposedParameters;

class ExposedParametersListener :
	private AudioProcessorValueTreeState::Listener
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	MidiOptions* midiOptions;
	const int8 offsetFor5bitSignedValues{ 31 };
	const int8 offsetFor6bitSignedValues{ 63 };

public:
	ExposedParametersListener() = delete;

	ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void parameterChanged(const String& parameterID, float newValue) override;

public:
	~ExposedParametersListener();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersListener)
};