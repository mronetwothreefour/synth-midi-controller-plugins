#include "G_WIDG_Toggle_Exp_P.h"

#include "C_ID_P.h"
#include "C_XYWH_P.h"

Toggle_Exposed_P::Toggle_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub) :
	Exposed_Control_G{ param_id, hub }
{
	setInterceptsMouseClicks(true, false);
	toggle.setComponentID(ID::toggle_red);
	addAndMakeVisible(toggle);
	if (param_id == Exp_Param::arpeg_on_off) {
		val_mod_param = exp_state->getParameterAsValue(String{ Exp_Param::seq_on_off });
		val_mod_param.addListener(this);
	}
	if (param_id == Exp_Param::seq_on_off) {
		val_mod_param = exp_state->getParameterAsValue(String{ Exp_Param::arpeg_on_off });
		val_mod_param.addListener(this);
	}
	update_according_to_mod();
}

void Toggle_Exposed_P::resized() {
	auto toggle_diam = roundToInt(XYWH::toggle_diam * scale_factor);
	toggle.setSize(toggle_diam, toggle_diam);
	auto w = getWidth();
	if (param_id == Exp_Param::osc_sync) {
		toggle.setTopRightPosition(w, 0);
		return;
	}
	if (param_id == Exp_Param::seq_on_off) {
		toggle.setTopLeftPosition(0, 0);
		return;
	}
	toggle.setCentrePosition(w / 2, toggle_diam / 2);
}

void Toggle_Exposed_P::attach_to_param() {
	attachment.reset(new Btn_Attachment{ *exp_param, toggle, Exposed_Control_G::u_m });
}

void Toggle_Exposed_P::remove_attachment() {
	attachment = nullptr;
}

void Toggle_Exposed_P::mouseDown(const MouseEvent& /*e*/) {
	toggle.triggerClick();
}

void Toggle_Exposed_P::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, &toggle);
}

void Toggle_Exposed_P::update_according_to_mod() {
	if ((int)val_mod_param.getValue() == 1)
		toggle.setToggleState(false, sendNotification);
}
