#include "RandomizationComponent.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_EditBufferDataMessage.h"
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
	button_ForLockingAllOscParameters{ this, unexposedParams },
	button_ForUnlockingAllOscParameters{ this, unexposedParams },
	button_ForLockingAllLPFparameters{ this, unexposedParams },
	button_ForUnlockingAllLPFparameters{ this, unexposedParams },
	button_ForLockingAllVCAparameters{ this, unexposedParams },
	button_ForUnlockingAllVCAparameters{ this, unexposedParams },
	button_ForLockingAllEnv3Parameters{ this, unexposedParams },
	button_ForUnlockingAllEnv3Parameters{ this, unexposedParams },
	button_ForLockingAllModulatorParams{ this, unexposedParams },
	button_ForUnlockingAllModulatorParams{ this, unexposedParams },
	button_ForLockingAllMIDIcontrollerParams{ this, unexposedParams },
	button_ForUnlockingAllMIDIcontrollerParams{ this, unexposedParams },
	button_ForLockingAllLFO1parameters{ 1, this, unexposedParams },
	button_ForLockingAllLFO2parameters{ 2, this, unexposedParams },
	button_ForLockingAllLFO3parameters{ 3, this, unexposedParams },
	button_ForLockingAllLFO4parameters{ 4, this, unexposedParams },
	button_ForUnlockingAllLFO1parameters{ 1, this, unexposedParams },
	button_ForUnlockingAllLFO2parameters{ 2, this, unexposedParams },
	button_ForUnlockingAllLFO3parameters{ 3, this, unexposedParams },
	button_ForUnlockingAllLFO4parameters{ 4, this, unexposedParams },
	button_ForLockingAllVoiceNameChars{ this, unexposedParams },
	button_ForUnlockingAllVoiceNameChars{ this, unexposedParams },
	button_ForLockingAllSeqTrack1Params{ 1, this, unexposedParams },
	button_ForLockingAllSeqTrack2Params{ 2, this, unexposedParams },
	button_ForLockingAllSeqTrack3Params{ 3, this, unexposedParams },
	button_ForLockingAllSeqTrack4Params{ 4, this, unexposedParams },
	button_ForUnlockingAllSeqTrack1Params{ 1, this, unexposedParams },
	button_ForUnlockingAllSeqTrack2Params{ 2, this, unexposedParams },
	button_ForUnlockingAllSeqTrack3Params{ 3, this, unexposedParams },
	button_ForUnlockingAllSeqTrack4Params{ 4, this, unexposedParams },
	button_ForLockingAllKnobAssignParams{ this, unexposedParams },
	button_ForUnlockingAllKnobAssignParams{ this, unexposedParams },
	button_ForLockingAllPushItParams{ this, unexposedParams },
	button_ForUnlockingAllPushItParams{ this, unexposedParams },
	button_ForRandomizingUnlockedParameters{ this, unexposedParams }
{
	addAndMakeVisible(button_ForLockingAllParameters);
	addAndMakeVisible(button_ForUnlockingAllParameters);
	addAndMakeVisible(button_ForRandomizingUnlockedParameters);
	addAndMakeVisible(button_ForLockingAllOscParameters);
	addAndMakeVisible(button_ForUnlockingAllOscParameters);
	addAndMakeVisible(button_ForLockingAllLPFparameters);
	addAndMakeVisible(button_ForUnlockingAllLPFparameters);
	addAndMakeVisible(button_ForLockingAllVCAparameters);
	addAndMakeVisible(button_ForUnlockingAllVCAparameters);
	addAndMakeVisible(button_ForLockingAllEnv3Parameters);
	addAndMakeVisible(button_ForUnlockingAllEnv3Parameters);
	addAndMakeVisible(button_ForLockingAllModulatorParams);
	addAndMakeVisible(button_ForUnlockingAllModulatorParams);
	addAndMakeVisible(button_ForLockingAllMIDIcontrollerParams);
	addAndMakeVisible(button_ForUnlockingAllMIDIcontrollerParams);
	addAndMakeVisible(button_ForLockingAllLFO1parameters);
	addAndMakeVisible(button_ForLockingAllLFO2parameters);
	addAndMakeVisible(button_ForLockingAllLFO3parameters);
	addAndMakeVisible(button_ForLockingAllLFO4parameters);
	addAndMakeVisible(button_ForUnlockingAllLFO1parameters);
	addAndMakeVisible(button_ForUnlockingAllLFO2parameters);
	addAndMakeVisible(button_ForUnlockingAllLFO3parameters);
	addAndMakeVisible(button_ForUnlockingAllLFO4parameters);
	addAndMakeVisible(button_ForLockingAllVoiceNameChars);
	addAndMakeVisible(button_ForUnlockingAllVoiceNameChars);
	addAndMakeVisible(button_ForLockingAllSeqTrack1Params);
	addAndMakeVisible(button_ForLockingAllSeqTrack2Params);
	addAndMakeVisible(button_ForLockingAllSeqTrack3Params);
	addAndMakeVisible(button_ForLockingAllSeqTrack4Params);
	addAndMakeVisible(button_ForUnlockingAllSeqTrack1Params);
	addAndMakeVisible(button_ForUnlockingAllSeqTrack2Params);
	addAndMakeVisible(button_ForUnlockingAllSeqTrack3Params);
	addAndMakeVisible(button_ForUnlockingAllSeqTrack4Params);
	addAndMakeVisible(button_ForLockingAllKnobAssignParams);
	addAndMakeVisible(button_ForUnlockingAllKnobAssignParams);
	addAndMakeVisible(button_ForLockingAllPushItParams);
	addAndMakeVisible(button_ForUnlockingAllPushItParams);

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
	}
	if (info.controlTypeFor(param) == ControlType::voiceNameChar) {
		paramLockToggleButtons[param].setComponentID("lockButtonForVoiceNameChar_" + paramID);
		paramLockToggleButtons[param].setSize(GUI::voiceNameCharacters_w, GUI::voiceNameCharacters_h);
	}
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	paramLockToggleButtons[param].setToggleState(randomizationOptions->paramIsLocked(param), dontSendNotification);
	paramLockToggleButtons[param].addListener(this);
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
	button_ForLockingAllOscParameters.setBounds(GUI::bounds_RandomizationOscLockButton);
	button_ForUnlockingAllOscParameters.setBounds(GUI::bounds_RandomizationOscUnlockButton);
	button_ForLockingAllLPFparameters.setBounds(GUI::bounds_RandomizationLPFlockButton);
	button_ForUnlockingAllLPFparameters.setBounds(GUI::bounds_RandomizationLPFunlockButton);
	button_ForLockingAllVCAparameters.setBounds(GUI::bounds_RandomizationVCAlockButton);
	button_ForUnlockingAllVCAparameters.setBounds(GUI::bounds_RandomizationVCAunlockButton);
	button_ForLockingAllEnv3Parameters.setBounds(GUI::bounds_RandomizationEnv3LockButton);
	button_ForUnlockingAllEnv3Parameters.setBounds(GUI::bounds_RandomizationEnv3UnlockButton);
	button_ForLockingAllModulatorParams.setBounds(GUI::bounds_RandomizationModulatorsLockButton);
	button_ForUnlockingAllModulatorParams.setBounds(GUI::bounds_RandomizationModulatorsUnlockButton);
	button_ForLockingAllMIDIcontrollerParams.setBounds(GUI::bounds_RandomizationMIDIcontrollersLockButton);
	button_ForUnlockingAllMIDIcontrollerParams.setBounds(GUI::bounds_RandomizationMIDIcontrollersUnlockButton);
	button_ForLockingAllLFO1parameters.setBounds(GUI::bounds_RandomizationLFO1lockButton);
	button_ForUnlockingAllLFO1parameters.setBounds(GUI::bounds_RandomizationLFO1unlockButton);
	button_ForLockingAllLFO2parameters.setBounds(GUI::bounds_RandomizationLFO2lockButton);
	button_ForUnlockingAllLFO2parameters.setBounds(GUI::bounds_RandomizationLFO2unlockButton);
	button_ForLockingAllLFO3parameters.setBounds(GUI::bounds_RandomizationLFO3lockButton);
	button_ForUnlockingAllLFO3parameters.setBounds(GUI::bounds_RandomizationLFO3unlockButton);
	button_ForLockingAllLFO4parameters.setBounds(GUI::bounds_RandomizationLFO4lockButton);
	button_ForUnlockingAllLFO4parameters.setBounds(GUI::bounds_RandomizationLFO4unlockButton);
	button_ForLockingAllVoiceNameChars.setBounds(GUI::bounds_RandomizationVoiceNameLockButton);
	button_ForUnlockingAllVoiceNameChars.setBounds(GUI::bounds_RandomizationVoiceNameUnlockButton);
	button_ForLockingAllSeqTrack1Params.setBounds(GUI::bounds_RandomizationSeqTrack1LockButton);
	button_ForLockingAllSeqTrack2Params.setBounds(GUI::bounds_RandomizationSeqTrack2LockButton);
	button_ForLockingAllSeqTrack3Params.setBounds(GUI::bounds_RandomizationSeqTrack3LockButton);
	button_ForLockingAllSeqTrack4Params.setBounds(GUI::bounds_RandomizationSeqTrack4LockButton);
	button_ForUnlockingAllSeqTrack1Params.setBounds(GUI::bounds_RandomizationSeqTrack1UnlockButton);
	button_ForUnlockingAllSeqTrack2Params.setBounds(GUI::bounds_RandomizationSeqTrack2UnlockButton);
	button_ForUnlockingAllSeqTrack3Params.setBounds(GUI::bounds_RandomizationSeqTrack3UnlockButton);
	button_ForUnlockingAllSeqTrack4Params.setBounds(GUI::bounds_RandomizationSeqTrack4UnlockButton);
	button_ForLockingAllKnobAssignParams.setBounds(GUI::bounds_RandomizationKnobAssignLockButton);
	button_ForUnlockingAllKnobAssignParams.setBounds(GUI::bounds_RandomizationKnobAssignUnlockButton);
	button_ForLockingAllPushItParams.setBounds(GUI::bounds_RandomizationPushItLockButton);
	button_ForUnlockingAllPushItParams.setBounds(GUI::bounds_RandomizationPushItUnlockButton);
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		auto ctrlCenterPoint{ info.controlCenterPointFor(param) };
		paramLockToggleButtons[param].setCentrePosition(ctrlCenterPoint);
	}
}

