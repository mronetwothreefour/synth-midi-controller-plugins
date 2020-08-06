#pragma once

#include <JuceHeader.h>



class IncomingSysExHandler
{
	AudioProcessorValueTreeState* exposedParams;

public:
	IncomingSysExHandler() = delete;

	explicit IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams);
	~IncomingSysExHandler();
	MidiBuffer pullSysExWithMatchingIDOutOfBuffer(const MidiBuffer& midiMessages);

private:
	bool incomingSysExHasMatchingID(MidiMessage midiMessage);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingSysExHandler)
};

