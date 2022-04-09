#include "randomization_AllowedOctavesForSeqTrackComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedOctavesForSeqTrackComponent::AllowedOctavesForSeqTrackComponent(int trackNum, UnexposedParameters* unexposedParams) :
	trackNum{ trackNum },
	unexposedParams{ unexposedParams }
{
	jassert(trackNum > 0 && trackNum < 5);

	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToSeqTrackAllowedStepValuesTree(this);
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };

	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "ForSeqTrack" + (String)trackNum + "_Octave" + String(octaveNum) };
		allowedOctaveToggles[octaveNum].setComponentID(toggleID);
		if (editModeIsSelectedStep) {
			auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForSelectedStepInSeqTrack(octaveNum, selectedStep, trackNum) };
			allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
		}
		else {
			auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum) };
			allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
		}
		allowedOctaveToggles[octaveNum].addListener(this);
		addAndMakeVisible(allowedOctaveToggles[octaveNum]);
		allowedOctaveToggles[octaveNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
	}

	button_ForAllowingAllOctaves.setComponentID(ID::button_AllOctavesForSeqTrack.toString() + (String)trackNum);
	button_ForAllowingAllOctaves.addListener(this);
	addAndMakeVisible(button_ForAllowingAllOctaves);

	generateTooltips();	

	setSize(GUI::randomizationAllowedOctavesForLFOandSeqTrackComponents_w, GUI::randomizationAllowedOctavesForLFOandSeqTrackComponents_h);
}

void AllowedOctavesForSeqTrackComponent::generateTooltips() {
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
		String toggleTooltip{ "" };
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
			toggleTooltip += "Toggles whether or not notes in octave " + (String)octaveNum + " are allowed when\n";
			if (editModeIsSelectedStep)
				toggleTooltip += "a random pitch is generated for the selected step in track " + (String)trackNum + "\n";
			else
				toggleTooltip += "a random pitch is generated for all the steps in track " + (String)trackNum + "\n";
			toggleTooltip += "(when the track destination is an oscillator pitch).\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make notes in octave " + (String)octaveNum + " the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed octave.\n";
			allowedOctaveToggles[octaveNum].setTooltip(toggleTooltip);
		}
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all octaves when generating\n";
		if (editModeIsSelectedStep)
			buttonTooltip += "a random pitch for the selected step in track " + (String)trackNum + "\n";
		else
			buttonTooltip += "a random pitch for all the steps in track " + (String)trackNum + "\n";
		toggleTooltip += "(when the track destination is an oscillator pitch).";
		button_ForAllowingAllOctaves.setTooltip(buttonTooltip);
	}
}

void AllowedOctavesForSeqTrackComponent::resized() {
	allowedOctaveToggles[0].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[1].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[2].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[3].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[4].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[5].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllOctaves.setBounds(GUI::bounds_RandomizationAllowAllOctavesForLFOandSeqStepButton);
}

void AllowedOctavesForSeqTrackComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
	auto editModeIsAllSteps{ randomizationOptions->editModeForSeqTrackIsAllSteps(trackNum) };
	auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };

	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForSeqTrack" + (String)trackNum + "_Octave")) {
		auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("Octave", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
				if (octaveNum == clickedOctaveNum) {
					allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
					if (editModeIsSelectedStep)
						randomizationOptions->setOctaveIsAllowedForSelectedStepInSeqTrack(octaveNum, selectedStep, trackNum);
					else
						randomizationOptions->setOctaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum);
				}
				else {
					allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
					if (editModeIsSelectedStep)
						randomizationOptions->setOctaveIsNotAllowedForSelectedStepInSeqTrack(octaveNum, selectedStep, trackNum);
					else
						randomizationOptions->setOctaveIsNotAllowedForAllStepsInSeqTrack(octaveNum, trackNum);
				}
			}
		}
		else {
			auto isAllowed{ button->getToggleState() };
			if (isAllowed)
				if (editModeIsSelectedStep)
					randomizationOptions->setOctaveIsAllowedForSelectedStepInSeqTrack(clickedOctaveNum, selectedStep, trackNum);
				else
					randomizationOptions->setOctaveIsAllowedForAllStepsInSeqTrack(clickedOctaveNum, trackNum);
			else
				if (editModeIsSelectedStep)
					randomizationOptions->setOctaveIsNotAllowedForSelectedStepInSeqTrack(clickedOctaveNum, selectedStep, trackNum);
				else
					randomizationOptions->setOctaveIsNotAllowedForAllStepsInSeqTrack(clickedOctaveNum, trackNum);
		}
		if (editModeIsSelectedStep && randomizationOptions->noOctaveIsAllowedForSelectedStepInSeqTrack(selectedStep, trackNum)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForSelectedStepInSeqTrack(clickedOctaveNum, selectedStep, trackNum);
		}
		if (editModeIsAllSteps && randomizationOptions->noOctaveIsAllowedForAllStepsInSeqTrack(trackNum)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForAllStepsInSeqTrack(clickedOctaveNum, trackNum);
		}
	}
	if (buttonID == ID::button_AllOctavesForSeqTrack.toString() + (String)trackNum) {
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
			allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
			if (editModeIsSelectedStep)
				randomizationOptions->setOctaveIsAllowedForSelectedStepInSeqTrack(octaveNum, selectedStep, trackNum);
			else
				randomizationOptions->setOctaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum);
		}
	}
}

void AllowedOctavesForSeqTrackComponent::valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) {
	if (propertyID.toString() == "editModeIsSelectedStepForSeqTrack" + (String)trackNum ||
		propertyID.toString() == "stepSelectedForEditingInSeqTrack" + (String)trackNum)
	{
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto editModeIsSelectedStep{ randomizationOptions->editModeForSeqTrackIsSelectedStep(trackNum) };
		auto selectedStep{ randomizationOptions->stepSelectedForEditingInSeqTrack(trackNum) };
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum) {
			if (editModeIsSelectedStep) {
				auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForSelectedStepInSeqTrack(octaveNum, selectedStep, trackNum) };
				allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
			}
			else {
				auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForAllStepsInSeqTrack(octaveNum, trackNum) };
				allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
			}
		}
		generateTooltips();
	}
}

AllowedOctavesForSeqTrackComponent::~AllowedOctavesForSeqTrackComponent() {
	button_ForAllowingAllOctaves.removeListener(this);
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOsAndSeqSteps; ++octaveNum)
		allowedOctaveToggles[octaveNum].removeListener(this);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackAllowedStepValuesTree(this);
}
