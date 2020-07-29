#include "widget_ProgramBanksWindow.h"



ProgramSlotsWidget::ProgramSlotsWidget(uint8 bank) :
	bank{ bank },
	buttton_w{ 120 },
	buttton_h{ 17 },
	buttonGap{ 5 },
	selectedSlot{ -1 }
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

	auto programSlotsWidget_w{ 8 * buttton_w + 7 * buttonGap };
	auto programSlotsWidget_h{ 16 * buttton_h };
	setSize(programSlotsWidget_w, programSlotsWidget_h);
}

ProgramSlotsWidget::~ProgramSlotsWidget() {
}

void ProgramSlotsWidget::resized() {
	for (auto i = 0; i != 128; ++i) {
		auto col_x{ (i / 16) * (buttton_w + buttonGap) };
		auto row_y{ (i % 16) * buttton_h };
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


//================================================================================


ProgramBanksTab::ProgramBanksTab(uint8 bank, PluginProcessor& processor) :
	bank{ bank },
	programSlots{ bank },
	processor{ processor }
{
	setComponentID("ProgramBanksTab");

	addAndMakeVisible(programSlots);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	auto programBanksTab_w{ 1015 };
	auto programBanksTab_h{ 325 };
	setSize(programBanksTab_w, programBanksTab_h);
}

ProgramBanksTab::~ProgramBanksTab() {
	removeKeyListener(commandManager.getKeyMappings());
}

void ProgramBanksTab::paint(Graphics& g) {
}

void ProgramBanksTab::resized() {
	programSlots.setBounds(10, 10, programSlots.getWidth(), programSlots.getHeight());
}

void ProgramBanksTab::timerCallback() {
}

ApplicationCommandTarget* ProgramBanksTab::getNextCommandTarget() {
	return nullptr;
}

void ProgramBanksTab::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> ids{ copyProgram, pasteProgram };
	commands.addArray(ids);
}

void ProgramBanksTab::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyProgram:
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteProgram:
		result.setInfo("Paste Program", "Replace the program in the selected storage slot with the program in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool ProgramBanksTab::perform(const InvocationInfo& info) {
	return false;
}

void ProgramBanksTab::labelTextChanged(Label* label) {
}

void ProgramBanksTab::editorShown(Label* label, TextEditor& editor) {
}


//================================================================================


ProgramBanksTabbedComponent::ProgramBanksTabbedComponent(PluginProcessor& processor) :
	TabbedComponent(TabbedButtonBar::TabsAtLeft),
	bank1{ 0, processor },
	bank2{ 1, processor },
	bank3{ 2, processor }
{
	setTabBarDepth(30);
	setOutline(0);
	addTab("1", Color::device, &bank1, true, 1);
	addTab("2", Color::device, &bank2, true, 2);
	addTab("3", Color::device, &bank3, true, 3);

	auto tab_w{ 1015 };
	auto tab_h{ 325 };
	setSize(tab_w + getTabBarDepth(), tab_h);
}


//================================================================================


ProgramBanksWindow::ProgramBanksWindow(PluginProcessor& processor) :
	DialogWindow{ "Program Banks", Color::device, true, false },
	contentComponent{ processor }
{
	contentComponent.setVisible(true);
}

ProgramBanksWindow::~ProgramBanksWindow() {
}

