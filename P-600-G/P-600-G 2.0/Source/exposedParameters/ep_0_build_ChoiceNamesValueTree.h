#pragma once

#include <JuceHeader.h>

struct ExposedParamChoiceNamesValueTree
{
	static String convertIntToPitchName(const uint8& i) noexcept;

	static ValueTree buildForFilterKeyTrack(const bool verbose);
	static ValueTree buildForLFO_Shape(const bool verbose);
	static ValueTree buildForOffOn(const bool verbose);
	static ValueTree buildForOscFreq(const bool verbose);
	static ValueTree buildForPlainValue(const uint8 numberOfChoices, bool verbose);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};