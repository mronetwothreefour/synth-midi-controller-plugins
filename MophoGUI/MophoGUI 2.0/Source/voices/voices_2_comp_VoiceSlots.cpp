#include "voices_2_comp_VoiceSlots.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../midi/midi_1_EditBufferDataMessage.h"
#include "../midi/midi_1_VoiceDataMessage.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



VoiceSlots::VoiceSlots(VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	outgoingMIDI{ unexposedParams->getOutgoingMidiBuffers() },
	voicesBanks{ unexposedParams->getVoicesBanks() },
	voiceTransmit{ unexposedParams->getVoiceTransmissionOptions() },
	selectedSlot{ VCS::numberOfSlotsInVoicesBank }
{
	if (bank >= VoicesBank::custom_1)
		voicesBanks->addListenerToCustomVoiceNameStringsTree(this);

	auto tooltipsOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipsOptions->shouldShowDescriptions() };
	for (uint8 slotNum = 0; slotNum != VCS::numberOfSlotsInVoicesBank; ++slotNum) {
		voiceSlotButtons[slotNum].setComponentID(ID::button_VoiceSlotRadioButton.toString());
		voiceSlotButtons[slotNum].setRadioGroupId(1);
		voiceSlotButtons[slotNum].onClick = [this, slotNum] { selectedSlot = slotNum; };
		setTextForVoiceSlotToggleButton(slotNum);
		String tip{ "" };
		if (shouldShowDescriptions) {
			tip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
			tip += "CTRL+C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
			tip += "CTRL+V overwrites the selected program with the settings in the\n";
			tip += "clipboard (only slots in the Custom banks can be overwritten).";
		}
		voiceSlotButtons[slotNum].setTooltip(tip);
		auto col_x{ (slotNum / 16) * (voiceSlotRadioButtton_w + voiceSlotRadioButtons_HorizGap) };
		auto row_y{ (slotNum % 16) * voiceSlotRadioButtton_h };
		voiceSlotButtons[slotNum].setBounds(col_x, row_y, voiceSlotRadioButtton_w, voiceSlotRadioButtton_h);
		addAndMakeVisible(voiceSlotButtons[slotNum]);
	}

	setSize(voiceSlots_w, voiceSlots_h);
}

void VoiceSlots::setTextForVoiceSlotToggleButton(uint8 slotNum) {
	auto slotNumString{ String(slotNum + 1) };
	slotNumString = slotNumString.paddedLeft('0', 3);
	auto voiceName{ voicesBanks->nameOfVoiceInBankSlot(bank, slotNum) };
	MessageManagerLock mmlock;
	voiceSlotButtons[slotNum].setName(slotNumString + " " + voiceName);
	voiceSlotButtons[slotNum].repaint();
	repaint();
}

void VoiceSlots::saveCurrentVoiceSettingsIntoSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataVector{ RawDataTools::extractRawDataFromExposedParameters(exposedParams) };
		auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, selectedSlot);
		setTextForVoiceSlotToggleButton(selectedSlot);
	}
}

void VoiceSlots::loadVoiceFromSelectedSlot() {
	if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
		auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
		RawDataTools::applyRawDataToExposedParameters(voiceDataVector.data(), exposedParams, unexposedParams);
		callAfterDelay(100, [this] { 
			EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams); 
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

void VoiceSlots::valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) {
	if (tree.getType().toString() == "bank_" + String((int)bank % 3)) {
		auto propertyName{ propertyID.toString() };
		auto slotString{ propertyName.fromLastOccurrenceOf("slot_", false, true) };
		auto slotNum{ slotString.getIntValue() };
		setTextForVoiceSlotToggleButton((uint8)slotNum);
	}
}

void VoiceSlots::timerCallback() {
}

VoiceSlots::~VoiceSlots() {
	if (bank >= VoicesBank::custom_1)
		voicesBanks->removeListenerFromCustomVoiceNameStringsTree(this);
}
