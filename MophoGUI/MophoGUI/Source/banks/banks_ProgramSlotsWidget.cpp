#include "banks_ProgramSlotsWidget.h"

#include "banks_RawProgramData.h"
#include "../midi/midi_ProgramDump.h"
#include "../midi/midi_ProgramEditBufferDump.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



ProgramSlotsWidget::ProgramSlotsWidget(ProgramBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	buttton_w{ 125 },
	buttton_h{ 19 },
	buttonHorizontalGap{ 7 },
	selectedSlot{ 128 }
{
	auto programBanks{ unexposedParams->programBanks_get() };
	for (uint8 slot = 0; slot != programBanks->programSlotOutOfRange(); ++slot) {
		setUpProgramSlotToggleButton(slot);
		addAndMakeVisible(programSlotButtons[slot]);
	}

	if (bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3) {
		programBanks->addListenerToNameStringsForCustomBank(this, bank);
	}

	auto programSlotsWidget_w{ 8 * buttton_w + 7 * buttonHorizontalGap };
	auto programSlotsWidget_h{ 16 * buttton_h };
	setSize(programSlotsWidget_w, programSlotsWidget_h);
}

void ProgramSlotsWidget::setUpProgramSlotToggleButton(uint8 slot) {
	programSlotButtons[slot].setComponentID(ID::component_PgmSlotRadioButton.toString());
	programSlotButtons[slot].setRadioGroupId(1);
	programSlotButtons[slot].onClick = [this, slot] { selectedSlot = slot; };
	setTooltipForProgramSlotToggleButton(slot);
	setTextForProgramSlotToggleButton(slot);
}

void ProgramSlotsWidget::setTooltipForProgramSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	auto tooltips{ unexposedParams->tooltipOptions_get() };
	if (tooltips->shouldShowDescription()) {
		slotTooltip += "Click a program's name to select it before using the buttons below.\n";
		slotTooltip += "CTRL-c copies the selected program's settings into the clipboard.\n";
		slotTooltip += "CTRL-v overwrites the selected program with the settings in the\n";
		slotTooltip += "clipboard (only slots in the Custom banks can be overwritten).";
	}
	programSlotButtons[slot].setTooltip(slotTooltip);
}

void ProgramSlotsWidget::setTextForProgramSlotToggleButton(uint8 slot) {
	String slotNumber;
	if (slot < 9) slotNumber = "00" + (String)(slot + 1);
	if (slot > 8 && slot < 99) slotNumber = "0" + (String)(slot + 1);
	if (slot > 98) slotNumber = (String)(slot + 1);
	auto programBanks{ unexposedParams->programBanks_get() };
	auto programName{ programBanks->nameOfProgramInBankSlot(bank, slot) };
	programSlotButtons[slot].setName(slotNumber + " " + programName);
	programSlotButtons[slot].repaint();
}

void ProgramSlotsWidget::storeCurrentProgramSettingsInSelectedSlot() {
	if (selectedSlot < 128) {
		auto programDataVector{ RawProgramData::extractFromExposedParameters(exposedParams) };
		auto programDataHexString{ RawProgramData::convertDataVectorToHexString(programDataVector) };
		auto programBanks{ unexposedParams->programBanks_get() };
		programBanks->storeProgramDataHexStringInCustomBankSlot(programDataHexString, bank, selectedSlot);
		setTextForProgramSlotToggleButton(selectedSlot);
		repaint();
	}
}

void ProgramSlotsWidget::loadProgramFromSelectedSlot() {
	if (selectedSlot < 128) {
		auto programBanks{ unexposedParams->programBanks_get() };
		auto programDataHexString{ programBanks->getProgramDataHexStringFromBankSlot(bank, selectedSlot) };
		auto programDataVector{ RawProgramData::convertHexStringToDataVector(programDataHexString) };
		RawProgramData::applyToExposedParameters(programDataVector.data(), exposedParams, unexposedParams);
		callAfterDelay(100, [this] { ProgramEditBufferDump::addDumpToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get()); });
	}
}

void ProgramSlotsWidget::pullSelectedProgramFromHardware() {
	if (selectedSlot < 128) {
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		auto midiOptions{ unexposedParams->midiOptions_get() };
		auto transmitTime{ midiOptions->programTransmitTime() };
		ProgramDump::addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(bank, selectedSlot, outgoingBuffers);
		callAfterDelay(transmitTime, [this] { setTextForProgramSlotToggleButton(selectedSlot); });
		callAfterDelay(transmitTime + 20, [this] { programSlotButtons[selectedSlot].repaint(); });
	}
}

void ProgramSlotsWidget::pushSelectedProgramToHardware() {
	if (selectedSlot < 128) {
		auto dumpDataVector{ ProgramDump::createProgramDumpForBankAndSlot(bank, selectedSlot, unexposedParams) };
		auto outgoingBuffers{ unexposedParams->outgoingMidiBuffers_get() };
		outgoingBuffers->addDataMessage(dumpDataVector);
	}
}

void ProgramSlotsWidget::resized() {
	for (auto i = 0; i != 128; ++i) {
		auto col_x{ (i / 16) * (buttton_w + buttonHorizontalGap) };
		auto row_y{ (i % 16) * (buttton_h) };
		programSlotButtons[i].setBounds(col_x, row_y, buttton_w, buttton_h);
	}
}

void ProgramSlotsWidget::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("pgm", false, true) };
	setTextForProgramSlotToggleButton((uint8)slotString.getIntValue());
}

void ProgramSlotsWidget::timerCallback() {
}

ProgramSlotsWidget::~ProgramSlotsWidget() {
	if (bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3) {
		auto programBanks{ unexposedParams->programBanks_get() };
		programBanks->removeListenerFromNameStringsForCustomBank(this, bank);
	}
}

