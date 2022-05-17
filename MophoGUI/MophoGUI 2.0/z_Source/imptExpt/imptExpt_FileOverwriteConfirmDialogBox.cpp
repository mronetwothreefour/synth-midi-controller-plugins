#include "imptExpt_FileOverwriteConfirmDialogBox.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



FileOverwriteConfirmDialogBox::FileOverwriteConfirmDialogBox(UnexposedParameters* unexposedParams)
{
	addAndMakeVisible(button_Cancel);
	button_Cancel.setComponentID(ID::button_CancelFileOverwrite.toString());
	button_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));

	addAndMakeVisible(button_Write);
	button_Write.setComponentID(ID::button_FileOverwrite.toString());
	button_Write.addShortcut(KeyPress(KeyPress::returnKey));

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_Cancel.setTooltip("Cancel file overwrite.");
		button_Write.setTooltip("Confirm file overwrite.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void FileOverwriteConfirmDialogBox::addListenerToButtons(Button::Listener* listener) {
	button_Cancel.addListener(listener);
	button_Write.addListener(listener);
}

void FileOverwriteConfirmDialogBox::removeListenerFromButtons(Button::Listener* listener) {
	button_Cancel.removeListener(listener);
	button_Write.removeListener(listener);
}

void FileOverwriteConfirmDialogBox::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_FolderNameDialogBox);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::OverwriteConfirmationBackground_png, BinaryData::OverwriteConfirmationBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::fileOverwriteConfirmBox_x, GUI::fileOverwriteConfirmBox_y);
}

void FileOverwriteConfirmDialogBox::resized() {
	button_Cancel.setBounds(GUI::bounds_FileOverwriteConfirmBoxCancelButton);
	button_Write.setBounds(GUI::bounds_FileOverwriteConfirmBoxWriteButton);
}

void FileOverwriteConfirmDialogBox::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
