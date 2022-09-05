#include "voices_7_gui_layer_BankTransmit.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace BinaryData;
using MemBlock = MemoryBlock;
using s_t = size_t;

GUI_Layer_BankTransmit::GUI_Layer_BankTransmit(VoicesBank& bank, BankTransmitType transmitType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmitType{ transmitType },
	unexposedParams{ unexposedParams },
	progressMessage{ "" },
	transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() },
	voiceCounter{ VCS::numberOfSlotsInVoicesBank },
	progress{ 0.0 },
	progressBar{ progress },
	btn_Stop{ "" },
	btn_Close{ unexposedParams }
{
	bankName = (bank < VoicesBank::custom_1 ? "Factory " : "Custom ") + String((int)bank % 3 + 1);

	addAndMakeVisible(progressBar);
	progressBar.setBounds(461, 319, 351, 18);

	btn_Stop.setComponentID(ID::btn_Stop.toString());
	btn_Stop.onClick = [this] { cancelTransmission(); };
	btn_Stop.setBounds(buttonBounds);
	addAndMakeVisible(btn_Stop);

	btn_Close.setBounds(buttonBounds);
	addChildComponent(btn_Close);

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
	g.setFont(GUI::font_ProgressDisplayMessage);
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
	auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
	if (transmitType == BankTransmitType::pull)
		SysExMessages::addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(bank, voiceSlot, outgoingBuffers);
	else {
		auto voicesBanks{ unexposedParams->getVoicesBanks() };
		SysExMessages::addDataMessageForVoiceStoredInBankAndSlotToOutgoingBuffers(voicesBanks, bank, voiceSlot, outgoingBuffers);
	}
}

void GUI_Layer_BankTransmit::cancelTransmission() {
	stopTimer();
	progressMessage = "Transmission Canceled";
	makeClosebuttonVisible();
	repaint();
}

void GUI_Layer_BankTransmit::makeClosebuttonVisible() {
	btn_Stop.setVisible(false);
	btn_Close.setVisible(true);
}
