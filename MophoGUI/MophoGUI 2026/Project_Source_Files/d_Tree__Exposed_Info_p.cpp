#include "d_Tree__Exposed_Info_p.h"

#include "d_Tip__Exposed_p.h"
#include "c_VOICE_p.h"

using namespace EXP;
using namespace XYWH;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Tree_Exposed_Info_Base{ EXP::exp_param_count }
{
	const bool curt{ true };

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		auto center_y = osc == 1 ? osc_row_1_y : osc_row_2_y;
		String n{ osc };
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_000_osc_1_pitch : ID::exp_006_osc_2_pitch,
				"Oscillator " + n + " Pitch", Ctrl_Type::knob_pitch,
				Knob_Display_Type::osc_pitch, osc == 1 ? 0 : 5,
				choice_count_osc_pitch, 24, ctrl_col_1_x, center_y, knob_diameter, knob_diameter,
				Tip_Exposed::osc_pitch(osc),
				Build_Tree::osc_pitch(EXP::choice_count_osc_pitch, curt),
				Build_Tree::osc_pitch(EXP::choice_count_osc_pitch)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_001_osc_1_fine_tune : ID::exp_007_osc_2_fine_tune,
				"Oscillator " + n + " Fine Tune", Ctrl_Type::knob,
				Knob_Display_Type::osc_fine, osc == 1 ? 1 : 6,
				choice_count_osc_fine, osc == 1 ? 49 : 51, ctrl_col_2_x, center_y, 
				knob_diameter, knob_diameter, Tip_Exposed::osc_fine(osc),
				Build_Tree::choice_names_osc_fine(curt), Build_Tree::choice_names_osc_fine()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_002_osc_1_shape : ID::exp_008_osc_2_shape,
				"Oscillator " + n + " Wave Shape", Ctrl_Type::knob_osc_shape,
				Knob_Display_Type::osc_shape, osc == 1 ? 2 : 7,
				choice_count_osc_shape, 1, ctrl_col_3_x, center_y, knob_diameter, knob_diameter,
				Tip_Exposed::osc_shape(osc),
				Build_Tree::choice_names_osc_shape(curt),
				Build_Tree::choice_names_osc_shape()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_003_osc_1_glide : ID::exp_009_osc_2_glide,
				"Oscillator " + n + " Glide Rate", Ctrl_Type::knob,
				Knob_Display_Type::unsigned_7_bit, osc == 1 ? 3 : 8,
				128, 0, ctrl_col_4_x, center_y, knob_diameter, knob_diameter,
				Tip_Exposed::osc_fine(osc),
				Build_Tree::unsigned_int(128, curt),
				Build_Tree::unsigned_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_004_osc_1_key_track : ID::exp_010_osc_2_key_track,
				"Oscillator " + n + " Keyboard Track On/Off", Ctrl_Type::toggle,
				Knob_Display_Type::none, osc == 1 ? 4 : 9, 2, 1, ctrl_col_6_x, center_y + 11, 32, 36,
				Tip_Exposed::osc_key_track(osc), Build_Tree::off_on(curt),
				Build_Tree::off_on(), ctrl_col_6_x, center_y
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_005_osc_1_sub_level : ID::exp_011_osc_2_sub_level,
				"Sub-Oscillator " + n + " Level", Ctrl_Type::knob,
				Knob_Display_Type::unsigned_7_bit, osc == 1 ? 114 : 115, 128, 0, ctrl_col_5_x,
				center_y, knob_diameter, knob_diameter, Tip_Exposed::osc_sub_level(osc), 
				Build_Tree::unsigned_int(128, curt), 
				Build_Tree::unsigned_int(128)
			),
			-1, nullptr);
	} 

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_012_osc_sync, "Hard Oscillator Sync On / Off", Ctrl_Type::toggle,
			Knob_Display_Type::none, 10, 2, 0, 242, 22, 76, toggle_diameter,
			Tip_Exposed::osc_sync(), Build_Tree::off_on(curt),
			Build_Tree::off_on(), 273, 22
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_013_glide_mode, "Glide Mode", Ctrl_Type::cbox,
			Knob_Display_Type::none, 11, 4, 0, ctrl_col_10_x, 78, osc_cbox_w, cbox_h,
			Tip_Exposed::glide_mode(), Build_Tree::choice_names_glide_mode(curt),
			Build_Tree::choice_names_glide_mode()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_014_osc_slop, "Oscillator Slop", Ctrl_Type::knob,
			Knob_Display_Type::osc_slop, 12, 6, 2, ctrl_col_7_x, osc_row_1_y, 
			knob_diameter, knob_diameter, Tip_Exposed::osc_slop(),
			Build_Tree::unsigned_int(6, curt), Build_Tree::unsigned_int(6)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_015_bend_range, "Pitch Bend Range", Ctrl_Type::knob,
			Knob_Display_Type::pitch_bend, 93, choice_count_bend_range, 4, ctrl_col_9_x, osc_row_1_y,
			knob_diameter, knob_diameter, Tip_Exposed::bend_range(),
			Build_Tree::choice_names_bend_range(curt), Build_Tree::choice_names_bend_range()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_016_note_priority, "Note Priority (Key Assign)", Ctrl_Type::cbox,
			Knob_Display_Type::none, 96, 6, 4, ctrl_col_10_x, 38,
			osc_cbox_w, cbox_h, Tip_Exposed::note_priority(),
			Build_Tree::choice_names_note_priority(curt), Build_Tree::choice_names_note_priority()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_017_osc_mix, "Oscillator 1 & 2 Mix", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 13, 128, 64, ctrl_col_8_x, osc_row_1_y,
			knob_diameter, knob_diameter, Tip_Exposed::osc_mix(),
			Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_018_noise_level, "Noise Level", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 14, 128, 0, ctrl_col_7_x, osc_row_2_y,
			knob_diameter, knob_diameter, Tip_Exposed::noise_level(),
			Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_019_ext_in_level, "External Audio Input Level", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 116, 128, 0, ctrl_col_8_x, osc_row_2_y,
			knob_diameter, knob_diameter, Tip_Exposed::ext_in_level(),
			Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end osc section

	// *************************************************************** lpf section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_020_lpf_freq, "LPF Cutoff Frequency", Ctrl_Type::knob_pitch, Knob_Display_Type::lpf_freq,
			15, choice_count_lpf_freq, 148, ctrl_col_1_x, lpf_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::lpf_freq(), Build_Tree::choice_names_lpf_freq(curt),
			Build_Tree::choice_names_lpf_freq()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_021_lpf_reso, "LPF Resonance", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			16, 128, 0, ctrl_col_2_x, lpf_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::lpf_reso(), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_022_lpf_key_amt, "LPF Keyboard Amount", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			17, 128, 0, ctrl_col_3_x, lpf_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::lpf_key_amt(), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_023_lpf_fm_amt, "LPF FM (By Oscillator 1)", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			18, 128, 0, ctrl_col_3_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::lpf_fm_amt(), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_024_lpf_type, "LPF Type", Ctrl_Type::toggle, Knob_Display_Type::none,
			19, 2, 1, ctrl_col_2_x, lpf_row_1_y, 34, 26, Tip_Exposed::lpf_type(),
			Build_Tree::choice_names_lpf_type(curt), Build_Tree::choice_names_lpf_type(),
			ctrl_col_2_x, 161
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_025_lpf_env_amt, "LPF Envelope Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			20, 255, 127, ctrl_col_1_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::lpf_env_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
			Build_Tree::choice_names_signed_8_bit_int()
		),
		-1, nullptr);

	String env_name{ "the LPF envelope" };

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_026_lpf_velo_amt, "LPF Envelope Velocity Amount", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 21, 128, 0, ctrl_col_2_x, lpf_row_3_y,
			knob_diameter, knob_diameter, Tip_Exposed::env_velo_amt(env_name),
			Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_027_lpf_delay, "LPF Envelope Delay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			22, 128, 0, ctrl_col_4_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_delay(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_028_lpf_attack, "LPF Envelope Attack", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			23, 128, 0, ctrl_col_5_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_attack(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_029_lpf_decay, "LPF Envelope Decay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			24, 128, 0, ctrl_col_6_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_decay(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_030_lpf_sustain, "LPF Envelope Sustain", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			25, 128, 0, ctrl_col_7_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_sustain(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_031_lpf_release, "LPF Envelope Release", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			26, 128, 0, ctrl_col_8_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_release(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end lpf section

	// *************************************************************** vca section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_032_vca_level, "VCA Baseline Level", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			27, 128, 0, ctrl_col_1_x, vca_row_1_y, knob_diameter, knob_diameter,
			Tip_Exposed::vca_level(), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_033_vca_env_amt, "VCA Envelope Amount", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			30, 255, 127, ctrl_col_2_x, vca_row_1_y, knob_diameter, knob_diameter,
			Tip_Exposed::vca_env_amt(), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	env_name = "the VCA envelope";

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_034_vca_vel_amt, "VCA Envelope Velocity Amount", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 31, 128, 0, ctrl_col_3_x, vca_row_1_y,
			knob_diameter, knob_diameter, Tip_Exposed::env_velo_amt(env_name),
			Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_035_vca_delay, "VCA Envelope Delay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			32, 128, 0, ctrl_col_4_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_delay(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_036_vca_attack, "VCA Envelope Attack", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			33, 128, 0, ctrl_col_5_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_attack(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_037_vca_decay, "VCA Envelope Decay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			34, 128, 0, ctrl_col_6_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_decay(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_038_vca_sustain, "VCA Envelope Sustain", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			35, 128, 64, ctrl_col_7_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_sustain(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_039_vca_release, "VCA Envelope Release", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			36, 128, 64, ctrl_col_8_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_release(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_040_voice_volume, "Program Volume", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			29, 128, 120, ctrl_col_2_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::voice_volume(), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end vca section

	// *************************************************************** lfo section
		auto mod_dest_param_description{ "Selects the target parameter for modulation" };

	for (int lfo = 0; lfo < 4; ++lfo) {
		int param_offset{ lfo * 5 };
		String n{ lfo + 1 };
		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 41 + param_offset } + "_lfo_" + n + "_freq",
				"LFO " + n + " Frequency", Ctrl_Type::knob, Knob_Display_Type::lfo_freq,
				37 + param_offset, 167, 80, 416 + lfo * lfo_block_spacing, lfo_row_1_y,
				knob_diameter, knob_diameter, Tip_Exposed::lfo_freq(lfo + 1),
				Build_Tree::choice_names_lfo_freq(curt), Build_Tree::choice_names_lfo_freq()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 42 + param_offset } + "_lfo_" + n + "_shape",
				"LFO " + n + " Wave Shape", Ctrl_Type::cbox, Knob_Display_Type::none,
				38 + param_offset, 5, 1, lfo_1_cbox_x + lfo * lfo_block_spacing, lfo_row_2_y,
				lfo_cbox_w, cbox_h, Tip_Exposed::lfo_shape(lfo + 1),
				Build_Tree::choice_names_lfo_shape(curt), Build_Tree::choice_names_lfo_shape()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 43 + param_offset } + "_lfo_" + n + "_amt",
				"LFO " + n + " Amount", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
				39 + param_offset, 128, 0, 461 + lfo * lfo_block_spacing, lfo_row_1_y,
				knob_diameter, knob_diameter, Tip_Exposed::lfo_amt(lfo + 1),
				Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 44 + param_offset } + "_lfo_" + n + "_dest",
				"LFO " + n + " Modulation Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
				40 + param_offset, EXP::choice_count_mod_dest, 0, lfo_1_cbox_x + lfo * lfo_block_spacing, lfo_row_3_y,
				lfo_cbox_w, cbox_h, mod_dest_param_description + String{ " by LFO " } + n + ".",
				Build_Tree::choice_names_mod_dest(curt), Build_Tree::choice_names_mod_dest()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 45 + param_offset } + "_lfo_" + n + "_key_sync",
				"LFO " + n + " Key Sync On / Off", Ctrl_Type::toggle, Knob_Display_Type::none,
				41 + param_offset, 2, 0, 507 + lfo * lfo_block_spacing, 526,
				26, 36, mod_dest_param_description + String{ " by LFO " } + n + ".",
				Build_Tree::choice_names_mod_dest(curt), Build_Tree::choice_names_mod_dest(),
				507 + lfo * lfo_block_spacing, lfo_row_1_y
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end lfo section

	// *************************************************************** env 3 section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_061_env_3_dest, "Envelope 3 Modulation Destination", Ctrl_Type::cbox,
			Knob_Display_Type::none, 57, EXP::choice_count_mod_dest, 0, ctrl_col_2_x, env_3_row_2_y,
			126, cbox_h, mod_dest_param_description + String{ " by envelope 3." },
			Build_Tree::choice_names_mod_dest(curt), Build_Tree::choice_names_mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_062_env_3_amount, "Envelope 3 Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			58, 255, 127, ctrl_col_2_x, env_3_row_1_y, knob_diameter, knob_diameter, 
			Tip_Exposed::env_3_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
			Build_Tree::choice_names_signed_8_bit_int()
		),
		-1, nullptr);

	env_name = "envelope 3";

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_063_env_3_velo_amt, "Envelope 3 Velocity Amount", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 59, 128, 0, ctrl_col_3_x, env_3_row_1_y,
			knob_diameter, knob_diameter, Tip_Exposed::env_velo_amt(env_name),
			Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_064_env_3_delay, "Envelope 3 Delay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			60, 128, 0, ctrl_col_4_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_delay(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_065_env_3_attack, "Envelope 3 Attack", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			61, 128, 0, ctrl_col_5_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_attack(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_066_env_3_decay, "Envelope 3 Decay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			62, 128, 0, ctrl_col_6_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_decay(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_067_env_3_sustain, "Envelope 3 Sustain", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			63, 128, 0, ctrl_col_7_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_sustain(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_068_env_3_release, "Envelope 3 Release", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			64, 128, 0, ctrl_col_8_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::env_release(env_name), Build_Tree::unsigned_int(128, curt),
			Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_069_env_3_repeat, "Envelope 3 Repeat", Ctrl_Type::toggle, Knob_Display_Type::none,
			98, 2, 0, ctrl_col_1_x, 537, 34, 26, Tip_Exposed::env_3_repeat(),
			Build_Tree::off_on(curt), Build_Tree::off_on(),
			ctrl_col_1_x, env_3_row_1_y
		),
		-1, nullptr);
	// ---------------------------------------------------------- end env 3 section
	
	// *************************************************************** mod section
	for (int mod = 0; mod < 4; ++mod) {
		String n{ mod + 1 };
		int offset{ mod * 3 };
		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 70 + offset } + "_mod_" + n + "_src", "Modulator " + n + " Source",
				Ctrl_Type::cbox, Knob_Display_Type::none, 65 + offset, EXP::choice_count_mod_src, 0,
				mod_col_1_x, 184 + mod * mod_block_spacing, mod_cbox_w, cbox_h, 
				"Selects the modulation source.", Build_Tree::choice_names_mod_src(curt),
				Build_Tree::choice_names_mod_src()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 71 + offset } + "_mod_" + n + "_amt", "Modulator " + n + " Amount",
				Ctrl_Type::knob, Knob_Display_Type::signed_8_bit, 66 + offset, 255, 127,
				mod_col_2_x, 201 + mod * mod_block_spacing, knob_diameter, knob_diameter,
				Tip_Exposed::mod_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
				Build_Tree::choice_names_signed_8_bit_int()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_0" + String{ 72 + offset } + "_mod_" + n + "_dest", "Modulator " + n + " Destination",
				Ctrl_Type::cbox, Knob_Display_Type::none, 67 + offset, EXP::choice_count_mod_dest, 0,
				mod_col_1_x, 218 + mod * mod_block_spacing, mod_cbox_w, cbox_h,
				"Selects the target parameter for modulation.", Build_Tree::choice_names_mod_dest(curt),
				Build_Tree::choice_names_mod_dest()
			),
			-1, nullptr);
	}
	// ---------------------------------------------------------- end mod section

	// *************************************************************** midi cc section
	auto cc_dest_description = mod_dest_param_description + String{ "." };
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_082_mod_wheel_amt, "Modulation Wheel Amount", Ctrl_Type::knob,
			Knob_Display_Type::signed_8_bit, 81, 255, 127, cc_col_2_x, cc_row_1_y, knob_diameter, knob_diameter,
			Tip_Exposed::midi_mod_wheel_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
			Build_Tree::choice_names_signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_083_mod_wheel_dest, "Modulation Wheel Destination", Ctrl_Type::cbox, 
			Knob_Display_Type::none, 82, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_1_y,
			cc_cbox_w, cbox_h, cc_dest_description, Build_Tree::choice_names_mod_dest(curt),
			Build_Tree::choice_names_mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_084_press_amt, "Pressure (Aftertouch) Amount", Ctrl_Type::knob,
			Knob_Display_Type::signed_8_bit, 83, 255, 127, cc_col_2_x, cc_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::midi_mod_wheel_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
			Build_Tree::choice_names_signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_085_press_dest, "Pressure (Aftertouch) Destination", Ctrl_Type::cbox, 
			Knob_Display_Type::none, 84, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_2_y,
			cc_cbox_w, cbox_h, cc_dest_description, Build_Tree::choice_names_mod_dest(curt),
			Build_Tree::choice_names_mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_086_breath_amt, "Breath Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			85, 255, 127, cc_col_2_x, cc_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::midi_breath_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
			Build_Tree::choice_names_signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_087_breath_dest, "Breath Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
			86, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_3_y,
			cc_cbox_w, cbox_h, cc_dest_description, Build_Tree::choice_names_mod_dest(curt),
			Build_Tree::choice_names_mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_088_velocity_amt, "Note Velocity Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			87, 255, 127, cc_col_2_x, cc_row_4_y, knob_diameter, knob_diameter,
			Tip_Exposed::midi_velocity_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
			Build_Tree::choice_names_signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_089_velocity_dest, "Note Velocity Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
			88, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_4_y,
			cc_cbox_w, cbox_h, cc_dest_description, Build_Tree::choice_names_mod_dest(curt),
			Build_Tree::choice_names_mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_090_pedal_amt, "Foot Pedal Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			89, 255, 127, cc_col_2_x, cc_row_5_y, knob_diameter, knob_diameter,
			Tip_Exposed::midi_pedal_amt(), Build_Tree::choice_names_signed_8_bit_int(curt),
			Build_Tree::choice_names_signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_091_pedal_dest, "Foot Pedal Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
			90, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_5_y,
			cc_cbox_w, cbox_h, cc_dest_description, Build_Tree::choice_names_mod_dest(curt),
			Build_Tree::choice_names_mod_dest()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end midi ctrl section

	// *************************************************************** push it section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_092_push_it_pitch, "Push It! Switch Pitch", Ctrl_Type::knob_pitch,
			Knob_Display_Type::osc_pitch, 111, choice_count_osc_pitch, 60, 1191, push_it_knob_row_y,
			knob_diameter, knob_diameter, Tip_Exposed::push_it_pitch(),
			Build_Tree::osc_pitch(EXP::choice_count_osc_pitch, curt),
			Build_Tree::osc_pitch(EXP::choice_count_osc_pitch)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_093_push_it_velo, "Push It! Switch Velocity", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 112, 128, 0, 1239, push_it_knob_row_y,
			knob_diameter, knob_diameter, Tip_Exposed::push_it_velocity(),
			Build_Tree::unsigned_int(128, curt), Build_Tree::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_094_push_it_mode, "Push It! Switch Mode", Ctrl_Type::cbox, Knob_Display_Type::none,
			113, 3, 0, 1215, 577, 88, cbox_h, Tip_Exposed::push_it_mode(),
			Build_Tree::choice_names_push_it_mode(curt), Build_Tree::choice_names_push_it_mode()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end push it section

	// *************************************************************** clock & arp section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_095_clock_tempo, "Clock Tempo", Ctrl_Type::knob, Knob_Display_Type::tempo,
			91, choice_count_clock_tempo, 90, 1236, clock_and_seq_row_y,
			knob_diameter, knob_diameter, Tip_Exposed::clock_tempo(),
			Build_Tree::choice_names_clock_tempo(curt), Build_Tree::choice_names_clock_tempo()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_096_clock_div, "Clock Division", Ctrl_Type::cbox, Knob_Display_Type::none,
			92, 13, 2, 1139, clock_and_seq_row_y, 126, cbox_h, Tip_Exposed::clock_division(),
			Build_Tree::choice_names_clock_div(curt), Build_Tree::choice_names_clock_div()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_097_arp_mode, "Arpeggiator Mode", Ctrl_Type::cbox, Knob_Display_Type::none,
			97, 15, 0, ctrl_col_10_x, 118, 124, cbox_h, Tip_Exposed::arp_mode(),
			Build_Tree::choice_names_arp_mode(curt), Build_Tree::choice_names_arp_mode()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_098_arpeg_on_off, "Arpeggiator On / Off", Ctrl_Type::toggle, Knob_Display_Type::none,
			100, 2, 0, ctrl_col_9_x, 116, 20, 26, Tip_Exposed::arp_on_off(),
			Build_Tree::off_on(curt), Build_Tree::off_on(),
			ctrl_col_9_x, osc_row_2_y
		),
		-1, nullptr);
	// ---------------------------------------------------------- end clock & arp section

	// *************************************************************** seq section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_099_seq_trig_mode, "Sequencer Trigger Mode", Ctrl_Type::cbox, Knob_Display_Type::none,
			94, 6, 0, 998, clock_and_seq_row_y, 114, cbox_h, Tip_Exposed::seq_trig_mode(),
			Build_Tree::choice_names_seq_trig_mode(curt), Build_Tree::choice_names_seq_trig_mode()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_100_seq_on_off, "Sequencer On / Off", Ctrl_Type::toggle, Knob_Display_Type::none,
			101, 2, 0, 863, clock_and_seq_row_y, 102, toggle_diameter, Tip_Exposed::seq_on_off(),
			Build_Tree::off_on(curt), Build_Tree::off_on(),
			819, clock_and_seq_row_y
		),
		-1, nullptr);

	for (int track = 1; track < 5; ++track) {
		String n{ track };
		auto even_track = track % 2 == 0;
		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_10" + n + "_seq_track_" + n + "_dest", "Sequencer Track " + n + " Destination",
				Ctrl_Type::cbox, Knob_Display_Type::none, 76 + track, 
				EXP::choice_count_mod_dest + even_track ? 1 : 0, track < 3 ? track : track == 3 ? 9 : 0,
				seq_track_dest_cbox_x, 169 + ((track - 1) * seq_track_block_spacing),
				seq_track_dest_cbox_w, cbox_h, Tip_Exposed::seq_track_dest(n),
				even_track ? Build_Tree::choice_names_seq_track_2_4_dest(track == 2, curt) : 
							 Build_Tree::choice_names_mod_dest(curt),
				even_track ? Build_Tree::choice_names_seq_track_2_4_dest(track == 2) : 
							 Build_Tree::choice_names_mod_dest()
			),
			-1, nullptr);
	}
	// ---------------------------------------------------------- end seq section

	// *************************************************************** knob assign section
	for (int knob = 1; knob < 5; ++knob) {
		String n{ knob };
		tree.addChild(
			Build_Tree::exposed_parameter(
				"ep_10" + String{ 4 + knob } + "_assign_knob_" + n, "Parameter Assigned To Knob " + n,
				Ctrl_Type::cbox, Knob_Display_Type::none, 104 + knob, 169,
				knob == 1 ? 5 : knob == 2 ? 11 : knob == 3 ? 43 : 23, knob_assign_cbox_x,
				521 + ((knob - 1) * knob_assign_spacing), knob_assign_cbox_w, cbox_h,
				Tip_Exposed::knob_assign(n), Build_Tree::choice_names_knob_assign(curt),
				Build_Tree::choice_names_knob_assign()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end knob assign section

	// *************************************************************** seq step section
	for (int track = 0; track < 4; ++track) {
		String t{ track + 1 };
		for (int step = 0; step < 16; ++step) {
			String s{ step + 1 };
			String id{ "ep_" + String{ EXP::first_seq_step_param_index + track * 16 + step } };
			id += "_seq_track_" + t + "_step_" + s;
			tree.addChild(
				Build_Tree::exposed_parameter(
					id, "Sequencer Track " + t + " Step " + s, Ctrl_Type::seq_step,
					Knob_Display_Type::none, 120 + track * 16 + step, track == 0 ? 128 : 127, 0,
					825 + step * (seq_step_w + step_and_char_gap), 196 + track * seq_track_block_spacing,
					seq_step_w, seq_step_h, Tip_Exposed::seq_track_step(t, s),
					Build_Tree::choice_names_seq_track_step(curt), Build_Tree::choice_names_seq_track_step()
				),
				-1, nullptr);
		}
	} // ---------------------------------------------------------- end seq step section

	// *************************************************************** voice name char section
	String init_voice_name{ "Basic Program   " };
	for (int character = 0; character < VOICE::name_char_count; ++character) {
		String c{ character + 1 };
		String id{ "ep_" + String{ EXP::first_voice_name_char_param_index + character } };
		id += "_voice_name_char_" + c;
		tree.addChild(
			Build_Tree::exposed_parameter(
				id, "Program Name Character " + c, Ctrl_Type::voice_name_char, Knob_Display_Type::none,
				184 + character, choice_count_voice_name_char, (int)init_voice_name[character],
				596 + character * (voice_name_char_w + step_and_char_gap), voice_name_char_y,
				voice_name_char_w, voice_name_char_h, Tip_Exposed::voice_name_char(c),
				Build_Tree::choice_names_voice_name_char(curt), Build_Tree::choice_names_voice_name_char()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end voice name char section
}

const Identifier Exposed_Parameter_Info::id_for(Track track, Step step) const {
	if (step != Step::all) {
		auto param_num{ 
			EXP::param_index_seq_track_1_step_1 + ((int)track - 1) * 16 + ((int)step - 1) 
		};
		auto exp_param_id{ "ep_" + String{ param_num } };
		exp_param_id << "_Seq_Track_" << String{ (int)track };
		exp_param_id << "_Step_" << String{ (int)step };
		return exp_param_id;
	}
	return {};
}

const Ctrl_Type Exposed_Parameter_Info::ctrl_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::exp_p_ctrl_type] };
	return Ctrl_Type::error;
}

const Knob_Display_Type Exposed_Parameter_Info::knob_display_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Knob_Display_Type{ (int)param(i)[ID::exp_p_knob_display_type] };
	return Knob_Display_Type::error;
}

const uint8 Exposed_Parameter_Info::nrpn_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::exp_p_nrpn];
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::param_index_for(const uint8 nrpn) const {
	for (uint8 i = 0; i < exp_param_count; ++i) {
		if (nrpn_for(i) == nrpn)
			return i;
	}
	return (uint8)255;
}

