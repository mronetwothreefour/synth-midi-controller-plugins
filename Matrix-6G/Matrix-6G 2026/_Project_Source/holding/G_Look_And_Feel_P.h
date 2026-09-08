#pragma once

#include "G_Look_And_Feel_A.h"

class Look_And_Feel :
	public Look_And_Feel_A
{
//==============================================================================
public: explicit Look_And_Feel(float& scale_factor);

public: void positionComboBoxText(ComboBox& cbox, Label& lbl) override;
public: PopupMenu::Options getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& lbl) override;
public: void drawPopupMenuItemWithOptions(Graphics& g, const Rectangle<int>& area, 
										  bool hilited, const PopupMenu::Item& item,
										  const PopupMenu::Options& o) override;

public: void draw_label_p(Graphics& g, Label& lbl, String& lbl_name) override;

public: void drawRotarySlider(Graphics& /*g*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/,
							  float /*current_pos*/, const float /*min_angle*/,
							  const float /*max_angle*/, Slider& /*s*/) override {}
public: void drawLinearSlider(Graphics& g, int x, int y, int w, int h, float current_pos,
							  float min_pos, float max_pos, const Slider::SliderStyle style,
							  Slider& s) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Look_And_Feel)
};
