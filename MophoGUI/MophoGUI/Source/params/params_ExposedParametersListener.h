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

public:
	ExposedParametersListener() = delete;

	ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void parameterChanged(const String& parameterID, float newValue) override;
	void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn);

public:
	~ExposedParametersListener();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersListener)
};