#include "pgmData_PgmDataBankComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../imptExpt/imptExpt_ExportPgmDataComponent.h"
#include "../imptExpt/imptExpt_ExportPgmDataBankComponent.h"
#include "../imptExpt/imptExpt_ImportPgmDataComponent.h"
#include "../imptExpt/imptExpt_ImportPgmDataBankComponent.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ProgramDataBankComponent::ProgramDataBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slotsComponent{ exposedParams, unexposedParams },
	button_ForLoadingSelectedProgram{ slotsComponent, unexposedParams },
	button_ForSavingPgmInSelectedSlot{ slotsComponent, unexposedParams, label_PgmNameEditor },
	button_ForPullingSelectedPgmFromHardware{ slotsComponent, unexposedParams, label_PgmNameEditor },
	button_ForImportingPgmFromFile{ unexposedParams },
	button_ForExportingSelectedPgmToFile{ unexposedParams },
	button_ForEditingSelectedPgmName{ label_PgmNameEditor, slotsComponent, unexposedParams },
	button_ForPullingEntireBankFromHardware{ unexposedParams },
	button_ForPushingEntireBankToHardware{ unexposedParams },
	button_ForImportingProgramBankFromFile{ unexposedParams },
	button_ForExportingProgramBankToFile{ unexposedParams }
{
	addAndMakeVisible(slotsComponent);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	addAndMakeVisible(button_ForSavingPgmInSelectedSlot);
	addAndMakeVisible(button_ForPullingSelectedPgmFromHardware);
	addAndMakeVisible(button_ForImportingPgmFromFile);
	addAndMakeVisible(button_ForExportingSelectedPgmToFile);
	addAndMakeVisible(button_ForEditingSelectedPgmName);
	addAndMakeVisible(button_ForClosingPgmDataBank);
	addAndMakeVisible(button_ForPullingEntireBankFromHardware);
	addAndMakeVisible(button_ForPushingEntireBankToHardware);
	addAndMakeVisible(button_ForImportingProgramBankFromFile);
	addAndMakeVisible(button_ForExportingProgramBankToFile);

	button_ForImportingPgmFromFile.onClick = [this] { showImportPgmComponent(); };
	button_ForExportingSelectedPgmToFile.onClick = [this] { showExportSelectedPgmComponent(); };
	button_ForPullingEntireBankFromHardware.onClick = [this] { showProgramBankTransmissionComponent(ProgramBankTransmissionComponent::TransmissionType::pull); };
	button_ForPushingEntireBankToHardware.onClick = [this] { showProgramBankTransmissionComponent(ProgramBankTransmissionComponent::TransmissionType::push); };
	button_ForImportingProgramBankFromFile.onClick = [this] { showImportPgmDataBankComponent(); };
	button_ForExportingProgramBankToFile.onClick = [this] { showExportPgmDataBankComponent(); };

	button_ForClosingPgmDataBank.setComponentID(ID::button_Exit.toString());
	button_ForClosingPgmDataBank.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingPgmDataBank.onClick = [this] { hideThisComponent(); };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription())
		button_ForClosingPgmDataBank.setTooltip("Click to close the Program Storage Bank window.");

	label_PgmNameEditor.setInterceptsMouseClicks(false, true);
	label_PgmNameEditor.setComponentID(ID::label_PgmNameEditor.toString());
	label_PgmNameEditor.setFont(FontsMenu::fontFor_ProgramSlotRadioButtons);
	label_PgmNameEditor.addListener(this);
	addAndMakeVisible(label_PgmNameEditor);

	commandManager.registerAllCommandsForTarget(this);
	addKeyListener(commandManager.getKeyMappings());

	setSize(GUI::editor_w, GUI::editor_h);
}

void ProgramDataBankComponent::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	MemoryInputStream memInputStream{ BinaryData::PgmBankWindowBackground_png, BinaryData::PgmBankWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::pgmDataBankWindow_x, GUI::pgmDataBankWindow_y);
}

void ProgramDataBankComponent::resized() {
	button_ForLoadingSelectedProgram.setBounds(GUI::bounds_PgmBankWindowLoadSelectedPgmButton);
	button_ForSavingPgmInSelectedSlot.setBounds(GUI::bounds_PgmBankWindowSavePgmButton);
	button_ForPullingSelectedPgmFromHardware.setBounds(GUI::bounds_PgmBankWindowPullSelectedPgmButton);
	button_ForImportingPgmFromFile.setBounds(GUI::bounds_PgmBankWindowImptPgmButton);
	button_ForExportingSelectedPgmToFile.setBounds(GUI::bounds_PgmBankWindowExptSelectedPgmButton);
	button_ForEditingSelectedPgmName.setBounds(GUI::bounds_PgmBankWindowNameButton);
	button_ForPullingEntireBankFromHardware.setBounds(GUI::bounds_PgmBankWindowPullBankButton);
	button_ForPushingEntireBankToHardware.setBounds(GUI::bounds_PgmBankWindowPushBankButton);
	button_ForImportingProgramBankFromFile.setBounds(GUI::bounds_PgmBankWindowImptPgmBankButton);
	button_ForExportingProgramBankToFile.setBounds(GUI::bounds_PgmBankWindowExptPgmBankButton);
	button_ForClosingPgmDataBank.setBounds(GUI::bounds_PgmBankWindowExitButton);
	slotsComponent.setBounds(GUI::bounds_PgmDataSlotsComponent);
}

