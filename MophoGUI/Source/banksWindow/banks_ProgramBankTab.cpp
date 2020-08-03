#include "banks_ProgramBankTab.h"



ProgramBankTab::ProgramBankTab(uint8 bank, AudioProcessorValueTreeState* exposedParams) :
	bank{ bank },
	programSlots{ bank, exposedParams },
	button_ForLoadingSelectedProgram{ programSlots },
	button_ForSavingProgramInSelectedSlot{ programSlots }
{
	addAndMakeVisible(programSlots);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	button_ForLoadingSelectedProgram.setAlwaysOnTop(true);
	addAndMakeVisible(button_ForSavingProgramInSelectedSlot);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	auto programBanksTab_w{ 1065 };
	auto programBanksTab_h{ 370 };
	setSize(programBanksTab_w, programBanksTab_h);
}

ProgramBankTab::~ProgramBankTab() {
	removeKeyListener(commandManager.getKeyMappings());
}

void ProgramBankTab::paint(Graphics& g) {
	g.setColour(Color::black);
	Font font{ FontsDB::family_Global, FontsDB::style_ForControlLabels, FontsDB::size_ForPgmBanksWindowLabels };
	g.setFont(font);
	auto label_y{ 334 };
	auto label_h{ 21 };
	Rectangle<int> selectedPgmLabelArea{ 15, label_y, 164, label_h };
	g.drawText("SELECTED PROGRAM :", selectedPgmLabelArea, Justification::right);
	Rectangle<int> entireBankLabelArea{ 445, label_y, 110, label_h };
	g.drawText("ENTIRE BANK :", entireBankLabelArea, Justification::right);
	Rectangle<int> txTimeLabelArea{ 692, label_y, 130, label_h };
	g.drawText("TRANSMIT TIME :", txTimeLabelArea, Justification::right);
	Rectangle<int> allBanksLabelArea{ 899, label_y, 96, label_h };
	g.drawText("ALL BANKS :", allBanksLabelArea, Justification::right);
}

void ProgramBankTab::resized() {
	programSlots.setBounds(15, 14, programSlots.getWidth(), programSlots.getHeight());
	auto buttons_y{ 334 };
	auto buttons_w{ 50 };
	auto buttons_h{ 21 };
	button_ForLoadingSelectedProgram.setBounds(184, buttons_y, buttons_w, buttons_h);
	button_ForSavingProgramInSelectedSlot.setBounds(244, buttons_y, buttons_w, buttons_h);
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
