#pragma once

#include <JuceHeader.h>



class GUILookAndFeel :
	public LookAndFeel_V4
{
public:
	GUILookAndFeel() = default;
	void drawRotarySlider(Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;
	void drawLinearSlider(Graphics& g, int x, int y, int w, int h, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle sliderStyle, Slider& slider) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUILookAndFeel)
};