#include "G_WIDG_Slider_Exp_B.h"

Slider_Exposed_B::Slider_Exposed_B(const int param_index, Data_Hub_P* hub) :
	Exposed_Control_B{ param_index, hub },
	Slider_Wheel_Mod_P{ hub->get_undo_mngr(), exp_info.ctrl_type_for(param_index)},
	display{ param_index, hub, this },
	param_index{ param_index }
{
	addAndMakeVisible(display);
}

void Slider_Exposed_B::resized() {
	auto scale_f = Exposed_Control_B::scale_factor;
	setMouseDragSensitivity(Exposed_Control_B::exp_info.drag_sensitivity_for(param_index, scale_f));
	display.setBounds(getLocalBounds());
	Slider::resized();
}

void Slider_Exposed_B::attach_to_param() {
	attachment.reset(new SliderParameterAttachment{ *param, *this, Exposed_Control_B::u_m });
	setDoubleClickReturnValue(false, 0.0, Mods::noModifiers);
}

void Slider_Exposed_B::remove_attachment() {
	attachment = nullptr;
}

void Slider_Exposed_B::mouseDoubleClick(const MouseEvent& /*e*/) {
	display.showEditor();
}

void Slider_Exposed_B::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, this);
}
