#include "rndm_0_func_GroupLockStateMethods.h"

#include "../constants/constants_Enum.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_MatrixMod.h"
#include "../exposedParameters/ep_2_tree_ParamRandomizationOptions.h"

using namespace Matrix_6G_Constants;

void GroupLockStateMethods::allParams(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
	for (int modNum = 0; modNum != MMOD::numberOfModulators; ++modNum) {
		randomization->setMatrixModParamIsLocked(modNum, MM_Type::source, shouldBeLocked ? true : false);
		randomization->setMatrixModParamIsLocked(modNum, MM_Type::amount, shouldBeLocked ? true : false);
		randomization->setMatrixModParamIsLocked(modNum, MM_Type::destination, shouldBeLocked ? true : false);
	}
}

void GroupLockStateMethods::allOscParams(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstOscParamIndex; paramIndex != first_VCF_ParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_VCF_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_VCF_ParamIndex; paramIndex != first_VCA_ParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_VCA_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_VCA_ParamIndex; paramIndex != first_VCF_FM_ParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_VCF_FM_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_VCF_FM_ParamIndex; paramIndex != firstPortamentoParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allPortamentoParams(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstPortamentoParamIndex; paramIndex != keyboardModeParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::all_LFO_Params(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = first_LFO_ParamIndex; paramIndex != firstRampParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allRampParams(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstRampParamIndex; paramIndex != firstTrackingParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allTrackingParams(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (auto paramIndex = firstTrackingParamIndex; paramIndex != firstEnvAmpParamIndex; ++paramIndex)
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
}

void GroupLockStateMethods::allEnvelopeParams(int envNum, ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	jassert(envNum > 0 && envNum < 4);
	auto firstEnvAmpParam{ uint8(firstEnvAmpParamIndex + (envNum - 1) * 10) };
	for (auto i = 0; i != 10; ++i) {
		auto paramIndex{ uint8(firstEnvAmpParam + i) };
		randomization->setParamIsLocked(paramIndex, shouldBeLocked ? true : false);
	}
}

void GroupLockStateMethods::allMatrixModParams(ParamRandomizationOptions* randomization, bool shouldBeLocked) {
	for (int modNum = 0; modNum != MMOD::numberOfModulators; ++modNum) {
		randomization->setMatrixModParamIsLocked(modNum, MM_Type::source, shouldBeLocked ? true : false);
		randomization->setMatrixModParamIsLocked(modNum, MM_Type::amount, shouldBeLocked ? true : false);
		randomization->setMatrixModParamIsLocked(modNum, MM_Type::destination, shouldBeLocked ? true : false);
	}
}
