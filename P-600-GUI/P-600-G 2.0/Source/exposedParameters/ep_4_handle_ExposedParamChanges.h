#pragma once

#include <JuceHeader.h>
#include "ep_2_func_ExposedParamsRandomizationMethods.h"

using Randomize = ExposedParamsRandomizationMethods;

class ExposedParameters;
class InfoForExposedParameters;
class Outgoing_MIDI_Buffers;
class UnexposedParameters;
class VoiceTransmissionOptions;

class ExposedParamChangesHandler :
	private AudioProcessorParameter::Listener
{
	ExposedParameters* exposedParams;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	Randomize* randomize;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	VoiceTransmissionOptions* transmitOptions;

public:
	ExposedParamChangesHandler() = delete;

	ExposedParamChangesHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void parameterValueChanged(int changedParamIndex, float newValue) override;
	void parameterGestureChanged(int paramIndex, bool gestureIsStarting) override;

public:
	~ExposedParamChangesHandler();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChangesHandler)
};