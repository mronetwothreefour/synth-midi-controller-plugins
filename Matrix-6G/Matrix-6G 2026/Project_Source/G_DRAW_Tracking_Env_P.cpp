#include "G_DRAW_Tracking_Env_P.h"

#include "C_COLOR_P.h"
#include "C_XYWH_P.h"

using namespace XYWH;

using End_Cap = PathStrokeType::EndCapStyle;
using Joint = PathStrokeType::JointStyle;
using Stroke = PathStrokeType;

Draw_Tracking_Env_P::Draw_Tracking_Env_P(Data_Hub_P* hub) :
	Data_User_P{ hub }
{
	for (int i = 0; i < 5; ++i) {
		auto param = exp_state->getParameter(String{ (int)Exp_Param::track_point_1 + i });
		if (param) {
			params.add(param);
			y_coords.add(0.0f);
		}
	}
	if (params[0]){
		val_pt_0 = exp_state->getParameterAsValue(String{ (int)Exp_Param::track_point_1 });
		val_pt_0.addListener(this);
		valueChanged(val_pt_0);
	}
	if (params[1]){
		val_pt_1 = exp_state->getParameterAsValue(String{ (int)Exp_Param::track_point_2 });
		val_pt_1.addListener(this);
		valueChanged(val_pt_1);
	}
	if (params[2]){
		val_pt_2 = exp_state->getParameterAsValue(String{ (int)Exp_Param::track_point_3 });
		val_pt_2.addListener(this);
		valueChanged(val_pt_2);
	}
	if (params[3]){
		val_pt_3 = exp_state->getParameterAsValue(String{ (int)Exp_Param::track_point_4 });
		val_pt_3.addListener(this);
		valueChanged(val_pt_3);
	}
	if (params[4]){
		val_pt_4 = exp_state->getParameterAsValue(String{ (int)Exp_Param::track_point_5 });
		val_pt_4.addListener(this);
		valueChanged(val_pt_4);
	}
}

void Draw_Tracking_Env_P::paint(Graphics& g) {
	Path p{};
	auto min_y = track_env_init_min_y * scale_factor;
	auto w = track_env_segment_init_w * scale_factor;
	auto x = track_env_init_begin_x * scale_factor;
	p.startNewSubPath(x, min_y - (y_coords[0] * scale_factor));
	for (int i = 1; i < 5; ++i) {
		x += w;
		p.lineTo(x, min_y - (y_coords[i] * scale_factor));
	}
	g.setColour(COLOR::env_stroke);
	g.strokePath(p, Stroke{ 2.0f * scale_factor, Joint::curved, End_Cap::rounded });
}

void Draw_Tracking_Env_P::valueChanged(Value& v) {
	if (v.refersToSameSourceAs(val_pt_0))
		y_coords.set(0, params[0]->getValue() * track_env_init_h);
	if (v.refersToSameSourceAs(val_pt_1))
		y_coords.set(1, params[1]->getValue() * track_env_init_h);
	if (v.refersToSameSourceAs(val_pt_2))
		y_coords.set(2, params[2]->getValue() * track_env_init_h);
	if (v.refersToSameSourceAs(val_pt_3))
		y_coords.set(3, params[3]->getValue() * track_env_init_h);
	if (v.refersToSameSourceAs(val_pt_4))
		y_coords.set(4, params[4]->getValue() * track_env_init_h);
	repaint();
}

Draw_Tracking_Env_P::~Draw_Tracking_Env_P() {
	val_pt_0.removeListener(this);
	val_pt_1.removeListener(this);
	val_pt_2.removeListener(this);
	val_pt_3.removeListener(this);
	val_pt_4.removeListener(this);
	params.clear();
	y_coords.clear();
}
