#include "splits_BankTransmissionComponent.h"

#include "splits_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_SplitDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SplitsBankTransmissionComponent::SplitsBankTransmissionComponent(TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->midiOptions_get()->patchTransmitTime() },
	splitCounter{ splits::numberOfSlotsInBank },
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
	splitCounter = 0;
	startTimer(transmitTime);
}

void SplitsBankTransmissionComponent::timerCallback() {
	stopTimer();
	if (splitCounter < splits::numberOfSlotsInBank) {
		transmitMidiBufferForSplitSlot(splitCounter);
		++splitCounter;
		progress = splitCounter / (double)splits::numberOfSlotsInBank;
		repaint();
		startTimer(transmitTime);
	}
	else {
		makeClosebuttonVisible();
		repaint();
	}
}

void SplitsBankTransmissionComponent::transmitMidiBufferForSplitSlot(uint8 splitSlot) {
	auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	if (transmissionType == TransmissionType::pull) {
		SplitDataMessage::addRequestForSplitDataStoredInHardwareSlotToOutgoingMidiBuffers(splitSlot, outgoingBuffers);
	}
	else {
		SplitDataMessage::addDataMessageForSplitStoredInSlotToOutgoingMidiBuffers(splitSlot, unexposedParams);
		callAfterDelay(10, [this, outgoingBuffers, splitSlot]
			{
				auto midiOptions{ unexposedParams->midiOptions_get() };
				auto basicChannel{ midiOptions->basicChannel() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, splitSlot);
			}
		);
	}
}

void SplitsBankTransmissionComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_SplitsWindow);
	g.setColour(Color::button_gray);
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

const char* SplitsBankTransmissionComponent::getTitleLabelImageData() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_png;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_png;
	else
		return nullptr;
}

size_t SplitsBankTransmissionComponent::getTitleLabelImageDataSize() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::TitlePullingEntireBank_pngSize;
	if (transmissionType == TransmissionType::push)
		return BinaryData::TitlePushingEntireBank_pngSize;
	else
		return (size_t)0;
}

void SplitsBankTransmissionComponent::cancelTransmission() {
	stopTimer();
	makeClosebuttonVisible();
	repaint();
}

void SplitsBankTransmissionComponent::makeClosebuttonVisible() {
	button_Stop.setVisible(false);
	button_Close.setVisible(true);
}

void SplitsBankTransmissionComponent::hideThisComponent() {
	setVisible(false);
}
