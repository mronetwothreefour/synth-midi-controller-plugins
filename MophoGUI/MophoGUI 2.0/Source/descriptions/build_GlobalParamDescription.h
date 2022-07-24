#pragma once

#include <JuceHeader.h>

struct GlobalParamDescription
{
	static String buildForAudioOutput();
	static String buildForHardwareOutputBalance();
	static String buildForCurrentValueTooltip();
	static String buildForDescriptionTooltip();
	static String buildForGlobalFineTune();
	static String buildForGlobalTranspose();
	static String buildForHardwareReceiveChannel();
	static String buildForMIDI_ClockSource();
	static String buildForMIDI_ControllersStatus();
	static String buildForParamChangeSendType();
	static String buildForParamChangeReceiveType();
	static String buildForPedalMode();
	static String buildForSysExStatus();
	static String buildForTooltipDelay();
	static String buildForVoiceChanges();

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamDescription)
};