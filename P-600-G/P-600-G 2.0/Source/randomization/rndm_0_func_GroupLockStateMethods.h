#include <JuceHeader.h>

class ExposedParamsRandomizationOptions;

struct GroupLockStateMethods {
	static const uint8 firstOsc_A_ParamIndex{ 0 };
	static const uint8 firstOsc_B_ParamIndex{ 6 };
	static const uint8 mixerParamIndex{ 12 };
	static const uint8 firstFilterParamIndex{ 14 };
	static const uint8 firstAmpParamIndex{ 22 };
	static const uint8 firstPolyModParamIndex{ 26 };
	static const uint8 unisonParamIndex{ 30 };
	static const uint8 first_LFO_ParamIndex{ 31 };
	static void allParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allOsc_A_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allOsc_B_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allFilterParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allAmpParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allPolyModParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void all_LFO_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GroupLockStateMethods)
};