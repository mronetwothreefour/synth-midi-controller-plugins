#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Wheel_Mod_B.h"

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_B
{
public: bool modifying_osc_shape;
public: bool modifying_seq_step;
public: bool modifying_seq_track_1;

//==============================================================================
public: explicit Slider_Wheel_Mod_P(Data_Hub_P* hub, Ctrl_Type ctrl_type);

private: void shift_increment_value(double increment, double& value) override;

public: void mouseDown(const MouseEvent& e) override;
};