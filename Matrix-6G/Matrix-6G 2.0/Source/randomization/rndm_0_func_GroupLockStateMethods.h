#pragma once

#include <JuceHeader.h>

class ParamRandomizationOptions;

struct GroupLockStateMethods {
	static const uint8 firstOscParamIndex{ 0 };
	static const uint8 first_VCF_ParamIndex{ 21 };
	static const uint8 first_VCA_ParamIndex{ 27 };
	static const uint8 first_VCF_FM_ParamIndex{ 30 };
	static const uint8 firstPortamentoParamIndex{ 33 };
	static const uint8 keyboardModeParamIndex{ 37 };
	static const uint8 first_LFO_ParamIndex{ 38 };
	static const uint8 firstRampParamIndex{ 56 };
	static const uint8 firstTrackingParamIndex{ 60 };
	static const uint8 firstEnvAmpParamIndex{ 66 };
	static void allParams(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void allOscParams(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void all_VCF_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void all_VCA_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void all_VCF_FM_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void allPortamentoParams(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void all_LFO_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void allRampParams(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void allTrackingParams(ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void allEnvelopeParams(int envNum, ParamRandomizationOptions* randomization, bool shouldBeLocked);
	static void allMatrixModParams(ParamRandomizationOptions* randomization, bool shouldBeLocked);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GroupLockStateMethods)
};