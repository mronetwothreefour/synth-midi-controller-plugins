#include "G_WIDGET_Ctrl_Toggle_P.h"

#include "C_GET_P.h"
#include "C_ID_Main_P.h"
#include "C_NAME_P.h"

using namespace WIDGET;

Ctrl_Toggle::Ctrl_Toggle(const String& param_id, Value param_val, Data_Hub* hub) :
	Ctrl_A{ param_id, param_val, hub }
{
	setInterceptsMouseClicks(true, false);
	toggle.setName(GET::ctrl_name_for(param_id));
	addAndMakeVisible(toggle);
	if (param_id == ID::exp_arpeg_on_off) {
		linked_param_val = exp_state->getParameterAsValue(ID::exp_seq_on_off);
		linked_param_val.addListener(this);
	}
	if (param_id == ID::exp_seq_on_off) {
		linked_param_val = exp_state->getParameterAsValue(ID::exp_arpeg_on_off);
		linked_param_val.addListener(this);
	}
	update_ctrl_setting();
	linked_param_changed();
}

void Ctrl_Toggle::resized() {
	auto b = GET::init_bounds_for(toggle.getName()) * scale_factor;
	toggle.setBounds(b);
}

void Ctrl_Toggle::attach_to_param() {
	if (param_ptr)
		attachment.reset(new Btn_Attachment{ *param_ptr, toggle, Ctrl_A::u_m });
}

void Ctrl_Toggle::remove_attachment() {
	attachment = nullptr;
}

void Ctrl_Toggle::update_ctrl_setting() {
	toggle.setToggleState((int)param_val.getValue() != 0, dontSendNotification);
}

void Ctrl_Toggle::mouseDown(const MouseEvent& /*e*/) {
	toggle.triggerClick();
}

void Ctrl_Toggle::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, &toggle);
}

void Ctrl_Toggle::linked_param_changed() {
	if ((int)linked_param_val.getValue() != 1)
		toggle.setToggleState(false, sendNotification);
}
