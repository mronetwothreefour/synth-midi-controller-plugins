#include "G_DRAW_Envelope_P.h"

Draw_Envelope_P::Draw_Envelope_P(Env_Type env_type, Data_Hub_P* hub) :
	Draw_Envelope_G{ hub }
{
	auto param_offset = (int)env_type * ((int)Exp_Param::env_2_delay - (int)Exp_Param::env_1_delay);
	param_delay = exp_state->getParameter(String{ (int)Exp_Param::env_1_delay + param_offset });
	if (param_delay) {
		val_delay = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_1_delay + param_offset });
		val_delay.addListener(this);
	}
	param_attack = exp_state->getParameter(String{ (int)Exp_Param::env_1_attack + param_offset });
	if (param_attack) {
		val_attack = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_1_attack + param_offset });
		val_attack.addListener(this);
	}
	param_decay = exp_state->getParameter(String{ (int)Exp_Param::env_1_decay + param_offset });
	if (param_decay) {
		val_decay = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_1_decay + param_offset });
		val_decay.addListener(this);
	}
	param_sustain = exp_state->getParameter(String{ (int)Exp_Param::env_1_sustain + param_offset });
	if (param_sustain) {
		val_sustain = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_1_sustain + param_offset });
		val_sustain.addListener(this);
	}
	param_release = exp_state->getParameter(String{ (int)Exp_Param::env_1_release + param_offset });
	if (param_release) {
		val_release = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_1_release + param_offset });
		val_release.addListener(this);
	}

	if (param_delay)
		valueChanged(val_delay);
	if (param_attack)
		valueChanged(val_attack);
	if (param_decay)
		valueChanged(val_decay);
	if (param_sustain)
		valueChanged(val_sustain);
	if (param_release)
		valueChanged(val_release);
}
