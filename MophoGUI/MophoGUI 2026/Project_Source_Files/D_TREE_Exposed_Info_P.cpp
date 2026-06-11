#include "D_TREE_Exposed_Info_P.h"

#include "c_VOICE_p.h"
#include "D_TIP_Exposed_P.h"

using namespace EXP;
using namespace XYWH;

using Choices_Exp = Subtree_Choices_Exp_P;
using Tip_Exp = Tip_Exposed_P;

Tree_Exposed_Info_P::Tree_Exposed_Info_P() :
	Tree_Exposed_Info_B{ EXP::exp_param_count }
{
	const bool curt{ true };

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		auto center_y = osc == 1 ? osc_row_1_y : osc_row_2_y;
		String n{ osc };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_000_osc_1_pitch : ID::exp_006_osc_2_pitch,
				"Oscillator " + n + " Pitch", Ctrl_Type::knob_pitch, Knob_Display_Type::osc_pitch,
				osc == 1 ? 0 : 5, choice_count_osc_pitch, 24, ctrl_col_1_x, center_y,
				knob_diameter, knob_diameter, Tip_Exp::osc_pitch(osc),
				Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch, curt),
				Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_001_osc_1_fine_tune : ID::exp_007_osc_2_fine_tune,
				"Oscillator " + n + " Fine Tune", Ctrl_Type::knob,
				Knob_Display_Type::osc_fine, osc == 1 ? 1 : 6,
				choice_count_osc_fine, osc == 1 ? 49 : 51, ctrl_col_2_x, center_y, 
				knob_diameter, knob_diameter, Tip_Exp::osc_fine(osc),
				Choices_Exp::osc_fine(curt), Choices_Exp::osc_fine()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_002_osc_1_shape : ID::exp_008_osc_2_shape,
				"Oscillator " + n + " Wave Shape", Ctrl_Type::knob_osc_shape,
				Knob_Display_Type::osc_shape, osc == 1 ? 2 : 7, choice_count_osc_shape, 1,
				ctrl_col_3_x, center_y, knob_diameter, knob_diameter,
				Tip_Exp::osc_shape(osc), Choices_Exp::osc_shape(curt), Choices_Exp::osc_shape()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_003_osc_1_glide : ID::exp_009_osc_2_glide,
				"Oscillator " + n + " Glide Rate", Ctrl_Type::knob,
				Knob_Display_Type::unsigned_7_bit, osc == 1 ? 3 : 8, 128, 0,
				ctrl_col_4_x, center_y, knob_diameter, knob_diameter, Tip_Exp::osc_fine(osc),
				Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_004_osc_1_key_track : ID::exp_010_osc_2_key_track,
				"Oscillator " + n + " Keyboard Track On/Off", Ctrl_Type::toggle,
				Knob_Display_Type::none, osc == 1 ? 4 : 9, 2, 1, ctrl_col_6_x, center_y + 11, 32, 36,
				Tip_Exp::osc_key_track(osc), Choices_Exp::off_on(curt),
				Choices_Exp::off_on(), ctrl_col_6_x, center_y
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_005_osc_1_sub_level : ID::exp_011_osc_2_sub_level,
				"Sub-Oscillator " + n + " Level", Ctrl_Type::knob,
				Knob_Display_Type::unsigned_7_bit, osc == 1 ? 114 : 115, 128, 0, ctrl_col_5_x,
				center_y, knob_diameter, knob_diameter, Tip_Exp::osc_sub_level(osc), 
				Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
			),
			-1, nullptr);
	} 

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_012_osc_sync, "Hard Oscillator Sync On / Off", Ctrl_Type::toggle,
			Knob_Display_Type::none, 10, 2, 0, 242, 22, 76, toggle_diameter,
			Tip_Exp::osc_sync(), Choices_Exp::off_on(curt), Choices_Exp::off_on(), 273, 22
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_013_glide_mode, "Glide Mode", Ctrl_Type::cbox,
			Knob_Display_Type::none, 11, 4, 0, ctrl_col_10_x, 78, osc_cbox_w, cbox_h,
			Tip_Exp::glide_mode(), Choices_Exp::glide_mode(curt), Choices_Exp::glide_mode()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_014_osc_slop, "Oscillator Slop", Ctrl_Type::knob,
			Knob_Display_Type::osc_slop, 12, 6, 2, ctrl_col_7_x, osc_row_1_y, 
			knob_diameter, knob_diameter, Tip_Exp::osc_slop(),
			Choices_Exp::unsigned_int(6, curt), Choices_Exp::unsigned_int(6)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_015_bend_range, "Pitch Bend Range", Ctrl_Type::knob,
			Knob_Display_Type::bend_range, 93, choice_count_bend_range, 4, ctrl_col_9_x, osc_row_1_y,
			knob_diameter, knob_diameter, Tip_Exp::bend_range(),
			Choices_Exp::bend_range(curt), Choices_Exp::bend_range()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_016_note_priority, "Note Priority (Key Assign)", Ctrl_Type::cbox,
			Knob_Display_Type::none, 96, 6, 4, ctrl_col_10_x, 38,
			osc_cbox_w, cbox_h, Tip_Exp::note_priority(),
			Choices_Exp::note_priority(curt), Choices_Exp::note_priority()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_017_osc_mix, "Oscillator 1 & 2 Mix", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 13, 128, 64, ctrl_col_8_x, osc_row_1_y,
			knob_diameter, knob_diameter, Tip_Exp::osc_mix(),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_018_noise_level, "Noise Level", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 14, 128, 0, ctrl_col_7_x, osc_row_2_y,
			knob_diameter, knob_diameter, Tip_Exp::noise_level(),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_019_ext_in_level, "External Audio Input Level", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 116, 128, 0, ctrl_col_8_x, osc_row_2_y,
			knob_diameter, knob_diameter, Tip_Exp::ext_in_level(),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end osc section

	// *************************************************************** lpf section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_020_lpf_freq, "LPF Cutoff Frequency", Ctrl_Type::knob_pitch, Knob_Display_Type::lpf_freq,
			15, choice_count_lpf_freq, 148, ctrl_col_1_x, lpf_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::lpf_freq(), Choices_Exp::lpf_freq(curt), Choices_Exp::lpf_freq()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_021_lpf_reso, "LPF Resonance", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			16, 128, 0, ctrl_col_2_x, lpf_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::lpf_reso(), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_022_lpf_key_amt, "LPF Keyboard Amount", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			17, 128, 0, ctrl_col_3_x, lpf_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::lpf_key_amt(), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_023_lpf_fm_amt, "LPF FM (By Oscillator 1)", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			18, 128, 0, ctrl_col_3_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::lpf_fm_amt(), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_024_lpf_type, "LPF Type", Ctrl_Type::toggle, Knob_Display_Type::none,
			19, 2, 1, ctrl_col_2_x, lpf_row_1_y, 34, 26, Tip_Exp::lpf_type(),
			Choices_Exp::lpf_type(curt), Choices_Exp::lpf_type(), ctrl_col_2_x, 161
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_025_lpf_env_amt, "LPF Envelope Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			20, 255, 127, ctrl_col_1_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::lpf_env_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
		),
		-1, nullptr);

	String env_name{ "the LPF envelope" };

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_026_lpf_velo_amt, "LPF Envelope Velocity Amount", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 21, 128, 0, ctrl_col_2_x, lpf_row_3_y,
			knob_diameter, knob_diameter, Tip_Exp::env_velo_amt(env_name),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_027_lpf_delay, "LPF Envelope Delay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			22, 128, 0, ctrl_col_4_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_delay(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_028_lpf_attack, "LPF Envelope Attack", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			23, 128, 0, ctrl_col_5_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_attack(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_029_lpf_decay, "LPF Envelope Decay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			24, 128, 0, ctrl_col_6_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_decay(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_030_lpf_sustain, "LPF Envelope Sustain", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			25, 128, 0, ctrl_col_7_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_sustain(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_031_lpf_release, "LPF Envelope Release", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			26, 128, 0, ctrl_col_8_x, lpf_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_release(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end lpf section

	// *************************************************************** vca section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_032_vca_level, "VCA Baseline Level", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			27, 128, 0, ctrl_col_1_x, vca_row_1_y, knob_diameter, knob_diameter,
			Tip_Exp::vca_level(), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_033_vca_env_amt, "VCA Envelope Amount", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			30, 128, 127, ctrl_col_2_x, vca_row_1_y, knob_diameter, knob_diameter,
			Tip_Exp::vca_env_amt(), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	env_name = "the VCA envelope";

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_034_vca_vel_amt, "VCA Envelope Velocity Amount", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 31, 128, 0, ctrl_col_3_x, vca_row_1_y,
			knob_diameter, knob_diameter, Tip_Exp::env_velo_amt(env_name),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_035_vca_delay, "VCA Envelope Delay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			32, 128, 0, ctrl_col_4_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_delay(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_036_vca_attack, "VCA Envelope Attack", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			33, 128, 0, ctrl_col_5_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_attack(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_037_vca_decay, "VCA Envelope Decay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			34, 128, 0, ctrl_col_6_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_decay(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_038_vca_sustain, "VCA Envelope Sustain", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			35, 128, 64, ctrl_col_7_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_sustain(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_039_vca_release, "VCA Envelope Release", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			36, 128, 64, ctrl_col_8_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_release(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_040_voice_volume, "Program Volume", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			29, 128, 120, ctrl_col_2_x, vca_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::voice_volume(), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end vca section

	// *************************************************************** lfo section
		auto mod_dest_param_description{ "Selects the target parameter for modulation" };

	for (int lfo = 0; lfo < 4; ++lfo) {
		int param_offset{ lfo * 5 };
		String n{ lfo + 1 };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 41 + param_offset } + "_lfo_" + n + "_freq",
				"LFO " + n + " Frequency", Ctrl_Type::knob, Knob_Display_Type::lfo_freq,
				37 + param_offset, 167, 80, 416 + lfo * lfo_block_spacing, lfo_row_1_y,
				knob_diameter, knob_diameter, Tip_Exp::lfo_freq(lfo + 1),
				Choices_Exp::lfo_freq(curt), Choices_Exp::lfo_freq()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 42 + param_offset } + "_lfo_" + n + "_shape",
				"LFO " + n + " Wave Shape", Ctrl_Type::cbox, Knob_Display_Type::none,
				38 + param_offset, 5, 1, lfo_1_cbox_x + lfo * lfo_block_spacing, lfo_row_2_y,
				lfo_cbox_w, cbox_h, Tip_Exp::lfo_shape(lfo + 1),
				Choices_Exp::lfo_shape(curt), Choices_Exp::lfo_shape()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 43 + param_offset } + "_lfo_" + n + "_amt",
				"LFO " + n + " Amount", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
				39 + param_offset, 128, 0, 461 + lfo * lfo_block_spacing, lfo_row_1_y,
				knob_diameter, knob_diameter, Tip_Exp::lfo_amt(lfo + 1),
				Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 44 + param_offset } + "_lfo_" + n + "_dest",
				"LFO " + n + " Modulation Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
				40 + param_offset, EXP::choice_count_mod_dest, 0, lfo_1_cbox_x + lfo * lfo_block_spacing, lfo_row_3_y,
				lfo_cbox_w, cbox_h, mod_dest_param_description + String{ " by LFO " } + n + ".",
				Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 45 + param_offset } + "_lfo_" + n + "_key_sync",
				"LFO " + n + " Key Sync On / Off", Ctrl_Type::toggle, Knob_Display_Type::none,
				41 + param_offset, 2, 0, 507 + lfo * lfo_block_spacing, 526,
				26, 36, mod_dest_param_description + String{ " by LFO " } + n + ".",
				Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest(),
				507 + lfo * lfo_block_spacing, lfo_row_1_y
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end lfo section

	// *************************************************************** env 3 section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_061_env_3_dest, "Envelope 3 Modulation Destination", Ctrl_Type::cbox,
			Knob_Display_Type::none, 57, EXP::choice_count_mod_dest, 0, ctrl_col_2_x, env_3_row_2_y,
			126, cbox_h, mod_dest_param_description + String{ " by envelope 3." },
			Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_062_env_3_amount, "Envelope 3 Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			58, 255, 127, ctrl_col_2_x, env_3_row_1_y, knob_diameter, knob_diameter, 
			Tip_Exp::env_3_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
		),
		-1, nullptr);

	env_name = "envelope 3";

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_063_env_3_velo_amt, "Envelope 3 Velocity Amount", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 59, 128, 0, ctrl_col_3_x, env_3_row_1_y,
			knob_diameter, knob_diameter, Tip_Exp::env_velo_amt(env_name),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_064_env_3_delay, "Envelope 3 Delay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			60, 128, 0, ctrl_col_4_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_delay(env_name), Choices_Exp::unsigned_int(128, curt),
			Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_065_env_3_attack, "Envelope 3 Attack", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			61, 128, 0, ctrl_col_5_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_attack(env_name), Choices_Exp::unsigned_int(128, curt),
			Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_066_env_3_decay, "Envelope 3 Decay", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			62, 128, 0, ctrl_col_6_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_decay(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_067_env_3_sustain, "Envelope 3 Sustain", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			63, 128, 0, ctrl_col_7_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_sustain(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_068_env_3_release, "Envelope 3 Release", Ctrl_Type::knob, Knob_Display_Type::unsigned_7_bit,
			64, 128, 0, ctrl_col_8_x, env_3_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_release(env_name), Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_069_env_3_repeat, "Envelope 3 Repeat", Ctrl_Type::toggle, Knob_Display_Type::none,
			98, 2, 0, ctrl_col_1_x, 537, 34, 26, Tip_Exp::env_3_repeat(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on(), ctrl_col_1_x, env_3_row_1_y
		),
		-1, nullptr);
	// ---------------------------------------------------------- end env 3 section
	
	// *************************************************************** mod section
	for (int mod = 0; mod < 4; ++mod) {
		String n{ mod + 1 };
		int offset{ mod * 3 };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 70 + offset } + "_mod_" + n + "_src", "Modulator " + n + " Source",
				Ctrl_Type::cbox, Knob_Display_Type::none, 65 + offset, EXP::choice_count_mod_src, 0,
				mod_col_1_x, 184 + mod * mod_block_spacing, mod_cbox_w, cbox_h, 
				"Selects the modulation source.", Choices_Exp::mod_src(curt), Choices_Exp::mod_src()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 71 + offset } + "_mod_" + n + "_amt", "Modulator " + n + " Amount",
				Ctrl_Type::knob, Knob_Display_Type::signed_8_bit, 66 + offset, 255, 127,
				mod_col_2_x, 201 + mod * mod_block_spacing, knob_diameter, knob_diameter,
				Tip_Exp::mod_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_0" + String{ 72 + offset } + "_mod_" + n + "_dest", "Modulator " + n + " Destination",
				Ctrl_Type::cbox, Knob_Display_Type::none, 67 + offset, EXP::choice_count_mod_dest, 0,
				mod_col_1_x, 218 + mod * mod_block_spacing, mod_cbox_w, cbox_h,
				"Selects the target parameter for modulation.", Choices_Exp::mod_dest(curt),
				Choices_Exp::mod_dest()
			),
			-1, nullptr);
	}
	// ---------------------------------------------------------- end mod section

	// *************************************************************** midi cc section
	auto cc_dest_description = mod_dest_param_description + String{ "." };
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_082_mod_wheel_amt, "Modulation Wheel Amount", Ctrl_Type::knob,
			Knob_Display_Type::signed_8_bit, 81, 255, 127, cc_col_2_x, cc_row_1_y, knob_diameter, knob_diameter,
			Tip_Exp::midi_mod_wheel_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_083_mod_wheel_dest, "Modulation Wheel Destination", Ctrl_Type::cbox, 
			Knob_Display_Type::none, 82, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_1_y,
			cc_cbox_w, cbox_h, cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_084_press_amt, "Pressure (Aftertouch) Amount", Ctrl_Type::knob,
			Knob_Display_Type::signed_8_bit, 83, 255, 127, cc_col_2_x, cc_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::midi_mod_wheel_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_085_press_dest, "Pressure (Aftertouch) Destination", Ctrl_Type::cbox, 
			Knob_Display_Type::none, 84, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_2_y,
			cc_cbox_w, cbox_h, cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_086_breath_amt, "Breath Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			85, 255, 127, cc_col_2_x, cc_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::midi_breath_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_087_breath_dest, "Breath Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
			86, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_3_y,
			cc_cbox_w, cbox_h, cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_088_velocity_amt, "Note Velocity Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			87, 255, 127, cc_col_2_x, cc_row_4_y, knob_diameter, knob_diameter,
			Tip_Exp::midi_velocity_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_089_velocity_dest, "Note Velocity Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
			88, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_4_y,
			cc_cbox_w, cbox_h, cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_090_pedal_amt, "Foot Pedal Amount", Ctrl_Type::knob, Knob_Display_Type::signed_8_bit,
			89, 255, 127, cc_col_2_x, cc_row_5_y, knob_diameter, knob_diameter,
			Tip_Exp::midi_pedal_amt(), Choices_Exp::signed_8_bit_int(curt), Choices_Exp::signed_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_091_pedal_dest, "Foot Pedal Destination", Ctrl_Type::cbox, Knob_Display_Type::none,
			90, EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_5_y,
			cc_cbox_w, cbox_h, cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end midi ctrl section

	// *************************************************************** push it section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_092_push_it_pitch, "Push It! Switch Pitch", Ctrl_Type::knob_pitch,
			Knob_Display_Type::osc_pitch, 111, choice_count_osc_pitch, 60, 1191, push_it_knob_row_y,
			knob_diameter, knob_diameter, Tip_Exp::push_it_pitch(),
			Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch, curt),
			Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_093_push_it_velo, "Push It! Switch Velocity", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_7_bit, 112, 128, 100, 1239, push_it_knob_row_y,
			knob_diameter, knob_diameter, Tip_Exp::push_it_velocity(),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_094_push_it_mode, "Push It! Switch Mode", Ctrl_Type::cbox, Knob_Display_Type::none,
			113, 3, 0, 1215, 577, 88, cbox_h, Tip_Exp::push_it_mode(),
			Choices_Exp::push_it_mode(curt), Choices_Exp::push_it_mode()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end push it section

	// *************************************************************** clock & arp section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_095_clock_tempo, "Clock Tempo", Ctrl_Type::knob, Knob_Display_Type::clock_tempo,
			91, choice_count_clock_tempo, 90, 1236, clock_and_seq_row_y,
			knob_diameter, knob_diameter, Tip_Exp::clock_tempo(),
			Choices_Exp::clock_tempo(curt), Choices_Exp::clock_tempo()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_096_clock_div, "Clock Division", Ctrl_Type::cbox, Knob_Display_Type::none,
			92, 13, 2, 1139, clock_and_seq_row_y, 126, cbox_h, Tip_Exp::clock_division(),
			Choices_Exp::clock_div(curt), Choices_Exp::clock_div()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_097_arp_mode, "Arpeggiator Mode", Ctrl_Type::cbox, Knob_Display_Type::none,
			97, 15, 0, ctrl_col_10_x, 118, 124, cbox_h, Tip_Exp::arp_mode(),
			Choices_Exp::arp_mode(curt), Choices_Exp::arp_mode()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_098_arpeg_on_off, "Arpeggiator On / Off", Ctrl_Type::toggle, Knob_Display_Type::none,
			100, 2, 0, ctrl_col_9_x, 116, 20, 26, Tip_Exp::arp_on_off(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on(), ctrl_col_9_x, osc_row_2_y
		),
		-1, nullptr);
	// ---------------------------------------------------------- end clock & arp section

	// *************************************************************** seq section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_099_seq_trig_mode, "Sequencer Trigger Mode", Ctrl_Type::cbox, Knob_Display_Type::none,
			94, 6, 0, 998, clock_and_seq_row_y, 114, cbox_h, Tip_Exp::seq_trig_mode(),
			Choices_Exp::seq_trig_mode(curt), Choices_Exp::seq_trig_mode()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_100_seq_on_off, "Sequencer On / Off", Ctrl_Type::toggle, Knob_Display_Type::none,
			101, 2, 0, 863, clock_and_seq_row_y, 102, toggle_diameter, Tip_Exp::seq_on_off(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on(), 819, clock_and_seq_row_y
		),
		-1, nullptr);

	for (int track = 1; track < 5; ++track) {
		String n{ track };
		auto even_track = track % 2 == 0;
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_10" + n + "_seq_track_" + n + "_dest", "Sequencer Track " + n + " Destination",
				Ctrl_Type::cbox, Knob_Display_Type::none, 76 + track, 
				EXP::choice_count_mod_dest + (even_track ? 1 : 0), track < 3 ? track : track == 3 ? 9 : 0,
				seq_track_dest_cbox_x, 169 + ((track - 1) * seq_track_block_spacing),
				seq_track_dest_cbox_w, cbox_h, Tip_Exp::seq_track_dest(n),
				even_track ? Choices_Exp::seq_track_2_4_dest(track == 2, curt) : Choices_Exp::mod_dest(curt),
				even_track ? Choices_Exp::seq_track_2_4_dest(track == 2) : Choices_Exp::mod_dest()
			),
			-1, nullptr);
	}
	// ---------------------------------------------------------- end seq section

	// *************************************************************** knob assign section
	for (int knob = 1; knob < 5; ++knob) {
		String n{ knob };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				"ep_10" + String{ 4 + knob } + "_assign_knob_" + n, "Parameter Assigned To Knob " + n,
				Ctrl_Type::cbox, Knob_Display_Type::none, 104 + knob, 169,
				knob == 1 ? 5 : knob == 2 ? 11 : knob == 3 ? 43 : 23, knob_assign_cbox_x,
				521 + ((knob - 1) * knob_assign_spacing), knob_assign_cbox_w, cbox_h,
				Tip_Exp::knob_assign(n), Choices_Exp::knob_assign(curt), Choices_Exp::knob_assign()
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
				Subtree_Exposed_Info_P::build(
					id, "Sequencer Track " + t + " Step " + s, Ctrl_Type::seq_step,
					Knob_Display_Type::none, 120 + track * 16 + step, track == 0 ? 128 : 127, 0,
					825 + step * (seq_step_w + step_and_char_gap), 196 + track * seq_track_block_spacing,
					seq_step_w, seq_step_h, Tip_Exp::seq_track_step(t, s),
					Choices_Exp::seq_track_step(curt), Choices_Exp::seq_track_step()
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
			Subtree_Exposed_Info_P::build(
				id, "Program Name Character " + c, Ctrl_Type::voice_name_char, Knob_Display_Type::none,
				184 + character, choice_count_voice_name_char, (int)init_voice_name[character],
				596 + character * (voice_name_char_w + step_and_char_gap), voice_name_char_y,
				voice_name_char_w, voice_name_char_h, Tip_Exp::voice_name_char(c),
				Choices_Exp::voice_name_char(curt), Choices_Exp::voice_name_char()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end voice name char section
}

const Ctrl_Type Tree_Exposed_Info_P::ctrl_type_for(const int i) const {
	if (i < exp_param_count)
		return Ctrl_Type{ (int)param(i)[ID::exp_p_ctrl_type] };
	return Ctrl_Type::error;
}

const Knob_Display_Type Tree_Exposed_Info_P::knob_display_type_for(const int i) const {
	if (i < exp_param_count)
		return Knob_Display_Type{ (int)param(i)[ID::exp_p_knob_display_type] };
	return Knob_Display_Type::error;
}

const int Tree_Exposed_Info_P::nrpn_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_nrpn];
	return -1;
}

