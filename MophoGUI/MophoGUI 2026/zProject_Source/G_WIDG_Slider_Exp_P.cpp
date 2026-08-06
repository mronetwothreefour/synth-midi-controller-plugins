#include "G_WIDG_Slider_Exp_P.h"

#include "C_EXP_P.h"

Slider_Exposed_P::Slider_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub) :
	Slider_Exposed_G{ param_id, hub }
{
	if (ctrl_type == Ctrl_Type::knob_pitch)
		for_pitch = true;
	if (ctrl_type == Ctrl_Type::seq_step || ctrl_type == Ctrl_Type::seq_step_trk_1) {
		auto track = (param_id - Exp_Param::seq_track_1_step_1) / 16;
		mod_param_id = Exp_Param(Exp_Param::seq_track_1_dest + track);
		mod_param = exp_state->getParameter(String{ mod_param_id });
		val_mod_param = exp_state->getParameterAsValue(String{ mod_param_id });
		val_mod_param.addListener(this);
	}
	update_according_to_mod();
}

void Slider_Exposed_P::update_value_tip() {
	auto choice_num = roundToInt(exp_param->convertFrom0to1(exp_param->getValue()));
	String tip{};
	if ((ctrl_type == Ctrl_Type::seq_step || ctrl_type == Ctrl_Type::seq_step_trk_1) &&
		!for_pitch && choice_num < 126)
	{
		tip = String{ choice_num };
	}
	else
		tip = exp_info.choice_for(param_id, choice_num);
	tip_update.tip_value = tip;
}

void Slider_Exposed_P::update_according_to_mod() {
	if (mod_param) {
		auto track_dest = roundToInt(mod_param->convertFrom0to1(mod_param->getValue()));
		for_pitch = track_dest > 0 && track_dest < 4;
	}
	update_value_tip();
	display.set_text_to_stored_choice();
}

void Slider_Exposed_P::attach_to_param() {
	Slider_Exposed_G::attach_to_param();
	if (param_id >= Exp_Param::voice_name_char_1)
		setRange(32.0, 127.0, 1.0);
}

Slider_Exposed_P::~Slider_Exposed_P() {
	val_mod_param.removeListener(this);
}
