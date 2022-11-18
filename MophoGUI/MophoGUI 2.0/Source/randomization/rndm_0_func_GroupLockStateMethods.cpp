#include "rndm_0_func_GroupLockStateMethods.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Voices.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"

void GroupLockStateMethods::allParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allOscParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstOscParamIndex; paramIndex != first_LPF_ParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_LPF_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_LPF_ParamIndex; paramIndex != first_VCA_ParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_VCA_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_VCA_ParamIndex; paramIndex != first_LFO_FreqParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_LFO_Params(int lfoNum, ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	jassert(lfoNum > 0 && lfoNum < 5);
	auto firstLFO_FreqParam{ uint8(first_LFO_FreqParamIndex + (lfoNum - 1) * 5) };
	for (auto i = 0; i != 5; ++i) {
		auto paramIndex{ uint8(firstLFO_FreqParam + i) };
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
	}
}

void GroupLockStateMethods::allEnv_3_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstEnv_3_ParamIndex; paramIndex != firstModulatorParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allModulatorParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstModulatorParamIndex; paramIndex != first_MIDI_ControllerParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_MIDI_ControllerParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_MIDI_ControllerParamIndex; paramIndex != firstPushItParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allPushItParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstPushItParamIndex; paramIndex != firstPushItParamIndex + 3; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allKnobAssignParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = EP::firstKnobAssignParamIndex; paramIndex != EP::firstKnobAssignParamIndex + 4; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allSeqTrackParams(Track track, ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	auto trackNum{ (int)track - 1 };
	auto trackDestIndex{ uint8(EP::firstSeqTrackDestParamIndex + trackNum) };
	randomization->setParamIsLocked(trackDestIndex, shouldBeLocked ? true : false);
	auto firstSeqStepParam{ uint8(EP::firstSeqStepParamIndex + trackNum * 16) };
	for (auto i = 0; i != 16; ++i) {
		auto paramIndex{ uint8(firstSeqStepParam + i) };
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
	}
}

void GroupLockStateMethods::allVoiceNameChars(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = EP::firstVoiceNameCharParamIndex; paramIndex != EP::firstVoiceNameCharParamIndex + VCS::numberOfCharsInVoiceName; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}
