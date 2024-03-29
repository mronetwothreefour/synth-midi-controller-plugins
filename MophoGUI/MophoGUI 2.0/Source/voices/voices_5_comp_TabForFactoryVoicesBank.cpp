#include "voices_5_comp_TabForFactoryVoicesBank.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TabForFactoryVoicesBank::TabForFactoryVoicesBank(
	VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() },
	voiceCopyBuffer{ voiceCopyBuffer },
	btn_LoadSelected{ &voiceSlots, unexposedParams },
	btn_PushSelected{ &voiceSlots, unexposedParams },
	btn_ExportSelected{ bank, unexposedParams },
	btn_PushBank{ bank, unexposedParams },
	btn_ExportBank{ bank, unexposedParams }
{
	jassert(bank <= VoicesBank::factory_3);

	voiceSlots.setTopLeftPosition(GUI::voiceSlots_x, GUI::voiceSlots_y);
	addAndMakeVisible(voiceSlots);

	btn_LoadSelected.setTopLeftPosition(183, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_LoadSelected);
	btn_PushSelected.setTopLeftPosition(btn_LoadSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_PushSelected);
	btn_ExportSelected.setTopLeftPosition(btn_PushSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ExportSelected);

	btn_PushBank.setTopLeftPosition(638, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_PushBank);
	btn_ExportBank.setTopLeftPosition(btn_PushBank.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ExportBank);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::voicesBankTab_w, GUI::voicesBankTab_h);
}

void TabForFactoryVoicesBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_TabForVoicesBank_png, BinaryData::bkgrnd_TabForVoicesBank_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
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
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForFactoryVoicesBank::perform(const InvocationInfo& info) {
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < VCS::numberOfSlotsInVoicesBank) {
			voiceCopyBuffer = voicesBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForFactoryVoicesBank::addListenerToButtons(Button::Listener* listener) {
	btn_PushBank.addListener(listener);
	btn_ExportSelected.addListener(listener);
	btn_ExportBank.addListener(listener);
}

void TabForFactoryVoicesBank::removeListenerFromButtons(Button::Listener* listener) {
	btn_PushBank.removeListener(listener);
	btn_ExportSelected.removeListener(listener);
	btn_ExportBank.removeListener(listener);
}

VoiceSlots* TabForFactoryVoicesBank::getVoiceSlots() {
	return &voiceSlots;
}

TabForFactoryVoicesBank::~TabForFactoryVoicesBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
