#include "banks_TabForFactoryProgramBank.h"

#include "banks_ConvertRawProgramDataFormat.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"



TabForFactoryProgramBank::TabForFactoryProgramBank(uint8 bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	bank{ bank },
	programSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	programCopyBuffer{ programCopyBuffer },
	button_ForLoadingSelectedProgram{ programSlots, unexposedParams },
	button_ForPushingSelectedProgramToHardware{ programSlots, unexposedParams }
{
	addAndMakeVisible(programSlots);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	addAndMakeVisible(button_ForPushingSelectedProgramToHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());
	auto programBanksTab_w{ 1065 };
	auto programBanksTab_h{ 370 };
	setSize(programBanksTab_w, programBanksTab_h);
}

void TabForFactoryProgramBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForFactoryProgramBank::resized() {
	programSlots.setBounds(15, 14, programSlots.getWidth(), programSlots.getHeight());
	auto buttons_y{ 334 };
	auto buttons_w{ 50 };
	auto buttons_h{ 22 };
	auto buttons_horizontalSpacing{ 55 };
	auto loadButton_x{ 183 };
	auto pushButton_x{ loadButton_x + buttons_horizontalSpacing };
	button_ForLoadingSelectedProgram.setBounds(loadButton_x, buttons_y, buttons_w, buttons_h);
	button_ForPushingSelectedProgramToHardware.setBounds(pushButton_x, buttons_y, buttons_w, buttons_h);
}

ApplicationCommandTarget* TabForFactoryProgramBank::getNextCommandTarget() {
	return nullptr;
}

void TabForFactoryProgramBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyProgram };
	commands.addArray(IDs);
}

void TabForFactoryProgramBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyProgram:
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForFactoryProgramBank::perform(const InvocationInfo& info) {
	auto programBanks{ unexposedParams->programBanks_get() };
	auto selectedSlot{ programSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyProgram:
		if (selectedSlot < 128) {
			programCopyBuffer = programBanks->getProgramDataHexStringFromFactoryBankSlot(bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

TabForFactoryProgramBank::~TabForFactoryProgramBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
