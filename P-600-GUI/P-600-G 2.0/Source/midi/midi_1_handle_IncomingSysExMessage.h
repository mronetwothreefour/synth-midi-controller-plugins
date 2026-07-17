#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class UnexposedParameters;
class VoicesBank;
class VoiceTransmissionOptions;

class IncomingSysExMessageHandler
{
	ExposedParameters* exposedParams;
	VoicesBank* voicesBank;
	VoiceTransmissionOptions* transmitOptions;
	const int sysExMessageTypeByte{ 3 };

public:
	IncomingSysExMessageHandler() = delete;

	IncomingSysExMessageHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	MidiBuffer pullMessageForP_600_OutOfBuffer(const MidiBuffer& midiMessages);

private:
	void handleIncomingVoiceData(const uint8* sysExData, int sysExDataSize);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingSysExMessageHandler)
};

