#include "G_DRAW_Envelope_P.h"

using namespace DRAW;

Envelope::Envelope(const int env_num, Data_Hub* hub) :
	Envelope_A{ hub }
{
	String env{ "exp_env_" + (String)env_num };
	param_delay = exp_state->getParameter(env + "_delay");
	if (param_delay) {
		val_delay = exp_state->getParameterAsValue(env + "_delay");
		val_delay.addListener(this);
	}
	param_attack = exp_state->getParameter(env + "_attack");
	if (param_attack) {
		val_attack = exp_state->getParameterAsValue(env + "_attack");
		val_attack.addListener(this);
	}
	param_decay = exp_state->getParameter(env + "_decay");
	if (param_decay) {
		val_decay = exp_state->getParameterAsValue(env + "_decay");
		val_decay.addListener(this);
	}
	param_sustain = exp_state->getParameter(env + "_sustain");
	if (param_sustain) {
		val_sustain = exp_state->getParameterAsValue(env + "_sustain");
		val_sustain.addListener(this);
	}
	param_release = exp_state->getParameter(env + "_release");
	if (param_release) {
		val_release = exp_state->getParameterAsValue(env + "_release");
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
