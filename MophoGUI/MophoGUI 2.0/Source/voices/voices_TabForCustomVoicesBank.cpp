#include "voices_TabForCustomVoicesBank.h"

#include "voices_Constants.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



TabForCustomProgramBank::TabForCustomProgramBank(VoicesBank bank, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, String& programCopyBuffer) :
	bank{ bank },
	voiceSlots{ bank, exposedParams, unexposedParams },
	unexposedParams{ unexposedParams },
	programCopyBuffer{ programCopyBuffer },
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

void TabForCustomProgramBank::paint(Graphics& g) {
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::ProgramBanksTabBackground_png, BinaryData::ProgramBanksTabBackground_pngSize, false };
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 0, 0);
}

void TabForCustomProgramBank::resized() {
	voiceSlots.setBounds(GUI::bounds_VoiceSlotsWidget);
	button_ForLoadingSelectedVoice.setBounds(GUI::bounds_LoadSelectedVoiceButton);
	button_ForSavingVoiceIntoSelectedSlot.setBounds(GUI::bounds_SaveVoiceIntoSelectedSlotButton);
	button_ForPushingSelectedVoiceToHardware.setBounds(GUI::bounds_PushSelectedCustomVoiceButton);
	button_ForPullingSelectedVoiceFromHardware.setBounds(GUI::bounds_PullSelectedVoiceButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PushEntireBankButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_PullEntireBankButton);
}

ApplicationCommandTarget* TabForCustomProgramBank::getNextCommandTarget() {
	return nullptr;
}

void TabForCustomProgramBank::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyProgram, pasteProgram };
	commands.addArray(IDs);
}

void TabForCustomProgramBank::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyProgram:
		result.setInfo("Copy Program", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteProgram:
		result.setInfo("Paste Program", "Replace the program in the selected storage slot with the program in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool TabForCustomProgramBank::perform(const InvocationInfo& info) {
	auto programBanks{ unexposedParams->voicesBanks_get() };
	auto selectedSlot{ voiceSlots.selectedSlot };
	switch (info.commandID)
	{
	case copyProgram:
		if (selectedSlot < banks::numberOfSlotsInBank) {
			auto ProgramDataHexString{ programBanks->getVoiceDataHexStringFromBankSlot(bank, selectedSlot) };
			programCopyBuffer = ProgramDataHexString;
			return true;
		}
		else return false;
	case pasteProgram:
		if (selectedSlot < banks::numberOfSlotsInBank && programCopyBuffer != "") {
			programBanks->storeVoiceDataHexStringInCustomBankSlot(programCopyBuffer, bank, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void TabForCustomProgramBank::addListenerToPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.addListener(listener);
}

void TabForCustomProgramBank::addListenerToPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.addListener(listener);
}

void TabForCustomProgramBank::removeListenerFromPullEntireBankButton(Button::Listener* listener) {
	button_ForPullingEntireBankFromHardware.removeListener(listener);
}

void TabForCustomProgramBank::removeListenerFromPushEntireBankButton(Button::Listener* listener) {
	button_ForPushingEntireBankToHardware.removeListener(listener);
}

void TabForCustomProgramBank::timerCallback() {
}

TabForCustomProgramBank::~TabForCustomProgramBank() {
	removeKeyListener(commandManager.getKeyMappings());
}
