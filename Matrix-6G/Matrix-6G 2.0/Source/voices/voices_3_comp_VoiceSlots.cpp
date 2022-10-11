#include "voices_3_comp_VoiceSlots.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using Bank = VoicesBank;

VoiceSlots::VoiceSlots(VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() },
	voicesBanks{ unexposedParams->getVoicesBanks() },
	transmitOptions{ unexposedParams->getVoiceTransmissionOptions() },
	selectedSlot{ VCS::numberOfSlotsInVoicesBank }
{
	for (uint8 slotNum = 0; slotNum != VCS::numberOfSlotsInVoicesBank; ++slotNum) {
		voiceSlotButtons.push_back(std::make_unique<VoiceSlotRadioButton>(bank, slotNum, unexposedParams));
		voiceSlotButtons[slotNum]->onClick = [this, slotNum] { selectedSlot = slotNum; };
		auto col_x{ (slotNum / 25) * (GUI::voiceSlotRadioButtton_w + voiceSlotRadioButtons_HorizGap) };
		auto row_y{ (slotNum % 25) * GUI::voiceAndSplitSlotRadioButtton_h };
		voiceSlotButtons[slotNum]->setTopLeftPosition(col_x, row_y);
		addAndMakeVisible(voiceSlotButtons[slotNum].get());
	}

	setSize(voiceSlots_w, voiceSlots_h);
}

void VoiceSlots::saveCurrentVoiceSettingsIntoSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataVector{ RawDataTools::extractRawVoiceDataFrom_GUI(exposedParams) };
		auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, selectedSlot);
	}
}

void VoiceSlots::loadVoiceFromSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
		RawDataTools::applyRawVoiceDataTo_GUI(selectedSlot, voiceDataVector.data(), exposedParams, transmitOptions);
		callAfterDelay(100, [this] {
			SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, outgoingBuffers);
		});
	}
}

void VoiceSlots::pullSelectedVoiceFromHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank)
		SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(selectedSlot, outgoingBuffers);
}

void VoiceSlots::pushSelectedVoiceToHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank)
		SysExMessages::addDataMessageForVoiceStoredInBankAndSlotToOutgoingBuffers(voicesBanks, bank, selectedSlot, outgoingBuffers);
}

void VoiceSlots::timerCallback() {
}

VoiceSlots::~VoiceSlots() {
	voiceSlotButtons.clear();
}
