#include "G_WIDGET_Sli_Wheel_Mod_P.h"

#include "C_ID_Main_P.h"

using namespace WIDGET;

Slider_Wheel_Mod::Slider_Wheel_Mod(const std::string& param_id, Value param_value, Data_Hub* hub) :
	Slider_Wheel_Mod_A{ param_id, param_value, hub },
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
