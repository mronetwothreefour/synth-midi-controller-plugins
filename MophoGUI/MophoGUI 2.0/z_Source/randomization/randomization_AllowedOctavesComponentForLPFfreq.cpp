#include "randomization_AllowedOctavesComponentForLPFfreq.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedOctavesComponentForLPFfreq::AllowedOctavesComponentForLPFfreq(UnexposedParameters* unexposedParams) :
	paramIndex{ InfoForExposedParameters::get().indexForParamID(ID::lpfFreq.toString()) },
	unexposedParams{ unexposedParams }
{
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	auto paramID{ ID::lpfFreq.toString() };

	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLPFfreq; ++octaveNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "For_" + paramID + "_Octave" + String(octaveNum) };
		allowedOctaveToggles[octaveNum].setComponentID(toggleID);
		auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForParam(octaveNum, paramIndex) };
		allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
		allowedOctaveToggles[octaveNum].addListener(this);
		addAndMakeVisible(allowedOctaveToggles[octaveNum]);
		allowedOctaveToggles[octaveNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		if (shouldShowDescriptions) {
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not notes in octave " + (String)octaveNum + " are allowed\n";
			toggleTooltip += "when a random LPF cutoff frequency is generated.\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make notes in octave " + (String)octaveNum + " the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed octave.";
			if (octaveNum == 13) {
				toggleTooltip += "\nNote: Only notes C through G# are available in octave 13.";
			}
			allowedOctaveToggles[octaveNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllOctaves.setComponentID(ID::button_AllOctavesFor_.toString() + paramID);
	button_ForAllowingAllOctaves.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all octaves when gener-\n";
		buttonTooltip += "ating a random LPF cutoff frequency.";
		button_ForAllowingAllOctaves.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllOctaves);

	setSize(GUI::randomizationAllowedOctavesForLPFfreqComponent_w, GUI::randomizationAllowedOctavesForLPFfreqComponent_h);
}

void AllowedOctavesComponentForLPFfreq::resized() {
	allowedOctaveToggles[0].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[1].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[2].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[3].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[4].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[5].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[6].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 6 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[7].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[8].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[9].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[10].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[11].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[12].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[13].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 6 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow2_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllOctaves.setBounds(GUI::bounds_RandomizationAllowAllOctavesForLPFfreqButton);
}

void AllowedOctavesComponentForLPFfreq::turnOffAllToggles() {
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLPFfreq; ++octaveNum)
		allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
}

void AllowedOctavesComponentForLPFfreq::restoreAllToggles() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLPFfreq; ++octaveNum) {
		auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForParam(octaveNum, paramIndex) };
		allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
	}
}

void AllowedOctavesComponentForLPFfreq::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "For_" + paramID + "_Octave")) {
		auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("_Octave", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLPFfreq; ++octaveNum) {
				if (octaveNum == clickedOctaveNum) {
					allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
					randomizationOptions->setOctaveIsAllowedForParam(octaveNum, paramIndex);
				}
				else {
					allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
					randomizationOptions->setOctaveIsNotAllowedForParam(octaveNum, paramIndex);
				}
			}
		}
		else {
			auto isAllowed{ button->getToggleState() };
			if (isAllowed)
				randomizationOptions->setOctaveIsAllowedForParam(clickedOctaveNum, paramIndex);
			else
				randomizationOptions->setOctaveIsNotAllowedForParam(clickedOctaveNum, paramIndex);
		}
		if (randomizationOptions->noOctaveIsAllowedForParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForParam(clickedOctaveNum, paramIndex);
		}
		randomizationOptions->checkIfHighestOctaveIsOnlyOneAllowedForParam(paramIndex);
		randomizationOptions->checkIfOnlyOneValueIsAllowedForLPFfreqParam();
	}
	if (buttonID == ID::button_AllOctavesFor_.toString() + paramID) {
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLPFfreq; ++octaveNum) {
			allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForParam(octaveNum, paramIndex);
		}
		randomizationOptions->setHighestOctaveIsNotOnlyOneAllowedForParam(paramIndex);
		randomizationOptions->setMoreThanOneValueIsAllowedForParam_z(paramIndex);
	}
}

AllowedOctavesComponentForLPFfreq::~AllowedOctavesComponentForLPFfreq() {
	button_ForAllowingAllOctaves.removeListener(this);
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLPFfreq; ++octaveNum)
		allowedOctaveToggles[octaveNum].removeListener(this);
}
