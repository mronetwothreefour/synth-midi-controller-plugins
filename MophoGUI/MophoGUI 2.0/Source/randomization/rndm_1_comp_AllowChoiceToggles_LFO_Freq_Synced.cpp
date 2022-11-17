#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Synced.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

AllowChoiceToggles_LFO_Freq_Synced::AllowChoiceToggles_LFO_Freq_Synced(uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ tooltips },
	numberOfFreq{ EP::numberOfSynced_LFO_Frequencies },
	AllowChoiceToggles_Base{ numberOfFreq, 2, 8, 0, 100 }
{
	jassert(info->allowedChoicesTypeFor(paramIndex) == AllowedChoicesType::lfoFreq);
	for (auto freq = (uint8)0; freq < numberOfFreq; ++freq) {
		allowedChoiceToggles[freq]->setName(buildChoiceName(freq));
		allowedChoiceToggles[freq]->setTooltip(buildTooltip());
		allowedChoiceToggles[freq]->setToggleState(randomization->syncedFreqIsAllowedFor_LFO_FreqParam(freq, paramIndex), dontSendNotification);
	}
}

String AllowChoiceToggles_LFO_Freq_Synced::buildChoiceName(uint8 syncedFreq) {
	String choiceName{ "" };
	switch (syncedFreq)
	{
	case (uint8)0:
		choiceName = "1  cycle : 32 steps";
		break;
	case (uint8)1:
		choiceName = "1  cycle : 16 steps";
		break;
	case (uint8)2:
		choiceName = "1  cycle : 8 steps";
		break;
	case (uint8)3:
		choiceName = "1  cycle : 6 steps";
		break;
	case (uint8)4:
		choiceName = "1  cycle : 4 steps";
		break;
	case (uint8)5:
		choiceName = "1  cycle : 3 steps";
		break;
	case (uint8)6:
		choiceName = "1  cycle : 2 steps";
		break;
	case (uint8)7:
		choiceName = "1  cycle : 1.5 steps";
		break;
	case (uint8)8:
		choiceName = "1  cycle : 1 step";
		break;
	case (uint8)9:
		choiceName = "3  cycles : 2 steps";
		break;
	case (uint8)10:
		choiceName = "2  cycles : 1 step";
		break;
	case (uint8)11:
		choiceName = "3  cycles : 1 step";
		break;
	case (uint8)12:
		choiceName = "4  cycles : 1 step";
		break;
	case (uint8)13:
		choiceName = "6  cycles : 1 step";
		break;
	case (uint8)14:
		choiceName = "8  cycles : 1 step";
		break;
	case (uint8)15:
		choiceName = "16  cycles : 1 step";
		break;
	default:
		choiceName = "error";
		break;
	}
	return choiceName;
}

String AllowChoiceToggles_LFO_Freq_Synced::buildTooltip() {
	auto shouldShowDescriptions{ tooltips->shouldShowDescription() };
	String tip{ "" };
	if (shouldShowDescriptions) {
		auto paramID{ info->IDfor(paramIndex).toString() };
		auto lfoNumString{ paramID.fromFirstOccurrenceOf("LFO_", false, false).upToFirstOccurrenceOf("_Freq", false, false) };
		tip += "Click a synced frequency to toggle whether or not it\n";
		tip += "is allowed when generating a random frequency for LFO " + lfoNumString + ".\n";
		tip += "CTRL-click a synced frequency to make it the only one\n";
		tip += "allowed. SHIFT-click to allow a range of synced frequencies.\n";
	}
	return tip;
}

const bool AllowChoiceToggles_LFO_Freq_Synced::choiceIsAllowed(uint8 syncedFreq) {
	return randomization->syncedFreqIsAllowedFor_LFO_FreqParam(syncedFreq, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Synced::setChoiceIsAllowed(uint8 syncedFreq, bool shouldBeAllowed) {
	randomization->setSyncedFreqIsAllowedFor_LFO_FreqParam(syncedFreq, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles_LFO_Freq_Synced::clearAllowedChoices() {
	randomization->clearAllowedSyncedFreqForParam(paramIndex);
}

const bool AllowChoiceToggles_LFO_Freq_Synced::noChoiceIsAllowed() {
	return randomization->noSyncedFreqIsAllowedFor_LFO_FreqParam(paramIndex) == true;
}

void AllowChoiceToggles_LFO_Freq_Synced::restoreToggles() {
	for (auto syncedFreq = (uint8)0; syncedFreq < numberOfFreq; ++syncedFreq) {
		auto isAllowed{ randomization->syncedFreqIsAllowedFor_LFO_FreqParam(syncedFreq, paramIndex) };
		allowedChoiceToggles[syncedFreq]->setToggleState(isAllowed ? true : false, dontSendNotification);
		allowedChoiceToggles[syncedFreq]->setEnabled(true);
	}
}
