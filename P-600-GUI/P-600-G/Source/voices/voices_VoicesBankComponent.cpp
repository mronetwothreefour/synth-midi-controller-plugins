#include "voices_VoicesBankComponent.h"

#include "voices_Constants.h"
#include "voices_RestoreFactoryVoicesConfirmDialogBox.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../imptExpt/imptExpt_ExportVoiceDataComponent.h"
#include "../imptExpt/imptExpt_ExportVoicesBankComponent.h"
#include "../imptExpt/imptExpt_ImportVoiceDataComponent.h"
#include "../imptExpt/imptExpt_ImportVoicesBankComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



VoicesBankComponent::VoicesBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slotsComponent{ exposedParams, unexposedParams },
	button_ForLoadingSelectedVoice{ slotsComponent, unexposedParams },
	button_ForSavingVoiceIntoSelectedSlot{ slotsComponent, unexposedParams, label_VoiceNameEditor },
	button_ForPullingSelectedVoiceFromHardware{ slotsComponent, unexposedParams, label_VoiceNameEditor },
	button_ForImportingVoiceFromFile{ unexposedParams },
	button_ForExportingSelectedVoiceToFile{ unexposedParams },
	button_ForEditingSelectedVoiceName{ label_VoiceNameEditor, slotsComponent, unexposedParams },
	button_ForPullingEntireBankFromHardware{ unexposedParams },
	button_ForPushingEntireBankToHardware{ unexposedParams },
	button_ForImportingVoicesBankFromFile{ unexposedParams },
	button_ForExportingVoicesBankToFile{ unexposedParams },
	button_ForRestoringFactoryVoices{ unexposedParams },
	editor_txTime{ "transmitTime", "" }
{
	addAndMakeVisible(slotsComponent);
	addAndMakeVisible(button_ForLoadingSelectedVoice);
	addAndMakeVisible(button_ForSavingVoiceIntoSelectedSlot);
	addAndMakeVisible(button_ForPullingSelectedVoiceFromHardware);
	addAndMakeVisible(button_ForImportingVoiceFromFile);
	addAndMakeVisible(button_ForExportingSelectedVoiceToFile);
	addAndMakeVisible(button_ForEditingSelectedVoiceName);
	addAndMakeVisible(button_ForClosingVoicesBank);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForImportingVoicesBankFromFile);
	addAndMakeVisible(button_ForExportingVoicesBankToFile);
	addAndMakeVisible(button_ForRestoringFactoryVoices);

	button_ForImportingVoiceFromFile.onClick = [this] { showImportVoiceComponent(); };
	button_ForExportingSelectedVoiceToFile.onClick = [this] { showExportSelectedVoiceComponent(); };
	button_ForPullingEntireBankFromHardware.onClick = [this] { showBankTransmissionComponent(BankTransmissionComponent::TransmissionType::pull); };
	button_ForPushingEntireBankToHardware.onClick = [this] { showBankTransmissionComponent(BankTransmissionComponent::TransmissionType::push); };
	button_ForImportingVoicesBankFromFile.onClick = [this] { showImportVoicesBankComponent(); };
	button_ForExportingVoicesBankToFile.onClick = [this] { showExportVoicesBankComponent(); };
	button_ForRestoringFactoryVoices.onClick = [this] { showRestoreFactoryVoicesConfirmDialogBox(); };

	button_ForClosingVoicesBank.setComponentID(ID::button_Exit.toString());
	button_ForClosingVoicesBank.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingVoicesBank.onClick = [this] { hideThisComponent(); };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions())
		button_ForClosingVoicesBank.setTooltip("Click to close the Program Storage Bank window.");

	label_VoiceNameEditor.setInterceptsMouseClicks(false, true);
	label_VoiceNameEditor.setComponentID(ID::label_VoiceNameEditor.toString());
	label_VoiceNameEditor.setFont(FontsMenu::fontFor_VoiceSlotRadioButtons);
	label_VoiceNameEditor.addListener(this);
	addAndMakeVisible(label_VoiceNameEditor);

	auto tooltips{ unexposedParams->tooltipOptions_get() };
	String editor_txTimeTooltip{ "" };
	if (tooltips->shouldShowDescriptions()) {
		editor_txTimeTooltip += "The amount of time, in milliseconds, to allow for the complete transmission\n";
		editor_txTimeTooltip += "of a single program between the plugin and the Prophet-600 hardware.\n";
		editor_txTimeTooltip += "Increase this value if programs are getting " + GUI::openQuote + "lost" + GUI::closeQuote + " during pushes or pulls.\n";
		editor_txTimeTooltip += "Minimum time: 50 ms; Maximum time: 5000 ms.";
	}

	editor_txTime.setTooltip(editor_txTimeTooltip);
	editor_txTime.addListener(this);
	editor_txTime.setEditable(true);
	labelTextChanged(&editor_txTime);
	addAndMakeVisible(editor_txTime);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::editor_w, GUI::editor_h);
}

void VoicesBankComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::PgmBankWindowBackground_png, BinaryData::PgmBankWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::voicesBankWindow_x, GUI::voicesBankWindow_y);
}

void VoicesBankComponent::resized() {
	button_ForLoadingSelectedVoice.setBounds(GUI::bounds_VoicesBankWindowLoadSelectedVoiceButton);
	button_ForSavingVoiceIntoSelectedSlot.setBounds(GUI::bounds_VoicesBankWindowSaveVoiceButton);
	button_ForPullingSelectedVoiceFromHardware.setBounds(GUI::bounds_VoicesBankWindowPullSelectedVoiceButton);
	button_ForImportingVoiceFromFile.setBounds(GUI::bounds_VoicesBankWindowImptVoiceButton);
	button_ForExportingSelectedVoiceToFile.setBounds(GUI::bounds_VoicesBankWindowExptSelectedVoiceButton);
	button_ForEditingSelectedVoiceName.setBounds(GUI::bounds_VoicesBankWindowNameButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_VoicesBankWindowPullBankButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_VoicesBankWindowPushBankButton);
	button_ForImportingVoicesBankFromFile.setBounds(GUI::bounds_VoicesBankWindowImptBankButton);
	button_ForExportingVoicesBankToFile.setBounds(GUI::bounds_VoicesBankWindowExptBankButton);
	button_ForClosingVoicesBank.setBounds(GUI::bounds_VoicesBankWindowExitButton);
	button_ForRestoringFactoryVoices.setBounds(GUI::bounds_VoicesBankWindowFactButton);
	editor_txTime.setBounds(GUI::bounds_VoicesBankWindowTransmitTimeEditor);
	slotsComponent.setBounds(GUI::bounds_VoiceSlotsComponent);
}

void VoicesBankComponent::editorShown(Label* label, TextEditor& editor) {
	if (label->getComponentID() == ID::label_VoiceNameEditor.toString()) {
		editor.setFont(FontsMenu::fontFor_VoiceSlotRadioButtons);
		editor.setInputRestrictions(voices::maxLengthOfVoiceName);
		auto voicesBank{ unexposedParams->voicesBank_get() };
		auto slot{ slotsComponent.selectedSlot };
		editor.setText(voicesBank->nameOfVoiceInSlot(slot));
		editor.selectAll();
	}
	if (label == &editor_txTime) {
		editor.setInputRestrictions(GUI::maxNumberOfDigitsInLCDeditor, "0123456789");
		editor.setFont(FontsMenu::fontFor_LCDdisplayEditor);
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		editor.setText((String)voiceTransmissionOptions->voiceTransmitTime());
		editor.selectAll();
	}
}

void VoicesBankComponent::labelTextChanged(Label* label) {
	if (label->getComponentID() == ID::label_VoiceNameEditor.toString()) {
		auto newName{ label->getText() };
		auto slot{ slotsComponent.selectedSlot };
		auto voicesBank{ unexposedParams->voicesBank_get() };
		voicesBank->setNameOfVoiceInSlot(newName, slot);
	}
	if (label == &editor_txTime) {
		auto voiceTransmissionOptions{ unexposedParams->voiceTransmissionOptions_get() };
		if (label->getText().isNotEmpty())
		{
			auto newValue{ label->getText().getIntValue() };
			if (newValue >= voices::minTransmitTimeValue && newValue <= voices::maxTransmitTimeValue)
				voiceTransmissionOptions->setVoiceTransmitTime(newValue);
		}
		label->setText((String)voiceTransmissionOptions->voiceTransmitTime(), dontSendNotification);
	}
}

void VoicesBankComponent::buttonClicked(Button* button) {
	if (restoreFactoryVoicesConfirmDialogBox != nullptr) {
		if (button->getComponentID() == ID::button_EscRestoreFactory.toString())
			restoreFactoryVoicesConfirmDialogBox->hideThisComponent();
		if (button->getComponentID() == ID::button_OKrestoreFactory.toString()) {
			restoreFactoryVoicesConfirmDialogBox->hideThisComponent();
			auto voicesBank{ unexposedParams->voicesBank_get() };
			voicesBank->restoreFactoryVoicesBank();
		}
	}
}

ApplicationCommandTarget* VoicesBankComponent::getNextCommandTarget() {
	return nullptr;
}