const int Tree_Exposed_Info_P::param_index_for(const int nrpn) const {
	for (int i = 0; i < exp_param_count; ++i) {
		if (nrpn_for(i) == nrpn)
			return i;
	}
	return -1;
}

Point<int> Tree_Exposed_Info_P::red_toggle_center_for(int i) const {
	if (i < exp_param_count && ctrl_type_for(i) == Ctrl_Type::toggle) {
		auto x = (int)param(i)[ID::exp_p_red_toggle_center_x];
		auto y = (int)param(i)[ID::exp_p_red_toggle_center_y];
		return Point<int>{ x, y };
	}
	return {};
}

const int Tree_Exposed_Info_P::packed_bits_byte_index_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_packed_bits_byte_index];
	return -1;
}

const int Tree_Exposed_Info_P::packed_bits_mask_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_packed_bits_mask];
	return -1;
}

const int Tree_Exposed_Info_P::byte_index_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_byte_index];
	return -1;
}

const Track Tree_Exposed_Info_P::seq_track_for(const int i) const {
	if (i < exp_param_count) {
		auto first_track_index = EXP::param_index_seq_track_1_step_1;
		if (i >= first_track_index)
			return Track{ ((i - first_track_index) / 16) + 1 };
		return Track::none;
	}
	return Track::error;
}

const Step Tree_Exposed_Info_P::seq_track_step_for(const int i) const {
	if (i < exp_param_count) {
		auto first_track_index = EXP::param_index_seq_track_1_step_1;
		if (i >= first_track_index)
			return Step{ ((i - first_track_index) % 16) + 1 };
		return Step::none;
	}
	return Step::error;
}
