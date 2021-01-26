#include "patches_PatchSlotsComponent.h"


#include "patches_Constants.h"
#include "patches_RawPatchData.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_PatchDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



PatchSlotsComponent::PatchSlotsComponent(PatchBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	selectedSlot{ patches::numberOfSlotsInBank }
{
	auto patchBanks{ unexposedParams->patchBanks_get() };
	for (uint8 slot = 0; slot != patches::numberOfSlotsInBank; ++slot) {
		setUpPatchSlotToggleButton(slot);
		addAndMakeVisible(patchSlotButtons[slot]);
	}

	if (bank == PatchBank::customA || bank == PatchBank::customB) {
		patchBanks->addListenerToNameStringsForCustomBank(this, bank);
	}

	setSize(GUI::patchSlotsComponent_w, GUI::patchSlotsComponent_h);
}

void PatchSlotsComponent::setUpPatchSlotToggleButton(uint8 slot) {
	patchSlotButtons[slot].setComponentID(ID::button_PatchSlotRadioButton.toString());
	patchSlotButtons[slot].setRadioGroupId(1);
	patchSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForPatchSlotToggleButton(slot);
	setTextForPatchSlotToggleButton(slot);
}

void PatchSlotsComponent::setTooltipForPatchSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescription()) {
		slotTooltip += "Click a patch's name to select it before using the buttons below.\n";
		slotTooltip += "CTRL-c copies the selected patch's settings into the clipboard.\n";
		slotTooltip += "CTRL-v overwrites the selected patch with the settings in the\n";
		slotTooltip += "clipboard (only slots in Custom User Banks A & B can be overwritten).";
	}
	patchSlotButtons[slot].setTooltip(slotTooltip);
}

void PatchSlotsComponent::setTextForPatchSlotToggleButton(uint8 slot) {
	String slotNumber;
	if (slot < 10) 
		slotNumber = "0" + (String)(slot);
	else 
		slotNumber = (String)(slot);
	auto patchBanks{ unexposedParams->patchBanks_get() };
	auto patchName{ patchBanks->nameOfPatchInBankSlot(bank, slot) };
	patchSlotButtons[slot].setName(slotNumber + " " + patchName);
	patchSlotButtons[slot].repaint();
}

void PatchSlotsComponent::storeCurrentPatchSettingsInSelectedSlot() {
	if (selectedSlot < patches::numberOfSlotsInBank) {
		std::vector<uint8> dataVector;
		RawPatchData::addCurrentParameterSettingsToDataVector(exposedParams, unexposedParams, dataVector);
		auto patchDataHexString{ RawPatchData::convertDataVectorToHexString(dataVector) };
		auto patchBanks{ unexposedParams->patchBanks_get() };
		patchBanks->storePatchDataHexStringInCustomBankSlot(patchDataHexString, bank, selectedSlot);
		setTextForPatchSlotToggleButton(selectedSlot);
		repaint();
	}
}

void PatchSlotsComponent::loadPatchFromSelectedSlot() {
	if (selectedSlot < patches::numberOfSlotsInBank) {
		auto patchBanks{ unexposedParams->patchBanks_get() };
		auto patchDataHexString{ patchBanks->getPatchDataHexStringFromBankSlot(bank, selectedSlot) };
		auto patchDataVector{ RawPatchData::convertHexStringToDataVector(patchDataHexString) };
		RawPatchData::applyRawPatchDataToExposedParameters(patchDataVector.data(), exposedParams);
		RawPatchData::applyRawPatchDataToMatrixModParameters(patchDataVector.data(), unexposedParams);
		callAfterDelay(100, [this] { PatchDataMessage::addDataMessageForCurrentPatchToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}

void PatchSlotsComponent::pullSelectedPatchFromHardware()
{
}

void PatchSlotsComponent::pushSelectedPatchToHardware()
{
}

void PatchSlotsComponent::resized() {
	for (auto i = 0; i != patches::numberOfSlotsInBank; ++i) {
		auto col_x{ (i / 25) * (GUI::patchSlotRadioButtton_w + GUI::patchSlotRadioButtonsHorizontalGap) };
		auto row_y{ (i % 25) * GUI::patchSlotRadioButtton_h };
		patchSlotButtons[i].setBounds(col_x, row_y, GUI::patchSlotRadioButtton_w, GUI::patchSlotRadioButtonsHorizontalGap);
	}
}

void PatchSlotsComponent::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("patch", false, true) };
	setTextForPatchSlotToggleButton((uint8)slotString.getIntValue());
}

void PatchSlotsComponent::timerCallback() {
}

PatchSlotsComponent::~PatchSlotsComponent() {
	if (bank == PatchBank::customA || bank == PatchBank::customB) {
		auto patchBanks{ unexposedParams->patchBanks_get() };
		patchBanks->removeListenerFromNameStringsForCustomBank(this, bank);
	}
}
