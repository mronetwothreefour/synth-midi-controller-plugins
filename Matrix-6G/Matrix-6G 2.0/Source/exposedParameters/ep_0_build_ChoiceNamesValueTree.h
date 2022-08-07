#pragma once

#include <JuceHeader.h>

struct ExposedParamChoiceNamesValueTree {
	static String convertIntToPitchName(const uint8& i) noexcept;

	static ValueTree buildForKeyboardMode(const bool verbose);
	static ValueTree buildForLeverControl(const bool verbose);
	static ValueTree buildForOffOn(const bool verbose);
	static ValueTree buildForOscPitch(const bool verbose);
	static ValueTree buildForOscType(const int oscNum, const bool verbose);
	static ValueTree buildFor_LFO_SampleSource(const bool verbose);
	static ValueTree buildFor_LFO_TrigMode(const bool verbose);
	static ValueTree buildFor_LFO_WaveType(const bool verbose);
	static ValueTree buildForOsc_1_KeyTrack(const bool verbose);
	static ValueTree buildForOsc_1_Sync(const bool verbose);
	static ValueTree buildForOsc_2_And_VCF_KeyTrack(const bool verbose);
	static ValueTree buildForPortaMode(const bool verbose);
	static ValueTree buildForSigned_6_BitValue(const bool verbose);
	static ValueTree buildForSigned_7_BitValue(const bool verbose);
	static ValueTree buildForUnsignedValue(const int numberOfChoices, const bool verbose);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};