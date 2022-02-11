#include "voices_TabForFactoryVoicesBank.h"

#include "voices_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForFactoryProgramBank::TabForFactoryProgramBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	programCopyBuffer{ programCopyBuffer },
	button_ForLoadingSelectedVoice{ voiceSlots, unexposedParams },
	button_ForPushingEntireBankToHardware{ bank, unexposedParams },
	button_ForPushingSelectedVoiceToHardware{ voiceSlots, unexposedParams }
{
	addAndMakeVisible(voiceSlots);
	addAndMakeVisible(button_ForLoadingSelectedVoice);
	addAndMakeVisible(button_ForPushingSelectedVoiceToHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());
	setSize(GUI::tabForVoicesBank_w, GUI::tabForVoicesBank_h);
}

void TabForFactoryProgramBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForFactoryProgramBank::resized() {
	voiceSlots.setBounds(GUI::bounds_VoiceSlotsWidget);
	button_ForLoadingSelectedVoice.setBounds(GUI::bounds_LoadSelectedVoiceButton);
	button_ForPushingSelectedVoiceToHardware.setBounds(GUI::bounds_PushSelectedFactoryVoiceButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PushEntireBankButton);
}

ApplicationCommandTarget* TabForFactoryProgramBank::getNextCommandTarget() {
	return nullptr;
}

void TabForFactoryProgramBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyProgram };
	commands.addArray(IDs);
}

void TabForFactoryProgramBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyProgram:
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForFactoryProgramBank::perform(const InvocationInfo& info) {
	auto programBanks{ unexposedParams->voicesBanks_get() };
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyProgram:
		if (selectedSlot < banks::numberOfSlotsInBank) {
			programCopyBuffer = programBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForFactoryProgramBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForFactoryProgramBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

TabForFactoryProgramBank::~TabForFactoryProgramBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