Point<int> Exposed_Parameter_Info::red_toggle_center_for(uint8 i) const {
	if (i < exp_param_count && ctrl_type_for(i) == Ctrl_Type::toggle) {
		auto x = (int)param(i)[ID::exp_p_red_toggle_center_x];
		auto y = (int)param(i)[ID::exp_p_red_toggle_center_y];
		return Point<int>{ x, y };
	}
	return {};
}

const uint16 Exposed_Parameter_Info::packed_bits_byte_index_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint16)(int)param(i)[ID::exp_p_packed_bits_byte_index];
	return (uint16)65535;
}

const uint8 Exposed_Parameter_Info::packed_bits_mask_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::exp_p_packed_bits_mask];
	return (uint8)255;
}

const uint16 Exposed_Parameter_Info::byte_index_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint16)(int)param(i)[ID::exp_p_byte_index];
	return (uint16)65535;
}

const Track Exposed_Parameter_Info::seq_track_for(const uint8 i) const {
	if (i < exp_param_count) {
		auto first_track_index = EXP::param_index_seq_track_1_step_1;
		if (i >= first_track_index)
			return Track{ ((i - first_track_index) / 16) + 1 };
		return Track::none;
	}
	return Track::error;
}

const Step Exposed_Parameter_Info::seq_track_step_for(const uint8 i) const {
	if (i < exp_param_count) {
		auto first_track_index = EXP::param_index_seq_track_1_step_1;
		if (i >= first_track_index)
			return Step{ ((i - first_track_index) % 16) + 1 };
		return Step::none;
	}
	return Step::error;
}

const Choice_Menu_Type Exposed_Parameter_Info::choice_menu_type_for(const uint8 i) const {
	if (i < exp_param_count)
		return Choice_Menu_Type{ (int)param(i)[ID::exp_p_choice_menu_type] };
	return Choice_Menu_Type::error;
}
