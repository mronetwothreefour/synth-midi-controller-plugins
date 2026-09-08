#include "G_WIDGET_Ctrl_Slider_P.h"

#include "C_NAME_P.h"

using namespace WIDGET;

Ctrl_Slider::Ctrl_Slider(const String& param_id, Value param_val, Data_Hub* hub) :
	Ctrl_Slider_A{ param_id, param_val, hub }
{
	auto n = getName();
	if (n == NAME::knob_pitch)
		for_pitch = true;
	if (n == NAME::switch_2_pole || n == NAME::switch_3_pole)
		removeChildComponent(&label);
}
