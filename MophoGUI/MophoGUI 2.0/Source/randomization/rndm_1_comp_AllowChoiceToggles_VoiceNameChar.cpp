#include "rndm_1_comp_AllowChoiceToggles_VoiceNameChar.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

AllowChoiceToggles_VoiceNameChar::AllowChoiceToggles_VoiceNameChar(
	uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ tooltips },
	numberOfChoices{ 96 },
	AllowChoiceToggles_Base{ numberOfChoices, 10, 10, 4, 20 }
{
	jassert(paramIndex < EP::numberOfExposedParams);
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::voiceNameChar);
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		allowedChoiceToggles[choiceNum]->setName(buildChoiceName(choiceNum));
		allowedChoiceToggles[choiceNum]->setTooltip(buildTooltip());
	}
	restoreToggles();
}

String AllowChoiceToggles_VoiceNameChar::buildChoiceName(uint8 choiceNum) {
	choiceNum += EP::firstVisibleVoiceNameCharNumber;
	return info->choiceNameFor(choiceNum, paramIndex);
}

String AllowChoiceToggles_VoiceNameChar::buildTooltip() {
	String tip{ "" };
	if (tooltips->shouldShowDescription()) {
		auto paramName{ info->exposedNameFor(paramIndex) };
		tip += "Click a character to toggle whether or not it\n";
		tip += "is allowed when generating a random setting\n";
		tip += "for " + paramName + ".\n";
		tip += "CTRL-click a choice to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of choices.\n";
	}
	return tip;
}

const bool AllowChoiceToggles_VoiceNameChar::choiceIsAllowed(uint8 choiceNum) {
	jassert(choiceNum < numberOfChoices);
	return randomization->choiceIsAllowedForVoiceNameCharParam(choiceNum, paramIndex) == true;
}

void AllowChoiceToggles_VoiceNameChar::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	jassert(choiceNum < numberOfChoices);
	randomization->setChoiceIsAllowedForVoiceNameCharParam(choiceNum, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_VoiceNameChar::clearAllowedChoices() {
	randomization->clearAllowedChoicesForVoiceNameCharParam(paramIndex);
}

const bool AllowChoiceToggles_VoiceNameChar::noChoiceIsAllowed() {
	return randomization->noChoiceIsAllowedForParam(paramIndex) == true;
}

void AllowChoiceToggles_VoiceNameChar::restoreToggles() {
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		auto isAllowed{ randomization->choiceIsAllowedForVoiceNameCharParam(choiceNum, paramIndex) };
		allowedChoiceToggles[choiceNum]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
