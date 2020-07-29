#include "banks_ProgramBankTab.h"



ProgramBankTab::ProgramBankTab(uint8 bank, PluginProcessor& processor) :
	bank{ bank },
	programSlots{ bank },
	processor{ processor }
{
	addAndMakeVisible(programSlots);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	auto programBanksTab_w{ 1015 };
	auto programBanksTab_h{ 325 };
	setSize(programBanksTab_w, programBanksTab_h);
}

ProgramBankTab::~ProgramBankTab() {
	removeKeyListener(commandManager.getKeyMappings());
}

void ProgramBankTab::paint(Graphics& g) {
}

void ProgramBankTab::resized() {
	programSlots.setBounds(10, 10, programSlots.getWidth(), programSlots.getHeight());
}

void ProgramBankTab::timerCallback() {
}

ApplicationCommandTarget* ProgramBankTab::getNextCommandTarget() {
	return nullptr;
}

void ProgramBankTab::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> ids{ copyProgram, pasteProgram };
	commands.addArray(ids);
}

void ProgramBankTab::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
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

bool ProgramBankTab::perform(const InvocationInfo& info) {
	return false;
}

void ProgramBankTab::labelTextChanged(Label* label) {
}

void ProgramBankTab::editorShown(Label* label, TextEditor& editor) {
}
