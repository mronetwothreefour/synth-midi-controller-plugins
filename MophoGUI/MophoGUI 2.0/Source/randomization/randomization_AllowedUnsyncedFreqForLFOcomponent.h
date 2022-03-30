#pragma once

#include <JuceHeader.h>

#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class AllowedUnsyncedFreqForLFOcomponent :
	public Component,
	public Slider::Listener
{
	int lfoNum;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMod knob_ForMinUnsyncedFreq;
	RotarySliderWithMouseWheelMod knob_ForMaxUnsyncedFreq;

public:
	AllowedUnsyncedFreqForLFOcomponent() = delete;

	AllowedUnsyncedFreqForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams);
	void resized() override;
	void sliderValueChanged(Slider* slider) override;
	~AllowedUnsyncedFreqForLFOcomponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedUnsyncedFreqForLFOcomponent)
};