#include "randomization_OptionsComponent_LPFfreq.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_LPFfreq::RandomizationOptionsComponent_LPFfreq(UnexposedParameters* unexposedParams) :
	paramIndex{ InfoForExposedParameters::get().indexForParamID(ID::lpfFreq.toString()) },
	unexposedParams{ unexposedParams },
	allowedNotes{ paramIndex, unexposedParams },
	allowedOctaves{  unexposedParams },
	valueRange{ unexposedParams }
{
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };

	valueRangeModeToggle.setComponentID(ID::component_ToggleButton_ValueRangeModeFor_.toString() + paramID);
	valueRangeModeToggle.addListener(this);
	valueRangeModeToggle.setToggleState(randomizationOptions->randomizationModeForLPFfreqIsValueRange(), dontSendNotification);
	valueRangeModeToggle.setRadioGroupId(2, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "In this mode, only frequencies within the specified range\n";
		toggleTooltip += "can be randomly generated for the LPF cutoff frequency.";
		valueRangeModeToggle.setTooltip(toggleTooltip);
	}
	addAndMakeVisible(valueRangeModeToggle);

	pitchesModeToggle.setComponentID(ID::component_ToggleButton_PitchesModeFor_.toString() + paramID);
	pitchesModeToggle.addListener(this);
	pitchesModeToggle.setToggleState(randomizationOptions->randomizationModeForLPFfreqIsPitches(), dontSendNotification);
	pitchesModeToggle.setRadioGroupId(2, dontSendNotification);
	if (shouldShowDescriptions) {
		String toggleTooltip{ "" };
		toggleTooltip += "In this mode, randomly generated frequencies for the LPF cutoff frequency\n";
		toggleTooltip += "can be restricted to the specified notes within the specified octaves.";
		pitchesModeToggle.setTooltip(toggleTooltip);
	}
	addAndMakeVisible(pitchesModeToggle);

	addAndMakeVisible(valueRange);
	if (randomizationOptions->randomizationModeForLPFfreqIsPitches()) {
		valueRange.setEnabled(false);
	}

	addAndMakeVisible(allowedNotes);
	addAndMakeVisible(allowedOctaves);
	if (randomizationOptions->randomizationModeForLPFfreqIsValueRange()) {
		allowedNotes.turnOffAllToggles();
		allowedNotes.setEnabled(false);
		allowedOctaves.turnOffAllToggles();
		allowedOctaves.setEnabled(false);
	}

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingComponent);

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationOptionsComponent_LPFfreq::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawEllipse((float)controlCenter.x - 20.0f, (float)controlCenter.y - 20.0f, GUI::knob_diameter, GUI::knob_diameter, 2);
	MemoryInputStream memInputStream{ BinaryData::RandomizationOptionsLPFfreqBackground_png, BinaryData::RandomizationOptionsLPFfreqBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 88, 200);
}

void RandomizationOptionsComponent_LPFfreq::resized() {
	valueRangeModeToggle.setBounds(GUI::bounds_RandomizationValueRangeModeToggleForLPFfreq);
	pitchesModeToggle.setBounds(GUI::bounds_RandomizationPitchesModeToggleForLPFfreq);
	valueRange.setBounds(GUI::bounds_RandomizationValueRangeForLPFfreq);
	allowedNotes.setBounds(GUI::bounds_RandomizationAllowedNotesForLPFfreq);
	allowedOctaves.setBounds(GUI::bounds_RandomizationAllowedOctavesForLPFfreq);
	button_ForClosingComponent.setBounds(GUI::bounds_RandomizationLPFfreqOptionsCloseButton);
}

void RandomizationOptionsComponent_LPFfreq::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto toggledOn{ button->getToggleState() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	if (buttonID == ID::component_ToggleButton_ValueRangeModeFor_.toString() + paramID) {
		if (toggledOn) {
			randomizationOptions->setRandomizationModeForLPFfreqToValueRange();
			valueRange.setEnabled(true);
			allowedNotes.turnOffAllToggles();
			allowedNotes.setEnabled(false);
			allowedOctaves.turnOffAllToggles();
			allowedOctaves.setEnabled(false);
		}
	}
	if (buttonID == ID::component_ToggleButton_PitchesModeFor_.toString() + paramID) {
		if (toggledOn) {
			randomizationOptions->setRandomizationModeForLPFfreqToPitches();
			valueRange.setEnabled(false);
			allowedNotes.restoreAllToggles();
			allowedNotes.setEnabled(true);
			allowedOctaves.restoreAllToggles();
			allowedOctaves.setEnabled(true);
		}
	}
}

void RandomizationOptionsComponent_LPFfreq::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

RandomizationOptionsComponent_LPFfreq::~RandomizationOptionsComponent_LPFfreq() {
	valueRangeModeToggle.removeListener(this);
	pitchesModeToggle.removeListener(this);
}
