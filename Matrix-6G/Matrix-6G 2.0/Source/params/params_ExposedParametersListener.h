#pragma once

#include <JuceHeader.h>




class PatchTransmissionOptions;
class UnexposedParameters;

class ExposedParametersListener :
	private AudioProcessorValueTreeState::Listener
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	PatchTransmissionOptions* patchTransmissionOptions;

public:
	ExposedParametersListener() = delete;

	ExposedParametersListener(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void parameterChanged(const String& parameterID, float newValue) override;

public:
	~ExposedParametersListener();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParametersListener)
};