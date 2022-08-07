#pragma once

#include <JuceHeader.h>

struct ExposedParamDescription
{
	static String buildForKeyboardMode();
	static String buildForOscBalance();
	static String buildForOscKeyClick();
	static String buildForOscKeyTrack(const int oscNum);
	static String buildForLeverControl(const int oscNum);
	static String buildForOscPitch(const int oscNum);
	static String buildForOscPulseWidth(const int oscNum);
	static String buildForOscSawTri(const int oscNum);
	static String buildForOscType(const int oscNum);
	static String buildForOsc_1_Sync();
	static String buildForOsc_2_Detune();
	static String buildForOsc_LFO_1_FM(const int oscNum);
	static String buildForOsc_LFO_2_PWM(const int oscNum);
	static String buildForPortaLegato();
	static String buildForPortaMode();
	static String buildForPortaRate();
	static String buildForPortaVelo();
	static String buildFor_LFO_1_PressureAmt();
	static String buildFor_LFO_2_KeyTrackAmt();
	static String buildFor_LFO_Amp(const int lfoNum);
	static String buildFor_LFO_Lag(const int lfoNum);
	static String buildFor_LFO_RampAmt(const int lfoNum);
	static String buildFor_LFO_RetrigPoint(const int lfoNum);
	static String buildFor_LFO_SampleSource(const int lfoNum);
	static String buildFor_LFO_Speed(const int lfoNum);
	static String buildFor_LFO_TrigMode(const int lfoNum);
	static String buildFor_LFO_WaveType(const int lfoNum);
	static String buildFor_VCA_1_VeloAmt();
	static String buildFor_VCA_1_Volume();
	static String buildFor_VCA_2_Env_2_Amt();
	static String buildFor_VCF_Env_1_Amt();
	static String buildFor_VCF_FM_Env_3_Amt();
	static String buildFor_VCF_FM_Osc_1_Amt();
	static String buildFor_VCF_FM_PressureAmt();
	static String buildFor_VCF_Freq();
	static String buildFor_VCF_KeyTrack();
	static String buildFor_VCF_LeverControl();
	static String buildFor_VCF_PressureAmt();
	static String buildFor_VCF_Reso();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamDescription)
};