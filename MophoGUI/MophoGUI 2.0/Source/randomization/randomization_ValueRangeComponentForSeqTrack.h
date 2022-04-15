#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class ValueRangeComponentForSeqTrack :
	public Component,
	public Slider::Listener,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMod knob_ForMinStepValue;
	RendererForKnobValueStrings valueDisplay_ForMinStepValue;
	RotarySliderWithMouseWheelMod knob_ForMaxStepValue;
	RendererForKnobValueStrings valueDisplay_ForMaxStepValue;

public:
	ValueRangeComponentForSeqTrack() = delete;

	ValueRangeComponentForSeqTrack(int trackNum, UnexposedParameters* unexposedParams);
	void generateTooltips();
	void resized() override;
	void sliderValueChanged(Slider* slider) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~ValueRangeComponentForSeqTrack();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ValueRangeComponentForSeqTrack)
};