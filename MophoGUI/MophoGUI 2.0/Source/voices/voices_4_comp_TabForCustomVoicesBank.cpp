#include "voices_4_comp_TabForCustomVoicesBank.h"

#include "../constants/constants_Voices.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



TabForCustomVoicesBank::TabForCustomVoicesBank(
	VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() },
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
	jassert(bank >= VoicesBank::custom_1);
	auto buttonsRow_y{ 334 };
	addAndMakeVisible(voiceSlots);
	voiceSlots.setTopLeftPosition(15, 14);
	button_LoadSelected.setTopLeftPosition(183, buttonsRow_y);
	addAndMakeVisible(button_LoadSelected);
	button_SaveIntoSelected.setTopLeftPosition(238, buttonsRow_y);
	addAndMakeVisible(button_SaveIntoSelected);
	button_PushSelected.setTopLeftPosition(293, buttonsRow_y);
	addAndMakeVisible(button_PushSelected);
	button_PullSelected.setTopLeftPosition(348, buttonsRow_y);
	addAndMakeVisible(button_PullSelected);
	button_ExportSelected.setTopLeftPosition(403, buttonsRow_y);
	addAndMakeVisible(button_ExportSelected);
	button_ImportSelected.setTopLeftPosition(458, buttonsRow_y);
	addAndMakeVisible(button_ImportSelected);
	button_PushBank.setTopLeftPosition(638, buttonsRow_y);
	addAndMakeVisible(button_PushBank);
	button_PullBank.setTopLeftPosition(693, buttonsRow_y);
	addAndMakeVisible(button_PullBank);
	button_ExportBank.setTopLeftPosition(748, buttonsRow_y);
	addAndMakeVisible(button_ExportBank);
	button_ImportBank.setTopLeftPosition(803, buttonsRow_y);
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
