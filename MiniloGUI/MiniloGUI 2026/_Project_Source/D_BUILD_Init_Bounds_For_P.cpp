#include "D_BUILD_Init_Bounds_For_P.h"

#include "C_XYWH_P.h"

using namespace BUILD;
using namespace XYWH;

const Rectangle<int> Init_Bounds_For::ctrl_bounds(const int x, const int y, const bool knob) {
	auto w = knob ? knob_diam : switch_w;
	auto h = knob ? knob_diam : switch_h;
	Rectangle<int> r{ 0, 0, w, h };
	r.setCentre(x, y);
	return r;
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_amp_mod_and_level(const bool amp_mod) {
	auto x = amp_mod ? 769 : 829;
	return ctrl_bounds(x, ctrl_row_4_cntr_y, true);
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_flex_sli_knob(const int n) {
	auto x = n == 1 ? 269 : n == 2 ? 329 : 389;
	return ctrl_bounds(x, ctrl_row_4_cntr_y, true);
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_flex_sli_target() {
	return { 132, 441, 104, cbox_h };
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_keyboard_octave() {
	return { 42, 432, 64, 34 };
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_lfo_switch(const int n) {
	auto x = n == 1 ? 448 : n == 2 ? 493 : 538;
	return ctrl_bounds(x, ctrl_row_4_cntr_y);
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_microtune_scale() {
	return { 875, 441, 82, cbox_h };
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_porta_switch(const bool mode) {
	auto w = mode ? 40 : switch_w;
	auto x = mode ? 647 : 692;
	return { x, 423, w, switch_h };
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_porta_time() {
	return ctrl_bounds(612, ctrl_row_4_cntr_y);
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_tuning_knob(const int n) {
	auto x = n == 1 ? 992 : n == 2 ? 1052 : 1112;
	return ctrl_bounds(x, ctrl_row_4_cntr_y, true);
}

const Rectangle<int> Init_Bounds_For::avp_ctrl_voice_mode_btn(const int n) {
	return { 836 + n * 37, 307, 34, 28 };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_delay_knob(const int n) {
	auto x = n == 1 ? 848 : n == 2 ? 908 : 968;
	return ctrl_bounds(x, ctrl_row_1_cntr_y, true);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_delay_routing() {
	return { 1008, 77, 50, switch_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_env_stage(const int stage, const bool vca) {
	auto x = stage == 1 ? 559 : stage == 2 ? 627 : stage == 3 ? 695 : 763;
	auto y = vca ? ctrl_row_1_cntr_y : ctrl_row_2_cntr_y;
	return ctrl_bounds(x, y, true);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_knob(const bool rate) {
	return ctrl_bounds(rate ? 627 : 695, ctrl_row_3_cntr_y, true);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_switch(const bool wave) {
	return ctrl_bounds(wave ? 540 : 585, ctrl_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_target() {
	return { 744, 265, 50, switch_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lpf_freq() {
	return { 408, 86, knob_diam_lpf_freq, knob_diam_lpf_freq };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lpf_knob(const bool reso) {
	return ctrl_bounds(reso ? 397 : 469, ctrl_row_2_cntr_y, true);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lpf_switch(const bool key_track) {
	return ctrl_bounds(key_track ? 434 : 479, ctrl_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lpf_type() {
	return { 363, 251, switch_w, switch_lpf_type_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_mixer_knob(const int n) {
	auto y = n == 1 ? ctrl_row_1_cntr_y : n == 2 ? ctrl_row_2_cntr_y : ctrl_row_3_cntr_y;
	return ctrl_bounds(318, y, true);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_2_mod_knob(const bool x_mod) {
	return ctrl_bounds(x_mod ? 64 : 124, ctrl_row_3_cntr_y, true);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_2_mod_switch(const bool sync) {
	return ctrl_bounds(sync ? 184 : 244, ctrl_row_3_cntr_y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_knob(const bool osc_1, const bool pitch_fine) {
	auto x = pitch_fine ? 184 : 244;
	auto y = osc_1 ? ctrl_row_1_cntr_y : ctrl_row_2_cntr_y;
	return ctrl_bounds(x, y, true);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_switch(const bool osc_1, const bool octave) {
	auto x = octave ? 64 : 124;
	auto y = osc_1 ? ctrl_row_1_cntr_y : ctrl_row_2_cntr_y;
	return ctrl_bounds(x, y);
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_voice_mode_depth() {
	return ctrl_bounds(1112, ctrl_row_2_cntr_y, true);
}
