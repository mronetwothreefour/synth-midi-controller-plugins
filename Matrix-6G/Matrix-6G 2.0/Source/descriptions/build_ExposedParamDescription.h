#pragma once

#include <JuceHeader.h>

struct ExposedParamDescription
{
	static String buildForOscPitch(const int oscNum);
	static String buildForOscPulseWidth(const int oscNum);
	static String buildForOscSawTri(const int oscNum);
	static String buildForOscType(const int oscNum);
	static String buildForOsc_1_Sync();
	static String buildForOsc_2_Detune();
	static String buildForOsc_LFO_1_FM(const int oscNum);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamDescription)
};