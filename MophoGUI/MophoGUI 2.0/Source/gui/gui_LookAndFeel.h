#pragma once

#include <JuceHeader.h>



class MophoLookAndFeel :
	public LookAndFeel_V4
{
public:
	MophoLookAndFeel() = default;

	void drawRotarySlider(
		Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;

	void drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) override;
	void drawTickBox(
		Graphics& g, Component& component, float x, float y, float w, float h, const bool isTicked, 
		const bool isEnabled, const bool isHighlighted, const bool isDown) override;


private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MophoLookAndFeel)
};

