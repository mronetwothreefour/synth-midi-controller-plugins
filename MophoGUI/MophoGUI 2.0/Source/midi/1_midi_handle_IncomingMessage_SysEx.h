#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class IncomingMessageHandler_SysEx
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	const int sysExMessageTypeByte{ 3 };

public:
	IncomingMessageHandler_SysEx() = delete;

	IncomingMessageHandler_SysEx(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	MidiBuffer pullMessageForMophoOutOfBuffer(const MidiBuffer& midiMessages);

private:
	void handleSysExData(const uint8* sysExData);
	void handleIncomingEditBufferData(const uint8* sysExData);
	void handleIncomingVoiceData(const uint8* sysExData);
	void handleIncomingGlobalData(const uint8* sysExData);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingMessageHandler_SysEx)
};

