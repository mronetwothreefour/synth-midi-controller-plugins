#include "D_TREE_Exposed_Info_P.h"

#include "D_TIP_Exposed_P.h"

using namespace EXP;
using namespace XYWH;
using Tip_Exp = Tip_Exposed_P;

Tree_Exposed_Info_P::Tree_Exposed_Info_P()
{
	const bool curt{ true };

	using Choices_Exp = Subtree_Choices_Exp_P;
	using Tip_Exp = Tip_Exposed_P;
	using Display = Slider_Display_Type;

	// *************************************************************** osc section
	for (auto osc = 1; osc < 3; ++osc) {
		String o{ osc == 1 ? "A" : "B" };
		tree.addChild(
			Sub_Tree_Exposed::build(
				osc == 1 ? ID::exp_00_osc_a_pitch : ID::exp_06_osc_b_pitch,
				"Oscillator " + o + " Frequency", Ctrl_Type::knob_osc_pitch, osc == 1 ? 8 : 6,
				osc == 1 ? 1 : 3, 6, Display::osc_pitch, choice_count_osc_pitch, 12, osc_col_1_x,
				osc == 1 ? knob_row_2_y : knob_row_3_y, knob_diameter, knob_diameter, Tip_Exp::osc_pitch(o),
				Choices_Exp::osc_pitch(choice_count_osc_pitch, curt),
				Choices_Exp::osc_pitch(choice_count_osc_pitch)
			),
			-1, nullptr);

		tree.addChild(
			Sub_Tree_Exposed::build(
				osc == 1 ? ID::exp_01_osc_a_sync : ID::exp_07_osc_b_fine,
				"Oscillator " + o + (osc == 1 ? " Sync" : " Fine Tune"),
				osc == 1 ? Ctrl_Type::switch_2_pole : Ctrl_Type::knob, osc == 1 ? 30 : 9,
				osc == 1 ? 2 : 3, osc == 1 ? 1 : 7, osc == 1 ? Display::none : Display::int_7_bit,
				osc == 1 ? 2 : 128, 0, osc_col_2_x,
				osc == 1 ? switch_row_1_y : knob_row_3_y, osc == 1 ? switch_w : knob_diameter,
				osc == 1 ? switch_2_pole_h : knob_diameter,
				osc == 1 ? Tip_Exp::osc_a_sync() : Tip_Exp::osc_b_fine(),
				osc == 1 ? Choices_Exp::off_on(curt) : Choices_Exp::unsigned_int(128, curt),
				osc == 1 ? Choices_Exp::off_on() : Choices_Exp::unsigned_int(128)
			),
			-1, nullptr);

		tree.addChild(
			Sub_Tree_Exposed::build(
				osc == 1 ? ID::exp_02_osc_a_saw : ID::exp_08_osc_b_saw,
				"Oscillator " + o + " Shape: Sawtooth", Ctrl_Type::switch_2_pole, 30,
				osc == 1 ? 0 : 3, 1, Display::none, 2, 0, osc_col_3_x, osc == 1 ? switch_row_1_y : switch_row_2_y,
				switch_w, switch_2_pole_h, "When on, oscillator " + o + " outputs a sawtooth wave.",
				Choices_Exp::off_on(curt), Choices_Exp::off_on()
			),
			-1, nullptr);

		tree.addChild(
			Sub_Tree_Exposed::build(
				osc == 1 ? ID::exp_03_osc_a_tri : ID::exp_09_osc_b_tri,
				"Oscillator " + o + " Shape: Triangle", Ctrl_Type::switch_2_pole, osc == 1 ? 30 : 31,
				osc == 1 ? 1 : 0, 1, Display::none, 2, 1, osc_col_4_x, osc == 1 ? switch_row_1_y : switch_row_2_y,
				switch_w, switch_2_pole_h, "When on, oscillator " + o + " outputs a triangle wave.",
				Choices_Exp::off_on(curt), Choices_Exp::off_on()
			),
			-1, nullptr);

		tree.addChild(
			Sub_Tree_Exposed::build(
				osc == 1 ? ID::exp_04_osc_a_pulse : ID::exp_10_osc_b_pulse,
				"Oscillator " + o + " Shape: Pulse", Ctrl_Type::switch_2_pole, 28,
				osc == 1 ? 0 : 1, 1, Display::none, 2, 0, osc_col_5_x, osc == 1 ? switch_row_1_y : switch_row_2_y,
				switch_w, switch_2_pole_h, "When on, oscillator " + o + " outputs a pulse wave.",
				Choices_Exp::off_on(curt), Choices_Exp::off_on()
			),
			-1, nullptr);

		tree.addChild(
			Sub_Tree_Exposed::build(
				osc == 1 ? ID::exp_05_osc_a_pulse_w : ID::exp_11_osc_b_pulse_w,
				"Oscillator " + o + " Pulse Width", Ctrl_Type::knob, osc == 1 ? 0 : 26,
				osc == 1 ? 0 : 1, 7, Display::int_7_bit, 128, 64, osc_col_6_x, osc == 1 ? knob_row_2_y : knob_row_3_y,
				knob_diameter, knob_diameter, Tip_Exp::osc_pulse_w(o),
				Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end osc section

	// *************************************************************** mixer / glide section
	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_12_mixer, "Mixer", Ctrl_Type::knob, 11, 2, 6, Display::int_6_bit, 64, 32,
			mixer_glide_col_x, knob_row_2_y, knob_diameter, knob_diameter, Tip_Exp::mixer(),
			Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_13_glide, "Glide", Ctrl_Type::knob, 25, 1, 4, Display::int_4_bit, 16, 0,
			mixer_glide_col_x, knob_row_3_y, knob_diameter, knob_diameter, Tip_Exp::glide(),
			Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end mixer / glide section

	// *************************************************************** filter section
	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_14_filter_cutoff, "Filter Cutoff Frequency", Ctrl_Type::knob, 13, 0, 7, Display::int_7_bit,
			128, 64, filter_amp_col_1_x, knob_row_1_y, knob_diameter, knob_diameter, Tip_Exp::filter_cutoff(),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_15_filter_reso, "Filter Resonance", Ctrl_Type::knob, 14, 3, 6, Display::int_6_bit, 64, 32,
			filter_amp_col_2_x, knob_row_1_y, knob_diameter, knob_diameter, Tip_Exp::filter_reso(),
			Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_16_filter_env_amt, "Filter Envelope Amount", Ctrl_Type::knob, 16, 1, 4, Display::int_4_bit,
			16, 0, filter_amp_col_3_x, knob_row_1_y, knob_diameter, knob_diameter, Tip_Exp::filter_env_amt(),
			Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_17_filter_key_track, "Filter Keyboard Tracking", Ctrl_Type::switch_3_pole,
			28, 2, 2, Display::none, 3, 2, 1278, 72, switch_w, switch_3_pole_h, Tip_Exp::filter_key_track(),
			Choices_Exp::filter_key_track(curt), Choices_Exp::filter_key_track()
		),
		-1, nullptr);

	auto filter = true;

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_18_filter_env_attack, "Filter Envelope Attack", Ctrl_Type::knob, 20, 1, 4,
			Display::int_4_bit, 16, 0, filter_amp_col_1_x, knob_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_attack(filter), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_19_filter_env_decay, "Filter Envelope Decay", Ctrl_Type::knob, 19, 1, 4,
			Display::int_4_bit, 16, 0, filter_amp_col_2_x, knob_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_decay(filter), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_20_filter_env_sustain, "Filter Envelope Sustain", Ctrl_Type::knob, 18, 1, 4,
			Display::int_4_bit, 16, 0, filter_amp_col_3_x, knob_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_sustain(filter), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_21_filter_env_release, "Filter Envelope Release", Ctrl_Type::knob, 17, 1, 4,
			Display::int_4_bit, 16, 0, filter_amp_col_3_x, knob_row_2_y, knob_diameter, knob_diameter,
			Tip_Exp::env_sustain(filter), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end filter section

	// *************************************************************** amp section
	auto amp = false;

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_22_amp_env_attack, "Amplifier Envelope Attack", Ctrl_Type::knob, 24, 1, 4,
			Display::int_4_bit, 16, 0, filter_amp_col_1_x, knob_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_attack(amp), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_23_amp_env_decay, "Amplifier Envelope Decay", Ctrl_Type::knob, 23, 1, 4,
			Display::int_4_bit, 16, 0, filter_amp_col_2_x, knob_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_decay(amp), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_24_amp_env_sustain, "Amplifier Envelope Sustain", Ctrl_Type::knob, 22, 1, 4,
			Display::int_4_bit, 16, 15, filter_amp_col_3_x, knob_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_sustain(amp), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_25_amp_env_release, "Amplifier Envelope Release", Ctrl_Type::knob, 21, 1, 4,
			Display::int_4_bit, 16, 0, filter_amp_col_3_x, knob_row_3_y, knob_diameter, knob_diameter,
			Tip_Exp::env_sustain(amp), Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);
	// ---------------------------------------------------------- end amp section

	// *************************************************************** poly-mod section
	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_26_p_mod_amt_filter_env, "Poly-Mod Source: Filter Envelope Amount",
			Ctrl_Type::knob, 1, 3, 4, Display::int_4_bit, 16, 0, 60, knob_row_2_y, knob_diameter,
			knob_diameter, Tip_Exp::poly_mod_src_filter_env_amt(), Choices_Exp::unsigned_int(16, curt), 
			Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_27_p_mod_amt_osc_b, "Poly-Mod Source: Oscillator B Amount",
			Ctrl_Type::knob, 3, 3, 7, Display::int_7_bit, 128, 0, 184, knob_row_2_y, knob_diameter,
			knob_diameter, Tip_Exp::poly_mod_src_osc_b_amt(), Choices_Exp::unsigned_int(128, curt),
			Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_28_p_mod_dest_osc_a_freq, "Poly-Mod Destination: Oscillator A Frequency",
			Ctrl_Type::switch_2_pole, 31, 1, 1, Display::none, 2, 0, 287, switch_row_1_y,
			switch_w, switch_2_pole_h, Tip_Exp::poly_mod_dest_osc_a_pitch(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_29_p_mod_dest_filter, "Poly-Mod Destination: Filter Cutoff Frequency",
			Ctrl_Type::switch_2_pole, 31, 2, 1, Display::none, 2, 0, 347, switch_row_1_y,
			switch_w, switch_2_pole_h, Tip_Exp::poly_mod_dest_filter_freq(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end poly-mod section

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_30_unison_track, "Unison Tracking",
			Ctrl_Type::switch_2_pole, 31, 3, 1, Display::none, 2, 0, 416, switch_row_1_y,
			switch_w, switch_2_pole_h, Tip_Exp::unison_track(),
			Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);

	// *************************************************************** lfo section
	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_31_lfo_freq, "LFO Frequency", Ctrl_Type::knob, 2, 3, 4, Display::int_4_bit,
			16, 0, 60, knob_row_3_y, knob_diameter, knob_diameter, Tip_Exp::lfo_freq(),
			Choices_Exp::unsigned_int(16, curt), Choices_Exp::unsigned_int(16)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_32_lfo_shape, "LFO Wave Shape", Ctrl_Type::switch_2_pole, 29, 0, 1, Display::none,
			2, 1, 126, switch_row_2_y, switch_w, switch_2_pole_h, Tip_Exp::lfo_shape(),
			Choices_Exp::lfo_shape(curt), Choices_Exp::lfo_shape()
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_33_lfo_init_amt, "LFO Initial Amount", Ctrl_Type::knob, 5, 2, 5, Display::int_5_bit,
			32, 0, 207, knob_row_3_y, knob_diameter, knob_diameter, Tip_Exp::lfo_init_amt(),
			Choices_Exp::unsigned_int(32, curt), Choices_Exp::unsigned_int(32)
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_34_lfo_dest_osc_pitch, "LFO Destination: Oscillator Frequency", Ctrl_Type::switch_2_pole,
			29, 1, 1, Display::none, 2, 0, 282, switch_row_2_y, switch_w, switch_2_pole_h,
			Tip_Exp::lfo_dest_osc_pitch(), Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_35_lfo_dest_osc_pw, "LFO Destination: Oscillator Pulse Width", Ctrl_Type::switch_2_pole,
			29, 2, 1, Display::none, 2, 0, 342, switch_row_2_y, switch_w, switch_2_pole_h,
			Tip_Exp::lfo_dest_osc_pw(), Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);

	tree.addChild(
		Sub_Tree_Exposed::build(
			ID::exp_36_lfo_dest_filter, "LFO Destination: Filter Cutoff", Ctrl_Type::switch_2_pole,
			29, 3, 1, Display::none, 2, 0, 402, switch_row_2_y, switch_w, switch_2_pole_h,
			Tip_Exp::lfo_dest_filter(), Choices_Exp::off_on(curt), Choices_Exp::off_on()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end poly-mod section
}

const int Tree_Exposed_Info_P::first_nybble_index_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_first_nybble_index];
	return -1;
}

const int Tree_Exposed_Info_P::first_bit_index_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_first_bit_index];
	return -1;
}

const int Tree_Exposed_Info_P::bit_count_for(const int i) const {
	if (i < exp_param_count)
		return (int)param(i)[ID::exp_p_bit_count];
	return -1;
}

