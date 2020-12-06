#include "banks_ProgramBankTab.h"

#include "banks_ConvertRawProgramDataFormat.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



ProgramBankTab::ProgramBankTab(uint8 bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	bank{ bank },
	programSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	programCopyBuffer{ programCopyBuffer },
	button_ForLoadingSelectedProgram{ programSlots, unexposedParams },
	button_ForSavingProgramInSelectedSlot{ programSlots, unexposedParams },
	button_ForPushingSelectedProgramToHardware{ programSlots, unexposedParams },
	button_ForPullingSelectedProgramFromHardware{ programSlots, unexposedParams }
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

void ProgramBankTab::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto buttonImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(buttonImage, 0, 0);
}

void ProgramBankTab::resized() {
	programSlots.setBounds(15, 14, programSlots.getWidth(), programSlots.getHeight());
	auto buttons_y{ 334 };
	auto buttons_w{ 50 };
	auto buttons_h{ 22 };
	auto buttons_horizontalSpacing{ 60 };
	auto loadButton_x{ 183 };
	auto saveButton_x{ loadButton_x + buttons_horizontalSpacing };
	auto pushButton_x{ saveButton_x + buttons_horizontalSpacing };
	auto pullButton_x{ pushButton_x + buttons_horizontalSpacing };
	button_ForLoadingSelectedProgram.setBounds(loadButton_x, buttons_y, buttons_w, buttons_h);
	button_ForSavingProgramInSelectedSlot.setBounds(saveButton_x, buttons_y, buttons_w, buttons_h);
	button_ForPushingSelectedProgramToHardware.setBounds(pushButton_x, buttons_y, buttons_w, buttons_h);
	button_ForPullingSelectedProgramFromHardware.setBounds(pullButton_x, buttons_y, buttons_w, buttons_h);
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
	auto programBanks{ unexposedParams->programBanks_get() };
	auto selectedSlot{ programSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyProgram:
		if (selectedSlot < 128) {
			programCopyBuffer = programBanks->getProgramDataHexStringFromBankSlot(bank, selectedSlot);
			return true;
		}
		else return false;
	case pasteProgram:
		if (selectedSlot < 128 && programCopyBuffer != "") {
			programBanks->storeProgramDataHexStringInBankSlot(programCopyBuffer, bank, selectedSlot);
			updateProgramNameAfterDelay(programCopyBuffer, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void ProgramBankTab::updateProgramNameAfterDelay(const String& programDataHexString, uint8 selectedSlot) {
	callAfterDelay(20, [this, programDataHexString, selectedSlot] { storeNewProgramName(programDataHexString, selectedSlot); });
	callAfterDelay(40, [this, selectedSlot] { updateProgramSlotText(selectedSlot); });
}

void ProgramBankTab::storeNewProgramName(const String& programDataHexString, uint8 selectedSlot) {
	auto programDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(programDataHexString) };
	auto programNames{ unexposedParams->programNameStrings_get() };
	auto programName{ programNames->extractProgramNameFromDataVector(programDataVector) };
	programNames->storeNameOfProgramInBankSlot(programName, bank, selectedSlot);
}

void ProgramBankTab::updateProgramSlotText(uint8 selectedSlot) {
	programSlots.setTextForProgramSlotToggleButton(selectedSlot); 
	repaint();
}

void ProgramBankTab::timerCallback() {
}

ProgramBankTab::~ProgramBankTab() {
	removeKeyListener(commandManager.getKeyMappings());
}
