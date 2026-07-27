#pragma once

#include "C_ENUM_P.h"
#include "G_WIDG_Sli_Wheel_Mod_G.h"

using namespace ENUM;

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_G
{
public: bool for_lpf_eg_int;
public: bool for_osc_2_pitch_eg_int;
public: bool for_osc_pitch_fine;
public: bool for_tempo;
private: Voice_Mode for_voice_mode;
public: bool for_non_standard_knob;
private: Array<int> display_values;

//==============================================================================
public: explicit Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type);

public: void update_for_voice_mode(Voice_Mode new_mode);
private: void mod_value(double increment, double& current_slider_value) override;
private: void alt_mod_value(double increment, double& current_slider_value) override;
private: void ctrl_mod_value(double increment, double& current_slider_value) override;
private: void shift_increment_value(double increment, double& value) override;
private: int get_best_display_value_match(int value, int increment, int min, int max);
private: int get_next_multiple_of_100(int increment, int value);
};