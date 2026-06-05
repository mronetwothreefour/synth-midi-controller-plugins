#include "G_WIDG_Slider_Wheel_Mod_B.h"

Slider_Wheel_Mod_B::Slider_Wheel_Mod_B(Data_Hub_P* hub) :
	Data_User_P{ hub },
	modifying_pitch{ false }
{}

void Slider_Wheel_Mod_B::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) {
	if (isEnabled()) {
		u_m->beginNewTransaction();
		auto delta{ wheel.deltaY };
		auto new_value{ getValue() };
		auto increment{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f) {
			auto mods = e.mods.getRawFlags();
			switch (mods) {
			case ModifierKeys::altModifier: alt_increment_value(increment, new_value); break;
			case ModifierKeys::ctrlModifier: ctrl_increment_value(increment, new_value); break;
			case ModifierKeys::shiftModifier: shift_increment_value(increment, new_value); break;
			default: default_increment_value(increment, new_value); break;
			}
			setValue(new_value);
		}
		u_m->beginNewTransaction();
	}
}

void Slider_Wheel_Mod_B::alt_increment_value(double increment, double& value) {
	default_increment_value(increment, value);
}

void Slider_Wheel_Mod_B::ctrl_increment_value(double increment, double& value) {
	default_increment_value(increment, value);
}

void Slider_Wheel_Mod_B::default_increment_value(double increment, double& value) {
	value += increment;
}

void Slider_Wheel_Mod_B::shift_increment_value(double increment, double& value) {
	increment *= modifying_pitch ? 12.0 : 10.0;
	value += increment;
}

