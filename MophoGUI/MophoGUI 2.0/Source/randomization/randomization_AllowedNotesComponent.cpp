#include "randomization_AllowedNotesComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedNotesComponent::AllowedNotesComponent(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch || optionsType == RandomizationOptionsType::lpfFreq || optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToAllowedPitchesTree(this);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "For_" + paramID + "_Note" + String(noteNum) };
		allowedNoteToggles[noteNum].setComponentID(toggleID);
		auto noteIsAllowed{ randomizationOptions->noteIsAllowedForParam(noteNum, paramIndex) };
		allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
		allowedNoteToggles[noteNum].addListener(this);
		addAndMakeVisible(allowedNoteToggles[noteNum]);
		allowedNoteToggles[noteNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		auto noteName{ IntToPitchName::convert((uint8)noteNum).upToFirstOccurrenceOf(" ", false, false) };
		if (shouldShowDescriptions) {
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not " + noteName + " notes\n";
			if (optionsType == RandomizationOptionsType::pitch) {
				String paramName{ "" };
				if (paramID.contains("push"))
					paramName = "the Push It! switch";
				else {
					paramName = "oscillator ";
					paramName += paramID.contains("1") ? "1" : "2";
				}
				toggleTooltip += "are allowed when a random pitch is\n";
				toggleTooltip += "generated for " + paramName + ".\n";
			}
			if (optionsType == RandomizationOptionsType::lpfFreq) {
				toggleTooltip += "are allowed when a random LPF\n";
				toggleTooltip += "cutoff frequency is generated.\n";
			}
			if (optionsType == RandomizationOptionsType::lfoFreq) {
				auto lfoNum{ paramID.fromFirstOccurrenceOf("lfo", false, false).upToFirstOccurrenceOf("Freq", false, false) };
				toggleTooltip += "are allowed when a random pitched\n";
				toggleTooltip += "frequency is generated for LFO " + lfoNum + ".\n";
			}
			toggleTooltip += "Holding down the CTRL key when\n";
			toggleTooltip += "clicking the toggle will make " + noteName + "\n";
			toggleTooltip += "notes the only ones allowed. There\n";
			toggleTooltip += "must always be at least one allowed note.";
			allowedNoteToggles[noteNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllNotes.setComponentID(ID::button_AllNotesFor_.toString() + paramID);
	button_ForAllowingAllNotes.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all notes when generating\n";
		if (optionsType == RandomizationOptionsType::pitch) {
			String paramName{ "" };
			if (paramID.contains("push"))
				paramName = "the Push It! switch";
			else {
				paramName = "oscillator ";
				paramName += paramID.contains("1") ? "1" : "2";
			}
			buttonTooltip += "a random pitch for " + paramName + ".";
		}
		if (optionsType == RandomizationOptionsType::lpfFreq) {
			buttonTooltip += "a random LPF cutoff frequency.";
		}
		if (optionsType == RandomizationOptionsType::lfoFreq) {
			auto lfoNum{ paramID.fromFirstOccurrenceOf("lfo", false, false).upToFirstOccurrenceOf("Freq", false, false) };
			buttonTooltip += "a random pitched frequency for LFO " + lfoNum + ".\n";
		}
		button_ForAllowingAllNotes.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllNotes);

	ValueTree placeholderTree("placeholderTree");
	valueTreePropertyChanged(placeholderTree, ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + paramID);

	setSize(GUI::randomizationAllowedNotesComponent_w, GUI::randomizationAllowedNotesComponent_h);
}

void AllowedNotesComponent::resized() {
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

void AllowedNotesComponent::turnOffAllToggles() {
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
	}
}

void AllowedNotesComponent::restoreAllToggles() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
		auto noteIsAllowed{ randomizationOptions->noteIsAllowedForParam(noteNum, paramIndex) };
		allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
	}
}

