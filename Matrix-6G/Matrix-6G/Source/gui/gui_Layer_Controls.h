#pragma once

#include <JuceHeader.h>

#include "../widgets_ControlsForParameters/widget_ControlsForExposedParameters.h"



class UnexposedParameters;

class ControlsLayer :
	public Component,
	private ControlsForExposedParameters
{
	UnexposedParameters* unexposedParams;

public:
	ControlsLayer() = delete;

	ControlsLayer(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	~ControlsLayer() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlsLayer)
};