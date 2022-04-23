#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobWaveShapes.h"



enum class LFOfreqCategory {
	unsynced = 0,
	pitched,
	synced
};

class UnexposedParameters;

struct ParamRandomizationMethods {
	static void randomizeUnlockedParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	static uint8 pickRandomValueForParam(uint8 paramIndex);
	static uint8 pickRandomPitchForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomValueFromRangeForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomOscShapeAndPulseWidthForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomOscShapeIndexForParameter(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomPulseWidthForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomComboBoxItemForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomLPFfreq(UnexposedParameters* unexposedParams);
	static uint8 pickRandomLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static LFOfreqCategory pickRandomFreqCategoryForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomUnsyncedLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomPitchedLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomSyncedLFOfreqForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static uint8 pickRandomSeqStepValueForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static bool randomlyDecideIfStepInSeqTrack1IsRest(uint8 paramIndex, UnexposedParameters* unexposedParams);
	static bool randomlyDecideIfStepInSeqTrackIsRepeatValue(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams);
	static bool randomlyDecideIfStepInSeqTrackIsReset(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams);
	static uint8 pickRandomPitchForStepParamInTrack(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams);
	static uint8 pickRandomValueFromRangeForStepParamInTrack(uint8 paramIndex, int trackNum, UnexposedParameters* unexposedParams);
	static void randomizeArpAndSeqOnOffParameters(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
};