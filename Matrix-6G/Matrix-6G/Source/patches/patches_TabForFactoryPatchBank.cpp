#include "patches_TabForFactoryPatchBank.h"

#include "../patches/patches_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForFactoryProgramBank::TabForFactoryProgramBank(PatchBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	bank{ bank },
	patchSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	patchCopyBuffer{ programCopyBuffer },
	button_ForLoadingSelectedProgram{ patchSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams }
{
	addAndMakeVisible(patchSlots);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());
	setSize(GUI::patchBanksTab_w, GUI::patchBanksTab_h);
}

void TabForFactoryProgramBank::paint(Graphics& g) {
	g.fillAll(Color::device);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::PatchesFooterForFactoryBanks_png, BinaryData::PatchesFooterForFactoryBanks_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::patchBanksTabFooter_x, GUI::patchBanksTabFooter_y);
}

void TabForFactoryProgramBank::resized() {
	patchSlots.setBounds(GUI::bounds_PatchSlotsComponent);
	button_ForLoadingSelectedProgram.setBounds(GUI::bounds_PatchBanksFactoryTabLoadButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PatchBanksFactoryTabPushBankButton);
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
		result.setInfo("Copy Program", "Copy the patch in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForFactoryProgramBank::perform(const InvocationInfo& info) {
	auto patchBanks{ unexposedParams->patchBanks_get() };
	auto selectedSlot{ patchSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyProgram:
		if (selectedSlot < patches::numberOfSlotsInBank) {
			patchCopyBuffer = patchBanks->getPatchDataHexStringFromBankSlot(bank, selectedSlot);
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
