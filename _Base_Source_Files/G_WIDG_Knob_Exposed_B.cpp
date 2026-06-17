#include "G_WIDG_Knob_Exposed_B.h"

Knob_Exposed_B::Knob_Exposed_B(const int param_index, Data_Hub_P* hub) :
	Exposed_Control_B{ param_index, hub },
	Slider_Wheel_Mod_P{ hub },
	param_index{ param_index },
	display{ param_index, hub }
{
	setDoubleClickReturnValue(false, 0.0, ModifierKeys::noModifiers);
	addAndMakeVisible(display);
	resized();
}

void Knob_Exposed_B::resized() {
	auto scale_f = Exposed_Control_B::scale_factor;
	setMouseDragSensitivity(Exposed_Control_B::exp_info.drag_sensitivity_for(param_index, scale_f));
	display.setBounds(getLocalBounds());
}

void Knob_Exposed_B::set_modifying_pitch(bool is_true) {
	modifying_pitch = is_true;
}

void Knob_Exposed_B::attach_to_param() {
	attachment.reset(new SliderParameterAttachment{ *param,  *this, Exposed_Control_B::u_m });
}

void Knob_Exposed_B::remove_attachment() {
	attachment = nullptr;
}

void Knob_Exposed_B::mouseDoubleClick(const MouseEvent& /*e*/) {
	display.showEditor();
}
