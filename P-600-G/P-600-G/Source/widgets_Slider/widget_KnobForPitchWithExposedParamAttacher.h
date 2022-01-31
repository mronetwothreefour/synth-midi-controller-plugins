#pragma once

#include <JuceHeader.h>

#include "widget_ModifiedJuceSliders.h"
#include "../tooltips/tooltipSetter_ForExposedParamSliders.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobForPitchWithExposedParamAttacher : public Component
{
protected:
	uint8 param;
	RotarySliderWithMouseWheelModForPitch slider;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	KnobForPitchWithExposedParamAttacher() = delete;

	KnobForPitchWithExposedParamAttacher(uint8 param, UnexposedParameters* unexposedParams);
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobForPitchWithExposedParamAttacher)
};