void RandomizationComponent::randomizeUnlockedParameters() {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
	auto& info{ InfoForExposedParameters::get() };
	auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
	auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		if (param != arpegOnOffIndex && param != sequencerOnOffIndex) {
			if (paramLockToggleButtons[param].getToggleState() == false) {
				auto paramID{ info.IDfor(param) };
				Random rndmNumGenerator{};
				if (paramID == ID::osc1_Shape || paramID == ID::osc2_Shape) {
					auto newFloat{ rndmNumGenerator.nextFloat() };
					auto numberOfShapeOptions{ 5 };
					auto newShape{ (int)floor(newFloat * numberOfShapeOptions) };
					if (newShape != 4) {
						auto newNormalizedValue{ newShape / 103.0f };
						exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
					}
					else {
						auto newPulseWidth{ floor(rndmNumGenerator.nextFloat() * 100.0f) };
						auto newNormalizedValue{ (newShape + newPulseWidth) / 103.0f };
						exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
					}
				}
				else {
					auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
					exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
				}
			}
		}
	}
	Random rndmNumGenerator{};
	if (paramLockToggleButtons[arpegOnOffIndex].getToggleState() == false && paramLockToggleButtons[sequencerOnOffIndex].getToggleState() == false) {
		auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
		auto arpSeqOnOffOption{ (int)std::floor(newNormalizedValue * 3) };
		switch (arpSeqOnOffOption) {
		case 0: {
			exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(0.0);
			exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(0.0);
			break;
		}
		case 1: {
			exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(1.0);
			exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(0.0);
			break;
		}
		case 2: {
			exposedParams->getParameter("arpegOnOff")->setValueNotifyingHost(0.0);
			exposedParams->getParameter("sequencerOnOff")->setValueNotifyingHost(1.0);
			break;
		}
		default:
			break;
		}
	}
	EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get());
	voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

