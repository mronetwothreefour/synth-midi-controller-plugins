#include "G_WIDGET_Ctrl_A.h"

#include "C_GET_P.h"

using namespace WIDGET;

Ctrl_A::Ctrl_A(const String& param_id, Data_Hub* hub) :
	Data_User{ hub },
	param_ptr{ exp_state->getParameter(param_id) },
	param_val{ exp_state->getParameterAsValue(param_id) },
	linked_param_ptr{ nullptr },
	choices{ GET::choices_for(param_id) },
	choices_curt{ GET::choices_for(param_id, true) },
	init_bounds{ GET::init_bounds_for(param_id) }
{
	param_val.addListener(this);
	tip_update.tip_info = GET::tip_for(param_id);
	update_tip_current_choice();
}

Rectangle<int> Ctrl_A::scaled_bounds() {
	return init_bounds * scale_factor;
}

void Ctrl_A::update_tip_current_choice() {
	auto choice_num = roundToInt(param_ptr->convertFrom0to1(param_ptr->getValue()));
	tip_update.tip_current_choice = choices[choice_num];
}

void Ctrl_A::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(param_val))
		update_tip_current_choice();
	if (v.refersToSameSourceAs(linked_param_val))
		linked_param_changed();
}

Ctrl_A::~Ctrl_A() {
	param_val.removeListener(this);
}
