#include "randomization_LFOfreqOptionsComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



LFOfreqRandomizationOptionsComponent::LFOfreqRandomizationOptionsComponent(int lfoNum, UnexposedParameters* unexposedParams) :
	lfoNum{ lfoNum },
	unexposedParams{ unexposedParams },
	allowedNotes{ lfoNum, unexposedParams },
	allowedOctaves{ lfoNum, unexposedParams },
	allowedSyncedFreq{ lfoNum, unexposedParams },
	allowedUnsyncedFreq{ lfoNum, unexposedParams }
{
	jassert(lfoNum > 0 && lfoNum < 5);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	toggle_ForAllowingPitchedFreq.setComponentID(ID::component_ToggleButton_AllowPitchedFreqForLFO.toString());
	toggle_ForAllowingPitchedFreq.addListener(this);
	toggle_ForAllowingPitchedFreq.setToggleState(randomizationOptions->pitchedFreqAreAllowedForLFO(lfoNum), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingPitchedFreq);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not pitched frequencies are\n";
		toggleTooltip += "allowed when a random frequency is generated for\n";
		toggleTooltip += "LFO " + (String)lfoNum + ". At least one frequency category (pitched,\n";
		toggleTooltip += "un-synced, or synced) must be allowed.";
		toggle_ForAllowingPitchedFreq.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingUnsyncedFreq.setComponentID(ID::component_ToggleButton_AllowUnsyncedFreqForLFO.toString());
	toggle_ForAllowingUnsyncedFreq.addListener(this);
	toggle_ForAllowingUnsyncedFreq.setToggleState(randomizationOptions->unsyncedFreqAreAllowedForLFO(lfoNum), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingUnsyncedFreq);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not un-synced frequencies are\n";
		toggleTooltip += "allowed when a random frequency is generated for\n";
		toggleTooltip += "LFO " + (String)lfoNum + ". At least one frequency category (pitched,\n";
		toggleTooltip += "un-synced, or synced) must be allowed.";
		toggle_ForAllowingUnsyncedFreq.setTooltip(toggleTooltip);
	}

	toggle_ForAllowingSyncedFreq.setComponentID(ID::component_ToggleButton_AllowSyncedFreqForLFO.toString());
	toggle_ForAllowingSyncedFreq.addListener(this);
	toggle_ForAllowingSyncedFreq.setToggleState(randomizationOptions->syncedFreqAreAllowedForLFO(lfoNum), dontSendNotification);
	addAndMakeVisible(toggle_ForAllowingSyncedFreq);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "Toggles whether or not synced frequencies are\n";
		toggleTooltip += "allowed when a random frequency is generated for\n";
		toggleTooltip += "LFO " + (String)lfoNum + ". At least one frequency category (pitched,\n";
		toggleTooltip += "un-synced, or synced) must be allowed.";
		toggle_ForAllowingSyncedFreq.setTooltip(toggleTooltip);
	}

	addAndMakeVisible(allowedNotes);
	addAndMakeVisible(allowedOctaves);
	addAndMakeVisible(allowedUnsyncedFreq);
	addAndMakeVisible(allowedSyncedFreq);

	button_ForClosingLFOfreqOptionsComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingLFOfreqOptionsComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingLFOfreqOptionsComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingLFOfreqOptionsComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingLFOfreqOptionsComponent);

	setSize(GUI::editor_w, GUI::editor_h);
}

void LFOfreqRandomizationOptionsComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStreamForBackground{ BinaryData::RandomizationLFOOptionsBackground_png, BinaryData::RandomizationLFOOptionsBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStreamForBackground) };
	g.drawImageAt(backgroundImage, GUI::randomizationLFOoptionsBackground_x, GUI::randomizationLFOoptionsBackground_y);
	auto titleImageData{ getTitleImageData() };
	auto titleImageDataSize{ getTitleImageDataSize() };
	if (titleImageData != nullptr) {
		MemoryInputStream memInputStreamForTitle{ titleImageData, titleImageDataSize, false };
		auto titleImage{ imageFormat.decodeImage(memInputStreamForTitle) };
		g.drawImageAt(titleImage, GUI::randomizationLFOoptionsBackground_x, GUI::randomizationLFOoptionsBackground_y);
	}
}

const char* LFOfreqRandomizationOptionsComponent::getTitleImageData() {
	switch (lfoNum)
	{
	case 1:
		return BinaryData::TitleAllowedFreqForLFO1_png;
	case 2:
		return BinaryData::TitleAllowedFreqForLFO2_png;
	case 3:
		return BinaryData::TitleAllowedFreqForLFO3_png;
	case 4:
		return BinaryData::TitleAllowedFreqForLFO4_png;
	default:
		return nullptr;
	}
}

