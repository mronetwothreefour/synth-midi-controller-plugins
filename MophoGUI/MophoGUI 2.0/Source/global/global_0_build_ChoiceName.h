#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

struct GlobalParamChoiceName
{
	static String buildForAudioOutput(bool isMono);
	static String buildForHardwareOutputBalance(int choiceNum);
	static String buildForGlobalFineTune(int choiceNum, bool verbose);
	static String buildForGlobalTranspose(int choiceNum, bool verbose);
	static String buildForHardwareReceiveChannel(int choiceNum, bool verbose);
	static String buildForMIDI_ClockSource(MIDI_ClockSource sourceType, bool verbose);
	static String buildForMIDI_Controllers(bool areEnabled);
	static String buildForParamChangeReceiveType(ParamChangeReceiveType receiveType);
	static String buildForParamChangeSendType(ParamChangeSendType sendType);
	static String buildForPedalMode(bool isArpLatch);
	static String buildForSysEx(bool isOn);
	static String buildForVoiceChanges(bool isEnabled);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamChoiceName)
};