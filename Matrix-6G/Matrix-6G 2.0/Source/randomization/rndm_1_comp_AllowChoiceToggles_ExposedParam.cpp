#include "rndm_1_comp_AllowChoiceToggles_ExposedParam.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

AllowChoiceToggles_ExposedParam::AllowChoiceToggles_ExposedParam(
	uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	AllowChoiceToggles_Base{
		exposedParams->info->numberOfChoicesFor(paramIndex),
		exposedParams->info->numberOfAllowChoiceToggleColumnsFor(paramIndex),
		exposedParams->info->numberOfAllowChoiceToggleRowsFor(paramIndex),
		exposedParams->info->firstAllowChoiceToggleRowFor(paramIndex),
		exposedParams->info->widthOfAllowChoiceToggleColumnFor(paramIndex)
	},
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ tooltips },
	numberOfChoices{ info->numberOfChoicesFor(paramIndex) },
	rangeIsSigned{ info->choiceNameFor(0, paramIndex).startsWith("-") ? true : false }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->numberOfChoicesFor(paramIndex) > 2);

	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		allowedChoiceToggles[choiceNum]->setName(buildChoiceName(choiceNum));
		allowedChoiceToggles[choiceNum]->setTooltip(buildTooltip());
	}

	if (rangeIsSigned && randomization->transmitMethodIsQuickEdit()) {
		auto numberOfNegativeValues{ numberOfChoices == 63 ? 31 : 63 };
		for (auto choiceNum = 0; choiceNum != numberOfNegativeValues; ++choiceNum)
			allowedChoiceToggles[choiceNum]->setEnabled(false);
	}
}

String AllowChoiceToggles_ExposedParam::buildChoiceName(uint8 choiceNum) {
	return info->choiceNameFor(choiceNum, paramIndex);
}

String AllowChoiceToggles_ExposedParam::buildTooltip() {
	String tip{ "" };
	if (tooltips->shouldShowDescription()) {
		auto paramName{ info->exposedNameFor(paramIndex) };
		tip += "Click a choice to toggle whether or not it\n";
		tip += "is allowed when generating a random setting\n";
		tip += "for " + paramName + ".\n";
		tip += "CTRL-click a choice to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of choices.\n";
		if (info->numberOfAllowChoiceToggleColumnsFor(paramIndex) > 2) {
			tip += "ALT-click to allow a range of choices that\n";
			if (info->IDfor(paramIndex) == ID::ep_00_Osc_1_Pitch || info->IDfor(paramIndex) == ID::ep_10_Osc_2_Pitch)
				tip += "are all in the same note row.";
			else
				tip += "are all in the same row.";
		}
		if (rangeIsSigned && randomization->transmitMethodIsQuickEdit()) {
			tip += "When the transmit message type is set to QUICK,\n";
			tip += "negative values cannot be generated.";
		}
	}
	return tip;
}

const bool AllowChoiceToggles_ExposedParam::choiceIsAllowed(uint8 choiceNum) {
	return randomization->choiceIsAllowedForParam(choiceNum, paramIndex) == true;
}

void AllowChoiceToggles_ExposedParam::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	randomization->setChoiceIsAllowedForParam(choiceNum, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_ExposedParam::clearAllowedChoices() {
	randomization->clearAllowedChoicesForParam(paramIndex);
}

const bool AllowChoiceToggles_ExposedParam::noChoiceIsAllowed() {
	return randomization->noChoiceIsAllowedForParam(paramIndex) == true;
}

void AllowChoiceToggles_ExposedParam::restoreToggles() {
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		auto isAllowed{ randomization->choiceIsAllowedForParam(choiceNum, paramIndex) };
		allowedChoiceToggles[choiceNum]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}