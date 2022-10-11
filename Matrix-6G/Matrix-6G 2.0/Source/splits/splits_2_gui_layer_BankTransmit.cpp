#include "splits_2_gui_layer_BankTransmit.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Splits.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace BinaryData;
using MemBlock = MemoryBlock;

GUI_Layer_SplitsBankTransmit::GUI_Layer_SplitsBankTransmit(BankTransmitType transmitType, UnexposedParameters* unexposedParams) :
	transmitType{ transmitType },
	unexposedParams{ unexposedParams },
	transmitTime{ unexposedParams->getVoiceTransmissionOptions()->voiceTransmitTime() },
	splitCounter{ SPLT::numberOfSlotsInSplitsBank },
	progress{ 0.0 },
	progressBar{ progress },
	btn_Stop{ "" },
	btn_Close{ "" }
{
	progressBar.setComponentID(ID::comp_ProgressBar_SplitsBank.toString());
	addAndMakeVisible(progressBar);
	progressBar.setBounds(GUI::bounds_BankTransmitProgressBar);

	btn_Stop.setComponentID(ID::btn_Stop.toString());
	btn_Stop.onClick = [this] { cancelTransmission(); };
	btn_Stop.setBounds(GUI::bankTransmitStopButton_x, GUI::bankTransmitButtons_y, GUI::bankTransmitStopButton_w, GUI::buttons_small_h);
	addAndMakeVisible(btn_Stop);

	btn_Close.setComponentID(ID::btn_Close.toString());
	btn_Close.addShortcut(KeyPress{ KeyPress::escapeKey });
	btn_Close.onClick = [this, transmitType, unexposedParams] {
		getParentComponent()->grabKeyboardFocus();
		setVisible(false);
	};
	btn_Close.setBounds(GUI::bankTransmitCloseButton_x, GUI::bankTransmitButtons_y, GUI::bankTransmitCloseButton_w, GUI::buttons_small_h);
	addChildComponent(btn_Close);

	if (unexposedParams->getTooltipsOptions()->shouldShowDescription()) {
		btn_Stop.setTooltip("Click to stop the bank transmission.");
		btn_Close.setTooltip("Click to close this window.");
	}

	setSize(GUI::editor_w, GUI::editor_h);

	splitCounter = 0;
	startTimer(transmitTime);
}

void GUI_Layer_SplitsBankTransmit::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_VoicesBanks);
	g.setColour(GUI::color_ButtonGray);
	g.fillRect(GUI::bounds_BankTransmitBorder);
	g.setColour(GUI::color_Device);
	auto componentBounds{ GUI::bounds_BankTransmitBorder.reduced(GUI::borders_w, GUI::borders_w) };
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

void GUI_Layer_SplitsBankTransmit::timerCallback() {
	stopTimer();
	if (splitCounter < SPLT::numberOfSlotsInSplitsBank) {
		transmitMidiBufferForSplitSlot(splitCounter);
		++splitCounter;
		progress = splitCounter / (double)SPLT::numberOfSlotsInSplitsBank;
		repaint();
		startTimer(transmitTime);
	}
	else {
		makeCloseButtonVisible();
		repaint();
	}
}

void GUI_Layer_SplitsBankTransmit::transmitMidiBufferForSplitSlot(uint8 splitSlot) {
	auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
	if (transmitType == BankTransmitType::pull)
		SysExMessages::addRequestForSplitDataStoredInSlotToOutgoingBuffers(splitSlot, outgoingBuffers);
	else {
		auto splitsBank{ unexposedParams->getSplitsBank() };
		SysExMessages::addDataMessageForSplitStoredInSlotToOutgoingBuffers(splitsBank, splitSlot, outgoingBuffers);
		callAfterDelay(10, [this, outgoingBuffers, splitSlot] {
			auto globalOptions{ unexposedParams->getGlobalOptions() };
			auto basicChannel{ globalOptions->basicChannel() };
			outgoingBuffers->addProgramChangeMessage(basicChannel, splitSlot);
		});
	}
}

void GUI_Layer_SplitsBankTransmit::cancelTransmission() {
	stopTimer();
	makeCloseButtonVisible();
	repaint();
}

void GUI_Layer_SplitsBankTransmit::makeCloseButtonVisible() {
	btn_Stop.setVisible(false);
	btn_Close.setVisible(true);
}
