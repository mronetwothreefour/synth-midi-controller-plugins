#include "patches_TabForFactoryPatchBank.h"

#include "../patches/patches_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForFactoryVoicesBank::TabForFactoryVoicesBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& patchCopyBuffer) :
	bank{ bank },
	patchSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	patchCopyBuffer{ patchCopyBuffer },
	button_ForLoadingSelectedPatch{ patchSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams }
{
	addAndMakeVisible(patchSlots);
	addAndMakeVisible(button_ForLoadingSelectedPatch);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::patchBanksTab_w, GUI::patchBanksTab_h);
}

void TabForFactoryVoicesBank::paint(Graphics& g) {
	g.fillAll(Color::device);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::PatchesFooterForFactoryBanks_png, BinaryData::PatchesFooterForFactoryBanks_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::patchBanksTabFooter_x, GUI::patchBanksTabFooter_y);
}

void TabForFactoryVoicesBank::resized() {
	patchSlots.setBounds(GUI::bounds_PatchSlotsComponent);
	button_ForLoadingSelectedPatch.setBounds(GUI::bounds_PatchBanksFactoryTabLoadButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PatchBanksFactoryTabPushBankButton);
}

ApplicationCommandTarget* TabForFactoryVoicesBank::getNextCommandTarget() {
	return nullptr;
}

void TabForFactoryVoicesBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyPatch };
	commands.addArray(IDs);
}

void TabForFactoryVoicesBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyPatch:
		result.setInfo("Copy Patch", "Copy the patch in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForFactoryVoicesBank::perform(const InvocationInfo& info) {
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	auto selectedSlot{ patchSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyPatch:
		if (selectedSlot < voices::numberOfSlotsInBank) {
			patchCopyBuffer = voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForFactoryVoicesBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForFactoryVoicesBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

TabForFactoryVoicesBank::~TabForFactoryVoicesBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
