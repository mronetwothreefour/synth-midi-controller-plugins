#include "banks_ProgramSlotsWidget.h"



ProgramSlotsWidget::ProgramSlotsWidget(uint8 bank, PluginProcessor& processor) :
	bank{ bank },
	processor{ processor },
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
	auto& pgmBanks{ PluginProgramBanks::get() };
	programSlotButtons[slot].setName(slotNumber + " " + pgmBanks.getNameForProgramStoredInBankSlot(bank, slot));
}

void ProgramSlotsWidget::loadProgramFromSelectedSlot() {
	if (selectedSlot < 128) {
		auto& pgmBanks{ PluginProgramBanks::get() };
		auto programData{ pgmBanks.getProgramDataStoredInBankSlot(bank, selectedSlot) };
		processor.loadProgramFromStoredData(programData);
	}
}

void ProgramSlotsWidget::storeProgramInSelectedSlot() {
	if (selectedSlot < 128) {
		processor.saveProgramToStorageBankSlot(bank, selectedSlot);
		setTextForProgramSlotToggleButton(selectedSlot);
		repaint();
	}
}


