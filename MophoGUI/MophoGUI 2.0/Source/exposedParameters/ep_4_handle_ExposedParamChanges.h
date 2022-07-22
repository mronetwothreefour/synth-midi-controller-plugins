#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class InfoForExposedParameters;
class UnexposedParameters;
class VoiceTransmissionOptions;

class ExposedParamChangesHandler :
	private AudioProcessorParameter::Listener
{
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	UnexposedParameters* unexposedParams;
	VoiceTransmissionOptions* voiceTransmit;

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