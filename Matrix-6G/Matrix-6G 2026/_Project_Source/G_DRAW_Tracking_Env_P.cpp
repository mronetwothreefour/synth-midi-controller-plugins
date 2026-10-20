#include "G_DRAW_Tracking_Env_P.h"

#include "C_COLOR_P.h"
#include "C_XYWH_P.h"

using namespace DRAW;
using namespace XYWH;

using End_Cap = PathStrokeType::EndCapStyle;
using Joint = PathStrokeType::JointStyle;
using Stroke = PathStrokeType;

Tracking_Env::Tracking_Env(Data_Hub* hub) :
	Data_User{ hub }
{
	String track_pt{ "exp_track_point_" };
	for (int i = 1; i < 6; ++i) {
		auto param = exp_state->getParameter(track_pt + (String)i);
		if (param) {
			params.add(param);
			y_coords.add(0.0f);
		}
	}
	if (params[0]){
		val_pt_0 = exp_state->getParameterAsValue(track_pt + "1");
		val_pt_0.addListener(this);
		valueChanged(val_pt_0);
	}
	if (params[1]){
		val_pt_1 = exp_state->getParameterAsValue(track_pt + "2");
		val_pt_1.addListener(this);
		valueChanged(val_pt_1);
	}
	if (params[2]){
		val_pt_2 = exp_state->getParameterAsValue(track_pt + "3");
		val_pt_2.addListener(this);
		valueChanged(val_pt_2);
	}
	if (params[3]){
		val_pt_3 = exp_state->getParameterAsValue(track_pt + "4");
		val_pt_3.addListener(this);
		valueChanged(val_pt_3);
	}
	if (params[4]){
		val_pt_4 = exp_state->getParameterAsValue(track_pt + "5");
		val_pt_4.addListener(this);
		valueChanged(val_pt_4);
	}
}

void Tracking_Env::paint(Graphics& g) {
	Path p{};
	auto min_y = trk_env_init_min_y * scale_f;
	auto w = trk_env_segment_init_w * scale_f;
	auto x = trk_env_init_begin_x * scale_f;
	p.startNewSubPath(x, min_y - (y_coords[0] * scale_f));
	for (int i = 1; i < 5; ++i) {
		x += w;
		p.lineTo(x, min_y - (y_coords[i] * scale_f));
	}
	g.setColour(Colour{ COLOR::env_stroke });
	g.strokePath(p, Stroke{ 2.0f * scale_f, Joint::curved, End_Cap::rounded });
}

void Tracking_Env::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_pt_0))
		y_coords.set(0, params[0]->getValue() * trk_env_init_h);
	if (v.refersToSameSourceAs(val_pt_1))
		y_coords.set(1, params[1]->getValue() * trk_env_init_h);
	if (v.refersToSameSourceAs(val_pt_2))
		y_coords.set(2, params[2]->getValue() * trk_env_init_h);
	if (v.refersToSameSourceAs(val_pt_3))
		y_coords.set(3, params[3]->getValue() * trk_env_init_h);
	if (v.refersToSameSourceAs(val_pt_4))
		y_coords.set(4, params[4]->getValue() * trk_env_init_h);
	repaint();
}

Tracking_Env::~Tracking_Env() {
	val_pt_0.removeListener(this);
	val_pt_1.removeListener(this);
	val_pt_2.removeListener(this);
	val_pt_3.removeListener(this);
	val_pt_4.removeListener(this);
	params.clear();
	y_coords.clear();
}
