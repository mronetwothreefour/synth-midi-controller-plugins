#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct GlobalParamDescription
{
	static String buildForActiveSensing();
	static String buildForBasicChannel();
	static String buildForControllers();
	static String buildForControllerNumForLever_2();
	static String buildForControllerNumForLever_3();
	static String buildForControllerNumForPedal(int pedalNum);
	static String buildForCurrentValueTooltip();
	static String buildForDescriptionTooltip();
	static String buildForDisplayBrightness();
	static String buildForGlobalTune();
	static String buildForLocalControl();
	static String buildForOmniMode();
	static String buildForSpillover();
	static String buildForSplitStereo();
	static String buildForSysEx();
	static String buildForVibratoAmplitude();
	static String buildForVibratoModAmount(bool isForSpeed);
	static String buildForVibratoModSource(bool isForSpeed);
	static String buildForVibratoSpeed();
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