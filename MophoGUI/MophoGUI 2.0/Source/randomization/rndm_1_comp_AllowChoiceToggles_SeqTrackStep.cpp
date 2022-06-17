#include "rndm_1_comp_AllowChoiceToggles_SeqTrackStep.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_build_ChoiceNamesValueTree.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using Info = InfoForExposedParameters;



AllowChoiceToggles_SeqTrackStep::AllowChoiceToggles_SeqTrackStep(Track track, Step step, bool destIsPitched, UnexposedParameters* unexposedParams) :
	track{ track },
	step{ step },
	destIsPitched{ destIsPitched },
	randomizationOptions{ unexposedParams->getRandomizationOptions() },
	tooltipOptions{ unexposedParams->getTooltipsOptions() },
	AllowChoiceToggles_Base{ 
		EP::numberOfChoicesForSeqTrackSteps, 
		destIsPitched ? 6 : 13, 
		destIsPitched ? 24 : 10, 
		0,
		destIsPitched ? 38 : 26
	}
{
}

String AllowChoiceToggles_SeqTrackStep::buildChoiceName(uint8 choiceNum) {
	if (destIsPitched)
		return ExposedParamChoiceNamesValueTree::convertIntToSeqStepPitchName(choiceNum);
	else
		return String(choiceNum);
}

String AllowChoiceToggles_SeqTrackStep::buildTooltip() {
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String trackAndStepString{ "" };
	if (step == Step::all)
		trackAndStepString = "all steps in sequencer track " + String((int)track);
	else
		trackAndStepString = "step " + String((int)step) + " in sequencer track " + String((int)track);
	String toggleTooltip{ "" };
	if (shouldShowDescriptions) {
		toggleTooltip += "Click a choice to toggle whether or not it\n";
		toggleTooltip += "is allowed when generating a random setting\n";
		toggleTooltip += "for " + trackAndStepString + ".\n";
		toggleTooltip += "CTRL-click a choice to make it the only one\n";
		toggleTooltip += "ALT-click to allow a range of choices that\n";
		if (destIsPitched)
			toggleTooltip += "are all in the same note row.";
		else
			toggleTooltip += "are all in the same row.";
	}
	return toggleTooltip;
}

const bool AllowChoiceToggles_SeqTrackStep::choiceIsAllowed(uint8 choiceNum) {
	return randomizationOptions->choiceIsAllowedForSeqTrackStep(choiceNum, track, step) == true;
}

void AllowChoiceToggles_SeqTrackStep::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	randomizationOptions->setChoiceIsAllowedForSeqTrackStep(choiceNum, shouldBeAllowed, track, step);
}

void AllowChoiceToggles_SeqTrackStep::clearAllowedChoices() {
	randomizationOptions->clearAllowedChoicesForSeqTrackStep(track, step);
}

const bool AllowChoiceToggles_SeqTrackStep::noChoiceIsAllowed() {
	return randomizationOptions->noChoiceIsAllowedForSeqTrackStep(track, step) == true;
}

void AllowChoiceToggles_SeqTrackStep::restoreToggles() {
	for (auto choiceNum = (uint8)0; choiceNum < EP::numberOfChoicesForSeqTrackSteps; ++choiceNum) {
		auto isAllowed{ randomizationOptions->choiceIsAllowedForSeqTrackStep(choiceNum, track, step) };
		allowedChoiceToggles[choiceNum]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
