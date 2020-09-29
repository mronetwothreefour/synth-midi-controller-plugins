#pragma once

#include <JuceHeader.h>



class GUILookAndFeel :
	public LookAndFeel_V4
{
public:
	GUILookAndFeel() = default;
	Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override;
	void drawTooltip(Graphics& g, const String& text, int width, int height) override;
	TextLayout layoutTooltipText(const String& text, Colour colour) noexcept;
	void drawButtonBackground(Graphics& g, Button& button, const Colour& background, bool isHighlighted, bool isDown) override;
	void drawButtonText(Graphics& g, TextButton& button, bool isHighlighted, bool isDown) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUILookAndFeel)
};