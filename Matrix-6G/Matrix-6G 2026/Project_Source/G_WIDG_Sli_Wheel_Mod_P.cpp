#include "G_WIDG_Sli_Wheel_Mod_P.h"

Slider_Wheel_Mod_P::Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type) :
	Slider_Wheel_Mod_G{ u_m },
	inverted_range{ ctrl_type == Ctrl_Type::slider_osc_balance }
{
	if (ctrl_type == Ctrl_Type::slider_osc_balance) {
		setSliderStyle(SliderStyle::LinearHorizontal);
		setSliderSnapsToMousePosition(false);
	}
}

double Slider_Wheel_Mod_P::proportionOfLengthToValue(double proportion) {
	return Slider::proportionOfLengthToValue(inverted_range ? 1.0 - proportion : proportion);
}

double Slider_Wheel_Mod_P::valueToProportionOfLength(double value) {
	auto proportion = Slider::valueToProportionOfLength(value);
	return inverted_range ? 1.0 - proportion : proportion;
}
