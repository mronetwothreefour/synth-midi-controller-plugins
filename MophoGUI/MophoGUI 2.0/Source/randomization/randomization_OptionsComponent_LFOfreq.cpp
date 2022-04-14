#include "randomization_OptionsComponent_LFOfreq.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_LFOfreq::RandomizationOptionsComponent_LFOfreq(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	allowedNotes{ paramIndex, unexposedParams },
	allowedOctaves{ paramIndex, unexposedParams },
	allowedSyncedFreq{ paramIndex, unexposedParams },
	allowedUnsyncedFreq{ paramIndex, unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.randomizationOptionsTypeFor(paramIndex) == RandomizationOptionsType::lfoFreq);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	String paramName{ info.exposedNameFor(paramIndex) };
	String lfoName{ paramName.upToFirstOccurrenceOf(" Frequency", false, false) };

	toggle_ForAllowingPitchedFreq.setComponentID(ID::component_ToggleButton_AllowPitchedFreqFor_.toString() + paramID);
	toggle_ForAllowingPitchedFreq.addListener(this);
	toggle_ForAllowingPitchedFreq.setToggleState(randomizationOptions->pitchedFreqAreAllowedForParam(paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingPitchedFreq);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not pitched frequencies are\n";
		toggleTooltip += "allowed when a random frequency is generated for\n";
		toggleTooltip += lfoName + ". At least one frequency category (pitched,\n";
		toggleTooltip += "un-synced, or synced) must be allowed.";
		toggle_ForAllowingPitchedFreq.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingUnsyncedFreq.setComponentID(ID::component_ToggleButton_AllowUnsyncedFreqFor_.toString() + paramID);
	toggle_ForAllowingUnsyncedFreq.addListener(this);
	toggle_ForAllowingUnsyncedFreq.setToggleState(randomizationOptions->unsyncedFreqAreAllowedForParam(paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingUnsyncedFreq);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not un-synced frequencies are\n";
		toggleTooltip += "allowed when a random frequency is generated for\n";
		toggleTooltip += lfoName + ". At least one frequency category (pitched,\n";
		toggleTooltip += "un-synced, or synced) must be allowed.";
		toggle_ForAllowingUnsyncedFreq.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingSyncedFreq.setComponentID(ID::component_ToggleButton_AllowSyncedFreqFor_.toString() + paramID);
	toggle_ForAllowingSyncedFreq.addListener(this);
	toggle_ForAllowingSyncedFreq.setToggleState(randomizationOptions->syncedFreqAreAllowedForParam(paramIndex), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingSyncedFreq);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not synced frequencies are\n";
		toggleTooltip += "allowed when a random frequency is generated for\n";
		toggleTooltip += lfoName + ". At least one frequency category (pitched,\n";
		toggleTooltip += "un-synced, or synced) must be allowed.";
		toggle_ForAllowingSyncedFreq.setTooltip(toggleTooltip);
	}

	addAndMakeVisible(allowedNotes);
	addAndMakeVisible(allowedOctaves);
	addAndMakeVisible(allowedUnsyncedFreq);
	addAndMakeVisible(allowedSyncedFreq);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingComponent);

	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	background_x = controlCenter.x - GUI::knob_diameter / 2;
	background_y = 147;

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationOptionsComponent_LFOfreq::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	MemoryInputStream memInputStream{ BinaryData::RandomizationOptionsLFOfreqBackground_png, BinaryData::RandomizationOptionsLFOfreqBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, background_x, background_y);
}

