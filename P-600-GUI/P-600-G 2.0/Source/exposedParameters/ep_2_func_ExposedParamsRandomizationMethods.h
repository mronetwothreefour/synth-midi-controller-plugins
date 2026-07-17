#pragma once

#include <JuceHeader.h>

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
	Outgoing_MIDI_Buffers* outgoingBuffers;
	VoiceTransmissionOptions* transmitOptions;


public:
	ExposedParamsRandomizationMethods() = delete;

	ExposedParamsRandomizationMethods(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void randomizeAllUnlockedParameters();
	void randomizeParameter(uint8 paramIndex);

private:
	uint8 randomlyChooseNewSettingForParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForBinaryParam(uint8 paramIndex);
	uint8 randomlyChooseNewSettingForNonBinaryParam(uint8 paramIndex);
	void applyNewSettingToExposedParameterAfterDelay(uint8 newSetting, Identifier paramID, int delayInMs);
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsRandomizationMethods)
};