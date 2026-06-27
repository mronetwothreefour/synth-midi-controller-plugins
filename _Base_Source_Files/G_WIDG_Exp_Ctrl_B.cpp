#include "G_WIDG_Exp_Ctrl_B.h"

Exposed_Control_B::Exposed_Control_B() :
	Data_User_P{ nullptr },
	param_index{ -1 },
	ctrl_type{ Ctrl_Type::dummy }
{
	// This default constructor is needed when initializing the vector in Exposed_Control_Hub
}

Exposed_Control_B::Exposed_Control_B(const int param_index, Data_Hub_P* hub) :
	Data_User_P{ hub },
	param_index{ param_index },
	param{ exp_state->getParameter(exp_info.id_for(param_index)) },
	ctrl_type{ exp_info.ctrl_type_for(param_index) }
{
	param->addListener(this);
	tip_update.tip_info = exp_info.tip_for(param_index);
	update_value_tip();
}

void Exposed_Control_B::update_value_tip() {
	auto choice_num{ roundToInt(param->convertFrom0to1(param->getValue())) };
	tip_update.tip_value = exp_info.choice_for(param_index, choice_num);
}

void Exposed_Control_B::handleAsyncUpdate() {
	update_value_tip();
}

void Exposed_Control_B::parameterValueChanged(int /*param_index*/, float /*new_value*/) {
	handleAsyncUpdate();
}

Exposed_Control_B::~Exposed_Control_B() {
	param->removeListener(this);
}
