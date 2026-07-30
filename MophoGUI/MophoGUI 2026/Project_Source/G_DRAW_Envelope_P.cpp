#include "G_DRAW_Envelope_P.h"

Draw_Envelope_P::Draw_Envelope_P(Env_Type env_type, Data_Hub_P* hub) :
	Draw_Envelope_G{ hub }
{
	int dly{};
	int atk{};
	int dcy{};
	int sus{};
	int rel{};
	switch (env_type)
	{
	case ENUM::Env_Type::env_lpf:
		dly = (int)Exp_Param::lpf_delay;
		atk = (int)Exp_Param::lpf_attack;
		dcy = (int)Exp_Param::lpf_decay;
		sus = (int)Exp_Param::lpf_sustain;
		rel = (int)Exp_Param::lpf_release;
		break;
	case ENUM::Env_Type::env_vca:
		dly = (int)Exp_Param::vca_delay;
		atk = (int)Exp_Param::vca_attack;
		dcy = (int)Exp_Param::vca_decay;
		sus = (int)Exp_Param::vca_sustain;
		rel = (int)Exp_Param::vca_release;
		break;
	case ENUM::Env_Type::env_3:
		dly = (int)Exp_Param::env_3_delay;
		atk = (int)Exp_Param::env_3_attack;
		dcy = (int)Exp_Param::env_3_decay;
		sus = (int)Exp_Param::env_3_sustain;
		rel = (int)Exp_Param::env_3_release;
		break;
	default:
		break;
	}
	param_delay = exp_state->getParameter(String{ dly });
	if (param_delay) {
		val_delay = exp_state->getParameterAsValue(String{ dly });
		val_delay.addListener(this);
	}
	param_attack = exp_state->getParameter(String{ atk });
	if (param_attack) {
		val_attack = exp_state->getParameterAsValue(String{ atk });
		val_attack.addListener(this);
	}
	param_decay = exp_state->getParameter(String{ dcy });
	if (param_decay) {
		val_decay = exp_state->getParameterAsValue(String{ dcy });
		val_decay.addListener(this);
	}
	param_sustain = exp_state->getParameter(String{ sus });
	if (param_sustain) {
		val_sustain = exp_state->getParameterAsValue(String{ sus });
		val_sustain.addListener(this);
	}
	param_release = exp_state->getParameter(String{ rel });
	if (param_release) {
		val_release = exp_state->getParameterAsValue(String{ rel });
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
