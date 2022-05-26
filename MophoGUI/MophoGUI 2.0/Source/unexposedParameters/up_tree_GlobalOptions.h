#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



class GlobalOptions
{
	ValueTree globalOptionsTree;

public:
	GlobalOptions();
	void resetAllOptionsToDefaults();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 globalTranspose();
	void setGlobalTranspose(uint8 newTransposition);
	const uint8 globalFineTune();
	void setGlobalFineTune(uint8 newFineTune);
	const uint8 transmitChannel();
	void setTransmitChannel(uint8 newChannel);
	const uint8 hardwareReceiveChannel();
	void setHardwareReceiveChannel(uint8 newChannel);
	const MIDI_ClockSource midiClockSource();
	void setMIDI_ClockSource(MIDI_ClockSource newSource);
	const bool pedalModeIsArpLatch();
	void setPedalModeToArpLatch();
	void setPedalModeToNormal();
	const bool voiceChangeIsOn();
	void setVoiceChangeOn();
	void setVoiceChangeOff();
	const ParamChangeSendType paramChangeSendType();
	void setParamChangeSendType(ParamChangeSendType newSendType);
	const ParamChangeReceiveType paramChangeReceiveType();
	void setParamChangeReceiveType(ParamChangeReceiveType newReceiveType);
	const bool controllersAreOn();
	const bool controllersAreOff();
	void setControllersOn();
	void setControllersOff();
	const bool hardwareIsSetToReceiveNRPNcontrollers();
	const bool hardwareIsNotSetToReceiveNRPNcontrollers();
	const bool sysExIsOn();
	const bool sysExIsOff();
	void setSysExOn();
	void setSysExOff();
	bool hardwareOutputIsStereo();
	void setHardwareOutputToStereo();
	void setHardwareOutputToMono();
	const uint8 hardwareOutputBalance();
	void setHardwareOutputBalance(uint8 newBalance);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptions)
};
