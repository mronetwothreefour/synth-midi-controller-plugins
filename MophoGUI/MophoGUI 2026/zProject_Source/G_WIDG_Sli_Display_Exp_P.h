#pragma once

#include "G_WIDG_Sli_Display_Exp_G.h"

class Slider_Display_Exposed_P :
	public Slider_Display_Exposed_G
{
//==============================================================================
public: Slider_Display_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub,
								 Slider_Wheel_Mod_P* parent_slider);

private: void on_editor_show() override;
public: void set_text_to_stored_choice() override;
private: void on_text_change() override;
private: float text_to_float_osc_pitch_and_lpf_freq(const String& text);
private: float text_to_float_osc_shape(const String& text);
private: float text_to_float_lfo_freq(const String& text);
private: float text_to_float_seq_step(const String& text);
private: float text_to_float_other(const String& text);

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Display_Exposed_P)
};
