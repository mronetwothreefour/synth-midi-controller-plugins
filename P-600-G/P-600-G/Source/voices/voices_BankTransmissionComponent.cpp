#include "voices_BankTransmissionComponent.h"

#include "voices_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



ProgramBankTransmissionComponent::ProgramBankTransmissionComponent(TransmissionType transmissionType, UnexposedParameters* unexposedParams) :
	transmissionType{ transmissionType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->voiceTransmissionOptions_get()->voiceTransmitTime() },
	pgmCounter{ voices::numberOfSlotsInVoicesBank },
	progress{ 0.0 },
	progressBar{ progress }
{
	addAndMakeVisible(progressBar);
	progressBar.setBounds(GUI::bounds_BankTransmitProgressBar);

	button_Esc.setComponentID(ID::button_EscBankTransmit.toString());
	button_Esc.addShortcut(KeyPress(KeyPress::escapeKey));
	addAndMakeVisible(button_Esc);
	button_Esc.onClick = [this] { cancelTransmission(); };
	button_Esc.setBounds(GUI::bounds_BankTransmitButtons);

	button_OK.setComponentID(ID::button_OKBankTransmit.toString());
	addChildComponent(button_OK);
	button_OK.onClick = [this, transmissionType, unexposedParams] {
		if (transmissionType == TransmissionType::pull) {
			auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
			voiceTransmissionOptions->setIncomingVoiceShouldNotBeSavedInVoicesBank();
		}
		hideThisComponent();
	};
	button_OK.setBounds(GUI::bounds_BankTransmitButtons);

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_Esc.setTooltip("Cancels the bank transmission.");
		button_OK.setTooltip("Close this window.");
	}

	pgmCounter = 0;
	startTimer(transmitTime);
}

void ProgramBankTransmissionComponent::timerCallback() {
	stopTimer();
	if (pgmCounter < voices::numberOfSlotsInVoicesBank) {
		transmitMidiBufferForProgramSlot(pgmCounter);
		++pgmCounter;
		progress = pgmCounter / (double)voices::numberOfSlotsInVoicesBank;
		repaint();
		startTimer(transmitTime);
	}
	else {
		makeOKbuttonVisible();
		repaint();
	}
}

void ProgramBankTransmissionComponent::transmitMidiBufferForProgramSlot(uint8 pgmSlot) {
	auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	if (transmissionType == TransmissionType::pull) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		voiceTransmissionOptions->setIncomingVoiceShouldBeSavedInVoicesBank();
		VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(pgmSlot, outgoingBuffers);
	}
	else {
		VoiceDataMessage::addVoiceDataMessageForVoiceStoredInSlotToOutgoingMidiBuffers(pgmSlot, unexposedParams);
		callAfterDelay(10, [this, outgoingBuffers, pgmSlot]
			{
				outgoingBuffers->addProgramChangeMessage(MIDI::channel, pgmSlot);
			}
		);
	}
}

void ProgramBankTransmissionComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_VoicesBankWindow);
	g.setColour(Color::progressBarGray);
	PNGImageFormat imageFormat;
	MemoryInputStream bkgrndMemInputStream{ BinaryData::BankTransmissionWindowBackground_png, BinaryData::BankTransmissionWindowBackground_pngSize, false };
	auto bkgrndImage{ imageFormat.decodeImage(bkgrndMemInputStream) };
	g.drawImageAt(bkgrndImage, GUI::bankTransmitWindow_x, GUI::bankTransmitWindow_y);
	auto titleLabelImageData{ getTitleLabelImageData() };
	auto titleLabelImageDataSize{ getTitleLabelImageDataSize() };
	if (titleLabelImageData != nullptr) {
		MemoryInputStream titleMemInputStream{ titleLabelImageData, titleLabelImageDataSize, false };
		auto titleImage{ imageFormat.decodeImage(titleMemInputStream) };
		g.drawImageAt(titleImage, GUI::bankTransmitWindow_x, GUI::bankTransmitWindow_y);
	}
}

const char* ProgramBankTransmissionComponent::getTitleLabelImageData() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::PullingBankTitle_png;
	if (transmissionType == TransmissionType::push)
		return BinaryData::PushingBankTitle_png;
	else
		return nullptr;
}

size_t ProgramBankTransmissionComponent::getTitleLabelImageDataSize() {
	if (transmissionType == TransmissionType::pull)
		return BinaryData::PullingBankTitle_pngSize;
	if (transmissionType == TransmissionType::push)
		return BinaryData::PushingBankTitle_pngSize;
	else
		return (size_t)0;
}

void ProgramBankTransmissionComponent::cancelTransmission() {
	stopTimer();
	makeOKbuttonVisible();
	repaint();
}

void ProgramBankTransmissionComponent::makeOKbuttonVisible() {
	button_Esc.setVisible(false);
	button_Esc.clearShortcuts();
	button_OK.setVisible(true);
	button_OK.addShortcut(KeyPress(KeyPress::escapeKey));
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));
}

void ProgramBankTransmissionComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
