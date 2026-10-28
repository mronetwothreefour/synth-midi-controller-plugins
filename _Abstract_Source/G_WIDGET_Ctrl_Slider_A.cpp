#include "G_WIDGET_Ctrl_Slider_A.h"

#include "C_ID_A.h"

using namespace WIDGET;

Ctrl_Slider_A::Ctrl_Slider_A(const std::string& param_id, Value param_value, Data_Hub* hub) :
	Slider_Wheel_Mod{ param_id, param_value, hub },
	label{ param_id, hub, this }
{
	addAndMakeVisible(label);
	if (!param_ptr) {
		onValueChange = [this] { 
			auto new_val = roundToInt(getValue());
			if (getComponentID() == ID::app_curr_pgm_num) // not undoable
					app_p.set_current_pgm_num(new_val);
			else
				param_val.setValue(new_val);
		};
		setRange(0.0, double(Ctrl_A::choices.size() - 1), 1.0);
		update_ctrl_setting();
		label.set_text_to_stored_choice();
	}
}

void Ctrl_Slider_A::resized() {
	set_drag_sensitivity();
	label.setBounds(getLocalBounds());
	Slider::resized();
}

void Ctrl_Slider_A::attach_to_param() {
	if (param_ptr) {
		attachment.reset(new Slider_Attachment{ *param_ptr, *this, Ctrl_A::u_m });
		setDoubleClickReturnValue(false, 0.0, Mods::noModifiers);
	}
}

void Ctrl_Slider_A::remove_attachment() {
	attachment = nullptr;
}

void Ctrl_Slider_A::set_drag_sensitivity() {
	auto choice_count = Ctrl_A::choices.size();
	auto sensitivity = 175.0f * scale_f;
	if (choice_count < 128)
		sensitivity = (80.0f + choice_count / 2.0f) * scale_f;
	setMouseDragSensitivity(roundToInt(sensitivity));
}

void Ctrl_Slider_A::mouseDoubleClick(const MouseEvent&/*e*/) {
	if (label.editable)
		label.showEditor();
}

void Ctrl_Slider_A::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, this);
}