void RandomizationComponent::buttonClicked(Button* button) {
	auto& info{ InfoForExposedParameters::get() };
	auto buttonID{ button->getComponentID() };
	if (buttonID.startsWith("lockButton")) {
		auto paramID{ buttonID.fromFirstOccurrenceOf("_", false, false) };
		if (exposedParams->getParameter("arpegOnOff")->getValue() == 1 || exposedParams->getParameter("sequencerOnOff")->getValue() == 1) {
			if (paramID == "arpegOnOff") {
				auto sequencerOnOffIndex{ info.indexForParamID("sequencerOnOff") };
				paramLockToggleButtons[sequencerOnOffIndex].setToggleState(button->getToggleState(), sendNotification);
			}
			if (paramID == "sequencerOnOff") {
				auto arpegOnOffIndex{ info.indexForParamID("arpegOnOff") };
				paramLockToggleButtons[arpegOnOffIndex].setToggleState(button->getToggleState(), sendNotification);
			}
		}
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		auto paramIndex{ info.indexForParamID(paramID) };
		auto buttonIsToggledOn{ button->getToggleState() };
		if (buttonIsToggledOn)
			randomizationOptions->setParamIsLocked(paramIndex);
		else
			randomizationOptions->setParamIsUnlocked(paramIndex);
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
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param)
		paramLockToggleButtons[param].removeListener(this);
}
