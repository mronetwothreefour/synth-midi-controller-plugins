#include "RandomizationComponent.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../widgets_ControlsForParameters/widget_ControlTypes.h"

using namespace constants;



RandomizationComponent::RandomizationComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	button_ForLockingAllParameters{ this, unexposedParams },
	button_ForUnlockingAllParameters{ this, unexposedParams },
	button_ForLockingAllVoiceNameChars{ this, unexposedParams },
	button_ForUnlockingAllVoiceNameChars{ this, unexposedParams },
	button_ForLockingAllStepsInSeqTrack1{ 1, this, unexposedParams },
	button_ForLockingAllStepsInSeqTrack2{ 2, this, unexposedParams },
	button_ForLockingAllStepsInSeqTrack3{ 3, this, unexposedParams },
	button_ForLockingAllStepsInSeqTrack4{ 4, this, unexposedParams },
	button_ForUnlockingAllStepsInSeqTrack1{ 1, this, unexposedParams },
	button_ForUnlockingAllStepsInSeqTrack2{ 2, this, unexposedParams },
	button_ForUnlockingAllStepsInSeqTrack3{ 3, this, unexposedParams },
	button_ForUnlockingAllStepsInSeqTrack4{ 4, this, unexposedParams },
	button_ForRandomizingUnlockedParameters{ this, unexposedParams }
{
	addAndMakeVisible(button_ForLockingAllParameters);
	addAndMakeVisible(button_ForUnlockingAllParameters);
	addAndMakeVisible(button_ForRandomizingUnlockedParameters);
	addAndMakeVisible(button_ForLockingAllVoiceNameChars);
	addAndMakeVisible(button_ForUnlockingAllVoiceNameChars);
	addAndMakeVisible(button_ForLockingAllStepsInSeqTrack1);
	addAndMakeVisible(button_ForLockingAllStepsInSeqTrack2);
	addAndMakeVisible(button_ForLockingAllStepsInSeqTrack3);
	addAndMakeVisible(button_ForLockingAllStepsInSeqTrack4);
	addAndMakeVisible(button_ForUnlockingAllStepsInSeqTrack1);
	addAndMakeVisible(button_ForUnlockingAllStepsInSeqTrack2);
	addAndMakeVisible(button_ForUnlockingAllStepsInSeqTrack3);
	addAndMakeVisible(button_ForUnlockingAllStepsInSeqTrack4);

	button_ForClosingRandomizationComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingRandomizationComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingRandomizationComponent.onClick = [this] { hideThisComponent(); };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions())
		button_ForClosingRandomizationComponent.setTooltip("Click to close the Randomize\nProgram Settings window.");
	addAndMakeVisible(button_ForClosingRandomizationComponent);

	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		setUpParamLockToggleButton(param);
		addAndMakeVisible(paramLockToggleButtons[param]);
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationComponent::setUpParamLockToggleButton(uint8 param) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(param).toString() };
	if (info.controlTypeFor(param) == ControlType::comboBox) {
		paramLockToggleButtons[param].setComponentID("lockButtonForComboBox_" + paramID);
		paramLockToggleButtons[param].setSize(info.controlWidthFor(param), GUI::lockIcon_h);
	}
	if (info.controlTypeFor(param) == ControlType::knobForPitchWithValueStringDisplay ||
		info.controlTypeFor(param) == ControlType::knobWithValueStringDisplay ||
		info.controlTypeFor(param) == ControlType::knobWithWaveShapeDisplay) {
		paramLockToggleButtons[param].setComponentID("lockButtonForKnob_" + paramID);
		paramLockToggleButtons[param].setSize(GUI::knobLockButton_diameter, GUI::knobLockButton_diameter);
	}
	if (info.controlTypeFor(param) == ControlType::sequencerStep) {
		paramLockToggleButtons[param].setComponentID("lockButtonForSeqStep_" + paramID);
		paramLockToggleButtons[param].setSize(GUI::seqSteps_w, GUI::seqSteps_h);
	}
	if (info.controlTypeFor(param) == ControlType::toggleButton) {
		paramLockToggleButtons[param].setComponentID("lockButtonForToggle_" + paramID);
		paramLockToggleButtons[param].setSize(GUI::toggleLockButton_diameter, GUI::toggleLockButton_diameter);
		if (info.IDfor(param).toString() == "arpegOnOff" || info.IDfor(param).toString() == "sequencerOnOff")
			paramLockToggleButtons[param].addListener(this);
	}
	if (info.controlTypeFor(param) == ControlType::voiceNameChar) {
		paramLockToggleButtons[param].setComponentID("lockButtonForVoiceNameChar_" + paramID);
		paramLockToggleButtons[param].setSize(GUI::voiceNameCharacters_w, GUI::voiceNameCharacters_h);
	}
}

