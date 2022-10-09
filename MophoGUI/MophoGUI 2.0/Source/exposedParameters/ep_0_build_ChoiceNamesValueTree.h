#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;

struct ExposedParamChoiceNamesValueTree
{
	static String convertIntToPitchName(const uint8& i) noexcept;
	static String convertIntToSeqStepPitchName(const uint8& i) noexcept;

	static ValueTree buildForArpegMode(const ChoiceNameType type);
	static ValueTree buildForBendRange(const ChoiceNameType type);
	static ValueTree buildForClockDivision(const ChoiceNameType type);
	static ValueTree buildForClockTempo(const ChoiceNameType type);
	static ValueTree buildForGlideMode(const ChoiceNameType type);
	static ValueTree buildForKnobAssign(const ChoiceNameType type);
	static ValueTree buildForModDestination(const ChoiceNameType type);
	static ValueTree buildForModSource(const ChoiceNameType type);
	static ValueTree buildForNotePriority(const ChoiceNameType type);
	static ValueTree buildForOffOn(const ChoiceNameType type);
	static ValueTree buildForOscFineTune(const ChoiceNameType type);
	static ValueTree buildForOscPitch(const ChoiceNameType type);
	static ValueTree buildForOscShape(const ChoiceNameType type);
	static ValueTree buildForPlainValue(const uint8 numberOfChoices, const ChoiceNameType type);
	static ValueTree buildForPosNeg_127(const ChoiceNameType type);
	static ValueTree buildForPushItMode(const ChoiceNameType type);
	static ValueTree buildForSeqTrackStep(const ChoiceNameType type);
	static ValueTree buildForSeqTracks_2_4_Destination(const int trackNum, const ChoiceNameType type);
	static ValueTree buildForSeqTrigMode(const ChoiceNameType type);
	static ValueTree buildForVoiceNameChar(const ChoiceNameType type);
	static ValueTree buildFor_LFO_Freq(const ChoiceNameType type);
	static ValueTree buildFor_LFO_Shape(const ChoiceNameType type);
	static ValueTree buildFor_LPF_Freq(const ChoiceNameType type);
	static ValueTree buildFor_LPF_Type(const ChoiceNameType type);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};