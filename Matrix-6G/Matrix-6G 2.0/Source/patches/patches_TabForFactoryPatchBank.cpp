#include "patches_TabForFactoryPatchBank.h"

#include "../patches/patches_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForFactoryVoicesBank::TabForFactoryVoicesBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	voiceCopyBuffer{ voiceCopyBuffer },
	button_ForLoadingSelectedVoice{ voiceSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams }
{
	addAndMakeVisible(voiceSlots);
	addAndMakeVisible(button_ForLoadingSelectedVoice);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::voicesBanksTab_w, GUI::voicesBanksTab_h);
}

void TabForFactoryVoicesBank::paint(Graphics& g) {
	g.fillAll(Color::device);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::PatchesFooterForFactoryBanks_png, BinaryData::PatchesFooterForFactoryBanks_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::voicesBanksTabFooter_x, GUI::voicesBanksTabFooter_y);
}

void TabForFactoryVoicesBank::resized() {
	voiceSlots.setBounds(GUI::bounds_VoiceSlotsComponent);
	button_ForLoadingSelectedVoice.setBounds(GUI::bounds_VoicesBanksFactoryTabLoadButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_VoicesBanksFactoryTabPushBankButton);
}

ApplicationCommandTarget* TabForFactoryVoicesBank::getNextCommandTarget() {
	return nullptr;
}

void TabForFactoryVoicesBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyVoice };
	commands.addArray(IDs);
}

void TabForFactoryVoicesBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyVoice:
		result.setInfo("Copy Patch", "Copy the patch in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForFactoryVoicesBank::perform(const InvocationInfo& info) {
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < voices::numberOfSlotsInBank) {
			voiceCopyBuffer = voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot);
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
