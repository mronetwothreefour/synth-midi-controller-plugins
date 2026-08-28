#include "G_WIDGET_Ctrl_Slider_A.h"

using namespace WIDGET;

Ctrl_Slider_A::Ctrl_Slider_A(const String& param_id, Data_Hub* hub) :
	Ctrl_A{ param_id, hub },
	Slider_Wheel_Mod{ param_id, Ctrl_A::u_m },
	label{ param_id, hub, this }
{
	addAndMakeVisible(label);
}

void Ctrl_Slider_A::resized() {
	set_drag_sensitivity();
	label.setBounds(getLocalBounds());
	Slider::resized();
}

void Ctrl_Slider_A::attach_to_param() {
	attachment.reset(new Slider_Attachment{ *param_ptr, *this, Ctrl_A::u_m });
	setDoubleClickReturnValue(false, 0.0, Mods::noModifiers);
}

void Ctrl_Slider_A::remove_attachment() {
	attachment = nullptr;
}

void Ctrl_Slider_A::set_drag_sensitivity() {
	auto choice_count = Ctrl_A::choices.size();
	auto sensitivity = 175.0f * scale_factor;
	if (choice_count < 128)
		sensitivity = (80.0f + choice_count / 2.0f) * scale_factor;
	setMouseDragSensitivity(roundToInt(sensitivity));
}

void Ctrl_Slider_A::mouseDoubleClick(const MouseEvent&/*e*/) {
	if (label.editable)
		label.showEditor();
}

void Ctrl_Slider_A::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, this);
}
