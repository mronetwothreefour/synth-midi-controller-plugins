#include "G_WIDG_Val_Ctrl_G.h"

Value_Control_G::Value_Control_G(Value val_param, const Ctrl_Type ctrl_type, Data_Hub_P* hub,
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

Rectangle<int> Value_Control_G::get_scaled_bounds() {
	return init_bounds * scale_factor;
}

void Value_Control_G::update_value_tip() {
	auto choice_num = (int)val_param.getValue();
	tip_update.tip_value = choices_list[choice_num];
}

void Value_Control_G::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_param))
		update_value_tip();
}

Value_Control_G::~Value_Control_G() {
	val_param.removeListener(this);
}
