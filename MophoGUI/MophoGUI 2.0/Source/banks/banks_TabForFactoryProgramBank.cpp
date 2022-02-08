#include "banks_TabForFactoryProgramBank.h"

#include "../banks/banks_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForFactoryProgramBank::TabForFactoryProgramBank(ProgramBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	bank{ bank },
	programSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	programCopyBuffer{ programCopyBuffer },
	button_ForLoadingSelectedProgram{ programSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams },
	button_ForPushingSelectedProgramToHardware{ programSlots, unexposedParams }
{
	addAndMakeVisible(programSlots);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	addAndMakeVisible(button_ForPushingSelectedProgramToHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());
	setSize(GUI::programBanksTab_w, GUI::programBanksTab_h);
}

void TabForFactoryProgramBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForFactoryProgramBank::resized() {
	programSlots.setBounds(GUI::bounds_ProgramSlotsWidget);
	button_ForLoadingSelectedProgram.setBounds(GUI::bounds_LoadSelectedProgramButton);
	button_ForPushingSelectedProgramToHardware.setBounds(GUI::bounds_PushSelectedFactoryProgramButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PushEntireBankButton);
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
		if (selectedSlot < banks::numberOfSlotsInBank) {
			programCopyBuffer = programBanks->getProgramDataHexStringFromBankSlot(bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForFactoryProgramBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForFactoryProgramBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

TabForFactoryProgramBank::~TabForFactoryProgramBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
