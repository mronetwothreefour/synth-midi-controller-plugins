#include "G_WIDGET_Sli_Wheel_Mod_P.h"

#include "C_NAME_P.h"

using namespace WIDGET;

Slider_Wheel_Mod::Slider_Wheel_Mod(const String& param_id, UndoManager* u_m) :
	Slider_Wheel_Mod_A{ param_id, u_m }
{
	if (getName() == NAME::switch_2_pole || getName() == NAME::switch_3_pole)
		setSliderStyle(SliderStyle::LinearVertical);
}
