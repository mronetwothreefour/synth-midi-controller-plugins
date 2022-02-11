#include "widget_BankTransmissionComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"
#include "../voices/voices_TabbedComponentForFactoryVoicesBanks.h"

using namespace constants;



BankTransmissionComponent::BankTransmissionComponent(VoicesBank& bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	message{ "" },
	transmitTime{ unexposedParams->midiOptions_get()->voiceTransmitTime() },
	programCounter{ banks::numberOfSlotsInBank },
	progress{ 0.0 },
	progressBar{ progress },
	button_Stop{ "" },
	button_Close{ "" }
{
	switch (bank)
	{
	case VoicesBank::factory1:
		bankName = "Factory Bank 1";
		break;
	case VoicesBank::factory2:
		bankName = "Factory Bank 2";
		break;
	case VoicesBank::factory3:
		bankName = "Factory Bank 3";
		break;
	case VoicesBank::custom1:
		bankName = "Custom Bank 1";
		break;
	case VoicesBank::custom2:
		bankName = "Custom Bank 2";
		break;
	case VoicesBank::custom3:
		bankName = "Custom Bank 3";
		break;
	default:
		bankName = "error";
		break;
	}
	
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

	setSize(GUI::editor_w, GUI::editor_h);

	programCounter = 0;
	startTimer(transmitTime);
}

void BankTransmissionComponent::timerCallback() {
	stopTimer();
	if (programCounter < banks::numberOfSlotsInBank) {
		transmitMidiBufferForProgramSlot(programCounter);
		++programCounter;
		progress = programCounter / (double)banks::numberOfSlotsInBank;
		message = transmissionType == TransmissionType::push ? "Pushing " : "Pulling ";
		message += bankName + " Program " + (String)programCounter;
		message += transmissionType == TransmissionType::push ? " To Hardware" : " From Hardware";
		repaint();
		startTimer(transmitTime);
	}
	else {
		message = "Transmission Complete";
		makeClosebuttonVisible();
		repaint();
	}
}

void BankTransmissionComponent::transmitMidiBufferForProgramSlot(uint8 programSlot) {
	auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	if (transmissionType == TransmissionType::pull)
		VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingMidiBuffers(bank, programSlot, outgoingBuffers);
	else {
		auto programDumpVector{ VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(bank, programSlot, unexposedParams) };
		outgoingBuffers->addDataMessage(programDumpVector);
	}
}

void BankTransmissionComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_BanksWindow);
	g.setColour(Color::black);
	auto componentBounds{ GUI::bounds_BankTransmitProgressDisplayWindow };
	auto componentOutlineBounds{ componentBounds.expanded(GUI::windowOutlineThickness) };
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
	g.setColour(Color::black);
	g.setFont(FontsMenu::fontFor_ProgressDisplayMessage);
	g.drawFittedText(message, GUI::bounds_BankTransmitMessage, Justification::centred, 1, 1.0f);
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
	message = "Transmission Canceled";
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
