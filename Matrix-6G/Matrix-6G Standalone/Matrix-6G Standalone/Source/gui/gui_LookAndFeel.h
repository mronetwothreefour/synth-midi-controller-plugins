#pragma once

#include <JuceHeader.h>



class GUILookAndFeel :
	public LookAndFeel_V4
{
public:
	GUILookAndFeel() = default;
	//void drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override;
	void drawRotarySlider(Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;
	//void drawTooltip(Graphics& g, const String& text, int width, int height) override;
	//Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override;
	//TextLayout layoutTooltipText(const String& text, Colour colour) noexcept;
	//void drawButtonBackground(Graphics& g, Button& button, const Colour& background, bool isHighlighted, bool isDown) override;
	//const char* getButtonImageData(Button& button, bool isDown);
	//size_t getButtonImageDataSize(Button& button, bool isDown);
	void drawButtonText(Graphics& g, TextButton& button, bool isHighlighted, bool isDown) override;
	void drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) override;
	//void drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, const bool isTicked, const bool isEnabled, const bool isHighlighted, const bool isDown) override;
	void drawComboBox(Graphics& g, int width, int height, bool isDown, int x, int y, int w, int h, ComboBox& comboBox) override;
	PopupMenu::Options getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) override;
	void drawPopupMenuBackground(Graphics& g, int w, int h) override;
	//void drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive, const bool isHighlighted, const bool isTicked,
	//	const bool hasSubMenu, const String& text, const String& shortcutText, const Drawable* icon, const Colour* const textColor) override;
	void getIdealPopupMenuItemSize(const String& text, const bool isSeparator, int itemHeight, int& idealWidth, int& idealHeight) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUILookAndFeel)
};