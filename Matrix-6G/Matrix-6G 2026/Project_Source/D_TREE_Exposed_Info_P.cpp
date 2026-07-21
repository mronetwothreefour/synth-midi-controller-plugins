#include "D_TREE_Exposed_Info_P.h"

#include "C_EXP_P.h"
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
		auto center_x = osc == 1 ? osc_col_1_x : osc_col_2_x;
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_pitch : osc_2_pitch, osc == 1 ? 0 : 10,
				"Oscillator " + (String)osc + " Pitch", Ctrl_Type::slider_osc_pitch,
				osc == 1 ? 1 : 6, Range_Type::unsigned_int, Display::osc_pitch,
				choice_count_osc_pitch, 0, center_x, ctrl_row_01_y, osc_ctrl_w,
				Tip_Exp::osc_pitch(osc), Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch, curt),
				Choices_Exp::osc_pitch(EXP::choice_count_osc_pitch)
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_type : osc_2_type, osc == 1 ? 6 : 16,
				"Oscillator " + (String)osc + " Type", Ctrl_Type::cbox, osc == 1 ? 5 : 10,
				Range_Type::unsigned_int, Display::none, osc == 1 ? 4 : 5,
				osc == 1 ? 2 : 1, center_x, ctrl_row_02_y, osc_ctrl_w, Tip_Exp::osc_type(osc),
				Choices_Exp::osc_type(osc, curt), Choices_Exp::osc_type(osc)
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_pulse_w : osc_2_pulse_w, osc == 1 ? 3 : 13,
				"Oscillator " + (String)osc + " Pulse Width", Ctrl_Type::slider, osc == 1 ? 3 : 8,
				Range_Type::unsigned_int, Display::unsigned_int, 64,
				osc == 1 ? 31 : 24, center_x, ctrl_row_03_y, osc_ctrl_w, Tip_Exp::osc_pulse_w(osc),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_saw_tri : osc_2_saw_tri, osc == 1 ? 5 : 15,
				"Oscillator " + (String)osc + " Saw / Triangle Wave Blend", Ctrl_Type::slider,
				osc == 1 ? 2 : 7, Range_Type::unsigned_int, Display::unsigned_int,
				64, 31, center_x, ctrl_row_04_y, osc_ctrl_w, Tip_Exp::osc_saw_tri(osc),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_sync : osc_2_detune, osc == 1 ? 2 : 12,
				"Oscillator " + (String)osc + (osc == 1 ? " Sync" : " Detune"), 
				osc == 1 ? Ctrl_Type::cbox : Ctrl_Type::slider, osc == 1 ? 17 : 11,
				osc == 1 ? Range_Type::unsigned_int : Range_Type::signed_6_bit, 
				osc == 1 ? Display::none : Display::signed_6_bit,
				osc == 1 ? 4 : 63, osc == 1 ? 0 : 33, center_x, ctrl_row_05_y, osc_ctrl_w,
				osc == 1 ? Tip_Exp::osc_1_sync() : Tip_Exp::osc_2_detune(),
				osc == 1 ? Choices_Exp::osc_1_sync(curt) : Choices_Exp::signed_6_bit_int(curt),
				osc == 1 ? Choices_Exp::osc_1_sync() : Choices_Exp::signed_6_bit_int()
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_lfo_1_fm : osc_2_lfo_1_fm, osc == 1 ? 1 : 11,
				"Oscillator " + (String)osc + " Frequency Mod. by LFO 1", Ctrl_Type::slider, 
				osc == 1 ? 78 : 80, Range_Type::signed_7_bit, Display::signed_7_bit,
				127, 63, center_x, ctrl_row_06_y, osc_ctrl_w, Tip_Exp::osc_lfo_1_fm(osc),
				Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_lfo_2_pwm : osc_2_lfo_2_pwm, osc == 1 ? 4 : 14,
				"Oscillator " + (String)osc + " Pulse Width Mod. by LFO 2", Ctrl_Type::slider, 
				osc == 1 ? 79 : 81, Range_Type::signed_7_bit, Display::signed_7_bit,
				127, 63, center_x, ctrl_row_07_y, osc_ctrl_w, Tip_Exp::osc_lfo_2_pwm(osc),
				Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_key_click : osc_2_key_click, osc == 1 ? 9 : 19,
				"Oscillator " + (String)osc + " Key Click", Ctrl_Type::cbox, 
				osc == 1 ? 14 : 16, Range_Type::unsigned_int, Display::none,
				2, 0, center_x, ctrl_row_08_y, osc_ctrl_w, Tip_Exp::osc_key_click(),
				Choices_Exp::off_on_matrix(curt), Choices_Exp::off_on_matrix()
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_key_track : osc_2_key_track, osc == 1 ? 8 : 18,
				"Oscillator " + (String)osc + " Key Tracking", Ctrl_Type::cbox, 
				osc == 1 ? 13 : 15, Range_Type::unsigned_int, Display::none,
				osc == 1 ? 2 : 3, osc == 1 ? 0 : 2, center_x, ctrl_row_09_y, osc_ctrl_w,  
				Tip_Exp::osc_key_track(osc),
				osc == 1 ? Choices_Exp::osc_1_key_track(curt) : Choices_Exp::osc_2_and_vcf_key_track(curt),
				osc == 1 ? Choices_Exp::osc_1_key_track() : Choices_Exp::osc_2_and_vcf_key_track()
			), 
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				osc == 1 ? osc_1_lever_ctrl : osc_2_lever_ctrl, osc == 1 ? 7 : 17,
				"Oscillator " + (String)osc + " Lever Control", Ctrl_Type::cbox,
				osc == 1 ? 4 : 9, Range_Type::unsigned_int, Display::none,
				4, 3, center_x, ctrl_row_10_y, osc_ctrl_w,
				Tip_Exp::osc_lever_control(osc), Choices_Exp::osc_lever_control(curt),
				Choices_Exp::osc_lever_control()
			), 
			-1, nullptr);
	}

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			osc_balance, 20, "Oscillator Balance", Ctrl_Type::slider_osc_balance,
			12, Range_Type::unsigned_int, Display::unsigned_int,
			64, 31, 163, ctrl_row_11_y, 126, Tip_Exp::osc_balance(),
			Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
		), 
		-1, nullptr);
	// ---------------------------------------------------------- end osc section

	// *************************************************************** vcf section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_freq, 21, "VCF Cutoff Frequency", Ctrl_Type::slider, 18,
			Range_Type::unsigned_int, Display::unsigned_int, 128, 55,
			vcf_vca_col_x, ctrl_row_01_y, vcf_vca_ctrl_w, Tip_Exp::vcf_freq(),
			Choices_Exp::unsigned_int(128, curt), Choices_Exp::unsigned_int(128)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_reso, 24, "VCF Resonance", Ctrl_Type::slider, 19,
			Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
			vcf_vca_col_x, ctrl_row_02_y, vcf_vca_ctrl_w, Tip_Exp::vcf_reso(),
			Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_env_1_amt, 22, "VCF Envelope 1 Amount", Ctrl_Type::slider,
			82, Range_Type::signed_7_bit, Display::signed_7_bit, 127, 105,
			vcf_vca_col_x, ctrl_row_03_y, vcf_vca_ctrl_w, Tip_Exp::vcf_env_1_amt(),
			Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_press_amt, 23, "VCF Pressure Amount", Ctrl_Type::slider,
			83, Range_Type::signed_7_bit, Display::signed_7_bit, 127, 63,
			vcf_vca_col_x, ctrl_row_04_y, vcf_vca_ctrl_w, Tip_Exp::vcf_pressure_amt(),
			Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_lever_ctrl, 25, "VCF Lever Control", Ctrl_Type::cbox,
			20, Range_Type::unsigned_int, Display::none, 4, 0,
			vcf_vca_col_x, ctrl_row_05_y, vcf_vca_ctrl_w, Tip_Exp::vcf_lever_ctrl(),
			Choices_Exp::lever_ctrl(curt), Choices_Exp::lever_ctrl()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_key_track, 26, "VCF Key Tracking", Ctrl_Type::cbox,
			21, Range_Type::unsigned_int, Display::none, 3, 2,
			vcf_vca_col_x, ctrl_row_06_y, vcf_vca_ctrl_w, Tip_Exp::vcf_key_track(),
			Choices_Exp::osc_2_and_vcf_key_track(curt), Choices_Exp::osc_2_and_vcf_key_track()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end vcf section
	
	// *************************************************************** vca section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_1_volume, 27, "VCA 1 Volume", Ctrl_Type::slider,
			23, Range_Type::unsigned_int, Display::unsigned_int, 64, 63,
			vcf_vca_col_x, ctrl_row_09_y, vcf_vca_ctrl_w, Tip_Exp::vca_1_volume(),
			Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_1_velo_amt, 28, "VCA 1 Velocity Amount", Ctrl_Type::slider,
			84, Range_Type::signed_7_bit, Display::signed_7_bit, 127, 63,
			vcf_vca_col_x, ctrl_row_10_y, vcf_vca_ctrl_w, Tip_Exp::vca_1_velo_amt(),
			Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vca_2_env_2_amt, 29, "VCA 2 Envelope 2 Amount", Ctrl_Type::slider,
			85, Range_Type::signed_7_bit, Display::signed_7_bit, 127, 126,
			vcf_vca_col_x, ctrl_row_11_y, vcf_vca_ctrl_w, Tip_Exp::vca_2_env_2_amt(),
			Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end vca section

	// *************************************************************** vcf fm section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_fm_osc_1_amt, 30, "VCF FM By Oscillator 1 Amount", Ctrl_Type::slider,
			22, Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
			vcf_fm_col_x, ctrl_row_01_y, vcf_fm_ctrl_w, Tip_Exp::vcf_fm_osc_1_amt(),
			Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_fm_env_3_amt, 31, "VCF FM Envelope 3 Amount", Ctrl_Type::slider,
			92, Range_Type::signed_7_bit, Display::signed_7_bit, 127, 63,
			vcf_fm_col_x, ctrl_row_02_y, vcf_fm_ctrl_w, Tip_Exp::vcf_fm_env_3_amt(),
			Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			vcf_fm_press_amt, 32, "VCF FM Pressure Amount", Ctrl_Type::slider,
			93, Range_Type::signed_7_bit, Display::signed_7_bit, 127, 63,
			vcf_fm_col_x, ctrl_row_03_y, vcf_fm_ctrl_w, Tip_Exp::vcf_fm_press_amt(),
			Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end vcf fm section

	// *************************************************************** portamento section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			porta_rate, 44, "Portamento Rate", Ctrl_Type::slider,
			24, Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
			porta_key_mode_col_x, ctrl_row_06_y, porta_key_mode_col_w, Tip_Exp::porta_rate(),
			Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			porta_velo, 45, "Portamento Velocity Amount", Ctrl_Type::slider,
			91, Range_Type::signed_7_bit, Display::signed_7_bit, 127, 63,
			porta_key_mode_col_x, ctrl_row_07_y, porta_key_mode_col_w, Tip_Exp::porta_velo(),
			Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			porta_mode, 46, "Portamento Mode", Ctrl_Type::cbox,
			25, Range_Type::unsigned_int, Display::none, 3, 0,
			porta_key_mode_col_x, ctrl_row_08_y, porta_key_mode_col_w, Tip_Exp::porta_mode(),
			Choices_Exp::porta_mode(curt), Choices_Exp::porta_mode()
		),
		-1, nullptr);

	tree.addChild(
		Subtree_Exposed_Info_P::build(
			porta_legato, 47, "Portamento Legato Off / On", Ctrl_Type::cbox,
			26, Range_Type::unsigned_int, Display::none, 2, 0,
			porta_key_mode_col_x, ctrl_row_09_y, porta_key_mode_col_w, Tip_Exp::porta_legato(),
			Choices_Exp::off_on_matrix(curt), Choices_Exp::off_on_matrix()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end portamento section

	// *************************************************************** keyboard mode section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			keyboard_mode, 48, "Keyboard Mode", Ctrl_Type::cbox, 0, Range_Type::unsigned_int,
			Display::none, 4, 0, porta_key_mode_col_x, ctrl_row_12_y, porta_key_mode_col_w,
			Tip_Exp::keyboard_mode(), Choices_Exp::keyboard_mode(curt), Choices_Exp::keyboard_mode()
		),
		-1, nullptr);
	// ---------------------------------------------------------- end keyboard mode section

	// *************************************************************** lfo section
	for (int lfo = 1; lfo < 3; ++lfo) {
		auto center_x = lfo == 1 ? lfo_col_1_x : lfo_col_2_x;
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_speed : lfo_2_speed, lfo == 1 ? 80 : 90,
				"LFO " + (String)lfo + " Speed", Ctrl_Type::slider, lfo == 1 ? 27 : 34,
				Range_Type::unsigned_int, Display::unsigned_int, 64,
				lfo == 1 ? 40 : 30, center_x, ctrl_row_01_y, lfo_ctrl_w, Tip_Exp::lfo_speed(lfo),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_wave_type : lfo_2_wave_type, lfo == 1 ? 82 : 92,
				"LFO " + (String)lfo + " Wave Type", Ctrl_Type::cbox, lfo == 1 ? 30 : 37,
				Range_Type::unsigned_int, Display::none, 7, 0,
				center_x, ctrl_row_02_y, lfo_ctrl_w, Tip_Exp::lfo_wave_type(lfo),
				Choices_Exp::lfo_wave_type(curt), Choices_Exp::lfo_wave_type()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_samp_source : lfo_2_samp_source, lfo == 1 ? 88 : 98,
				"LFO " + (String)lfo + " Sample Source", Ctrl_Type::cbox, lfo == 1 ? 32 : 39,
				Range_Type::unsigned_int, Display::none, EXP::choice_count_mod_src, 9,
				center_x, ctrl_row_03_y, lfo_ctrl_w, Tip_Exp::lfo_sample_source(lfo),
				Choices_Exp::input_source(Input_Choice_Type::lfo, curt),
				Choices_Exp::input_source(Input_Choice_Type::lfo)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_amp : lfo_2_amp, lfo == 1 ? 84 : 94,
				"LFO " + (String)lfo + " Amplitude", Ctrl_Type::slider, lfo == 1 ? 33 : 40,
				Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
				center_x, ctrl_row_04_y, lfo_ctrl_w, Tip_Exp::lfo_amp(lfo),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_press_amt : lfo_2_key_track_amt, lfo == 1 ? 81 : 91,
				lfo == 1 ? "LFO 1 Pressure Amount" : "LFO 2 Key Tracking Amount", Ctrl_Type::slider,
				lfo == 1 ? 94 : 95, Range_Type::signed_7_bit, Display::signed_7_bit,
				127, 63, center_x, ctrl_row_05_y, osc_ctrl_w,
				lfo == 1 ? Tip_Exp::lfo_1_pressure_amt() : Tip_Exp::lfo_2_key_track_amt(),
				Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_ramp_1_amt : lfo_2_ramp_1_amt, lfo == 1 ? 85 : 95,
				"LFO " + (String)lfo + " Ramp " + (String)lfo + " Amount", Ctrl_Type::slider,
				lfo == 1 ? 89 : 90, Range_Type::signed_7_bit, Display::signed_7_bit,
				127, 63, center_x, ctrl_row_06_y, osc_ctrl_w, Tip_Exp::lfo_ramp_amt(lfo),
				Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_trig_mode : lfo_2_trig_mode, lfo == 1 ? 86 : 96,
				"LFO " + (String)lfo + " Trigger Mode", Ctrl_Type::cbox, lfo == 1 ? 28 : 35,
				Range_Type::unsigned_int, Display::none, 4, 0,
				center_x, ctrl_row_07_y, lfo_ctrl_w, Tip_Exp::lfo_trig_mode(lfo),
				Choices_Exp::lfo_trig_mode(curt), Choices_Exp::lfo_trig_mode()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_retrig_point : lfo_2_retrig_point, lfo == 1 ? 83 : 93,
				"LFO " + (String)lfo + " Retrigger Point", Ctrl_Type::slider, lfo == 1 ? 31 : 38,
				Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
				center_x, ctrl_row_08_y, lfo_ctrl_w, Tip_Exp::lfo_retrig_point(lfo),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				lfo == 1 ? lfo_1_lag : lfo_2_lag, lfo == 1 ? 87 : 97,
				"LFO " + (String)lfo + " Lag Processing Off / On", Ctrl_Type::cbox, lfo == 1 ? 29 : 36,
				Range_Type::unsigned_int, Display::none, 2, 0,
				center_x, ctrl_row_09_y, lfo_ctrl_w, Tip_Exp::lfo_lag(lfo),
				Choices_Exp::off_on_matrix(curt), Choices_Exp::off_on_matrix()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end lfo section

	// *************************************************************** ramp section
	for (int ramp = 1; ramp < 3; ++ramp) {
		auto center_x = ramp == 1 ? ramp_col_1_x : ramp_col_2_x;
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				ramp == 1 ? ramp_1_rate : ramp_2_rate, ramp == 1 ? 40 : 42,
				"Ramp " + (String)ramp + " Rate", Ctrl_Type::slider, ramp == 1 ? 74 : 76,
				Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
				center_x, ctrl_row_01_y, ramp_ctrl_w, Tip_Exp::ramp_rate(ramp),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				ramp == 1 ? ramp_1_trig : ramp_2_trig, ramp == 1 ? 41 : 43,
				"Ramp " + (String)ramp + " Trigger", Ctrl_Type::cbox, ramp == 1 ? 75 : 77,
				Range_Type::unsigned_int, Display::none, 4, 0,
				center_x, ctrl_row_02_y, ramp_ctrl_w, Tip_Exp::ramp_trig(ramp),
				Choices_Exp::ramp_trig(curt), Choices_Exp::ramp_trig()
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end ramp section

	// *************************************************************** tracking section
	tree.addChild(
		Subtree_Exposed_Info_P::build(
			track_input, 33, "Tracking Generator Input", Ctrl_Type::cbox, 68,
			Range_Type::unsigned_int, Display::none, EXP::choice_count_mod_src, 9,
			track_input_x, track_input_y, track_input_w, Tip_Exp::track_input(),
			Choices_Exp::input_source(Input_Choice_Type::tracking, curt),
			Choices_Exp::input_source(Input_Choice_Type::tracking)
		),
		-1, nullptr);
	for (int pt = 1; pt < 6; ++pt) {
		auto init_choice{ 0 };
		if (pt == 2)
			init_choice = 15;
		if (pt > 2)
			init_choice = 15 + (pt - 2) * 16;
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(track_point_1 + pt - 1), 33 + pt, "Tracking Point " + (String)pt,
				Ctrl_Type::slider, 68 + pt, Range_Type::unsigned_int, Display::unsigned_int, 64,
				init_choice, track_pt_1_x + (pt - 1) * track_pt_spacing, track_pt_y, track_pt_w,
				Tip_Exp::track_point(pt, init_choice), Choices_Exp::unsigned_int(64, curt),
				Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);
	}
	// ---------------------------------------------------------- end tracking section

	// *************************************************************** envelope section
	for (int env = 0; env < 3; ++env) {
		String env_num{ env + 1 };
		int param_offset{ env * 10 };
		int byte_offset{ env * 9 };
		int block_offset{ env * env_block_spacing };
		int center_x{ env_col_1_x + block_offset };
		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_amp + param_offset), 55 + param_offset,
				"Envelope " + env_num + " Amplitude", Ctrl_Type::slider, 47 + byte_offset,
				Range_Type::unsigned_int, Display::unsigned_int, 64, 40,
				center_x, env_ctrl_row_1_y, env_ctrl_w, Tip_Exp::env_amp(env_num),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_velo_amt + param_offset), 56 + param_offset,
				"Envelope " + env_num + " Velocity Amount", Ctrl_Type::slider, 86 + env,
				Range_Type::signed_7_bit, Display::signed_7_bit, 127, 126,
				center_x, env_ctrl_row_2_y, env_ctrl_w, Tip_Exp::env_velo_amt(env_num),
				Choices_Exp::signed_7_bit_int(curt), Choices_Exp::signed_7_bit_int()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_trig_mode + param_offset), 57 + param_offset,
				"Envelope " + env_num + " Trigger Mode", Ctrl_Type::cbox, 41 + byte_offset,
				Range_Type::unsigned_int, Display::none, 8, 0,
				center_x, env_ctrl_row_3_y, env_ctrl_w, Tip_Exp::env_trig_mode(env_num),
				Choices_Exp::env_trig_mode(curt), Choices_Exp::env_trig_mode()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_mode + param_offset), 58 + param_offset,
				"Envelope " + env_num + " Mode", Ctrl_Type::cbox, 49 + byte_offset,
				Range_Type::unsigned_int, Display::none, 4, 0,
				center_x, env_ctrl_row_4_y, env_ctrl_w, Tip_Exp::env_mode(env_num),
				Choices_Exp::env_mode(curt), Choices_Exp::env_mode()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_lfo_1_trig + param_offset), 59 + param_offset,
				"Envelope " + env_num + " LFO 1 Trigger", Ctrl_Type::cbox, 48 + byte_offset,
				Range_Type::unsigned_int, Display::none, 3, 0,
				center_x, env_ctrl_row_5_y, env_ctrl_w, Tip_Exp::env_lfo_1_trig(env_num),
				Choices_Exp::env_lfo_1_trig(curt), Choices_Exp::env_lfo_1_trig()
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_delay + param_offset), 50 + param_offset,
				"Envelope " + env_num + " Delay Time", Ctrl_Type::slider, 42 + byte_offset,
				Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
				env_1_delay_x + block_offset, env_ctrl_row_4_y, env_dadsr_ctrl_w, Tip_Exp::env_delay(env_num),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_attack + param_offset), 51 + param_offset,
				"Envelope " + env_num + " Attack Time", Ctrl_Type::slider, 43 + byte_offset,
				Range_Type::unsigned_int, Display::unsigned_int, 64, 0,
				env_1_attack_x + block_offset, env_ctrl_row_4_y, env_dadsr_ctrl_w, Tip_Exp::env_attack(env_num),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_decay + param_offset), 52 + param_offset,
				"Envelope " + env_num + " Decay Time", Ctrl_Type::slider, 44 + byte_offset,
				Range_Type::unsigned_int, Display::unsigned_int, 64, env == 2 ? 20 : 10,
				env_1_decay_x + block_offset, env_ctrl_row_4_y, env_dadsr_ctrl_w, Tip_Exp::env_decay(env_num),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_sustain + param_offset), 53 + param_offset,
				"Envelope " + env_num + " Sustain Level", Ctrl_Type::slider, 45 + byte_offset,
				Range_Type::unsigned_int, Display::unsigned_int, 64, env == 2 ? 0 : 50,
				env_1_sustain_x + block_offset, env_ctrl_row_4_y, env_dadsr_ctrl_w, Tip_Exp::env_sustain(env_num),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);

		tree.addChild(
			Subtree_Exposed_Info_P::build(
				Exp_Param(env_1_release + param_offset), 54 + param_offset,
				"Envelope " + env_num + " Release Time", Ctrl_Type::slider, 46 + byte_offset,
				Range_Type::unsigned_int, Display::unsigned_int, 64, env == 2 ? 20 : 10,
				env_1_release_x + block_offset, env_ctrl_row_4_y, env_dadsr_ctrl_w, Tip_Exp::env_release(env_num),
				Choices_Exp::unsigned_int(64, curt), Choices_Exp::unsigned_int(64)
			),
			-1, nullptr);
	} // ---------------------------------------------------------- end envelope section

	auto name = name_for(Exp_Param(95));
	name = name_for(env_3_trig_mode);
}

const int Tree_Exposed_Info_P::number_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_number];
}

const int Tree_Exposed_Info_P::byte_index_for(const Exp_Param id) const {
	return (int)param(id)[ID::exp_p_byte_index];
}

const Range_Type Tree_Exposed_Info_P::range_type_for(const Exp_Param id) const {
	return Range_Type{ (int)param(id)[ID::exp_p_range_type] };
}

