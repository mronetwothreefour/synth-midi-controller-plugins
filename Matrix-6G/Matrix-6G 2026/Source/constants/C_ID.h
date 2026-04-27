#pragma once

#include <JuceHeader.h>

namespace ID
{

	static const Identifier ep_00_osc_1_pitch        { "Ext. Parameter 00: Osc. 1 Pitch" };
	static const Identifier ep_01_osc_1_type         { "Ext. Parameter 01: Osc. 1 Type Select" };
	static const Identifier ep_02_osc_1_pulse_width  { "Ext. Parameter 02: Osc. 1 Pulse Width" };
	static const Identifier ep_03_osc_1_saw_tri      { "Ext. Parameter 03: Osc. 1 Saw / Tri Wave" };
	static const Identifier ep_04_osc_1_sync         { "Ext. Parameter 04: Osc. 1 Sync" };
	static const Identifier ep_05_osc_1_lfo_1_fm     { "Ext. Parameter 05: Osc. 1 LFO 1 FM Amount" };
	static const Identifier ep_06_osc_1_lfo_2_pwm    { "Ext. Parameter 06: Osc. 1 LFO 2 PWM Amount" };
	static const Identifier ep_07_osc_1_key_click    { "Ext. Parameter 07: Osc. 1 Key Click" };
	static const Identifier ep_08_osc_1_key_track    { "Ext. Parameter 08: Osc. 1 Key Tracking" };
	static const Identifier ep_09_osc_1_lever_ctrl   { "Ext. Parameter 09: Osc. 1 Lever Control" };
	static const Identifier ep_10_osc_2_pitch        { "Ext. Parameter 10: Osc. 2 Pitch" };
	static const Identifier ep_11_osc_2_type         { "Ext. Parameter 11: Osc. 2 Wave Type" };
	static const Identifier ep_12_osc_2_pulse_width  { "Ext. Parameter 12: Osc. 2 Pulse Width" };
	static const Identifier ep_13_osc_2_saw_tri      { "Ext. Parameter 13: Osc. 2 Saw / Tri Wave" };
	static const Identifier ep_14_osc_2_detune       { "Ext. Parameter 14: Osc. 2 Detune" };
	static const Identifier ep_15_osc_2_lfo_1_fm     { "Ext. Parameter 15: Osc. 2 LFO 1 FM Amount" };
	static const Identifier ep_16_osc_2_lfo_2_pwm    { "Ext. Parameter 16: Osc. 2 LFO 2 PWM Amount" };
	static const Identifier ep_17_osc_2_key_click    { "Ext. Parameter 17: Osc. 2 Key Click" };
	static const Identifier ep_18_osc_2_key_track    { "Ext. Parameter 18: Osc. 2 Key Tracking" };
	static const Identifier ep_19_osc_2_lever_ctrl   { "Ext. Parameter 19: Osc. 2 Lever Control" };
	static const Identifier ep_20_osc_balance        { "Ext. Parameter 20: Osc Balance" };
	static const Identifier ep_21_VCF_Freq           { "Ext. Parameter 21: VCF_Freq" };
	static const Identifier ep_22_VCF_Reso           { "Ext. Parameter 22: VCF_Reso" };
	static const Identifier ep_23_VCF_Env_1_Amt      { "Ext. Parameter 23: VCF_Env_1_Amt" };
	static const Identifier ep_24_VCF_PressureAmt    { "Ext. Parameter 24: VCF_PressureAmt" };
	static const Identifier ep_25_VCF_LeverControl   { "Ext. Parameter 25: VCF_LeverControl" };
	static const Identifier ep_26_VCF_KeyTrack       { "Ext. Parameter 26: VCF_KeyTrack" };
	static const Identifier ep_27_VCA_1_Volume       { "Ext. Parameter 27: VCA_1_Volume" };
	static const Identifier ep_28_VCA_1_VeloAmt      { "Ext. Parameter 28: VCA_1_VeloAmt" };
	static const Identifier ep_29_VCA_2_Env_2_Amt    { "Ext. Parameter 29: VCA_2_Env_2_Amt" };
	static const Identifier ep_30_VCF_FM_Osc_1_Amt   { "Ext. Parameter 30: VCF_FM_Osc_1_Amt" };
	static const Identifier ep_31_VCF_FM_Env_3_Amt   { "Ext. Parameter 31: VCF_FM_Env_3_Amt" };
	static const Identifier ep_32_VCF_FM_PressureAmt { "Ext. Parameter 32: VCF_FM_PressureAmt" };
	static const Identifier ep_33_PortaRate          { "Ext. Parameter 33: PortaRate" };
	static const Identifier ep_34_PortaVelo          { "Ext. Parameter 34: PortaVelo" };
	static const Identifier ep_35_PortaMode          { "Ext. Parameter 35: PortaMode" };
	static const Identifier ep_36_PortaLegato        { "Ext. Parameter 36: PortaLegato" };
	static const Identifier ep_37_KeyboardMode       { "Ext. Parameter 37: KeyboardMode" };
	static const Identifier ep_38_LFO_1_Speed        { "Ext. Parameter 38: LFO_1_Speed" };
	static const Identifier ep_39_LFO_1_WaveType     { "Ext. Parameter 39: LFO_1_WaveType" };
	static const Identifier ep_40_LFO_1_SampleSource { "Ext. Parameter 40: LFO_1_SampleSource" };
	static const Identifier ep_41_LFO_1_Amp          { "Ext. Parameter 41: LFO_1_Amp" };
	static const Identifier ep_42_LFO_1_PressureAmt  { "Ext. Parameter 42: LFO_1_PressureAmt" };
	static const Identifier ep_43_LFO_1_Ramp_1_Amt   { "Ext. Parameter 43: LFO_1_Ramp_1_Amt" };
	static const Identifier ep_44_LFO_1_TrigMode     { "Ext. Parameter 44: LFO_1_TrigMode" };
	static const Identifier ep_45_LFO_1_RetrigPoint  { "Ext. Parameter 45: LFO_1_RetrigPoint" };
	static const Identifier ep_46_LFO_1_Lag          { "Ext. Parameter 46: LFO_1_Lag" };
	static const Identifier ep_47_LFO_2_Speed        { "Ext. Parameter 47: LFO_2_Speed" };
	static const Identifier ep_48_LFO_2_WaveType     { "Ext. Parameter 48: LFO_2_WaveType" };
	static const Identifier ep_49_LFO_2_SampleSource { "Ext. Parameter 49: LFO_2_SampleSource" };
	static const Identifier ep_50_LFO_2_Amp          { "Ext. Parameter 50: LFO_2_Amp" };
	static const Identifier ep_51_LFO_2_KeyTrackAmt  { "Ext. Parameter 51: LFO_2_KeyTrackAmt" };
	static const Identifier ep_52_LFO_2_Ramp_2_Amt   { "Ext. Parameter 52: LFO_2_Ramp_2_Amt" };
	static const Identifier ep_53_LFO_2_TrigMode     { "Ext. Parameter 53: LFO_2_TrigMode" };
	static const Identifier ep_54_LFO_2_RetrigPoint  { "Ext. Parameter 54: LFO_2_RetrigPoint" };
	static const Identifier ep_55_LFO_2_Lag          { "Ext. Parameter 55: LFO_2_Lag" };
	static const Identifier ep_56_Ramp_1_Rate        { "Ext. Parameter 56: Ramp_1_Rate" };
	static const Identifier ep_57_Ramp_1_Trig        { "Ext. Parameter 57: Ramp_1_Trig" };
	static const Identifier ep_58_Ramp_2_Rate        { "Ext. Parameter 58: Ramp_2_Rate" };
	static const Identifier ep_59_Ramp_2_Trig        { "Ext. Parameter 59: Ramp_2_Trig" };
	static const Identifier ep_60_TrackInput         { "Ext. Parameter 60: TrackInput" };
	static const Identifier ep_61_TrackPoint_1       { "Ext. Parameter 61: TrackPoint_1" };
	static const Identifier ep_62_TrackPoint_2       { "Ext. Parameter 62: TrackPoint_2" };
	static const Identifier ep_63_TrackPoint_3       { "Ext. Parameter 63: TrackPoint_3" };
	static const Identifier ep_64_TrackPoint_4       { "Ext. Parameter 64: TrackPoint_4" };
	static const Identifier ep_65_TrackPoint_5       { "Ext. Parameter 65: TrackPoint_5" };
	static const Identifier ep_71_Env_1_Delay        { "Ext. Parameter 71: Env_1_Delay" };
	static const Identifier ep_72_Env_1_Attack       { "Ext. Parameter 72: Env_1_Attack" };
	static const Identifier ep_73_Env_1_Decay        { "Ext. Parameter 73: Env_1_Decay" };
	static const Identifier ep_74_Env_1_Sustain      { "Ext. Parameter 74: Env_1_Sustain" };
	static const Identifier ep_75_Env_1_Release      { "Ext. Parameter 75: Env_1_Release" };
	static const Identifier ep_81_Env_2_Delay        { "Ext. Parameter 81: Env_2_Delay" };
	static const Identifier ep_82_Env_2_Attack       { "Ext. Parameter 82: Env_2_Attack" };
	static const Identifier ep_83_Env_2_Decay        { "Ext. Parameter 83: Env_2_Decay" };
	static const Identifier ep_84_Env_2_Sustain      { "Ext. Parameter 84: Env_2_Sustain" };
	static const Identifier ep_85_Env_2_Release      { "Ext. Parameter 85: Env_2_Release" };
	static const Identifier ep_91_Env_3_Delay        { "Ext. Parameter 91: Env_3_Delay" };
	static const Identifier ep_92_Env_3_Attack       { "Ext. Parameter 92: Env_3_Attack" };
	static const Identifier ep_93_Env_3_Decay        { "Ext. Parameter 93: Env_3_Decay" };
	static const Identifier ep_94_Env_3_Sustain      { "Ext. Parameter 94: Env_3_Sustain" };
	static const Identifier ep_95_Env_3_Release      { "Ext. Parameter 95: Env_3_Release" };

}