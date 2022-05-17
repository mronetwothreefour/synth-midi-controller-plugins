#include "imptExpt_FileNotValidAlert.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"

using namespace constants;



FileNotValidAlert::FileNotValidAlert()
{
	addAndMakeVisible(button_Close);
	button_Close.setComponentID(ID::button_CloseFileNotValid.toString());
	button_Close.addShortcut(KeyPress(KeyPress::escapeKey));
	button_Close.addShortcut(KeyPress(KeyPress::returnKey));
	button_Close.onClick = [this] { hideThisComponent(); };

	setSize(GUI::editor_w, GUI::editor_h);
}

void FileNotValidAlert::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_ImptExptWindow);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::FileNotValidAlertBackground_png, BinaryData::FileNotValidAlertBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::fileNotValidAlert_x, GUI::fileNotValidAlert_y);
}

void FileNotValidAlert::resized() {
	button_Close.setBounds(GUI::bounds_AlertWindowCloseButton);
}

void FileNotValidAlert::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
