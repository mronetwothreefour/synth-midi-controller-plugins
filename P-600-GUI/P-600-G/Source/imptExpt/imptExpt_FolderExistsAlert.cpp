#include "imptExpt_FolderExistsAlert.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"

using namespace constants;



FolderExistsAlert::FolderExistsAlert()
{
	addAndMakeVisible(button_OK);
	button_OK.setComponentID(ID::button_OKfolderExists.toString());
	button_OK.addShortcut(KeyPress(KeyPress::escapeKey));
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));
	button_OK.onClick = [this] { hideThisComponent(); };

	setSize(GUI::editor_w, GUI::editor_h);
}

void FolderExistsAlert::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_FolderNameDialogBox);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::FolderExistsAlertBackground_png, BinaryData::FolderExistsAlertBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::folderExistAlert_x, GUI::folderExistAlert_y);
}

void FolderExistsAlert::resized() {
	button_OK.setBounds(GUI::bounds_AlertWindowOKbutton);
}

void FolderExistsAlert::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
