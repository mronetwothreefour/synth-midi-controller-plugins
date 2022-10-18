#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct GlobalParamDescription
{
	static String buildForVoiceMapInVoice(uint8 mapNum);
	static String buildForVoiceMapOutVoice(uint8 mapNum);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamDescription)
};