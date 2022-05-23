#pragma once

#include <JuceHeader.h>



class MophoLookAndFeel :
	public LookAndFeel_V4
{
public:
	MophoLookAndFeel() = default;

	void drawRotarySlider(
		Graphics& g, int x, int y, int w, int h, float sliderPos, const float startAngle, const float endAngle, Slider& slider) override;

	void drawLabel(Graphics& g, Label& label) override;

	void drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) override;
	void drawTickBox(
		Graphics& g, Component& component, float x, float y, float w, float h, const bool isTicked, 
		const bool isEnabled, const bool isHighlighted, const bool isDown) override;

	void drawComboBox(Graphics& g, int width, int height, bool isDown, int x, int y, int w, int h, ComboBox& comboBox) override;
	void positionComboBoxText(ComboBox& box, Label& label) override;
	PopupMenu::Options getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) override;
	void drawPopupMenuBackground(Graphics& g, int w, int h) override;
	void drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive, 
		const bool isHighlighted, const bool isTicked, const bool hasSubMenu, const String& text, const String& shortcutText,
		const Drawable* icon, const Colour* const textColor) override;
	void getIdealPopupMenuItemSize(const String& text, const bool isSeparator, int itemHeight, int& idealWidth, int& idealHeight) override;


private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MophoLookAndFeel)
};

