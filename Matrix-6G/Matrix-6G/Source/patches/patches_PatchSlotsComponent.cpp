#include "patches_PatchSlotsComponent.h"


#include "patches_RawPatchData.h"
#include "patches_RawPatchData.h"
#include "../midi/midi_PatchDataMessage.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



PatchSlotsComponent::PatchSlotsComponent(PatchBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	buttton_w{ 81 },
	buttton_h{ 16 },
	buttonHorizontalGap{ 23 },
	selectedSlot{ 100 }
{
	auto patchBanks{ unexposedParams->patchBanks_get() };
	for (uint8 slot = 0; slot != patchBanks->patchSlotOutOfRange(); ++slot) {
		setUpPatchSlotToggleButton(slot);
		addAndMakeVisible(patchSlotButtons[slot]);
	}

	if (bank == PatchBank::customA || bank == PatchBank::customB) {
		patchBanks->addListenerToNameStringsForCustomBank(this, bank);
	}

	auto patchSlotsWidget_w{ 4 * buttton_w + 3 * buttonHorizontalGap };
	auto patchSlotsWidget_h{ 25 * buttton_h };
	setSize(patchSlotsWidget_w, patchSlotsWidget_h);
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
	if (slot < 9) 
		slotNumber = "0" + (String)(slot + 1);
	else 
		slotNumber = (String)(slot + 1);
	auto patchBanks{ unexposedParams->patchBanks_get() };
	auto patchName{ patchBanks->nameOfPatchInBankSlot(bank, slot) };
	patchSlotButtons[slot].setName(slotNumber + " " + patchName);
	patchSlotButtons[slot].repaint();
}

void PatchSlotsComponent::storeCurrentPatchSettingsInSelectedSlot() {
	if (selectedSlot < 100) {
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
	if (selectedSlot < 128) {
		auto patchBanks{ unexposedParams->patchBanks_get() };
		auto patchDataHexString{ patchBanks->getPatchDataHexStringFromBankSlot(bank, selectedSlot) };
		auto patchDataVector{ RawPatchData::convertHexStringToDataVector(patchDataHexString) };
		RawPatchData::applyRawPatchDataToExposedParameters(patchDataVector.data(), exposedParams);
		RawPatchData::applyRawPatchDataToMatrixModParameters(patchDataVector.data(), unexposedParams);
		callAfterDelay(100, [this] { PatchDataMessage::sendCurrentPatchDataMessageToOutgoingMidiBuffers(exposedParams, unexposedParams); });
	}
}
