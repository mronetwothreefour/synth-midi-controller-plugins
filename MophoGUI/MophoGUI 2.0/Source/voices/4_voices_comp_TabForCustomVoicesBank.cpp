#include "4_voices_comp_TabForCustomVoicesBank.h"

#include "../constants/constants_Voices.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



TabForCustomVoicesBank::TabForCustomVoicesBank(
	VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	voiceCopyBuffer{ voiceCopyBuffer },
	button_LoadSelected{ &voiceSlots, unexposedParams },
	button_SaveIntoSelected{ &voiceSlots, unexposedParams },
	button_PushSelected{ &voiceSlots, unexposedParams },
	button_PullSelected{ &voiceSlots, unexposedParams },
	button_ExportSelected{ bank, unexposedParams },
	button_ImportSelected{ bank, unexposedParams },
	button_PushBank{ bank, unexposedParams },
	button_PullBank{ bank, unexposedParams },
	button_ExportBank{ bank, unexposedParams },
	button_ImportBank{ bank, unexposedParams }
{
	addAndMakeVisible(voiceSlots);
	addAndMakeVisible(button_LoadSelected);
	addAndMakeVisible(button_SaveIntoSelected);
	addAndMakeVisible(button_PushSelected);
	addAndMakeVisible(button_PullSelected);
	addAndMakeVisible(button_ExportSelected);
	addAndMakeVisible(button_ImportSelected);
	addAndMakeVisible(button_PushBank);
	addAndMakeVisible(button_PullBank);
	addAndMakeVisible(button_ExportBank);
	addAndMakeVisible(button_ImportBank);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());
	setSize(GUI::tabForVoicesBank_w, GUI::tabForVoicesBank_h);
}

void TabForCustomVoicesBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_TabForVoicesBank_png, BinaryData::bkgrnd_TabForVoicesBank_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForCustomVoicesBank::resized() {
	voiceSlots.setBounds(15, 14, voiceSlots.getWidth(), voiceSlots.getHeight());
	auto buttons_w{ GUI::voicesBanksLayerButtons_w };
	auto buttonsRow_y{ 334 };
	button_LoadSelected.setBounds(183, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_SaveIntoSelected.setBounds(238, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_PushSelected.setBounds(293, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_PullSelected.setBounds(348, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_ExportSelected.setBounds(403, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_ImportSelected.setBounds(458, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_PushBank.setBounds(638, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_PullBank.setBounds(693, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_ExportBank.setBounds(748, buttonsRow_y, buttons_w, GUI::redButton_h);
	button_ImportBank.setBounds(803, buttonsRow_y, buttons_w, GUI::redButton_h);
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

bool TabForCustomVoicesBank::perform(const InvocationInfo& info) {
	auto voicesBanks{ unexposedParams->getVoicesBanks() };
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
			auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
			voiceCopyBuffer = voiceDataHexString;
			return true;
		}
		else return false;
	case pasteVoice:
		if (selectedSlot < VCS::numberOfSlotsInVoicesBank && voiceCopyBuffer != "") {
			voicesBanks->storeVoiceDataHexStringInCustomBankSlot(voiceCopyBuffer, bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForCustomVoicesBank::addListenerToButtons(Button::Listener* listener) {
	button_ExportSelected.addListener(listener);
	button_ImportSelected.addListener(listener);
	button_PushBank.addListener(listener);
	button_PullBank.addListener(listener);
	button_ExportBank.addListener(listener);
	button_ImportBank.addListener(listener);
}

void TabForCustomVoicesBank::removeListenerFromButtons(Button::Listener* listener) {
	button_ExportSelected.removeListener(listener);
	button_ImportSelected.removeListener(listener);
	button_PushBank.removeListener(listener);
	button_PullBank.removeListener(listener);
	button_ExportBank.removeListener(listener);
	button_ImportBank.removeListener(listener);
}

VoiceSlots* TabForCustomVoicesBank::getVoiceSlots() {
	return &voiceSlots;
}

TabForCustomVoicesBank::~TabForCustomVoicesBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
