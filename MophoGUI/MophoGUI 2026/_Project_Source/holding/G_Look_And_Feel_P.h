#pragma once

#include "G_Look_And_Feel_A.h"

class Look_And_Feel :
	public Look_And_Feel_A
{
//==============================================================================
public: explicit Look_And_Feel(float& scale_factor);

public: void positionComboBoxText(ComboBox& cbox, Label& lbl) override;
public: PopupMenu::Options getOptionsForComboBoxPopupMenu(ComboBox& cbox, Label& lbl) override;
public: void drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool separator,
							   const bool active, const bool hilited, const bool ticked, 
							   const bool has_submenu, const String& txt, const String& shortcut_txt,
							   const Drawable* icon, const Colour* const txt_clr) override;

public: void draw_label_p(Graphics& g, Label& lbl, String& lbl_name) override;

public: void drawRotarySlider(Graphics& g, int x, int y, int w, int h, float current_pos,
							  const float min_angle, const float max_angle, Slider& s) override;

public: void drawTickBox(Graphics& g, Component& c, float x, float y, float w, float h,
						 const bool ticked, const bool enabled, const bool hilited,
						 const bool down) override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Look_And_Feel)
};