#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct SplitParamDescription
{
	static String buildForZoneLimit(SplitZone zone);
	static String buildForZone_MIDI_OutIsEnabled(SplitZone zone);
	static String buildForZoneTranspose(SplitZone zone);
	static String buildForZoneVoiceAssignment();
	static String buildForZoneVoiceNum(SplitZone zone);
	static String buildForZoneVolumeBalance();
};