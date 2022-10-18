#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

struct GlobalParamChoiceName
{
	static String buildForAudioOutput(const bool isMono);
	static String buildForGlobalFineTune(const int choiceNum, const ChoiceNameType type);
	static String buildForGlobalTranspose(const int choiceNum, const ChoiceNameType type);
	static String buildForHardwareOutputBalance(const int choiceNum);
	static String buildForHardwareReceiveChannel(const int choiceNum, const ChoiceNameType type);
	static String buildForMIDI_ClockSource(const MIDI_ClockSource sourceType, const ChoiceNameType type);
	static String buildForMIDI_Controllers(const bool areEnabled);
	static String buildForParamChangeReceiveType(const ParamChangeReceiveType receiveType);
	static String buildForParamChangeSendType(const ParamChangeSendType sendType);
	static String buildForPedalMode(const bool isArpLatch);
	static String buildForSysEx(const bool isOn);
	static String buildForVoiceChanges(const bool isEnabled);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamChoiceName)
};