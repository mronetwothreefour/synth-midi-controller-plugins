#include "widget_BankTransmissionComponent.h"

#include "../banks/banks_TabbedComponentForFactoryProgramBanks.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_ProgramDump.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



BankTransmissionComponent::BankTransmissionComponent(ProgramBank& bank, TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	message{ "" },
	transmitTime{ unexposedParams->midiOptions_get()->programTransmitTime() },
	programCounter{ 128 },
	progress{ 0.0 },
	progressBar{ progress },
	button_Stop{ "" },
	button_Close{ "" }
{
	switch (bank)
	{
	case ProgramBank::factory1:
		bankName = "Factory Bank 1";
		bankNumber = 1;
		break;
	case ProgramBank::factory2:
		bankName = "Factory Bank 2";
		bankNumber = 2;
		break;
	case ProgramBank::factory3:
		bankName = "Factory Bank 3";
		bankNumber = 3;
		break;
	case ProgramBank::custom1:
		bankName = "Custom Bank 1";
		bankNumber = 1;
		break;
	case ProgramBank::custom2:
		bankName = "Custom Bank 2";
		bankNumber = 2;
		break;
	case ProgramBank::custom3:
		bankName = "Custom Bank 3";
		bankNumber = 3;
		break;
	default:
		bankName = "error";
		bankNumber = 0;
		break;
	}
	title = transmissionType == TransmissionType::push ? "Push All Programs To Hardware Bank " + (String)bankNumber : "Pull All Programs From Hardware Bank " + (String)bankNumber;
	
	addAndMakeVisible(progressBar);
	auto progressBar_x{ 508 };
	auto progressBar_y{ 316 };
	auto progressBar_w{ 257 };
	auto progressBar_h{ 18 };
	progressBar.setBounds(progressBar_x, progressBar_y, progressBar_w, progressBar_h);

	button_Close.setComponentID(ID::button_Close.toString());
	button_Stop.setComponentID(ID::button_Stop.toString());
	addChildComponent(button_Close);
	addAndMakeVisible(button_Stop);
	button_Close.onClick = [this] { hideThisComponent(); };
	button_Stop.onClick = [this] { cancelTransmission(); };
	auto button_x{ 611 };
	auto button_y{ 349 };
	auto button_w{ 51 };
	auto button_h{ 22 };
	button_Close.setBounds(button_x, button_y, button_w, button_h);
	button_Stop.setBounds(button_x, button_y, button_w, button_h);

	setSize(1273, 626);

	programCounter = 0;
	startTimer(transmitTime);
}

void BankTransmissionComponent::timerCallback() {
	stopTimer();
	if (programCounter < 128) {
		transmitMidiBufferForProgramSlot(programCounter);
		++programCounter;
		progress = programCounter / 128.0;
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
	if (transmissionType == TransmissionType::pull) {
		ProgramDump::addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(bank, programSlot, outgoingBuffers);
		//auto programBankTab{ tabbedComponent.getCurrentProgramBankTab() };
		//if (programBankTab != nullptr)
		//	callAfterDelay(transmitTime, [this, programBankTab, programSlot] { programBankTab->updateProgramSlotText(programSlot); });
	}
	else {
		auto programDumpVector{ ProgramDump::createProgramDumpForBankAndSlot(bank, programSlot, unexposedParams) };
		outgoingBuffers->addDataMessage(programDumpVector);
	}
}

void BankTransmissionComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	Rectangle<int> dimBanksWindow{ 104, 113, 1065, 400 };
	g.fillRect(dimBanksWindow);
	g.setColour(Color::black);
	Rectangle<int> progressDisplayOutline{ 464, 236, 345, 154 };
	g.fillRect(progressDisplayOutline);
	g.setColour(Color::device);
	Rectangle<int> progressDisplayBackground{ 466, 238, 341, 150 };
	g.fillRect(progressDisplayBackground);
	PNGImageFormat imageFormat;
	auto titleLabelImageData{ getTitleLabelImageData() };
	auto titleLabelImageDataSize{ getTitleLabelImageDataSize() };
	if (titleLabelImageData != nullptr) {
		MemoryInputStream memInputStream{ titleLabelImageData, titleLabelImageDataSize, false };
		auto titleLabelImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(titleLabelImage, 466, 238);
	}
	g.setColour(Color::black);
	g.setFont(FontsMenu::fontFor_ProgressDisplayMessage);
	Rectangle<int> messageArea{ 476, 278, 321, 30 };
	g.drawFittedText(message, messageArea, Justification::centred, 1, 1.0f);
}

const char* BankTransmissionComponent::getTitleLabelImageData() {
	//if (bank == 0)
	//	return transmissionType == TransmissionType::pull ? BinaryData::LabelPullAllBank1_png : BinaryData::LabelPushAllBank1_png;
	//if (bank == 1)
	//	return transmissionType == TransmissionType::pull ? BinaryData::LabelPullAllBank2_png : BinaryData::LabelPushAllBank2_png;
	//if (bank == 2)
	//	return transmissionType == TransmissionType::pull ? BinaryData::LabelPullAllBank3_png : BinaryData::LabelPushAllBank3_png;
	//else
		return nullptr;
}

size_t BankTransmissionComponent::getTitleLabelImageDataSize() {
	//if (bank == 0)
	//	return size_t(transmissionType == TransmissionType::pull ? BinaryData::LabelPullAllBank1_pngSize : BinaryData::LabelPushAllBank1_pngSize);
	//if (bank == 1)
	//	return size_t(transmissionType == TransmissionType::pull ? BinaryData::LabelPullAllBank2_pngSize : BinaryData::LabelPushAllBank2_pngSize);
	//if (bank == 2)
	//	return size_t(transmissionType == TransmissionType::pull ? BinaryData::LabelPullAllBank3_pngSize : BinaryData::LabelPushAllBank3_pngSize);
	//else
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

BankTransmissionComponent::~BankTransmissionComponent() {
}