void AllowedNotesComponent::buttonClicked(Button* button) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "For_" + paramID + "_Note")) {
		auto clickedNoteNum{ buttonID.fromFirstOccurrenceOf("Note", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
				if (noteNum == clickedNoteNum) {
					allowedNoteToggles[noteNum].setToggleState(true, dontSendNotification);
					randomizationOptions->setNoteIsAllowedForParam(noteNum, paramIndex);
				}
				else {
					allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
					randomizationOptions->setNoteIsNotAllowedForParam(noteNum, paramIndex);
				}
			}
		}
		else {
			auto isAllowed{ button->getToggleState() };
			if (isAllowed)
				randomizationOptions->setNoteIsAllowedForParam(clickedNoteNum, paramIndex);
			else
				randomizationOptions->setNoteIsNotAllowedForParam(clickedNoteNum, paramIndex);
		}
		if (randomizationOptions->noNoteIsAllowedForParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setNoteIsAllowedForParam(clickedNoteNum, paramIndex);
		}
		auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
		switch (optionsType)
		{
		case RandomizationOptionsType::pitch:
			randomizationOptions->checkIfOnlyOneValueIsAllowedForPitchParam(paramIndex);
			break;
		case RandomizationOptionsType::lpfFreq:
			randomizationOptions->checkIfOnlyOneValueIsAllowedForLPFfreqParam();
			break;
		case RandomizationOptionsType::lfoFreq:
			randomizationOptions->checkIfOnlyOneValueIsAllowedForLFOfreqParam(paramIndex);
			break;
		default:
			break;
		}
	}
	if (buttonID == ID::button_AllNotesFor_.toString() + paramID) {
		auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
		auto numberOfNotes{ randomization::numberOfNotes };
		if (optionsType == RandomizationOptionsType::lpfFreq && randomizationOptions->highestOctaveIsOnlyOneAllowedForParam(paramIndex))
			numberOfNotes = randomization::highestNoteNumAllowedForHighestOctave_LPFfreq + 1;
		for (auto noteNum = 0; noteNum != numberOfNotes; ++noteNum) {
			allowedNoteToggles[noteNum].setToggleState(true, dontSendNotification);
			randomizationOptions->setNoteIsAllowedForParam(noteNum, paramIndex);
		}
		randomizationOptions->setMoreThanOneValueIsAllowedForParam_z(paramIndex);
	}
}

void AllowedNotesComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	if (propertyID.toString() == ID::randomization_HighestOctaveIsOnlyOneAllowedFor_.toString() + paramID) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto highestOctaveIsOnlyOneAllowed{ randomizationOptions->highestOctaveIsOnlyOneAllowedForParam(paramIndex) };
		auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
		int highestAllowedNote{ randomization::highestNoteNumAllowedForHighestOctave_PitchAndLFOfreq };
		if (optionsType == RandomizationOptionsType::lpfFreq)
			highestAllowedNote = randomization::highestNoteNumAllowedForHighestOctave_LPFfreq;
		for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum) {
			if (highestOctaveIsOnlyOneAllowed) {
				if (noteNum <= highestAllowedNote) {
					auto noteIsAllowed{ randomizationOptions->noteIsAllowedForParam(noteNum, paramIndex) };
					allowedNoteToggles[noteNum].setToggleState(noteIsAllowed, dontSendNotification);
					allowedNoteToggles[noteNum].setEnabled(true);
				}
				else {
					randomizationOptions->setNoteIsNotAllowedForParam(noteNum, paramIndex);
					allowedNoteToggles[noteNum].setToggleState(false, dontSendNotification);
					allowedNoteToggles[noteNum].setEnabled(false);
				}
			}
			else
				allowedNoteToggles[noteNum].setEnabled(true);
		}
		if (randomizationOptions->noNoteIsAllowedForParam(paramIndex)) {
			randomizationOptions->setNoteIsAllowedForParam(highestAllowedNote, paramIndex);
			allowedNoteToggles[highestAllowedNote].setToggleState(true, dontSendNotification);
		}
		if (optionsType == RandomizationOptionsType::pitch || optionsType == RandomizationOptionsType::lfoFreq)
			button_ForAllowingAllNotes.setEnabled(highestOctaveIsOnlyOneAllowed ? false : true);
	}
}

AllowedNotesComponent::~AllowedNotesComponent() {
	button_ForAllowingAllNotes.removeListener(this);
	for (auto noteNum = 0; noteNum != randomization::numberOfNotes; ++noteNum)
		allowedNoteToggles[noteNum].removeListener(this);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromAllowedPitchesTree(this);
}
