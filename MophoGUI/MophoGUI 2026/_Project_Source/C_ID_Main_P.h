#pragma once

#include <array>

namespace ID
{

	constexpr auto exp_arp_mode = "exp_arp_mode";
	constexpr auto exp_arpeg_on_off = "exp_arpeg_on_off";
	constexpr auto exp_bend_range = "exp_bend_range";
	constexpr auto exp_breath_amt = "exp_breath_amt";
	constexpr auto exp_breath_dest = "exp_breath_dest";
	constexpr auto exp_clock_div = "exp_clock_div";
	constexpr auto exp_clock_tempo = "exp_clock_tempo";
	constexpr auto exp_env_3_amount = "exp_env_3_amount";
	constexpr auto exp_env_3_attack = "exp_env_3_attack";
	constexpr auto exp_env_3_decay = "exp_env_3_decay";
	constexpr auto exp_env_3_delay = "exp_env_3_delay";
	constexpr auto exp_env_3_dest = "exp_env_3_dest";
	constexpr auto exp_env_3_release = "exp_env_3_release";
	constexpr auto exp_env_3_repeat = "exp_env_3_repeat";
	constexpr auto exp_env_3_sustain = "exp_env_3_sustain";
	constexpr auto exp_env_3_vel_amt = "exp_env_3_vel_amt";
	constexpr auto exp_ext_in_level = "exp_ext_in_level";
	constexpr auto exp_flex_knob_1 = "exp_flex_knob_1";
	constexpr auto exp_flex_knob_2 = "exp_flex_knob_2";
	constexpr auto exp_flex_knob_3 = "exp_flex_knob_3";
	constexpr auto exp_flex_knob_4 = "exp_flex_knob_4";
	constexpr auto exp_glide_mode = "exp_glide_mode";
	constexpr auto exp_lfo_1_amt = "exp_lfo_1_amt";
	constexpr auto exp_lfo_1_dest = "exp_lfo_1_dest";
	constexpr auto exp_lfo_1_freq = "exp_lfo_1_freq";
	constexpr auto exp_lfo_1_key_sync = "exp_lfo_1_key_sync";
	constexpr auto exp_lfo_1_shape = "exp_lfo_1_shape";
	constexpr auto exp_lfo_2_amt = "exp_lfo_2_amt";
	constexpr auto exp_lfo_2_dest = "exp_lfo_2_dest";
	constexpr auto exp_lfo_2_freq = "exp_lfo_2_freq";
	constexpr auto exp_lfo_2_key_sync = "exp_lfo_2_key_sync";
	constexpr auto exp_lfo_2_shape = "exp_lfo_2_shape";
	constexpr auto exp_lfo_3_amt = "exp_lfo_3_amt";
	constexpr auto exp_lfo_3_dest = "exp_lfo_3_dest";
	constexpr auto exp_lfo_3_freq = "exp_lfo_3_freq";
	constexpr auto exp_lfo_3_key_sync = "exp_lfo_3_key_sync";
	constexpr auto exp_lfo_3_shape = "exp_lfo_3_shape";
	constexpr auto exp_lfo_4_amt = "exp_lfo_4_amt";
	constexpr auto exp_lfo_4_dest = "exp_lfo_4_dest";
	constexpr auto exp_lfo_4_freq = "exp_lfo_4_freq";
	constexpr auto exp_lfo_4_key_sync = "exp_lfo_4_key_sync";
	constexpr auto exp_lfo_4_shape = "exp_lfo_4_shape";
	constexpr auto exp_lpf_attack = "exp_lpf_attack";
	constexpr auto exp_lpf_decay = "exp_lpf_decay";
	constexpr auto exp_lpf_delay = "exp_lpf_delay";
	constexpr auto exp_lpf_env_amt = "exp_lpf_env_amt";
	constexpr auto exp_lpf_fm_amt = "exp_lpf_fm_amt";
	constexpr auto exp_lpf_freq = "exp_lpf_freq";
	constexpr auto exp_lpf_key_amt = "exp_lpf_key_amt";
	constexpr auto exp_lpf_release = "exp_lpf_release";
	constexpr auto exp_lpf_reso = "exp_lpf_reso";
	constexpr auto exp_lpf_sustain = "exp_lpf_sustain";
	constexpr auto exp_lpf_type = "exp_lpf_type";
	constexpr auto exp_lpf_vel_amt = "exp_lpf_vel_amt";
	constexpr auto exp_mod_1_amt = "exp_mod_1_amt";
	constexpr auto exp_mod_1_dest = "exp_mod_1_dest";
	constexpr auto exp_mod_1_src = "exp_mod_1_src";
	constexpr auto exp_mod_2_amt = "exp_mod_2_amt";
	constexpr auto exp_mod_2_dest = "exp_mod_2_dest";
	constexpr auto exp_mod_2_src = "exp_mod_2_src";
	constexpr auto exp_mod_3_amt = "exp_mod_3_amt";
	constexpr auto exp_mod_3_dest = "exp_mod_3_dest";
	constexpr auto exp_mod_3_src = "exp_mod_3_src";
	constexpr auto exp_mod_4_amt = "exp_mod_4_amt";
	constexpr auto exp_mod_4_dest = "exp_mod_4_dest";
	constexpr auto exp_mod_4_src = "exp_mod_4_src";
	constexpr auto exp_mod_wheel_amt = "exp_mod_wheel_amt";
	constexpr auto exp_mod_wheel_dest = "exp_mod_wheel_dest";
	constexpr auto exp_noise_level = "exp_noise_level";
	constexpr auto exp_note_priority = "exp_note_priority";
	constexpr auto exp_osc_1_fine_tune = "exp_osc_1_fine_tune";
	constexpr auto exp_osc_1_glide = "exp_osc_1_glide";
	constexpr auto exp_osc_1_key_track = "exp_osc_1_key_track";
	constexpr auto exp_osc_1_pitch = "exp_osc_1_pitch";
	constexpr auto exp_osc_1_shape = "exp_osc_1_shape";
	constexpr auto exp_osc_1_sub_level = "exp_osc_1_sub_level";
	constexpr auto exp_osc_2_fine_tune = "exp_osc_2_fine_tune";
	constexpr auto exp_osc_2_glide = "exp_osc_2_glide";
	constexpr auto exp_osc_2_key_track = "exp_osc_2_key_track";
	constexpr auto exp_osc_2_pitch = "exp_osc_2_pitch";
	constexpr auto exp_osc_2_shape = "exp_osc_2_shape";
	constexpr auto exp_osc_2_sub_level = "exp_osc_2_sub_level";
	constexpr auto exp_osc_mix = "exp_osc_mix";
	constexpr auto exp_osc_slop = "exp_osc_slop";
	constexpr auto exp_osc_sync = "exp_osc_sync";
	constexpr auto exp_pedal_amt = "exp_pedal_amt";
	constexpr auto exp_pedal_dest = "exp_pedal_dest";
	constexpr auto exp_press_amt = "exp_press_amt";
	constexpr auto exp_press_dest = "exp_press_dest";
	constexpr auto exp_push_it_mode = "exp_push_it_mode";
	constexpr auto exp_push_it_pitch = "exp_push_it_pitch";
	constexpr auto exp_push_it_velo = "exp_push_it_velo";
	constexpr auto exp_seq_on_off = "exp_seq_on_off";
	constexpr auto exp_seq_track_1_dest = "exp_seq_track_1_dest";
	constexpr auto exp_seq_track_1_step_1 = "exp_seq_track_1_step_1";
	constexpr auto exp_seq_track_1_step_10 = "exp_seq_track_1_step_10";
	constexpr auto exp_seq_track_1_step_11 = "exp_seq_track_1_step_11";
	constexpr auto exp_seq_track_1_step_12 = "exp_seq_track_1_step_12";
	constexpr auto exp_seq_track_1_step_13 = "exp_seq_track_1_step_13";
	constexpr auto exp_seq_track_1_step_14 = "exp_seq_track_1_step_14";
	constexpr auto exp_seq_track_1_step_15 = "exp_seq_track_1_step_15";
	constexpr auto exp_seq_track_1_step_16 = "exp_seq_track_1_step_16";
	constexpr auto exp_seq_track_1_step_2 = "exp_seq_track_1_step_2";
	constexpr auto exp_seq_track_1_step_3 = "exp_seq_track_1_step_3";
	constexpr auto exp_seq_track_1_step_4 = "exp_seq_track_1_step_4";
	constexpr auto exp_seq_track_1_step_5 = "exp_seq_track_1_step_5";
	constexpr auto exp_seq_track_1_step_6 = "exp_seq_track_1_step_6";
	constexpr auto exp_seq_track_1_step_7 = "exp_seq_track_1_step_7";
	constexpr auto exp_seq_track_1_step_8 = "exp_seq_track_1_step_8";
	constexpr auto exp_seq_track_1_step_9 = "exp_seq_track_1_step_9";
	constexpr auto exp_seq_track_2_dest = "exp_seq_track_2_dest";
	constexpr auto exp_seq_track_2_step_1 = "exp_seq_track_2_step_1";
	constexpr auto exp_seq_track_2_step_10 = "exp_seq_track_2_step_10";
	constexpr auto exp_seq_track_2_step_11 = "exp_seq_track_2_step_11";
	constexpr auto exp_seq_track_2_step_12 = "exp_seq_track_2_step_12";
	constexpr auto exp_seq_track_2_step_13 = "exp_seq_track_2_step_13";
	constexpr auto exp_seq_track_2_step_14 = "exp_seq_track_2_step_14";
	constexpr auto exp_seq_track_2_step_15 = "exp_seq_track_2_step_15";
	constexpr auto exp_seq_track_2_step_16 = "exp_seq_track_2_step_16";
	constexpr auto exp_seq_track_2_step_2 = "exp_seq_track_2_step_2";
	constexpr auto exp_seq_track_2_step_3 = "exp_seq_track_2_step_3";
	constexpr auto exp_seq_track_2_step_4 = "exp_seq_track_2_step_4";
	constexpr auto exp_seq_track_2_step_5 = "exp_seq_track_2_step_5";
	constexpr auto exp_seq_track_2_step_6 = "exp_seq_track_2_step_6";
	constexpr auto exp_seq_track_2_step_7 = "exp_seq_track_2_step_7";
	constexpr auto exp_seq_track_2_step_8 = "exp_seq_track_2_step_8";
	constexpr auto exp_seq_track_2_step_9 = "exp_seq_track_2_step_9";
	constexpr auto exp_seq_track_3_dest = "exp_seq_track_3_dest";
	constexpr auto exp_seq_track_3_step_1 = "exp_seq_track_3_step_1";
	constexpr auto exp_seq_track_3_step_10 = "exp_seq_track_3_step_10";
	constexpr auto exp_seq_track_3_step_11 = "exp_seq_track_3_step_11";
	constexpr auto exp_seq_track_3_step_12 = "exp_seq_track_3_step_12";
	constexpr auto exp_seq_track_3_step_13 = "exp_seq_track_3_step_13";
	constexpr auto exp_seq_track_3_step_14 = "exp_seq_track_3_step_14";
	constexpr auto exp_seq_track_3_step_15 = "exp_seq_track_3_step_15";
	constexpr auto exp_seq_track_3_step_16 = "exp_seq_track_3_step_16";
	constexpr auto exp_seq_track_3_step_2 = "exp_seq_track_3_step_2";
	constexpr auto exp_seq_track_3_step_3 = "exp_seq_track_3_step_3";
	constexpr auto exp_seq_track_3_step_4 = "exp_seq_track_3_step_4";
	constexpr auto exp_seq_track_3_step_5 = "exp_seq_track_3_step_5";
	constexpr auto exp_seq_track_3_step_6 = "exp_seq_track_3_step_6";
	constexpr auto exp_seq_track_3_step_7 = "exp_seq_track_3_step_7";
	constexpr auto exp_seq_track_3_step_8 = "exp_seq_track_3_step_8";
	constexpr auto exp_seq_track_3_step_9 = "exp_seq_track_3_step_9";
	constexpr auto exp_seq_track_4_dest = "exp_seq_track_4_dest";
	constexpr auto exp_seq_track_4_step_1 = "exp_seq_track_4_step_1";
	constexpr auto exp_seq_track_4_step_10 = "exp_seq_track_4_step_10";
	constexpr auto exp_seq_track_4_step_11 = "exp_seq_track_4_step_11";
	constexpr auto exp_seq_track_4_step_12 = "exp_seq_track_4_step_12";
	constexpr auto exp_seq_track_4_step_13 = "exp_seq_track_4_step_13";
	constexpr auto exp_seq_track_4_step_14 = "exp_seq_track_4_step_14";
	constexpr auto exp_seq_track_4_step_15 = "exp_seq_track_4_step_15";
	constexpr auto exp_seq_track_4_step_16 = "exp_seq_track_4_step_16";
	constexpr auto exp_seq_track_4_step_2 = "exp_seq_track_4_step_2";
	constexpr auto exp_seq_track_4_step_3 = "exp_seq_track_4_step_3";
	constexpr auto exp_seq_track_4_step_4 = "exp_seq_track_4_step_4";
	constexpr auto exp_seq_track_4_step_5 = "exp_seq_track_4_step_5";
	constexpr auto exp_seq_track_4_step_6 = "exp_seq_track_4_step_6";
	constexpr auto exp_seq_track_4_step_7 = "exp_seq_track_4_step_7";
	constexpr auto exp_seq_track_4_step_8 = "exp_seq_track_4_step_8";
	constexpr auto exp_seq_track_4_step_9 = "exp_seq_track_4_step_9";
	constexpr auto exp_seq_trig_mode = "exp_seq_trig_mode";
	constexpr auto exp_unassigned_1 = "exp_unassigned_1";
	constexpr auto exp_unassigned_10 = "exp_unassigned_10";
	constexpr auto exp_unassigned_11 = "exp_unassigned_11";
	constexpr auto exp_unassigned_2 = "exp_unassigned_2";
	constexpr auto exp_unassigned_3 = "exp_unassigned_3";
	constexpr auto exp_unassigned_4 = "exp_unassigned_4";
	constexpr auto exp_unassigned_5 = "exp_unassigned_5";
	constexpr auto exp_unassigned_6 = "exp_unassigned_6";
	constexpr auto exp_unassigned_7 = "exp_unassigned_7";
	constexpr auto exp_unassigned_8 = "exp_unassigned_8";
	constexpr auto exp_unassigned_9 = "exp_unassigned_9";
	constexpr auto exp_vca_attack = "exp_vca_attack";
	constexpr auto exp_vca_decay = "exp_vca_decay";
	constexpr auto exp_vca_delay = "exp_vca_delay";
	constexpr auto exp_vca_env_amt = "exp_vca_env_amt";
	constexpr auto exp_vca_level = "exp_vca_level";
	constexpr auto exp_vca_release = "exp_vca_release";
	constexpr auto exp_vca_sustain = "exp_vca_sustain";
	constexpr auto exp_vca_vel_amt = "exp_vca_vel_amt";
	constexpr auto exp_velocity_amt = "exp_velocity_amt";
	constexpr auto exp_velocity_dest = "exp_velocity_dest";
	constexpr auto exp_voice_name_char_1 = "exp_voice_name_char_1";
	constexpr auto exp_voice_name_char_10 = "exp_voice_name_char_10";
	constexpr auto exp_voice_name_char_11 = "exp_voice_name_char_11";
	constexpr auto exp_voice_name_char_12 = "exp_voice_name_char_12";
	constexpr auto exp_voice_name_char_13 = "exp_voice_name_char_13";
	constexpr auto exp_voice_name_char_14 = "exp_voice_name_char_14";
	constexpr auto exp_voice_name_char_15 = "exp_voice_name_char_15";
	constexpr auto exp_voice_name_char_16 = "exp_voice_name_char_16";
	constexpr auto exp_voice_name_char_2 = "exp_voice_name_char_2";
	constexpr auto exp_voice_name_char_3 = "exp_voice_name_char_3";
	constexpr auto exp_voice_name_char_4 = "exp_voice_name_char_4";
	constexpr auto exp_voice_name_char_5 = "exp_voice_name_char_5";
	constexpr auto exp_voice_name_char_6 = "exp_voice_name_char_6";
	constexpr auto exp_voice_name_char_7 = "exp_voice_name_char_7";
	constexpr auto exp_voice_name_char_8 = "exp_voice_name_char_8";
	constexpr auto exp_voice_name_char_9 = "exp_voice_name_char_9";
	constexpr auto exp_voice_volume = "exp_voice_volume";

