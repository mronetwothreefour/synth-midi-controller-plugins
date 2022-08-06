#pragma once

#include <JuceHeader.h>

struct ExposedParamChoiceNamesValueTree {
	static String convertIntToPitchName(const uint8& i) noexcept;

	static ValueTree buildForOscPitch(const bool verbose);
	static ValueTree buildForOscType(const int oscNum, const bool verbose);
	static ValueTree buildForOsc_1_Sync(const bool verbose);
	static ValueTree buildForSigned_6_BitValue(const bool verbose);
	static ValueTree buildForSigned_7_BitValue(const bool verbose);
	static ValueTree buildForUnsignedValue(const int numberOfChoices, const bool verbose);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};