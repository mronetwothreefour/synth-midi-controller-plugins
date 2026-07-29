#include "G_WIDG_Exp_Ctrl_G.h"
#include "G_WIDG_Envelope_G.h"

Exposed_Control_G::Exposed_Control_G(const Exp_Param param_id, Data_Hub_P* hub) :
	Data_User_P{ hub },
	param_id{ param_id },
	exp_param{ exp_state->getParameter(String{ param_id })},
	val_exp_param{ exp_state->getParameterAsValue(String{ param_id }) },
	mod_param{ nullptr },
	ctrl_type{ exp_info.ctrl_type_for(param_id) }
{
	val_exp_param.addListener(this);
	init_bounds.setSize(exp_info.ctrl_width_for(param_id),
						exp_info.ctrl_height_for(param_id));
	init_bounds.setCentre(exp_info.ctrl_center_for(param_id));
	tip_update.tip_info = exp_info.tip_for(param_id);
	update_value_tip();
}

Rectangle<int> Exposed_Control_G::get_scaled_bounds() {
	return init_bounds * scale_factor;
}

void Exposed_Control_G::update_value_tip() {
	auto choice_num = roundToInt(exp_param->convertFrom0to1(exp_param->getValue()));
	tip_update.tip_value = exp_info.choice_for(param_id, choice_num);
}

void Exposed_Control_G::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_exp_param))
		update_value_tip();
	if (v.refersToSameSourceAs(val_mod_param))
		update_according_to_mod();
}

Exposed_Control_G::~Exposed_Control_G() {
	val_exp_param.removeListener(this);
}
