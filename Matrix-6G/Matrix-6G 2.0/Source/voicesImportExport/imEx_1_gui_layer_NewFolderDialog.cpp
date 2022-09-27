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
	lbl_FolderNameEditor.setComponentID(ID::lbl_FolderNameEditor.toString());
	lbl_FolderNameEditor.applyFontToAllText(GUI::font_BrowserText);
	lbl_FolderNameEditor.applyColourToAllText(GUI::color_OffWhite);
	lbl_FolderNameEditor.setText("New Folder");
	lbl_FolderNameEditor.selectAll();
	lbl_FolderNameEditor.onReturnKey = [this] { createNewFolder(); };
	lbl_FolderNameEditor.onEscapeKey = [this] { hideThisLayer(); };
	lbl_FolderNameEditor.setBounds(530, 284, 192, 26);
	addAndMakeVisible(lbl_FolderNameEditor);

	const int buttons_w{ 46 };
	const int buttonsRow_y{ 320 };
	btn_Cancel.setComponentID(ID::btn_Cancel_NewFolder.toString());
	btn_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));
	btn_Cancel.onClick = [this] { hideThisLayer(); };
	btn_Cancel.setBounds(577, buttonsRow_y, buttons_w, GUI::buttons_small_h);
	addAndMakeVisible(btn_Cancel);

	btn_Create.setComponentID(ID::btn_Create.toString());
	btn_Create.addShortcut(KeyPress(KeyPress::returnKey));
	btn_Create.onClick = [this] { createNewFolder(); };
	btn_Create.setBounds(629, buttonsRow_y, buttons_w, GUI::buttons_small_h);
	addAndMakeVisible(btn_Create);

	if (tooltips->shouldShowDescription()) {
		lbl_FolderNameEditor.setTooltip("Type in the name of the new folder.");
		btn_Cancel.setTooltip("Cancel new folder creation.");
		btn_Create.setTooltip("Create new folder.");
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
	auto newFolderName{ lbl_FolderNameEditor.getText() };
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
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

GUI_Layer_NewFolderDialog::~GUI_Layer_NewFolderDialog() {
	folderExistsAlert = nullptr;
}
