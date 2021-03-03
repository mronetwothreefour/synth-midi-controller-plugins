#include "splits_SplitSlotsComponent.h"

#include "splits_Constants.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_Constants.h"
#include "../midi/midi_SplitDataMessage.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



SplitSlotsComponent::SplitSlotsComponent(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	selectedSlot{ splits::numberOfSlotsInBank }
{
	auto splitsBank{ unexposedParams->splitsBank_get() };
	for (uint8 slot = 0; slot != splits::numberOfSlotsInBank; ++slot) {
		setUpSplitSlotToggleButton(slot);
		addAndMakeVisible(splitSlotButtons[slot]);
	}
	splitsBank->addListenerToSplitsNameStrings(this);
	setSize(GUI::splitSlotsComponent_w, GUI::splitSlotsComponent_h);
}

void SplitSlotsComponent::setUpSplitSlotToggleButton(uint8 slot) {
	splitSlotButtons[slot].setComponentID(ID::button_SplitSlotRadioButton.toString());
	splitSlotButtons[slot].setRadioGroupId(2);
	splitSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForSplitSlotToggleButton(slot);
	setTextForSplitSlotToggleButton(slot);
}

void SplitSlotsComponent::setTooltipForSplitSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescription()) {
		slotTooltip += "Click a split's name to select it before using the buttons below.\n";
		slotTooltip += "CTRL-C copies the selected split's settings into the clipboard.\n";
		slotTooltip += "CTRL-V overwrites the selected split with the settings in the clipboard.";
	}
	splitSlotButtons[slot].setTooltip(slotTooltip);
}

void SplitSlotsComponent::setTextForSplitSlotToggleButton(uint8 slot) {
	String slotNumber;
	if (slot < 10)
		slotNumber = "0" + (String)(slot);
	else
		slotNumber = (String)(slot);
	auto splitsBank{ unexposedParams->splitsBank_get() };
	auto splitName{ splitsBank->nameOfSplitInSlot(slot) };
	splitSlotButtons[slot].setName(slotNumber + " - " + splitName);
	splitSlotButtons[slot].repaint();
}

void SplitSlotsComponent::storeCurrentSplitSettingsInSelectedSlot() {
	if (selectedSlot < splits::numberOfSlotsInBank) {
		auto dataVector{ RawSysExDataVector::initializeSplitDataMessage(selectedSlot) };
		RawDataTools::addCurrentSplitSettingsToDataVector(unexposedParams, dataVector);
		dataVector.erase(dataVector.begin(), dataVector.begin() + MIDI::numberOfHeaderBytesInPatchAndSplitDataMessages);
		auto splitDataHexString{ RawDataTools::convertPatchOrSplitDataVectorToHexString(dataVector) };
		auto splitsBank{ unexposedParams->splitsBank_get() };
		splitsBank->storeSplitDataHexStringInSlot(splitDataHexString, selectedSlot);
		setTextForSplitSlotToggleButton(selectedSlot);
		repaint();
		callAfterDelay(100, [this] { SplitDataMessage::addDataMessageForSplitStoredInSlotToOutgoingMidiBuffers(selectedSlot, unexposedParams); });
	}
}

void SplitSlotsComponent::loadSplitFromSelectedSlot() {
	if (selectedSlot < splits::numberOfSlotsInBank) {
		auto splitsBank{ unexposedParams->splitsBank_get() };
		auto splitDataHexString{ splitsBank->getSplitDataHexStringFromSlot(selectedSlot) };
		auto splitDataVector{ RawDataTools::convertPatchOrSplitHexStringToDataVector(splitDataHexString) };
		RawDataTools::applySplitDataVectorToGUI(splitDataVector, unexposedParams);
		callAfterDelay(100, [this] { SplitDataMessage::addDataMessageForSplitStoredInSlotToOutgoingMidiBuffers(selectedSlot, unexposedParams); });
	}
}

void SplitSlotsComponent::pullSelectedSplitFromHardware() {
	auto outgoingMidiBuffers{ unexposedParams->outgoingMidiBuffers_get() };
	SplitDataMessage::addRequestForSplitDataStoredInHardwareSlotToOutgoingMidiBuffers(selectedSlot, outgoingMidiBuffers);
}

void SplitSlotsComponent::resized() {
	for (auto i = 0; i != splits::numberOfSlotsInBank; ++i) {
		auto col_x{ (i / 10) * (GUI::splitSlotRadioButtton_w + GUI::splitSlotRadioButtonsHorizontalGap) };
		auto row_y{ (i % 10) * GUI::splitSlotRadioButtton_h };
		splitSlotButtons[i].setBounds(col_x, row_y, GUI::splitSlotRadioButtton_w, GUI::splitSlotRadioButtton_h);
	}
}

void SplitSlotsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("split", false, true) };
	setTextForSplitSlotToggleButton((uint8)slotString.getIntValue());
}

void SplitSlotsComponent::timerCallback() {
}

SplitSlotsComponent::~SplitSlotsComponent() {
	auto splitsBank{ unexposedParams->splitsBank_get() };
	splitsBank->removeListenerFromSplitsNameStrings(this);
}

