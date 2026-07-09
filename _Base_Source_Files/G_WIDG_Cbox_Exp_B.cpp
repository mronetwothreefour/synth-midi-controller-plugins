#include "G_WIDG_Cbox_Exp_B.h"

Combo_Box_Exposed_B::Combo_Box_Exposed_B(const int param_index, Data_Hub_P* hub) :
	Exposed_Control_B{ param_index, hub }
{
	auto choices_list = exp_info.choices_list_for(param_index, true);
	addItemList(choices_list, 1);
}

inline void Combo_Box_Exposed_B::attach_to_param() {
	attachment.reset(new ComboBoxParameterAttachment{ *exp_param, *this, Exposed_Control_B::u_m });
}

inline void Combo_Box_Exposed_B::remove_attachment() {
	attachment = nullptr;
}

inline void Combo_Box_Exposed_B::mouseDown(const MouseEvent& e) {
	if (isPopupActive() && e.mods == ModifierKeys::leftButtonModifier) {
		hidePopup();
		return;
	}
	ComboBox::mouseDown(e);
}

inline void Combo_Box_Exposed_B::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, this);
}
