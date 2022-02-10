#include "patches_TabForCustomPatchBank.h"

#include "../patches/patches_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForCustomPatchBank::TabForCustomPatchBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& patchCopyBuffer) :
	bank{ bank },
	patchSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	patchCopyBuffer{ patchCopyBuffer },
	button_ForLoadingSelectedPatch{ patchSlots, unexposedParams },
	button_ForSavingPatchInSelectedSlot{ patchSlots, unexposedParams },
	button_ForPullingEntireBankFromHardware{ bank, unexposedParams },
	button_ForPullingSelectedPatchFromHardware{ patchSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams }
{
	addAndMakeVisible(patchSlots);
	addAndMakeVisible(button_ForLoadingSelectedPatch);
	addAndMakeVisible(button_ForSavingPatchInSelectedSlot);
	addAndMakeVisible(button_ForPullingSelectedPatchFromHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::patchBanksTab_w, GUI::patchBanksTab_h);
}

void TabForCustomPatchBank::paint(Graphics& g) {
	g.fillAll(Color::device);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::PatchesFooterForCustomBanks_png, BinaryData::PatchesFooterForCustomBanks_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::patchBanksTabFooter_x, GUI::patchBanksTabFooter_y);
}

void TabForCustomPatchBank::resized() {
	patchSlots.setBounds(GUI::bounds_PatchSlotsComponent);
	button_ForLoadingSelectedPatch.setBounds(GUI::bounds_PatchBanksCustomTabLoadButton);
	button_ForSavingPatchInSelectedSlot.setBounds(GUI::bounds_PatchBanksCustomTabSaveButton);
	button_ForPullingSelectedPatchFromHardware.setBounds(GUI::bounds_PatchBanksCustomTabPullSelectedPatchButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PatchBanksCustomTabPushButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_PatchBanksCustomTabPullEntireBankButton);
}

ApplicationCommandTarget* TabForCustomPatchBank::getNextCommandTarget() {
	return nullptr;
}

void TabForCustomPatchBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyPatch, pastePatch };
	commands.addArray(IDs);
}

void TabForCustomPatchBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyPatch:
		result.setInfo("Copy Patch", "Copy the patch in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pastePatch:
		result.setInfo("Paste Patch", "Replace the patch in the selected storage slot with the patch in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForCustomPatchBank::perform(const InvocationInfo& info) {
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	auto selectedSlot{ patchSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyPatch:
		if (selectedSlot < voices::numberOfSlotsInBank) {
			auto PatchDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
			patchCopyBuffer = PatchDataHexString;
			return true;
		}
		else return false;
	case pastePatch:
		if (selectedSlot < voices::numberOfSlotsInBank && patchCopyBuffer != "") {
			voicesBanks->storeVoiceDataHexStringInCustomBankSlot(patchCopyBuffer, bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForCustomPatchBank::addListenerToPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.addListener(listener);
}

void TabForCustomPatchBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForCustomPatchBank::removeListenerFromPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.removeListener(listener);
}

void TabForCustomPatchBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

void TabForCustomPatchBank::timerCallback() {
}

TabForCustomPatchBank::~TabForCustomPatchBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
