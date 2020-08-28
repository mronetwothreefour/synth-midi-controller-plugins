#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class IncomingSysExHandler
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	const int sysExMessageTypeByte;
	const int programDumpBankByte;
	const int programDumpSlotByte;
	const int firstProgramDataByte;
	const int firstUnusedProgramDataByte;
	const int globalTransposeLSByte;
	const int globalTransposeMSByte;
	const int globalFineTuneLSByte;
	const int globalFineTuneMSByte;
	const int globalHardwareReceiveChannelLSByte;
	const int globalHardwareReceiveChannelMSByte;
	const int globalMidiClockTypeByte;
	const int globalParameterSendTypetByte;
	const int globalParameterReceiveTypeByte;
	const int globalMidiControllersOnByte;
	const int globalSysExOnByte;
	const int globalStereoOutByte;
	const int globalBalanceByte;
	const int globalPedalModeIsArpByte;
	const int globalProgramChangeOnByte;

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

