#pragma once

#include <JuceHeader.h>



class IncomingNRPNhandler
{
	AudioProcessorValueTreeState* exposedParams;
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

	explicit IncomingNRPNhandler(AudioProcessorValueTreeState* exposedParams);
	~IncomingNRPNhandler();
	MidiBuffer pullFullyFormedNRPNoutOfBuffer(const MidiBuffer& midiMessages);

private:
	void handle_If_MessageTargetsOneOfTheNRPNcontrollers(MidiMessage midiMessage);
	void handleNRPNmessage(MidiMessage midiMessage);
	void handle_if_MessageTargetsNRPNtypeMSB(MidiMessage midiMessage);
	void handle_if_MessageTargetsNRPNtypeLSB(MidiMessage midiMessage);
	void handle_if_MessageTargetsNRPNvalueMSB(MidiMessage midiMessage);
	void handle_if_MessageTargetsNRPNvalueLSB(MidiMessage midiMessage);
	void applyIncomingNRPNvalueToExposedParameter(int nrpnType, int newValue);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingNRPNhandler)
};

