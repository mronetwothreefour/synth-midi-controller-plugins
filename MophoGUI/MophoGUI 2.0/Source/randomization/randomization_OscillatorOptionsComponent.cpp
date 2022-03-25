#include "randomization_OscillatorOptionsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



OscillatorRandomizationOptionsComponent::OscillatorRandomizationOptionsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams }
{
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		allowNoteToggleButtons[noteNum].setComponentID(ID::component_ToggleButton.toString() + "ForOsc1Note" + String(noteNum));
		auto noteIsAllowed{ randomizationOptions->noteIsAllowedForOscillator(noteNum, 1) };
		allowNoteToggleButtons[noteNum].setRadioGroupId(0, dontSendNotification);
		allowNoteToggleButtons[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
		allowNoteToggleButtons[noteNum].addListener(this);
		addAndMakeVisible(allowNoteToggleButtons[noteNum]);
		allowNoteToggleButtons[noteNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	}
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
		allowOctaveToggleButtons[octaveNum].setComponentID(ID::component_ToggleButton.toString() + "ForOsc1Octave" + String(octaveNum));
		auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForOscillator(octaveNum, 1) };
		allowOctaveToggleButtons[octaveNum].setRadioGroupId(0, dontSendNotification);
		allowOctaveToggleButtons[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
		allowOctaveToggleButtons[octaveNum].addListener(this);
		addAndMakeVisible(allowOctaveToggleButtons[octaveNum]);
		allowOctaveToggleButtons[octaveNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	}

	button_ForClosingOscOptionsComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingOscOptionsComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingOscOptionsComponent.onClick = [this] { hideThisComponent(); };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions())
		button_ForClosingOscOptionsComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingOscOptionsComponent);

	setSize(GUI::editor_w, GUI::editor_h);
}

void OscillatorRandomizationOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::RandomizationOscOptionsBackground_png, BinaryData::RandomizationOscOptionsBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::randomizationOscOptionsBackground_x, GUI::randomizationOscOptionsBackground_y);
}

void OscillatorRandomizationOptionsComponent::resized() {
	allowNoteToggleButtons[0].setBounds(GUI::randomizationOscOptionsToggleRow2_x, GUI::randomizationOscOptionsToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[1].setBounds(GUI::randomizationOscOptionsToggleRow1_x, GUI::randomizationOscOptionsToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[2].setBounds(GUI::randomizationOscOptionsToggleRow2_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[3].setBounds(GUI::randomizationOscOptionsToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[4].setBounds(GUI::randomizationOscOptionsToggleRow2_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[5].setBounds(GUI::randomizationOscOptionsToggleRow2_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[6].setBounds(GUI::randomizationOscOptionsToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[7].setBounds(GUI::randomizationOscOptionsToggleRow2_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[8].setBounds(GUI::randomizationOscOptionsToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[9].setBounds(GUI::randomizationOscOptionsToggleRow2_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[10].setBounds(GUI::randomizationOscOptionsToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowNoteToggleButtons[11].setBounds(GUI::randomizationOscOptionsToggleRow2_x + 6 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);

	allowOctaveToggleButtons[0].setBounds(GUI::randomizationOscOptionsToggleRow3_x, GUI::randomizationOscOptionsToggleRow3_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[1].setBounds(GUI::randomizationOscOptionsToggleRow3_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow3_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[2].setBounds(GUI::randomizationOscOptionsToggleRow3_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow3_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[3].setBounds(GUI::randomizationOscOptionsToggleRow3_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow3_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[4].setBounds(GUI::randomizationOscOptionsToggleRow3_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow3_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[5].setBounds(GUI::randomizationOscOptionsToggleRow3_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow3_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[6].setBounds(GUI::randomizationOscOptionsToggleRow4_x, GUI::randomizationOscOptionsToggleRow4_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[7].setBounds(GUI::randomizationOscOptionsToggleRow4_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow4_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[8].setBounds(GUI::randomizationOscOptionsToggleRow4_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow4_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[9].setBounds(GUI::randomizationOscOptionsToggleRow4_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow4_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowOctaveToggleButtons[10].setBounds(GUI::randomizationOscOptionsToggleRow4_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationOscOptionsToggleRow4_y, GUI::toggle_diameter, GUI::toggle_diameter);
	
	button_ForClosingOscOptionsComponent.setBounds(GUI::bounds_RandomizationOscOptionsCloseButton);
}

void OscillatorRandomizationOptionsComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForOsc")) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto oscNum{ buttonID.contains("Osc1") ? 1 : 2 };
		if (buttonID.contains("Note")) {
			auto clickedNoteNum{ buttonID.fromFirstOccurrenceOf("Note", false, false).getIntValue() };
			if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
				for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
					if (noteNum == clickedNoteNum) {
						allowNoteToggleButtons[noteNum].setToggleState(true, dontSendNotification);
						randomizationOptions->setNoteIsAllowedForOscillator(noteNum, oscNum);
					}
					else {
						allowNoteToggleButtons[noteNum].setToggleState(false, dontSendNotification);
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
		}
		if (buttonID.contains("Octave")) {
			auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("Octave", false, false).getIntValue() };
			if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
				for (auto octaveNum = 0; octaveNum != randomization::numberOfNotes; ++octaveNum) {
					if (octaveNum == clickedOctaveNum) {
						allowNoteToggleButtons[octaveNum].setToggleState(true, dontSendNotification);
						randomizationOptions->setOctaveIsAllowedForOscillator(octaveNum, oscNum);
					}
					else {
						allowNoteToggleButtons[octaveNum].setToggleState(false, dontSendNotification);
						randomizationOptions->setOctaveIsNotAllowedForOscillator(octaveNum, oscNum);
					}
				}
			}
			else {
				auto isAllowed{ button->getToggleState() };
				if (isAllowed)
					randomizationOptions->setOctaveIsAllowedForOscillator(clickedOctaveNum, oscNum);
				else
					randomizationOptions->setOctaveIsNotAllowedForOscillator(clickedOctaveNum, oscNum);
			}
		}
	}
}

void OscillatorRandomizationOptionsComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

OscillatorRandomizationOptionsComponent::~OscillatorRandomizationOptionsComponent() {
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		allowNoteToggleButtons[noteNum].removeListener(this);
	}
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
		allowNoteToggleButtons[octaveNum].removeListener(this);
	}
}
