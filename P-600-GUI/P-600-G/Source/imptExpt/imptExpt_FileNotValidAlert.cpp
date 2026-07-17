#include "imptExpt_FileNotValidAlert.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"

using namespace constants;



FileNotValidAlert::FileNotValidAlert()
{
	addAndMakeVisible(button_OK);
	button_OK.setComponentID(ID::button_OKfileNotValid.toString());
	button_OK.addShortcut(KeyPress(KeyPress::escapeKey));
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));
	button_OK.onClick = [this] { hideThisComponent(); };

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
	button_OK.setBounds(GUI::bounds_AlertWindowOKbutton);
}

void FileNotValidAlert::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}
