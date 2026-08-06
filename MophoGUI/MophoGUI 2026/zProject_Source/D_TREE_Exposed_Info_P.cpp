#include "D_TREE_Exposed_Info_P.h"

#include "C_EXP_P.h"
#include "C_ID_P.h"
#include "C_VOICE_P.h"
#include "C_XYWH_P.h"
#include "D_SUBTREE_Choices_Exp_P.h"
#include "D_SUBTREE_Exposed_Info_P.h"
#include "D_TIP_Exposed_P.h"

using namespace EXP;
using namespace XYWH;

using Display = Slider_Display_Type;
using Choices_Exp = Subtree_Choices_Exp_P;
using Tip_Exp = Tip_Exposed_P;

Tree_Exposed_Info_P::Tree_Exposed_Info_P()
{
	const bool curt{ true };

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		auto center_y = osc == 1 ? osc_row_1_y : osc_row_2_y;
		String n{ osc };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_pitch : osc_2_pitch, "Oscillator " + n + " Pitch",
				Ctrl_Type::knob_pitch, Display::osc_pitch, osc == 1 ? 0 : 5,
				choice_count_osc_pitch, 24, ctrl_col_1_x, center_y,
				knob_diam, knob_diam, Tip_Exp::osc_pitch(osc),
				Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch, curt),
				Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_fine_tune : osc_2_fine_tune, "Oscillator " + n + " Fine Tune",
				Ctrl_Type::knob, Display::osc_fine, osc == 1 ? 1 : 6, choice_count_osc_fine,
				osc == 1 ? 49 : 51, ctrl_col_2_x, center_y, knob_diam, knob_diam,
				Tip_Exp::osc_fine(osc), Choices_Exp::osc_fine(curt), Choices_Exp::osc_fine()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_shape : osc_2_shape, "Oscillator " + n + " Wave Shape",
				Ctrl_Type::knob_osc_shape, Display::osc_shape, osc == 1 ? 2 : 7,
				choice_count_osc_shape, 1, ctrl_col_3_x, center_y, knob_diam, knob_diam,
				Tip_Exp::osc_shape(osc), Choices_Exp::osc_shape(curt), Choices_Exp::osc_shape()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_glide : osc_2_glide, "Oscillator " + n + " Glide Rate",
				Ctrl_Type::knob, Display::u_7_bit_int, osc == 1 ? 3 : 8, 128, 0,
				ctrl_col_4_x, center_y, knob_diam, knob_diam, Tip_Exp::osc_glide(osc),
				Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_key_track : osc_2_key_track,
				"Oscillator " + n + " Keyboard Track On/Off", Ctrl_Type::toggle,
				Display::none, osc == 1 ? 4 : 9, 2, 1, ctrl_col_6_x, center_y + 11, 32, 36,
				Tip_Exp::osc_key_track(osc), Choices_Exp::off_on(curt),
				Choices_Exp::off_on(), ctrl_col_6_x, center_y
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_sub_level : osc_2_sub_level,
				"Sub-Oscillator " + n + " Level", Ctrl_Type::knob,
				Display::u_7_bit_int, osc == 1 ? 114 : 115, 128, 0, ctrl_col_5_x,
				center_y, knob_diam, knob_diam, Tip_Exp::osc_sub_level(osc), 
				Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
			),
			-1, nullptr);
	} 

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			osc_sync, "Hard Oscillator Sync On / Off", Ctrl_Type::toggle,
			Display::none, 10, 2, 0, 242, 22, 76, toggle_diam, Tip_Exp::osc_sync(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on(), 273, 22
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			glide_mode, "Glide Mode", Ctrl_Type::cbox, Display::none, 11, 4, 0,
			ctrl_col_10_x, 78, osc_cbox_w, cbox_h, Tip_Exp::glide_mode(),
			Choices_Exp::glide_mode(curt), Choices_Exp::glide_mode()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			osc_slop, "Oscillator Slop", Ctrl_Type::knob, Display::osc_slop, 12, 6, 2,
			ctrl_col_7_x, osc_row_1_y, knob_diam, knob_diam, Tip_Exp::osc_slop(),
			Choices_Exp::u_int(6, curt), Choices_Exp::u_int(6)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			bend_range, "Pitch Bend Range", Ctrl_Type::knob, Display::bend_range, 93,
			choice_count_bend_range, 4, ctrl_col_9_x, osc_row_1_y, knob_diam, knob_diam,
			Tip_Exp::bend_range(), Choices_Exp::bend_range(curt), Choices_Exp::bend_range()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			note_priority, "Note Priority (Key Assign)", Ctrl_Type::cbox, Display::none,
			96, 6, 4, ctrl_col_10_x, 38, osc_cbox_w, cbox_h, Tip_Exp::note_priority(),
			Choices_Exp::note_priority(curt), Choices_Exp::note_priority()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			osc_mix, "Oscillator 1 & 2 Mix", Ctrl_Type::knob, Display::u_7_bit_int,
			13, 128, 64, ctrl_col_8_x, osc_row_1_y, knob_diam, knob_diam, Tip_Exp::osc_mix(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			noise_level, "Noise Level", Ctrl_Type::knob, Display::u_7_bit_int, 14,
			128, 0, ctrl_col_7_x, osc_row_2_y, knob_diam, knob_diam, Tip_Exp::noise_level(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ext_in_level, "External Audio Input Level", Ctrl_Type::knob, Display::u_7_bit_int,
			116, 128, 0, ctrl_col_8_x, osc_row_2_y, knob_diam, knob_diam, Tip_Exp::ext_in_level(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end osc section

	// *************************************************************** lpf section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_freq, "LPF Cutoff Frequency", Ctrl_Type::knob_pitch, Display::lpf_freq, 15,
			choice_count_lpf_freq, 148, ctrl_col_1_x, lpf_row_2_y, knob_diam, knob_diam,
			Tip_Exp::lpf_freq(), Choices_Exp::lpf_freq(curt), Choices_Exp::lpf_freq()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_reso, "LPF Resonance", Ctrl_Type::knob, Display::u_7_bit_int, 16, 128, 0,
			ctrl_col_2_x, lpf_row_2_y, knob_diam, knob_diam, Tip_Exp::lpf_reso(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_key_amt, "LPF Keyboard Amount", Ctrl_Type::knob, Display::u_7_bit_int,
			17, 128, 0, ctrl_col_3_x, lpf_row_2_y, knob_diam, knob_diam, Tip_Exp::lpf_key_amt(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_fm_amt, "LPF FM (By Oscillator 1)", Ctrl_Type::knob, Display::u_7_bit_int,
			18, 128, 0, ctrl_col_3_x, lpf_row_3_y, knob_diam, knob_diam, Tip_Exp::lpf_fm_amt(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_type, "LPF Type", Ctrl_Type::toggle, Display::none, 19, 2, 1,
			ctrl_col_2_x, lpf_row_1_y, 34, 26, Tip_Exp::lpf_type(),
			Choices_Exp::lpf_type(curt), Choices_Exp::lpf_type(), ctrl_col_2_x, 161
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_env_amt, "LPF Envelope Amount", Ctrl_Type::knob, Display::s_8_bit_int, 20,
			255, 127, ctrl_col_1_x, lpf_row_3_y, knob_diam, knob_diam, Tip_Exp::lpf_env_amt(),
			Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
		),
		-1, nullptr);

	String env_name{ "the LPF envelope" };

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_velo_amt, "LPF Envelope Velocity Amount", Ctrl_Type::knob,
			Display::u_7_bit_int, 21, 128, 0, ctrl_col_2_x, lpf_row_3_y,
			knob_diam, knob_diam, Tip_Exp::env_velo_amt(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_delay, "LPF Envelope Delay", Ctrl_Type::knob, Display::u_7_bit_int, 22, 128,
			0, ctrl_col_4_x, lpf_row_3_y, knob_diam, knob_diam, Tip_Exp::env_delay(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_attack, "LPF Envelope Attack", Ctrl_Type::knob, Display::u_7_bit_int, 23, 128,
			0, ctrl_col_5_x, lpf_row_3_y, knob_diam, knob_diam, Tip_Exp::env_attack(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_decay, "LPF Envelope Decay", Ctrl_Type::knob, Display::u_7_bit_int, 24, 128,
			0, ctrl_col_6_x, lpf_row_3_y, knob_diam, knob_diam, Tip_Exp::env_decay(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_sustain, "LPF Envelope Sustain", Ctrl_Type::knob, Display::u_7_bit_int, 25,
			128, 0, ctrl_col_7_x, lpf_row_3_y, knob_diam, knob_diam, Tip_Exp::env_sustain(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			lpf_release, "LPF Envelope Release", Ctrl_Type::knob, Display::u_7_bit_int, 26,
			128, 0, ctrl_col_8_x, lpf_row_3_y, knob_diam, knob_diam, Tip_Exp::env_release(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end lpf section

	// *************************************************************** vca section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_level, "VCA Baseline Level", Ctrl_Type::knob, Display::u_7_bit_int, 27,
			128, 0, ctrl_col_1_x, vca_row_1_y, knob_diam, knob_diam, Tip_Exp::vca_level(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_env_amt, "VCA Envelope Amount", Ctrl_Type::knob, Display::u_7_bit_int, 30,
			128, 127, ctrl_col_2_x, vca_row_1_y, knob_diam, knob_diam, Tip_Exp::vca_env_amt(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	env_name = "the VCA envelope";

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_vel_amt, "VCA Envelope Velocity Amount", Ctrl_Type::knob, Display::u_7_bit_int,
			31, 128, 0, ctrl_col_3_x, vca_row_1_y, knob_diam, knob_diam, Tip_Exp::env_velo_amt(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_delay, "VCA Envelope Delay", Ctrl_Type::knob, Display::u_7_bit_int, 32,
			128, 0, ctrl_col_4_x, vca_row_2_y, knob_diam, knob_diam, Tip_Exp::env_delay(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_attack, "VCA Envelope Attack", Ctrl_Type::knob, Display::u_7_bit_int, 33,
			128, 0, ctrl_col_5_x, vca_row_2_y, knob_diam, knob_diam, Tip_Exp::env_attack(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_decay, "VCA Envelope Decay", Ctrl_Type::knob, Display::u_7_bit_int, 34, 128,
			0, ctrl_col_6_x, vca_row_2_y, knob_diam, knob_diam, Tip_Exp::env_decay(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_sustain, "VCA Envelope Sustain", Ctrl_Type::knob, Display::u_7_bit_int, 35,
			128, 64, ctrl_col_7_x, vca_row_2_y, knob_diam, knob_diam, Tip_Exp::env_sustain(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_release, "VCA Envelope Release", Ctrl_Type::knob, Display::u_7_bit_int, 36,
			128, 64, ctrl_col_8_x, vca_row_2_y, knob_diam, knob_diam, Tip_Exp::env_release(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			voice_volume, "Program Volume", Ctrl_Type::knob, Display::u_7_bit_int, 29, 128,
			120, ctrl_col_2_x, vca_row_2_y, knob_diam, knob_diam, Tip_Exp::voice_volume(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end vca section

	// *************************************************************** lfo section
		auto mod_dest_param_description{ "Selects the target parameter for modulation" };

	for (int lfo = 0; lfo < 4; ++lfo) {
		int offset{ lfo * 5 };
		String n{ lfo + 1 };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(lfo_1_freq + offset), "LFO " + n + " Frequency", Ctrl_Type::knob,
				Display::lfo_freq, 37 + offset, 167, 80, 416 + lfo * lfo_block_spacing,
				lfo_row_1_y, knob_diam, knob_diam, Tip_Exp::lfo_freq(lfo + 1),
				Choices_Exp::lfo_freq(curt), Choices_Exp::lfo_freq()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(lfo_1_shape + offset), "LFO " + n + " Wave Shape", Ctrl_Type::cbox,
				Display::none, 38 + offset, 5, 1, lfo_1_cbox_x + lfo * lfo_block_spacing,
				lfo_row_2_y, lfo_cbox_w, cbox_h, Tip_Exp::lfo_shape(lfo + 1),
				Choices_Exp::lfo_shape(curt), Choices_Exp::lfo_shape()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(lfo_1_amt + offset), "LFO " + n + " Amount", Ctrl_Type::knob,
				Display::u_7_bit_int, 39 + offset, 128, 0, 461 + lfo * lfo_block_spacing,
				lfo_row_1_y, knob_diam, knob_diam, Tip_Exp::lfo_amt(lfo + 1),
				Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(lfo_1_dest + offset), "LFO " + n + " Modulation Destination",
				Ctrl_Type::cbox, Display::none, 40 + offset, EXP::choice_count_mod_dest,
				0, lfo_1_cbox_x + lfo * lfo_block_spacing, lfo_row_3_y, lfo_cbox_w, cbox_h,
				mod_dest_param_description + String{ " by LFO " } + n + ".",
				Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(lfo_1_key_sync + offset), "LFO " + n + " Key Sync On / Off",
				Ctrl_Type::toggle, Display::none, 41 + offset, 2, 0,
				507 + lfo * lfo_block_spacing, 526, 26, 36, Tip_Exp::lfo_key_sync(lfo + 1),
				Choices_Exp::off_on(curt), Choices_Exp::off_on(),
				507 + lfo * lfo_block_spacing, lfo_row_1_y
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end lfo section

	// *************************************************************** env 3 section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_dest, "Envelope 3 Modulation Destination", Ctrl_Type::cbox,
			Display::none, 57, EXP::choice_count_mod_dest, 0, ctrl_col_2_x, env_3_row_2_y,
			126, cbox_h, mod_dest_param_description + String{ " by envelope 3." },
			Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_amount, "Envelope 3 Amount", Ctrl_Type::knob, Display::s_8_bit_int, 58,
			255, 127, ctrl_col_2_x, env_3_row_1_y, knob_diam, knob_diam, Tip_Exp::env_3_amt(),
			Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
		),
		-1, nullptr);

	env_name = "envelope 3";

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_velo_amt, "Envelope 3 Velocity Amount", Ctrl_Type::knob,
			Display::u_7_bit_int, 59, 128, 0, ctrl_col_3_x, env_3_row_1_y,
			knob_diam, knob_diam, Tip_Exp::env_velo_amt(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_delay, "Envelope 3 Delay", Ctrl_Type::knob, Display::u_7_bit_int, 60, 128,
			0, ctrl_col_4_x, env_3_row_2_y, knob_diam, knob_diam, Tip_Exp::env_delay(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_attack, "Envelope 3 Attack", Ctrl_Type::knob, Display::u_7_bit_int, 61, 128,
			0, ctrl_col_5_x, env_3_row_2_y, knob_diam, knob_diam, Tip_Exp::env_attack(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_decay, "Envelope 3 Decay", Ctrl_Type::knob, Display::u_7_bit_int, 62, 128,
			0, ctrl_col_6_x, env_3_row_2_y, knob_diam, knob_diam, Tip_Exp::env_decay(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_sustain, "Envelope 3 Sustain", Ctrl_Type::knob, Display::u_7_bit_int, 63,
			128, 0, ctrl_col_7_x, env_3_row_2_y, knob_diam, knob_diam, Tip_Exp::env_sustain(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_release, "Envelope 3 Release", Ctrl_Type::knob, Display::u_7_bit_int, 64,
			128, 0, ctrl_col_8_x, env_3_row_2_y, knob_diam, knob_diam, Tip_Exp::env_release(env_name),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			env_3_repeat, "Envelope 3 Repeat", Ctrl_Type::toggle, Display::none, 98, 2,
			0, ctrl_col_1_x, 537, 34, 26, Tip_Exp::env_3_repeat(), Choices_Exp::off_on(curt),
			Choices_Exp::off_on(), ctrl_col_1_x, env_3_row_1_y
		),
		-1, nullptr);
	// ---------------------------------------------------------- end env 3 section
	
	// *************************************************************** mod section
	for (int mod = 0; mod < 4; ++mod) {
		String n{ mod + 1 };
		int offset{ mod * 3 };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(mod_1_src + offset), "Modulator " + n + " Source", Ctrl_Type::cbox,
				Display::none, 65 + offset, EXP::choice_count_mod_src, 0, mod_col_1_x,
				184 + mod * mod_block_spacing, mod_cbox_w, cbox_h, "Selects the modulation source.",
				Choices_Exp::mod_src(curt), Choices_Exp::mod_src()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(mod_1_amt + offset), "Modulator " + n + " Amount", Ctrl_Type::knob,
				Display::s_8_bit_int, 66 + offset, 255, 127, mod_col_2_x,
				201 + mod * mod_block_spacing, knob_diam, knob_diam, Tip_Exp::mod_amt(),
				Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(mod_1_dest + offset), "Modulator " + n + " Destination",
				Ctrl_Type::cbox, Display::none, 67 + offset, EXP::choice_count_mod_dest, 0,
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
			mod_wheel_amt, "Modulation Wheel Amount", Ctrl_Type::knob, Display::s_8_bit_int, 81,
			255, 127, cc_col_2_x, cc_row_1_y, knob_diam, knob_diam, Tip_Exp::midi_mod_wheel_amt(),
			Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			mod_wheel_dest, "Modulation Wheel Destination", Ctrl_Type::cbox, Display::none, 82,
			EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_1_y, cc_cbox_w, cbox_h,
			cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			press_amt, "Pressure (Aftertouch) Amount", Ctrl_Type::knob, Display::s_8_bit_int, 83,
			255, 127, cc_col_2_x, cc_row_2_y, knob_diam, knob_diam, Tip_Exp::midi_mod_wheel_amt(),
			Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			press_dest, "Pressure (Aftertouch) Destination", Ctrl_Type::cbox, Display::none, 84,
			EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_2_y, cc_cbox_w, cbox_h,
			cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			breath_amt, "Breath Amount", Ctrl_Type::knob, Display::s_8_bit_int, 85, 255,
			127, cc_col_2_x, cc_row_3_y, knob_diam, knob_diam, Tip_Exp::midi_breath_amt(),
			Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			breath_dest, "Breath Destination", Ctrl_Type::cbox, Display::none, 86,
			EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_3_y, cc_cbox_w, cbox_h,
			cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			velocity_amt, "Note Velocity Amount", Ctrl_Type::knob, Display::s_8_bit_int, 87, 255,
			127, cc_col_2_x, cc_row_4_y, knob_diam, knob_diam, Tip_Exp::midi_velocity_amt(),
			Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			velocity_dest, "Note Velocity Destination", Ctrl_Type::cbox, Display::none, 88,
			EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_4_y, cc_cbox_w, cbox_h,
			cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			pedal_amt, "Foot Pedal Amount", Ctrl_Type::knob, Display::s_8_bit_int, 89, 255, 127,
			cc_col_2_x, cc_row_5_y, knob_diam, knob_diam, Tip_Exp::midi_pedal_amt(),
			Choices_Exp::s_8_bit_int(curt), Choices_Exp::s_8_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			pedal_dest, "Foot Pedal Destination", Ctrl_Type::cbox, Display::none, 90,
			EXP::choice_count_mod_dest, 0, cc_col_1_x, cc_row_5_y, cc_cbox_w, cbox_h,
			cc_dest_description, Choices_Exp::mod_dest(curt), Choices_Exp::mod_dest()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end midi cc section

	// *************************************************************** push it section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			push_it_pitch, "Push It! Switch Pitch", Ctrl_Type::knob_pitch, Display::osc_pitch,
			111, choice_count_osc_pitch, 60, 1191, push_it_knob_row_y, knob_diam, knob_diam,
			Tip_Exp::push_it_pitch(), Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch, curt),
			Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			push_it_velo, "Push It! Switch Velocity", Ctrl_Type::knob, Display::u_7_bit_int,
			112, 128, 100, 1239, push_it_knob_row_y, knob_diam, knob_diam, Tip_Exp::push_it_velocity(),
			Choices_Exp::u_int(128, curt), Choices_Exp::u_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			push_it_mode, "Push It! Switch Mode", Ctrl_Type::cbox, Display::none,
			113, 3, 0, 1215, 577, 88, cbox_h, Tip_Exp::push_it_mode(),
			Choices_Exp::push_it_mode(curt), Choices_Exp::push_it_mode()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end push it section

	// *************************************************************** clock & arp section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			clock_tempo, "Clock Tempo", Ctrl_Type::knob, Display::clock_tempo, 91,
			choice_count_clock_tempo, 90, 1236, clock_and_seq_row_y, knob_diam, knob_diam,
			Tip_Exp::clock_tempo(), Choices_Exp::clock_tempo(curt), Choices_Exp::clock_tempo()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			clock_div, "Clock Division", Ctrl_Type::cbox, Display::none, 92, 13, 2,
			1139, clock_and_seq_row_y, 126, cbox_h, Tip_Exp::clock_division(),
			Choices_Exp::clock_div(curt), Choices_Exp::clock_div()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			arp_mode, "Arpeggiator Mode", Ctrl_Type::cbox, Display::none, 97, 15,
			0, ctrl_col_10_x, 118, 124, cbox_h, Tip_Exp::arp_mode(),
			Choices_Exp::arp_mode(curt), Choices_Exp::arp_mode()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			arpeg_on_off, "Arpeggiator On / Off", Ctrl_Type::toggle, Display::none, 100, 2,
			0, ctrl_col_9_x, 116, 20, 26, Tip_Exp::arp_on_off(), Choices_Exp::off_on(curt),
			Choices_Exp::off_on(), ctrl_col_9_x, osc_row_2_y
		),
		-1, nullptr);
	// ---------------------------------------------------------- end clock & arp section

	// *************************************************************** seq section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			seq_trig_mode, "Sequencer Trigger Mode", Ctrl_Type::cbox, Display::none,
			94, 6, 0, 998, clock_and_seq_row_y, 114, cbox_h, Tip_Exp::seq_trig_mode(),
			Choices_Exp::seq_trig_mode(curt), Choices_Exp::seq_trig_mode()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			seq_on_off, "Sequencer On / Off", Ctrl_Type::toggle, Display::none,
			101, 2, 0, 863, clock_and_seq_row_y, 102, toggle_diam, Tip_Exp::seq_on_off(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on(), 819, clock_and_seq_row_y
		),
		-1, nullptr);

	for (int track = 1; track < 5; ++track) {
		String n{ track };
		auto even_track = track % 2 == 0;
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(seq_track_1_dest + track - 1), "Sequencer Track " + n + " Destination",
				Ctrl_Type::cbox, Display::none, 76 + track, 
				even_track ? EXP::choice_count_seq_track_2_4_dest : EXP::choice_count_mod_dest,
				track < 3 ? track : track == 3 ? 9 : 0,
				seq_track_dest_cbox_x, seq_track_1_dest_cbox_y + ((track - 1) * seq_track_block_spacing),
				seq_track_dest_cbox_w, cbox_h, Tip_Exp::seq_track_dest(track),
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
				Exp_Param(flex_knob_1 + knob - 1), "Parameter Assigned To Knob " + n,
				Ctrl_Type::cbox, Display::none, 104 + knob, choice_count_flex_knob,
				knob == 1 ? 5 : knob == 2 ? 11 : knob == 3 ? 43 : 23, flex_knob_cbox_x,
				521 + ((knob - 1) * flex_knob_spacing), flex_knob_cbox_w, cbox_h,
				Tip_Exp::flex_knob(n), Choices_Exp::flex_knob(curt), Choices_Exp::flex_knob()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end knob assign section

	// *************************************************************** unassigned section
	for (int param = Exp_Param::unassigned_1; param <= Exp_Param::unassigned_11; ++param) {
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(param), "Unassigned", Ctrl_Type::error, Display::none, -1, 0,
				0, 0, 0, 0, 0, "", ValueTree{}, ValueTree{}
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end knob assign section

	// *************************************************************** seq step section
	for (int track = 0; track < 4; ++track) {
		String t{ track + 1 };
		for (int step = 0; step < 16; ++step) {
			String s{ step + 1 };
			int id{ seq_track_1_step_1 + track * 16 + step };
			tree.addChild(
				Subtree_Exposed_Info_P::build(
					Exp_Param(id), "Sequencer Track " + t + " Step " + s,
					t == "1" ? Ctrl_Type::seq_step_trk_1 : Ctrl_Type::seq_step,
					t == "1" ? Display::seq_step_trk_1 : Display::seq_step,
					120 + track * 16 + step, t == "1" ? 128 : 127, 0,
					seq_step_col_1 + step * (seq_step_w + step_and_char_gap), 196 + track * seq_track_block_spacing,
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
		int id{ voice_name_char_1 + character };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(id), "Program Name Character " + c,
				Ctrl_Type::voice_name_char, Display::voice_name_char,
				184 + character, choice_count_voice_name_char, (int)init_voice_name[character],
				596 + character * (voice_name_char_w + step_and_char_gap), voice_name_char_y,
				voice_name_char_w, voice_name_char_h, Tip_Exp::voice_name_char(c),
				Choices_Exp::voice_name_char(curt), Choices_Exp::voice_name_char()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end voice name char section
}

const int Tree_Exposed_Info_P::nrpn_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_nrpn];
}

Point<int> Tree_Exposed_Info_P::red_toggle_center_for(const Exp_Param id) const {
	if (ctrl_type_for(id) == Ctrl_Type::toggle) {
		auto x = (int)param(id)[ID::exp_p_red_toggle_cntr_x];
		auto y = (int)param(id)[ID::exp_p_red_toggle_cntr_y];
		return Point<int>{ x, y };
	}
	return {};
}

const int Tree_Exposed_Info_P::packed_bits_byte_index_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_packed_bits_byte_index];
}

const int Tree_Exposed_Info_P::packed_bits_mask_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_packed_bits_mask];
}

const int Tree_Exposed_Info_P::byte_index_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_byte_index];
}

Layout Tree_Exposed_Info_P::build_param_layout() const {
	Layout layout;
	for (int i = 0; i < EXP::exp_param_count; ++i) {
		if (i < Exp_Param::unassigned_1 || i > Exp_Param::unassigned_11) {
			auto id{ Exp_Param(i) };
			auto name{ name_for(id) };
			auto choices_list{ choices_list_for(id) };
			auto init_choice{ init_choice_for(id) };
			layout.add(std::make_unique<AudioParameterChoice>(id, name, choices_list, init_choice));
		}
	}
	return layout;
}

