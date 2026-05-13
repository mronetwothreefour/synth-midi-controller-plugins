#pragma once

#include <JuceHeader.h>

#include "C_00-B_ID.h"

namespace ID
{

	static const Identifier ep_000_osc_1_pitch     { "ep_000_osc_1_pitch" };
	static const Identifier ep_001_osc_1_fine_tune { "ep_001_osc_1_fine_tune" };
	static const Identifier ep_002_osc_1_shape     { "ep_002_osc_1_shape" };
	static const Identifier ep_003_osc_1_glide     { "ep_003_osc_1_glide" };
	static const Identifier ep_004_osc_1_key_track { "ep_004_osc_1_key_track" };
	static const Identifier ep_005_osc_1_sub_level { "ep_005_osc_1_sub_level" };
	static const Identifier ep_006_osc_2_pitch     { "ep_006_osc_2_pitch" };
	static const Identifier ep_007_osc_2_fine_tune  { "ep_007_osc_2_fine_tune" };
	static const Identifier ep_008_osc_2_shape     { "ep_008_osc_2_shape" };
	static const Identifier ep_009_osc_2_glide     { "ep_009_osc_2_glide" };
	static const Identifier ep_010_osc_2_key_track { "ep_010_osc_2_key_track" };
	static const Identifier ep_011_osc_2_sub_level { "ep_011_osc_2_sub_level" };
	static const Identifier ep_012_osc_sync        { "ep_012_osc_sync" };
	static const Identifier ep_013_glide_mode      { "ep_013_glide_mode" };
	static const Identifier ep_014_osc_slop        { "ep_014_osc_slop" };
	static const Identifier ep_015_bend_range      { "ep_015_bend_range" };
	static const Identifier ep_016_note_priority   { "ep_016_note_priority" };
	static const Identifier ep_017_osc_mix         { "ep_017_osc_mix" };
	static const Identifier ep_018_noise_level     { "ep_018_noise_level" };
	static const Identifier ep_019_ext_in_level    { "ep_019_ext_in_level" };
	static const Identifier ep_020_lpf_freq        { "ep_020_lpf_freq" };
	static const Identifier ep_021_lpf_reso        { "ep_021_lpf_reso" };
	static const Identifier ep_022_lpf_key_amt     { "ep_022_lpf_key_amt" };
	static const Identifier ep_023_lpf_fm_amt      { "ep_023_lpf_fm_amt" };
	static const Identifier ep_024_lpf_type        { "ep_024_lpf_type" };
	static const Identifier ep_025_lpf_env_amt     { "ep_025_lpf_env_amt" };
	static const Identifier ep_026_lpf_vel_amt     { "ep_026_lpf_vel_amt" };
	static const Identifier ep_027_lpf_delay       { "ep_027_lpf_delay" };
	static const Identifier ep_028_lpf_attack      { "ep_028_lpf_attack" };
	static const Identifier ep_029_lpf_decay       { "ep_029_lpf_decay" };
	static const Identifier ep_030_lpf_sustain     { "ep_030_lpf_sustain" };
	static const Identifier ep_031_lpf_release     { "ep_031_LPF_release" };
	static const Identifier ep_032_vca_level       { "ep_032_vca_level" };
	static const Identifier ep_033_vca_env_amt     { "ep_033_vca_env_amt" };
	static const Identifier ep_034_vca_vel_amt     { "ep_034_vca_vel_amt" };
	static const Identifier ep_035_vca_delay       { "ep_035_vca_delay" };
	static const Identifier ep_036_vca_attack      { "ep_036_vca_attack" };
	static const Identifier ep_037_vca_decay       { "ep_037_vca_decay" };
	static const Identifier ep_038_vca_sustain     { "ep_038_vca_sustain" };
	static const Identifier ep_039_vca_release     { "ep_039_vca_release" };
	static const Identifier ep_040_voice_volume    { "ep_040_voice_volume" };
	static const Identifier ep_061_env_3_dest      { "ep_061_env_3_dest" };
	static const Identifier ep_062_env_3_amount    { "ep_062_env_3_amount" };
	static const Identifier ep_063_env_3_vel_amt   { "ep_063_env_3_vel_amt" };
	static const Identifier ep_064_env_3_delay     { "ep_064_env_3_delay" };
	static const Identifier ep_065_env_3_attack    { "ep_065_env_3_attack" };
	static const Identifier ep_066_env_3_decay     { "ep_066_env_3_decay" };
	static const Identifier ep_067_env_3_sustain   { "ep_067_env_3_sustain" };
	static const Identifier ep_068_env_3_release   { "ep_068_env_3_release" };
	static const Identifier ep_069_env_3_repeat    { "ep_069_env_3_repeat" };
	static const Identifier ep_082_mod_wheel_amt   { "ep_082_mod_wheel_amt" };
	static const Identifier ep_083_mod_wheel_dest  { "ep_083_mod_wheel_dest" };
	static const Identifier ep_084_press_amt       { "ep_084_press_amt" };
	static const Identifier ep_085_press_dest      { "ep_085_press_dest" };
	static const Identifier ep_086_breath_amt      { "ep_086_breath_amt" };
	static const Identifier ep_087_breath_dest     { "ep_087_breath_dest" };
	static const Identifier ep_088_velocity_amt    { "ep_088_velocity_amt" };
	static const Identifier ep_089_velocity_dest   { "ep_089_velocity_dest" };
	static const Identifier ep_090_pedal_amt       { "ep_090_pedal_amt" };
	static const Identifier ep_091_pedal_dest      { "ep_091_pedal_dest" };
	static const Identifier ep_092_push_it_pitch   { "ep_092_push_it_pitch" };
	static const Identifier ep_093_push_it_velo    { "ep_093_push_it_velo" };
	static const Identifier ep_094_push_it_mode    { "ep_094_push_it_mode" };
	static const Identifier ep_095_clock_tempo     { "ep_095_clock_tempo" };
	static const Identifier ep_096_clock_div       { "ep_096_clock_div" };
	static const Identifier ep_097_arpeg_mode      { "ep_097_arpeg_mode" };
	static const Identifier ep_098_arpeg_on_off    { "ep_098_arpeg_on_off" };
	static const Identifier ep_099_seq_trig_mode   { "ep_099_seq_trig_mode" };
	static const Identifier ep_100_seq_on_off      { "ep_100_seq_on_off" };

	// exposed parameter properties
	static const Identifier ep_p_byte_index{ "ep_p_byte_index" };
	static const Identifier ep_p_choice_menu_type{ "ep_p_choice_menu_type" };
	static const Identifier ep_p_knob_display_type{ "ep_p_knob_display_type" };
	static const Identifier ep_p_nrpn{ "ep_p_nrpn" };
	static const Identifier ep_p_packed_bits_byte_index{ "ep_p_packed_bits_byte_index" };
	static const Identifier ep_p_packed_bits_mask{ "ep_p_packed_bits_mask" };
	static const Identifier ep_p_red_toggle_center_x{ "ep_p_red_toggle_center_x" };
	static const Identifier ep_p_red_toggle_center_y{ "ep_p_red_toggle_center_y" };
}