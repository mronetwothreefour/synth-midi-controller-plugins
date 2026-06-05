#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Wheel_Mod_B.h"

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_B
{
public: bool modifying_osc_pitch_fine;
public: bool modifying_osc_2_pitch_eg_int;
public: bool modifying_tempo;

//==============================================================================
public: explicit Slider_Wheel_Mod_P(Data_Hub_P* hub);

private: void alt_increment_value(double increment, double& value) override;
private: void ctrl_increment_value(double increment, double& value) override;
};