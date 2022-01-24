#include "imptExpt_FileOverwriteConfirmDialogBox.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



FileOverwriteConfirmDialogBox::FileOverwriteConfirmDialogBox(UnexposedParameters* unexposedParams)
{
	addAndMakeVisible(button_Esc);
	button_Esc.setComponentID(ID::button_EscFileOverwrite.toString());
	button_Esc.addShortcut(KeyPress(KeyPress::escapeKey));
	addAndMakeVisible(button_OK);
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));
	button_OK.setComponentID(ID::button_OKfileOverwrite.toString());

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		button_Esc.setTooltip("Cancel file overwrite.");
		button_OK.setTooltip("Confirm file overwrite.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void FileOverwriteConfirmDialogBox::addListenerToButtons(Button::Listener* listener) {
	button_Esc.addListener(listener);
	button_OK.addListener(listener);
}

void FileOverwriteConfirmDialogBox::removeListenerFromButtons(Button::Listener* listener) {
	button_Esc.removeListener(listener);
	button_OK.removeListener(listener);
}

void FileOverwriteConfirmDialogBox::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_ImptExptBrowserComponent);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::OverwriteConfirmationBackground_png, BinaryData::OverwriteConfirmationBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::fileOverwriteConfirmBox_x, GUI::fileOverwriteConfirmBox_y);
}

void FileOverwriteConfirmDialogBox::resized() {
	button_Esc.setBounds(GUI::bounds_fileOverwriteConfirmBoxEscButton);
	button_OK.setBounds(GUI::bounds_fileOverwriteConfirmBoxOKbutton);
}

void FileOverwriteConfirmDialogBox::hideThisComponent() {
	setVisible(false);
}
