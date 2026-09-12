#pragma once

#include <string>
#include <tuple>
#include <unordered_map>

#include "C_ID_Main_P.h"

using namespace std;

namespace MAP
{

	static const unordered_map<string, tuple<string, int>> exp_name_and_qnum{
		//exposed osc
		{ ID::exp_osc_1_pitch, { "Oscillator 1 Pitch", 0 } },
		{ ID::exp_osc_1_type, { "Oscillator 1 Type", 6 } },
		{ ID::exp_osc_1_pulse_w, { "Oscillator 1 Pulse Width", 3 } },
		{ ID::exp_osc_1_saw_tri, { "Oscillator 1 Saw / Triangle Wave Blend", 5 } },
		{ ID::exp_osc_1_sync, { "Oscillator 1 Sync", 2 } },
		{ ID::exp_osc_1_lfo_1_fm, { "Oscillator 1 Frequency Mod. by LFO 1", 1 } },
		{ ID::exp_osc_1_lfo_2_pwm, { "Oscillator 1 Pulse Width Mod. by LFO 2", 4 } },
		{ ID::exp_osc_1_key_click, { "Oscillator 1 Key Click", 9 } },
		{ ID::exp_osc_1_key_track, { "Oscillator 1 Key Tracking", 8 } },
		{ ID::exp_osc_1_lever_ctrl, { "Oscillator 1 Lever Control", 7 } },
		{ ID::exp_osc_2_pitch, { "Oscillator 2 Pitch", 10 } },
		{ ID::exp_osc_2_type, { "Oscillator 2 Type", 16 } },
		{ ID::exp_osc_2_pulse_w, { "Oscillator 2 Pulse Width", 13 } },
		{ ID::exp_osc_2_saw_tri, { "Oscillator 2 Saw / Triangle Wave Blend", 15 } },
		{ ID::exp_osc_2_detune, { "Oscillator 2 Detune", 12 } },
		{ ID::exp_osc_2_lfo_1_fm, { "Oscillator 2 Frequency Mod. by LFO 1", 11 } },
		{ ID::exp_osc_2_lfo_2_pwm, { "Oscillator 2 Pulse Width Mod. by LFO 2", 14 } },
		{ ID::exp_osc_2_key_click, { "Oscillator 2 Key Click", 19 } },
		{ ID::exp_osc_2_key_track, { "Oscillator 2 Key Tracking", 18 } },
		{ ID::exp_osc_2_lever_ctrl, { "Oscillator 2 Lever Control", 17 } },
		{ ID::exp_osc_balance, { "Oscillator Balance", 20 } },
		//exposed vcf
		{ ID::exp_vcf_freq, { "VCF Cutoff Frequency", 21 } },
		{ ID::exp_vcf_reso, { "VCF Resonance", 24 } },
		{ ID::exp_vcf_env_1_amt, { "VCF Envelope 1 Amount", 22 } },
		{ ID::exp_vcf_press_amt, { "VCF Pressure Amount", 23 } },
		{ ID::exp_vcf_lever_ctrl, { "VCF Lever Control", 25 } },
		{ ID::exp_vcf_key_track, { "VCF Key Tracking", 26 } },
		//exposed vca
		{ ID::exp_vca_1_volume, { "VCA 1 Volume", 27 } },
		{ ID::exp_vca_1_velo_amt, { "VCA 1 Velocity Amount", 28 } },
		{ ID::exp_vca_2_env_2_amt, { "VCA 2 Envelope 2 Amount", 29 } },
		//exposed vcf fm
		{ ID::exp_vcf_fm_osc_1_amt, { "VCF FM By Oscillator 1 Amount", 30 } },
		{ ID::exp_vcf_fm_env_3_amt, { "VCF FM Envelope 3 Amount", 31 } },
		{ ID::exp_vcf_fm_press_amt, { "VCF FM Pressure Amount", 32 } },
		//exposed porta & keyboard mode
		{ ID::exp_porta_rate, { "Portamento Rate", 44 } },
		{ ID::exp_porta_velo, { "Portamento Velocity Amount", 45 } },
		{ ID::exp_porta_mode, { "Portamento Mode", 46 } },
		{ ID::exp_porta_legato, { "Portamento Legato Off / On", 47 } },
		{ ID::exp_keyboard_mode, { "Keyboard Mode", 48 } },
		//exposed lfo
		{ ID::exp_lfo_1_speed, { "LFO 1 Speed", 80 } },
		{ ID::exp_lfo_1_wave_type, { "LFO 1 Wave Type", 82 } },
		{ ID::exp_lfo_1_samp_source, { "LFO 1 Sample Source", 88 } },
		{ ID::exp_lfo_1_amp, { "LFO 1 Amplitude", 84 } },
		{ ID::exp_lfo_1_press_amt, { "LFO 1 Pressure Amount", 81 } },
		{ ID::exp_lfo_1_ramp_1_amt, { "LFO 1 Ramp 1 Amount", 85 } },
		{ ID::exp_lfo_1_trig_mode, { "LFO 1 Trigger Mode", 86 } },
		{ ID::exp_lfo_1_retrig_point, { "LFO 1 Retrigger Point", 83 } },
		{ ID::exp_lfo_1_lag, { "LFO 1 Lag Processing Off / On", 87 } },
		{ ID::exp_lfo_2_speed, { "LFO 2 Speed", 90 } },
		{ ID::exp_lfo_2_wave_type, { "LFO 2 Wave Type", 92 } },
		{ ID::exp_lfo_2_samp_source, { "LFO 2 Sample Source", 98 } },
		{ ID::exp_lfo_2_amp, { "LFO 2 Amplitude", 94 } },
		{ ID::exp_lfo_2_key_track_amt, { "LFO 2 Key Tracking Amount", 91 } },
		{ ID::exp_lfo_2_ramp_2_amt, { "LFO 2 Ramp 2 Amount", 95 } },
		{ ID::exp_lfo_2_trig_mode, { "LFO 2 Trigger Mode", 96 } },
		{ ID::exp_lfo_2_retrig_point, { "LFO 2 Retrigger Point", 93 } },
		{ ID::exp_lfo_2_lag, { "LFO 2 Lag Processing Off / On", 97 } },
		//exposed ramp
		{ ID::exp_ramp_1_rate, { "Ramp 1 Rate", 40 } },
		{ ID::exp_ramp_1_trig, { "Ramp 1 Trigger", 41 } },
		{ ID::exp_ramp_2_rate, { "Ramp 2 Rate", 42 } },
		{ ID::exp_ramp_2_trig, { "Ramp 2 Trigger", 43 } },
		//exposed tracking
		{ ID::exp_track_input, { "Tracking Generator Input", 33 } },
		{ ID::exp_track_point_1, { "Tracking Point 1", 34 } },
		{ ID::exp_track_point_2, { "Tracking Point 2", 35 } },
		{ ID::exp_track_point_3, { "Tracking Point 3", 36 } },
		{ ID::exp_track_point_4, { "Tracking Point 4", 37 } },
		{ ID::exp_track_point_5, { "Tracking Point 5", 38 } },
		//exposed env
		{ ID::exp_env_1_amp, { "Envelope 1 Amplitude", 55 } },
		{ ID::exp_env_1_velo_amt, { "Envelope 1 Velocity Amount", 56 } },
		{ ID::exp_env_1_trig_mode, { "Envelope 1 Trigger Mode", 57 } },
		{ ID::exp_env_1_mode, { "Envelope 1 Mode", 58 } },
		{ ID::exp_env_1_lfo_1_trig, { "Envelope 1 LFO 1 Trigger", 59 } },
		{ ID::exp_env_1_delay, { "Envelope 1 Delay Time", 50 } },
		{ ID::exp_env_1_attack, { "Envelope 1 Attack Time", 51 } },
		{ ID::exp_env_1_decay, { "Envelope 1 Decay Time", 52 } },
		{ ID::exp_env_1_sustain, { "Envelope 1 Sustain Level", 53 } },
		{ ID::exp_env_1_release, { "Envelope 1 Release Time", 54 } },
		{ ID::exp_env_2_amp, { "Envelope 2 Amplitude", 65 } },
		{ ID::exp_env_2_velo_amt, { "Envelope 2 Velocity Amount", 66 } },
		{ ID::exp_env_2_trig_mode, { "Envelope 2 Trigger Mode", 67 } },
		{ ID::exp_env_2_mode, { "Envelope 2 Mode", 68 } },
		{ ID::exp_env_2_lfo_1_trig, { "Envelope 2 LFO 1 Trigger", 69 } },
		{ ID::exp_env_2_delay, { "Envelope 2 Delay Time", 60 } },
		{ ID::exp_env_2_attack, { "Envelope 2 Attack Time", 61 } },
		{ ID::exp_env_2_decay, { "Envelope 2 Decay Time", 62 } },
		{ ID::exp_env_2_sustain, { "Envelope 2 Sustain Level", 63 } },
		{ ID::exp_env_2_release, { "Envelope 2 Release Time", 64 } },
		{ ID::exp_env_3_amp, { "Envelope 3 Amplitude", 75 } },
		{ ID::exp_env_3_velo_amt, { "Envelope 3 Velocity Amount", 76 } },
		{ ID::exp_env_3_trig_mode, { "Envelope 3 Trigger Mode", 77 } },
		{ ID::exp_env_3_mode, { "Envelope 3 Mode", 78 } },
		{ ID::exp_env_3_lfo_1_trig, { "Envelope 3 LFO 1 Trigger", 79 } },
		{ ID::exp_env_3_delay, { "Envelope 3 Delay Time", 70 } },
		{ ID::exp_env_3_attack, { "Envelope 3 Attack Time", 71 } },
		{ ID::exp_env_3_decay, { "Envelope 3 Decay Time", 72 } },
		{ ID::exp_env_3_sustain, { "Envelope 3 Sustain Level", 73 } },
		{ ID::exp_env_3_release, { "Envelope 3 Release Time", 74 } },
	};

}
