#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class IncomingNRPNhandler
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	const int nrpnTypeMSB{ 99 };
	const int nrpnTypeLSB{ 98 };
	const int nrpnValueMSB{ 6 };
	const int nrpnValueLSB{ 38 };
	bool nrpnTypeMSBvalueReceived{ false };
	bool nrpnTypeLSBvalueReceived{ false };
	bool nrpnValueMSBvalueReceived{ false };
	bool nrpnValueLSBvalueReceived{ false };
	int nrpnTypeMSBvalue{ 0 };
	int nrpnTypeLSBvalue{ 0 };
	int nrpnValueMSBvalue{ 0 };
	int nrpnValueLSBvalue{ 0 };
	MidiBuffer midiMessagesToPassThrough;
	MidiBuffer incompleteNRPN;

public:
	IncomingNRPNhandler() = delete;

	IncomingNRPNhandler(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	MidiBuffer pullFullyFormedNRPNmessageOutOfBuffer(const MidiBuffer& midiMessages);

private:
	void checkIfControllerTypeIsNRPN(MidiMessage midiMessage);
	void handleNRPNcontrollerMessage(MidiMessage midiMessage);
	void handleControllerWhichTargetsNRPNtypeMSB(MidiMessage midiMessage);
	void handleControllerWhichTargetsNRPNtypeLSB(MidiMessage midiMessage);
	void handleControllerWhichTargetsNRPNvalueMSB(MidiMessage midiMessage);
	void handleControllerWhichTargetsNRPNvalueLSB(MidiMessage midiMessage);
	void applyIncomingNRPNvalueToExposedParameter(int nrpnType, int newValue);
	void applyIncomingNRPNvalueToUnexposedParameter(int nrpnType, int newValue);

public:
	~IncomingNRPNhandler();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingNRPNhandler)
};

