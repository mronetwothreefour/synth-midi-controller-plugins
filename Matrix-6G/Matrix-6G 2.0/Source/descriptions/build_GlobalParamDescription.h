#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct GlobalParamDescription
{
	static String buildForVoiceMapInVoice(uint8 mapSlotNum);
	static String buildForVoiceMapOutVoice(uint8 mapSlotNum);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamDescription)
};