#pragma once

#include <JuceHeader.h>

class P_600_LookAndFeel :
	public LookAndFeel_V4
{
public:
	P_600_LookAndFeel() = default;

	void drawRotarySlider(
		Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;

	void drawLinearSlider(
		Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos,
		float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override;

	void drawLabel(Graphics& g, Label& label) override;
	void fillTextEditorBackground(Graphics& g, int w, int h, TextEditor& textEditor) override;
	void drawTextEditorOutline(Graphics& g, int w, int h, TextEditor& textEditor) override;

	void drawTooltip(Graphics& g, const String& text, int width, int height) override;
	Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override;
	TextLayout layoutTooltipText(const String& text, Colour colour) noexcept;
};