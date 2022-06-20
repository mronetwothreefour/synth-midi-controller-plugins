#include "voices_4_comp_TabForFactoryVoicesBank.h"

#include "../constants/constants_Voices.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"



TabForFactoryVoicesBank::TabForFactoryVoicesBank(
	VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& voiceCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() },
	voiceCopyBuffer{ voiceCopyBuffer },
	button_LoadSelected{ &voiceSlots, unexposedParams },
	button_PushSelected{ &voiceSlots, unexposedParams },
	button_ExportSelected{ bank, unexposedParams },
	button_PushBank{ bank, unexposedParams },
	button_ExportBank{ bank, unexposedParams }
{
	addAndMakeVisible(voiceSlots);
	addAndMakeVisible(button_LoadSelected);
	addAndMakeVisible(button_PushSelected);
	addAndMakeVisible(button_ExportSelected);
	addAndMakeVisible(button_PushBank);
	addAndMakeVisible(button_ExportBank);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::tabForVoicesBank_w, GUI::tabForVoicesBank_h);
}

void TabForFactoryVoicesBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_TabForVoicesBank_png, BinaryData::bkgrnd_TabForVoicesBank_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForFactoryVoicesBank::resized() {
	voiceSlots.setTopLeftPosition(15, 14);
	auto buttonsRow_y{ 334 };
	button_LoadSelected.setTopLeftPosition(183, buttonsRow_y);
	button_PushSelected.setTopLeftPosition(238, buttonsRow_y);
	button_ExportSelected.setTopLeftPosition(293, buttonsRow_y);
	button_PushBank.setTopLeftPosition(638, buttonsRow_y);
	button_ExportBank.setTopLeftPosition(693, buttonsRow_y);
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
	button_PushBank.addListener(listener);
	button_ExportSelected.addListener(listener);
	button_ExportBank.addListener(listener);
}

void TabForFactoryVoicesBank::removeListenerFromButtons(Button::Listener* listener) {
	button_PushBank.removeListener(listener);
	button_ExportSelected.removeListener(listener);
	button_ExportBank.removeListener(listener);
}

VoiceSlots* TabForFactoryVoicesBank::getVoiceSlots() {
	return &voiceSlots;
}

TabForFactoryVoicesBank::~TabForFactoryVoicesBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
