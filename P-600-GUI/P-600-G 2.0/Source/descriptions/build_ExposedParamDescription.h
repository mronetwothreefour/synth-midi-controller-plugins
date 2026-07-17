#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace P_600_G_Constants;

struct ExposedParamDescription
{
	static String buildForEnvAttack(EnvelopeType envType);
	static String buildForEnvDecay(EnvelopeType envType);
	static String buildForEnvRelease(EnvelopeType envType);
	static String buildForEnvSustain(EnvelopeType envType);
	static String buildForFilterCutoff();
	static String buildForFilterEnvAmt();
	static String buildForFilterKeyTrack();
	static String buildForFilterReso();
	static String buildForGlide();
	static String buildForLFO_Dest_Filter();
	static String buildForLFO_Dest_Freq();
	static String buildForLFO_Dest_PW();
	static String buildForLFO_Freq();
	static String buildForLFO_InitAmount();
	static String buildForLFO_Shape();
	static String buildForMixer();
	static String buildForOscFreq(const String oscLetter);
	static String buildForOscPulseWidth(const String oscLetter);
	static String buildForOsc_A_Sync();
	static String buildForOsc_B_Fine();
	static String buildForPolyModAmt_FilterEnv();
	static String buildForPolyModAmt_Osc_B();
	static String buildForPolyModDest_Filter();
	static String buildForPolyModDest_Osc_A_Freq();
	static String buildForUnisonTrack();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamDescription)

};