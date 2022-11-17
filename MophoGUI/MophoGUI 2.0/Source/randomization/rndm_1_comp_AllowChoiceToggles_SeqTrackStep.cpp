#include "rndm_1_comp_AllowChoiceToggles_SeqTrackStep.h"

#include "../constants/constants_ExposedParameters.h"
#include "../exposedParameters/ep_0_build_ChoiceNamesValueTree.h"
#include "../exposedParameters/ep_2_tree_ExposedParamsRandomizationOptions.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

AllowChoiceToggles_SeqTrackStep::AllowChoiceToggles_SeqTrackStep(
	Track track, bool destIsPitched, ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips) :
	track{ track },
	step{ randomization->targetStepForSeqTrack(track) },
	destIsPitched{ destIsPitched },
	randomization{ randomization },
	tooltips{ tooltips },
	AllowChoiceToggles_Base{ 
		EP::numberOfChoicesForSeqTrackSteps, 
		destIsPitched ? 6 : 13, 
		destIsPitched ? 24 : 10, 
		0,
		destIsPitched ? 38 : 26
	}
{
	for (auto choiceNum = (uint8)0; choiceNum < EP::numberOfChoicesForSeqTrackSteps; ++choiceNum) {
		allowedChoiceToggles[choiceNum]->setName(buildChoiceName(choiceNum));
		allowedChoiceToggles[choiceNum]->setTooltip(buildTooltip());
		allowedChoiceToggles[choiceNum]->setToggleState(randomization->choiceIsAllowedForSeqTrackStep(choiceNum, track, step), dontSendNotification);
	}
}

String AllowChoiceToggles_SeqTrackStep::buildChoiceName(uint8 choiceNum) {
	if (destIsPitched)
		return ExposedParamChoiceNamesValueTree::convertIntToSeqStepPitchName(choiceNum);
	else
		return String(choiceNum);
}

String AllowChoiceToggles_SeqTrackStep::buildTooltip() {
	String trackAndStepString{ "" };
	if (step == Step::all)
		trackAndStepString = "all steps in sequencer track " + String((int)track);
	else
		trackAndStepString = "step " + String((int)step) + " in sequencer track " + String((int)track);
	String tip{ "" };
	if (tooltips->shouldShowDescription()) {
		tip += "Click a choice to toggle whether or not it\n";
		tip += "is allowed when generating a random setting\n";
		tip += "for " + trackAndStepString + ".\n";
		tip += "CTRL-click a choice to make it the only one\n";
		tip += "ALT-click to allow a range of choices that\n";
		if (destIsPitched)
			tip += "are all in the same note row.";
		else
			tip += "are all in the same row.";
	}
	return tip;
}

const bool AllowChoiceToggles_SeqTrackStep::choiceIsAllowed(uint8 choiceNum) {
	return randomization->choiceIsAllowedForSeqTrackStep(choiceNum, track, step) == true;
}

void AllowChoiceToggles_SeqTrackStep::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	if (step == Step::all)
		randomization->setChoiceIsAllowedForAllSeqTrackSteps(choiceNum, shouldBeAllowed, track);
	else
		randomization->setChoiceIsAllowedForSeqTrackStep(choiceNum, shouldBeAllowed, track, step);
}

void AllowChoiceToggles_SeqTrackStep::clearAllowedChoices() {
	if (step == Step::all)
		randomization->clearAllowedChoicesForAllSeqTrackSteps(track);
	else
		randomization->clearAllowedChoicesForSeqTrackStep(track, step);
}

const bool AllowChoiceToggles_SeqTrackStep::noChoiceIsAllowed() {
	return randomization->noChoiceIsAllowedForSeqTrackStep(track, step) == true;
}

void AllowChoiceToggles_SeqTrackStep::restoreToggles() {
	for (auto choiceNum = (uint8)0; choiceNum < EP::numberOfChoicesForSeqTrackSteps; ++choiceNum) {
		auto isAllowed{ randomization->choiceIsAllowedForSeqTrackStep(choiceNum, track, step) };
		allowedChoiceToggles[choiceNum]->setToggleState(isAllowed ? true : false, dontSendNotification);
	}
}
