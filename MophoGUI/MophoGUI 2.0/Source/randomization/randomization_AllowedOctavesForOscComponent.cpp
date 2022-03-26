#include "randomization_AllowedOctavesForOscComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedOctavesForOscComponent::AllowedOctavesForOscComponent(int oscNum, UnexposedParameters* unexposedParams) :
	oscNum{ oscNum },
	unexposedParams{ unexposedParams }
{
	jassert(oscNum == 1 || oscNum == 2);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "ForOsc" + (String)oscNum + "Octave" + String(octaveNum) };
		allowedOctaveToggleButtons[octaveNum].setComponentID(toggleID);
		auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForOscillator(octaveNum, 1) };
		allowedOctaveToggleButtons[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
		allowedOctaveToggleButtons[octaveNum].addListener(this);
		addAndMakeVisible(allowedOctaveToggleButtons[octaveNum]);
		allowedOctaveToggleButtons[octaveNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		if (shouldShowDescriptions) {
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not notes in octave " + (String)octaveNum + " are allowed\n";
			toggleTooltip += "when a random pitch is generated for oscillator " + (String)oscNum + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make notes in octave " + (String)octaveNum + " the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed octave.";
			allowedOctaveToggleButtons[octaveNum].setTooltip(toggleTooltip);
		}
	}
}

void AllowedOctavesForOscComponent::resized() {
	allowedOctaveToggleButtons[0].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[1].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[2].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[3].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[4].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[5].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[6].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[7].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[8].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[9].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggleButtons[10].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
}

void AllowedOctavesForOscComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForOsc" + (String)oscNum + "Octave")) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("Octave", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
				if (octaveNum == clickedOctaveNum) {
					allowedOctaveToggleButtons[octaveNum].setToggleState(true, dontSendNotification);
					randomizationOptions->setOctaveIsAllowedForOscillator(octaveNum, oscNum);
				}
				else {
					allowedOctaveToggleButtons[octaveNum].setToggleState(false, dontSendNotification);
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
		if (randomizationOptions->noOctaveIsAllowedForOscillator(oscNum)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForOscillator(clickedOctaveNum, oscNum);
		}
	}
}

AllowedOctavesForOscComponent::~AllowedOctavesForOscComponent() {
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
		allowedOctaveToggleButtons[octaveNum].removeListener(this);
	}
}
