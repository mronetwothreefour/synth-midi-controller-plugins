#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Pitched.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_build_ChoiceNamesValueTree.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



AllowChoiceToggles_LFO_Freq_Pitched::AllowChoiceToggles_LFO_Freq_Pitched(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	randomization{ unexposedParams->getRandomizationOptions() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	numberOfFreq{ EP::numberOfPitchedLFO_Frequencies },
	AllowChoiceToggles_Base{ numberOfFreq, 6, 12, 0, 36 }
{
	jassert(Info::get().allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	for (auto freq = (uint8)0; freq < numberOfFreq; ++freq) {
		allowedChoiceToggles[freq]->setName(buildChoiceName(freq));
		allowedChoiceToggles[freq]->setTooltip(buildTooltip());
		allowedChoiceToggles[freq]->setToggleState(randomization->pitchedFreqIsAllowedForLFO_FreqParam(freq, paramIndex), dontSendNotification);
	}
}

String AllowChoiceToggles_LFO_Freq_Pitched::buildChoiceName(uint8 pitchedFreq) {
	return ExposedParamChoiceNamesValueTree::convertIntToPitchName(pitchedFreq);
}

String AllowChoiceToggles_LFO_Freq_Pitched::buildTooltip() {
	auto shouldShowDescriptions{ tooltips->shouldShowDescriptions() };
	String tip{ "" };
	if (shouldShowDescriptions) {
		auto paramID{ Info::get().IDfor(paramIndex).toString() };
		auto lfoNumString{ paramID.fromFirstOccurrenceOf("LFO_", false, false).upToFirstOccurrenceOf("_Freq", false, false) };
		tip += "Click a pitched frequency to toggle whether or not it\n";
		tip += "is allowed when generating a random frequency for LFO " + lfoNumString + ".\n";
		tip += "CTRL-click a pitched frequency to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of pitched frequencies.\n";
		tip += "ALT-click to allow a range of pitched frequencies that are";
		tip += "all in the same note row.";
	}
	return tip;
}

const bool AllowChoiceToggles_LFO_Freq_Pitched::choiceIsAllowed(uint8 pitchedFreq) {
	return randomization->pitchedFreqIsAllowedForLFO_FreqParam(pitchedFreq, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Pitched::setChoiceIsAllowed(uint8 pitchedFreq, bool shouldBeAllowed) {
	randomization->setPitchedFreqIsAllowedForLFO_FreqParam(pitchedFreq, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Pitched::clearAllowedChoices() {
	randomization->clearAllowedPitchedFreqForParam(paramIndex);
}

const bool AllowChoiceToggles_LFO_Freq_Pitched::noChoiceIsAllowed() {
	return randomization->noPitchedFreqIsAllowedForLFO_FreqParam(paramIndex) == true;
}

void AllowChoiceToggles_LFO_Freq_Pitched::restoreToggles() {
	for (auto pitchedFreq = (uint8)0; pitchedFreq < numberOfFreq; ++pitchedFreq) {
		auto isAllowed{ randomization->pitchedFreqIsAllowedForLFO_FreqParam(pitchedFreq, paramIndex) };
		allowedChoiceToggles[pitchedFreq]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
