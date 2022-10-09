#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_Splits.h"
#include "../exposedParameters/ep_0_build_ChoiceNamesValueTree.h"

using namespace Matrix_6G_Constants;

struct SplitParamChoiceName
{
	static String buildForZoneLimit(uint8 choiceNum, ChoiceNameType type) {
		jassert(choiceNum > -1 && choiceNum < SPLT::numberOfChoicesForZoneLimit);
		auto pitchName{ ExposedParamChoiceNamesValueTree::convertIntToPitchName(choiceNum) };
		return pitchName + (type == ChoiceNameType::verbose ? " (MIDI Note " + (String)choiceNum + ")" : "");
	}

	static String buildForZoneTranspose(uint8 choiceNum, ChoiceNameType type) {
		jassert(choiceNum > -1 && choiceNum < 61);
		if (choiceNum < 35)
			return (String)(choiceNum - 36) + (type == ChoiceNameType::verbose ? " semitones" : "");
		if (choiceNum == 35)
			return type == ChoiceNameType::verbose ? "-1 semitone" : "-1";
		if (choiceNum == 36)
			return type == ChoiceNameType::verbose ? "No Transpose" : "0";
		if (choiceNum == 37)
			return type == ChoiceNameType::verbose ? "+1 semitone" : "+1";
		if (choiceNum > 37 && choiceNum < 61)
			return "+" + (String)(choiceNum - 36) + (type == ChoiceNameType::verbose ? " semitones" : "");
		else
			return type == ChoiceNameType::verbose ? "range error" : "err";
	}

	static String buildForZone_MIDI_OutIsEnabled(bool isEnabled, ChoiceNameType type) {
		if (isEnabled)
			return type == ChoiceNameType::verbose ? "Enabled" : "ON";
		else
			return type == ChoiceNameType::verbose ? "Disabled" : "OFF";
	}

	static String buildForZoneVoiceAssignment(SplitZoneVoiceAssignment assignment, ChoiceNameType type) {
		switch (assignment)
		{
		case SplitZoneVoiceAssignment::lower_2_Upper_4:
			return type == ChoiceNameType::verbose ? "2 Voices Lower / 4 Voices Upper" : "2/4";
		case SplitZoneVoiceAssignment::lower_4_Upper_2:
			return type == ChoiceNameType::verbose ? "4 Voices Lower / 2 Voices Upper" : "4/2";
		case SplitZoneVoiceAssignment::lower_6_Upper_0:
			return type == ChoiceNameType::verbose ? "6 Voices Lower / 0 Voices Upper" : "6/0";
		case SplitZoneVoiceAssignment::lower_0_Upper_6:
			return type == ChoiceNameType::verbose ? "0 Voices Lower / 6 Voices Upper" : "0/6";
		default:
			return "range error";
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitParamChoiceName)
};