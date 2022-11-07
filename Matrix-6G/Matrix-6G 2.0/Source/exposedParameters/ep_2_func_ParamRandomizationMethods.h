#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;
using MM_Type = MatrixModParamType;

class ExposedParameters;
class ParamRandomizationOptions;
class InfoForExposedParameters;
class MatrixModOptions;
class Outgoing_MIDI_Buffers;
class UnexposedParameters;
class VoiceTransmissionOptions;

class ParamRandomizationMethods :
	private Timer
{
	ExposedParameters* exposedParams;
	AudioProcessorValueTreeState* state;
	MatrixModOptions* matrixModOptions;
	ParamRandomizationOptions* randomization;
	InfoForExposedParameters* info;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	VoiceTransmissionOptions* transmitOptions;


public:
	ParamRandomizationMethods() = delete;

	ParamRandomizationMethods(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void randomizeAllUnlockedParameters();
	void randomizeExposedParameter(uint8 paramIndex);
	void randomizeMatrixModParameter(int modNum, MM_Type paramType);

private:
	uint8 randomlyChooseNewSettingForExposedParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForBinaryExposedParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForNonBinaryExposedParam(uint8 paramIndex);
	void applyNewSettingToExposedParameterAfterDelay(uint8 newSetting, Identifier paramID, int delayInMs);

	uint8 randomlyChooseNewSettingForMatrixModParam(int modNum, MM_Type paramType);
	void applyNewSettingToMatrixModParam(uint8 newSetting, int modNum, MM_Type paramType);

	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ParamRandomizationMethods)
};