#pragma once

#include <JuceHeader.h>



struct ExposedParamChoiceNamesValueTree {
	static String convertIntToPitchName(const uint8& i) noexcept;
	static String convertIntToSeqStepPitchName(const uint8& i) noexcept;

	static ValueTree buildFor_ArpegMode(bool verbose);
	static ValueTree buildFor_BendRange(bool verbose);
	static ValueTree buildFor_ClockDivision(bool verbose);
	static ValueTree buildFor_ClockTempo(bool verbose);
	static ValueTree buildFor_GlideMode(bool verbose);
	static ValueTree buildFor_KnobAssign(bool verbose);
	static ValueTree buildFor_LFO_Freq(bool verbose);
	static ValueTree buildFor_LFO_Shape(bool verbose);
	static ValueTree buildFor_LPF_Freq(bool verbose);
	static ValueTree buildFor_LPF_Type(bool verbose);
	static ValueTree buildFor_ModDestination(bool verbose);
	static ValueTree buildFor_ModSource(bool verbose);
	static ValueTree buildFor_NotePriority(bool verbose);
	static ValueTree buildFor_OffOn(bool verbose);
	static ValueTree buildFor_OscFineTune(bool verbose);
	static ValueTree buildFor_OscPitch(bool verbose);
	static ValueTree buildFor_OscShape(bool verbose);
	static ValueTree buildFor_PlainValue(uint8 numberOfChoices, bool verbose);
	static ValueTree buildFor_PlusMinus127(bool verbose);
	static ValueTree buildFor_PushItMode(bool verbose);
	static ValueTree buildFor_SeqTrackStep(bool verbose);
	static ValueTree buildFor_SeqTracks_2_4_Destination(int trackNum, bool verbose);
	static ValueTree buildFor_SeqTrigMode(bool verbose);
	static ValueTree buildFor_VoiceNameChar(bool verbose);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};