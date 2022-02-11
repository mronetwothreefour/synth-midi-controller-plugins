#include "voices_VoiceSlotsComponent.h"

#include "voices_Constants.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../midi/midi_EditBufferDataMessage.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoiceSlotsComponent::VoiceSlotsComponent(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	selectedSlot{ banks::numberOfSlotsInBank }
{
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	for (uint8 slot = 0; slot != banks::numberOfSlotsInBank; ++slot) {
		setUpVoiceSlotToggleButton(slot);
		addAndMakeVisible(voiceSlotButtons[slot]);
	}

	if (bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3) {
		voicesBanks->addListenerToNameStringsForCustomBank(this, bank);
	}

	setSize(GUI::voiceSlotsWidget_w, GUI::voiceSlotsWidget_h);
}

void VoiceSlotsComponent::setUpVoiceSlotToggleButton(uint8 slot) {
	voiceSlotButtons[slot].setComponentID(ID::component_VoiceSlotRadioButton.toString());
	voiceSlotButtons[slot].setRadioGroupId(1);
	voiceSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForVoiceSlotToggleButton(slot);
	setTextForVoiceSlotToggleButton(slot);
}

void VoiceSlotsComponent::setTooltipForVoiceSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescription()) {
		slotTooltip += "Click a program" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
		slotTooltip += "CTRL+C copies the selected program" + GUI::apostrophe + "s settings into the clipboard.\n";
		slotTooltip += "CTRL+V overwrites the selected program with the settings in the\n";
		slotTooltip += "clipboard (only slots in the Custom banks can be overwritten).";
	}
	voiceSlotButtons[slot].setTooltip(slotTooltip);
}

void VoiceSlotsComponent::setTextForVoiceSlotToggleButton(uint8 slot) {
	String slotString{ int(slot + 1) };
	slotString = slotString.paddedLeft('0', 3);
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	auto voiceName{ voicesBanks->nameOfVoiceInBankSlot(bank, slot) };
	voiceSlotButtons[slot].setName(slotString + " " + voiceName);
	voiceSlotButtons[slot].repaint();
}

void VoiceSlotsComponent::saveCurrentVoiceSettingsIntoSelectedSlot() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto voiceDataVector{ RawDataTools::extractFromExposedParameters(exposedParams) };
		auto voiceDataHexString{ RawDataTools::convertDataVectorToHexString(voiceDataVector) };
		auto voicesBanks{ unexposedParams->voicesBanks_get() };
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, selectedSlot);
		setTextForVoiceSlotToggleButton(selectedSlot);
		repaint();
	}
}

void VoiceSlotsComponent::loadVoiceFromSelectedSlot() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto voicesBanks{ unexposedParams->voicesBanks_get() };
		auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertHexStringToDataVector(voiceDataHexString) };
		RawDataTools::applyToExposedParameters(voiceDataVector.data(), exposedParams, unexposedParams);
		callAfterDelay(100, [this] { EditBufferDataMessage::addEditBufferDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get()); });
	}
}

void VoiceSlotsComponent::pullSelectedVoiceFromHardware() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		auto transmitTime{ midiOptions->voiceTransmitTime() };
		VoiceDataMessage::addRequestForVoiceDataStoredInBankAndSlotToOutgoingMidiBuffers(bank, selectedSlot, outgoingBuffers);
		callAfterDelay(transmitTime, [this] { setTextForVoiceSlotToggleButton(selectedSlot); });
		callAfterDelay(transmitTime + 20, [this] { voiceSlotButtons[selectedSlot].repaint(); });
	}
}

void VoiceSlotsComponent::pushSelectedVoiceToHardware() {
	if (selectedSlot < banks::numberOfSlotsInBank) {
		auto dumpDataVector{ VoiceDataMessage::createDataMessageForVoiceStoredInBankAndSlot(bank, selectedSlot, unexposedParams) };
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		outgoingBuffers->addDataMessage(dumpDataVector);
	}
}

void VoiceSlotsComponent::resized() {
	for (auto i = 0; i != banks::numberOfSlotsInBank; ++i) {
		auto col_x{ (i / 16) * (GUI::voiceSlotRadioButtton_w + GUI::voiceSlotRadioButtonsHorizontalGap) };
		auto row_y{ (i % 16) * GUI::voiceSlotRadioButtton_h };
		voiceSlotButtons[i].setBounds(col_x, row_y, GUI::voiceSlotRadioButtton_w, GUI::voiceSlotRadioButtton_h);
	}
}

void VoiceSlotsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("pgm", false, true) };
	setTextForVoiceSlotToggleButton((uint8)slotString.getIntValue());
}

void VoiceSlotsComponent::timerCallback() {
}

VoiceSlotsComponent::~VoiceSlotsComponent() {
	if (bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3) {
		auto voicesBanks{ unexposedParams->voicesBanks_get() };
		voicesBanks->removeListenerFromNameStringsForCustomBank(this, bank);
	}
}

