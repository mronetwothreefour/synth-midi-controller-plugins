#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class IncomingSysExHandler
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	IncomingSysExHandler() = delete;

	explicit IncomingSysExHandler(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	MidiBuffer pullSysExWithMatchingIDOutOfBuffer(const MidiBuffer& midiMessages);

private:
	bool incomingSysExHasMatchingID(MidiMessage midiMessage);
	void handleIncomingProgramEditBufferDump(const uint8* sysExData);
	void handleIncomingProgramDump(const uint8* sysExData);
	void handleIncomingGlobalParametersDump(const uint8* sysExData);
	void updateMidiOptions(const uint8* sysExData);
	void updateGlobalAudioOptions(const uint8* sysExData);

public:
	~IncomingSysExHandler();


private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingSysExHandler)
};

