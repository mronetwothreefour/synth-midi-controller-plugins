#include "G_WIDG_Sli_Wheel_Mod_G.h"

#include "C_XYWH_P.h"

Slider_Wheel_Mod_G::Slider_Wheel_Mod_G(UndoManager* u_m) :
	u_m{ u_m },
	for_pitch{ false }
{
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setRotaryParameters(XYWH::rotary_slider_begin_angle, XYWH::rotary_slider_end_angle, true);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
}

void Slider_Wheel_Mod_G::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) {
	if (isEnabled()) {
		u_m->beginNewTransaction();
		auto delta{ wheel.deltaY };
		auto new_value{ getValue() };
		auto increment{ getInterval() * (delta < 0.0 ? -1.0 : 1.0) };
		if (delta != 0.0f) {
			auto mods = e.mods.withoutMouseButtons();
			if (mods == Mods::noModifiers) mod_value(increment, new_value);
			if (mods == Mods::altModifier) alt_mod_value(increment, new_value);
			if (mods == Mods::ctrlModifier) ctrl_mod_value(increment, new_value);
			if (mods == Mods::shiftModifier) shift_increment_value(increment, new_value);
			setValue(new_value);
		}
		u_m->beginNewTransaction();
	}
}

void Slider_Wheel_Mod_G::mod_value(double increment, double& curr_sli_val) {
	curr_sli_val += increment;
}

void Slider_Wheel_Mod_G::shift_increment_value(double increment, double& curr_sli_val) {
	increment *= for_pitch ? 12.0 : 10.0;
	curr_sli_val += increment;
}

