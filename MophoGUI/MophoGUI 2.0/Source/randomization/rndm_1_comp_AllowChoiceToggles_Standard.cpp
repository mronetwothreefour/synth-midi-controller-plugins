#include "rndm_1_comp_AllowChoiceToggles_Standard.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



AllowChoiceToggles_Standard::AllowChoiceToggles_Standard(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
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
}

String AllowChoiceToggles_Standard::buildChoiceName(uint8 choiceNum) {
	return Info::get().choiceNameFor(choiceNum, paramIndex);
}

String AllowChoiceToggles_Standard::buildTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String toggleTooltip{ "" };
	if (shouldShowDescriptions) {
		auto paramName{ Info::get().exposedNameFor(paramIndex) };
		toggleTooltip += "Click a choice to toggle whether or not it\n";
		toggleTooltip += "is allowed when generating a random setting\n";
		toggleTooltip += "for " + paramName + ".\n";
		toggleTooltip += "CTRL-click a choice to make it the only one\n";
		toggleTooltip += "allowed. SHIFT-click to allow a range of choices.\n";
		if (Info::get().numberOfAllowChoiceToggleColumnsFor(paramIndex) > 2) {
			toggleTooltip += "ALT-click to allow a range of choices that\n";
			if (Info::get().controlTypeFor(paramIndex) == ControlType::knobForPitch)
				toggleTooltip += "are all in the same note row.";
			else
				toggleTooltip += "are all in the same row.";
		}
	}
	return toggleTooltip;
}

const bool AllowChoiceToggles_Standard::choiceIsAllowed(uint8 choiceNum) {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	return randomizationOptions->choiceIsAllowedForParam(choiceNum, paramIndex) == true;
}

void AllowChoiceToggles_Standard::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	randomizationOptions->setChoiceIsAllowedForParam(choiceNum, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_Standard::clearAllowedChoices() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	randomizationOptions->clearAllowedChoicesForParam(paramIndex);
}

const bool AllowChoiceToggles_Standard::noChoiceIsAllowed() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	return randomizationOptions->noChoiceIsAllowedForParam(paramIndex) == true;
}

void AllowChoiceToggles_Standard::restoreToggles() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		auto isAllowed{ randomizationOptions->choiceIsAllowedForParam(choiceNum, paramIndex) };
		allowedChoiceToggles[choiceNum]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
