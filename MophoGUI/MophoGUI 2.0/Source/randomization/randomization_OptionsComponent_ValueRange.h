#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class RandomizationOptionsComponent_ValueRange :
	public Component,
	public Slider::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMod knob_ForMinValue;
	RendererForKnobValueStrings valueDisplay_ForMinValue;
	RotarySliderWithMouseWheelMod knob_ForMaxValue;
	RendererForKnobValueStrings valueDisplay_ForMaxValue;
	TextButton button_ForClosingComponent;

public:
	RandomizationOptionsComponent_ValueRange() = delete;

	RandomizationOptionsComponent_ValueRange(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void sliderValueChanged(Slider* slider) override;
	void hideThisComponent();
	~RandomizationOptionsComponent_ValueRange();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_ValueRange)
};