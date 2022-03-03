#include "voices_TabForCustomVoicesBank.h"

#include "voices_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForCustomVoiceBank::TabForCustomVoiceBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	voiceCopyBuffer{ voiceCopyBuffer },
	button_ForLoadingSelectedVoice{ voiceSlots, unexposedParams },
	button_ForSavingVoiceIntoSelectedSlot{ voiceSlots, unexposedParams },
	button_ForPullingEntireBankFromHardware{ bank, unexposedParams },
	button_ForPullingSelectedVoiceFromHardware{ voiceSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams },
	button_ForPushingSelectedVoiceToHardware{ voiceSlots, unexposedParams }
{
	addAndMakeVisible(voiceSlots);
	addAndMakeVisible(button_ForLoadingSelectedVoice);
	addAndMakeVisible(button_ForSavingVoiceIntoSelectedSlot);
	addAndMakeVisible(button_ForPushingSelectedVoiceToHardware);
	addAndMakeVisible(button_ForPullingSelectedVoiceFromHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());
	setSize(GUI::tabForVoicesBank_w, GUI::tabForVoicesBank_h);
}

void TabForCustomVoiceBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForCustomVoiceBank::resized() {
	voiceSlots.setBounds(GUI::bounds_VoiceSlotsWidget);
	button_ForLoadingSelectedVoice.setBounds(GUI::bounds_LoadSelectedVoiceButton);
	button_ForSavingVoiceIntoSelectedSlot.setBounds(GUI::bounds_SaveVoiceIntoSelectedSlotButton);
	button_ForPushingSelectedVoiceToHardware.setBounds(GUI::bounds_PushSelectedCustomVoiceButton);
	button_ForPullingSelectedVoiceFromHardware.setBounds(GUI::bounds_PullSelectedVoiceButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PushEntireBankButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_PullEntireBankButton);
}

ApplicationCommandTarget* TabForCustomVoiceBank::getNextCommandTarget() {
	return nullptr;
}

void TabForCustomVoiceBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyVoice, pasteVoice };
	commands.addArray(IDs);
}

void TabForCustomVoiceBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyVoice:
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteVoice:
		result.setInfo("Paste Program", "Replace the program in the selected storage slot with the program in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForCustomVoiceBank::perform(const InvocationInfo& info) {
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < voices::numberOfSlotsInVoicesBank) {
			auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
			voiceCopyBuffer = voiceDataHexString;
			return true;
		}
		else return false;
	case pasteVoice:
		if (selectedSlot < voices::numberOfSlotsInVoicesBank && voiceCopyBuffer != "") {
			voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceCopyBuffer, bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForCustomVoiceBank::addListenerToPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.addListener(listener);
}

void TabForCustomVoiceBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForCustomVoiceBank::removeListenerFromPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.removeListener(listener);
}

void TabForCustomVoiceBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

void TabForCustomVoiceBank::timerCallback() {
}

TabForCustomVoiceBank::~TabForCustomVoiceBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
