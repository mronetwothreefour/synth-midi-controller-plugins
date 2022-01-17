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
	button_ForLoadingSelectedProgram{ slotsComponent, unexposedParams }
{
	addAndMakeVisible(slotsComponent);
	addAndMakeVisible(button_ForLoadingSelectedProgram);

	addAndMakeVisible(button_ForNamingSelectedPgm);
	button_ForNamingSelectedPgm.setComponentID(ID::button_Name.toString());
	button_ForNamingSelectedPgm.onClick = [this] { positionAndShowNameEditorForSelectedPgm(); };

	addAndMakeVisible(button_ForClosingPgmDataBank);
	button_ForClosingPgmDataBank.setComponentID(ID::button_Exit.toString());
	button_ForClosingPgmDataBank.onClick = [this] { hideThisComponent(); };

	label_PgmNameEditor.setInterceptsMouseClicks(false, true);
	label_PgmNameEditor.setComponentID(ID::label_PgmNameEditor.toString());
	label_PgmNameEditor.addListener(this);
	addAndMakeVisible(label_PgmNameEditor);

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription())
		setComponentTooltips();

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
	button_ForLoadingSelectedProgram.setBounds(GUI::bounds_PgmDataBankWindowLoadSelectedPgmButton);
	button_ForNamingSelectedPgm.setBounds(GUI::bounds_PgmDataBankWindowNameButton);
	button_ForClosingPgmDataBank.setBounds(GUI::bounds_PgmDataBankWindowExitButton);
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

void ProgramDataBankComponent::setComponentTooltips() {
	String nameButtonTooltip;
	nameButtonTooltip += "Click to change the name of the selected program.\n";
	nameButtonTooltip += "Note: The hardware has no provisions for storing\n";
	nameButtonTooltip += "program names. The name is deleted when a pro-\n";
	nameButtonTooltip += "gram is pulled from the hardware into a plugin slot.";
	button_ForNamingSelectedPgm.setTooltip(nameButtonTooltip);

	button_ForClosingPgmDataBank.setTooltip("Closes the Program Storage Bank window.");
}

void ProgramDataBankComponent::hideThisComponent() {
	setVisible(false);
}

void ProgramDataBankComponent::positionAndShowNameEditorForSelectedPgm() {
	auto slot{ slotsComponent.selectedSlot };
	if (slot < pgmData::numberOfSlotsInPgmDataBank) {
		auto editor_x{ GUI::pgmNameEditorLabel_horizInset + (slot / 10 * GUI::pgmDataSlotRadioButton_w)};
		auto editor_y{ GUI::pgmDataSlotsComponent_y + (slot % 10 * GUI::pgmDataSlotRadioButton_h)};
		label_PgmNameEditor.setBounds(editor_x, editor_y, GUI::pgmNameEditorLabel_w, GUI::pgmDataSlotRadioButton_h);
	}
	label_PgmNameEditor.showEditor();
}

ProgramDataBankComponent::~ProgramDataBankComponent() {
	label_PgmNameEditor.removeListener(this);
}
