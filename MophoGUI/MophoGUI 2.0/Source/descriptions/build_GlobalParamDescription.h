#pragma once

#include <JuceHeader.h>



struct GlobalParamDescription
{
	static String buildFor_AudioOutput();
	static String buildFor_BalanceTweak();
	static String buildFor_CurrentSettingTooltip();
	static String buildFor_DescriptionTooltip();
	static String buildFor_GlobalFineTune();
	static String buildFor_GlobalTranspose();
	static String buildFor_HardwareReceiveChannel();
	static String buildFor_MIDI_ClockSource();
	static String buildFor_MIDI_ControllersStatus();
	static String buildFor_ParamChangeSendType();
	static String buildFor_ParamChangeReceiveType();
	static String buildFor_PedalMode();
	static String buildFor_SysExStatus();
	static String buildFor_TooltipDelay();
	static String buildFor_VoiceChange();

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamDescription)
};