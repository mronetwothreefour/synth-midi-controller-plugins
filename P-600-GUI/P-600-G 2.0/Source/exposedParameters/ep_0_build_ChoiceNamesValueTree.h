#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace P_600_G_Constants;

struct ExposedParamChoiceNamesValueTree
{
	static String convertIntToPitchName(const uint8& i) noexcept;

	static ValueTree buildForFilterKeyTrack(const ChoiceNameType type);
	static ValueTree buildForLFO_Shape(const ChoiceNameType type);
	static ValueTree buildForOffOn(const ChoiceNameType type);
	static ValueTree buildForOscFreq(const ChoiceNameType type);
	static ValueTree buildForPlainValue(const uint8 numberOfChoices, ChoiceNameType type);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};