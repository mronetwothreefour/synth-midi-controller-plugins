#include "randomization_AllowedNotesAndBentNotesComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



AllowedNotesAndBentNotesComponent::AllowedNotesAndBentNotesComponent(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToAllowedPitchesTree(this);
	randomizationOptions->addListenerToSeqTrackOptionsTree(this);
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };

	for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "ForSeqTrack" + (String)trackNum + "_Note" + String(noteNum) };
		allowedNoteToggles[noteNum].setComponentID(toggleID);
		bool noteIsAllowed;
		if (editModeIsSelectedStep) {
			auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
			auto& info{ InfoForExposedParameters::get() };
			auto paramIndex{ info.indexForParamID(paramID) };
			noteIsAllowed = randomizationOptions->noteIsAllowedForParam(noteNum, paramIndex);
		}
		else
			noteIsAllowed = randomizationOptions->noteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum);
		allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
		allowedNoteToggles[noteNum].addListener(this);
		addAndMakeVisible(allowedNoteToggles[noteNum]);
		allowedNoteToggles[noteNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	}

	button_ForAllowingAllNotes.setComponentID(ID::button_AllNotesFor_.toString() + "SeqTrack" + (String)trackNum);
	button_ForAllowingAllNotes.addListener(this);
	addAndMakeVisible(button_ForAllowingAllNotes);

	button_ForAllowingAllBentNotes.setComponentID(ID::button_AllNotesFor_.toString() + "BentNotesInSeqTrack" + (String)trackNum);
	button_ForAllowingAllBentNotes.addListener(this);
	addAndMakeVisible(button_ForAllowingAllBentNotes);

	generateTooltips();

	if (randomizationOptions->trackDestinationIsAnOscPitchParameter(trackNum)) {
		ValueTree placeholderTree("placeholderTree");
		if (editModeIsSelectedStep)
			valueTreePropertyChanged(placeholderTree, ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + "seqTrack" + (String)trackNum + "Step" + (String)selectedStep);
		else
			valueTreePropertyChanged(placeholderTree, ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + "AllStepsInSeqTrack" + (String)trackNum);
	}


	setSize(GUI::randomizationAllowedNotesComponentForSeqTrack_w, GUI::randomizationAllowedNotesComponentForSeqTrack_h);
}

void AllowedNotesAndBentNotesComponent::generateTooltips() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };

		for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
			auto noteName{ IntToPitchName::convertToSeqStepPitchName((uint8)noteNum) };
			if (noteName.contains("+")) {
				noteName = noteName.removeCharacters("0+");
				noteName = GUI::openQuote + "bent" + GUI::closeQuote + " " + noteName.upToFirstOccurrenceOf("+", false, false) + " (+)";
			}
			else
				noteName = noteName.removeCharacters("0");
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not " + noteName + " notes are allowed when\n";
			if (editModeIsSelectedStep) 
				toggleTooltip += "a random pitch is generated for the selected step in track " + (String)trackNum + ".\n";
			else
				toggleTooltip += "a random pitch is generated for all the steps in track " + (String)trackNum + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make " + noteName + " notes the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed note.";
			allowedNoteToggles[noteNum].setTooltip(toggleTooltip);
		}

		String allNotesTooltip{ "" };
		allNotesTooltip += "Click to allow all notes when generating\n";
		if (editModeIsSelectedStep)
			allNotesTooltip += "a random pitch for the selected step in track " + (String)trackNum + ".";
		else
			allNotesTooltip += "a random pitch for all the steps in track " + (String)trackNum + ".";
		button_ForAllowingAllNotes.setTooltip(allNotesTooltip);

		String allBentNotesTooltip{ "" };
		allBentNotesTooltip += "Click to allow all " + GUI::openQuote + "bent" + GUI::closeQuote + " (+) notes when generating\n";
		if (editModeIsSelectedStep)
			allBentNotesTooltip += "a random pitch for the selected step in track " + (String)trackNum + ".";
		else
			allBentNotesTooltip += "a random pitch for all the steps in track " + (String)trackNum + ".";
		button_ForAllowingAllNotes.setTooltip(allBentNotesTooltip);
	}
}

