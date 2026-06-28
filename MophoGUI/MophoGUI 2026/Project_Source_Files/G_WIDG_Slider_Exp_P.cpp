#include "G_WIDG_Slider_Exp_P.h"

Slider_Exposed_P::Slider_Exposed_P(const int param_index, Data_Hub_P* hub) :
	Slider_Exposed_B{ param_index, hub },
	param_2{ nullptr }
{
	if (ctrl_type == Ctrl_Type::seq_step || ctrl_type == Ctrl_Type::seq_step_track_1) {
		auto track = (param_index - EXP::first_seq_step_param_index) / 16;
		auto track_dest_param_index = EXP::first_seq_track_dest_param_index + track;
		param_2 = exp_state->getParameter(exp_info.id_for(track_dest_param_index));
		if (param_2)
			param_2->addListener(this);
	}
	handleAsyncUpdate();
}

void Slider_Exposed_P::handleAsyncUpdate() {
	Exposed_Control_B::handleAsyncUpdate();
	if (ctrl_type == Ctrl_Type::seq_step || ctrl_type == Ctrl_Type::seq_step_track_1) {
		auto track_dest = roundToInt(param_2->convertFrom0to1(param_2->getValue()));
		modifying_pitch = track_dest > 0 && track_dest < 4;
		display.set_text_to_stored_choice();
	}
}

Slider_Exposed_P::~Slider_Exposed_P() {
	param_2 = nullptr;
}
