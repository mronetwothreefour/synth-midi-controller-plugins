#pragma once

#include <JuceHeader.h>

class MatrixLookAndFeel :
	public LookAndFeel_V4
{
public:
	MatrixLookAndFeel() = default;

	void drawLabel(Graphics& g, Label& label) override;

	void drawRotarySlider(
		Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;

	void drawLinearSlider(
		Graphics& g, int x, int y, int width, int height, float sliderPos, float minSliderPos, 
		float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override;

	void drawComboBox(Graphics& g, int width, int height, bool isDown, int x, int y, int w, int h, ComboBox& comboBox) override;
	PopupMenu::Options getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) override;
	void drawPopupMenuBackground(Graphics& g, int w, int h) override;
	void drawPopupMenuItem(
		Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive, 
		const bool isHighlighted, const bool isTicked, const bool hasSubMenu, const String& text, 
		const String& shortcutText, const Drawable* icon, const Colour* const textColor) override;
	void getIdealPopupMenuItemSize(const String& text, const bool isSeparator, int itemHeight, int& idealWidth, int& idealHeight) override;

	void drawTooltip(Graphics& g, const String& text, int width, int height) override;
	Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override;
	TextLayout layoutTooltipText(const String& text, Colour colour) noexcept;
};