#include "voices_5_comp_TabForCustomVoicesBank.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TabForCustomVoicesBank::TabForCustomVoicesBank(
	VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() },
	voiceCopyBuffer{ voiceCopyBuffer },
	btn_LoadSelected{ &voiceSlots, unexposedParams },
	btn_SaveIntoSelected{ &voiceSlots, unexposedParams },
	btn_PushSelected{ &voiceSlots, unexposedParams },
	btn_PullSelected{ &voiceSlots, unexposedParams },
	btn_ExportSelected{ bank, unexposedParams },
	btn_ImportSelected{ bank, unexposedParams },
	btn_PushBank{ bank, unexposedParams },
	btn_PullBank{ bank, unexposedParams },
	btn_ExportBank{ bank, unexposedParams },
	btn_ImportBank{ bank, unexposedParams }
{
	jassert(bank >= VoicesBank::custom_1);

	voiceSlots.setTopLeftPosition(GUI::voiceSlots_x, GUI::voiceSlots_y);
	addAndMakeVisible(voiceSlots);

	btn_LoadSelected.setTopLeftPosition(183, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_LoadSelected);
	btn_SaveIntoSelected.setTopLeftPosition(btn_LoadSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_SaveIntoSelected);
	btn_PushSelected.setTopLeftPosition(btn_SaveIntoSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_PushSelected);
	btn_PullSelected.setTopLeftPosition(btn_PushSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_PullSelected);
	btn_ExportSelected.setTopLeftPosition(btn_PullSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ExportSelected);
	btn_ImportSelected.setTopLeftPosition(btn_ExportSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ImportSelected);

	btn_PushBank.setTopLeftPosition(638, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_PushBank);
	btn_PullBank.setTopLeftPosition(btn_PushBank.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_PullBank);
	btn_ExportBank.setTopLeftPosition(btn_PullBank.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ExportBank);
	btn_ImportBank.setTopLeftPosition(btn_ExportBank.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ImportBank);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::voicesBankTab_w, GUI::voicesBankTab_h);
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
	btn_ExportSelected.addListener(listener);
	btn_ImportSelected.addListener(listener);
	btn_PushBank.addListener(listener);
	btn_PullBank.addListener(listener);
	btn_ExportBank.addListener(listener);
	btn_ImportBank.addListener(listener);
}

void TabForCustomVoicesBank::removeListenerFromButtons(Button::Listener* listener) {
	btn_ExportSelected.removeListener(listener);
	btn_ImportSelected.removeListener(listener);
	btn_PushBank.removeListener(listener);
	btn_PullBank.removeListener(listener);
	btn_ExportBank.removeListener(listener);
	btn_ImportBank.removeListener(listener);
}

VoiceSlots* TabForCustomVoicesBank::getVoiceSlots() {
	return &voiceSlots;
}

TabForCustomVoicesBank::~TabForCustomVoicesBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
