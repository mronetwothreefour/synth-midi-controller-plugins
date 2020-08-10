#include "banks_ProgramBankTab.h"

#include "../banksWindow/banks_PluginProgramBanks_Singleton.h"
#include "../banksWindow/banks_ProgramNameStrings_Singleton.h"
#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Fonts.h"



ProgramBankTab::ProgramBankTab(uint8 bank, AudioProcessorValueTreeState* exposedParams, String& programCopyBuffer) :
	bank{ bank },
	programSlots{ bank, exposedParams },
	programCopyBuffer{ programCopyBuffer },
	button_ForLoadingSelectedProgram{ programSlots },
	button_ForSavingProgramInSelectedSlot{ programSlots },
	button_ForPushingSelectedProgramToHardware{ programSlots },
	button_ForPullingSelectedProgramFromHardware{ programSlots }
{
	addAndMakeVisible(programSlots);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	addAndMakeVisible(button_ForSavingProgramInSelectedSlot);
	addAndMakeVisible(button_ForPushingSelectedProgramToHardware);
	addAndMakeVisible(button_ForPullingSelectedProgramFromHardware);

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
	auto label_y{ 333 };
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
	button_ForPushingSelectedProgramToHardware.setBounds(304, buttons_y, buttons_w, buttons_h);
	button_ForPullingSelectedProgramFromHardware.setBounds(364, buttons_y, buttons_w, buttons_h);
}

void ProgramBankTab::timerCallback() {
}

ApplicationCommandTarget* ProgramBankTab::getNextCommandTarget() {
	return nullptr;
}

void ProgramBankTab::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyProgram, pasteProgram };
	commands.addArray(IDs);
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
	auto& banks{ PluginProgramBanks::get() };
	auto selectedSlot{ programSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyProgram:
		if (selectedSlot < 128) {
			programCopyBuffer = banks.getProgramHexStringFromBankSlot(bank, selectedSlot);
			return true;
		}
		else return false;
	case pasteProgram:
		if (selectedSlot < 128 && programCopyBuffer != "") {
			banks.storeProgramHexStringInBankSlot(programCopyBuffer, bank, selectedSlot);
			updateProgramSlotTextAfterDelay(selectedSlot);
		}
	default:
		return false;
	}
}

void ProgramBankTab::updateProgramSlotTextAfterDelay(uint8 selectedSlot) {
	callAfterDelay(20, [this, selectedSlot] { 	ProgramNameStrings::get().storeProgramNameInBankSlot(bank, selectedSlot); });
	callAfterDelay(40, [this, selectedSlot] { programSlots.setTextForProgramSlotToggleButton(selectedSlot); repaint(); });
}