size_t LFOfreqRandomizationOptionsComponent::getTitleImageDataSize() {
	switch (lfoNum)
	{
	case 1:
		return BinaryData::TitleAllowedFreqForLFO1_pngSize;
	case 2:
		return BinaryData::TitleAllowedFreqForLFO2_pngSize;
	case 3:
		return BinaryData::TitleAllowedFreqForLFO3_pngSize;
	case 4:
		return BinaryData::TitleAllowedFreqForLFO4_pngSize;
	default:
		return size_t();
	}
}

void LFOfreqRandomizationOptionsComponent::resized() {
	toggle_ForAllowingPitchedFreq.setBounds(GUI::bounds_RandomizationAllowPitchedFreqToggle);
	toggle_ForAllowingUnsyncedFreq.setBounds(GUI::bounds_RandomizationAllowUnsyncedFreqToggle);
	toggle_ForAllowingSyncedFreq.setBounds(GUI::bounds_RandomizationAllowSyncedFreqToggle);
	allowedNotes.setBounds(GUI::bounds_RandomizationAllowedNotesForLFO);
	allowedOctaves.setBounds(GUI::bounds_RandomizationAllowedOctavesForLFO);
	allowedUnsyncedFreq.setBounds(GUI::bounds_RandomizationAllowedUnsyncedFreqForLFO);
	allowedSyncedFreq.setBounds(GUI::bounds_RandomizationAllowedSyncedFreqForLFO);
	button_ForClosingLFOfreqOptionsComponent.setBounds(GUI::bounds_RandomizationLFOoptionsCloseButton);
}

void LFOfreqRandomizationOptionsComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto toggledOn{ button->getToggleState() };
	if (buttonID == ID::component_ToggleButton_AllowPitchedFreqForLFO.toString()) {
		if (toggledOn) {
			randomizationOptions->setPitchedFreqAreAllowedForLFO(lfoNum);
			allowedNotes.restoreAllToggles();
			allowedNotes.setEnabled(true);
			allowedOctaves.restoreAllToggles();
			allowedOctaves.setEnabled(true);
		}
		else {
			randomizationOptions->setPitchedFreqAreNotAllowedForLFO(lfoNum);
			auto noFreqAllowed{ randomizationOptions->noFreqAreAllowedForLFO(lfoNum) };
			if (noFreqAllowed) {
				randomizationOptions->setPitchedFreqAreAllowedForLFO(lfoNum);
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
	if (buttonID == ID::component_ToggleButton_AllowSyncedFreqForLFO.toString()) {
		if (toggledOn) {
			randomizationOptions->setSyncedFreqAreAllowedForLFO(lfoNum);
			allowedSyncedFreq.restoreAllToggles();
			allowedSyncedFreq.setEnabled(true);
		}
		else {
			randomizationOptions->setSyncedFreqAreNotAllowedForLFO(lfoNum);
			auto noFreqAllowed{ randomizationOptions->noFreqAreAllowedForLFO(lfoNum) };
			if (noFreqAllowed) {
				randomizationOptions->setSyncedFreqAreAllowedForLFO(lfoNum);
				button->setToggleState(true, dontSendNotification);
			}
			else {
				allowedSyncedFreq.turnOffAllToggles();
				allowedSyncedFreq.setEnabled(false);
			}
		}
	}
	if (buttonID == ID::component_ToggleButton_AllowUnsyncedFreqForLFO.toString()) {
		if (toggledOn) {
			randomizationOptions->setUnsyncedFreqAreAllowedForLFO(lfoNum);
			allowedUnsyncedFreq.setEnabled(true);
		}
		else {
			auto noFreqAllowed{ randomizationOptions->noFreqAreAllowedForLFO(lfoNum) };
			if (noFreqAllowed) {
				randomizationOptions->setUnsyncedFreqAreAllowedForLFO(lfoNum);
				button->setToggleState(true, dontSendNotification);
			}
			else {
				randomizationOptions->setUnsyncedFreqAreNotAllowedForLFO(lfoNum);
				allowedUnsyncedFreq.setEnabled(false);
			}
		}
	}
}

void LFOfreqRandomizationOptionsComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

LFOfreqRandomizationOptionsComponent::~LFOfreqRandomizationOptionsComponent() {
	toggle_ForAllowingPitchedFreq.removeListener(this);
	toggle_ForAllowingSyncedFreq.removeListener(this);
	toggle_ForAllowingUnsyncedFreq.removeListener(this);
}
