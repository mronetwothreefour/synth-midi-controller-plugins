#pragma once

#include <JuceHeader.h>

using ExposedParameters = AudioProcessorValueTreeState;



class InfoForExposedParameters;
class UnexposedParameters;
class VoiceTransmissionOptions;

class ExposedParamChangesHandler :
	private AudioProcessorParameter::Listener
{
	ExposedParameters* exposedParams;
	UnexposedParameters* unexposedParams;
	InfoForExposedParameters* info;
	VoiceTransmissionOptions* voiceTransmit;

public:
	ExposedParamChangesHandler() = delete;

	ExposedParamChangesHandler(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void parameterValueChanged(int changedParamIndex, float newValue);
	void parameterGestureChanged(int paramIndex, bool gestureIsStarting);
	void arpeggiatorAndSequencerCannotBothBeOn(Identifier turnedOnParamID);

public:
	~ExposedParamChangesHandler();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChangesHandler)
};