#pragma once

#include <JuceHeader.h>



class MidiOptions
{
	ValueTree midiOptionsTree;

public:
	MidiOptions();

private:
	void fillMidiOptionsTreeWithProperties();

public:
	void resetMidiOptionsToDefaults();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 transmitChannel();
	void setTransmitChannel(uint8 newChannel);
	const uint8 hardwareReceiveChannel();
	void setHardwareReceiveChannel(uint8 newChannel);
	const uint8 clockType();
	void setClockType(uint8 newType);
	const uint8 parameterSendType();
	void setParameterSendType(uint8 newType);
	const uint8 parameterReceiveType();
	void setParameterReceiveType(uint8 newType);
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
	const bool pedalModeIsArpLatch();
	void setPedalModeToArpLatch();
	void setPedalModeToNormal();
	const bool voiceChangeIsOn();
	void setVoiceChangeOn();
	void setVoiceChangeOff();
	const bool paramChangeEchoesAreNotBlocked();
	void setParamChangeEchoesAreBlocked();
	void setParamChangeEchoesAreNotBlocked();
	const int voiceTransmitTime();
	void setVoiceTransmitTime(int timeInMilliseconds);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiOptions)
};
