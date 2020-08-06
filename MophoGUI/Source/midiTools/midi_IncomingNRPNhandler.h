#pragma once

#include <JuceHeader.h>



class IncomingNRPNhandler
{
	AudioProcessorValueTreeState* exposedParams;
	const int nrpnTypeMSB{ 99 };
	const int nrpnTypeLSB{ 98 };
	const int nrpnValueMSB{ 6 };
	const int nrpnValueLSB{ 38 };

public:
	IncomingNRPNhandler() = delete;

	explicit IncomingNRPNhandler(AudioProcessorValueTreeState* exposedParams);
	~IncomingNRPNhandler();
	MidiBuffer pullFullyFormedNRPNoutOfBuffer(const MidiBuffer& midiMessages);

private:
	bool messageTargetsOneOfTheNRPNcontrollers(MidiMessage midiMessage);
	void applyIncomingNRPNvalueToExposedParameter(int nrpnType, int newValue);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(IncomingNRPNhandler)
};