void RandomizationOptionsComponent_LFOfreq::resized() {
	toggle_ForAllowingPitchedFreq.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_AllowPitchedToggle_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_AllowPitchedToggle_y, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_ForAllowingUnsyncedFreq.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_AllowUnsyncedToggle_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_AllowUnsyncedToggle_y, GUI::toggle_diameter, GUI::toggle_diameter);
	toggle_ForAllowingSyncedFreq.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_AllowSyncedToggle_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_AllowSyncedToggle_y, GUI::toggle_diameter, GUI::toggle_diameter);
	allowedNotes.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_AllowedNotes_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_AllowedNotes_y, GUI::randomizationAllowedNotesComponent_w, GUI::randomizationAllowedNotesComponent_h);
	allowedOctaves.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_AllowedOctaves_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_AllowedOctaves_y, GUI::randomizationAllowedOctavesComponent_w, GUI::randomizationAllowedOctavesComponent_h);
	allowedUnsyncedFreq.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_AllowedUnsynced_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_AllowedUnsynced_y, GUI::randomizationAllowedUnsyncedFreqComponent_w, GUI::randomizationAllowedUnsyncedFreqComponent_h);
	allowedSyncedFreq.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_AllowedSynced_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_AllowedSynced_y, GUI::randomizationAllowedSyncedFreqComponent_w, GUI::randomizationAllowedSyncedFreqComponent_h);
	button_ForClosingComponent.setBounds(background_x + GUI::randomizationOptionsComponent_LFOfreq_CloseButton_x, background_y + GUI::randomizationOptionsComponent_LFOfreq_CloseButton_y, GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
}

void RandomizationOptionsComponent_LFOfreq::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto toggledOn{ button->getToggleState() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	if (buttonID == ID::component_ToggleButton_AllowPitchedFreqFor_.toString() + paramID) {
		if (toggledOn) {
			randomizationOptions->setPitchedFreqAreAllowedForParam(paramIndex);
			allowedNotes.restoreAllToggles();
			allowedNotes.setEnabled(true);
			allowedOctaves.restoreAllToggles();
			allowedOctaves.setEnabled(true);
		}
		else {
			randomizationOptions->setPitchedFreqAreNotAllowedForParam(paramIndex);
			auto noFreqAllowed{ randomizationOptions->noFreqAreAllowedForParam(paramIndex) };
			if (noFreqAllowed) {
				randomizationOptions->setPitchedFreqAreAllowedForParam(paramIndex);
				button->setToggleState(true, dontSendNotification);
			}
			else {
				allowedNotes.turnOffAllToggles();
				allowedNotes.setEnabled(false);
				allowedOctaves.turnOffAllToggles();
				allowedOctaves.setEnabled(false);
			}
		}
	}
	if (buttonID == ID::component_ToggleButton_AllowSyncedFreqFor_.toString() + paramID) {
		if (toggledOn) {
			randomizationOptions->setSyncedFreqAreAllowedForParam(paramIndex);
			allowedSyncedFreq.restoreAllToggles();
			allowedSyncedFreq.setEnabled(true);
		}
		else {
			randomizationOptions->setSyncedFreqAreNotAllowedForParam(paramIndex);
			auto noFreqAllowed{ randomizationOptions->noFreqAreAllowedForParam(paramIndex) };
			if (noFreqAllowed) {
				randomizationOptions->setSyncedFreqAreAllowedForParam(paramIndex);
				button->setToggleState(true, dontSendNotification);
			}
			else {
				allowedSyncedFreq.turnOffAllToggles();
				allowedSyncedFreq.setEnabled(false);
			}
		}
	}
	if (buttonID == ID::component_ToggleButton_AllowUnsyncedFreqFor_.toString() + paramID) {
		if (toggledOn) {
			randomizationOptions->setUnsyncedFreqAreAllowedForParam(paramIndex);
			allowedUnsyncedFreq.setEnabled(true);
		}
		else {
			auto noFreqAllowed{ randomizationOptions->noFreqAreAllowedForParam(paramIndex) };
			if (noFreqAllowed) {
				randomizationOptions->setUnsyncedFreqAreAllowedForParam(paramIndex);
				button->setToggleState(true, dontSendNotification);
			}
			else {
				randomizationOptions->setUnsyncedFreqAreNotAllowedForParam(paramIndex);
				allowedUnsyncedFreq.setEnabled(false);
			}
		}
	}
}

void RandomizationOptionsComponent_LFOfreq::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

RandomizationOptionsComponent_LFOfreq::~RandomizationOptionsComponent_LFOfreq() {
	toggle_ForAllowingPitchedFreq.removeListener(this);
	toggle_ForAllowingSyncedFreq.removeListener(this);
	toggle_ForAllowingUnsyncedFreq.removeListener(this);
}
