#include "rndm_0_func_GroupLockStateMethods.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"

using namespace P_600_G_Constants;

void GroupLockStateMethods::allParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allOsc_A_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstOsc_A_ParamIndex; paramIndex != firstOsc_B_ParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allOsc_B_Params(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstOsc_B_ParamIndex; paramIndex != mixerParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allFilterParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstFilterParamIndex; paramIndex != firstAmpParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allAmpParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstAmpParamIndex; paramIndex != firstPolyModParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allPolyModParams(ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstPolyModParamIndex; paramIndex != unisonParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_LFO_Params(int lfoNum, ExposedParamsRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_LFO_ParamIndex; paramIndex != EP::numberOfExposedParams; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}
