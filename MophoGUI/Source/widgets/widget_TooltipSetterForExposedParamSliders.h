#pragma once

#include <JuceHeader.h>

#include "widget_TooltipSetter.h"



class TooltipSetterForExposedParamSliders :
	public TooltipSetter,
	public Slider::Listener
{
	Slider& slider;
	uint8 param;
	IntToContextualStringConverter* converter;

public:
	TooltipSetterForExposedParamSliders() = delete;

	TooltipSetterForExposedParamSliders(Slider& slider, uint8 param);
	~TooltipSetterForExposedParamSliders();
	void sliderValueChanged(Slider* sliderThatChanged) override;

private:
	void setTooltip() noexcept override;
	String generateTooltipText() noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamSliders)
};
