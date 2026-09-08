#include "G_WIDGET_Sli_Wheel_Mod_A.h"

#include "C_GET_P.h"
#include "C_MISC_P.h"

using namespace MISC;
using namespace WIDGET;

Slider_Wheel_Mod_A::Slider_Wheel_Mod_A(const String& param_id, UndoManager* u_m) :
	u_m{ u_m },
	for_pitch{ false },
	choices{ GET::choices_for(param_id) },
	choices_curt{ GET::choices_for(param_id, true) }
{
	setComponentID(param_id);
	setName(GET::ctrl_name_for(param_id));
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setRotaryParameters(rotary_sli_begin_angle, rotary_sli_end_angle, true);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
}

void Slider_Wheel_Mod_A::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) {
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
			if (mods == Mods::shiftModifier) shift_mod_value(increment, new_value);
			setValue(new_value);
		}
		u_m->beginNewTransaction();
	}
}

void Slider_Wheel_Mod_A::mod_value(double increment, double& curr_val) {
	curr_val += increment;
}

void Slider_Wheel_Mod_A::shift_mod_value(double increment, double& curr_val) {
	increment *= for_pitch ? 12.0 : 10.0;
	curr_val += increment;
}

