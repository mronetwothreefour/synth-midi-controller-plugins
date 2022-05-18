#pragma once

#include <JuceHeader.h>



struct ChoiceNamesValueTree {
	static String convertIntToPitchName(const uint8& i) noexcept;
	static ValueTree buildFor_OscFineTune();
	static ValueTree buildFor_OscFineTune_Verbose();
	static ValueTree buildFor_OscPitch();
	static ValueTree buildFor_OscPitch_Verbose();
	static ValueTree buildFor_OscShape();
	static ValueTree buildFor_OscShape_Verbose();
	static ValueTree buildFor_PlainValue(uint8 numberOfChoices);
	static ValueTree buildFor_PlainValue_Verbose(uint8 numberOfChoices);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChoiceNamesValueTree)
};