#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobWaveShapes.h"



enum class LFOfreqCategory {
	unsynced = 0,
	pitched,
	synced
};




class UnexposedParameters;

class ParamRandomizationMethods :
	private Timer
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	ParamRandomizationMethods() = delete;

	ParamRandomizationMethods(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void randomizeAllUnlockedParameters();
	void randomizeParameter(String paramID);

private:
	uint8 pickRandomValueForParam(uint8 paramIndex);
	uint8 pickRandomPitchForParam(uint8 paramIndex);
	uint8 pickRandomValueFromRangeForParam(uint8 paramIndex);
	uint8 pickRandomOscShapeAndPulseWidthForParam(uint8 paramIndex);
	uint8 pickRandomOscShapeIndexForParameter(uint8 paramIndex);
	uint8 pickRandomPulseWidthForParam(uint8 paramIndex);
	uint8 pickRandomComboBoxItemForParam(uint8 paramIndex);
	uint8 pickRandomLPFfreq();
	uint8 pickRandomLFOfreqForParam(uint8 paramIndex);
	LFOfreqCategory pickRandomFreqCategoryForParam(uint8 paramIndex);
	uint8 pickRandomUnsyncedLFOfreqForParam(uint8 paramIndex);
	uint8 pickRandomPitchedLFOfreqForParam(uint8 paramIndex);
	uint8 pickRandomSyncedLFOfreqForParam(uint8 paramIndex);
	uint8 pickRandomSeqStepValueForParam(uint8 paramIndex);
	bool randomlyDecideIfStepInSeqTrack1IsRest(uint8 paramIndex);
	bool randomlyDecideIfStepInSeqTrackIsRepeatValue(uint8 paramIndex, int trackNum);
	bool randomlyDecideIfStepInSeqTrackIsReset(uint8 paramIndex, int trackNum);
	uint8 pickRandomPitchForStepParamInTrack(uint8 paramIndex, int trackNum);
	uint8 pickRandomValueFromRangeForStepParamInTrack(uint8 paramIndex, int trackNum);
	void updateParamWithNewNormalizedValueAfterDelay(String paramID, float newNormalizedValue, int delayInMs);
	void randomizeArpAndSeqOnOffParametersAfterDelay(int delayInMs);
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationMethods)
};