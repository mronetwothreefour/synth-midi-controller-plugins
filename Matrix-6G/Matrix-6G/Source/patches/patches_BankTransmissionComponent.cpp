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



PatchBankTransmissionComponent::PatchBankTransmissionComponent(PatchBank& bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->patchTransmissionOptions_get()->patchTransmitTime() },
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
	button_Close.onClick = [this, bank, transmissionType, unexposedParams] { 
		if (transmissionType == TransmissionType::pull) {
			auto patchTransmissionOptions{ unexposedParams->patchTransmissionOptions_get() };
			if (bank == PatchBank::customA || bank == PatchBank::customB)
				patchTransmissionOptions->setIncomingPatchShouldNotBeSavedInCustomBank();
		}
		hideThisComponent();
	};
	button_Stop.onClick = [this] { cancelTransmission(); };
	button_Close.setBounds(GUI::bounds_BankTransmitButtons);
	button_Stop.setBounds(GUI::bounds_BankTransmitButtons);

	patchCounter = 0;
	startTimer(transmitTime);
}

void PatchBankTransmissionComponent::timerCallback() {
	stopTimer();
	if (patchCounter < patches::numberOfSlotsInBank) {
		transmitMidiBufferForPatchSlot(patchCounter);
		++patchCounter;
		progress = patchCounter / (double)patches::numberOfSlotsInBank;
		repaint();
		startTimer(transmitTime);
	}
	else {
		makeCloseButtonVisible();
		repaint();
	}
}

void PatchBankTransmissionComponent::transmitMidiBufferForPatchSlot(uint8 patchSlot) {
	auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	if (transmissionType == TransmissionType::pull) {
		auto patchTransmissionOptions{ unexposedParams->patchTransmissionOptions_get() };
		if (bank == PatchBank::customA)
			patchTransmissionOptions->setIncomingPatchShouldBeSavedInCustomBankA();
		else
			patchTransmissionOptions->setIncomingPatchShouldBeSavedInCustomBankB();
		PatchDataMessage::addRequestForPatchDataStoredInHardwareSlotToOutgoingMidiBuffers(patchSlot, outgoingBuffers);
	}
	else {
		PatchDataMessage::addDataMessageForPatchStoredInBankAndSlotToOutgoingMidiBuffers(bank, patchSlot, unexposedParams);
		callAfterDelay(10, [this, outgoingBuffers, patchSlot]
			{
				auto masterOptions{ unexposedParams->masterOptions_get() };
				auto basicChannel{ masterOptions->basicChannel() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, patchSlot);
			}
		);
	}
}

void PatchBankTransmissionComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_PatchBanksWindow);
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

const char* PatchBankTransmissionComponent::getTitleLabelImageData() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_png;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_png;
	else
		return nullptr;
}

size_t PatchBankTransmissionComponent::getTitleLabelImageDataSize() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_pngSize;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_pngSize;
	else
		return (size_t)0;
}

void PatchBankTransmissionComponent::cancelTransmission() {
	stopTimer();
	makeCloseButtonVisible();
	repaint();
}

void PatchBankTransmissionComponent::makeCloseButtonVisible() {
	button_Stop.setVisible(false);
	button_Close.setVisible(true);
}

void PatchBankTransmissionComponent::hideThisComponent() {
	setVisible(false);
}
