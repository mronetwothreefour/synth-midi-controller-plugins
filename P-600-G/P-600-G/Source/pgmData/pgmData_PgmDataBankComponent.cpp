#include "pgmData_PgmDataBankComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;




ProgramDataBankComponent::ProgramDataBankComponent(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	slotsComponent{ exposedParams, unexposedParams },
	button_ForLoadingSelectedProgram{ slotsComponent, unexposedParams },
	button_ForSavingPgmInSelectedSlot{ slotsComponent, unexposedParams, label_PgmNameEditor },
	button_ForEditingSelectedPgmName{ label_PgmNameEditor, slotsComponent, unexposedParams }
{
	addAndMakeVisible(slotsComponent);
	addAndMakeVisible(button_ForLoadingSelectedProgram);
	addAndMakeVisible(button_ForSavingPgmInSelectedSlot);
	addAndMakeVisible(button_ForEditingSelectedPgmName);

	addAndMakeVisible(button_ForClosingPgmDataBank);
	button_ForClosingPgmDataBank.setComponentID(ID::button_Exit.toString());
	button_ForClosingPgmDataBank.onClick = [this] { hideThisComponent(); };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription())
		button_ForClosingPgmDataBank.setTooltip("Closes the Program Storage Bank window.");

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
	g.drawImageAt(backgroundImage, GUI::pgmDataBankWindowInset_x, GUI::pgmDataBankWindowInset_y);
}

void ProgramDataBankComponent::resized() {
	button_ForLoadingSelectedProgram.setBounds(GUI::bounds_PgmBankWindowLoadSelectedPgmButton);
	button_ForSavingPgmInSelectedSlot.setBounds(GUI::bounds_PgmBankWindowSavePgmButton);
	button_ForEditingSelectedPgmName.setBounds(GUI::bounds_PgmBankWindowNameButton);
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

void ProgramDataBankComponent::buttonClicked(Button* /*button*/) {
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

void ProgramDataBankComponent::hideThisComponent() {
	setVisible(false);
}

ProgramDataBankComponent::~ProgramDataBankComponent() {
	label_PgmNameEditor.removeListener(this);
}
