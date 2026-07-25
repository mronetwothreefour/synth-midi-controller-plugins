#pragma once

#include "G_WIDG_Slider_Exp_G.h"

class Slider_Exposed_P :
	public Slider_Exposed_G
{
//==============================================================================
public: Slider_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub) :
	Slider_Exposed_G{ param_id, hub }
{
	if (ctrl_type == Ctrl_Type::slider_osc_pitch)
		modifying_pitch = true;
}

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Exposed_P)
};