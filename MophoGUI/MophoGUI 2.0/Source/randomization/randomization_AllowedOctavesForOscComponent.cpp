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
		allowedOctaveToggles[octaveNum].setComponentID(toggleID);
		auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForOscillator(octaveNum, oscNum) };
		allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
		allowedOctaveToggles[octaveNum].addListener(this);
		addAndMakeVisible(allowedOctaveToggles[octaveNum]);
		allowedOctaveToggles[octaveNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		if (shouldShowDescriptions) {
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not notes in octave " + (String)octaveNum + " are allowed\n";
			toggleTooltip += "when a random pitch is generated for oscillator " + (String)oscNum + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make notes in octave " + (String)octaveNum + " the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed octave.\n";
			if (octaveNum == 10) {
				toggleTooltip += "Note: C is the only note in octave 10. If only\n";
				toggleTooltip += "octave 10 is allowed, a pitch of C 10 will always\n";
				toggleTooltip += "be produced, regardless of the allowed note settings.";
			}
			allowedOctaveToggles[octaveNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllOctaves.setComponentID(ID::button_AllOctavesForOsc.toString() + (String)oscNum);
	button_ForAllowingAllOctaves.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all octaves when generating\n";
		buttonTooltip += "a random pitch for oscillator" + (String)oscNum + ".";
		button_ForAllowingAllOctaves.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllOctaves);

	setSize(GUI::randomizationAllowedOctavesForOscComponent_w, GUI::randomizationAllowedOctavesForOscComponent_h);
}

void AllowedOctavesForOscComponent::resized() {
	allowedOctaveToggles[0].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[1].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[2].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[3].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[4].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[5].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[6].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[7].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[8].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[9].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[10].setBounds(GUI::randomizationAllowedOctaveToggleRow2_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllOctaves.setBounds(GUI::bounds_RandomizationAllowAllOctavesForOscButton);
}

void AllowedOctavesForOscComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForOsc" + (String)oscNum + "Octave")) {
		auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("Octave", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
				if (octaveNum == clickedOctaveNum) {
					allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
					randomizationOptions->setOctaveIsAllowedForOscillator(octaveNum, oscNum);
				}
				else {
					allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
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
	if (buttonID == ID::button_AllOctavesForOsc.toString() + (String)oscNum) {
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
			allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForOscillator(octaveNum, oscNum);
		}
	}
}

AllowedOctavesForOscComponent::~AllowedOctavesForOscComponent() {
	button_ForAllowingAllOctaves.removeListener(this);
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForOscillators; ++octaveNum) {
		allowedOctaveToggles[octaveNum].removeListener(this);
	}
}
