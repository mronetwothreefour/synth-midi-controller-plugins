#include "rndm_1_comp_AllowChoiceToggles_Standard.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

AllowChoiceToggles_Standard::AllowChoiceToggles_Standard(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	numberOfChoices{ exposedParams->info->numberOfChoicesFor(paramIndex) },
	AllowChoiceToggles_Base{
		exposedParams->info->numberOfChoicesFor(paramIndex),
		exposedParams->info->numberOfAllowChoiceToggleColumnsFor(paramIndex),
		exposedParams->info->numberOfAllowChoiceToggleRowsFor(paramIndex),
		exposedParams->info->firstAllowChoiceToggleRowFor(paramIndex),
		exposedParams->info->widthOfAllowChoiceToggleColumnFor(paramIndex)
	}
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		allowedChoiceToggles[choiceNum]->setName(buildChoiceName(choiceNum));
		allowedChoiceToggles[choiceNum]->setTooltip(buildTooltip());
	}
	restoreToggles();
}

String AllowChoiceToggles_Standard::buildChoiceName(uint8 choiceNum) {
	return info->choiceNameFor(choiceNum, paramIndex);
}

String AllowChoiceToggles_Standard::buildTooltip() {
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
			if (info->controlTypeFor(paramIndex) == ControlType::knobForPitch)
				tip += "are all in the same note row.";
			else
				tip += "are all in the same row.";
		}
	}
	return tip;
}

const bool AllowChoiceToggles_Standard::choiceIsAllowed(uint8 choiceNum) {
	return randomization->choiceIsAllowedForParam(choiceNum, paramIndex) == true;
}

void AllowChoiceToggles_Standard::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	randomization->setChoiceIsAllowedForParam(choiceNum, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_Standard::clearAllowedChoices() {
	randomization->clearAllowedChoicesForParam(paramIndex);
}

const bool AllowChoiceToggles_Standard::noChoiceIsAllowed() {
	return randomization->noChoiceIsAllowedForParam(paramIndex) == true;
}

void AllowChoiceToggles_Standard::restoreToggles() {
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		auto isAllowed{ randomization->choiceIsAllowedForParam(choiceNum, paramIndex) };
		allowedChoiceToggles[choiceNum]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
