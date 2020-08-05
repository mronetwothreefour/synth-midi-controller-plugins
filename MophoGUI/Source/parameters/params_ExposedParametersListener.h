#pragma once

#include <JuceHeader.h>



class ExposedParametersListener :
	private AudioProcessorValueTreeState::Listener
{
	AudioProcessorValueTreeState* exposedParams;
	const uint8 arpeggiator;
	const uint8 sequencer;

public:
	ExposedParametersListener() = delete;

	explicit ExposedParametersListener(AudioProcessorValueTreeState* exposedParams);
	~ExposedParametersListener();

private:
	void parameterChanged(const String& parameterID, float newValue) override;
	void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersListener)
};