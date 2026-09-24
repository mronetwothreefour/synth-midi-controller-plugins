#include "G_WIDGET_Sli_Wheel_Mod_P.h"

#include "C_NAME_P.h"

using namespace WIDGET;

Slider_Wheel_Mod::Slider_Wheel_Mod(const std::string& param_id, Value param_value, Data_Hub* hub) :
	Slider_Wheel_Mod_A{ param_id, param_value, hub }
{
	if (getName().startsWith("ctr_sli_sw"))
		setSliderStyle(SliderStyle::LinearVertical);
}
