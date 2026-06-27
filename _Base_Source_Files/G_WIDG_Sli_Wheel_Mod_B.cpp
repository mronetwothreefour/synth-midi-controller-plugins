#include "G_WIDG_Sli_Wheel_Mod_B.h"

#include "C_XYWH_P.h"

Slider_Wheel_Mod_B::Slider_Wheel_Mod_B(UndoManager* u_m) :
	u_m{ u_m },
	modifying_pitch{ false }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setRotaryParameters(XYWH::rotary_slider_start_angle, XYWH::rotary_slider_end_angle, true);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
}

void Slider_Wheel_Mod_B::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) {
	if (isEnabled()) {
		u_m->beginNewTransaction();
		auto delta{ wheel.deltaY };
		auto new_value{ getValue() };
		auto increment{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f) {
			auto mods = e.mods.withoutMouseButtons();
			if (mods == Mods::noModifiers) increment_value(increment, new_value);
			if (mods == Mods::altModifier) alt_increment_value(increment, new_value);
			if (mods == Mods::ctrlModifier) ctrl_increment_value(increment, new_value);
			if (mods == Mods::shiftModifier) shift_increment_value(increment, new_value);
			setValue(new_value);
		}
		u_m->beginNewTransaction();
	}
}

void Slider_Wheel_Mod_B::increment_value(double increment, double& value) {
	value += increment;
}

void Slider_Wheel_Mod_B::shift_increment_value(double increment, double& value) {
	increment *= modifying_pitch ? 12.0 : 10.0;
	value += increment;
}

