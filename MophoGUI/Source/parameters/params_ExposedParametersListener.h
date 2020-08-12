#pragma once

#include <JuceHeader.h>



class OutgoingMidiBuffers;

class ExposedParametersListener :
	private AudioProcessorValueTreeState::Listener
{
	AudioProcessorValueTreeState* exposedParams;
	OutgoingMidiBuffers* outgoingBuffers;
	const uint8 arpeggiator;
	const uint8 sequencer;

public:
	ExposedParametersListener() = delete;

	ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, OutgoingMidiBuffers* outgoingBuffers);
	~ExposedParametersListener();

private:
	void parameterChanged(const String& parameterID, float newValue) override;
	void arpeggiatorAndSequencerCannotBothBeOn(uint8 paramTurnedOn);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersListener)
};