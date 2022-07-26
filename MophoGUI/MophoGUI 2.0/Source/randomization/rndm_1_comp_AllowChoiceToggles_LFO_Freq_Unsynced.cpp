#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Unsynced.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

AllowChoiceToggles_LFO_Freq_Unsynced::AllowChoiceToggles_LFO_Freq_Unsynced(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	numberOfFreq{ EP::numberOfUnsynced_LFO_Frequencies },
	AllowChoiceToggles_Base{ numberOfFreq, 9, 10, 0, 20 }
{
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	for (auto freq = (uint8)0; freq < numberOfFreq; ++freq) {
		allowedChoiceToggles[freq]->setName(buildChoiceName(freq));
		allowedChoiceToggles[freq]->setTooltip(buildTooltip());
		allowedChoiceToggles[freq]->setToggleState(randomization->unsyncedFreqIsAllowedFor_LFO_FreqParam(freq, paramIndex), dontSendNotification);
	}
}

String AllowChoiceToggles_LFO_Freq_Unsynced::buildChoiceName(uint8 unsyncedFreq) {
	return (String)unsyncedFreq;
}

String AllowChoiceToggles_LFO_Freq_Unsynced::buildTooltip() {
	String tip{ "" };
	if (tooltips->shouldShowDescription()) {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto lfoNumString{ paramID.fromFirstOccurrenceOf("LFO_", false, false).upToFirstOccurrenceOf("_Freq", false, false) };
		tip += "Click an un-synced frequency to toggle whether or not it\n";
		tip += "is allowed when generating a random frequency for LFO " + lfoNumString + ".\n";
		tip += "CTRL-click an un-synced frequency to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of un-synced frequencies.\n";
		tip += "ALT-click to allow a range of un-synced frequencies that are\n";
		tip += "all in the same row.";
	}
	return tip;
}

const bool AllowChoiceToggles_LFO_Freq_Unsynced::choiceIsAllowed(uint8 unsyncedFreq) {
	return randomization->unsyncedFreqIsAllowedFor_LFO_FreqParam(unsyncedFreq, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Unsynced::setChoiceIsAllowed(uint8 unsyncedFreq, bool shouldBeAllowed) {
	randomization->setUnsyncedFreqIsAllowedFor_LFO_FreqParam(unsyncedFreq, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Unsynced::clearAllowedChoices() {
	randomization->clearAllowedUnsyncedFreqForParam(paramIndex);
}

const bool AllowChoiceToggles_LFO_Freq_Unsynced::noChoiceIsAllowed() {
	return randomization->noUnsyncedFreqIsAllowedFor_LFO_FreqParam(paramIndex) == true;
}

void AllowChoiceToggles_LFO_Freq_Unsynced::restoreToggles() {
	for (auto unsyncedFreq = (uint8)0; unsyncedFreq < numberOfFreq; ++unsyncedFreq) {
		auto isAllowed{ randomization->unsyncedFreqIsAllowedFor_LFO_FreqParam(unsyncedFreq, paramIndex) };
		allowedChoiceToggles[unsyncedFreq]->setToggleState(isAllowed ? true : false, dontSendNotification);
		allowedChoiceToggles[unsyncedFreq]->setEnabled(true);
	}
}
