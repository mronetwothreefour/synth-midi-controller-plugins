#include "imEx_1_gui_layer_NewFolderDialog.h"

#include "imEx_0_gui_layer_FolderExistsAlert.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

GUI_Layer_NewFolderDialog::GUI_Layer_NewFolderDialog(FileBrowserComponent* browserComponent, UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	browserComponent{ browserComponent }
{
	label_FolderNameEditor.setComponentID(ID::label_FolderNameEditor.toString());
	label_FolderNameEditor.applyFontToAllText(GUI::font_BrowserText);
	label_FolderNameEditor.applyColourToAllText(GUI::color_White);
	label_FolderNameEditor.setText("New Folder");
	label_FolderNameEditor.selectAll();
	label_FolderNameEditor.onReturnKey = [this] { createNewFolder(); };
	label_FolderNameEditor.onEscapeKey = [this] { hideThisLayer(); };
	label_FolderNameEditor.setBounds(541, 293, 191, 26);
	addAndMakeVisible(label_FolderNameEditor);

	const int buttons_w{ GUI::btn_Cancel_w };
	const int buttonsRow_y{ 326 };
	btn_Cancel.setComponentID(ID::btn_Cancel_NewFolder.toString());
	btn_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));
	btn_Cancel.onClick = [this] { hideThisLayer(); };
	btn_Cancel.setBounds(582, buttonsRow_y, buttons_w, GUI::redButton_h);
	addAndMakeVisible(btn_Cancel);

	btn_Create.setComponentID(ID::btn_Create.toString());
	btn_Create.addShortcut(KeyPress(KeyPress::returnKey));
	btn_Create.onClick = [this] { createNewFolder(); };
	btn_Create.setBounds(639, buttonsRow_y, buttons_w, GUI::redButton_h);
	addAndMakeVisible(btn_Create);


	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescription()) {
		label_FolderNameEditor.setTooltip("Type in the name of the new folder.");
		btn_Cancel.setTooltip("Cancel new folder creation.");
		btn_Create.setTooltip("Create new folder.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_NewFolderDialog::paint(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(getParentComponent()->getBounds());
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_NewFolderDialog_png, BinaryData::bkgrnd_NewFolderDialog_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 526, 259);
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
	folderExistsAlert.reset(new GUI_Layer_FolderExistsAlert(unexposedParams));
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
