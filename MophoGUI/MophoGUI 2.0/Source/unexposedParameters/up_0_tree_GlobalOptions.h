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

	const uint8 globalTranspose();
	void setGlobalTranspose(const uint8 newTransposition);

	const uint8 globalFineTune();
	void setGlobalFineTune(const uint8 newFineTune);

	const uint8 transmitChannel();
	void setTransmitChannel(const uint8 newChannel);

	const uint8 hardwareReceiveChannel();
	void setHardwareReceiveChannel(const uint8 newChannel);

	const MIDI_ClockSource midiClockSource();
	void setMIDI_ClockSource(const MIDI_ClockSource newSource);

	const bool pedalModeIsArpLatch();
	void setPedalModeIsArpLatch(const bool shouldBeArpLatch);

	const bool voiceChangesAreEnabled();
	void setVoiceChangesAreEnabled(const bool shouldBeEnabled);

	const ParamChangeSendType paramChangeSendType();
	void setParamChangeSendType(const ParamChangeSendType newSendType);

	const ParamChangeReceiveType paramChangeReceiveType();
	void setParamChangeReceiveType(const ParamChangeReceiveType newReceiveType);

	const bool controllersAreEnabled();
	void setControllersAreEnabled(const bool shouldBeEnabled);

	const bool hardwareIsSetToReceiveNRPNcontrollers();
	const bool hardwareIsNotSetToReceiveNRPNcontrollers();

	const bool sysExIsEnabled();
	void setSysExIsEnabled(const bool shouldBeEnabled);

	bool hardwareOutputIsMono();
	void setHardwareOutputIsMono(const bool shouldBeMono);

	const uint8 hardwareOutputBalance();
	void setHardwareOutputBalance(const uint8 newBalance);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptions)
};