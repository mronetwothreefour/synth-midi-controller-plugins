#include "G_WIDGET_Sli_Wheel_Mod_A.h"

#include "C_GET_P.h"
#include "C_MISC_P.h"

using namespace MISC;
using namespace WIDGET;

Slider_Wheel_Mod_A::Slider_Wheel_Mod_A(const std::string& param_id, Value param_value,
									   Data_Hub* hub) :
	Ctrl_A{ param_id, param_value, hub },
	for_pitch{ String{ param_id }.contains("pitch") }
{
	setComponentID(param_id);
	setName(GET::ctrl_name_for(param_id));
	setSliderStyle(Slider::RotaryHorizontalVerticalDrag);
	setRotaryParameters(knb_angle_0, knb_angle_1, true);
	setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
}

void WIDGET::Slider_Wheel_Mod_A::update_ctrl_setting() {
	setValue((double)param_val.getValue(), dontSendNotification);
}

void Slider_Wheel_Mod_A::mouseWheelMove(const MouseEvent& e, const MouseWheelDetails& wheel) {
	if (isEnabled()) {
		u_m->beginNewTransaction();
		auto delta = wheel.deltaY;
		auto curr_value = getValue();
		if (delta != 0.0f) {
			auto increasing = delta > 0.0;
			auto mods = e.mods.withoutMouseButtons();
			if (mods == Mods::noModifiers) mod_value(increasing, curr_value);
			if (mods == Mods::altModifier) alt_mod_value(increasing, curr_value);
			if (mods == Mods::ctrlModifier) ctrl_mod_value(increasing, curr_value);
			if (mods == Mods::shiftModifier) shift_mod_value(increasing, curr_value);
			setValue(curr_value);
		}
		u_m->beginNewTransaction();
	}
}

void Slider_Wheel_Mod_A::mod_value(bool increasing, double& curr_val) {
	curr_val += increasing ? 1.0 : -1.0;
}

void Slider_Wheel_Mod_A::shift_mod_value(bool increasing, double& curr_val) {
	auto increment = for_pitch ? 12.0 : 10.0;
	curr_val += increasing ? increment : increment * -1.0;
}

