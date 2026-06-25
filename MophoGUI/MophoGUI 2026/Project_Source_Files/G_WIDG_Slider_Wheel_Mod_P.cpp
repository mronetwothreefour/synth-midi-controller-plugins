#include "G_WIDG_Slider_Wheel_Mod_P.h"

Slider_Wheel_Mod_P::Slider_Wheel_Mod_P(Data_Hub_P* hub, Ctrl_Type ctrl_type) :
	Slider_Wheel_Mod_B{ hub },
	modifying_osc_shape{ ctrl_type == Ctrl_Type::knob_osc_shape },
	modifying_seq_step{ ctrl_type == Ctrl_Type::seq_step_track_1 || ctrl_type == Ctrl_Type::seq_step },
	modifying_seq_track_1{ ctrl_type == Ctrl_Type::seq_step_track_1 }
{
	if (modifying_osc_shape)
		setComponentID(ID::knob_osc_shape.toString());
	if (modifying_seq_step)
		setComponentID(modifying_seq_track_1 ? ID::knob_seq_step_track_1.toString() : ID::knob_seq_step.toString());
}

void Slider_Wheel_Mod_P::shift_increment_value(double increment, double& value) {
	if (modifying_pitch)
		increment *= modifying_seq_step ? 24.0 : 12.0;
	else
		increment *= 10.0;
	value += increment;
}

void Slider_Wheel_Mod_P::mouseDown(const MouseEvent& e) {
	if (modifying_osc_shape && e.mods.isCtrlDown()) {
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
	if (modifying_seq_step) {
		if (e.mods == ModifierKeys::ctrlModifier + ModifierKeys::leftButtonModifier)
			setValue(126.0, sendNotification);
		if (modifying_seq_track_1 && e.mods == ModifierKeys::ctrlAltCommandModifiers + ModifierKeys::leftButtonModifier)
			setValue(127.0, sendNotification);
	}
	Slider::mouseDown(e);
}