void VoicesBankComponent::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyVoice, pasteVoice };
	commands.addArray(IDs);
}

void VoicesBankComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyVoice:
		result.setInfo("Copy Patch", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pasteVoice:
		result.setInfo("Paste Patch", "Replace the program in the selected storage slot with the program in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool VoicesBankComponent::perform(const InvocationInfo& info) {
	auto voicesBank{ unexposedParams->voicesBank_get() };
	auto selectedSlot{ slotsComponent.selectedSlot };
	switch (info.commandID)
	{
	case copyVoice:
		if (selectedSlot < voices::numberOfSlotsInVoicesBank) {
			auto voiceDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(selectedSlot) };
			voiceCopyBuffer = voiceDataHexString;
			return true;
		}
		else return false;
	case pasteVoice:
		if (selectedSlot < voices::numberOfSlotsInVoicesBank && voiceCopyBuffer != "") {
			voicesBank->storeVoiceDataHexStringInSlot(voiceCopyBuffer, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void VoicesBankComponent::showImportVoiceComponent() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < voices::numberOfSlotsInVoicesBank) {
		importVoiceComponent.reset(new ImportVoiceDataComponent(&slotsComponent, unexposedParams));
		if (importVoiceComponent != nullptr) {
			addAndMakeVisible(importVoiceComponent.get());
			importVoiceComponent->setBounds(getLocalBounds());
			importVoiceComponent->grabKeyboardFocus();
		}
	}
}

void VoicesBankComponent::showExportSelectedVoiceComponent() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < voices::numberOfSlotsInVoicesBank) {
		exportSelectedVoiceComponent.reset(new ExportVoiceDataComponent(&slotsComponent, unexposedParams));
		if (exportSelectedVoiceComponent != nullptr) {
			addAndMakeVisible(exportSelectedVoiceComponent.get());
			exportSelectedVoiceComponent->setBounds(getLocalBounds());
			exportSelectedVoiceComponent->grabKeyboardFocus();
		}
	}
}

void VoicesBankComponent::showBankTransmissionComponent(BankTransmissionComponent::TransmissionType transmitType) {
	bankTransmissionComponent.reset(new BankTransmissionComponent(transmitType, unexposedParams));
	if (bankTransmissionComponent != nullptr) {
		addAndMakeVisible(bankTransmissionComponent.get());
		bankTransmissionComponent->setBounds(getLocalBounds());
		bankTransmissionComponent->grabKeyboardFocus();
	}
}

void VoicesBankComponent::showImportVoicesBankComponent() {
	importVoicesBankComponent.reset(new ImportVoicesBankComponent(&slotsComponent, unexposedParams));
	if (importVoicesBankComponent != nullptr) {
		addAndMakeVisible(importVoicesBankComponent.get());
		importVoicesBankComponent->setBounds(getLocalBounds());
		importVoicesBankComponent->grabKeyboardFocus();
	}
}

void VoicesBankComponent::showExportVoicesBankComponent() {
	exportVoicesBankComponent.reset(new ExportVoicesBankComponent(&slotsComponent, unexposedParams));
	if (exportVoicesBankComponent != nullptr) {
		addAndMakeVisible(exportVoicesBankComponent.get());
		exportVoicesBankComponent->setBounds(getLocalBounds());
		exportVoicesBankComponent->grabKeyboardFocus();
	}
}

void VoicesBankComponent::showRestoreFactoryVoicesConfirmDialogBox() {
	restoreFactoryVoicesConfirmDialogBox.reset(new RestoreFactoryVoicesConfirmDialogBox(unexposedParams));
	if (restoreFactoryVoicesConfirmDialogBox != nullptr) {
		addAndMakeVisible(restoreFactoryVoicesConfirmDialogBox.get());
		restoreFactoryVoicesConfirmDialogBox->addListenerToButtons(this);
		restoreFactoryVoicesConfirmDialogBox->setBounds(getLocalBounds());
		restoreFactoryVoicesConfirmDialogBox->grabKeyboardFocus();
	}
}

void VoicesBankComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

VoicesBankComponent::~VoicesBankComponent() {
	if (restoreFactoryVoicesConfirmDialogBox != nullptr)
		restoreFactoryVoicesConfirmDialogBox->removeListenerFromButtons(this);
	restoreFactoryVoicesConfirmDialogBox = nullptr;
	exportVoicesBankComponent = nullptr;
	importVoicesBankComponent = nullptr;
	bankTransmissionComponent = nullptr;
	exportSelectedVoiceComponent = nullptr;
	importVoiceComponent = nullptr;
	label_VoiceNameEditor.removeListener(this);
}
