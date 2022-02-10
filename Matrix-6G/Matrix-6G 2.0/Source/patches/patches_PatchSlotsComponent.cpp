#include "patches_PatchSlotsComponent.h"

#include "patches_Constants.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_VoiceDataMessage.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoiceSlotsComponent::VoiceSlotsComponent(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	selectedSlot{ voices::numberOfSlotsInBank }
{
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	for (uint8 slot = 0; slot != voices::numberOfSlotsInBank; ++slot) {
		setUpVoiceSlotToggleButton(slot);
		addAndMakeVisible(voiceSlotButtons[slot]);
	}

	if (bank == VoicesBank::customA || bank == VoicesBank::customB) {
		voicesBanks->addListenerToNameStringsForCustomBank(this, bank);
	}

	setSize(GUI::voiceSlotsComponent_w, GUI::voiceSlotsComponent_h);
}

void VoiceSlotsComponent::setUpVoiceSlotToggleButton(uint8 slot) {
	voiceSlotButtons[slot].setComponentID(ID::button_VoiceSlotRadioButton.toString());
	voiceSlotButtons[slot].setRadioGroupId(1);
	voiceSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForVoiceSlotToggleButton(slot);
	setTextForVoiceSlotToggleButton(slot);
}

void VoiceSlotsComponent::setTooltipForVoiceSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescription()) {
		slotTooltip += "Click a patch" + GUI::apostrophe + "s name to select it before using the buttons below.\n";
		slotTooltip += "CTRL-C copies the selected patch" + GUI::apostrophe + "s settings into the clipboard.\n";
		slotTooltip += "CTRL-V overwrites the selected patch with the settings in the\n";
		slotTooltip += "clipboard (only slots in Custom User Banks A & B can be overwritten).";
	}
	voiceSlotButtons[slot].setTooltip(slotTooltip);
}

void VoiceSlotsComponent::setTextForVoiceSlotToggleButton(uint8 slot) {
	jassert(slot < voices::numberOfSlotsInBank);
	String slotNumber;
	if (slot < 10) 
		slotNumber = "0" + (String)(slot);
	else 
		slotNumber = (String)(slot);
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	auto voiceName{ voicesBanks->nameOfVoiceInBankSlot(bank, slot) };
	voiceSlotButtons[slot].setName(slotNumber + " - " + voiceName);
	voiceSlotButtons[slot].repaint();
}

void VoiceSlotsComponent::storeCurrentVoiceSettingsInSelectedSlot() {
	if (selectedSlot < voices::numberOfSlotsInBank) {
		auto dataVector{ RawSysExDataVector::initializeVoiceDataMessage(selectedSlot) };
		RawDataTools::addCurrentParameterSettingsToDataVector(exposedParams, unexposedParams, dataVector);
		dataVector.erase(dataVector.begin(), dataVector.begin() + MIDI::numberOfHeaderBytesInDataDumpMessages);
		auto voiceDataHexString{ RawDataTools::convertVoiceOrSplitDataVectorToHexString(dataVector) };
		auto voicesBanks{ unexposedParams->voicesBanks_get() };
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceDataHexString, bank, selectedSlot);
		setTextForVoiceSlotToggleButton(selectedSlot);
		repaint();
		callAfterDelay(100, [this] { VoiceDataMessage::addDataMessageForCurrentVoiceToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}

void VoiceSlotsComponent::loadVoiceFromSelectedSlot() {
	if (selectedSlot < voices::numberOfSlotsInBank) {
		auto voicesBanks{ unexposedParams->voicesBanks_get() };
		auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
		auto voiceDataVector{ RawDataTools::convertVoiceOrSplitHexStringToDataVector(voiceDataHexString) };
		RawDataTools::applyVoiceDataVectorToGUI(selectedSlot, voiceDataVector, exposedParams, unexposedParams);
		callAfterDelay(100, [this] { VoiceDataMessage::addDataMessageForCurrentVoiceToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}

void VoiceSlotsComponent::pullSelectedVoiceFromHardware() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	VoiceDataMessage::addRequestForVoiceDataStoredInHardwareSlotToOutgoingMidiBuffers(selectedSlot, outgoingMidiBuffers);
}

void VoiceSlotsComponent::resized() {
	for (auto i = 0; i != voices::numberOfSlotsInBank; ++i) {
		auto col_x{ (i / 25) * (GUI::voiceSlotRadioButtton_w + GUI::voiceSlotRadioButtonsHorizontalGap) };
		auto row_y{ (i % 25) * GUI::voiceSlotRadioButtton_h };
		voiceSlotButtons[i].setBounds(col_x, row_y, GUI::voiceSlotRadioButtton_w, GUI::voiceSlotRadioButtton_h);
	}
}

void VoiceSlotsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("voice", false, true) };
	setTextForVoiceSlotToggleButton((uint8)slotString.getIntValue());
}

void VoiceSlotsComponent::timerCallback() {
}

VoiceSlotsComponent::~VoiceSlotsComponent() {
	if (bank == VoicesBank::customA || bank == VoicesBank::customB) {
		auto voicesBanks{ unexposedParams->voicesBanks_get() };
		voicesBanks->removeListenerFromNameStringsForCustomBank(this, bank);
	}
}
