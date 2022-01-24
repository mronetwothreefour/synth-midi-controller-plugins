#include "imptExpt_ExportPgmDataComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_PgmDataSlotsComponent.h"

using namespace constants;



ExportProgramDataComponent::ExportProgramDataComponent(uint8 slot, UnexposedParameters* unexposedParams) :
	slot{ slot },
	unexposedParams{ unexposedParams }
{
	label_Title.setText("Export P-600-G Program...", dontSendNotification);
	label_Title.setComponentID(ID::label_ImptExptComponentTitle.toString());

	String userDocsPath{ File::getSpecialLocation(File::userDocumentsDirectory).getFullPathName() };
	String p600gDir{ "\\P-600-G\\" };
	auto defaultDirPath{ userDocsPath + p600gDir };
	auto pgmDataBank{ unexposedParams->programDataBank_get() };
	auto pgmName{ pgmDataBank->nameOfPgmInSlot(slot) };
	pgmName = File::createLegalFileName(pgmName);
	File defaultFile{ defaultDirPath + pgmName + pgmDataFileFilter.getDescription() };
	auto browserFlags{ FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles | FileBrowserComponent::warnAboutOverwriting | FileBrowserComponent::doNotClearFileNameOnRootChange };
	browserComponent.reset(new FileBrowserComponent(browserFlags, defaultFile, &pgmDataFileFilter, nullptr));
	if (browserComponent != nullptr) {
		browserComponent->setComponentID(ID::component_ImptExptBrowser.toString());
		browserComponent->setFilenameBoxLabel("");
		addAndMakeVisible(browserComponent.get());
		browserComponent->addListener(this);
	}

	addAndMakeVisible(button_NewFolder);
	button_NewFolder.setComponentID(ID::button_NewFldr.toString());
	button_NewFolder.onClick = [this] { createNewFolder(); };

	addAndMakeVisible(button_Esc);
	button_Esc.setComponentID(ID::button_EscImptExpt.toString());
	button_Esc.addShortcut(KeyPress(KeyPress::escapeKey));
	button_Esc.onClick = [this] { hideThisComponent(); };

	addAndMakeVisible(button_OK);
	button_OK.setComponentID(ID::button_OKimptExpt.toString());
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));
	button_OK.onClick = [this] { okButtonClicked(); };

	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		button_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		button_Esc.setTooltip("Click to cancel the file export\n(or press the ESC key).");
		button_OK.setTooltip("Click to export the selected program" + GUI::apostrophe + "s\ndata to the specified file.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void ExportProgramDataComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_PgmBankWindow);
	g.setOpacity(1.0f);
	MemoryInputStream backgroundInputStream{ BinaryData::ImportExportWindowBackground_png, BinaryData::ImportExportWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(backgroundInputStream) };
	g.drawImageAt(backgroundImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
	MemoryInputStream titleInputStream{ BinaryData::WindowTitleExportProgram_png, BinaryData::WindowTitleExportProgram_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(titleInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ExportProgramDataComponent::resized() {
	browserComponent->setBounds(GUI::bounds_ImptExptBrowserComponent);
	button_NewFolder.setBounds(GUI::bounds_ImptExptNewFldrButton);
	button_Esc.setBounds(GUI::bounds_ImptExptEscButton);
	button_OK.setBounds(GUI::bounds_ImptExptOKbutton);
}

void ExportProgramDataComponent::buttonClicked(Button* button) {
	if (fileOverwriteConfirmDialogBox != nullptr) {
		if (button->getComponentID() == ID::button_EscFileOverwrite.toString())
			fileOverwriteConfirmDialogBox->hideThisComponent();
		if (button->getComponentID() == ID::button_OKfileOverwrite.toString()) {
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeProgramDataIntoFile(selectedFile);
		}
	}
}

void ExportProgramDataComponent::selectionChanged() {
}

void ExportProgramDataComponent::fileClicked(const File& file, const MouseEvent& /*mouseEvent*/) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
	}
}

void ExportProgramDataComponent::fileDoubleClicked(const File& file) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
		okButtonClicked();
	}
}

void ExportProgramDataComponent::browserRootChanged(const File& /*file*/) {
}

void ExportProgramDataComponent::createNewFolder() {
	File currentDirectory{ browserComponent->getRoot() };
	auto directoryPathString{ currentDirectory.getFullPathName() };
	String testNewFolder{ "\\Test New Folder" };
	directoryPathString.append(testNewFolder, testNewFolder.length());
	File newDirectory{ directoryPathString };
	if (!newDirectory.exists()) {
		newDirectory.createDirectory();
		browserComponent->refresh();
	}
}

void ExportProgramDataComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile()) {
		showFileOverwriteConfirmDialogBox();
	}
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeProgramDataIntoFile(fileToWriteTo);
	}
}

void ExportProgramDataComponent::showFileOverwriteConfirmDialogBox() {
	fileOverwriteConfirmDialogBox.reset(new FileOverwriteConfirmDialogBox(unexposedParams));
	fileOverwriteConfirmDialogBox->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteConfirmDialogBox.get());
	fileOverwriteConfirmDialogBox->setBounds(getLocalBounds());
	fileOverwriteConfirmDialogBox->grabKeyboardFocus();
}

File ExportProgramDataComponent::createFileToWriteTo(File& file) {
	auto fullPath{ file.getFullPathName() };
	auto fileType{ pgmDataFileFilter.getDescription() };
	if (!fullPath.endsWith(fileType))
		fullPath.append(fileType, fileType.length());
	File fileToWriteTo{ fullPath };
	fileToWriteTo.create();
	return fileToWriteTo;
}

void ExportProgramDataComponent::writeProgramDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto pgmDataBank{ unexposedParams->programDataBank_get() };
		auto pgmDataHexString{ pgmDataBank->getPgmDataHexStringFromSlot(slot) };
		outStream.writeText(pgmDataHexString, false, false, nullptr);
		hideThisComponent();
	}
}

void ExportProgramDataComponent::hideThisComponent() {
	setVisible(false);
}

ExportProgramDataComponent::~ExportProgramDataComponent() {
	if (fileOverwriteConfirmDialogBox != nullptr) {
		fileOverwriteConfirmDialogBox->removeListenerFromButtons(this);
		fileOverwriteConfirmDialogBox = nullptr;
	}
	if (browserComponent != nullptr) {
		browserComponent->removeListener(this);
		browserComponent = nullptr;
	}
}
