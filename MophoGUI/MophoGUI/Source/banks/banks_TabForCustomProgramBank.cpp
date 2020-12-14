#include "banks_TabForCustomProgramBank.h"

#include "banks_ConvertRawProgramDataFormat.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



TabForCustomProgramBank::TabForCustomProgramBank(ProgramBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	bank{ bank },
	programSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	programCopyBuffer{ programCopyBuffer },
	button_ForLoadingSelectedProgram{ programSlots, unexposedParams },
	button_ForSavingProgramInSelectedSlot{ programSlots, unexposedParams },
	button_ForPullingEntireBankFromHardware{ bank, unexposedParams },
	button_ForPullingSelectedProgramFromHardware{ programSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams },
	button_ForPushingSelectedProgramToHardware{ programSlots, unexposedParams }
{
	addAndMakeVisible(programSlots);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	addAndMakeVisible(button_ForSavingProgramInSelectedSlot);
	addAndMakeVisible(button_ForPushingSelectedProgramToHardware);
	addAndMakeVisible(button_ForPullingSelectedProgramFromHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());
	auto programBanksTab_w{ 1065 };
	auto programBanksTab_h{ 370 };
	setSize(programBanksTab_w, programBanksTab_h);
}

void TabForCustomProgramBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForCustomProgramBank::resized() {
	programSlots.setBounds(15, 14, programSlots.getWidth(), programSlots.getHeight());
	auto buttons_y{ 334 };
	auto buttons_w{ 50 };
	auto buttons_h{ 22 };
	auto buttons_horizontalSpacing{ 55 };
	auto loadButton_x{ 183 };
	auto saveButton_x{ loadButton_x + buttons_horizontalSpacing };
	auto pushButton_x{ saveButton_x + buttons_horizontalSpacing };
	auto pullButton_x{ pushButton_x + buttons_horizontalSpacing };
	auto pushBankButton_x{ 638 };
	auto pullBankButton_x{ pushBankButton_x + buttons_horizontalSpacing };
	button_ForLoadingSelectedProgram.setBounds(loadButton_x, buttons_y, buttons_w, buttons_h);
	button_ForSavingProgramInSelectedSlot.setBounds(saveButton_x, buttons_y, buttons_w, buttons_h);
	button_ForPushingSelectedProgramToHardware.setBounds(pushButton_x, buttons_y, buttons_w, buttons_h);
	button_ForPullingSelectedProgramFromHardware.setBounds(pullButton_x, buttons_y, buttons_w, buttons_h);
	button_ForPushingEntireBankToHardware.setBounds(pushBankButton_x, buttons_y, buttons_w, buttons_h);
	button_ForPullingEntireBankFromHardware.setBounds(pullBankButton_x, buttons_y, buttons_w, buttons_h);
}

ApplicationCommandTarget* TabForCustomProgramBank::getNextCommandTarget() {
	return nullptr;
}

void TabForCustomProgramBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyProgram, pasteProgram };
	commands.addArray(IDs);
}

void TabForCustomProgramBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
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

bool TabForCustomProgramBank::perform(const InvocationInfo& info) {
	auto programBanks{ unexposedParams->programBanks_get() };
	auto selectedSlot{ programSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyProgram:
		if (selectedSlot < 128) {
			auto ProgramDataHexString{ programBanks->getProgramDataHexStringFromBankSlot(bank, selectedSlot) };
			programCopyBuffer = ProgramDataHexString;
			return true;
		}
		else return false;
	case pasteProgram:
		if (selectedSlot < 128 && programCopyBuffer != "") {
			programBanks->storeProgramDataHexStringInCustomBankSlot(programCopyBuffer, bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForCustomProgramBank::addListenerToPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.addListener(listener);
}

void TabForCustomProgramBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForCustomProgramBank::removeListenerFromPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.removeListener(listener);
}

void TabForCustomProgramBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

void TabForCustomProgramBank::timerCallback() {
}

TabForCustomProgramBank::~TabForCustomProgramBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
