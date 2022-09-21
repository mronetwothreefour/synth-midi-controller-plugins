#include "voices_5_comp_TabForFactoryVoicesBank.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Voices.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

TabForFactoryVoicesBank::TabForFactoryVoicesBank(VoicesBank bank, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() },
	voiceCopyBuffer{ voiceCopyBuffer },
	btn_LoadSelected{ &voiceSlots, unexposedParams },
	btn_ExportSelected{ bank, unexposedParams },
	btn_PushBank{ bank, unexposedParams },
	btn_ExportBank{ bank, unexposedParams }
{
	jassert(bank <= VoicesBank::strings);

	voiceSlots.setTopLeftPosition(GUI::voiceSlots_x, GUI::voiceSlots_y);
	addAndMakeVisible(voiceSlots);

	btn_LoadSelected.setTopLeftPosition(131, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_LoadSelected);
	btn_ExportSelected.setTopLeftPosition(btn_LoadSelected.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ExportSelected);

	btn_PushBank.setTopLeftPosition(261, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_PushBank);
	btn_ExportBank.setTopLeftPosition(btn_PushBank.getX() + GUI::voicesBankTabButtons_x_spacing, GUI::voicesBankTabButtons_y);
	addAndMakeVisible(btn_ExportBank);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::voicesBankTab_w, GUI::voicesBankTab_h);
}

void TabForFactoryVoicesBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_VoicesBankFooter_Factory_png, BinaryData::bkgrnd_VoicesBankFooter_Factory_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, GUI::voicesBankTabFooter_y);
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
		result.setInfo("Copy Program", "Copy the patch in the selected storage slot", "CopyAndPaste", 0);
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
