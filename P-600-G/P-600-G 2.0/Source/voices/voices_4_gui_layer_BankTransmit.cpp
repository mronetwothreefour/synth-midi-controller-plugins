#include "voices_4_gui_layer_BankTransmit.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace BinaryData;
using MemBlock = MemoryBlock;

GUI_Layer_VoicesBankTransmit::GUI_Layer_VoicesBankTransmit(BankTransmitType transmitType, UnexposedParameters* unexposedParams) :
	transmitType{ transmitType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() },
	voiceCounter{ VCS::numberOfSlotsInVoicesBank },
	progress{ 0.0 },
	progressBar{ progress },
	btn_Esc{ "" },
	btn_OK{ "" }
{
	addAndMakeVisible(progressBar);
	progressBar.setBounds(541, 176, 320, 18);

	btn_Esc.setComponentID(ID::btn_Esc.toString());
	btn_Esc.addShortcut(KeyPress{ KeyPress::escapeKey });
	btn_Esc.onClick = [this] { cancelTransmission(); };
	btn_Esc.setBounds(buttonBounds);
	addAndMakeVisible(btn_Esc);

	btn_OK.setComponentID(ID::btn_OK.toString());
	btn_OK.addShortcut(KeyPress{ KeyPress::returnKey });
	btn_OK.onClick = [this, transmitType, unexposedParams] {
		if (transmitType == BankTransmitType::pull) {
			auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
			transmitOptions->setIncomingVoiceShouldBeStored(false);
		}
		getParentComponent()->grabKeyboardFocus();
		setVisible(false);
	};
	btn_OK.setBounds(buttonBounds);
	addChildComponent(btn_OK);

	if (unexposedParams->getTooltipsOptions()->shouldShowDescription()) {
		btn_Esc.setTooltip("Click to stop the bank transmission.");
		btn_OK.setTooltip("Click to close this window.");
	}

	setSize(GUI::editor_w, GUI::editor_h);

	voiceCounter = 0;
	startTimer(transmitTime);
}

void GUI_Layer_VoicesBankTransmit::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_VoicesBanks);
	g.setOpacity(1.0f);

	auto component_x{ 526 };
	auto component_y{ 130 };
	MemBlock mBlock{};
	PNGImageFormat imageFormat;

	mBlock = MemBlock{ bkgrnd_VoicesBankTransmit_png, bkgrnd_VoicesBankTransmit_pngSize };
	MemoryInputStream memInputStream_Background{ mBlock, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream_Background) };
	g.drawImageAt(backgroundImage, component_x, component_y);

	if (transmitType == BankTransmitType::pull)
		mBlock = MemBlock{ lbl_PullingEntireBank_png, lbl_PullingEntireBank_pngSize };
	else
		mBlock = MemBlock{ lbl_PushingEntireBank_png, lbl_PushingEntireBank_pngSize };
	MemoryInputStream memInputStream_Title{ mBlock, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream_Title) };
	g.drawImageAt(titleImage, component_x, component_y);
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
		make_OK_ButtonVisible();
		repaint();
	}
}

void GUI_Layer_VoicesBankTransmit::transmitMidiBufferForVoiceSlot(uint8 voiceSlot) {
	auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
	if (transmitType == BankTransmitType::pull) {
		auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
		transmitOptions->setIncomingVoiceShouldBeStored(true);
		SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(voiceSlot, outgoingBuffers);
	}
	else {
		auto voicesBank{ unexposedParams->getVoicesBank() };
		SysExMessages::addDataMessageForVoiceStoredInSlotToOutgoingBuffers(voicesBank, voiceSlot, outgoingBuffers);
		callAfterDelay(10, [this, outgoingBuffers, voiceSlot] { outgoingBuffers->addProgramChangeMessage(voiceSlot); });
	}
}

void GUI_Layer_VoicesBankTransmit::cancelTransmission() {
	stopTimer();
	make_OK_ButtonVisible();
	repaint();
}

void GUI_Layer_VoicesBankTransmit::make_OK_ButtonVisible() {
	btn_Esc.setVisible(false);
	btn_OK.setVisible(true);
}
