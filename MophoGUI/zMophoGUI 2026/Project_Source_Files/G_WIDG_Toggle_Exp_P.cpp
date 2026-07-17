#include "G_WIDG_Toggle_Exp_P.h"

Toggle_Exposed_P::Toggle_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Exposed_Control_B{ param_index, hub }
{
	setInterceptsMouseClicks(true, false);
	toggle.setComponentID(ID::toggle_red.toString());
	addAndMakeVisible(toggle);
	auto id = exp_info.id_for(exp_param_index);
	if (id == ID::exp_098_arpeg_on_off) {
		val_mod_param = exp_state->getParameterAsValue(ID::exp_100_seq_on_off);
		val_mod_param.addListener(this);
	}
	if (id == ID::exp_100_seq_on_off) {
		val_mod_param = exp_state->getParameterAsValue(ID::exp_098_arpeg_on_off);
		val_mod_param.addListener(this);
	}
	update_according_to_mod();
}

void Toggle_Exposed_P::resized() {
	auto toggle_diam = roundToInt(XYWH::toggle_diameter * scale_factor);
	toggle.setSize(toggle_diam, toggle_diam);
	auto id = exp_info.id_for(exp_param_index);
	auto w = getWidth();
	if (id == ID::exp_012_osc_sync) {
		toggle.setTopRightPosition(w, 0);
		return;
	}
	if (id == ID::exp_100_seq_on_off) {
		toggle.setTopLeftPosition(0, 0);
		return;
	}
	toggle.setCentrePosition(w / 2, toggle_diam / 2);
}

void Toggle_Exposed_P::attach_to_param() {
	attachment.reset(new ButtonParameterAttachment{ *exp_param, toggle, Exposed_Control_B::u_m });
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
