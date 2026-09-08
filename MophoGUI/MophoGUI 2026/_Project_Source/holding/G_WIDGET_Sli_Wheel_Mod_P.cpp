#include "G_WIDGET_Sli_Wheel_Mod_P.h"

#include "C_GET_P.h"
#include "C_NAME_P.h"

using namespace WIDGET;

using Key = KeyPress;

Slider_Wheel_Mod::Slider_Wheel_Mod(const String& param_id, UndoManager* u_m) :
	Slider_Wheel_Mod_A{ param_id, u_m }
{
	auto n = getName();
	for_osc_shape = n == NAME::knob_osc_shape;
	for_seq_step = n == NAME::seq_step || getName() == NAME::seq_step_trk_1;
	for_seq_trk_1 = n == NAME::seq_step_trk_1;
}

void Slider_Wheel_Mod::shift_mod_value(double increment, double& curr_val) {
	if (for_pitch)
		increment *= for_seq_step ? 24.0 : 12.0;
	else
		increment *= 10.0;
	curr_val += increment;
}

void Slider_Wheel_Mod::mouseDown(const MouseEvent& e) {
	auto mods = e.mods;
	if (for_osc_shape && mods == Mods::ctrlModifier + Mods::leftButtonModifier) {
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
	if (for_seq_step) {
		if (mods == Mods::ctrlModifier + Mods::leftButtonModifier)
			setValue(126.0, sendNotification);
		if (for_seq_trk_1 && mods == Mods::altModifier + Mods::leftButtonModifier)
			setValue(127.0, sendNotification);
	}
	Slider::mouseDown(e);
}
