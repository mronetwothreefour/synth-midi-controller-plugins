#include "d_Tree__Exposed_Info_p.h"

#include "d_Tip__Exposed_p.h"

using namespace EXP;
using namespace XYWH;

Exposed_Parameter_Info::Exposed_Parameter_Info() :
	Base_Exposed_Parameter_Info{ EXP::exp_param_count }
{
	const bool curt{ true };

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		String o{ osc };
		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_00_osc_1_octave : ID::exp_04_osc_2_octave,
				"Oscillator " + o + " Octave", Ctrl_Type::switch_osc_octave, Knob_Display_Type::none,
				osc == 1 ? 48 : 49, 4, 1, 64, osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, switch_w, switch_h,
				Tip_Exposed::osc_octave(o), Build_Tree::bit_locations_osc_octave(osc),
				Build_Tree::choice_names_osc_octave(curt), Build_Tree::choice_names_osc_octave()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_01_osc_1_wave : ID::exp_05_osc_2_wave,
				"Oscillator " + o + " Wave", Ctrl_Type::switch_3_pole, Knob_Display_Type::none,
				osc == 1 ? 50 : 51, 3, 2, 124, osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, switch_w, switch_h,
				Tip_Exposed::osc_wave(o), Build_Tree::bit_locations_osc_wave(osc),
				Build_Tree::choice_names_osc_and_lfo_wave(curt), Build_Tree::choice_names_osc_and_lfo_wave()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_02_osc_1_pitch_fine : ID::exp_06_osc_2_pitch_fine,
				"Oscillator " + o + " Pitch Fine Tune",  Ctrl_Type::knob_osc_pitch_fine,
				Knob_Display_Type::osc_pitch_fine, osc == 1 ? 34 : 35, EXP::choice_count_osc_pitch_fine,
				1200, 184, osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exposed::osc_pitch_fine(o), Build_Tree::bit_locations_osc_pitch_fine(osc),
				Build_Tree::choice_names_osc_pitch_fine(curt), Build_Tree::choice_names_osc_pitch_fine()
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				osc == 1 ? ID::exp_03_osc_1_shape : ID::exp_07_osc_2_shape,
				"Oscillator " + o + " Shape",  Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
				osc == 1 ? 36 : 37, EXP::choice_count_unsigned_10_bit, 0, 244,
				osc == 1 ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exposed::osc_shape(o), Build_Tree::bit_locations_osc_shape(osc),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end osc section

	// *************************************************************** osc 2 x-mod section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_08_osc_2_xmod_depth, "Oscillator 2 Cross-Modulation Depth", Ctrl_Type::knob,
			Knob_Display_Type::osc_2_pitch_eg_int, 41, EXP::choice_count_unsigned_10_bit, 0,
			64, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::osc_2_x_mod_depth(), Build_Tree::bit_locations_osc_2_x_mod_depth(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_09_osc_2_pitch_eg_int, "Oscillator 2 Pitch EG Intensity", Ctrl_Type::knob,
			Knob_Display_Type::osc_2_pitch_eg_int, 42, EXP::choice_count_unsigned_10_bit, 512,
			124, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::osc_2_pitch_eg_int(), Build_Tree::bit_locations_osc_2_pitch_eg_int(),
			Build_Tree::choice_names_osc_2_pitch_eg_int(curt),
			Build_Tree::choice_names_osc_2_pitch_eg_int()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_10_osc_2_sync, "Oscillator 2 Sync", Ctrl_Type::switch_2_pole, Knob_Display_Type::none,
			80, 2, 0, 184, ctrl_row_3_y, switch_w, switch_h,
			Tip_Exposed::osc_2_sync(), Build_Tree::bit_locations_osc_2_sync(),
			Build_Tree::choice_names_off_on(curt), Build_Tree::choice_names_off_on()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_11_osc_2_ring_mod, "Oscillator 2 Ring Modulation", Ctrl_Type::switch_2_pole,
			Knob_Display_Type::none, 81, 2, 0, 244, ctrl_row_3_y, switch_w, switch_h,
			Tip_Exposed::osc_2_ring_mod(), Build_Tree::bit_locations_osc_2_ring_mod(),
			Build_Tree::choice_names_off_on(curt), Build_Tree::choice_names_off_on()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end osc 2 x-mod section

	// *************************************************************** mixer section
	for (int knob = 1; knob < 4; ++knob) {
		tree.addChild(
			Build_Tree::exposed_parameter(
				knob == 1 ? ID::exp_12_osc_1_level : knob == 2 ? ID::exp_13_osc_2_level : ID::exp_14_noise_level,
				String{ knob == 1 ? "Oscillator 1" : knob == 2 ? "Oscillator 2" : "Noise" } + " Level",
				Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit, knob == 1 ? 39 : knob == 2 ? 40 : 33,
				EXP::choice_count_unsigned_10_bit, knob == 1 ? 1023 : 0, 318,
				knob == 1 ? ctrl_row_1_y : knob == 2 ? ctrl_row_2_y : ctrl_row_3_y,
				knob_diameter, knob_diameter,
				Tip_Exposed::level_knob(knob), Build_Tree::bit_locations_level_knob(knob),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end mixer section

	// *************************************************************** lpf section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_15_lpf_freq, "LPF Cutoff Frequency", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_10_bit, 43, EXP::choice_count_unsigned_10_bit, 1023,
			433, 111, knob_lpf_freq_diameter, knob_lpf_freq_diameter,
			Tip_Exposed::lpf_freq(), Build_Tree::bit_locations_lpf_freq(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_16_lpf_reso, "LPF Resonance", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
			44, EXP::choice_count_unsigned_10_bit, 0, 397, ctrl_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::lpf_reso(), Build_Tree::bit_locations_lpf_reso(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_17_lpf_eg_int, "LPF EG Intensity", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
			45, EXP::choice_count_unsigned_10_bit, 512, 469, ctrl_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::lpf_eg_int(), Build_Tree::bit_locations_lpf_eg_int(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_18_lpf_type, "LPF Type", Ctrl_Type::switch_2_pole,
			Knob_Display_Type::none, 84, 2, 1, 380, ctrl_row_3_y, switch_w, switch_h,
			Tip_Exposed::lpf_type(), Build_Tree::bit_locations_lpf_type(),
			Build_Tree::choice_names_lpf_type(curt), Build_Tree::choice_names_lpf_type()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_19_lpf_key_track, "LPF Key Tracking", Ctrl_Type::switch_3_pole,
			Knob_Display_Type::none, 83, 3, 0, 437, ctrl_row_3_y, 40, switch_h,
			Tip_Exposed::lpf_key_track(), Build_Tree::bit_locations_lpf_key_track(),
			Build_Tree::choice_names_0_50_100(curt), Build_Tree::choice_names_0_50_100()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_20_lpf_vel_amt, "LPF Velocity Amount", Ctrl_Type::switch_3_pole,
			Knob_Display_Type::none, 82, 3, 0, 482, ctrl_row_3_y, 40, switch_h,
			Tip_Exposed::lpf_velo_amt(), Build_Tree::bit_locations_lpf_velo_amt(),
			Build_Tree::choice_names_0_50_100(curt), Build_Tree::choice_names_0_50_100()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end lpf section

	// *************************************************************** env section
	for (int env = 1; env < 3; ++env) {
		auto vca = env == 1;
		String pre{ vca ? "VCA " : "" };
		tree.addChild(
			Build_Tree::exposed_parameter(
				vca ? ID::exp_21_vca_env_attack : ID::exp_25_env_attack,
				pre + "Envelope Attack", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
				vca ? 16 : 20, EXP::choice_count_unsigned_10_bit, 0,
				env_knob_a_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exposed::env_attack(vca), Build_Tree::bit_locations_env_attack(vca),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				vca ? ID::exp_22_vca_env_decay : ID::exp_26_env_decay,
				pre + "Envelope Decay", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
				vca ? 17 : 21, EXP::choice_count_unsigned_10_bit, 512,
				env_knob_d_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exposed::env_decay(vca), Build_Tree::bit_locations_env_decay(vca),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				vca ? ID::exp_23_vca_env_sustain : ID::exp_27_env_sustain,
				pre + "Envelope Sustain", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
				vca ? 18 : 22, EXP::choice_count_unsigned_10_bit, vca ? 1023 : 0,
				env_knob_s_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exposed::env_sustain(vca), Build_Tree::bit_locations_env_sustain(vca),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);

		tree.addChild(
			Build_Tree::exposed_parameter(
				vca ? ID::exp_24_vca_env_release : ID::exp_28_env_release,
				pre + "Envelope Release", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
				vca ? 19 : 23, EXP::choice_count_unsigned_10_bit, 0,
				env_knob_r_x,  vca ? ctrl_row_1_y : ctrl_row_2_y, knob_diameter, knob_diameter,
				Tip_Exposed::env_release(vca), Build_Tree::bit_locations_env_release(vca),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
				Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end env section

	// *************************************************************** lfo section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_29_LFO_Wave, "LFO Wave", Ctrl_Type::switch_3_pole, Knob_Display_Type::none,
			58, 3, 1, 540, ctrl_row_3_y, switch_w, switch_h,
			Tip_Exposed::lfo_wave(), Build_Tree::bit_locations_lfo_wave(),
			Build_Tree::choice_names_osc_and_lfo_wave(curt), Build_Tree::choice_names_osc_and_lfo_wave()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_30_lfo_eg_mod, "LFO EG Modulation Target", Ctrl_Type::switch_3_pole,
			Knob_Display_Type::none, 57, 3, 0, 585, ctrl_row_3_y, 40, switch_h,
			Tip_Exposed::lfo_eg_mod(), Build_Tree::bit_locations_lfo_eg_mod(),
			Build_Tree::choice_names_lfo_eg_mod(curt), Build_Tree::choice_names_lfo_eg_mod()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_31_lfo_rate, "LFO Rate", Ctrl_Type::knob_lfo_rate, Knob_Display_Type::lfo_rate,
			24, EXP::choice_count_unsigned_10_bit, 512, 627, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::lfo_rate(), Build_Tree::bit_locations_lfo_rate(),
			Build_Tree::choice_names_lfo_rate(curt), Build_Tree::choice_names_lfo_rate()
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_32_lfo_int, "LFO Intensity", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
			26, EXP::choice_count_unsigned_10_bit, 0, 695, ctrl_row_3_y, knob_diameter, knob_diameter,
			Tip_Exposed::lfo_int(), Build_Tree::bit_locations_lfo_int(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_33_lfo_target, "LFO Modulation Target", Ctrl_Type::switch_3_pole,
			Knob_Display_Type::none, 56, 3, 2, 769, ctrl_row_3_y, 50, switch_h,
			Tip_Exposed::lfo_target(), Build_Tree::bit_locations_lfo_target(),
			Build_Tree::choice_names_lfo_target(curt), Build_Tree::choice_names_lfo_target()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end lfo section

	// *************************************************************** delay section
	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_34_delay_hpf_freq, "Delay HPF Cutoff Frequency", Ctrl_Type::knob,
			Knob_Display_Type::unsigned_10_bit, 29, EXP::choice_count_unsigned_10_bit, 256,
			848, ctrl_row_1_y, knob_diameter, knob_diameter,
			Tip_Exposed::delay_hpf_freq(), Build_Tree::bit_locations_delay_hpf_freq(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_35_delay_time, "Delay Time", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
			30, EXP::choice_count_unsigned_10_bit, 1023, 908, ctrl_row_1_y, knob_diameter, knob_diameter,
			Tip_Exposed::delay_time(), Build_Tree::bit_locations_delay_time(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_36_delay_feedback, "Delay Feedback", Ctrl_Type::knob, Knob_Display_Type::unsigned_10_bit,
			31, EXP::choice_count_unsigned_10_bit, 512, 968, ctrl_row_1_y, knob_diameter, knob_diameter,
			Tip_Exposed::delay_feedback(), Build_Tree::bit_locations_delay_feedback(),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit, curt),
			Build_Tree::choice_names_unsigned_int(EXP::choice_count_unsigned_10_bit)
		),
		-1, nullptr);

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_37_delay_routing, "Delay Output Routing", Ctrl_Type::switch_3_pole,
			Knob_Display_Type::none, 88, 3, 0, 1033, ctrl_row_1_y, 50, switch_h,
			Tip_Exposed::delay_routing(), Build_Tree::bit_locations_delay_routing(),
			Build_Tree::choice_names_delay_routing(curt), Build_Tree::choice_names_delay_routing()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end delay section

	tree.addChild(
		Build_Tree::exposed_parameter(
			ID::exp_38_voice_mode_depth, "Voice Mode Depth", Ctrl_Type::knob_voice_mode_depth,
			Knob_Display_Type::voice_mode_depth, 27, EXP::choice_count_unsigned_10_bit, 0,
			1112, ctrl_row_2_y, knob_diameter, knob_diameter,
			Tip_Exposed::voice_mode_depth(), Build_Tree::bit_locations_voice_mode_depth(),
			Build_Tree::choice_names_voice_mode_depth(curt),
			Build_Tree::choice_names_voice_mode_depth()
		),
		-1, nullptr);
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

const uint8 Exposed_Parameter_Info::cc_num_for(const uint8 i) const {
	if (i < exp_param_count)
		return (uint8)(int)param(i)[ID::exp_p_cc_num];
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::bit_count_for(const uint8 i) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::tree_bit_locations);
		return (uint8)bit_locations.getNumProperties();
	}
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::byte_index_for_param_bit(const uint8 i, const uint8 b) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::tree_bit_locations);
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto byte_index{ bit_locations[bit_id].toString() };
			byte_index = byte_index.fromFirstOccurrenceOf("byte_", false, false);
			byte_index = byte_index.upToFirstOccurrenceOf("__", false, false);
			return (uint8)byte_index.getIntValue();
		}
	}
	return (uint8)255;
}

const uint8 Exposed_Parameter_Info::bit_index_for_param_bit(const uint8 i, const uint8 b) const {
	if (i < exp_param_count) {
		auto bit_locations = param(i).getChildWithName(ID::tree_bit_locations);
		if (b < bit_locations.getNumProperties()) {
			Identifier bit_id{ "bit_" + (String)b };
			auto bit_index{ bit_locations[bit_id].toString() };
			bit_index = bit_index.fromFirstOccurrenceOf("bit_", false, false);
			return (uint8)bit_index.getIntValue();
		}
	}
	return (uint8)255;
}
