#include "banks_ProgramSlotsWidget.h"

#include "banks_ConvertRawProgramDataFormat.h"
#include "../midi/midi_ProgramDump.h"
#include "../midi/midi_ProgramEditBufferDump.h"
#include "../params/params_Identifiers.h"
#include "../params/params_RawProgramData.h"
#include "../params/params_UnexposedParameters_Facade.h"



ProgramSlotsWidget::ProgramSlotsWidget(uint8 bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	unexposedParams{ unexposedParams },
	buttton_w{ 125 },
	buttton_h{ 19 },
	buttonHorizontalGap{ 7 },
	selectedSlot{ 128 }
{
	auto programBanks{ unexposedParams->pluginProgramBanks_get() };
	for (uint8 slot = 0; slot != programBanks->programSlotOutOfRange(); ++slot) {
		setUpProgramSlotToggleButton(slot);
		addAndMakeVisible(programSlotButtons[slot]);
	}
	auto programSlotsWidget_w{ 8 * buttton_w + 7 * buttonHorizontalGap };
	auto programSlotsWidget_h{ 16 * buttton_h };
	setSize(programSlotsWidget_w, programSlotsWidget_h);
}

void ProgramSlotsWidget::setUpProgramSlotToggleButton(uint8 slot) {
	programSlotButtons[slot].setComponentID(ID::component_PgmSlotRadioButton.toString());
	programSlotButtons[slot].setRadioGroupId(1);
	programSlotButtons[slot].onClick = [this, slot] {selectedSlot = slot; };
	setTooltipForProgramSlotToggleButton(slot);
	setTextForProgramSlotToggleButton(slot);
}

void ProgramSlotsWidget::setTooltipForProgramSlotToggleButton(uint8 slot) {
	String slotTooltip{ "" };
	slotTooltip += "Click a program's name to select it before using the buttons below.\n";
	slotTooltip += "CTRL-c copies the selected program's settings into the clipboard.\n";
	slotTooltip += "CTRL-v overwrites the selected program with the settings in the clipboard.";
	programSlotButtons[slot].setTooltip(slotTooltip);
}

void ProgramSlotsWidget::setTextForProgramSlotToggleButton(uint8 slot) {
	String slotNumber;
	if (slot < 10) slotNumber = "00" + (String)(slot + 1);
	if (slot > 9 && slot < 100) slotNumber = "0" + (String)(slot + 1);
	if (slot > 99) slotNumber = (String)(slot + 1);
	auto programNames{ unexposedParams->programNameStrings_get() };
	programSlotButtons[slot].setName(slotNumber + " " + programNames->nameOfProgramInBankSlot(bank, slot));
}

void ProgramSlotsWidget::storeCurrentProgramSettingsInSelectedSlot() {
	if (selectedSlot < 128) {
		auto programDataVector{ RawProgramData::extractFromExposedParameters(exposedParams) };
		auto programDataHexString{ ConvertRawProgramDataFormat::dataVectorToHexString(programDataVector) };
		auto programBanks{ unexposedParams->pluginProgramBanks_get() };
		programBanks->storeProgramDataHexStringInBankSlot(programDataHexString, bank, selectedSlot);
		auto programNames{ unexposedParams->programNameStrings_get() };
		auto programName{ programNames->extractProgramNameFromDataVector(programDataVector) };
		programNames->storeNameOfProgramInBankSlot(programName, bank, selectedSlot);
		setTextForProgramSlotToggleButton(selectedSlot);
		repaint();
	}
}

void ProgramSlotsWidget::loadProgramFromSelectedSlot() {
	if (selectedSlot < 128) {
		auto programBanks{ unexposedParams->pluginProgramBanks_get() };
		auto programDataHexString{ programBanks->getProgramDataHexStringFromBankSlot(bank, selectedSlot) };
		auto programDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(programDataHexString) };
		RawProgramData::applyToExposedParameters(programDataVector.data(), exposedParams, unexposedParams);
		callAfterDelay(100, [this] { ProgramEditBufferDump::addDumpToOutgoingMidiBuffers(exposedParams, unexposedParams->outgoingMidiBuffers_get()); });
	}
}

void ProgramSlotsWidget::pullSelectedProgramFromHardware() {
	if (selectedSlot < 128) {
		auto midiOptions{ unexposedParams->midiOptions_get() };
		auto transmitTime{ midiOptions->programTransmitTime() };
		ProgramDump::addRequestForProgramInBankAndSlotToOutgoingMidiBuffers(bank, selectedSlot, unexposedParams);
		callAfterDelay(transmitTime, [this] { setTextForProgramSlotToggleButton(selectedSlot); });
		callAfterDelay(transmitTime + 20, [this] { programSlotButtons[selectedSlot].repaint(); });
	}
}

void ProgramSlotsWidget::pushSelectedProgramToHardware() {
	if (selectedSlot < 128) {
		ProgramDump::addProgramInBankAndSlotToOutgoingMidiBuffers(bank, selectedSlot, unexposedParams);
	}
}

void ProgramSlotsWidget::resized() {
	for (auto i = 0; i != 128; ++i) {
		auto col_x{ (i / 16) * (buttton_w + buttonHorizontalGap) };
		auto row_y{ (i % 16) * (buttton_h) };
		programSlotButtons[i].setBounds(col_x, row_y, buttton_w, buttton_h);
	}
}

ProgramSlotsWidget::~ProgramSlotsWidget() {
}

void ProgramSlotsWidget::timerCallback() {
}

