#pragma once

#include <JuceHeader.h>



struct ChoiceNamesValueTree {
	static String convertIntToPitchName(const uint8& i) noexcept;

	static ValueTree buildFor_BendRange(bool verbose);
	static ValueTree buildFor_GlideMode(bool verbose);
	static ValueTree buildFor_LPF_Freq(bool verbose);
	static ValueTree buildFor_LPF_Type(bool verbose);
	static ValueTree buildFor_NotePriority(bool verbose);
	static ValueTree buildFor_OffOn(bool verbose);
	static ValueTree buildFor_OscFineTune(bool verbose);
	static ValueTree buildFor_OscPitch(bool verbose);
	static ValueTree buildFor_OscShape(bool verbose);
	static ValueTree buildFor_PlainValue(uint8 numberOfChoices, bool verbose);
	static ValueTree buildFor_PlusMinus127(bool verbose);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChoiceNamesValueTree)
};