#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class AllowedUnsyncedFreqComponent :
	public Component,
	public Slider::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMod knob_ForMinUnsyncedFreq;
	RendererForKnobValueStrings valueDisplay_ForMinUnsyncedFreq;
	RotarySliderWithMouseWheelMod knob_ForMaxUnsyncedFreq;
	RendererForKnobValueStrings valueDisplay_ForMaxUnsyncedFreq;

public:
	AllowedUnsyncedFreqComponent() = delete;

	AllowedUnsyncedFreqComponent(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void resized() override;
	void sliderValueChanged(Slider* slider) override;
	~AllowedUnsyncedFreqComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedUnsyncedFreqComponent)
};