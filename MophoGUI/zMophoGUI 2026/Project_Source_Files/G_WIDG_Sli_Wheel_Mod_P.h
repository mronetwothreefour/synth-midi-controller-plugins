#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Sli_Wheel_Mod_B.h"
#include "C_ENUM_P.h"

using namespace ENUM;

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_B
{
public: bool modifying_osc_shape;
public: bool modifying_seq_step;
public: bool modifying_seq_track_1;

//==============================================================================
public: Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type);

private: void shift_increment_value(double increment, double& value) override;

public: void mouseDown(const MouseEvent& e) override;
};