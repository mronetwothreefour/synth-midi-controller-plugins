#include "splits_2_comp_SplitSlots.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Splits.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

SplitSlots::SplitSlots(UnexposedParameters* unexposedParams) :
	outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
	splitsBank{ unexposedParams->getSplitsBank() },
	splitOptions{ unexposedParams->getSplitOptions() },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() },
	selectedSlot{ SPLT::numberOfSlotsInSplitsBank }
{
	for (uint8 slotNum = 0; slotNum != SPLT::numberOfSlotsInSplitsBank; ++slotNum) {
		splitSlotButtons.push_back(std::make_unique<SplitSlotRadioButton>(slotNum, unexposedParams));
		splitSlotButtons[slotNum]->onClick = [this, slotNum] { selectedSlot = slotNum; };
		auto col_x{ (slotNum / 10) * (GUI::splitSlotRadioButtton_w + splitSlotRadioButtons_HorizGap) };
		auto row_y{ (slotNum % 10) * GUI::voiceAndSplitSlotRadioButtton_h };
		splitSlotButtons[slotNum]->setTopLeftPosition(col_x, row_y);
		addAndMakeVisible(splitSlotButtons[slotNum].get());
	}

	setSize(splitSlots_w, splitSlots_h);
}

void SplitSlots::saveCurrentSplitSettingsIntoSelectedSlot() {
	if (selectedSlot < SPLT::numberOfSlotsInSplitsBank) {
		auto splitDataVector{ RawDataTools::extractRawSplitDataFrom_GUI(splitOptions) };
		auto splitDataHexString{ RawDataTools::convertDataVectorToHexString(splitDataVector) };
		splitsBank->storeSplitDataHexStringInSlot(splitDataHexString, selectedSlot);
	}
}

void SplitSlots::loadSplitFromSelectedSlot() {
	if (selectedSlot < SPLT::numberOfSlotsInSplitsBank) {
		auto splitDataHexString{ splitsBank->getSplitDataHexStringFromSlot(selectedSlot) };
		auto splitDataVector{ RawDataTools::convertHexStringToDataVector(splitDataHexString) };
		RawDataTools::applyRawSplitDataTo_GUI(splitDataVector.data(), splitOptions);
		callAfterDelay(100, [this] {
			SysExMessages::addDataMessageForSplitStoredInSlotToOutgoingBuffers(splitsBank, selectedSlot, outgoingBuffers);
		});
	}
}

void SplitSlots::pullSelectedSplitFromHardware() {
	if (selectedSlot < SPLT::numberOfSlotsInSplitsBank)
		SysExMessages::addRequestForSplitDataStoredInSlotToOutgoingBuffers(selectedSlot, outgoingBuffers);
}

void SplitSlots::pushSelectedSplitToHardware() {
	if (selectedSlot < SPLT::numberOfSlotsInSplitsBank)
		SysExMessages::addDataMessageForSplitStoredInSlotToOutgoingBuffers(splitsBank, selectedSlot, outgoingBuffers);
}

void SplitSlots::timerCallback() {
}

SplitSlots::~SplitSlots() {
	splitSlotButtons.clear();
}
