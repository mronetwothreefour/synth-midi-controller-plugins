#include "voices_2_comp_VoiceSlots.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../midi/midi_1_EditBufferDataMessage.h"
#include "../midi/midi_1_VoiceDataMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



VoiceSlots::VoiceSlots(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	outgoingMIDI{ unexposedParams->getOutgoingMidiBuffers() },
	voicesBanks{ unexposedParams->getVoicesBanks() },
	voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() },
	selectedSlot{ VCS::numberOfSlotsInVoicesBank }
{
	if (bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3)
		voicesBanks->addListenerToNameStringsForCustomBank(this, bank);

	auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipsOptions->shouldShowDescriptions() };
	for (uint8 slot = 0; slot != VCS::numberOfSlotsInVoicesBank; ++slot) {
		voiceSlotButtons[slot].setComponentID(ID::button_VoiceSlotRadioButton.toString());
		voiceSlotButtons[slot].setRadioGroupId(1);
		voiceSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
		setTextForVoiceSlotToggleButton(slot);
		String tip{ "" };
		if (shouldShowDescriptions) {
			tip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
			tip += "CTRL+C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
			tip += "CTRL+V overwrites the selected program with the settings in the\n";
			tip += "clipboard (only slots in the Custom banks can be overwritten).";
		}
		voiceSlotButtons[slot].setTooltip(tip);
		addAndMakeVisible(voiceSlotButtons[slot]);
	}

	setSize(voiceSlots_w, voiceSlots_h);
}

void VoiceSlots::setTextForVoiceSlotToggleButton(uint8 slot) {
	auto slotString{ String(slot + 1) };
	slotString = slotString.paddedLeft('0', 3);
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
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, selectedSlot);
		setTextForVoiceSlotToggleButton(selectedSlot);
		repaint();
	}
}

void VoiceSlots::loadVoiceFromSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
		RawDataTools::applyRawDataToExposedParameters(voiceDataVector.data(), exposedParams, unexposedParams);
		callAfterDelay(100, [this] { 
			EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, outgoingMIDI); 
		});
	}
}

void VoiceSlots::pullSelectedVoiceFromHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto transmitTime{ voiceTransmit->voiceTransmitTime() };
		VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingBuffers(bank, selectedSlot, outgoingMIDI);
		callAfterDelay(transmitTime, [this] { setTextForVoiceSlotToggleButton(selectedSlot); });
		callAfterDelay(transmitTime + 20, [this] { voiceSlotButtons[selectedSlot].repaint(); });
	}
}

void VoiceSlots::pushSelectedVoiceToHardware() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto dumpDataVector{ VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(bank, selectedSlot, unexposedParams) };
		outgoingMIDI->addDataMessage(dumpDataVector);
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
	if (bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3)
		voicesBanks->removeListenerFromNameStringsForCustomBank(this, bank);
}
