#pragma once

#include <JuceHeader.h>

#include "../constants/constants_Enum.h"

using namespace MophoConstants;
using Track = SeqTrackNum;



class ExposedParamsRandomizationOptions;

struct GroupLockStateMethods {
	static const uint8 firstOscParamIndex{ 0 };
	static const uint8 firstLPF_ParamIndex{ 20 };
	static const uint8 firstVCA_ParamIndex{ 32 };
	static const uint8 firstLFO_FreqParamIndex{ 41 };
	static const uint8 firstEnv_3_ParamIndex{ 61 };
	static const uint8 firstModulatorParamIndex{ 70 };
	static const uint8 firstMIDI_ControllerParamIndex{ 82 };
	static const uint8 firstPushItParamIndex{ 92 };
	static void allParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allOscParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allLPF_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allVCA_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allLFO_Params(int lfoNum, ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allEnv_3_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allModulatorParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allMIDI_ControllerParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allPushItParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allKnobAssignParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allSeqTrackParams(Track track, ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
	static void allVoiceNameChars(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked);
};