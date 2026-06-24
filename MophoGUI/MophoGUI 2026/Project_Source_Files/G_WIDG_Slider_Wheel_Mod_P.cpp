#include "G_WIDG_Slider_Wheel_Mod_P.h"

Slider_Wheel_Mod_P::Slider_Wheel_Mod_P(Data_Hub_P* hub, Ctrl_Type ctrl_type) :
	Slider_Wheel_Mod_B{ hub },
	modifying_seq_step{ ctrl_type == Ctrl_Type::seq_step }
{}

void Slider_Wheel_Mod_P::shift_increment_value(double increment, double& value) {
	if (modifying_pitch)
		increment *= modifying_seq_step ? 24.0 : 12.0;
	else
		increment *= 10.0;
	value += increment;
}

void Slider_Wheel_Mod_P::mouseDown(const MouseEvent& e) {
	if (getComponentID() == ID::knob_osc_shape.toString() && e.mods.isCtrlDown()) {
		if (KeyPress::isKeyCurrentlyDown('0') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad0)) {
			setValue(0.0, sendNotification);
		}
		if (KeyPress::isKeyCurrentlyDown('1') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad1)) {
			setValue(1.0, sendNotification);
		}
		if (KeyPress::isKeyCurrentlyDown('2') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad2)) {
			setValue(2.0, sendNotification);
		}
		if (KeyPress::isKeyCurrentlyDown('3') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad3)) {
			setValue(3.0, sendNotification);
		}
		if (KeyPress::isKeyCurrentlyDown('4') || KeyPress::isKeyCurrentlyDown(KeyPress::numberPad4)) {
			setValue(54.0, sendNotification);
		}
	}
	Slider::mouseDown(e);
}
