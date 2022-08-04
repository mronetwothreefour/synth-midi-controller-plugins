#pragma once

#include <JuceHeader.h>

#include "ep_2_func_ExposedParamsRandomizationMethods.h"

using Randomize = ExposedParamsRandomizationMethods;

class ExposedParameters;
class InfoForExposedParameters;
class UnexposedParameters;
class VoiceTransmissionOptions;

class ExposedParamChangesHandler :
	private AudioProcessorParameter::Listener
{
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	Randomize* randomize;
	UnexposedParameters* unexposedParams;
	VoiceTransmissionOptions* transmitOptions;

public:
	ExposedParamChangesHandler() = delete;

	ExposedParamChangesHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void parameterValueChanged(int changedParamIndex, float newValue) override;
	void parameterGestureChanged(int paramIndex, bool gestureIsStarting) override;
	void arpeggiatorAndSequencerCannotBothBeOn(const Identifier turnedOnParamID);

public:
	~ExposedParamChangesHandler();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChangesHandler)
};