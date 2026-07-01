#include "D_TREE_Exposed_Info_P.h"

#include "D_TIP_Exposed_P.h"

using namespace EXP;
using namespace XYWH;

using Display = Slider_Display_Type;
using Bit_Loc_Exp = Subtree_Bit_Loc_Exp_P;
using Choices_Exp = Subtree_Choices_Exp_P;
using Tip_Exp = Tip_Exposed_P;

Tree_Exposed_Info_P::Tree_Exposed_Info_P()
{
	const bool curt{ true };

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		String o{ osc };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_00_osc_1_octave : ID::exp_04_osc_2_octave,
				"Oscillator " + o + " Octave", Ctrl_Type::switch_osc_octave, Display::none,
				osc == 1 ? 48 : 49, 4, 1, 64, osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, switch_w, switch_h,
				Tip_Exp::osc_octave(o), Bit_Loc_Exp::osc_octave(osc),
				Choices_Exp::osc_octave(curt), Choices_Exp::osc_octave()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_01_osc_1_wave : ID::exp_05_osc_2_wave,
				"Oscillator " + o + " Wave", Ctrl_Type::switch_3_pole, Display::none,
				osc == 1 ? 50 : 51, 3, 2, 124, osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, switch_w, switch_h,
				Tip_Exp::osc_wave(o), Bit_Loc_Exp::osc_wave(osc),
				Choices_Exp::osc_and_lfo_wave(curt), Choices_Exp::osc_and_lfo_wave()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_02_osc_1_pitch_fine : ID::exp_06_osc_2_pitch_fine,
				"Oscillator " + o + " Pitch Fine Tune",  Ctrl_Type::knob_osc_pitch_fine,
				Display::osc_pitch_fine, osc == 1 ? 34 : 35, EXP::choice_count_unsigned_10_bit,
				512, 184, osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exp::osc_pitch_fine(o), Bit_Loc_Exp::osc_pitch_fine(osc),
				Choices_Exp::osc_pitch_fine(curt), Choices_Exp::osc_pitch_fine()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? ID::exp_03_osc_1_shape : ID::exp_07_osc_2_shape,
				"Oscillator " + o + " Shape",  Ctrl_Type::knob, Display::unsigned_10_bit,
				osc == 1 ? 36 : 37, EXP::choice_count_unsigned_10_bit, 0, 244,
				osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exp::osc_shape(o), Bit_Loc_Exp::osc_shape(osc),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end osc section

	// *************************************************************** osc 2 x-mod section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_08_osc_2_xmod_depth, "Oscillator 2 Cross-Modulation Depth", Ctrl_Type::knob,
			Display::osc_2_pitch_eg_int, 41, EXP::choice_count_unsigned_10_bit, 0,
			64, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::osc_2_x_mod_depth(), Bit_Loc_Exp::osc_2_x_mod_depth(),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_09_osc_2_pitch_eg_int, "Oscillator 2 Pitch EG Intensity",
			Ctrl_Type::knob_osc_2_pitch_eg_int, Display::osc_2_pitch_eg_int, 42,
			EXP::choice_count_unsigned_10_bit, 512, 124, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::osc_2_pitch_eg_int(), Bit_Loc_Exp::osc_2_pitch_eg_int(),
			Choices_Exp::osc_2_pitch_eg_int(curt), Choices_Exp::osc_2_pitch_eg_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_10_osc_2_sync, "Oscillator 2 Sync", Ctrl_Type::switch_2_pole, Display::none,
			80, 2, 0, 184, ctrl_row_3_y, switch_w, switch_h, Tip_Exp::osc_2_sync(), Bit_Loc_Exp::osc_2_sync(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_11_osc_2_ring_mod, "Oscillator 2 Ring Modulation", Ctrl_Type::switch_2_pole,
			Display::none, 81, 2, 0, 244, ctrl_row_3_y, switch_w, switch_h,
			Tip_Exp::osc_2_ring_mod(), Bit_Loc_Exp::osc_2_ring_mod(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end osc 2 x-mod section

	// *************************************************************** mixer section
	for (int knob = 1; knob < 4; ++knob) {
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				knob == 1 ? ID::exp_12_osc_1_level : knob == 2 ? ID::exp_13_osc_2_level : ID::exp_14_noise_level,
				String{ knob == 1 ? "Oscillator 1" : knob == 2 ? "Oscillator 2" : "Noise" } + " Level",
				Ctrl_Type::knob, Display::unsigned_10_bit, knob == 1 ? 39 : knob == 2 ? 40 : 33,
				EXP::choice_count_unsigned_10_bit, knob == 1 ? 1023 : 0, 318,
				knob == 1 ? ctrl_row_1_y : knob == 2 ? ctrl_row_2_y : ctrl_row_3_y,
				knob_diameter, knob_diameter, Tip_Exp::level_knob(knob), Bit_Loc_Exp::level_knob(knob),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end mixer section

	// *************************************************************** lpf section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_15_lpf_freq, "LPF Cutoff Frequency", Ctrl_Type::knob,
			Display::unsigned_10_bit, 43, EXP::choice_count_unsigned_10_bit, 1023,
			433, 111, knob_diameter_lpf_freq, knob_diameter_lpf_freq,
			Tip_Exp::lpf_freq(), Bit_Loc_Exp::lpf_freq(),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_16_lpf_reso, "LPF Resonance", Ctrl_Type::knob, Display::unsigned_10_bit,
			44, EXP::choice_count_unsigned_10_bit, 0, 397, ctrl_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::lpf_reso(), Bit_Loc_Exp::lpf_reso(),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_17_lpf_eg_int, "LPF EG Intensity", Ctrl_Type::knob, Display::lpf_eg_int,
			45, EXP::choice_count_unsigned_10_bit, 512, 469, ctrl_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::lpf_eg_int(), Bit_Loc_Exp::lpf_eg_int(),
			Choices_Exp::lpf_eg_int(curt),
			Choices_Exp::lpf_eg_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_18_lpf_type, "LPF Type", Ctrl_Type::switch_2_pole,
			Display::none, 84, 2, 1, 380, ctrl_row_3_y, switch_w, switch_h,
			Tip_Exp::lpf_type(), Bit_Loc_Exp::lpf_type(),
			Choices_Exp::lpf_type(curt), Choices_Exp::lpf_type()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_19_lpf_key_track, "LPF Key Tracking", Ctrl_Type::switch_3_pole,
			Display::none, 83, 3, 0, 437, ctrl_row_3_y, 40, switch_h,
			Tip_Exp::lpf_key_track(), Bit_Loc_Exp::lpf_key_track(),
			Choices_Exp::zero_50_100(curt), Choices_Exp::zero_50_100()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_20_lpf_vel_amt, "LPF Velocity Amount", Ctrl_Type::switch_3_pole,
			Display::none, 82, 3, 0, 482, ctrl_row_3_y, 40, switch_h,
			Tip_Exp::lpf_velo_amt(), Bit_Loc_Exp::lpf_velo_amt(),
			Choices_Exp::zero_50_100(curt), Choices_Exp::zero_50_100()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end lpf section

	// *************************************************************** env section
	for (int env = 1; env < 3; ++env) {
		auto vca = env == 1;
		String pre{ vca ? "VCA " : "" };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				vca ? ID::exp_21_vca_env_attack : ID::exp_25_env_attack,
				pre + "Envelope Attack", Ctrl_Type::knob, Display::unsigned_10_bit,
				vca ? 16 : 20, EXP::choice_count_unsigned_10_bit, 0,
				env_knob_a_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exp::env_attack(vca), Bit_Loc_Exp::env_attack(vca),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				vca ? ID::exp_22_vca_env_decay : ID::exp_26_env_decay,
				pre + "Envelope Decay", Ctrl_Type::knob, Display::unsigned_10_bit,
				vca ? 17 : 21, EXP::choice_count_unsigned_10_bit, 512,
				env_knob_d_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exp::env_decay(vca), Bit_Loc_Exp::env_decay(vca),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				vca ? ID::exp_23_vca_env_sustain : ID::exp_27_env_sustain,
				pre + "Envelope Sustain", Ctrl_Type::knob, Display::unsigned_10_bit,
				vca ? 18 : 22, EXP::choice_count_unsigned_10_bit, vca ? 1023 : 0,
				env_knob_s_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exp::env_sustain(vca), Bit_Loc_Exp::env_sustain(vca),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				vca ? ID::exp_24_vca_env_release : ID::exp_28_env_release,
				pre + "Envelope Release", Ctrl_Type::knob, Display::unsigned_10_bit,
				vca ? 19 : 23, EXP::choice_count_unsigned_10_bit, 0,
				env_knob_r_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exp::env_release(vca), Bit_Loc_Exp::env_release(vca),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end env section

	// *************************************************************** lfo section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_29_LFO_Wave, "LFO Wave", Ctrl_Type::switch_3_pole, Display::none,
			58, 3, 1, 540, ctrl_row_3_y, switch_w, switch_h, Tip_Exp::lfo_wave(), Bit_Loc_Exp::lfo_wave(),
			Choices_Exp::osc_and_lfo_wave(curt), Choices_Exp::osc_and_lfo_wave()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_30_lfo_eg_mod, "LFO EG Modulation Target", Ctrl_Type::switch_3_pole,
			Display::none, 57, 3, 0, 585, ctrl_row_3_y, 40, switch_h,
			Tip_Exp::lfo_eg_mod(), Bit_Loc_Exp::lfo_eg_mod(),
			Choices_Exp::lfo_eg_mod(curt), Choices_Exp::lfo_eg_mod()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_31_lfo_rate, "LFO Rate", Ctrl_Type::knob_lfo_rate, Display::lfo_rate,
			24, EXP::choice_count_unsigned_10_bit, 512, 627, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::lfo_rate(), Bit_Loc_Exp::lfo_rate(), Choices_Exp::lfo_rate(curt), Choices_Exp::lfo_rate()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_32_lfo_int, "LFO Intensity", Ctrl_Type::knob, Display::unsigned_10_bit,
			26, EXP::choice_count_unsigned_10_bit, 0, 695, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::lfo_int(), Bit_Loc_Exp::lfo_int(),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_33_lfo_target, "LFO Modulation Target", Ctrl_Type::switch_3_pole,
			Display::none, 56, 3, 2, 769, ctrl_row_3_y, 50, switch_h,
			Tip_Exp::lfo_target(), Bit_Loc_Exp::lfo_target(),
			Choices_Exp::lfo_target(curt), Choices_Exp::lfo_target()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end lfo section

	// *************************************************************** delay section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_34_delay_hpf_freq, "Delay HPF Cutoff Frequency", Ctrl_Type::knob,
			Display::unsigned_10_bit, 29, EXP::choice_count_unsigned_10_bit, 256,
			848, ctrl_row_1_y, knob_diameter, knob_diameter,
			Tip_Exp::delay_hpf_freq(), Bit_Loc_Exp::delay_hpf_freq(),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_35_delay_time, "Delay Time", Ctrl_Type::knob, Display::unsigned_10_bit,
			30, EXP::choice_count_unsigned_10_bit, 1023, 908, ctrl_row_1_y, knob_diameter, knob_diameter,
			Tip_Exp::delay_time(), Bit_Loc_Exp::delay_time(),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_36_delay_feedback, "Delay Feedback", Ctrl_Type::knob, Display::unsigned_10_bit,
			31, EXP::choice_count_unsigned_10_bit, 512, 968, ctrl_row_1_y, knob_diameter, knob_diameter,
			Tip_Exp::delay_feedback(), Bit_Loc_Exp::delay_feedback(),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Choices_Exp::unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_37_delay_routing, "Delay Output Routing", Ctrl_Type::switch_3_pole,
			Display::none, 88, 3, 0, 1033, ctrl_row_1_y, 50, switch_h,
			Tip_Exp::delay_routing(), Bit_Loc_Exp::delay_routing(),
			Choices_Exp::delay_routing(curt), Choices_Exp::delay_routing()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end delay section

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			ID::exp_38_voice_mode_depth, "Voice Mode Depth", Ctrl_Type::knob_voice_mode_depth,
			Display::voice_mode_depth, 27, EXP::choice_count_unsigned_10_bit, 0,
			1112, ctrl_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::voice_mode_depth(), Bit_Loc_Exp::voice_mode_depth(),
			Choices_Exp::voice_mode_depth(curt), Choices_Exp::voice_mode_depth()
		),
		-1, nullptr);
}

const int Tree_Exposed_Info_P::cc_num_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_cc_num];
	return -1;
}

const int Tree_Exposed_Info_P::bit_count_for(const int i) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::subtree_bit_locations);
		return bit_locations.getNumProperties();
	}
	return -1;
}

const int Tree_Exposed_Info_P::byte_index_for_param_bit(const int i, const int b) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::subtree_bit_locations);
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto byte_index{ bit_locations[bit_id].toString() };
			byte_index = byte_index.fromFirstOccurrenceOf("byte_", false, false);
			byte_index = byte_index.upToFirstOccurrenceOf("__", false, false);
			return byte_index.getIntValue();
		}
	}
	return -1;
}

const int Tree_Exposed_Info_P::bit_index_for_param_bit(const int i, const int b) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::subtree_bit_locations);
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto bit_index{ bit_locations[bit_id].toString() };
			bit_index = bit_index.fromFirstOccurrenceOf("bit_", false, false);
			return bit_index.getIntValue();
		}
	}
	return -1;
}
