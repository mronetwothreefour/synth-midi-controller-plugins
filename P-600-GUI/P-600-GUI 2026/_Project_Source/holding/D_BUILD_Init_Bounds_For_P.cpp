#include "D_BUILD_Init_Bounds_For_P.h"

#include "C_XYWH_P.h"

using namespace BUILD;
using namespace XYWH;

const Rectangle<int> Init_Bounds_For::exp_ctrl(const int x, const int y) {
	auto knob = y != switch_row_1_cntr_y && y != switch_row_2_cntr_y;
	auto w = knob ? knob_diam : switch_2_pole_w;
	auto h = knob ? knob_diam : switch_2_pole_h;
	Rectangle<int> r{ 0, 0, w, h };
	r.setCentre(x, y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_env_stage(const int s, const bool filter) {
	auto x = s == 1 ? filter_amp_col_1_cntr_x : s == 2 ? filter_amp_col_2_cntr_x :
			 s == 3 ? filter_amp_col_3_cntr_x : filter_amp_col_4_cntr_x;
	return exp_ctrl(x, filter ? knob_row_2_cntr_y : knob_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_filter_key_track() {
	return { 1268, 48, switch_3_pole_w, switch_3_pole_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_filter_knob(const int c) {
	auto x = c == 1 ? filter_amp_col_1_cntr_x :
			 c == 2 ? filter_amp_col_2_cntr_x :
			 filter_amp_col_3_cntr_x;
	return exp_ctrl(x, knob_row_1_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_knob(const bool lfo_freq) {
	return exp_ctrl(lfo_freq ? 60 : 207, knob_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_switch(const int s) {
	auto x = s == 1 ? 126 : s == 2 ? 282 : s == 3 ? 342 : 402;
	return exp_ctrl(x, switch_row_2_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_a_sync() {
	return exp_ctrl(osc_col_2_cntr_x, switch_row_1_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_b_fine() {
	return exp_ctrl(osc_col_2_cntr_x, knob_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_poly_mod(const int c) {
	auto x = c == 1 ? 60 : c == 2 ? 184 : c == 3 ? 287 : 347;
	return exp_ctrl(x, c < 3 ? knob_row_2_cntr_y : switch_row_1_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_mixer_glide(const bool mixer) {
	return exp_ctrl(mixer_glide_cntr_x, mixer ? knob_row_2_cntr_y : knob_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_pitch(const bool osc_a) {
	return exp_ctrl(osc_col_1_cntr_x, osc_a ? knob_row_2_cntr_y : knob_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_pulse_w(const bool osc_a) {
	return exp_ctrl(osc_col_6_cntr_x, osc_a ? knob_row_2_cntr_y : knob_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_shape(const int s, const bool osc_a) {
	auto x = s == 1 ? osc_col_3_cntr_x : s == 2 ? osc_col_4_cntr_x : osc_col_5_cntr_x;
	return exp_ctrl(x, osc_a ? switch_row_1_cntr_y : switch_row_2_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_unison_track() {
	return exp_ctrl(416, switch_row_1_cntr_y);
}

