#include "voices_TabForCustomVoicesBank.h"

#include "../voices/voices_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForCustomVoicesBank::TabForCustomVoicesBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	voiceCopyBuffer{ voiceCopyBuffer },
	button_ForLoadingSelectedVoice{ voiceSlots, unexposedParams },
	button_ForSavingVoiceIntoSelectedSlot{ voiceSlots, unexposedParams },
	button_ForPullingEntireBankFromHardware{ bank, unexposedParams },
	button_ForPullingSelectedVoiceFromHardware{ voiceSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams }
{
	addAndMakeVisible(voiceSlots);
	addAndMakeVisible(button_ForLoadingSelectedVoice);
	addAndMakeVisible(button_ForSavingVoiceIntoSelectedSlot);
	addAndMakeVisible(button_ForPullingSelectedVoiceFromHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::voicesBanksTab_w, GUI::voicesBanksTab_h);
}

void TabForCustomVoicesBank::paint(Graphics& g) {
	g.fillAll(Color::device);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::PatchesFooterForCustomBanks_png, BinaryData::PatchesFooterForCustomBanks_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::voicesBanksTabFooter_x, GUI::voicesBanksTabFooter_y);
}

void TabForCustomVoicesBank::resized() {
	voiceSlots.setBounds(GUI::bounds_VoiceSlotsComponent);
	button_ForLoadingSelectedVoice.setBounds(GUI::bounds_VoicesBanksCustomTabLoadButton);
	button_ForSavingVoiceIntoSelectedSlot.setBounds(GUI::bounds_VoicesBanksCustomTabSaveButton);
	button_ForPullingSelectedVoiceFromHardware.setBounds(GUI::bounds_VoicesBanksCustomTabPullSelectedVoiceButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_VoicesBanksCustomTabPushButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_VoicesBanksCustomTabPullEntireBankButton);
}

ApplicationCommandTarget* TabForCustomVoicesBank::getNextCommandTarget() {
	return nullptr;
}

void TabForCustomVoicesBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyVoice, pasteVoice };
	commands.addArray(IDs);
}

void TabForCustomVoicesBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyVoice:
		result.setInfo("Copy Patch", "Copy the patch in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteVoice:
		result.setInfo("Paste Patch", "Replace the patch in the selected storage slot with the patch in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForCustomVoicesBank::perform(const InvocationInfo& info) {
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < voices::numberOfSlotsInBank) {
			auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
			voiceCopyBuffer = voiceDataHexString;
			return true;
		}
		else return false;
	case pasteVoice:
		if (selectedSlot < voices::numberOfSlotsInBank && voiceCopyBuffer != "") {
			voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceCopyBuffer, bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForCustomVoicesBank::addListenerToPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.addListener(listener);
}

void TabForCustomVoicesBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForCustomVoicesBank::removeListenerFromPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.removeListener(listener);
}

void TabForCustomVoicesBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

void TabForCustomVoicesBank::timerCallback() {
}

TabForCustomVoicesBank::~TabForCustomVoicesBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
