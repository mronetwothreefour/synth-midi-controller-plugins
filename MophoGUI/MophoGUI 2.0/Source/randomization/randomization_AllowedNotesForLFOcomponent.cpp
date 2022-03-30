#include "randomization_AllowedNotesForLFOcomponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedNotesForLFOcomponent::AllowedNotesForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	unexposedParams{ unexposedParams }
{
	jassert(lfoNum > 0 && lfoNum < 5);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto pitchedFreqAreAllowed{ randomizationOptions->pitchedFreqAreAllowedForLFO(lfoNum) };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "ForLFO" + (String)lfoNum + "_Note" + String(noteNum) };
		allowedNoteToggles[noteNum].setComponentID(toggleID);
		if (pitchedFreqAreAllowed) {
			auto noteIsAllowed{ randomizationOptions->noteIsAllowedForLFO(noteNum, lfoNum) };
			allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
		}
		else
			allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
		allowedNoteToggles[noteNum].addListener(this);
		addAndMakeVisible(allowedNoteToggles[noteNum]);
		allowedNoteToggles[noteNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		if (shouldShowDescriptions) {
			auto noteName{ IntToPitchName::convert((uint8)noteNum).upToFirstOccurrenceOf(" ", false, false) };
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not " + noteName + " notes are allowed\n";
			toggleTooltip += "when a random pitched frequency is generated for LFO " + (String)lfoNum + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make " + noteName + " notes the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed note.";
			allowedNoteToggles[noteNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllNotes.setComponentID(ID::button_AllNotesForLFO.toString() + (String)lfoNum);
	button_ForAllowingAllNotes.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all notes when generating\n";
		buttonTooltip += "a random pitched frequency for LFO " + (String)lfoNum + ".";
		button_ForAllowingAllNotes.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllNotes);

	setSize(GUI::randomizationAllowedNotesComponent_w, GUI::randomizationAllowedNotesComponent_h);
}

void AllowedNotesForLFOcomponent::resized() {
	allowedNoteToggles[0].setBounds(GUI::randomizationAllowedNoteToggleRow2_x, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[1].setBounds(GUI::randomizationAllowedNoteToggleRow1_x, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[2].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[3].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[4].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[5].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[6].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[7].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[8].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[9].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[10].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggles[11].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 6 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllNotes.setBounds(GUI::bounds_RandomizationAllowAllNotesButton);
}

void AllowedNotesForLFOcomponent::turnOffAllToggles() {
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
	}
}

void AllowedNotesForLFOcomponent::restoreAllToggles() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		auto noteIsAllowed{ randomizationOptions->noteIsAllowedForLFO(noteNum, lfoNum) };
		allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
	}
}

void AllowedNotesForLFOcomponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto pitchedFreqAreAllowed{ randomizationOptions->pitchedFreqAreAllowedForLFO(lfoNum) };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForLFO" + (String)lfoNum + "_Note")) {
		if (pitchedFreqAreAllowed) {
			auto clickedNoteNum{ buttonID.fromFirstOccurrenceOf("Note", false, false).getIntValue() };
			if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
				for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
					if (noteNum == clickedNoteNum) {
						allowedNoteToggles[noteNum].setToggleState(true, dontSendNotification);
						randomizationOptions->setNoteIsAllowedForLFO(noteNum, lfoNum);
					}
					else {
						allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
						randomizationOptions->setNoteIsNotAllowedForLFO(noteNum, lfoNum);
					}
				}
			}
			else {
				auto isAllowed{ button->getToggleState() };
				if (isAllowed)
					randomizationOptions->setNoteIsAllowedForLFO(clickedNoteNum, lfoNum);
				else
					randomizationOptions->setNoteIsNotAllowedForLFO(clickedNoteNum, lfoNum);
			}
			if (randomizationOptions->noNoteIsAllowedForLFO(lfoNum)) {
				button->setToggleState(true, dontSendNotification);
				randomizationOptions->setNoteIsAllowedForLFO(clickedNoteNum, lfoNum);
			}
		}
		else
			button->setToggleState(false, dontSendNotification);
	}
	if (buttonID == ID::button_AllNotesForLFO.toString() + (String)lfoNum) {
		if (pitchedFreqAreAllowed) {
			for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
				allowedNoteToggles[noteNum].setToggleState(true, dontSendNotification);
				randomizationOptions->setNoteIsAllowedForLFO(noteNum, lfoNum);
			}
		}
	}
}

AllowedNotesForLFOcomponent::~AllowedNotesForLFOcomponent() {
	button_ForAllowingAllNotes.removeListener(this);
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		allowedNoteToggles[noteNum].removeListener(this);
	}
}
