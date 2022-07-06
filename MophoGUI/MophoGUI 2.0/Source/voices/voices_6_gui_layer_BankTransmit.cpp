#include "voices_6_gui_layer_BankTransmit.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_1_VoiceDataMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace BinaryData;
using MemBlock = MemoryBlock;
using s_t = size_t;



GUI_Layer_BankTransmit::GUI_Layer_BankTransmit(VoicesBank& bank, BankTransmitType transmitType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmitType{ transmitType },
	unexposedParams{ unexposedParams },
	outgoingMIDI{ unexposedParams->getOutgoingMidiBuffers() },
	progressMessage{ "" },
	transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() },
	voiceCounter{ VCS::numberOfSlotsInVoicesBank },
	progress{ 0.0 },
	progressBar{ progress },
	button_Stop{ "" },
	button_Close{ unexposedParams }
{
	bankName = (bank < VoicesBank::custom_1 ? "Factory " : "Custom ") + String((int)bank % 3 + 1);

	addAndMakeVisible(progressBar);
	progressBar.setBounds(461, 319, 351, 18);

	button_Stop.setComponentID(ID::button_Stop.toString());
	button_Stop.onClick = [this] { cancelTransmission(); };
	button_Stop.setBounds(buttonBounds);
	addAndMakeVisible(button_Stop);

	button_Close.setBounds(buttonBounds);
	addChildComponent(button_Close);

	setSize(GUI::editor_w, GUI::editor_h);

	voiceCounter = 0;
	startTimer(transmitTime);
}

void GUI_Layer_BankTransmit::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(getParentComponent()->getBounds());
	g.setOpacity(1.0f);
	Rectangle<int> bkgrndBounds{ 444, 251, 385, 124 };
	g.fillRect(bkgrndBounds);
	g.setColour(GUI::color_Device);
	g.fillRect(bkgrndBounds.reduced(2));

	MemBlock mBlock{};
	if (transmitType == BankTransmitType::pull)
		mBlock = MemBlock{ lbl_PullingEntireBank_png, lbl_PullingEntireBank_pngSize };
	else
		mBlock = MemBlock{ lbl_PushingEntireBank_png, lbl_PushingEntireBank_pngSize };
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, 454, 260);

	g.setColour(GUI::color_Black);
	g.setFont(GUI::fontFor_ProgressDisplayMessage);
	const Rectangle<int> progressMessageBounds{ 461, 290, 351, 28 };
	g.drawFittedText(progressMessage, progressMessageBounds, Justification::centred, 1, 1.0f);
}

void GUI_Layer_BankTransmit::timerCallback() {
	stopTimer();
	if (voiceCounter < VCS::numberOfSlotsInVoicesBank) {
		transmitMidiBufferForVoiceSlot(voiceCounter);
		++voiceCounter;
		progress = voiceCounter / (double)VCS::numberOfSlotsInVoicesBank;
		progressMessage = transmitType == BankTransmitType::push ? "Pushing " : "Pulling ";
		progressMessage += bankName + " Program " + (String)voiceCounter;
		progressMessage += transmitType == BankTransmitType::push ? " To Hardware" : " From Hardware";
		repaint();
		startTimer(transmitTime);
	}
	else {
		progressMessage = "Transmission Complete";
		makeClosebuttonVisible();
		repaint();
	}
}

void GUI_Layer_BankTransmit::transmitMidiBufferForVoiceSlot(uint8 voiceSlot) {
	if (transmitType == BankTransmitType::pull)
		VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(bank, voiceSlot, outgoingMIDI);
	else {
		auto voiceDataMessageVector{ VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(bank, voiceSlot, unexposedParams) };
		outgoingMIDI->addDataMessage(voiceDataMessageVector);
	}
}

void GUI_Layer_BankTransmit::cancelTransmission() {
	stopTimer();
	progressMessage = "Transmission Canceled";
	makeClosebuttonVisible();
	repaint();
}

void GUI_Layer_BankTransmit::makeClosebuttonVisible() {
	button_Stop.setVisible(false);
	button_Close.setVisible(true);
}
