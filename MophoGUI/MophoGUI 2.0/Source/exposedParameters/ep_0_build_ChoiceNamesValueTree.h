#pragma once

#include <JuceHeader.h>

struct ExposedParamChoiceNamesValueTree
{
	static String convertIntToPitchName(const uint8& i) noexcept;
	static String convertIntToSeqStepPitchName(const uint8& i) noexcept;

	static ValueTree buildForArpegMode(const bool verbose);
	static ValueTree buildForBendRange(const bool verbose);
	static ValueTree buildForClockDivision(const bool verbose);
	static ValueTree buildForClockTempo(const bool verbose);
	static ValueTree buildForGlideMode(const bool verbose);
	static ValueTree buildForKnobAssign(const bool verbose);
	static ValueTree buildForModDestination(const bool verbose);
	static ValueTree buildForModSource(const bool verbose);
	static ValueTree buildForNotePriority(const bool verbose);
	static ValueTree buildForOffOn(const bool verbose);
	static ValueTree buildForOscFineTune(const bool verbose);
	static ValueTree buildForOscPitch(const bool verbose);
	static ValueTree buildForOscShape(const bool verbose);
	static ValueTree buildForPlainValue(const uint8 numberOfChoices, bool verbose);
	static ValueTree buildForPosNeg_127(const bool verbose);
	static ValueTree buildForPushItMode(const bool verbose);
	static ValueTree buildForSeqTrackStep(const bool verbose);
	static ValueTree buildForSeqTracks_2_4_Destination(const int trackNum, bool verbose);
	static ValueTree buildForSeqTrigMode(const bool verbose);
	static ValueTree buildForVoiceNameChar(const bool verbose);
	static ValueTree buildFor_LFO_Freq(const bool verbose);
	static ValueTree buildFor_LFO_Shape(const bool verbose);
	static ValueTree buildFor_LPF_Freq(const bool verbose);
	static ValueTree buildFor_LPF_Type(const bool verbose);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};