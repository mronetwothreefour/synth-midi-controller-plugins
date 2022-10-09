#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace Matrix_6G_Constants;

struct ExposedParamChoiceNamesValueTree 
{
	static String convertIntToPitchName(const uint8& i) noexcept;

	static ValueTree buildForEnvMode(const ChoiceNameType type);
	static ValueTree buildForEnvTrigMode(const ChoiceNameType type);
	static ValueTree buildForEnv_LFO_1_Trig(const ChoiceNameType type);
	static ValueTree buildForKeyboardMode(const ChoiceNameType type);
	static ValueTree buildForLeverControl(const ChoiceNameType type);
	static ValueTree buildForModSource(const ChoiceNameType type);
	static ValueTree buildForOffOn(const ChoiceNameType type);
	static ValueTree buildForOscPitch(const ChoiceNameType type);
	static ValueTree buildForOscType(const int oscNum, const ChoiceNameType type);
	static ValueTree buildForOsc_1_KeyTrack(const ChoiceNameType type);
	static ValueTree buildForOsc_1_Sync(const ChoiceNameType type);
	static ValueTree buildForOsc_2_And_VCF_KeyTrack(const ChoiceNameType type);
	static ValueTree buildForPortaMode(const ChoiceNameType type);
	static ValueTree buildForRampTrig(const ChoiceNameType type);
	static ValueTree buildFor_LFO_SampleSource(const ChoiceNameType type);
	static ValueTree buildFor_LFO_TrigMode(const ChoiceNameType type);
	static ValueTree buildFor_LFO_WaveType(const ChoiceNameType type);
	static ValueTree buildForSigned_6_BitValue(const ChoiceNameType type);
	static ValueTree buildForSigned_7_BitValue(const ChoiceNameType type);
	static ValueTree buildForUnsignedValue(const int numberOfChoices, const ChoiceNameType type);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExposedParamChoiceNamesValueTree)
};