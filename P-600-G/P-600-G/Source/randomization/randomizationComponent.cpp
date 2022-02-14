#include "randomizationComponent.h"

#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationComponent::RandomizationComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	button_ForLockingAllParameters{ this, unexposedParams },
	button_ForUnlockingAllParameters{ this, unexposedParams },
	button_ForRandomizingUnlockedParameters{ this, unexposedParams }
{
	addAndMakeVisible(button_ForLockingAllParameters);
	addAndMakeVisible(button_ForUnlockingAllParameters);
	addAndMakeVisible(button_ForRandomizingUnlockedParameters);

	button_ForClosingRandomizationComponent.setComponentID(ID::button_Exit.toString());
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

void RandomizationComponent::setUpParamLockToggleButton(uint8 param)
{
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(param).toString() };
	paramLockToggleButtons[param].setComponentID("lockButton_" + paramID);
	paramLockToggleButtons[param].setSize(GUI::buttonRandomizationParamLock_w, GUI::buttonRandomizationParamLock_h);
}

void RandomizationComponent::paint(Graphics& g) {
	MemoryInputStream memInputStream{ BinaryData::RandomizationWindowBackground_png, BinaryData::RandomizationWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void RandomizationComponent::resized() {
	button_ForLockingAllParameters.setBounds(GUI::bounds_RandomizationLockAllButton);
	button_ForUnlockingAllParameters.setBounds(GUI::bounds_RandomizationLockNoneButton);
	button_ForRandomizingUnlockedParameters.setBounds(GUI::bounds_RandomizationOKbutton);
	button_ForClosingRandomizationComponent.setBounds(GUI::bounds_RandomizationExitButton);
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

void RandomizationComponent::randomizeUnlockedParameters() {
	auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
	voiceTransmissionOptions->setParamChangeEchoesAreBlocked();
	auto& info{ InfoForExposedParameters::get() };
	for (uint8 param = 0; param != info.paramOutOfRange(); ++param) {
		Random rndmNumGenerator{};
		if (paramLockToggleButtons[param].getToggleState() == false) {
			auto newNormalizedValue{ rndmNumGenerator.nextFloat() };
			auto paramID{ info.IDfor(param) };
			exposedParams->getParameter(paramID)->setValueNotifyingHost(newNormalizedValue);
		}
	}
	VoiceDataMessage::addVoiceDataMessageForCurrentExposedParamsSettingsToOutgoingMidiBuffers(exposedParams, unexposedParams);
	callAfterDelay(10, [this]
		{
			auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
			auto voiceSlot{ voiceTransmissionOptions->currentVoiceNumber() };
			auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
			outgoingBuffers->addProgramChangeMessage(MIDI::channel, voiceSlot);
		}
	);
	voiceTransmissionOptions->setParamChangeEchoesAreNotBlocked();
}

void RandomizationComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

void RandomizationComponent::timerCallback() {
}

