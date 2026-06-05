#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Wheel_Mod_B.h"

class Slider_Wheel_Mod_P :
	public Slider_Wheel_Mod_B
{
//==============================================================================
public: explicit Slider_Wheel_Mod_P(Data_Hub_P* hub) :
					 Slider_Wheel_Mod_B{ hub }
				 {}
};