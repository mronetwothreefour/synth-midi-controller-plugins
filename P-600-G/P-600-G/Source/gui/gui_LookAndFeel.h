#pragma once

#include <JuceHeader.h>



class GUILookAndFeel :
	public LookAndFeel_V4
{
public:
	GUILookAndFeel() = default;
	void drawRotarySlider(Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;
	void drawLinearSlider(Graphics& g, int x, int y, int w, int h, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle sliderStyle, Slider& slider) override;
	void drawTooltip(Graphics& g, const String& text, int width, int height) override;
	Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override;
	TextLayout layoutTooltipText(const String& text, Colour colour) noexcept;
	void drawButtonBackground(Graphics& g, Button& button, const Colour& background, bool isHighlighted, bool isDown) override;
	const char* getButtonImageData(Button& button, bool isDown);
	size_t getButtonImageDataSize(Button& button, bool isDown);
	void drawButtonText(Graphics& g, TextButton& button, bool isHighlighted, bool isDown) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUILookAndFeel)
};