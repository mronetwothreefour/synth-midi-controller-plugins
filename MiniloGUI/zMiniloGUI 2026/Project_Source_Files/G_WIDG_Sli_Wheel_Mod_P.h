#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Sli_Wheel_Mod_B.h"
#include "C_ENUM_P.h"

using namespace ENUM;

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_B
{
public: bool modifying_osc_pitch_fine;
public: bool modifying_osc_2_pitch_eg_int;
public: bool modifying_tempo;
private: Array<int> display_values;

//==============================================================================
public: explicit Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type);

private: void mod_value(double increment, double& current_slider_value) override;
private: void alt_mod_value(double increment, double& current_slider_value) override;
private: void ctrl_mod_value(double increment, double& current_slider_value) override;
private: void shift_increment_value(double increment, double& value) override;
private: int get_best_display_value_match(int value, int increment, int min, int max);
private: int get_next_multiple_of_100(int increment, int value);
};