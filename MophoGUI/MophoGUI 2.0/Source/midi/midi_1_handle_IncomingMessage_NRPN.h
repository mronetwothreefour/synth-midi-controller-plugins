#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class GlobalOptions;
class UnexposedParameters;
class VoiceTransmissionOptions;

class IncomingMessageHandler_NRPN
{
	ExposedParameters* exposedParams;
	GlobalOptions* global;
	VoiceTransmissionOptions* transmitOptions;
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
	void checkIfControllerTypeIsNRPN(const MidiMessage midiMessage);
	void handleControllerMessage(const MidiMessage midiMessage);
	void handleControllerMessage_Type_MSB(const MidiMessage midiMessage);
	void handleControllerMessage_Type_LSB(const MidiMessage midiMessage);
	void handleControllerMessage_Value_MSB(const MidiMessage midiMessage);
	void handleControllerMessage_Value_LSB(const MidiMessage midiMessage);
	void applyIncomingValueToExposedParameter(const int nrpnType, const int newValue);
	void applyIncomingValueToGlobalOption(const int nrpnType, const int newValue);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingMessageHandler_NRPN)
};