void RandomizationComponent::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::RandomizationWindowBackground_png, BinaryData::RandomizationWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void RandomizationComponent::resized() {
	button_ForLockingAllParameters.setBounds(GUI::bounds_RandomizationLockAllButton);
	button_ForUnlockingAllParameters.setBounds(GUI::bounds_RandomizationUnlockAllButton);
	button_ForRandomizingUnlockedParameters.setBounds(GUI::bounds_RandomizeButton);
	button_ForClosingRandomizationComponent.setBounds(GUI::bounds_RandomizationCloseButton);
	button_ForLockingAllVoiceNameChars.setBounds(GUI::bounds_RandomizationVoiceNameLockButton);
	button_ForUnlockingAllVoiceNameChars.setBounds(GUI::bounds_RandomizationVoiceNameUnlockButton);
	button_ForLockingAllStepsInSeqTrack1.setBounds(GUI::bounds_RandomizationSeqTrack1LockButton);
	button_ForLockingAllStepsInSeqTrack2.setBounds(GUI::bounds_RandomizationSeqTrack2LockButton);
	button_ForLockingAllStepsInSeqTrack3.setBounds(GUI::bounds_RandomizationSeqTrack3LockButton);
	button_ForLockingAllStepsInSeqTrack4.setBounds(GUI::bounds_RandomizationSeqTrack4LockButton);
	button_ForUnlockingAllStepsInSeqTrack1.setBounds(GUI::bounds_RandomizationSeqTrack1UnlockButton);
	button_ForUnlockingAllStepsInSeqTrack2.setBounds(GUI::bounds_RandomizationSeqTrack2UnlockButton);
	button_ForUnlockingAllStepsInSeqTrack3.setBounds(GUI::bounds_RandomizationSeqTrack3UnlockButton);
	button_ForUnlockingAllStepsInSeqTrack4.setBounds(GUI::bounds_RandomizationSeqTrack4UnlockButton);
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		auto ctrlCenterPoint{ info.controlCenterPointFor(param) };
		paramLockToggleButtons[param].setCentrePosition(ctrlCenterPoint);
	}
}

void RandomizationComponent::lockAllParameters() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		paramLockToggleButtons[param].setToggleState(true, dontSendNotification);
	}
}

void RandomizationComponent::unlockAllParameters() {
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		paramLockToggleButtons[param].setToggleState(false, dontSendNotification);
	}
}

void RandomizationComponent::lockAllVoiceNameCharacters() {
	auto& info{ InfoForExposedParameters::get() };
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ (String)(charNum + 1) };
		auto paramIndex{ info.indexForParamID("nameChar" + charNumString) };
		paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	}
}

void RandomizationComponent::unlockAlVoicelNameCharacters() {
	auto& info{ InfoForExposedParameters::get() };
	for (auto charNum = 0; charNum != 16; ++charNum) {
		auto charNumString{ (String)(charNum + 1) };
		auto paramIndex{ info.indexForParamID("nameChar" + charNumString) };
		paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	}
}

void RandomizationComponent::lockAllStepsInSeqTrack(int trackNum) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto step = 0; step != 16; ++step) {
		auto paramID{ "track" + (String)trackNum + "Step" + (String)(step + 1) };
		auto paramIndex{ info.indexForParamID(paramID) };
		paramLockToggleButtons[paramIndex].setToggleState(true, dontSendNotification);
	}
}

void RandomizationComponent::unlockAllStepsInSeqTrack(int trackNum) {
	auto& info{ InfoForExposedParameters::get() };
	for (auto step = 0; step != 16; ++step) {
		auto paramID{ "track" + (String)trackNum + "Step" + (String)(step + 1) };
		auto paramIndex{ info.indexForParamID(paramID) };
		paramLockToggleButtons[paramIndex].setToggleState(false, dontSendNotification);
	}
}

void RandomizationComponent::randomizeUnlockedParameters() {
}

void RandomizationComponent::buttonClicked(Button* button) {
	auto& info{ InfoForExposedParameters::get() };
	if (exposedParams->getParameter("arpegOnOff")->getValue() == 1 || exposedParams->getParameter("sequencerOnOff")->getValue() == 1) {
		if (button->getComponentID() == "lockButtonForToggle_arpegOnOff") {
			auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
			paramLockToggleButtons[sequencerOnOffIndex].setToggleState(button->getToggleState(), dontSendNotification);
		}
		if (button->getComponentID() == "lockButtonForToggle_sequencerOnOff") {
			auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
			paramLockToggleButtons[arpegOnOffIndex].setToggleState(button->getToggleState(), dontSendNotification);
		}
	}
}

void RandomizationComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

void RandomizationComponent::timerCallback() {
}

RandomizationComponent::~RandomizationComponent() {
	auto& info{ InfoForExposedParameters::get() };
	auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
	paramLockToggleButtons[arpegOnOffIndex].removeListener(this);
	auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
	paramLockToggleButtons[sequencerOnOffIndex].removeListener(this);
}
