#include "rndm_1_comp_AllowChoiceToggles_MatrixModParam.h"

#include "../constants/constants_MatrixMod.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../matrixMod/mMod_0_build_ChoiceName.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

using MM_ChoiceName = MatrixModParamChoiceName;

AllowChoiceToggles_MatrixModParam::AllowChoiceToggles_MatrixModParam(
	int modNum, MM_Type paramType, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	AllowChoiceToggles_Base{
		paramType == MM_Type::source ? MMOD::numberOfSrcChoices : paramType == MM_Type::amount ? MMOD::numberOfAmtChoices : MMOD::numberOfDestChoices,
		paramType == MM_Type::amount ? 16 : 3,
		paramType == MM_Type::source ? 7 : paramType == MM_Type::amount ? 8 : 11,
		paramType == MM_Type::amount ? 1 : 0,
		paramType == MM_Type::amount ? 24 : 42,
	},
	modNum{ modNum },
	paramType{ paramType },
	matrixModOptions{ exposedParams->matrixModOptions.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ tooltips },
	numberOfChoices{ paramType == MM_Type::source ? MMOD::numberOfSrcChoices : paramType == MM_Type::amount ? MMOD::numberOfAmtChoices : MMOD::numberOfDestChoices }
{
	jassert(modNum < MMOD::numberOfModulators);

	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		allowedChoiceToggles[choiceNum]->setName(buildChoiceName(choiceNum));
		allowedChoiceToggles[choiceNum]->setTooltip(buildTooltip());
	}
}

String AllowChoiceToggles_MatrixModParam::buildChoiceName(uint8 choiceNum) {
	switch (paramType)
	{
	case MM_Type::source:
		return MM_ChoiceName::buildForModSource(choiceNum, ChoiceNameType::concise);
	case MM_Type::amount:
		return MM_ChoiceName::buildForModAmount(choiceNum);
	case MM_Type::destination:
		return MM_ChoiceName::buildForModDest(choiceNum, ChoiceNameType::concise);
	default:
		return "ERR";
	}
}

String AllowChoiceToggles_MatrixModParam::buildTooltip() {
	String tip{ "" };
	if (tooltips->shouldShowDescription()) {
		String paramName{ "Modulator " + (String)modNum };
		paramName += paramType == MM_Type::source ? " Source" : paramType == MM_Type::amount ? " Amount" : " Destination";
		tip += "Click a choice to toggle whether or not it\n";
		tip += "is allowed when generating a random setting\n";
		tip += "for " + paramName + ".\n";
		tip += "CTRL-click a choice to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of choices.\n";
		tip += "ALT-click to allow a range of choices that\n";
		tip += "are all in the same row.";
	}
	return tip;
}

const bool AllowChoiceToggles_MatrixModParam::choiceIsAllowed(uint8 choiceNum) {
	return randomization->choiceIsAllowedForMatrixModParam(choiceNum, modNum, paramType) == true;
}

void AllowChoiceToggles_MatrixModParam::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	randomization->setChoiceIsAllowedForMatrixModParam(choiceNum, shouldBeAllowed, modNum, paramType);
}

void AllowChoiceToggles_MatrixModParam::clearAllowedChoices() {
	randomization->clearAllowedChoicesForMatrixModParam(modNum, paramType);
}

const bool AllowChoiceToggles_MatrixModParam::noChoiceIsAllowed() {
	return randomization->noChoiceIsAllowedForMatrixModParam(modNum, paramType) == true;
}
