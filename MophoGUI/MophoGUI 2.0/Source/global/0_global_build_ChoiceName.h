#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;



struct GlobalParamChoiceName {
	static String buildFor_AudioOutput(bool isStereo);
	static String buildFor_HardwareOutputBalance(int choiceNum);
	static String buildFor_GlobalFineTune(int choiceNum, bool verbose);
	static String buildFor_GlobalTranspose(int choiceNum, bool verbose);
	static String buildFor_HardwareReceiveChannel(int choiceNum, bool verbose);
	static String buildFor_MIDI_ClockSource(MIDI_ClockSource sourceType, bool verbose);
	static String buildFor_MIDI_Controllers(bool areOn);
	static String buildFor_ParamChangeReceiveType(ParamChangeReceiveType receiveType);
	static String buildFor_ParamChangeSendType(ParamChangeSendType sendType);
	static String buildFor_PedalMode(bool isArpLatch);
	static String buildFor_SysEx(bool isOn);
	static String buildFor_VoiceChange(bool isEnabled);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamChoiceName)
};