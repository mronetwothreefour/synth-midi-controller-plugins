#include "randomization_AllowedOctavesComponentForLFOfreq.h"

#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedOctavesComponentForLFOfreq::AllowedOctavesComponentForLFOfreq(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String paramName{ info.exposedNameFor(paramIndex) };
	String lfoName{ paramName.upToFirstOccurrenceOf(" Frequency", false, false) };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum) {
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
			toggleTooltip += "when a random pitched frequency is generated for " + lfoName + ".\n";
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

	button_ForAllowingAllOctaves.setComponentID(ID::button_AllOctavesFor_.toString() + paramID);
	button_ForAllowingAllOctaves.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all octaves when generating a\n";
		buttonTooltip += "random pitched frequency for " + lfoName + ".";
		button_ForAllowingAllOctaves.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllOctaves);

	setSize(GUI::randomizationAllowedOctavesForLFOandSeqTrackComponents_w, GUI::randomizationAllowedOctavesForLFOandSeqTrackComponents_h);
}

void AllowedOctavesComponentForLFOfreq::resized() {
	allowedOctaveToggles[0].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[1].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[2].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 2 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[3].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 3 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[4].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 4 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedOctaveToggles[5].setBounds(GUI::randomizationAllowedOctaveToggleRow1_x + 5 * GUI::randomizationOptionsToggles_horizSpacing, GUI::randomizationAllowedOctaveToggleRow1_y, GUI::toggle_diameter, GUI::toggle_diameter);

	button_ForAllowingAllOctaves.setBounds(GUI::bounds_RandomizationAllowAllOctavesForLFOandSeqStepButton);
}

void AllowedOctavesComponentForLFOfreq::turnOffAllToggles() {
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum)
		allowedOctaveToggles[octaveNum].setToggleState(false, dontSendNotification);
}

void AllowedOctavesComponentForLFOfreq::restoreAllToggles() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum) {
		auto octaveIsAllowed{ randomizationOptions->octaveIsAllowedForParam(octaveNum, paramIndex) };
		allowedOctaveToggles[octaveNum].setToggleState(octaveIsAllowed, dontSendNotification);
	}
}

void AllowedOctavesComponentForLFOfreq::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "For_" + paramID + "_Octave")) {
		auto clickedOctaveNum{ buttonID.fromFirstOccurrenceOf("_Octave", false, false).getIntValue() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum) {
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
		randomizationOptions->checkIfOnlyOneValueIsAllowedForLFOfreqParam(paramIndex);
	}
	if (buttonID == ID::button_AllOctavesFor_.toString() + paramID) {
		for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum) {
			allowedOctaveToggles[octaveNum].setToggleState(true, dontSendNotification);
			randomizationOptions->setOctaveIsAllowedForParam(octaveNum, paramIndex);
		}
	}
}

AllowedOctavesComponentForLFOfreq::~AllowedOctavesComponentForLFOfreq() {
	button_ForAllowingAllOctaves.removeListener(this);
	for (auto octaveNum = 0; octaveNum != randomization::numberOfOctavesForLFOfreqAndSeqSteps; ++octaveNum)
		allowedOctaveToggles[octaveNum].removeListener(this);
}
