#include "randomization_AllowedOctavesComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedOctavesComponent::AllowedOctavesComponent(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::pitch);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String paramName{ "" };
	if (paramID.contains("push"))
		paramName = "the Push It! switch";
	else {
		paramName = "oscillator ";
		paramName += paramID.contains("1") ? "1" : "2";
	}
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctaves; ++octaveNum) {
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
			toggleTooltip += "when a random pitch is generated for " + paramName + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle\n";
			toggleTooltip += "will make notes in octave " + (String)octaveNum + " the only ones allowed.\n";
			toggleTooltip += "There must always be at least one allowed octave.\n";
			if (octaveNum == 10) {
				toggleTooltip += "Note: C is the only note in octave 10. If only octave 10\n";
				toggleTooltip += "is allowed, a pitch of C 10 will always be produced.";
			}
			allowedOctaveToggles[octaveNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllOctaves.setComponentID(ID::button_AllOctavesFor_.toString() + paramID);
	button_ForAllowingAllOctaves.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all octaves when generating\n";
		buttonTooltip += "a random pitch for " + paramName + ".";
		button_ForAllowingAllOctaves.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllOctaves);

	setSize(GUI::randomizationAllowedOctavesComponent_w, GUI::randomizationAllowedOctavesComponent_h);
}

void AllowedOctavesComponent::resized() {
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

void AllowedOctavesComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "For_" + paramID + "_Octave")) {
		auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("Octave", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctaves; ++octaveNum) {
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
		randomizationOptions->checkIfOnlyOneValueIsAllowedForPitchParam(paramIndex);
	}
	if (buttonID == ID::button_AllOctavesFor_.toString() + paramID) {
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctaves; ++octaveNum) {
			allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForParam(octaveNum, paramIndex);
		}
		randomizationOptions->setHighestOctaveIsNotOnlyOneAllowedForParam(paramIndex);
		randomizationOptions->setMoreThanOneValueIsAllowedForParam(paramIndex);
	}
}

AllowedOctavesComponent::~AllowedOctavesComponent() {
	button_ForAllowingAllOctaves.removeListener(this);
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctaves; ++octaveNum) {
		allowedOctaveToggles[octaveNum].removeListener(this);
	}
}
