#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class ValueRangeComponentForLPFfreq :
	public Component,
	public Slider::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMod knob_ForMinValue;
	RendererForKnobValueStrings valueDisplay_ForMinValue;
	RotarySliderWithMouseWheelMod knob_ForMaxValue;
	RendererForKnobValueStrings valueDisplay_ForMaxValue;

public:
	ValueRangeComponentForLPFfreq() = delete;

	explicit ValueRangeComponentForLPFfreq(UnexposedParameters* unexposedParams);
	void resized() override;
	void sliderValueChanged(Slider* slider) override;
	~ValueRangeComponentForLPFfreq();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ValueRangeComponentForLPFfreq)
};