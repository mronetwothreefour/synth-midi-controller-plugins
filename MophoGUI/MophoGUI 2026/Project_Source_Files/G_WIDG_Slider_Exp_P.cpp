#include "G_WIDG_Slider_Exp_P.h"

Slider_Exposed_P::Slider_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Slider_Exposed_B{ param_index, hub }
{
	if (ctrl_type == Ctrl_Type::knob_pitch)
		modifying_pitch = true;
	if (ctrl_type == Ctrl_Type::seq_step || ctrl_type == Ctrl_Type::seq_step_track_1) {
		auto track = (param_index - EXP::first_seq_step_param_index) / 16;
		mod_param_index = EXP::first_seq_track_dest_param_index + track;
		auto mod_param_id = exp_info.id_for(mod_param_index);
		mod_param = exp_state->getParameter(mod_param_id);
		val_mod_param = exp_state->getParameterAsValue(mod_param_id);
		val_mod_param.addListener(this);
	}
	update_according_to_mod();
}

void Slider_Exposed_P::update_value_tip() {
	auto choice_num = roundToInt(exp_param->convertFrom0to1(exp_param->getValue()));
	String tip{};
	if (!modifying_pitch && 
		(ctrl_type == Ctrl_Type::seq_step || ctrl_type == Ctrl_Type::seq_step_track_1))
	{
		tip = String{ choice_num };
	}
	else
		tip = exp_info.choice_for(exp_param_index, choice_num);
	tip_update.tip_value = tip;
}

void Slider_Exposed_P::update_according_to_mod() {
	if (mod_param) {
		auto track_dest = roundToInt(mod_param->convertFrom0to1(mod_param->getValue()));
		modifying_pitch = track_dest > 0 && track_dest < 4;
	}
	update_value_tip();
	display.set_text_to_stored_choice();
}

void Slider_Exposed_P::attach_to_param() {
	Slider_Exposed_B::attach_to_param();
	if (exp_param_index >= EXP::first_voice_name_char_param_index)
		setRange(32.0, 127.0, 1.0);
}

Slider_Exposed_P::~Slider_Exposed_P() {
	val_mod_param.removeListener(this);
}
