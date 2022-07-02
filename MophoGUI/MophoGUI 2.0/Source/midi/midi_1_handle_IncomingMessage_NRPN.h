#pragma once

#include <JuceHeader.h>

using ExposedParameters = AudioProcessorValueTreeState;



class GlobalOptions;
class InfoForExposedParameters;
class UnexposedParameters;
class VoiceTransmissionOptions;

class IncomingMessageHandler_NRPN
{
	ExposedParameters* exposedParams;
	InfoForExposedParameters* info;
	GlobalOptions* global;
	VoiceTransmissionOptions* voiceTransmit;
	bool receivedType_MSB{ false };
	bool receivedType_LSB{ false };
	bool receivedValue_MSB{ false };
	bool receivedValue_LSB{ false };
	int type_MSB{ 0 };
	int type_LSB{ 0 };
	int value_MSB{ 0 };
	int value_LSB{ 0 };
	MidiBuffer midiMessagesToPassThrough;
	MidiBuffer incompleteNRPN;

public:
	IncomingMessageHandler_NRPN() = delete;

	IncomingMessageHandler_NRPN(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	MidiBuffer pullFullyFormedMessageOutOfBuffer(const MidiBuffer& midiMessages);

private:
	void checkIfControllerTypeIsNRPN(MidiMessage midiMessage);
	void handleControllerMessage(MidiMessage midiMessage);
	void handleControllerMessage_Type_MSB(MidiMessage midiMessage);
	void handleControllerMessage_Type_LSB(MidiMessage midiMessage);
	void handleControllerMessage_Value_MSB(MidiMessage midiMessage);
	void handleControllerMessage_Value_LSB(MidiMessage midiMessage);
	void applyIncomingValueToExposedParameter(int nrpnType, int newValue);
	void applyIncomingValueToGlobalOption(int nrpnType, int newValue);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingMessageHandler_NRPN)
};

