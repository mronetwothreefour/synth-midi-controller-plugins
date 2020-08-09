#include "banks_ProgramSlotsWidget.h"

#include "banks_PluginProgramBanks_Singleton.h"
#include "banks_ProgramNameStrings_Singleton.h"
#include "../helpers/helper_Identifiers.h"
#include "../midiTools/midi_ProgramDump.h"
#include "../midiTools/midi_ProgramEditBufferDump.h"



void ProgramSlotsWidget::timerCallback() {
}

ProgramSlotsWidget::ProgramSlotsWidget(uint8 bank, AudioProcessorValueTreeState* exposedParams) :
	bank{ bank },
	exposedParams{ exposedParams },
	buttton_w{ 125 },
	buttton_h{ 19 },
	buttonHorizontalGap{ 7 },
	selectedSlot{ 128 }
{
	auto& pgmBanks{ PluginProgramBanks::get() };
	for (uint8 slot = 0; slot != pgmBanks.programSlotOutOfRange(); ++slot) {
		setComponentID("ProgramSlotsWidget");
		addAndMakeVisible(programSlotButtons[slot]);
		setTextForProgramSlotToggleButton(slot);
		programSlotButtons[slot].setComponentID(ID::component_PgmSlotRadioButton.toString());
		programSlotButtons[slot].setRadioGroupId(1);
		programSlotButtons[slot].onClick = [this, slot] {selectedSlot = slot; };
	}

	auto programSlotsWidget_w{ 8 * buttton_w + 7 * buttonHorizontalGap };
	auto programSlotsWidget_h{ 16 * buttton_h };
	setSize(programSlotsWidget_w, programSlotsWidget_h);
}

ProgramSlotsWidget::~ProgramSlotsWidget() {
}

void ProgramSlotsWidget::resized() {
	for (auto i = 0; i != 128; ++i) {
		auto col_x{ (i / 16) * (buttton_w + buttonHorizontalGap) };
		auto row_y{ (i % 16) * (buttton_h) };
		programSlotButtons[i].setBounds(col_x, row_y, buttton_w, buttton_h);
	}
}

void ProgramSlotsWidget::setTextForProgramSlotToggleButton(uint8 slot) {
	String slotNumber;
	if (slot < 10) slotNumber = "00" + (String)(slot + 1);
	if (slot > 9 && slot < 100) slotNumber = "0" + (String)(slot + 1);
	if (slot > 99) slotNumber = (String)(slot + 1);
	auto& pgmNames{ ProgramNameStrings::get() };
	programSlotButtons[slot].setName(slotNumber + " " + pgmNames.getNameForProgramInBankSlot(bank, slot));
}

void ProgramSlotsWidget::loadProgramFromSelectedSlot() {
	if (selectedSlot < 128) {
		auto& pgmBanks{ PluginProgramBanks::get() };
		auto programDataVector{ pgmBanks.getProgramDataStoredInBankSlot(bank, selectedSlot) };
		RawProgramData::applyToExposedParameters(programDataVector.data(), exposedParams);
		callAfterDelay(100, [this] { ProgramEditBufferDump::send(exposedParams); });
	}
}

void ProgramSlotsWidget::storeCurrentProgramSettingsInSelectedSlot() {
	if (selectedSlot < 128) {
		auto programData{ RawProgramData::extractFromExposedParameters(exposedParams) };
		auto& programBanks{ PluginProgramBanks::get() };
		programBanks.storeProgramDataInBankSlot(programData.data(), bank, selectedSlot);
		auto& programNames{ ProgramNameStrings::get() };
		programNames.storeProgramNameInBankSlot(bank, selectedSlot);
		setTextForProgramSlotToggleButton(selectedSlot);
		repaint();
	}
}

void ProgramSlotsWidget::pushSelectedProgramToHardware() {
	if (selectedSlot < 128) {
		ProgramDump::sendToBankAndSlot(bank, selectedSlot);
	}
}


