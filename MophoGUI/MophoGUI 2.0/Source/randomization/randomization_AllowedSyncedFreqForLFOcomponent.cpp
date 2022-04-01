#include "randomization_AllowedSyncedFreqForLFOcomponent.h"

#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



AllowedSyncedFreqForLFOcomponent::AllowedSyncedFreqForLFOcomponent(int lfoNum, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	unexposedParams{ unexposedParams }
{
	jassert(lfoNum > 0 && lfoNum < 5);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto syncedFreqAreAllowed{ randomizationOptions->syncedFreqAreAllowedForLFO(lfoNum) };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		auto toggleID{ ID::component_ToggleButton.toString() + "ForLFO" + (String)lfoNum + "_SyncedFreq" + String(freqNum) };
		allowedSyncedFreqToggles[freqNum].setComponentID(toggleID);
		if (syncedFreqAreAllowed) {
			auto syncedFreqIsAllowed{ randomizationOptions->syncedFreqIsAllowedForLFO(freqNum, lfoNum) };
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
			toggleTooltip += "a random synced frequency is generated for LFO " + (String)lfoNum + ".\n";
			toggleTooltip += "Holding down the CTRL key when clicking the toggle will\n";
			toggleTooltip += "make this the only synced frequency allowed. There\n";
			toggleTooltip += "must always be at least one allowed synced frequency.";
			allowedSyncedFreqToggles[freqNum].setTooltip(toggleTooltip);
		}
	}

	button_ForAllowingAllSyncedFreq.setComponentID(ID::button_AllSyncedFreqForLFO.toString() + (String)lfoNum);
	button_ForAllowingAllSyncedFreq.addListener(this);
	if (tooltipOptions->shouldShowDescriptions()) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all synced frequencies when generating\n";
		buttonTooltip += "a random synced frequency for LFO " + (String)lfoNum + ".";
		button_ForAllowingAllSyncedFreq.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllSyncedFreq);

	setSize(GUI::randomizationAllowedSyncedFreqForLFOComponent_w, GUI::randomizationAllowedSyncedFreqForLFOComponent_h);
}

void AllowedSyncedFreqForLFOcomponent::resized() {
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		auto toggle_x{ freqNum % 4 * GUI::randomizationAllowedSyncedFreqToggle_ColSpacing };
		auto toggle_y{ freqNum % 4 * GUI::randomizationAllowedSyncedFreqToggle_RowSpacing };
		allowedSyncedFreqToggles[freqNum].setBounds(toggle_x, toggle_y, GUI::toggle_diameter, GUI::toggle_diameter);
	}

	button_ForAllowingAllSyncedFreq.setBounds(GUI::bounds_RandomizationAllowAllSyncedButton);
}

void AllowedSyncedFreqForLFOcomponent::turnOffAllToggles() {
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		allowedSyncedFreqToggles[freqNum].setToggleState(false, dontSendNotification);
	}
}

void AllowedSyncedFreqForLFOcomponent::restoreAllToggles() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		auto freqIsAllowed{ randomizationOptions->syncedFreqIsAllowedForLFO(freqNum, lfoNum) };
		allowedSyncedFreqToggles[freqNum].setToggleState(freqIsAllowed, dontSendNotification);
	}
}

void AllowedSyncedFreqForLFOcomponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto syncedFreqAreAllowed{ randomizationOptions->syncedFreqAreAllowedForLFO(lfoNum) };
	if (buttonID.startsWith(ID::component_ToggleButton.toString() + "ForLFO" + (String)lfoNum + "_SyncedFreq")) {
		if (syncedFreqAreAllowed) {
			auto clickedFreqNum{ buttonID.fromFirstOccurrenceOf("Freq", false, false).getIntValue() };
			if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
				for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
					if (freqNum == clickedFreqNum) {
						allowedSyncedFreqToggles[freqNum].setToggleState(true, dontSendNotification);
						randomizationOptions->setSyncedFreqIsAllowedForLFO(freqNum, lfoNum);
					}
					else {
						allowedSyncedFreqToggles[freqNum].setToggleState(false, dontSendNotification);
						randomizationOptions->setSyncedFreqIsNotAllowedForLFO(freqNum, lfoNum);
					}
				}
			}
			else {
				auto isAllowed{ button->getToggleState() };
				if (isAllowed)
					randomizationOptions->setSyncedFreqIsAllowedForLFO(clickedFreqNum, lfoNum);
				else
					randomizationOptions->setSyncedFreqIsNotAllowedForLFO(clickedFreqNum, lfoNum);
			}
			if (randomizationOptions->noSyncedFreqAreAllowedForLFO(lfoNum)) {
				button->setToggleState(true, dontSendNotification);
				randomizationOptions->setSyncedFreqIsAllowedForLFO(clickedFreqNum, lfoNum);
			}
		}
		else
			button->setToggleState(false, dontSendNotification);
	}
	if (buttonID == ID::button_AllSyncedFreqForLFO.toString() + (String)lfoNum) {
		if (syncedFreqAreAllowed) {
			for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
				allowedSyncedFreqToggles[freqNum].setToggleState(true, dontSendNotification);
				randomizationOptions->setSyncedFreqIsAllowedForLFO(freqNum, lfoNum);
			}
		}
	}
}

AllowedSyncedFreqForLFOcomponent::~AllowedSyncedFreqForLFOcomponent() {
	button_ForAllowingAllSyncedFreq.removeListener(this);
	for (auto freqNum = 0; freqNum != randomization::numberOfSyncedFreqForLFOs; ++freqNum) {
		allowedSyncedFreqToggles[freqNum].removeListener(this);
	}
}
