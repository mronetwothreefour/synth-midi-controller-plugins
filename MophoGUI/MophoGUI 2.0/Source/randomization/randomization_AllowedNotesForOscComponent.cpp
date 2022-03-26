#include "randomization_AllowedNotesForOscComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedNotesForOscComponent::AllowedNotesForOscComponent(int oscNum, UnexposedParameters* unexposedParams) :
	oscNum{ oscNum },
	unexposedParams{ unexposedParams }
{
	jassert(oscNum == 1 || oscNum == 2);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "ForOsc" + (String)oscNum + "Note" + String(noteNum) };
		allowedNoteToggleButtons[noteNum].setComponentID(toggleID);
		auto noteIsAllowed{ randomizationOptions->noteIsAllowedForOscillator(noteNum, 1) };
		allowedNoteToggleButtons[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
		allowedNoteToggleButtons[noteNum].addListener(this);
		addAndMakeVisible(allowedNoteToggleButtons[noteNum]);
		allowedNoteToggleButtons[noteNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		if (shouldShowDescriptions) {
			auto noteName{ IntToPitchName::convert(noteNum).upToFirstOccurrenceOf(" ", false, false)};
			String toggleTooltip {""};
			toggleTooltip += "Toggles whether or not " + noteName + " notes are allowed\n";
			toggleTooltip += "when a random pitch is generated for oscillator " + (String)oscNum + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make " + noteName + " notes the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed note.";
			allowedNoteToggleButtons[noteNum].setTooltip(toggleTooltip);
		}
	}
}

void AllowedNotesForOscComponent::resized() {
	allowedNoteToggleButtons[0].setBounds(GUI::randomizationAllowedNoteToggleRow2_x, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[1].setBounds(GUI::randomizationAllowedNoteToggleRow1_x, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[2].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[3].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[4].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[5].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[6].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[7].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[8].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[9].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[10].setBounds(GUI::randomizationAllowedNoteToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNoteToggleButtons[11].setBounds(GUI::randomizationAllowedNoteToggleRow2_x + 6 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedNoteToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
}

void AllowedNotesForOscComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForOsc" + (String)oscNum + "Note")) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto clickedNoteNum{ buttonID.fromFirstOccurrenceOf("Note", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
				if (noteNum == clickedNoteNum) {
					allowedNoteToggleButtons[noteNum].setToggleState(true, dontSendNotification);
					randomizationOptions->setNoteIsAllowedForOscillator(noteNum, oscNum);
				}
				else {
					allowedNoteToggleButtons[noteNum].setToggleState(false, dontSendNotification);
					randomizationOptions->setNoteIsNotAllowedForOscillator(noteNum, oscNum);
				}
			}
		}
		else {
			auto isAllowed{ button->getToggleState() };
			if (isAllowed)
				randomizationOptions->setNoteIsAllowedForOscillator(clickedNoteNum, oscNum);
			else
				randomizationOptions->setNoteIsNotAllowedForOscillator(clickedNoteNum, oscNum);
		}
		if (randomizationOptions->noNoteIsAllowedForOscillator(oscNum)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setNoteIsAllowedForOscillator(clickedNoteNum, oscNum);
		}
	}
}

AllowedNotesForOscComponent::~AllowedNotesForOscComponent() {
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		allowedNoteToggleButtons[noteNum].removeListener(this);
	}
}
