#include "voices_3_comp_VoiceSlots.h"

#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../midi/midi_1_SysExMessages.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

VoiceSlots::VoiceSlots(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	outgoingMIDI{ unexposedParams->getOutgoing_MIDI_Buffers() },
	voicesBank{ unexposedParams->getVoicesBank() },
	selectedSlot{ VCS::numberOfSlotsInVoicesBank }
{
	for (uint8 slotNum = 0; slotNum != VCS::numberOfSlotsInVoicesBank; ++slotNum) {
		voiceSlotButtons.push_back(std::make_unique<VoiceSlotRadioButton>(slotNum, unexposedParams));
		voiceSlotButtons[slotNum]->onClick = [this, slotNum] { selectedSlot = slotNum; };
		auto col_x{ (slotNum / 10) * (GUI::voiceSlotRadioButtton_w) };
		auto row_y{ (slotNum % 10) * GUI::voiceSlotRadioButtton_h };
		voiceSlotButtons[slotNum]->setTopLeftPosition(col_x, row_y);
		addAndMakeVisible(voiceSlotButtons[slotNum].get());
	}

	setSize(voiceSlots_w, voiceSlots_h);
}

void VoiceSlots::saveCurrentVoiceSettingsIntoSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataVector{ RawDataTools::extractRawVoiceDataFromExposedParameters(exposedParams) };
		auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
		voicesBank->storeVoiceDataHexStringInSlot(voiceDataHexString, selectedSlot);
	}
}

void VoiceSlots::loadVoiceFromSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
		auto transmitOptions{ unexposedParams->getVoiceTransmissionOptions() };
		RawDataTools::applyRawVoiceDataToExposedParameters(voiceDataVector.data(), exposedParams, transmitOptions);
		transmitOptions->setCurrentVoiceNumber(selectedSlot);
		callAfterDelay(100, [this, transmitOptions] {
			auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
			SysExMessages::addDataMessageForCurrentVoiceToOutgoingBuffers(exposedParams, transmitOptions, outgoingBuffers);
		});
	}
}

void VoiceSlots::pullSelectedVoiceFromHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank)
		SysExMessages::addRequestForVoiceDataStoredInSlotToOutgoingBuffers(selectedSlot, outgoingMIDI);
}

void VoiceSlots::pushSelectedVoiceToHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto outgoingBuffers{ unexposedParams->getOutgoing_MIDI_Buffers() };
		SysExMessages::addDataMessageForVoiceStoredInSlotToOutgoingBuffers(voicesBank, selectedSlot, outgoingBuffers);
	}
}

void VoiceSlots::timerCallback() {
}

VoiceSlots::~VoiceSlots() {
	voiceSlotButtons.clear();
}
