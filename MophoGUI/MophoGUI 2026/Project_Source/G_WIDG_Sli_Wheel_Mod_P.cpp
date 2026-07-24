#include "G_WIDG_Sli_Wheel_Mod_P.h"

#include "C_ID_P.h"

using Key = KeyPress;

Slider_Wheel_Mod_P::Slider_Wheel_Mod_P(UndoManager* u_m, Ctrl_Type ctrl_type) :
	Slider_Wheel_Mod_G{ u_m },
	modifying_osc_shape{ ctrl_type == Ctrl_Type::knob_osc_shape },
	modifying_seq_step{ ctrl_type == Ctrl_Type::seq_step_trk_1 || ctrl_type == Ctrl_Type::seq_step },
	modifying_seq_trk_1{ ctrl_type == Ctrl_Type::seq_step_trk_1 }
{
	if (modifying_osc_shape)
		setComponentID(ID::knob_osc_shape);
	if (modifying_seq_step)
		setComponentID(modifying_seq_trk_1 ? ID::knob_seq_step_trk_1 : ID::knob_seq_step);
}

void Slider_Wheel_Mod_P::shift_increment_value(double increment, double& value) {
	if (modifying_pitch)
		increment *= modifying_seq_step ? 24.0 : 12.0;
	else
		increment *= 10.0;
	value += increment;
}

void Slider_Wheel_Mod_P::mouseDown(const MouseEvent& e) {
	auto mods = e.mods;
	if (modifying_osc_shape && mods == Mods::ctrlModifier + Mods::leftButtonModifier) {
		if (Key::isKeyCurrentlyDown('0') || Key::isKeyCurrentlyDown(Key::numberPad0)) {
			setValue(0.0, sendNotification);
		}
		if (Key::isKeyCurrentlyDown('1') || Key::isKeyCurrentlyDown(Key::numberPad1)) {
			setValue(1.0, sendNotification);
		}
		if (Key::isKeyCurrentlyDown('2') || Key::isKeyCurrentlyDown(Key::numberPad2)) {
			setValue(2.0, sendNotification);
		}
		if (Key::isKeyCurrentlyDown('3') || Key::isKeyCurrentlyDown(Key::numberPad3)) {
			setValue(3.0, sendNotification);
		}
		if (Key::isKeyCurrentlyDown('4') || Key::isKeyCurrentlyDown(Key::numberPad4)) {
			setValue(54.0, sendNotification);
		}
	}
	if (modifying_seq_step) {
		if (mods == Mods::ctrlModifier + Mods::leftButtonModifier)
			setValue(126.0, sendNotification);
		if (modifying_seq_trk_1 && mods == Mods::altModifier + Mods::leftButtonModifier)
			setValue(127.0, sendNotification);
	}
	Slider::mouseDown(e);
}
