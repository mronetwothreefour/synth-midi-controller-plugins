#pragma once

#include <JuceHeader.h>

#include "widget_KnobValueRenderers.h"
#include "widget_CustomSliders.h"
#include "widget_TooltipSetters.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobWithExposedParamAttacher : public Component
{
protected:
	RotarySliderWithMouseWheelMod slider;
	std::unique_ptr<SliderAttachment> attachment;
	uint8 param;
	TooltipSetterForExposedParamSliders tooltipSetter;

public:
	KnobWithExposedParamAttacher() = delete;

	explicit KnobWithExposedParamAttacher(uint8 param) :
		param{ param },
		tooltipSetter{ slider, param }
	{
		addAndMakeVisible(slider);
		slider.setMouseDragSensitivity(80 + InfoForExposedParameters::get().numberOfStepsFor(param) / 2);
		slider.setComponentID(ID::component_Knob.toString());
	}

	~KnobWithExposedParamAttacher() {
	}

	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams) {
		attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(param).toString(), slider));
	}

	void deleteAttachment() { 
		attachment = nullptr; 
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobWithExposedParamAttacher)
};


