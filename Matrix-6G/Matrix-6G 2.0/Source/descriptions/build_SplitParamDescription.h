#pragma once

#include <JuceHeader.h>

struct SplitParamDescription
{
	static String buildForZoneLimit(bool isLowerZone);
	static String buildForZoneTranspose(bool isLowerZone);
	static String buildForZoneVoiceNum(bool isLowerZone);
	static String buildForZoneVolumeBalance();
};