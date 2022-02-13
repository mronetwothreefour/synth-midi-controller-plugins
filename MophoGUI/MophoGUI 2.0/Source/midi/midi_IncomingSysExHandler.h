#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class IncomingSysExHandler
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	IncomingSysExHandler() = delete;

	IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	MidiBuffer pullSysExWithMatchingIDOutOfBuffer(const MidiBuffer& midiMessages);

private:
	bool incomingSysExHasMatchingID(MidiMessage midiMessage);
	void handleIncomingEditBufferDataMessage(const uint8* sysExData);
	void handleIncomingVoiceDataMessage(const uint8* sysExData);
	void handleIncomingGlobalDataMessage(const uint8* sysExData);
	void updateGlobalOptions(const uint8* sysExData);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingSysExHandler)
};

