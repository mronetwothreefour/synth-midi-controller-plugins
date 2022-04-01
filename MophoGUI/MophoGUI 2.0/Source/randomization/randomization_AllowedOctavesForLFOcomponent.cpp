#include "randomization_AllowedOctavesForLFOcomponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedOctavesForLFOcomponent::AllowedOctavesForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	unexposedParams{ unexposedParams }
{
	jassert(lfoNum > 0 && lfoNum < 5);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto pitchedFreqAreAllowed{ randomizationOptions->pitchedFreqAreAllowedForLFO(lfoNum) };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "ForLFO" + (String)lfoNum + "_Octave" + String(octaveNum) };
		allowedOctaveToggles[octaveNum].setComponentID(toggleID);
		if (pitchedFreqAreAllowed) {
			auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForLFO(octaveNum, lfoNum) };
			allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
		}
		else
			allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
		allowedOctaveToggles[octaveNum].addListener(this);
		addAndMakeVisible(allowedOctaveToggles[octaveNum]);
		allowedOctaveToggles[octaveNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		if (shouldShowDescriptions) {
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not notes in octave " + (String)octaveNum + " are allowed\n";
			toggleTooltip += "when a random pitched frequency is generated for LFO " + (String)lfoNum + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make notes in octave " + (String)octaveNum + " the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed octave.\n";
			if (octaveNum == 5) {
				toggleTooltip += "Note: C is the only note in octave 5. If only\n";
				toggleTooltip += "octave 5 is allowed, a pitch of C 5 will always\n";
				toggleTooltip += "be produced, regardless of the allowed note settings.";
			}
			allowedOctaveToggles[octaveNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllOctaves.setComponentID(ID::button_AllOctavesForLFO.toString() + (String)lfoNum);
	button_ForAllowingAllOctaves.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all octaves when generating\n";
		buttonTooltip += "a random pitched frequency for LFO " + (String)lfoNum + ".";
		button_ForAllowingAllOctaves.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllOctaves);

	setSize(GUI::randomizationAllowedOctavesForLFOandSeqStepComponents_w, GUI::randomizationAllowedOctavesForLFOandSeqStepComponents_h);
}

void AllowedOctavesForLFOcomponent::resized() {
	allowedOctaveToggles[0].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[1].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[2].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[3].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[4].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[5].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllOctaves.setBounds(GUI::bounds_RandomizationAllowAllOctavesForLFOandSeqStepButton);
}

void AllowedOctavesForLFOcomponent::turnOffAllToggles() {
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
	}
}

void AllowedOctavesForLFOcomponent::restoreAllToggles() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForLFO(octaveNum, lfoNum) };
		allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
	}
}

void AllowedOctavesForLFOcomponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto pitchedFreqAreAllowed{ randomizationOptions->pitchedFreqAreAllowedForLFO(lfoNum) };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForLFO" + (String)lfoNum + "_Octave")) {
		if (pitchedFreqAreAllowed) {
			auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("Octave", false, false).getIntValue() };
			if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
				for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
					if (octaveNum == clickedOctaveNum) {
						allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
						randomizationOptions->setOctaveIsAllowedForLFO(octaveNum, lfoNum);
					}
					else {
						allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
						randomizationOptions->setOctaveIsNotAllowedForLFO(octaveNum, lfoNum);
					}
				}
			}
			else {
				auto isAllowed{ button->getToggleState() };
				if (isAllowed)
					randomizationOptions->setOctaveIsAllowedForLFO(clickedOctaveNum, lfoNum);
				else
					randomizationOptions->setOctaveIsNotAllowedForLFO(clickedOctaveNum, lfoNum);
			}
			if (randomizationOptions->noOctaveIsAllowedForLFO(lfoNum)) {
				button->setToggleState(true, dontSendNotification);
				randomizationOptions->setOctaveIsAllowedForLFO(clickedOctaveNum, lfoNum);
			}
		}
		else
			button->setToggleState(false, dontSendNotification);
	}
	if (buttonID == ID::button_AllOctavesForLFO.toString() + (String)lfoNum) {
		if (pitchedFreqAreAllowed) {
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
				allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
				randomizationOptions->setOctaveIsAllowedForLFO(octaveNum, lfoNum);
			}
		}
	}
}

AllowedOctavesForLFOcomponent::~AllowedOctavesForLFOcomponent() {
	button_ForAllowingAllOctaves.removeListener(this);
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		allowedOctaveToggles[octaveNum].removeListener(this);
	}
}
