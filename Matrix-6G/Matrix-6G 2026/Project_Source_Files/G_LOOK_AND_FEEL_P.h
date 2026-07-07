#pragma once

#include <JuceHeader.h>

#include "G_LOOK_AND_FEEL_B.h"

class Look_And_Feel_P :
	public Look_And_Feel_B
{
//==============================================================================
public: explicit Look_And_Feel_P(float& scale_factor);

public: void positionComboBoxText(ComboBox& cbox, Label& lbl) override;
public: PopupMenu::Options getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& lbl) override;
public: void drawPopupMenuBackground(Graphics& g, int w, int h) override;
public: void drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool separator,
							   const bool active, const bool hilited, const bool ticked, 
							   const bool has_submenu, const String& txt, const String& shortcut_txt,
							   const Drawable* icon, const Colour* const txt_clr) override;
public: void getIdealPopupMenuItemSizeWithOptions(const String& txt, bool separator,
												  int standard_h, int& ideal_w, int& ideal_h,
												  const PopupMenu::Options& o) override;

public: void draw_label_p(Graphics& g, Label& lbl, String& lbl_id) override;

public: void drawRotarySlider(Graphics& /*g*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float /*current_pos*/,
							  const float /*min_angle*/, const float /*max_angle*/, Slider& /*s*/) override {}
public: void drawLinearSlider(Graphics& g, int x, int y, int w, int h, float current_pos, float min_pos, 
							  float max_pos, const Slider::SliderStyle style, Slider& s) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Look_And_Feel_P)
};
