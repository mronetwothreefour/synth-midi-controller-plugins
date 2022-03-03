#include "imptExpt_FolderNameDialogBox.h"

#include "imptExpt_FolderExistsAlert.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



FolderNameDialogBox::FolderNameDialogBox(FileBrowserComponent* browserComponent, UnexposedParameters* unexposedParams) :
	browserComponent{ browserComponent }
{
	addAndMakeVisible(label_FolderName);
	label_FolderName.setComponentID(ID::label_FolderName.toString());
	label_FolderName.applyFontToAllText(FontsMenu::fontFor_BrowserText);
	label_FolderName.applyColourToAllText(Color::white);
	label_FolderName.setText("New Folder");
	label_FolderName.selectAll();
	label_FolderName.onReturnKey = [this] { createNewFolder(); };
	label_FolderName.onEscapeKey = [this] { hideThisComponent(); };

	addAndMakeVisible(button_Cancel);
	button_Cancel.setComponentID(ID::button_CancelNewFolder.toString());
	button_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));
	button_Cancel.onClick = [this] { hideThisComponent(); };

	addAndMakeVisible(button_Create);
	button_Create.setComponentID(ID::button_Create.toString());
	button_Create.addShortcut(KeyPress(KeyPress::returnKey));
	button_Create.onClick = [this] { createNewFolder(); };


	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		label_FolderName.setTooltip("Type in the name of the new folder.");
		button_Cancel.setTooltip("Cancel new folder creation.");
		button_Create.setTooltip("Create new folder.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void FolderNameDialogBox::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_ImptExptWindow);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::FolderNameDialogBackground_png, BinaryData::FolderNameDialogBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::folderNameDialogBox_x, GUI::folderNameDialogBox_y);
}

void FolderNameDialogBox::resized() {
	label_FolderName.setBounds(GUI::bounds_FolderNameDialogBoxEditor);
	button_Cancel.setBounds(GUI::bounds_FolderNameDialogBoxCancelButton);
	button_Create.setBounds(GUI::bounds_FolderNameDialogBoxCreateButton);
}

void FolderNameDialogBox::createNewFolder() {
	File currentDirectory{ browserComponent->getRoot() };
	auto directoryPathString{ currentDirectory.getFullPathName() };
	auto newFolderName{ label_FolderName.getText() };
	auto newFolderPath{ "\\" + File::createLegalFileName(newFolderName) };
	directoryPathString.append(newFolderPath, newFolderPath.length());
	File newDirectory{ directoryPathString };
	if (newDirectory.exists() && !newDirectory.existsAsFile())
		showFolderExistsAlert();
	else {
		newDirectory.createDirectory();
		browserComponent->refresh();
		hideThisComponent();
	}
}

void FolderNameDialogBox::showFolderExistsAlert() {
	folderExistsAlert.reset(new FolderExistsAlert());
	addAndMakeVisible(folderExistsAlert.get());
	folderExistsAlert->setBounds(getLocalBounds());
	folderExistsAlert->grabKeyboardFocus();
}

void FolderNameDialogBox::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

FolderNameDialogBox::~FolderNameDialogBox() {
	folderExistsAlert = nullptr;
}
