#include "patches_BankTransmissionComponent.h"

#include "patches_Constants.h"
#include "patches_TabbedComponentForPatchBanks.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_PatchDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



BankTransmissionComponent::BankTransmissionComponent(PatchBank& bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->midiOptions_get()->patchTransmitTime() },
	patchCounter{ patches::numberOfSlotsInBank },
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
	button_Close.onClick = [this] { hideThisComponent(); };
	button_Stop.onClick = [this] { cancelTransmission(); };
	button_Close.setBounds(GUI::bounds_BankTransmitButtons);
	button_Stop.setBounds(GUI::bounds_BankTransmitButtons);
}

void BankTransmissionComponent::timerCallback() {
	stopTimer();
	if (patchCounter < patches::numberOfSlotsInBank) {
		transmitMidiBufferForPatchSlot(patchCounter);
		++patchCounter;
		progress = patchCounter / (double)patches::numberOfSlotsInBank;
		repaint();
		startTimer(transmitTime);
	}
	else {
		makeClosebuttonVisible();
		repaint();
	}
}

void BankTransmissionComponent::transmitMidiBufferForPatchSlot(uint8 patchSlot) {
	auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	if (transmissionType == TransmissionType::pull)
		PatchDataMessage::addRequestForPatchDataStoredInHardwareSlotToOutgoingMidiBuffers(patchSlot, outgoingBuffers);
	else {
		PatchDataMessage::addDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(bank, patchSlot, unexposedParams);
	}
}

void BankTransmissionComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_PatchBanksWindow);
	g.setColour(Color::button_blue);
	auto bankTransmitComponent{ GUI::bounds_BankTransmitComponent };
	g.fillRect(bankTransmitComponent);
	g.setColour(Color::device);
	bankTransmitComponent.reduce(GUI::windowBorderThickness, GUI::windowBorderThickness);
	PNGImageFormat imageFormat;
	auto titleLabelImageData{ getTitleLabelImageData() };
	auto titleLabelImageDataSize{ getTitleLabelImageDataSize() };
	if (titleLabelImageData != nullptr) {
		MemoryInputStream memInputStream{ titleLabelImageData, titleLabelImageDataSize, false };
		auto titleLabelImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(titleLabelImage, GUI::bankTransmitTitleLabel_x, GUI::bankTransmitTitleLabel_y);
	}
}

const char* BankTransmissionComponent::getTitleLabelImageData() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_png;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_png;
	else
		return nullptr;
}

size_t BankTransmissionComponent::getTitleLabelImageDataSize() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_pngSize;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_pngSize;
	else
		return (size_t)0;
}

void BankTransmissionComponent::cancelTransmission() {
	stopTimer();
	makeClosebuttonVisible();
	repaint();
}

void BankTransmissionComponent::makeClosebuttonVisible() {
	button_Stop.setVisible(false);
	button_Close.setVisible(true);
}

void BankTransmissionComponent::hideThisComponent() {
	setVisible(false);
}
