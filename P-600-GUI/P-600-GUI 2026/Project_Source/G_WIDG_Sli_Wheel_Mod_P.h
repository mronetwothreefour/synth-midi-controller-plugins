#pragma once

#include "C_ENUM_P.h"
#include "G_WIDG_Sli_Wheel_Mod_G.h"

using namespace ENUM;

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_G
{
//==============================================================================
public: explicit Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type) :
					 Slider_Wheel_Mod_G{ u_m }
				 {
				 	 if (ctrl_type == Ctrl_Type::switch_2_pole || ctrl_type == Ctrl_Type::switch_3_pole)
				 		 setSliderStyle(SliderStyle::LinearVertical);
				 }
};