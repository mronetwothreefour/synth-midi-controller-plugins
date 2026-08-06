#include "G_DRAW_Envelope_P.h"

#include "C_COLOR_G.h"
#include "C_PATH_Widgets_P.h"
#include "C_XYWH_P.h"

Draw_Envelope_P::Draw_Envelope_P(bool vca_env, Data_Hub_P* hub) :
	Draw_Envelope_G{ hub }
{
	auto param_offset = vca_env ? 29 : 0;
	param_attack = exp_state->getParameter(String{ (int)Exp_Param::env_attack + param_offset });
	if (param_attack) {
		val_attack = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_attack + param_offset });
		val_attack.addListener(this);
	}
	param_decay = exp_state->getParameter(String{ (int)Exp_Param::env_decay + param_offset });
	if (param_decay) {
		val_decay = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_decay + param_offset });
		val_decay.addListener(this);
	}
	param_sustain = exp_state->getParameter(String{ (int)Exp_Param::env_sustain + param_offset });
	if (param_sustain) {
		val_sustain = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_sustain + param_offset });
		val_sustain.addListener(this);
	}
	param_release = exp_state->getParameter(String{ (int)Exp_Param::env_release + param_offset });
	if (param_release) {
		val_release = exp_state->getParameterAsValue(String{ (int)Exp_Param::env_release + param_offset });
		val_release.addListener(this);
	}
	if (param_attack)
		valueChanged(val_attack);
	if (param_decay)
		valueChanged(val_decay);
	if (param_sustain)
		valueChanged(val_sustain);
	if (param_release)
		valueChanged(val_release);
}

void Draw_Envelope_P::paint(Graphics& g) {
	g.setColour(COLOR::black);
	g.fillRect(XYWH::env_backdrop_init_bounds * scale_factor);
	Path p;
	p.loadPathFromData(PATH::env_baseline, sizeof(PATH::env_baseline));
	g.setColour(COLOR::white);
	g.fillPath(p, AffineTransform::scale(scale_factor));
	Draw_Envelope_G::paint(g);
}