	constexpr std::array<const char*, 200> exp_params{
		exp_osc_1_pitch,
		exp_osc_1_fine_tune,
		exp_osc_1_shape,
		exp_osc_1_glide,
		exp_osc_1_sub_level,
		exp_osc_1_key_track,
		exp_osc_2_pitch,
		exp_osc_2_fine_tune,
		exp_osc_2_shape,
		exp_osc_2_glide,
		exp_osc_2_key_track,
		exp_osc_2_sub_level,
		exp_osc_sync,
		exp_glide_mode,
		exp_osc_slop,
		exp_bend_range,
		exp_note_priority,
		exp_osc_mix,
		exp_noise_level,
		exp_ext_in_level,
		exp_lpf_freq,
		exp_lpf_reso,
		exp_lpf_key_amt,
		exp_lpf_fm_amt,
		exp_lpf_type,
		exp_lpf_env_amt,
		exp_lpf_vel_amt,
		exp_lpf_delay,
		exp_lpf_attack,
		exp_lpf_decay,
		exp_lpf_sustain,
		exp_lpf_release,
		exp_vca_level,
		exp_vca_env_amt,
		exp_vca_vel_amt,
		exp_vca_delay,
		exp_vca_attack,
		exp_vca_decay,
		exp_vca_sustain,
		exp_vca_release,
		exp_voice_volume,
		exp_lfo_1_freq,
		exp_lfo_1_shape,
		exp_lfo_1_amt,
		exp_lfo_1_dest,
		exp_lfo_1_key_sync,
		exp_lfo_2_freq,
		exp_lfo_2_shape,
		exp_lfo_2_amt,
		exp_lfo_2_dest,
		exp_lfo_2_key_sync,
		exp_lfo_3_freq,
		exp_lfo_3_shape,
		exp_lfo_3_amt,
		exp_lfo_3_dest,
		exp_lfo_3_key_sync,
		exp_lfo_4_freq,
		exp_lfo_4_shape,
		exp_lfo_4_amt,
		exp_lfo_4_dest,
		exp_lfo_4_key_sync,
		exp_env_3_dest,
		exp_env_3_amount,
		exp_env_3_vel_amt,
		exp_env_3_delay,
		exp_env_3_attack,
		exp_env_3_decay,
		exp_env_3_sustain,
		exp_env_3_release,
		exp_env_3_repeat,
		exp_mod_1_src,
		exp_mod_1_amt,
		exp_mod_1_dest,
		exp_mod_2_src,
		exp_mod_2_amt,
		exp_mod_2_dest,
		exp_mod_3_src,
		exp_mod_3_amt,
		exp_mod_3_dest,
		exp_mod_4_src,
		exp_mod_4_amt,
		exp_mod_4_dest,
		exp_mod_wheel_amt,
		exp_mod_wheel_dest,
		exp_press_amt,
		exp_press_dest,
		exp_breath_amt,
		exp_breath_dest,
		exp_velocity_amt,
		exp_velocity_dest,
		exp_pedal_amt,
		exp_pedal_dest,
		exp_push_it_pitch,
		exp_push_it_velo,
		exp_push_it_mode,
		exp_clock_tempo,
		exp_clock_div,
		exp_arp_mode,
		exp_arpeg_on_off,
		exp_seq_trig_mode,
		exp_seq_on_off,
		exp_seq_track_1_dest,
		exp_seq_track_2_dest,
		exp_seq_track_3_dest,
		exp_seq_track_4_dest,
		exp_flex_knob_1,
		exp_flex_knob_2,
		exp_flex_knob_3,
		exp_flex_knob_4,
		exp_unassigned_1,
		exp_unassigned_2,
		exp_unassigned_3,
		exp_unassigned_4,
		exp_unassigned_5,
		exp_unassigned_6,
		exp_unassigned_7,
		exp_unassigned_8,
		exp_unassigned_9,
		exp_unassigned_10,
		exp_unassigned_11,
		exp_seq_track_1_step_1,
		exp_seq_track_1_step_2,
		exp_seq_track_1_step_3,
		exp_seq_track_1_step_4,
		exp_seq_track_1_step_5,
		exp_seq_track_1_step_6,
		exp_seq_track_1_step_7,
		exp_seq_track_1_step_8,
		exp_seq_track_1_step_9,
		exp_seq_track_1_step_10,
		exp_seq_track_1_step_11,
		exp_seq_track_1_step_12,
		exp_seq_track_1_step_13,
		exp_seq_track_1_step_14,
		exp_seq_track_1_step_15,
		exp_seq_track_1_step_16,
		exp_seq_track_2_step_1,
		exp_seq_track_2_step_2,
		exp_seq_track_2_step_3,
		exp_seq_track_2_step_4,
		exp_seq_track_2_step_5,
		exp_seq_track_2_step_6,
		exp_seq_track_2_step_7,
		exp_seq_track_2_step_8,
		exp_seq_track_2_step_9,
		exp_seq_track_2_step_10,
		exp_seq_track_2_step_11,
		exp_seq_track_2_step_12,
		exp_seq_track_2_step_13,
		exp_seq_track_2_step_14,
		exp_seq_track_2_step_15,
		exp_seq_track_2_step_16,
		exp_seq_track_3_step_1,
		exp_seq_track_3_step_2,
		exp_seq_track_3_step_3,
		exp_seq_track_3_step_4,
		exp_seq_track_3_step_5,
		exp_seq_track_3_step_6,
		exp_seq_track_3_step_7,
		exp_seq_track_3_step_8,
		exp_seq_track_3_step_9,
		exp_seq_track_3_step_10,
		exp_seq_track_3_step_11,
		exp_seq_track_3_step_12,
		exp_seq_track_3_step_13,
		exp_seq_track_3_step_14,
		exp_seq_track_3_step_15,
		exp_seq_track_3_step_16,
		exp_seq_track_4_step_1,
		exp_seq_track_4_step_2,
		exp_seq_track_4_step_3,
		exp_seq_track_4_step_4,
		exp_seq_track_4_step_5,
		exp_seq_track_4_step_6,
		exp_seq_track_4_step_7,
		exp_seq_track_4_step_8,
		exp_seq_track_4_step_9,
		exp_seq_track_4_step_10,
		exp_seq_track_4_step_11,
		exp_seq_track_4_step_12,
		exp_seq_track_4_step_13,
		exp_seq_track_4_step_14,
		exp_seq_track_4_step_15,
		exp_seq_track_4_step_16,
		exp_voice_name_char_1,
		exp_voice_name_char_2,
		exp_voice_name_char_3,
		exp_voice_name_char_4,
		exp_voice_name_char_5,
		exp_voice_name_char_6,
		exp_voice_name_char_7,
		exp_voice_name_char_8,
		exp_voice_name_char_9,
		exp_voice_name_char_10,
		exp_voice_name_char_11,
		exp_voice_name_char_12,
		exp_voice_name_char_13,
		exp_voice_name_char_14,
		exp_voice_name_char_15,
		exp_voice_name_char_16
	};

}
