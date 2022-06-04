#include "2_voices_comp_VoiceSlots.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/0_midi_RawDataTools.h"
#include "../midi/1_midi_EditBufferDataMessage.h"
#include "../midi/1_midi_VoiceDataMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



VoiceSlots::VoiceSlots(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	selectedSlot{ VCS::numberOfSlotsInVoicesBank }
{
	auto voicesBanks{ unexposedParams->getVoicesBanks() };
	if (bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3) {
		voicesBanks->addListenerToNameStringsForCustomBank(this, bank);
	}

	auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipsOptions->shouldShowDescriptions() };
	for (uint8 slot = 0; slot != VCS::numberOfSlotsInVoicesBank; ++slot) {
		voiceSlotButtons[slot].setComponentID(ID::button_VoiceSlotRadioButton.toString());
		voiceSlotButtons[slot].setRadioGroupId(1);
		voiceSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
		setTextForVoiceSlotToggleButton(slot);
		String slotTooltip{ "" };
		if (shouldShowDescriptions) {
			slotTooltip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
			slotTooltip += "CTRL+C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
			slotTooltip += "CTRL+V overwrites the selected program with the settings in the\n";
			slotTooltip += "clipboard (only slots in the Custom banks can be overwritten).";
		}
		voiceSlotButtons[slot].setTooltip(slotTooltip);
		addAndMakeVisible(voiceSlotButtons[slot]);
	}

	setSize(voiceSlots_w, voiceSlots_h);
}

void VoiceSlots::setTextForVoiceSlotToggleButton(uint8 slot) {
	auto slotString{ String(slot + 1) };
	slotString = slotString.paddedLeft('0', 3);
	auto voicesBanks{ unexposedParams->getVoicesBanks() };
	auto voiceName{ voicesBanks->nameOfVoiceInBankSlot(bank, slot) };
	MessageManagerLock mmlock;
	voiceSlotButtons[slot].setName(slotString + " " + voiceName);
	voiceSlotButtons[slot].repaint();
}

void VoiceSlots::resized() {
	for (auto slotNum = 0; slotNum != VCS::numberOfSlotsInVoicesBank; ++slotNum) {
		auto col_x{ (slotNum / 16) * (voiceSlotRadioButtton_w + voiceSlotRadioButtons_HorizGap) };
		auto row_y{ (slotNum % 16) * voiceSlotRadioButtton_h };
		voiceSlotButtons[slotNum].setBounds(col_x, row_y, voiceSlotRadioButtton_w, voiceSlotRadioButtton_h);
	}
}

void VoiceSlots::saveCurrentVoiceSettingsIntoSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataVector{ RawDataTools::extractRawDataFromExposedParameters(exposedParams) };
		auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
		auto voicesBanks{ unexposedParams->getVoicesBanks() };
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, selectedSlot);
		setTextForVoiceSlotToggleButton(selectedSlot);
		repaint();
	}
}

void VoiceSlots::loadVoiceFromSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voicesBanks{ unexposedParams->getVoicesBanks() };
		auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
		RawDataTools::applyRawDataToExposedParameters(voiceDataVector.data(), exposedParams, unexposedParams);
		callAfterDelay(100, [this] { 
			EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->getOutgoingMidiBuffers()); 
		});
	}
}

void VoiceSlots::pullSelectedVoiceFromHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto outgoingBuffers{ unexposedParams->getOutgoingMidiBuffers() };
		auto voiceTransmissionOptions{ unexposedParams->getVoiceTransmissionOptions() };
		auto transmitTime{ voiceTransmissionOptions->voiceTransmitTime() };
		VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(bank, selectedSlot, outgoingBuffers);
		callAfterDelay(transmitTime, [this] { setTextForVoiceSlotToggleButton(selectedSlot); });
		callAfterDelay(transmitTime + 20, [this] { voiceSlotButtons[selectedSlot].repaint(); });
	}
}

void VoiceSlots::pushSelectedVoiceToHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto dumpDataVector{ VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(bank, selectedSlot, unexposedParams) };
		auto outgoingBuffers{ unexposedParams->getOutgoingMidiBuffers() };
		outgoingBuffers->addDataMessage(dumpDataVector);
	}
}

void VoiceSlots::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("voice_", false, true) };
	setTextForVoiceSlotToggleButton((uint8)slotString.getIntValue());
}

void VoiceSlots::timerCallback() {
}

VoiceSlots::~VoiceSlots() {
	if (bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3) {
		auto voicesBanks{ unexposedParams->getVoicesBanks() };
		voicesBanks->removeListenerFromNameStringsForCustomBank(this, bank);
	}
}
