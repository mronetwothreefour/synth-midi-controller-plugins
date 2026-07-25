#include "G_WIDG_Slider_Exp_P.h"

#include "C_ID_P.h"

Slider_Exposed_P::Slider_Exposed_P(const Exp_Param param_id, Data_Hub_P* hub) :
	Slider_Exposed_G{ param_id, hub }
{
	if (ctrl_type == Ctrl_Type::knob_lpf_freq)
		setComponentID(ID::knob_lpf_freq);
	if (ctrl_type == Ctrl_Type::switch_2_pole ||
		ctrl_type == Ctrl_Type::switch_3_pole ||
		ctrl_type == Ctrl_Type::switch_lpf_type ||
		ctrl_type == Ctrl_Type::switch_osc_octave)
	{
		removeChildComponent(&display);
		if (ctrl_type == Ctrl_Type::switch_2_pole)
			setComponentID(ID::switch_2_pole);
		if (ctrl_type == Ctrl_Type::switch_3_pole)
			setComponentID(ID::switch_3_pole);
		if (ctrl_type == Ctrl_Type::switch_lpf_type)
			setComponentID(ID::switch_lpf_type);
		if (ctrl_type == Ctrl_Type::switch_osc_octave)
			setComponentID(ID::switch_osc_octave);
	}
	if (ctrl_type == Ctrl_Type::knob_voice_mode_depth) {
		val_mod_param = avp.get_param_as_value(Aux_Voice_Param::voice_mode);
		val_mod_param.addListener(this);
	}
	update_according_to_mod();
}

void Slider_Exposed_P::update_according_to_mod() {
	update_value_tip();
	display.set_text_to_stored_choice();
}

Slider_Exposed_P::~Slider_Exposed_P() {
	val_mod_param.removeListener(this);
}
