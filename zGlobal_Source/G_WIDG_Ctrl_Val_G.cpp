#include "G_WIDG_Ctrl_Val_G.h"

Control_Value_G::Control_Value_G(Value val_param, const Ctrl_Type ctrl_type, Data_Hub_P* hub,
								 StringArray choices_list, StringArray choices_list_curt,
								 const Rectangle<int> init_bounds, const String& info_tip) :
	Data_User_P{ hub },
	val_param{ val_param },
	ctrl_type{ ctrl_type },
	choices_list{ choices_list },
	choices_list_curt{ choices_list_curt },
	init_bounds{ init_bounds }
{
	val_param.addListener(this);
	tip_update.tip_info = info_tip;
	update_value_tip();
}

Rectangle<int> Control_Value_G::get_scaled_bounds() {
	return init_bounds * scale_factor;
}

void Control_Value_G::update_value_tip() {
	auto choice_num = (int)val_param.getValue();
	tip_update.tip_value = choices_list[choice_num];
}

void Control_Value_G::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_param))
		update_value_tip();
}

Control_Value_G::~Control_Value_G() {
	val_param.removeListener(this);
}
