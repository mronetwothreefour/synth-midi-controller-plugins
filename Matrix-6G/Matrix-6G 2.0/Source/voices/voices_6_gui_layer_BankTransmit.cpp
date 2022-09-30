#include "voices_6_gui_layer_BankTransmit.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace BinaryData;
using MemBlock = MemoryBlock;

GUI_Layer_VoicesBankTransmit::GUI_Layer_VoicesBankTransmit(VoicesBank& bank, BankTransmitType transmitType, UnexposedParameters* unexposedParams) :
	bank{ bank },
	transmitType{ transmitType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() },
	voiceCounter{ VCS::numberOfSlotsInVoicesBank },
	progress{ 0.0 },
	progressBar{ progress },
	btn_Stop{ "" },
	btn_Close{ "" }
{
	progressBar.setComponentID(ID::comp_ProgressBar_VoicesBank.toString());
	addAndMakeVisible(progressBar);
	progressBar.setBounds(461, 289, 330, 18);

	auto buttons_y{ 317 };
	btn_Stop.setComponentID(ID::btn_Stop.toString());
	btn_Stop.onClick = [this] { cancelTransmission(); };
	btn_Stop.setBounds(607, buttons_y, 38, GUI::buttons_small_h);
	addAndMakeVisible(btn_Stop);

	btn_Close.setComponentID(ID::btn_Close.toString());
	btn_Close.addShortcut(KeyPress{ KeyPress::escapeKey });
	btn_Close.onClick = [this, transmitType, unexposedParams] {
		if (transmitType == BankTransmitType::pull) {
			auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
			transmitOptions->setIncomingVoiceShouldNotBeStored();
		}
		getParentComponent()->grabKeyboardFocus();
		setVisible(false); 
	};
	btn_Close.setBounds(605, buttons_y, 42, GUI::buttons_small_h);
	addChildComponent(btn_Close);

	if (unexposedParams->getTooltipsOptions()->shouldShowDescription()) {
		btn_Stop.setTooltip("Click to stop the bank transmission.");
		btn_Close.setTooltip("Click to close this window.");
	}

	setSize(GUI::editor_w, GUI::editor_h);

	voiceCounter = 0;
	startTimer(transmitTime);
}

void GUI_Layer_VoicesBankTransmit::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_VoicesBanks);
	g.setColour(GUI::color_ButtonBlue);
	Rectangle<int> borderBounds{ 441, 239, 370, 118 };
	g.fillRect(borderBounds);
	g.setColour(GUI::color_Device);
	auto componentBounds{ borderBounds.reduced(GUI::borders_w, GUI::borders_w) };
	g.fillRect(componentBounds);

	MemBlock mBlock{};
	if (transmitType == BankTransmitType::pull)
		mBlock = MemBlock{ lbl_PullingEntireBank_png, lbl_PullingEntireBank_pngSize };
	else
		mBlock = MemBlock{ lbl_PushingEntireBank_png, lbl_PushingEntireBank_pngSize };
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, componentBounds.getX(), componentBounds.getY());
}

void GUI_Layer_VoicesBankTransmit::timerCallback() {
	stopTimer();
	if (voiceCounter < VCS::numberOfSlotsInVoicesBank) {
		transmitMidiBufferForVoiceSlot(voiceCounter);
		++voiceCounter;
		progress = voiceCounter / (double)VCS::numberOfSlotsInVoicesBank;
		repaint();
		startTimer(transmitTime);
	}
	else {
		makeCloseButtonVisible();
		repaint();
	}
}

void GUI_Layer_VoicesBankTransmit::transmitMidiBufferForVoiceSlot(uint8 voiceSlot) {
	auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
	if (transmitType == BankTransmitType::pull) {
		auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
		transmitOptions->setIncomingVoiceShouldBeStoredInCustomBank(bank);
		SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(voiceSlot, outgoingBuffers);
	}
	else {
		auto voicesBanks{ unexposedParams->getVoicesBanks() };
		SysExMessages::addDataMessageForVoiceStoredInBankAndSlotToOutgoingBuffers(voicesBanks, bank, voiceSlot, outgoingBuffers);
		callAfterDelay(10, [this, outgoingBuffers, voiceSlot] {
				auto globalOptions{ unexposedParams->getGlobalOptions() };
				auto basicChannel{ globalOptions->basicChannel() };
				outgoingBuffers->addProgramChangeMessage(basicChannel, voiceSlot);
			}
		);
	}
}

void GUI_Layer_VoicesBankTransmit::cancelTransmission() {
	stopTimer();
	makeCloseButtonVisible();
	repaint();
}

void GUI_Layer_VoicesBankTransmit::makeCloseButtonVisible() {
	btn_Stop.setVisible(false);
	btn_Close.setVisible(true);
}
