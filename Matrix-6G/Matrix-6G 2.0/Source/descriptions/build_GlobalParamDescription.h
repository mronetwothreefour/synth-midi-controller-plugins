#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct GlobalParamDescription
{
	static String buildForActiveSensing();
	static String buildForControllers();
	static String buildForCurrentValueTooltip();
	static String buildForDescriptionTooltip();
	static String buildForLocalControl();
	static String buildForOmniMode();
	static String buildForSpillover();
	static String buildForSplitStereo();
	static String buildForSysEx();
	static String buildForVibratoModSource(bool isForSpeed);
	static String buildForVibratoWaveType();
	static String buildForVoiceChanges();
	static String buildForVoiceMapInVoice(uint8 mapSlotNum);
	static String buildForVoiceMapEcho();
	static String buildForVoiceMap();
	static String buildForVoiceMapOutVoice(uint8 mapSlotNum);
	static String buildFor_MIDI_Echo();
	static String buildFor_MIDI_Mono();
	static String buildFor_SQUICK();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GlobalParamDescription)
};