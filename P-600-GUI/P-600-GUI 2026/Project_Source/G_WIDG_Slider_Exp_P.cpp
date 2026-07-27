#include "G_WIDG_Slider_Exp_P.h"

#include "C_ID_P.h"

Slider_Exposed_P::Slider_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub) :
	Slider_Exposed_G{ param_id, hub }
{
	if (ctrl_type == Ctrl_Type::knob_osc_pitch)
		for_pitch = true;
	if (ctrl_type == Ctrl_Type::switch_2_pole || ctrl_type == Ctrl_Type::switch_3_pole) {
		removeChildComponent(&display);
		if (ctrl_type == Ctrl_Type::switch_2_pole)
			setComponentID(ID::switch_2_pole);
		if (ctrl_type == Ctrl_Type::switch_3_pole)
			setComponentID(ID::switch_3_pole);
	}
}
