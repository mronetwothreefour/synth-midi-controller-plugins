#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

using Step = SeqTrackStepNum;
using Track = SeqTrackNum;

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;

class ExposedParamsRandomizationMethods :
	private Timer
{
	AudioProcessorValueTreeState* state;
	ExposedParamsRandomizationOptions* randomization;
	InfoForExposedParameters* info;

public:
	ExposedParamsRandomizationMethods() = delete;

	explicit ExposedParamsRandomizationMethods(ExposedParameters* exposedParams);
	void randomizeAllUnlockedParameters();
	void randomizeParameter(uint8 paramIndex);
	void randomizeSeqTrackStep(Track track, Step step);

private:
	uint8 randomlyChooseNewSettingForParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForStandardOrVoiceNameCharParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForOscShapeParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForBinaryParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingFor_LFO_FreqParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForSeqTrackStep(Track track, Step step);

	void applyNewSettingToExposedParameter(uint8 newSetting, Identifier paramID);

	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsRandomizationMethods)
};