#include "widget_ProgramBanksWindow.h"

ProgramBanksTab::ProgramBanksTab(int bank, PluginProcessor& processor) :
	bank{ bank },
	processor{ processor }
{
	setComponentID("ProgramBanksTab");

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	auto programBanksTab_w{ 1015 };
	auto programBanksTab_h{ 325 };
	setSize(programBanksTab_w, programBanksTab_h);
}

ProgramBanksTab::~ProgramBanksTab() {
	removeKeyListener(commandManager.getKeyMappings());
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

