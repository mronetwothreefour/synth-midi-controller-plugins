#include "G_WIDG_Cbox_Exp_G.h"

Combo_Box_Exposed_G::Combo_Box_Exposed_G(const Exp_Param param_id, Data_Hub_P* hub) :
	Control_Exposed_G{ param_id, hub }
{
	auto choices_list = exp_info.choices_list_for(param_id, true);
	addItemList(choices_list, 1);
}

inline void Combo_Box_Exposed_G::attach_to_param() {
	attachment.reset(new Cbox_Attachment{ *exp_param, *this, Control_Exposed_G::u_m });
}

inline void Combo_Box_Exposed_G::remove_attachment() {
	attachment = nullptr;
}

inline void Combo_Box_Exposed_G::mouseDown(const MouseEvent& e) {
	if (isPopupActive() && e.mods == ModifierKeys::leftButtonModifier) {
		hidePopup();
		return;
	}
	ComboBox::mouseDown(e);
}

inline void Combo_Box_Exposed_G::modifierKeysChanged(const Mods& mods) {
	tip_update.on_mod_keys_changed(mods, this);
}
