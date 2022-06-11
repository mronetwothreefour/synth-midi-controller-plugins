#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Unsynced.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



AllowChoiceToggles_LFO_Freq_Unsynced::AllowChoiceToggles_LFO_Freq_Unsynced(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	numberOfFreq{ EP::numberOfUnsyncedLFO_Frequencies },
	AllowChoiceToggles_Base{ numberOfFreq, 9, 10, 0, 20 }
{
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
}

String AllowChoiceToggles_LFO_Freq_Unsynced::buildChoiceName(uint8 unsyncedFreq) {
	return (String)unsyncedFreq;
}

String AllowChoiceToggles_LFO_Freq_Unsynced::buildTooltip() {
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String toggleTooltip{ "" };
	if (shouldShowDescriptions) {
		auto paramID{ Info::get().IDfor(paramIndex).toString() };
		auto lfoNumString{ paramID.fromFirstOccurrenceOf("LFO_", false, false).upToFirstOccurrenceOf("_Freq", false, false) };
		toggleTooltip += "Click an un-synced frequency to toggle whether or not it\n";
		toggleTooltip += "is allowed when generating a random frequency for LFO " + lfoNumString + ".\n";
		toggleTooltip += "CTRL-click an un-synced frequency to make it the only one\n";
		toggleTooltip += "allowed. SHIFT-click to allow a range of un-synced frequencies.\n";
		toggleTooltip += "ALT-click to allow a range of un-synced frequencies that are";
		toggleTooltip += "all in the same row.";
	}
	return toggleTooltip;
}

const bool AllowChoiceToggles_LFO_Freq_Unsynced::choiceIsAllowed(uint8 unsyncedFreq) {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	return randomizationOptions->unsyncedFreqIsAllowedForLFO_FreqParam(unsyncedFreq, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Unsynced::setChoiceIsAllowed(uint8 unsyncedFreq, bool shouldBeAllowed) {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	randomizationOptions->setUnsyncedFreqIsAllowedForLFO_FreqParam(unsyncedFreq, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Unsynced::clearAllowedChoices() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	randomizationOptions->clearAllowedUnsyncedFreqForParam(paramIndex);
}

const bool AllowChoiceToggles_LFO_Freq_Unsynced::noChoiceIsAllowed() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	return randomizationOptions->noUnsyncedFreqIsAllowedForLFO_FreqParam(paramIndex) == true;
}

void AllowChoiceToggles_LFO_Freq_Unsynced::restoreToggles() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	for (auto unsyncedFreq = (uint8)0; unsyncedFreq < numberOfFreq; ++unsyncedFreq) {
		auto isAllowed{ randomizationOptions->unsyncedFreqIsAllowedForLFO_FreqParam(unsyncedFreq, paramIndex) };
		allowedChoiceToggles[unsyncedFreq]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
