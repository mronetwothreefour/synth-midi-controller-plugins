#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class GlobalOptions;
class UnexposedParameters;
class VoicesBanks;
class VoiceTransmissionOptions;
// TODO: handle global and split data messages

class IncomingSysExMessageHandler
{
	ExposedParameters* exposedParams;
	GlobalOptions* global;
	VoicesBanks* voicesBanks;
	VoiceTransmissionOptions* transmitOptions;
	const int sysExMessageTypeByte{ 3 };

public:
	IncomingSysExMessageHandler() = delete;

	IncomingSysExMessageHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	MidiBuffer pullMessageForMatrixOutOfBuffer(const MidiBuffer& midiMessages);

private:
	void handleSysExData(const uint8* sysExData, int sysExDataSize);
	void handleIncomingVoiceData(const uint8* sysExData, int sysExDataSize);
	void handleIncomingGlobalData(const uint8* sysExData, int sysExDataSize);
	void handleIncomingSplitData(const uint8* sysExData, int sysExDataSize);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingSysExMessageHandler)
};

