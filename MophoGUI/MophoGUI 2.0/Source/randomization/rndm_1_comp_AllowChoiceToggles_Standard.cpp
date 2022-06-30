#include "rndm_1_comp_AllowChoiceToggles_Standard.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



AllowChoiceToggles_Standard::AllowChoiceToggles_Standard(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	randomization{ unexposedParams->getRandomizationOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	numberOfChoices{ Info::get().numberOfChoicesFor(paramIndex) },
	AllowChoiceToggles_Base{
		numberOfChoices,
		Info::get().numberOfAllowChoiceToggleColumnsFor(paramIndex),
		Info::get().numberOfAllowChoiceToggleRowsFor(paramIndex),
		Info::get().firstAllowChoiceToggleRowFor(paramIndex),
		Info::get().widthOfAllowChoiceToggleColumnFor(paramIndex)
	}
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::standard);
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		allowedChoiceToggles[choiceNum]->setName(buildChoiceName(choiceNum));
		allowedChoiceToggles[choiceNum]->setTooltip(buildTooltip());
		allowedChoiceToggles[choiceNum]->setToggleState(randomization->choiceIsAllowedForParam(choiceNum, paramIndex), dontSendNotification);
	}
}

String AllowChoiceToggles_Standard::buildChoiceName(uint8 choiceNum) {
	return Info::get().choiceNameFor(choiceNum, paramIndex);
}

String AllowChoiceToggles_Standard::buildTooltip() {
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };
	String tip{ "" };
	if (shouldShowDescriptions) {
		auto paramName{ Info::get().exposedNameFor(paramIndex) };
		tip += "Click a choice to toggle whether or not it\n";
		tip += "is allowed when generating a random setting\n";
		tip += "for " + paramName + ".\n";
		tip += "CTRL-click a choice to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of choices.\n";
		if (Info::get().numberOfAllowChoiceToggleColumnsFor(paramIndex) > 2) {
			tip += "ALT-click to allow a range of choices that\n";
			if (Info::get().controlTypeFor(paramIndex) == ControlType::knobForPitch)
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
