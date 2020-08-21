#include "widget_BankTransmissionComponent.h"

#include "../banks/banks_ProgramBanksTabbedComponent.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_ProgramDump.h"
#include "../params/params_UnexposedParameters_Facade.h"



BankTransmissionComponent::BankTransmissionComponent(ProgramBanksTabbedComponent& tabbedComponent, TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	tabbedComponent{ tabbedComponent },
	bank{ (uint8)tabbedComponent.getCurrentTabIndex() },
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	title{ transmissionType == TransmissionType::push ? "Push All Programs To Bank " + (String)(bank + 1) : "Pull All Programs From Bank " + (String)(bank + 1) },
	message{ "" },
	transmitTime{ unexposedParams->midiOptions_get()->programTransmitTime() },
	programCounter{ 128 },
	progress{ 0.0 },
	progressBar{ progress },
	button_Stop{ "STOP" },
	button_OK{ "OK" }
{
	addAndMakeVisible(progressBar);
	auto progressBar_x{ 508 };
	auto progressBar_y{ 316 };
	auto progressBar_w{ 257 };
	auto progressBar_h{ 18 };
	progressBar.setBounds(progressBar_x, progressBar_y, progressBar_w, progressBar_h);

	addChildComponent(button_OK);
	addAndMakeVisible(button_Stop);
	button_OK.onClick = [this] { hideThisComponent(); };
	button_Stop.onClick = [this] { cancelTransmission(); };
	auto button_x{ 611 };
	auto button_y{ 352 };
	auto button_w{ 51 };
	auto button_h{ 21 };
	button_OK.setBounds(button_x, button_y, button_w, button_h);
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
		message += "Bank " + (String)(bank + 1) + " Program " + (String)programCounter;
		message += transmissionType == TransmissionType::push ? " To Hardware" : " From Hardware";
		repaint();
		startTimer(transmitTime);
	}
	else {
		message = "Transmission Complete";
		makeOKbuttonVisible();
		repaint();
	}
}

void BankTransmissionComponent::transmitMidiBufferForProgramSlot(uint8 programSlot) {
	if (transmissionType == TransmissionType::pull) {
		ProgramDump::addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(bank, programSlot, unexposedParams);
		auto programBankTab{ tabbedComponent.getCurrentProgramBankTab() };
		if (programBankTab != nullptr)
			callAfterDelay(transmitTime, [this, programBankTab, programSlot] { programBankTab->updateProgramSlotText(programSlot); });
	}
	else
		ProgramDump::addProgramInBankAndSlotToOutgoingMidiBuffers(bank, programSlot, unexposedParams);
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
	g.setColour(Color::black);
	Font titleFont{ FontsDB::family_Global, FontsDB::style_ForProgressDisplayTitle, FontsDB::size_ForProgressDisplayTitle };
	g.setFont(titleFont);
	Rectangle<int> titleArea{ 476, 248, 321, 30 };
	g.drawFittedText(title, titleArea, Justification::centred, 1, 1.0f);
	Font messageFont{ FontsDB::family_Global, FontsDB::style_ForProgressDisplayMessage, FontsDB::size_ForProgressDisplayMessage };
	g.setFont(messageFont);
	Rectangle<int> messageArea{ 476, 278, 321, 30 };
	g.drawFittedText(message, messageArea, Justification::centred, 1, 1.0f);
}

void BankTransmissionComponent::cancelTransmission() {
	stopTimer();
	message = "Transmission Canceled";
	makeOKbuttonVisible();
	repaint();
}

void BankTransmissionComponent::makeOKbuttonVisible() {
	button_Stop.setVisible(false);
	button_OK.setVisible(true);
}

void BankTransmissionComponent::hideThisComponent() {
	setVisible(false);
}

BankTransmissionComponent::~BankTransmissionComponent() {
}
