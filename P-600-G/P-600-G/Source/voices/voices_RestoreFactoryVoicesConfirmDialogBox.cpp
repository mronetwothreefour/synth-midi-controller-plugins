#include "voices_RestoreFactoryVoicesConfirmDialogBox.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RestoreFactoryVoicesConfirmDialogBox::RestoreFactoryVoicesConfirmDialogBox(UnexposedParameters* unexposedParams)
{
	addAndMakeVisible(button_Esc);
	button_Esc.setComponentID(ID::button_EscRestoreFactory.toString());
	button_Esc.addShortcut(KeyPress(KeyPress::escapeKey));

	addAndMakeVisible(button_OK);
	button_OK.setComponentID(ID::button_OKrestoreFactory.toString());
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_Esc.setTooltip("Cancel restore.");
		button_OK.setTooltip("Confirm restore.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void RestoreFactoryVoicesConfirmDialogBox::addListenerToButtons(Button::Listener* listener) {
	button_Esc.addListener(listener);
	button_OK.addListener(listener);
}

void RestoreFactoryVoicesConfirmDialogBox::removeListenerFromButtons(Button::Listener* listener) {
	button_Esc.removeListener(listener);
	button_OK.removeListener(listener);
}

void RestoreFactoryVoicesConfirmDialogBox::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_FolderNameDialogBox);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::RestoreFactoryProgramsConfirmationBackground_png, BinaryData::RestoreFactoryProgramsConfirmationBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::restoreFactoryConfirmBox_x, GUI::restoreFactoryConfirmBox_y);
}

void RestoreFactoryVoicesConfirmDialogBox::resized() {
	button_Esc.setBounds(GUI::bounds_RestoreFactoryConfirmBoxEscButton);
	button_OK.setBounds(GUI::bounds_RestoreFactoryConfirmBoxOKbutton);
}

void RestoreFactoryVoicesConfirmDialogBox::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
