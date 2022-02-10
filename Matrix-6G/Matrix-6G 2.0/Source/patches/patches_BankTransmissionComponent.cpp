#include "patches_BankTransmissionComponent.h"

#include "patches_Constants.h"
#include "patches_TabbedComponentForPatchBanks.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoicesBankTransmissionComponent::VoicesBankTransmissionComponent(VoicesBank& bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->voiceTransmissionOptions_get()->voiceTransmitTime() },
	voiceCounter{ voices::numberOfSlotsInBank },
	progress{ 0.0 },
	progressBar{ progress },
	button_Stop{ "" },
	button_Close{ "" }
{
	addAndMakeVisible(progressBar);
	progressBar.setBounds(GUI::bounds_BankTransmitProgressBar);

	button_Close.setComponentID(ID::button_Close.toString());
	button_Stop.setComponentID(ID::button_Stop.toString());
	addChildComponent(button_Close);
	addAndMakeVisible(button_Stop);
	button_Close.onClick = [this, bank, transmissionType, unexposedParams] { 
		if (transmissionType == TransmissionType::pull) {
			auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
			if (bank == VoicesBank::customA || bank == VoicesBank::customB)
				voiceTransmissionOptions->setIncomingVoiceShouldNotBeSavedInCustomBank();
		}
		hideThisComponent();
	};
	button_Stop.onClick = [this] { cancelTransmission(); };
	button_Close.setBounds(GUI::bounds_BankTransmitButtons);
	button_Stop.setBounds(GUI::bounds_BankTransmitButtons);

	voiceCounter = 0;
	startTimer(transmitTime);
}

void VoicesBankTransmissionComponent::timerCallback() {
	stopTimer();
	if (voiceCounter < voices::numberOfSlotsInBank) {
		transmitMidiBufferForVoiceSlot(voiceCounter);
		++voiceCounter;
		progress = voiceCounter / (double)voices::numberOfSlotsInBank;
		repaint();
		startTimer(transmitTime);
	}
	else {
		makeCloseButtonVisible();
		repaint();
	}
}

void VoicesBankTransmissionComponent::transmitMidiBufferForVoiceSlot(uint8 voiceSlot) {
	auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	if (transmissionType == TransmissionType::pull) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		if (bank == VoicesBank::customA)
			voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInCustomBankA();
		else
			voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInCustomBankB();
		VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(voiceSlot, outgoingBuffers);
	}
	else {
		VoiceDataMessage::addDataMessageForVoiceStoredInBankAndSlotToOutgoingMidiBuffers(bank, voiceSlot, unexposedParams);
		callAfterDelay(10, [this, outgoingBuffers, voiceSlot]
			{
				auto masterOptions{ unexposedParams->masterOptions_get() };
				auto basicChannel{ masterOptions->basicChannel() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, voiceSlot);
			}
		);
	}
}

void VoicesBankTransmissionComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_VoicesBanksWindow);
	g.setColour(Color::button_blue);
	auto componentBounds{ GUI::bounds_BankTransmitComponent };
	auto componentOutlineBounds{ componentBounds.expanded(GUI::windowBorderThickness) };
	g.fillRect(componentOutlineBounds);
	g.setColour(Color::device);
	g.fillRect(componentBounds);
	PNGImageFormat imageFormat;
	auto titleLabelImageData{ getTitleLabelImageData() };
	auto titleLabelImageDataSize{ getTitleLabelImageDataSize() };
	if (titleLabelImageData != nullptr) {
		MemoryInputStream memInputStream{ titleLabelImageData, titleLabelImageDataSize, false };
		auto titleLabelImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(titleLabelImage, GUI::bankTransmitTitleLabel_x, GUI::bankTransmitTitleLabel_y);
	}
}

const char* VoicesBankTransmissionComponent::getTitleLabelImageData() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_png;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_png;
	else
		return nullptr;
}

size_t VoicesBankTransmissionComponent::getTitleLabelImageDataSize() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_pngSize;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_pngSize;
	else
		return (size_t)0;
}

void VoicesBankTransmissionComponent::cancelTransmission() {
	stopTimer();
	makeCloseButtonVisible();
	repaint();
}

void VoicesBankTransmissionComponent::makeCloseButtonVisible() {
	button_Stop.setVisible(false);
	button_Close.setVisible(true);
}

void VoicesBankTransmissionComponent::hideThisComponent() {
	setVisible(false);
}