void ProgramDataBankComponent::editorShown(Label* label, TextEditor& editor) {
	if (label->getComponentID() == ID::label_PgmNameEditor.toString()) {
		editor.setFont(FontsMenu::fontFor_ProgramSlotRadioButtons);
		editor.setInputRestrictions(pgmData::maxLengthOfPgmName);
		auto pgmDataBank{ unexposedParams->programDataBank_get() };
		auto slot{ slotsComponent.selectedSlot };
		editor.setText(pgmDataBank->nameOfPgmInSlot(slot));
		editor.selectAll();
	}
}

void ProgramDataBankComponent::labelTextChanged(Label* label) {
	if (label->getComponentID() == ID::label_PgmNameEditor.toString()) {
		auto newName{ label->getText() };
		auto slot{ slotsComponent.selectedSlot };
		auto pgmDataBank{ unexposedParams->programDataBank_get() };
		pgmDataBank->setNameOfPgmInSlot(newName, slot);
	}
}

ApplicationCommandTarget* ProgramDataBankComponent::getNextCommandTarget() {
	return nullptr;
}

void ProgramDataBankComponent::getAllCommands(Array<CommandID>& commands) {
	Array<CommandID> IDs{ copyPgm, pastePgm };
	commands.addArray(IDs);
}

void ProgramDataBankComponent::getCommandInfo(CommandID commandID, ApplicationCommandInfo& result) {
	switch (commandID)
	{
	case copyPgm:
		result.setInfo("Copy Patch", "Copy the program in the selected storage slot", "CopyAndPaste", 0);
		result.addDefaultKeypress('c', ModifierKeys::commandModifier);
		break;
	case pastePgm:
		result.setInfo("Paste Patch", "Replace the program in the selected storage slot with the program in the clipboard", "CopyAndPaste", 0);
		result.addDefaultKeypress('v', ModifierKeys::commandModifier);
		break;
	default:
		break;
	}
}

bool ProgramDataBankComponent::perform(const InvocationInfo& info) {
	auto pgmDataBank{ unexposedParams->programDataBank_get() };
	auto selectedSlot{ slotsComponent.selectedSlot };
	switch (info.commandID)
	{
	case copyPgm:
		if (selectedSlot < pgmData::numberOfSlotsInPgmDataBank) {
			auto pgmDataHexString{ pgmDataBank->getPgmDataHexStringFromSlot(selectedSlot) };
			pgmCopyBuffer = pgmDataHexString;
			return true;
		}
		else return false;
	case pastePgm:
		if (selectedSlot < pgmData::numberOfSlotsInPgmDataBank && pgmCopyBuffer != "") {
			pgmDataBank->storePgmDataHexStringInSlot(pgmCopyBuffer, selectedSlot);
			return true;
		}
		else return false;
	default:
		return false;
	}
}

void ProgramDataBankComponent::showImportPgmComponent() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < pgmData::numberOfSlotsInPgmDataBank) {
		importPgmComponent.reset(new ImportProgramDataComponent(&slotsComponent, unexposedParams));
		if (importPgmComponent != nullptr) {
			addAndMakeVisible(importPgmComponent.get());
			importPgmComponent->setBounds(getLocalBounds());
			importPgmComponent->grabKeyboardFocus();
		}
	}
}

void ProgramDataBankComponent::showExportSelectedPgmComponent() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < pgmData::numberOfSlotsInPgmDataBank) {
		exportSelectedPgmComponent.reset(new ExportProgramDataComponent(&slotsComponent, unexposedParams));
		if (exportSelectedPgmComponent != nullptr) {
			addAndMakeVisible(exportSelectedPgmComponent.get());
			exportSelectedPgmComponent->setBounds(getLocalBounds());
			exportSelectedPgmComponent->grabKeyboardFocus();
		}
	}
}

void ProgramDataBankComponent::showProgramBankTransmissionComponent(ProgramBankTransmissionComponent::TransmissionType transmitType) {
	pgmBankTransmissionComponent.reset(new ProgramBankTransmissionComponent(transmitType, unexposedParams));
	if (pgmBankTransmissionComponent != nullptr) {
		addAndMakeVisible(pgmBankTransmissionComponent.get());
		pgmBankTransmissionComponent->setBounds(getLocalBounds());
		pgmBankTransmissionComponent->grabKeyboardFocus();
	}
}

void ProgramDataBankComponent::showImportPgmDataBankComponent() {
	importPgmDataBankComponent.reset(new ImportProgramDataBankComponent(&slotsComponent, unexposedParams));
	if (importPgmDataBankComponent != nullptr) {
		addAndMakeVisible(importPgmDataBankComponent.get());
		importPgmDataBankComponent->setBounds(getLocalBounds());
		importPgmDataBankComponent->grabKeyboardFocus();
	}
}

void ProgramDataBankComponent::showExportPgmDataBankComponent() {
	exportPgmDataBankComponent.reset(new ExportProgramDataBankComponent(&slotsComponent, unexposedParams));
	if (exportPgmDataBankComponent != nullptr) {
		addAndMakeVisible(exportPgmDataBankComponent.get());
		exportPgmDataBankComponent->setBounds(getLocalBounds());
		exportPgmDataBankComponent->grabKeyboardFocus();
	}
}

void ProgramDataBankComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

ProgramDataBankComponent::~ProgramDataBankComponent() {
	exportPgmDataBankComponent = nullptr;
	importPgmDataBankComponent = nullptr;
	pgmBankTransmissionComponent = nullptr;
	exportSelectedPgmComponent = nullptr;
	importPgmComponent = nullptr;
	label_PgmNameEditor.removeListener(this);
}
