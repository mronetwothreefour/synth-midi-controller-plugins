#include "G_WIDG_Slider_Exp_G.h"

Slider_Exposed_G::Slider_Exposed_G(const Exp_Param param_id, Data_Hub_P* hub) :
	Exposed_Control_G{ param_id, hub },
	Slider_Wheel_Mod_P{ hub->get_undo_mngr(), exp_info.ctrl_type_for(param_id)},
	display{ param_id, hub, this }
{
	addAndMakeVisible(display);
}

void Slider_Exposed_G::resized() {
	auto scale_f = Exposed_Control_G::scale_factor;
	setMouseDragSensitivity(Exposed_Control_G::exp_info.drag_sensitivity_for(param_id, scale_f));
	display.setBounds(getLocalBounds());
	Slider::resized();
}

void Slider_Exposed_G::attach_to_param() {
	attachment.reset(new Slider_Attachment{ *exp_param, *this, Exposed_Control_G::u_m });
	setDoubleClickReturnValue(false, 0.0, Mods::noModifiers);
}

void Slider_Exposed_G::remove_attachment() {
	attachment = nullptr;
}

void Slider_Exposed_G::mouseDoubleClick(const MouseEvent& /*e*/) {
	if (display.editable)
		display.showEditor();
}

void Slider_Exposed_G::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, this);
}
