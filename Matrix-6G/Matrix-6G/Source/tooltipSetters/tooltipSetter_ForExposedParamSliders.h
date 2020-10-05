#pragma once

#include <JuceHeader.h>

#include "tooltipSetter_Base.h"
#include "../params/params_IntToContextualStringConverters.h"



class TooltipSetterForExposedParamSliders :
	public TooltipSetter,
	public Slider::Listener
{
	Slider& slider;
	uint8 param;
	UnexposedParameters* unexposedParams;
	IntToContextualStringConverter* converter;

public:
	TooltipSetterForExposedParamSliders() = delete;

	TooltipSetterForExposedParamSliders(Slider& slider, uint8 param, UnexposedParameters* unexposedParams);
	void sliderValueChanged(Slider* sliderThatChanged) override;

private:
	void setTooltip() override;
	String generateTooltipText() override;

public:
	~TooltipSetterForExposedParamSliders();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamSliders)
};
