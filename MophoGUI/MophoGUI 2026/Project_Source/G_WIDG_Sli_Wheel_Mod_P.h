#pragma once

#include "C_ENUM_P.h"
#include "G_WIDG_Sli_Wheel_Mod_G.h"

using namespace ENUM;

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_G
{
public: bool for_osc_shape;
public: bool for_seq_step;
public: bool for_seq_trk_1;

//==============================================================================
public: Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type);

private: void shift_increment_value(double increment, double& value) override;

public: void mouseDown(const MouseEvent& e) override;
};