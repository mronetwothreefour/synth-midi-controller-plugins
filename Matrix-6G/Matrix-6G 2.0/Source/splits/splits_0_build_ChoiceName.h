#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"
#include "../constants/constants_Splits.h"
#include "../exposedParameters/ep_0_build_ChoiceNamesValueTree.h"

using namespace Matrix_6G_Constants;

struct SplitParamChoiceName
{
	static String buildForZoneLimit(uint8 choiceNum, bool verbose) {
		jassert(choiceNum > -1 && choiceNum < SPLT::numberOfChoicesForZoneLimit);
		auto pitchName{ ExposedParamChoiceNamesValueTree::convertIntToPitchName(choiceNum) };
		return pitchName + (verbose ? " (MIDI Note " + (String)choiceNum + ")" : "");
	}

	static String buildForZoneTranspose(uint8 choiceNum, bool verbose) {
		jassert(choiceNum > -1 && choiceNum < 61);
		if (choiceNum < 35)
			return (String)(choiceNum - 36) + (verbose ? " semitones" : "");
		if (choiceNum == 35)
			return verbose ? "-1 semitone" : "-1";
		if (choiceNum == 36)
			return verbose ? "No Transpose" : "0";
		if (choiceNum == 37)
			return verbose ? "+1 semitone" : "+1";
		if (choiceNum > 37 && choiceNum < 61)
			return "+" + (String)(choiceNum - 36) + (verbose ? " semitones" : "");
		else
			return verbose ? "range error" : "err";
	}

	static String buildForZone_MIDI_OutIsEnabled(bool isEnabled, bool verbose) {
		if (isEnabled)
			return verbose ? "Enabled" : "ON";
		else
			return verbose ? "Disabled" : "OFF";
	}

	static String buildForZoneVoiceAssignment(SplitZoneVoiceAssignment assignment, bool verbose) {
		switch (assignment)
		{
		case SplitZoneVoiceAssignment::lower_2_Upper_4:
			return verbose ? "2 Voices Lower / 4 Voices Upper" : "2/4";
		case SplitZoneVoiceAssignment::lower_4_Upper_2:
			return verbose ? "4 Voices Lower / 2 Voices Upper" : "4/2";
		case SplitZoneVoiceAssignment::lower_6_Upper_0:
			return verbose ? "6 Voices Lower / 0 Voices Upper" : "6/0";
		case SplitZoneVoiceAssignment::lower_0_Upper_6:
			return verbose ? "0 Voices Lower / 6 Voices Upper" : "0/6";
		default:
			return "range error";
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SplitParamChoiceName)
};