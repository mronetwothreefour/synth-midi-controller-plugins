#include "G_WIDG_Exp_Ctrl_B.h"

Exposed_Control_B::Exposed_Control_B(const int exp_param_index, Data_Hub_P* hub) :
	Data_User_P{ hub },
	exp_param_index{ exp_param_index },
	exp_param{ exp_state->getParameter(exp_info.id_for(exp_param_index)) },
	val_exp_param{ exp_state->getParameterAsValue(exp_info.id_for(exp_param_index)) },
	mod_param{ nullptr },
	ctrl_type{ exp_info.ctrl_type_for(exp_param_index) }
{
	val_exp_param.addListener(this);
	init_bounds.setSize(exp_info.ctrl_width_for(exp_param_index),
						exp_info.ctrl_height_for(exp_param_index));
	init_bounds.setCentre(exp_info.ctrl_center_for(exp_param_index));
	tip_update.tip_info = exp_info.tip_for(exp_param_index);
	update_value_tip();
}

Rectangle<int> Exposed_Control_B::get_scaled_bounds() {
	return init_bounds * scale_factor;
}

void Exposed_Control_B::update_value_tip() {
	auto choice_num = roundToInt(exp_param->convertFrom0to1(exp_param->getValue()));
	tip_update.tip_value = exp_info.choice_for(exp_param_index, choice_num);
}

void Exposed_Control_B::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_exp_param))
		update_value_tip();
	if (v.refersToSameSourceAs(val_mod_param))
		update_according_to_mod();
}

Exposed_Control_B::~Exposed_Control_B() {
	val_exp_param.removeListener(this);
}
