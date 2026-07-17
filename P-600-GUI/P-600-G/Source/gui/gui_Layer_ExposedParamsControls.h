#pragma once

#include <JuceHeader.h>

#include "../widgets_ControlsForParameters/widget_ControlsForExposedParameters.h"



class UnexposedParameters;

class ExposedParamsControlsLayer :
	public Component,
	private ControlsForExposedParameters
{
public:
	ExposedParamsControlsLayer() = delete;

	ExposedParamsControlsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	~ExposedParamsControlsLayer() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamsControlsLayer)
};