#include "G_WIDG_Envelope_G.h"

#include "C_COLOR_P.h"
#include "C_XYWH_P.h"

using namespace XYWH;

using End_Cap = PathStrokeType::EndCapStyle;
using Joint = PathStrokeType::JointStyle;
using Stroke = PathStrokeType;

Envelope_G::Envelope_G(Data_Hub_P* hub) :
	Data_User_P{ hub }
{}

void Envelope_G::paint(Graphics& g) {
	Path p{};
	auto x = env_init_begin_x * scale_factor;
	auto end_x = env_init_end_x * scale_factor;
	auto min_y = env_init_min_y * scale_factor;
	auto max_y = env_init_max_y * scale_factor;
	auto sustain_y = min_y - (sustain_h * scale_factor);
	p.startNewSubPath(x, min_y);
	if (delay_w > 0.0f) {
		x += delay_w * scale_factor;
		p.lineTo(x, min_y);
	}
	x += attack_w * scale_factor;
	p.lineTo(x, max_y);
	x += decay_w * scale_factor;
	p.lineTo(x, sustain_y);
	x += env_sustain_init_w * scale_factor;
	p.lineTo(x, sustain_y);
	x += release_w * scale_factor;
	p.lineTo(x, min_y);
	if (x < end_x)
		p.lineTo(end_x, min_y);
	g.setColour(COLOR::env_stroke);
	g.strokePath(p, Stroke{ 2.0f * scale_factor, Joint::curved, End_Cap::rounded });
}

void Envelope_G::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_delay) && param_delay)
		delay_w = param_delay->getValue() * env_stage_init_max_w;
	if (v.refersToSameSourceAs(val_attack) && param_attack)
		attack_w = param_attack->getValue() * env_stage_init_max_w;
	if (v.refersToSameSourceAs(val_decay) && param_decay)
		decay_w = param_decay->getValue() * env_stage_init_max_w;
	if (v.refersToSameSourceAs(val_sustain) && param_sustain)
		sustain_h = param_sustain->getValue() * (env_init_min_y - env_init_max_y);
	if (v.refersToSameSourceAs(val_release) && param_release)
		release_w = param_release->getValue() * env_stage_init_max_w;
	repaint();
}

Envelope_G::~Envelope_G() {
	val_delay.removeListener(this);
	val_attack.removeListener(this);
	val_decay.removeListener(this);
	val_sustain.removeListener(this);
	val_release.removeListener(this);
}
