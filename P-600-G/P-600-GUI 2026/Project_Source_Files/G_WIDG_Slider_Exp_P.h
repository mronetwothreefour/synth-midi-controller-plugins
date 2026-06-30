#pragma once

#include <JuceHeader.h>

#include "G_WIDG_Slider_Exp_B.h"

class Slider_Exposed_P :
	public Slider_Exposed_B
{
//==============================================================================
public: Slider_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Slider_Exposed_B{ param_index, hub }
{
	if (ctrl_type == Ctrl_Type::knob_osc_pitch)
		modifying_pitch = true;
	if (ctrl_type == Ctrl_Type::switch_2_pole || ctrl_type == Ctrl_Type::switch_3_pole)
		removeChildComponent(&display);
}

//==============================================================================
private: JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(Slider_Exposed_P)
};