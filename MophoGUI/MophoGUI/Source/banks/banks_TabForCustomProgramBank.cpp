#include "banks_TabForCustomProgramBank.h"

#include "../banks/banks_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



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
	setSize(GUI::programBanksTab_w, GUI::programBanksTab_h);
}

void TabForCustomProgramBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForCustomProgramBank::resized() {
	programSlots.setBounds(GUI::bounds_ProgramSlotsWidget);
	button_ForLoadingSelectedProgram.setBounds(GUI::bounds_LoadSelectedProgramButton);
	button_ForSavingProgramInSelectedSlot.setBounds(GUI::bounds_SaveProgramInSelectedSlotButton);
	button_ForPushingSelectedProgramToHardware.setBounds(GUI::bounds_PushSelectedCustomProgramButton);
	button_ForPullingSelectedProgramFromHardware.setBounds(GUI::bounds_PullSelectedProgramButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PushEntireBankButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_PullEntireBankButton);
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
		if (selectedSlot < banks::numberOfSlotsInBank) {
			auto ProgramDataHexString{ programBanks->getProgramDataHexStringFromBankSlot(bank, selectedSlot) };
			programCopyBuffer = ProgramDataHexString;
			return true;
		}
		else return false;
	case pasteProgram:
		if (selectedSlot < banks::numberOfSlotsInBank && programCopyBuffer != "") {
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
