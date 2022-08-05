#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"
#include "../tooltipSetters/tooltipSetter_ForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class LinearSliderWithExposedParamAttacher :
	public Component
{
protected:
	uint8 param;
	LinearSliderWithMouseWheelModAndReversedRange slider;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipSetterForExposedParamSliders tooltipSetter;
	IntToContextualStringConverter* converter;

public:
	LinearSliderWithExposedParamAttacher() = delete;

	LinearSliderWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams);
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LinearSliderWithExposedParamAttacher)
};


