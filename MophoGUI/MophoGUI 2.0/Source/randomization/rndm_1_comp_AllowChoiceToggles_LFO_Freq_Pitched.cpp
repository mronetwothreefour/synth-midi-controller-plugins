#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Pitched.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_0_build_ChoiceNamesValueTree.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

AllowChoiceToggles_LFO_Freq_Pitched::AllowChoiceToggles_LFO_Freq_Pitched(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ tooltips },
	numberOfFreq{ EP::numberOfPitched_LFO_Frequencies },
	AllowChoiceToggles_Base{ numberOfFreq, 6, 12, 0, 36 }
{
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	for (auto freq = (uint8)0; freq < numberOfFreq; ++freq) {
		allowedChoiceToggles[freq]->setName(buildChoiceName(freq));
		allowedChoiceToggles[freq]->setTooltip(buildTooltip());
		allowedChoiceToggles[freq]->setToggleState(randomization->pitchedFreqIsAllowedFor_LFO_FreqParam(freq, paramIndex), dontSendNotification);
	}
}

String AllowChoiceToggles_LFO_Freq_Pitched::buildChoiceName(uint8 pitchedFreq) {
	return ExposedParamChoiceNamesValueTree::convertIntToPitchName(pitchedFreq);
}

String AllowChoiceToggles_LFO_Freq_Pitched::buildTooltip() {
	String tip{ "" };
	if (tooltips->shouldShowDescription()) {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto lfoNumString{ paramID.fromFirstOccurrenceOf("LFO_", false, false).upToFirstOccurrenceOf("_Freq", false, false) };
		tip += "Click a pitched frequency to toggle whether or not it\n";
		tip += "is allowed when generating a random frequency for LFO " + lfoNumString + ".\n";
		tip += "CTRL-click a pitched frequency to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of pitched frequencies.\n";
		tip += "ALT-click to allow a range of pitched frequencies that are\n";
		tip += "all in the same note row.";
	}
	return tip;
}

const bool AllowChoiceToggles_LFO_Freq_Pitched::choiceIsAllowed(uint8 pitchedFreq) {
	return randomization->pitchedFreqIsAllowedFor_LFO_FreqParam(pitchedFreq, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Pitched::setChoiceIsAllowed(uint8 pitchedFreq, bool shouldBeAllowed) {
	randomization->setPitchedFreqIsAllowedFor_LFO_FreqParam(pitchedFreq, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Pitched::clearAllowedChoices() {
	randomization->clearAllowedPitchedFreqForParam(paramIndex);
}

const bool AllowChoiceToggles_LFO_Freq_Pitched::noChoiceIsAllowed() {
	return randomization->noPitchedFreqIsAllowedFor_LFO_FreqParam(paramIndex) == true;
}

void AllowChoiceToggles_LFO_Freq_Pitched::restoreToggles() {
	for (auto pitchedFreq = (uint8)0; pitchedFreq < numberOfFreq; ++pitchedFreq) {
		auto isAllowed{ randomization->pitchedFreqIsAllowedFor_LFO_FreqParam(pitchedFreq, paramIndex) };
		allowedChoiceToggles[pitchedFreq]->setToggleState(isAllowed ? true : false, dontSendNotification);
		allowedChoiceToggles[pitchedFreq]->setEnabled(true);
	}
}
