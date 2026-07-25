#pragma once

#include "G_WIDG_Sli_Display_Exp_G.h"

class Slider_Display_Exposed_P :
	public Slider_Display_Exposed_G
{
//==============================================================================
public: Slider_Display_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub,
								 Slider_Wheel_Mod_P* parent_slider);

private: void on_editor_show() override;
private: void set_text_to_stored_choice() override;
private: void on_text_change() override;

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Display_Exposed_P)
};
