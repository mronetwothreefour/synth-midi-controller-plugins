#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"
#include "../tooltipSetters/tooltipSetter_ForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class RotarySliderWithExposedParamAttacher : 
	public Component
{
protected:
	uint8 param;
	RotarySliderWithMouseWheelMod slider;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipSetterForExposedParamSliders tooltipSetter;
	IntToContextualStringConverter* converter;

public:
	RotarySliderWithExposedParamAttacher() = delete;

	RotarySliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams);
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void paint(Graphics& g) override;
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RotarySliderWithExposedParamAttacher)
};


