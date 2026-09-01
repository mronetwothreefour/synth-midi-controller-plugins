#include "D_BUILD_Init_Bounds_For_P.h"

#include "C_XYWH_P.h"

using namespace BUILD;
using namespace XYWH;

const Rectangle<int> Init_Bounds_For::exp_ctrl_arp_mode() {
	return { 438, 110, osc_cbox_w, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_arpeg_on_off() {
	return { 401, 103, toggle_diam, 27 };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_cc_amt(const int n) {
	Rectangle<int> r{ 0, 0, knob_diam, knob_diam };
	auto cntr_y = mod_0_amt_cntr_y + n * mod_block_spacing;
	r.setCentre(mod_amt_cntr_x, cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_cc_dest(const int n) {
	auto y = cc_0_dest_y + n * cc_block_spacing;
	return { cc_dest_x, y, cc_dest_w, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_clock_tempo() {
	Rectangle<int> r{ 0, 0, knob_diam, knob_diam };
	r.setCentre(1236, 126);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_clock_div() {
	return { 1077, 118, 124, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_env_3(const int n, const int c) {
	auto h = c == 0 ? 28 : knob_diam;
	auto w = c == 0 ? 36 : knob_diam;
	Rectangle<int> r{ 0, 0, w, h };
	auto cntr_y = n == 0 ? env_3_row_0_cntr_y : env_3_row_1_cntr_y;
	if (c == 0)
		cntr_y += 14;
	r.setCentre(ctrl_col_0_cntr_x + c * ctrl_col_w, cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_env_3_dest() {
	return { 30, 575, 126, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_flex_knob(const int n) {
	auto y = flex_knob_cbox_0_y + n * flex_knob_cbox_spacing;
	return { flex_knob_cbox_x, y, flex_knob_cbox_w, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_glide_mode() {
	return { 438, 30, osc_cbox_w, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_cbox(const int n, const bool dest) {
	auto x = lfo_0_cbox_x + n * lfo_block_spacing;
	auto y = dest ? lfo_dest_y : lfo_shape_y;
	Rectangle<int> r{ x, y, lfo_cbox_w, cbox_h };
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_key_sync(const int n) {
	Rectangle<int> r{ 0, 0, lfo_key_sync_w, lfo_key_sync_h };
	auto cntr_x = lfo_0_key_sync_cntr_x + n * lfo_block_spacing;
	r.setCentre(cntr_x, lfo_key_sync_cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lfo_knob(const int n, const bool amt) {
	Rectangle<int> r{ 0, 0, knob_diam, knob_diam };
	auto cntr_x = (amt ? lfo_0_amt_cntr_x : lfo_0_freq_cntr_x) + n * lfo_block_spacing;
	r.setCentre(cntr_x, lfo_knob_cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lpf(const int  n, const int c) {
	Rectangle<int> r{ 0, 0, knob_diam, knob_diam };
	auto cntr_y = n == 0 ? lpf_row_0_cntr_y : lpf_row_1_cntr_y;
	r.setCentre(ctrl_col_0_cntr_x + c * ctrl_col_w, cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_lpf_type() {
	return { 75, 154, 35, 27 };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_mod_amt(const int n) {
	Rectangle<int> r{ 0, 0, knob_diam, knob_diam };
	auto cntr_y = mod_0_amt_cntr_y + n * mod_block_spacing;
	r.setCentre(mod_amt_cntr_x, cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_mod_cbox(const int n, const bool dest) {
	auto y = (dest ? mod_0_dest_y : mod_0_src_y) + n * mod_block_spacing;
	Rectangle<int> r{ mod_cbox_x, y, mod_cbox_w, cbox_h };
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_note_priority() {
	return { 438, 70, osc_cbox_w, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc(const int n, const int c) {
	auto h = c == 5 ? 36 : knob_diam;
	auto w = c == 5 ? 32 : knob_diam;
	Rectangle<int> r{ 0, 0, w, h };
	auto cntr_y = n == 0 ? osc_row_0_cntr_y : osc_row_1_cntr_y;
	if (c == 5)
		cntr_y += 11;
	r.setCentre(ctrl_col_0_cntr_x + c * ctrl_col_w, cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_osc_sync() {
	return { 200, 15, 80, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_push_it_knob(const bool pitch) {
	Rectangle<int> r{ 0, 0, knob_diam, knob_diam };
	auto cntr_x = pitch ? push_it_pitch_cntr_x : push_it_velo_cntr_x;
	r.setCentre(cntr_x, push_it_knob_cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_push_it_mode() {
	return { 1171, 569, 88, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_seq_on_off() {
	return { 812, 119, 103, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_seq_track_dest(const int n) {
	auto y = seq_track_0_dest_y + n * seq_track_block_spacing;
	return { seq_track_dest_x, y, seq_track_dest_w, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_seq_track_step(const int t, const int s) {
	auto x = seq_step_0_x + s * (seq_step_w + step_and_char_gap);
	auto y = seq_track_0_step_y + t * seq_track_block_spacing;
	return { x, y, seq_step_w, seq_step_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_seq_trig_mode() {
	return { 941, 118, 114, cbox_h };
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_vca(const int n, const int c) {
	Rectangle<int> r{ 0, 0, knob_diam, knob_diam };
	auto cntr_y = n == 0 ? vca_row_0_cntr_y : vca_row_1_cntr_y;
	r.setCentre(ctrl_col_0_cntr_x + c * ctrl_col_w, cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::exp_ctrl_voice_name_char(const int n) {
	Rectangle<int> r{ 0, 0, voice_name_char_w, voice_name_char_h };
	auto cntr_x = voice_name_char_0_cntr_x + n * (voice_name_char_w + step_and_char_gap);
	r.setCentre(cntr_x, voice_name_char_cntr_y);
	return r;
}

const Rectangle<int> Init_Bounds_For::toggle_arpeg_on_off() {
	return { 0, 0, toggle_diam, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::toggle_env_3_repeat() {
	return { 11, 0, toggle_diam, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::toggle_lfo_key_sync() {
	return { 7, 0, toggle_diam, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::toggle_lpf_type() {
	return { 11, 0, toggle_diam, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::toggle_osc_key_track() {
	return { 17, 0, toggle_diam, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::toggle_osc_sync() {
	return { 66, 0, toggle_diam, toggle_diam };
}

const Rectangle<int> Init_Bounds_For::toggle_seq_on_off() {
	return { 0, 0, toggle_diam, toggle_diam };
}
