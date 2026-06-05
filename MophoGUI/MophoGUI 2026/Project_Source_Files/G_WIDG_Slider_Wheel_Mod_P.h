#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Wheel_Mod_B.h"

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_B
{
public: bool modifying_seq_step;

//==============================================================================
public: explicit Slider_Wheel_Mod_P(Data_Hub_P* hub) :
					 Slider_Wheel_Mod_B{ hub },
					 modifying_seq_step{ false }
				 {}

private: void shift_increment_value(double increment, double& value) override {
				if (modifying_pitch)
					increment *= modifying_seq_step ? 24.0 : 12.0;
				else
					increment *= 10.0;
				value += increment;
			}
};