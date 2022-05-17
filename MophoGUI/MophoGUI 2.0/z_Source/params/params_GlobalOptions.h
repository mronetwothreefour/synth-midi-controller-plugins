#pragma once

#include <JuceHeader.h>



class GlobalOptions
{
	ValueTree globalOptionsTree;

public:
	GlobalOptions();

private:
	void fillGlobalOptionsTreeWithProperties();

public:
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
	const uint8 clockType();
	void setClockType(uint8 newType);
	const bool pedalModeIsArpLatch();
	void setPedalModeToArpLatch();
	void setPedalModeToNormal();
	const bool voiceChangeIsOn();
	void setVoiceChangeOn();
	void setVoiceChangeOff();
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
	bool hardwareOutputIsStereo();
	void setHardwareOutputStereo();
	void setHardwareOutputMono();
	const uint8 globalBalance();
	void setGlobalBalance(uint8 newBalance);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalOptions)
};
