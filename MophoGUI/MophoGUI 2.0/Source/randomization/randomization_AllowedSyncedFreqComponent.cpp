#include "randomization_AllowedSyncedFreqComponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedSyncedFreqComponent::AllowedSyncedFreqComponent(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto optionsType{ info.randomizationOptionsTypeFor(paramIndex) };
	jassert(optionsType == RandomizationOptionsType::lfoFreq);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto syncedFreqAreAllowed{ randomizationOptions->syncedFreqAreAllowedForParam(paramIndex) };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String paramName{ info.exposedNameFor(paramIndex) };
	String lfoName{ paramName.upToFirstOccurrenceOf(" Frequency", false, false) };

	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "For_" + paramID + "_SyncedFreq" + String(freqNum) };
		allowedSyncedFreqToggles[freqNum].setComponentID(toggleID);
		if (syncedFreqAreAllowed) {
			auto syncedFreqIsAllowed{ randomizationOptions->syncedFreqIsAllowedForParam(freqNum, paramIndex) };
			allowedSyncedFreqToggles[freqNum].setToggleState(syncedFreqIsAllowed, dontSendNotification);
		}
		else
			allowedSyncedFreqToggles[freqNum].setToggleState(false, dontSendNotification);
		allowedSyncedFreqToggles[freqNum].addListener(this);
		addAndMakeVisible(allowedSyncedFreqToggles[freqNum]);
		allowedSyncedFreqToggles[freqNum].setSize(GUI::toggle_diameter, GUI::toggle_diameter);
		if (shouldShowDescriptions) {
			auto intToLFOfreqString{ IntToLFOfreqString::get() };
			auto offsetFreqNum{ freqNum + params::firstSyncedLFOfreq };
			auto syncedFreqRatio{ intToLFOfreqString->convert((uint8)offsetFreqNum) };
			auto syncedFreqDescription{ intToLFOfreqString->verboseConvert((uint8)offsetFreqNum).fromFirstOccurrenceOf(": ", false, false) };
			String toggleTooltip{ "" };
			toggleTooltip += "Toggles whether or not synced frequency " + syncedFreqRatio + "\n";
			toggleTooltip += "(" + syncedFreqDescription + ") is allowed when\n";
			toggleTooltip += "a random synced frequency is generated for " + lfoName + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle will\n";
			toggleTooltip += "make this the only synced frequency allowed. There\n";
			toggleTooltip += "must always be at least one allowed synced frequency.";
			allowedSyncedFreqToggles[freqNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllSyncedFreq.setComponentID(ID::button_AllSyncedFreqFor_.toString() + paramID);
	button_ForAllowingAllSyncedFreq.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all synced frequencies when generating\n";
		buttonTooltip += "a random synced frequency for " + lfoName + + ".";
		button_ForAllowingAllSyncedFreq.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllSyncedFreq);

	setSize(GUI::randomizationAllowedSyncedFreqComponent_w, GUI::randomizationAllowedSyncedFreqComponent_h);
}

void AllowedSyncedFreqComponent::resized() {
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		auto toggle_x{ freqNum / 4 * GUI::randomizationAllowedSyncedFreqToggle_ColSpacing };
		auto toggle_y{ freqNum % 4 * GUI::randomizationAllowedSyncedFreqToggle_RowSpacing };
		allowedSyncedFreqToggles[freqNum].setBounds(toggle_x, toggle_y, GUI::toggle_diameter, GUI::toggle_diameter);
	}

	button_ForAllowingAllSyncedFreq.setBounds(GUI::bounds_RandomizationAllowAllSyncedButton);
}

void AllowedSyncedFreqComponent::turnOffAllToggles() {
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		allowedSyncedFreqToggles[freqNum].setToggleState(false, dontSendNotification);
	}
}

void AllowedSyncedFreqComponent::restoreAllToggles() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		auto freqIsAllowed{ randomizationOptions->syncedFreqIsAllowedForParam(freqNum, paramIndex) };
		allowedSyncedFreqToggles[freqNum].setToggleState(freqIsAllowed, dontSendNotification);
	}
}

void AllowedSyncedFreqComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto syncedFreqAreAllowed{ randomizationOptions->syncedFreqAreAllowedForParam(paramIndex) };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "For_" + paramID + "_SyncedFreq")) {
		if (syncedFreqAreAllowed) {
			auto clickedFreqNum{ buttonID.fromFirstOccurrenceOf("SyncedFreq", false, false).getIntValue() };
			if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
				for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
					if (freqNum == clickedFreqNum) {
						allowedSyncedFreqToggles[freqNum].setToggleState(true, dontSendNotification);
						randomizationOptions->setSyncedFreqIsAllowedForParam(freqNum, paramIndex);
					}
					else {
						allowedSyncedFreqToggles[freqNum].setToggleState(false, dontSendNotification);
						randomizationOptions->setSyncedFreqIsNotAllowedForParam(freqNum, paramIndex);
					}
				}
			}
			else {
				auto isAllowed{ button->getToggleState() };
				if (isAllowed)
					randomizationOptions->setSyncedFreqIsAllowedForParam(clickedFreqNum, paramIndex);
				else
					randomizationOptions->setSyncedFreqIsNotAllowedForParam(clickedFreqNum, paramIndex);
			}
			if (randomizationOptions->noSyncedFreqAreAllowedForParam(paramIndex)) {
				button->setToggleState(true, dontSendNotification);
				randomizationOptions->setSyncedFreqIsAllowedForParam(clickedFreqNum, paramIndex);
			}
		}
		else
			button->setToggleState(false, dontSendNotification);
		randomizationOptions->checkIfOnlyOneValueIsAllowedForLFOfreqParam(paramIndex);
	}
	if (buttonID == ID::button_AllSyncedFreqFor_.toString() + paramID) {
		if (syncedFreqAreAllowed) {
			for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
				allowedSyncedFreqToggles[freqNum].setToggleState(true, dontSendNotification);
				randomizationOptions->setSyncedFreqIsAllowedForParam(freqNum, paramIndex);
			}
		}
	}
}

AllowedSyncedFreqComponent::~AllowedSyncedFreqComponent() {
	button_ForAllowingAllSyncedFreq.removeListener(this);
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		allowedSyncedFreqToggles[freqNum].removeListener(this);
	}
}
