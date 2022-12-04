#pragma once

#include <JuceHeader.h>

#include "ep_2_func_ParamRandomizationMethods.h"
#include "ep_2_tree_ParamRandomizationOptions.h"

using Randomize = ParamRandomizationMethods;

class ExposedParameters;
class InfoForExposedParameters;
class Outgoing_MIDI_Buffers;
class UnexposedParameters;
class VoiceTransmissionOptions;

class ExposedParamChangesHandler :
	private AudioProcessorParameter::Listener
{
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