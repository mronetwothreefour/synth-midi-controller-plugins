#include "imEx_1_gui_layer_NewFolderDialog.h"

#include "imEx_0_gui_layer_FolderExistsAlert.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_0_tree_TooltipsOptions.h"

GUI_Layer_NewFolderDialog::GUI_Layer_NewFolderDialog(FileBrowserComponent* browserComponent, TooltipsOptions* tooltips) :
	tooltips{ tooltips },
	browserComponent{ browserComponent }
{
	label_FolderNameEditor.setComponentID(ID::label_FolderNameEditor.toString());
	label_FolderNameEditor.applyFontToAllText(GUI::font_BrowserText);
	label_FolderNameEditor.applyColourToAllText(GUI::color_OffWhite);
	label_FolderNameEditor.setText("New Folder");
	label_FolderNameEditor.selectAll();
	label_FolderNameEditor.onReturnKey = [this] { createNewFolder(); };
	label_FolderNameEditor.onEscapeKey = [this] { hideThisLayer(); };
	label_FolderNameEditor.setBounds(609, 161, 184, 20);
	addAndMakeVisible(label_FolderNameEditor);

	const int buttonsRow_y{ 195 };
	btn_Esc.setComponentID(ID::btn_Esc_NewFolder.toString());
	btn_Esc.addShortcut(KeyPress(KeyPress::escapeKey));
	btn_Esc.onClick = [this] { hideThisLayer(); };
	btn_Esc.setBounds(656, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_Esc);

	btn_OK.setComponentID(ID::btn_OK.toString());
	btn_OK.addShortcut(KeyPress(KeyPress::returnKey));
	btn_OK.onClick = [this] { createNewFolder(); };
	btn_OK.setBounds(706, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_OK);

	if (tooltips->shouldShowDescription()) {
		label_FolderNameEditor.setTooltip("Type in the name of the new folder.");
		btn_Esc.setTooltip("Cancel new folder creation.");
		btn_OK.setTooltip("Create new folder.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_NewFolderDialog::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_ImportExport);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_NewFolderDialog_png, BinaryData::bkgrnd_NewFolderDialog_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::bounds_NewFolder.getX(), GUI::bounds_NewFolder.getY());
}

void GUI_Layer_NewFolderDialog::createNewFolder() {
	File currentDirectory{ browserComponent->getRoot() };
	auto directoryPathString{ currentDirectory.getFullPathName() };
	auto newFolderName{ label_FolderNameEditor.getText() };
	auto newFolderPath{ "\\" + File::createLegalFileName(newFolderName) };
	directoryPathString.append(newFolderPath, newFolderPath.length());
	File newDirectory{ directoryPathString };
	if (newDirectory.exists() && !newDirectory.existsAsFile())
		showFolderExistsAlert();
	else {
		newDirectory.createDirectory();
		browserComponent->refresh();
		hideThisLayer();
	}
}

void GUI_Layer_NewFolderDialog::showFolderExistsAlert() {
	folderExistsAlert.reset(new GUI_Layer_FolderExistsAlert(tooltips));
	addAndMakeVisible(folderExistsAlert.get());
	folderExistsAlert->setBounds(getLocalBounds());
	folderExistsAlert->grabKeyboardFocus();
}

void GUI_Layer_NewFolderDialog::hideThisLayer() {
	setVisible(false);
	getParentComponent()->grabKeyboardFocus();
}

GUI_Layer_NewFolderDialog::~GUI_Layer_NewFolderDialog() {
	folderExistsAlert = nullptr;
}
