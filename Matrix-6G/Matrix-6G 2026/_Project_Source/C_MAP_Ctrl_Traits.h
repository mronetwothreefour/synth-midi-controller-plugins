#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_NAME_P.h"
#include "C_SL_Tip_Exposed_P.h"
#include "C_SL_Tip_Matrix_Mod_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace NAME;
using namespace std;

using Tip = Tip_For;

namespace MAP
{

	static const unordered_map<string, tuple<string, int, string>> ctrl_traits{
		//exposed osc
		{ ID::exp_osc_1_pitch, { ctr_sli_knb, 0, Tip::exp_osc_pitch(1) } },
		{ ID::exp_osc_1_type, { ctr_cbx, 2, Tip::exp_osc_type(1) } },
		{ ID::exp_osc_1_pulse_w, { ctr_sli_knb, 31, Tip::exp_osc_pulse_w(1) } },
		{ ID::exp_osc_1_saw_tri, { ctr_sli_knb, 31, Tip::exp_osc_saw_tri(1) } },
		{ ID::exp_osc_1_sync, { ctr_cbx, 0, Tip::from_SL(SL::osc_1_sync_tip) } },
		{ ID::exp_osc_1_lfo_1_fm, { ctr_sli_knb, 63, Tip::exp_osc_lfo_1_fm(1) } },
		{ ID::exp_osc_1_lfo_2_pwm, { ctr_sli_knb, 63, Tip::exp_osc_lfo_2_pwm(1) } },
		{ ID::exp_osc_1_key_click, { ctr_cbx, 0, Tip::from_SL(SL::osc_key_click_tip) } },
		{ ID::exp_osc_1_key_track, { ctr_cbx, 0, Tip::exp_osc_key_track(1) } },
		{ ID::exp_osc_1_lever_ctrl, { ctr_cbx, 3, Tip::exp_osc_lever_control(1) } },
		{ ID::exp_osc_2_pitch, { ctr_sli_knb, 0, Tip::exp_osc_pitch(3) } },
		{ ID::exp_osc_2_type, { ctr_cbx, 2, Tip::exp_osc_type(3) } },
		{ ID::exp_osc_2_pulse_w, { ctr_sli_knb, 31, Tip::exp_osc_pulse_w(3) } },
		{ ID::exp_osc_2_saw_tri, { ctr_sli_knb, 31, Tip::exp_osc_saw_tri(3) } },
		{ ID::exp_osc_2_detune, { ctr_cbx, 0, Tip::from_SL(SL::osc_2_detune_tip) } },
		{ ID::exp_osc_2_lfo_1_fm, { ctr_sli_knb, 63, Tip::exp_osc_lfo_1_fm(3) } },
		{ ID::exp_osc_2_lfo_2_pwm, { ctr_sli_knb, 63, Tip::exp_osc_lfo_2_pwm(3) } },
		{ ID::exp_osc_2_key_click, { ctr_cbx, 0, Tip::from_SL(SL::osc_key_click_tip) } },
		{ ID::exp_osc_2_key_track, { ctr_cbx, 0, Tip::exp_osc_key_track(3) } },
		{ ID::exp_osc_2_lever_ctrl, { ctr_cbx, 3, Tip::exp_osc_lever_control(3) } },
		{ ID::exp_osc_balance, { sli_osc_bal, 31, Tip::from_SL(SL::osc_balance_tip) } },
		//exposed vcf
		{ ID::exp_vcf_freq, { ctr_sli_knb, 55, Tip::from_SL(SL::vcf_freq_tip) } },
		{ ID::exp_vcf_reso, { ctr_sli_knb, 0, Tip::from_SL(SL::vcf_reso_tip) } },
		{ ID::exp_vcf_env_1_amt, { ctr_sli_knb, 105, Tip::from_SL(SL::vcf_env_1_amt_tip) } },
		{ ID::exp_vcf_press_amt, { ctr_sli_knb, 63, Tip::from_SL(SL::vcf_pressure_amt_tip) } },
		{ ID::exp_vcf_lever_ctrl, { ctr_cbx, 0, Tip::from_SL(SL::vcf_lever_ctrl_tip) } },
		{ ID::exp_vcf_key_track, { ctr_cbx, 2, Tip::from_SL(SL::vcf_key_track_tip) } },
		//exposed vca
		{ ID::exp_vca_1_volume, { ctr_sli_knb, 63, Tip::from_SL(SL::vca_1_volume_tip) } },
		{ ID::exp_vca_1_velo_amt, { ctr_sli_knb, 63, Tip::from_SL(SL::vca_1_velo_amt_tip) } },
		{ ID::exp_vca_2_env_2_amt, { ctr_sli_knb, 126, Tip::from_SL(SL::vca_2_env_2_amt_tip) } },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, { ctr_sli_knb, 0, Tip::from_SL(vcf_fm_osc_1_amt_tip) } },
		{ ID::exp_vcf_fm_env_3_amt, { ctr_sli_knb, 63, Tip::from_SL(vcf_fm_env_3_amt_tip) } },
		{ ID::exp_vcf_fm_press_amt, { ctr_sli_knb, 63, Tip::from_SL(SL::vcf_fm_pressure_amt_tip) } },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, { ctr_sli_knb, 0, Tip::from_SL(porta_rate_tip) } },
		{ ID::exp_porta_velo, { ctr_sli_knb, 63, Tip::from_SL(porta_velo_tip) } },
		{ ID::exp_porta_mode, { ctr_cbx, 0, Tip::from_SL(porta_mode_tip) } },
		{ ID::exp_porta_legato, { ctr_cbx, 0, Tip::from_SL(porta_legato_tip) } },
		{ ID::exp_keyboard_mode, { ctr_cbx, 0, Tip::from_SL(keyboard_mode_tip) } },
		//exposed lfo
		{ ID::exp_lfo_1_speed, { ctr_sli_knb, 27, Tip::exp_lfo_speed(1) } },
		{ ID::exp_lfo_1_wave_type, { ctr_cbx, 0, Tip::exp_lfo_wave_type(1) } },
		{ ID::exp_lfo_1_samp_source, { ctr_cbx, 9, Tip::exp_lfo_sample_source(1) } },
		{ ID::exp_lfo_1_amp, { ctr_sli_knb, 0, Tip::exp_lfo_amp(1) } },
		{ ID::exp_lfo_1_press_amt, { ctr_sli_knb, 63, Tip::from_SL(lfo_1_pressure_amt_tip) } },
		{ ID::exp_lfo_1_ramp_1_amt, { ctr_sli_knb, 63, Tip::exp_lfo_ramp_amt(1) } },
		{ ID::exp_lfo_1_trig_mode, { ctr_cbx, 0, Tip::exp_lfo_trig_mode(1) } },
		{ ID::exp_lfo_1_retrig_point, { ctr_sli_knb, 0, Tip::exp_lfo_retrig_point(1) } },
		{ ID::exp_lfo_1_lag, { ctr_cbx, 0, Tip::exp_lfo_lag(1) } },
		{ ID::exp_lfo_2_speed, { ctr_sli_knb, 27, Tip::exp_lfo_speed(3) } },
		{ ID::exp_lfo_2_wave_type, { ctr_cbx, 0, Tip::exp_lfo_wave_type(3) } },
		{ ID::exp_lfo_2_samp_source, { ctr_cbx, 9, Tip::exp_lfo_sample_source(3) } },
		{ ID::exp_lfo_2_amp, { ctr_sli_knb, 0, Tip::exp_lfo_amp(3) } },
		{ ID::exp_lfo_2_key_track_amt, { ctr_sli_knb, 63, Tip::from_SL(lfo_2_key_track_amt_tip) } },
		{ ID::exp_lfo_2_ramp_2_amt, { ctr_sli_knb, 63, Tip::exp_lfo_ramp_amt(3) } },
		{ ID::exp_lfo_2_trig_mode, { ctr_cbx, 0, Tip::exp_lfo_trig_mode(3) } },
		{ ID::exp_lfo_2_retrig_point, { ctr_sli_knb, 0, Tip::exp_lfo_retrig_point(3) } },
		{ ID::exp_lfo_2_lag, { ctr_cbx, 0, Tip::exp_lfo_lag(3) } },
		//exposed ramp
		{ ID::exp_ramp_1_rate, { ctr_sli_knb, 0, Tip::exp_ramp_rate(1) } },
		{ ID::exp_ramp_1_trig, { ctr_cbx, 0, Tip::exp_ramp_trig(1) } },
		{ ID::exp_ramp_2_rate, { ctr_sli_knb, 0, Tip::exp_ramp_rate(3) } },
		{ ID::exp_ramp_2_trig, { ctr_cbx, 0, Tip::exp_ramp_trig(3) } },
		//exposed tracking
		{ ID::exp_track_input, { ctr_cbx, 9, Tip::from_SL(track_input_tip) } },
		{ ID::exp_track_point_1, { ctr_sli_knb, 0, Tip::exp_track_point(2, 0) } },
		{ ID::exp_track_point_2, { ctr_sli_knb, 15, Tip::exp_track_point(2, 15) } },
		{ ID::exp_track_point_3, { ctr_sli_knb, 31, Tip::exp_track_point(3, 31) } },
		{ ID::exp_track_point_4, { ctr_sli_knb, 47, Tip::exp_track_point(4, 47) } },
		{ ID::exp_track_point_5, { ctr_sli_knb, 63, Tip::exp_track_point(5, 63) } },
		//exposed env
		{ ID::exp_env_1_amp, { ctr_sli_knb, 40, Tip::exp_env_amp(1) } },
		{ ID::exp_env_1_velo_amt, { ctr_sli_knb, 126, Tip::exp_env_velo_amt(1) } },
		{ ID::exp_env_1_trig_mode, { ctr_cbx, 0, Tip::exp_env_trig_mode(1) } },
		{ ID::exp_env_1_mode, { ctr_cbx, 0, Tip::exp_env_mode(1) } },
		{ ID::exp_env_1_lfo_1_trig, { ctr_cbx, 0, Tip::exp_env_lfo_1_trig(1) } },
		{ ID::exp_env_1_delay, { ctr_sli_knb, 0, Tip::exp_env_stage(2, 0) } },
		{ ID::exp_env_1_attack, { ctr_sli_knb, 0, Tip::exp_env_stage(2, 1) } },
		{ ID::exp_env_1_decay, { ctr_sli_knb, 10, Tip::exp_env_stage(2, 2) } },
		{ ID::exp_env_1_sustain, { ctr_sli_knb, 50, Tip::exp_env_stage(2, 3) } },
		{ ID::exp_env_1_release, { ctr_sli_knb, 10, Tip::exp_env_stage(2, 4) } },
		{ ID::exp_env_2_amp, { ctr_sli_knb, 40, Tip::exp_env_amp(3) } },
		{ ID::exp_env_2_velo_amt, { ctr_sli_knb, 126, Tip::exp_env_velo_amt(3) } },
		{ ID::exp_env_2_trig_mode, { ctr_cbx, 0, Tip::exp_env_trig_mode(3) } },
		{ ID::exp_env_2_mode, { ctr_cbx, 0, Tip::exp_env_mode(3) } },
		{ ID::exp_env_2_lfo_1_trig, { ctr_cbx, 0, Tip::exp_env_lfo_1_trig(3) } },
		{ ID::exp_env_2_delay, { ctr_sli_knb, 0, Tip::exp_env_stage(2, 0) } },
		{ ID::exp_env_2_attack, { ctr_sli_knb, 0, Tip::exp_env_stage(2, 1) } },
		{ ID::exp_env_2_decay, { ctr_sli_knb, 10, Tip::exp_env_stage(2, 2) } },
		{ ID::exp_env_2_sustain, { ctr_sli_knb, 50, Tip::exp_env_stage(2, 3) } },
		{ ID::exp_env_2_release, { ctr_sli_knb, 10, Tip::exp_env_stage(2, 4) } },
		{ ID::exp_env_3_amp, { ctr_sli_knb, 40, Tip::exp_env_amp(3) } },
		{ ID::exp_env_3_velo_amt, { ctr_sli_knb, 126, Tip::exp_env_velo_amt(3) } },
		{ ID::exp_env_3_trig_mode, { ctr_cbx, 0, Tip::exp_env_trig_mode(3) } },
		{ ID::exp_env_3_mode, { ctr_cbx, 0, Tip::exp_env_mode(3) } },
		{ ID::exp_env_3_lfo_1_trig, { ctr_cbx, 0, Tip::exp_env_lfo_1_trig(3) } },
		{ ID::exp_env_3_delay, { ctr_sli_knb, 0, Tip::exp_env_stage(3, 0) } },
		{ ID::exp_env_3_attack, { ctr_sli_knb, 0, Tip::exp_env_stage(3, 1) } },
		{ ID::exp_env_3_decay, { ctr_sli_knb, 20, Tip::exp_env_stage(3, 2) } },
		{ ID::exp_env_3_sustain, { ctr_sli_knb, 0, Tip::exp_env_stage(3, 3) } },
		{ ID::exp_env_3_release, { ctr_sli_knb, 20, Tip::exp_env_stage(3, 4) } },

		{ ID::mmod_0_src, { ctr_cbx, 17, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_0_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_0_dst, { ctr_cbx, 16, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_1_src, { ctr_cbx, 17, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_1_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_1_dst, { ctr_cbx, 21, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_2_src, { ctr_cbx, 11, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_2_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_2_dst, { ctr_cbx, 9, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_3_src, { ctr_cbx, 20, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_3_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_3_dst, { ctr_cbx, 8, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_4_src, { ctr_cbx, 0, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_4_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_4_dst, { ctr_cbx, 0, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_5_src, { ctr_cbx, 0, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_5_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_5_dst, { ctr_cbx, 0, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_6_src, { ctr_cbx, 0, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_6_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_6_dst, { ctr_cbx, 0, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_7_src, { ctr_cbx, 0, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_7_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_7_dst, { ctr_cbx, 0, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_8_src, { ctr_cbx, 0, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_8_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_8_dst, { ctr_cbx, 0, Tip::from_SL(mmod_dst_tip) } },
		{ ID::mmod_9_src, { ctr_cbx, 0, Tip::from_SL(mmod_src_tip) } },
		{ ID::mmod_9_amt, { ctr_sli_knb, 63, Tip::from_SL(mmod_amt_tip) } },
		{ ID::mmod_9_dst, { ctr_cbx, 0, Tip::from_SL(mmod_dst_tip) } },
	};

}
