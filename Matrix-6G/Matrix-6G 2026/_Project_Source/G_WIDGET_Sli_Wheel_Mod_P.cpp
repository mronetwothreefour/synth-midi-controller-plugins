#include "G_WIDGET_Sli_Wheel_Mod_P.h"

#include "C_ID_EXP_P.h"

using namespace WIDGET;

Slider_Wheel_Mod::Slider_Wheel_Mod(const String& param_id, UndoManager* u_m) :
	Slider_Wheel_Mod_A{ param_id, u_m },
	inverted_range{ param_id == ID::exp_osc_balance }
{
	if (inverted_range) {
		setSliderStyle(SliderStyle::LinearHorizontal);
		setSliderSnapsToMousePosition(false);
	}
}

double Slider_Wheel_Mod::proportionOfLengthToValue(double proportion) {
	return Slider::proportionOfLengthToValue(inverted_range ? 1.0 - proportion : proportion);
}

double Slider_Wheel_Mod::valueToProportionOfLength(double value) {
	auto proportion = Slider::valueToProportionOfLength(value);
	return inverted_range ? 1.0 - proportion : proportion;
}
