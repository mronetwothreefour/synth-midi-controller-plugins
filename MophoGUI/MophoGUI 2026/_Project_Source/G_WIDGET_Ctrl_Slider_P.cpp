#include "G_WIDGET_Ctrl_Slider_P.h"

#include "C_ID_Main_P.h"

using namespace WIDGET;

Ctrl_Slider::Ctrl_Slider(const std::string& param_id, Value param_val, Data_Hub* hub) :
	Ctrl_Slider_A{ param_id, param_val, hub }
{
	if (param_id == ID::exp_lpf_freq)
		for_pitch = true;
	if (for_seq_step) {
		auto track = String{ param_id }.fromFirstOccurrenceOf("_track_", false, false).
										upToFirstOccurrenceOf("_step_", false, false);
		auto linked_param_id = "exp_seq_track_" + track + "_dest";
		linked_param_val = exp_state->getParameterAsValue(linked_param_id);
		linked_param_val.addListener(this);
	}
	linked_param_changed();
}

void Ctrl_Slider::update_tip_current_choice() {
	auto choice_num = (int)param_val.getValue();
	String tip{};
	auto n = getName();
	if (for_seq_step && !for_pitch && choice_num < 126)
		tip = (String)choice_num;
	else
		tip = Ctrl_A::choices[choice_num];
	tip_update.tip_current_choice = tip.toStdString();
}

void Ctrl_Slider::linked_param_changed() {
	auto track_dest = (int)linked_param_val.getValue();
	for_pitch = track_dest > 0 && track_dest < 4;
	update_tip_current_choice();
	label.set_text_to_stored_choice();
}

void Ctrl_Slider::attach_to_param() {
	Ctrl_Slider_A::attach_to_param();
	if (getComponentID().startsWith("exp_voice_name_char_"))
		setRange(32.0, 127.0, 1.0);
}
