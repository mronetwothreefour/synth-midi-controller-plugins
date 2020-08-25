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
	uint8 transmitChannel();
	void setTransmitChannel(uint8 newChannel);
	uint8 hardwareReceiveChannel();
	void setHardwareReceiveChannel(uint8 newChannel);
	uint8 clockType();
	void setClockType(uint8 newType);
	uint8 parameterSendType();
	void setParameterSendType(uint8 newType);
	uint8 parameterReceiveType();
	void setParameterReceiveType(uint8 newType);
	bool controllersAreOn();
	void setControllersOn();
	void setControllersOff();
	bool sysExIsOn();
	void setSysExOn();
	void setSysExOff();
	bool midiThruIsOn();
	void setMidiThruOn();
	void setMidiThruOff();
	bool paramChangeEchosAreNotBlocked();
	void setParamChangeEchosAreBlocked();
	void setParamChangeEchosAreNotBlocked();
	int programTransmitTime();
	void setProgramTransmitTime(int timeInMilliseconds);
	~MidiOptions();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiOptions)
};
