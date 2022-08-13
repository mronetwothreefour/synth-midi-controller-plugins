#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

using Step = SeqTrackStepNum;
using Track = SeqTrackNum;

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class Outgoing_MIDI_Buffers;
class UnexposedParameters;
class VoiceTransmissionOptions;

class ExposedParamsRandomizationMethods :
	private Timer
{
	ExposedParameters* exposedParams;
	AudioProcessorValueTreeState* state;
	ExposedParamsRandomizationOptions* randomization;
	InfoForExposedParameters* info;
	Outgoing_MIDI_Buffers* outgoingMidiBuffers;
	VoiceTransmissionOptions* transmitOptions;


public:
	ExposedParamsRandomizationMethods() = delete;

	explicit ExposedParamsRandomizationMethods(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
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

	void applyNewSettingToExposedParameterAfterDelay(uint8 newSetting, Identifier paramID, int delayInMs);
	void randomizeArpAndSeqOnOffParametersAfterDelay(int delayInMs);

	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsRandomizationMethods)
};