void AllowedNotesAndBentNotesComponent::resized() {
	allowedNoteToggles[0].setBounds(GUI::randomizationAllowedNoteToggleRow2_x, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[1].setBounds(GUI::randomizationAllowedBentNoteToggleRow2_x, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[2].setBounds(GUI::randomizationAllowedNoteToggleRow1_x, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[3].setBounds(GUI::randomizationAllowedBentNoteToggleRow1_x, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[4].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[5].setBounds(GUI::randomizationAllowedBentNoteToggleRow2_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[6].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[7].setBounds(GUI::randomizationAllowedBentNoteToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[8].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[9].setBounds(GUI::randomizationAllowedBentNoteToggleRow2_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[10].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[11].setBounds(GUI::randomizationAllowedBentNoteToggleRow2_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[12].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[13].setBounds(GUI::randomizationAllowedBentNoteToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[14].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[15].setBounds(GUI::randomizationAllowedBentNoteToggleRow2_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[16].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[17].setBounds(GUI::randomizationAllowedBentNoteToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[18].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[19].setBounds(GUI::randomizationAllowedBentNoteToggleRow2_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[20].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[21].setBounds(GUI::randomizationAllowedBentNoteToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[22].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 6 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[23].setBounds(GUI::randomizationAllowedBentNoteToggleRow2_x + 6 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllNotes.setBounds(GUI::bounds_RandomizationAllowAllNotesButton);
	button_ForAllowingAllBentNotes.setBounds(GUI::bounds_RandomizationAllowAllBentNotesButton);
}

void AllowedNotesAndBentNotesComponent::turnOffAllToggles() {
	for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
		allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
	}
}

void AllowedNotesAndBentNotesComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto editModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
	auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
	auto& info{ InfoForExposedParameters::get() };
	auto paramIndex{ info.indexForParamID(paramID) };

	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForSeqTrack" + (String)trackNum + "_Note")) {
		auto clickedNoteNum{ buttonID.fromFirstOccurrenceOf("Note", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
				if (noteNum == clickedNoteNum) {
					allowedNoteToggles[noteNum].setToggleState(true, dontSendNotification);
					if (editModeIsSelectedStep)
						randomizationOptions->setNoteIsAllowedForParam(noteNum, paramIndex);
					else
						randomizationOptions->setNoteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum);
				}
				else {
					allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
					if (editModeIsSelectedStep)
						randomizationOptions->setNoteIsNotAllowedForParam(noteNum, paramIndex);
					else
						randomizationOptions->setNoteIsNotAllowedForAllStepsInSeqTrack(noteNum, trackNum);
				}
			}
		}
		else {
			auto isAllowed{ button->getToggleState() };
			if (isAllowed)
				if (editModeIsSelectedStep)
					randomizationOptions->setNoteIsAllowedForParam(clickedNoteNum, paramIndex);
				else
					randomizationOptions->setNoteIsAllowedForAllStepsInSeqTrack(clickedNoteNum, trackNum);
			else
				if (editModeIsSelectedStep)
					randomizationOptions->setNoteIsNotAllowedForParam(clickedNoteNum, paramIndex);
				else
					randomizationOptions->setNoteIsNotAllowedForAllStepsInSeqTrack(clickedNoteNum, trackNum);
		}
		if (editModeIsSelectedStep && randomizationOptions->noNoteIsAllowedForParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setNoteIsAllowedForParam(clickedNoteNum, paramIndex);
		}
		if (editModeIsAllSteps && randomizationOptions->noNoteIsAllowedForAllStepsInSeqTrack(trackNum)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setNoteIsAllowedForAllStepsInSeqTrack(clickedNoteNum, trackNum);
		}
		if (editModeIsSelectedStep)
			randomizationOptions->checkIfOnlyOneValueIsAllowedForSeqStepParam(paramIndex);
		else
			randomizationOptions->checkIfOnlyOneValueIsAllowedForAllStepsInSeqTrack(trackNum);
	}
	if (buttonID.startsWith(ID::button_AllNotesFor_.toString())) {
		auto numberOfNotes{ randomization::numberOfNotesAndBentNotes };
		auto highestOctaveIsOnlyOneAllowed{ editModeIsSelectedStep ? randomizationOptions->highestOctaveIsOnlyOneAllowedForParam(paramIndex) :
											randomizationOptions->highestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(trackNum) };
		if (highestOctaveIsOnlyOneAllowed)
			numberOfNotes = randomization::highestNoteNumAllowedForHighestOctave_SeqTrackStep + 1;
		if (buttonID == ID::button_AllNotesFor_.toString() + "SeqTrack" + (String)trackNum) {
			for (auto noteNum = 0; noteNum < numberOfNotes; noteNum += 2) {
				allowedNoteToggles[noteNum].setToggleState(true, dontSendNotification);
				if (editModeIsSelectedStep)
					randomizationOptions->setNoteIsAllowedForParam(noteNum, paramIndex);
				else
					randomizationOptions->setNoteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum);
			}
		}
		if (buttonID == ID::button_AllNotesFor_.toString() + "BentNotesInSeqTrack" + (String)trackNum) {
			for (auto noteNum = 1; noteNum < numberOfNotes; noteNum += 2) {
				allowedNoteToggles[noteNum].setToggleState(true, dontSendNotification);
				if (editModeIsSelectedStep)
					randomizationOptions->setNoteIsAllowedForParam(noteNum, paramIndex);
				else
					randomizationOptions->setNoteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum);
			}
		}
		if (editModeIsSelectedStep)
			randomizationOptions->setMoreThanOneValueIsAllowedForParam(paramIndex);
		else
			randomizationOptions->setMoreThanOneValueIsAllowedForAllStepsInSeqTrack(trackNum);
	}
}

void AllowedNotesAndBentNotesComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	auto propertyIDstring{ propertyID.toString() };
	auto& info{ InfoForExposedParameters::get() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto editModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum) };
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
	auto paramID{ "seqTrack" + (String)trackNum + "Step" + (String)selectedStep };
	auto paramIndex{ info.indexForParamID(paramID) };
	if (propertyIDstring == "editModeIsSelectedStepForSeqTrack" + (String)trackNum ||
		propertyIDstring == "stepSelectedForEditingInSeqTrack" + (String)trackNum)
	{
		for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
			if (editModeIsSelectedStep) {
				auto noteIsAllowed{ randomizationOptions->noteIsAllowedForParam(noteNum, paramIndex) };
				allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
			}
			else {
				auto noteIsAllowed{ randomizationOptions->noteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum) };
				allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
			}
		}
		generateTooltips();
	}
	if (propertyIDstring.startsWith(ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString())) {
		if ((editModeIsSelectedStep && propertyIDstring.endsWith("seqTrack" + (String)trackNum + "Step" + (String)selectedStep)) ||
			(editModeIsAllSteps && propertyIDstring.endsWith("AllStepsInSeqTrack" + (String)trackNum))) 
		{
			int highestAllowedNote{ randomization::highestNoteNumAllowedForHighestOctave_SeqTrackStep };
			auto highestOctaveIsOnlyOneAllowed{ (bool)false };
			if (editModeIsSelectedStep)
				highestOctaveIsOnlyOneAllowed = randomizationOptions->highestOctaveIsOnlyOneAllowedForParam(paramIndex);
			else
				highestOctaveIsOnlyOneAllowed = randomizationOptions->highestOctaveIsOnlyOneAllowedForAllStepsInSeqTrack(trackNum);
			for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
				if (highestOctaveIsOnlyOneAllowed) {
					if (noteNum <= highestAllowedNote) {
						auto noteIsAllowed{ (bool)false };
						if (editModeIsSelectedStep)
							noteIsAllowed = randomizationOptions->noteIsAllowedForParam(noteNum, paramIndex);
						else
							noteIsAllowed = randomizationOptions->noteIsAllowedForAllStepsInSeqTrack(noteNum, trackNum);
						allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
						allowedNoteToggles[noteNum].setEnabled(true);
					}
					else {
						if (editModeIsSelectedStep)
							randomizationOptions->setNoteIsNotAllowedForParam(noteNum, paramIndex);
						else
							randomizationOptions->setNoteIsNotAllowedForAllStepsInSeqTrack(noteNum, trackNum);
						allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
						allowedNoteToggles[noteNum].setEnabled(false);
					}
				}
				else
					allowedNoteToggles[noteNum].setEnabled(true);
			}
			if (editModeIsSelectedStep) {
				if (randomizationOptions->noNoteIsAllowedForParam(paramIndex)) {
					randomizationOptions->setNoteIsAllowedForParam(highestAllowedNote, paramIndex);
					allowedNoteToggles[highestAllowedNote].setToggleState(true, dontSendNotification);
				}
			}
			else {
				if (randomizationOptions->noNoteIsAllowedForAllStepsInSeqTrack(trackNum)) {
					randomizationOptions->setNoteIsAllowedForAllStepsInSeqTrack(highestAllowedNote, trackNum);
					allowedNoteToggles[highestAllowedNote].setToggleState(true, dontSendNotification);
				}
			}
		}
	}
}

AllowedNotesAndBentNotesComponent::~AllowedNotesAndBentNotesComponent() {
	button_ForAllowingAllBentNotes.removeListener(this);
	button_ForAllowingAllNotes.removeListener(this);
	for (auto noteNum = 0; noteNum != randomization::numberOfNotesAndBentNotes; ++noteNum) {
		allowedNoteToggles[noteNum].removeListener(this);
	}
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackOptionsTree(this);
	randomizationOptions->removeListenerFromAllowedPitchesTree(this);
}
