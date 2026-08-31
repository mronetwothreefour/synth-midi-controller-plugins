#include "G_WIDGET_Ctrl_Cbox_A.h"

#include "C_GET_P.h"

using namespace WIDGET;

Ctrl_Cbox_A::Ctrl_Cbox_A(const String& param_id, Value param_value, Data_Hub* hub) :
	Ctrl_A{ param_id, param_value, hub }
{
	addItemList(choices_curt, 1);
	if (!param_ptr) {
		onChange = [this] { param_val.setValue(getSelectedItemIndex()); };
		update_ctrl_setting();
	}
}

void Ctrl_Cbox_A::attach_to_param() {
	if (param_ptr)
		attachment.reset(new Cbox_Attachment{ *param_ptr, *this, Ctrl_A::u_m });
}

void Ctrl_Cbox_A::remove_attachment() {
	attachment = nullptr;
}

void Ctrl_Cbox_A::update_ctrl_setting() {
	setSelectedItemIndex((int)param_val.getValue(), dontSendNotification);
}

void Ctrl_Cbox_A::mouseDown(const MouseEvent& e) {
	if (isPopupActive() && e.mods == ModifierKeys::leftButtonModifier) {
		hidePopup();
		return;
	}
	ComboBox::mouseDown(e);
}

void Ctrl_Cbox_A::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, this);
}
