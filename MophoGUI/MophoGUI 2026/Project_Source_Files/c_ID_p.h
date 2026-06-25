#pragma once

#include <JuceHeader.h>

#include "C_ID_B.h"

namespace ID
{

	static const Identifier exp_000_osc_1_pitch     { "exp_000_osc_1_pitch" };
	static const Identifier exp_001_osc_1_fine_tune { "exp_001_osc_1_fine_tune" };
	static const Identifier exp_002_osc_1_shape     { "exp_002_osc_1_shape" };
	static const Identifier exp_003_osc_1_glide     { "exp_003_osc_1_glide" };
	static const Identifier exp_004_osc_1_key_track { "exp_004_osc_1_key_track" };
	static const Identifier exp_005_osc_1_sub_level { "exp_005_osc_1_sub_level" };
	static const Identifier exp_006_osc_2_pitch     { "exp_006_osc_2_pitch" };
	static const Identifier exp_007_osc_2_fine_tune { "exp_007_osc_2_fine_tune" };
	static const Identifier exp_008_osc_2_shape     { "exp_008_osc_2_shape" };
	static const Identifier exp_009_osc_2_glide     { "exp_009_osc_2_glide" };
	static const Identifier exp_010_osc_2_key_track { "exp_010_osc_2_key_track" };
	static const Identifier exp_011_osc_2_sub_level { "exp_011_osc_2_sub_level" };
	static const Identifier exp_012_osc_sync        { "exp_012_osc_sync" };
	static const Identifier exp_013_glide_mode      { "exp_013_glide_mode" };
	static const Identifier exp_014_osc_slop        { "exp_014_osc_slop" };
	static const Identifier exp_015_bend_range      { "exp_015_bend_range" };
	static const Identifier exp_016_note_priority   { "exp_016_note_priority" };
	static const Identifier exp_017_osc_mix         { "exp_017_osc_mix" };
	static const Identifier exp_018_noise_level     { "exp_018_noise_level" };
	static const Identifier exp_019_ext_in_level    { "exp_019_ext_in_level" };
	static const Identifier exp_020_lpf_freq        { "exp_020_lpf_freq" };
	static const Identifier exp_021_lpf_reso        { "exp_021_lpf_reso" };
	static const Identifier exp_022_lpf_key_amt     { "exp_022_lpf_key_amt" };
	static const Identifier exp_023_lpf_fm_amt      { "exp_023_lpf_fm_amt" };
	static const Identifier exp_024_lpf_type        { "exp_024_lpf_type" };
	static const Identifier exp_025_lpf_env_amt     { "exp_025_lpf_env_amt" };
	static const Identifier exp_026_lpf_velo_amt    { "exp_026_lpf_velo_amt" };
	static const Identifier exp_027_lpf_delay       { "exp_027_lpf_delay" };
	static const Identifier exp_028_lpf_attack      { "exp_028_lpf_attack" };
	static const Identifier exp_029_lpf_decay       { "exp_029_lpf_decay" };
	static const Identifier exp_030_lpf_sustain     { "exp_030_lpf_sustain" };
	static const Identifier exp_031_lpf_release     { "exp_031_LPF_release" };
	static const Identifier exp_032_vca_level       { "exp_032_vca_level" };
	static const Identifier exp_033_vca_env_amt     { "exp_033_vca_env_amt" };
	static const Identifier exp_034_vca_vel_amt     { "exp_034_vca_vel_amt" };
	static const Identifier exp_035_vca_delay       { "exp_035_vca_delay" };
	static const Identifier exp_036_vca_attack      { "exp_036_vca_attack" };
	static const Identifier exp_037_vca_decay       { "exp_037_vca_decay" };
	static const Identifier exp_038_vca_sustain     { "exp_038_vca_sustain" };
	static const Identifier exp_039_vca_release     { "exp_039_vca_release" };
	static const Identifier exp_040_voice_volume    { "exp_040_voice_volume" };
	static const Identifier exp_061_env_3_dest      { "exp_061_env_3_dest" };
	static const Identifier exp_062_env_3_amount    { "exp_062_env_3_amount" };
	static const Identifier exp_063_env_3_velo_amt  { "exp_063_env_3_velo_amt" };
	static const Identifier exp_064_env_3_delay     { "exp_064_env_3_delay" };
	static const Identifier exp_065_env_3_attack    { "exp_065_env_3_attack" };
	static const Identifier exp_066_env_3_decay     { "exp_066_env_3_decay" };
	static const Identifier exp_067_env_3_sustain   { "exp_067_env_3_sustain" };
	static const Identifier exp_068_env_3_release   { "exp_068_env_3_release" };
	static const Identifier exp_069_env_3_repeat    { "exp_069_env_3_repeat" };
	static const Identifier exp_082_mod_wheel_amt   { "exp_082_mod_wheel_amt" };
	static const Identifier exp_083_mod_wheel_dest  { "exp_083_mod_wheel_dest" };
	static const Identifier exp_084_press_amt       { "exp_084_press_amt" };
	static const Identifier exp_085_press_dest      { "exp_085_press_dest" };
	static const Identifier exp_086_breath_amt      { "exp_086_breath_amt" };
	static const Identifier exp_087_breath_dest     { "exp_087_breath_dest" };
	static const Identifier exp_088_velocity_amt    { "exp_088_velocity_amt" };
	static const Identifier exp_089_velocity_dest   { "exp_089_velocity_dest" };
	static const Identifier exp_090_pedal_amt       { "exp_090_pedal_amt" };
	static const Identifier exp_091_pedal_dest      { "exp_091_pedal_dest" };
	static const Identifier exp_092_push_it_pitch   { "exp_092_push_it_pitch" };
	static const Identifier exp_093_push_it_velo    { "exp_093_push_it_velo" };
	static const Identifier exp_094_push_it_mode    { "exp_094_push_it_mode" };
	static const Identifier exp_095_clock_tempo     { "exp_095_clock_tempo" };
	static const Identifier exp_096_clock_div       { "exp_096_clock_div" };
	static const Identifier exp_097_arp_mode        { "exp_097_arp_mode" };
	static const Identifier exp_098_arpeg_on_off    { "exp_098_arpeg_on_off" };
	static const Identifier exp_099_seq_trig_mode   { "exp_099_seq_trig_mode" };
	static const Identifier exp_100_seq_on_off      { "exp_100_seq_on_off" };

	// exposed parameter properties
	static const Identifier exp_p_byte_index{ "exp_p_byte_index" };
	static const Identifier exp_p_choice_menu_type{ "exp_p_choice_menu_type" };
	static const Identifier exp_p_nrpn{ "exp_p_nrpn" };
	static const Identifier exp_p_packed_bits_byte_index{ "exp_p_packed_bits_byte_index" };
	static const Identifier exp_p_packed_bits_mask{ "exp_p_packed_bits_mask" };
	static const Identifier exp_p_red_toggle_center_x{ "exp_p_red_toggle_center_x" };
	static const Identifier exp_p_red_toggle_center_y{ "exp_p_red_toggle_center_y" };

	static const Identifier knob_osc_shape{ "knob_osc_shape" };
	static const Identifier knob_seq_step{ "knob_seq_step" };
	static const Identifier knob_seq_step_track_1{ "knob_seq_step_track_1" };

	static const Identifier label_osc_shape{ "label_osc_shape" };
	static const Identifier label_seq_step{ "label_seq_step" };
}