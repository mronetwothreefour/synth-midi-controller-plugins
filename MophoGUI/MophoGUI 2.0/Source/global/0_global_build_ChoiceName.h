#pragma once

#include <JuceHeader.h>



struct GlobalParamChoiceName {
	static String buildFor_GlobalFineTune(int choiceNum, bool verbose);
	static String buildFor_GlobalTranspose(int choiceNum, bool verbose);
	static String buildFor_HardwareReceiveChannel(int choiceNum, bool verbose);
	static String buildFor_MIDI_ClockSource(int choiceNum, bool verbose);
	static String buildFor_ParamChangeSendType(int choiceNum);
	static String buildFor_PedalMode(int choiceNum);
	static String buildFor_VoiceChange(int choiceNum);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamChoiceName)
};