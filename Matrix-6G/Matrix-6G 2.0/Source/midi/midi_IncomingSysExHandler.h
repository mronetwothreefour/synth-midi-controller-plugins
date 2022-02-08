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
	void handleIncomingPatchDump(const uint8* sysExData);
	void handleIncomingSplitDump(const uint8* sysExData);
	void handleIncomingMasterOptionsDump(const uint8* sysExData);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingSysExHandler)
};

