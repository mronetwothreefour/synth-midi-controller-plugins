#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"
#include "C_MISC_P.h"
#include "C_SL_Tip_Widget_P.h"
#include "D_BUILD_Tip_For_P.h"

using namespace BUILD;
using namespace MISC;
using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<string, int, string>> txt_editor_traits{
		//exposed osc
		{ ID::exp_osc_1_pitch, txt_editor_traits_osc_pitch },
		{ ID::exp_osc_1_fine_tune, txt_editor_traits_osc_fine_tune },
		{ ID::exp_osc_1_shape, txt_editor_traits_osc_shape },
		{ ID::exp_osc_1_glide, txt_editor_traits_u_7_bit },
		{ ID::exp_osc_1_sub_level, txt_editor_traits_u_7_bit },
		{ ID::exp_osc_2_pitch, txt_editor_traits_osc_pitch },
		{ ID::exp_osc_2_fine_tune, txt_editor_traits_osc_fine_tune },
		{ ID::exp_osc_2_shape, txt_editor_traits_osc_shape },
		{ ID::exp_osc_2_glide, txt_editor_traits_u_7_bit },
		{ ID::exp_osc_2_sub_level, txt_editor_traits_u_7_bit },
		{ ID::exp_osc_slop, { allowed_chars_osc_slop, 1, Tip_For::txt_editor_u_int(5) } },
		{ ID::exp_bend_range, { allowed_chars_u_int, 2, Tip_For::txt_editor_u_int(12) } },
		{ ID::exp_osc_mix, txt_editor_traits_u_7_bit },
		{ ID::exp_noise_level, txt_editor_traits_u_7_bit },
		{ ID::exp_ext_in_level, txt_editor_traits_u_7_bit },
		//exposed lpf
		{ ID::exp_lpf_freq, { allowed_chars_pitch, 4, Tip_For::txt_editor_pitch(61, 0, 164) } },
		{ ID::exp_lpf_reso, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_key_amt, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_fm_amt, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_env_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_lpf_vel_amt, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_delay, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_attack, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_decay, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_sustain, txt_editor_traits_u_7_bit },
		{ ID::exp_lpf_release, txt_editor_traits_u_7_bit },
		//exposed vca
		{ ID::exp_vca_level, txt_editor_traits_u_7_bit },
		{ ID::exp_vca_env_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_vca_vel_amt, txt_editor_traits_u_7_bit },
		{ ID::exp_vca_delay, txt_editor_traits_u_7_bit },
		{ ID::exp_vca_attack, txt_editor_traits_u_7_bit },
		{ ID::exp_vca_decay, txt_editor_traits_u_7_bit },
		{ ID::exp_vca_sustain, txt_editor_traits_u_7_bit },
		{ ID::exp_vca_release, txt_editor_traits_u_7_bit },
		{ ID::exp_voice_volume, txt_editor_traits_u_7_bit },
		//exposed lfo
		{ ID::exp_lfo_1_freq, txt_editor_traits_lfo_freq },
		{ ID::exp_lfo_1_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_lfo_2_freq, txt_editor_traits_lfo_freq },
		{ ID::exp_lfo_2_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_lfo_3_freq, txt_editor_traits_lfo_freq },
		{ ID::exp_lfo_3_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_lfo_4_freq, txt_editor_traits_lfo_freq },
		{ ID::exp_lfo_4_amt, txt_editor_traits_s_8_bit },
		//exposed env 3
		{ ID::exp_env_3_amount, txt_editor_traits_s_8_bit },
		{ ID::exp_env_3_vel_amt, txt_editor_traits_u_7_bit },
		{ ID::exp_env_3_delay, txt_editor_traits_u_7_bit },
		{ ID::exp_env_3_attack, txt_editor_traits_u_7_bit },
		{ ID::exp_env_3_decay, txt_editor_traits_u_7_bit },
		{ ID::exp_env_3_sustain, txt_editor_traits_u_7_bit },
		{ ID::exp_env_3_release, txt_editor_traits_u_7_bit },
		//exposed mod
		{ ID::exp_mod_1_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_mod_2_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_mod_3_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_mod_4_amt, txt_editor_traits_s_8_bit },
		//exposed midi cc
		{ ID::exp_mod_wheel_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_press_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_breath_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_velocity_amt, txt_editor_traits_s_8_bit },
		{ ID::exp_pedal_amt, txt_editor_traits_s_8_bit },
		//exposed push it
		{ ID::exp_push_it_pitch, txt_editor_traits_osc_pitch },
		{ ID::exp_push_it_velo, txt_editor_traits_u_7_bit },
		//exposed clock & arp
		{ ID::exp_clock_tempo, { allowed_chars_u_int, 3, Tip_For::from_SL(SL::edit_clock_tempo_tip) } },
		//exposed seq step
		{ ID::exp_seq_track_1_step_1, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_2, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_3, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_4, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_5, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_6, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_7, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_8, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_9, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_10, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_11, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_12, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_13, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_14, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_15, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_1_step_16, txt_editor_traits_step_t_1 },
		{ ID::exp_seq_track_2_step_1, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_2, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_3, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_4, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_5, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_6, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_7, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_8, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_9, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_10, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_11, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_12, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_13, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_14, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_15, txt_editor_traits_step },
		{ ID::exp_seq_track_2_step_16, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_1, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_2, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_3, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_4, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_5, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_6, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_7, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_8, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_9, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_10, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_11, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_12, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_13, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_14, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_15, txt_editor_traits_step },
		{ ID::exp_seq_track_3_step_16, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_1, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_2, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_3, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_4, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_5, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_6, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_7, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_8, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_9, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_10, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_11, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_12, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_13, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_14, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_15, txt_editor_traits_step },
		{ ID::exp_seq_track_4_step_16, txt_editor_traits_step },
	};

}
