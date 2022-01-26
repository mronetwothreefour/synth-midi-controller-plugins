#include "imptExpt_ImportPgmDataComponent.h"

#include "imptExpt_FileNotValidAlert.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_Constants.h"

using namespace constants;



ImportProgramDataComponent::ImportProgramDataComponent(uint8 slot, UnexposedParameters* unexposedParams) :
	slot{ slot },
	unexposedParams{ unexposedParams }
{
	String userDocsPath{ File::getSpecialLocation(File::userDocumentsDirectory).getFullPathName() };
	String p600gDir{ "\\P-600-G\\" };
	File defaultDirectory{ userDocsPath + p600gDir };
	auto browserFlags{ FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles };
	browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory, &pgmDataFileFilter, nullptr));
	if (browserComponent != nullptr) {
		browserComponent->setComponentID(ID::component_ImptExptBrowser.toString());
		browserComponent->setFilenameBoxLabel("");
		addAndMakeVisible(browserComponent.get());
		browserComponent->addListener(this);
	}

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
		button_Esc.setTooltip("Click to cancel the data import.");
		button_OK.setTooltip("Click to import program data\nfrom the selected file.");
	}

	setSize(GUI::editor_w, GUI::editor_h);
}

void ImportProgramDataComponent::paint(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_PgmBankWindow);
	g.setOpacity(1.0f);
	MemoryInputStream backgroundInputStream{ BinaryData::ImportExportWindowBackground_png, BinaryData::ImportExportWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(backgroundInputStream) };
	g.drawImageAt(backgroundImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
	MemoryInputStream titleInputStream{ BinaryData::WindowTitleImportProgram_png, BinaryData::WindowTitleImportProgram_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(titleInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ImportProgramDataComponent::resized() {
	browserComponent->setBounds(GUI::bounds_ImptExptBrowserComponent);
	button_Esc.setBounds(GUI::bounds_ImptExptEscButton);
	button_OK.setBounds(GUI::bounds_ImptExptOKbutton);
}

void ImportProgramDataComponent::selectionChanged() {
}

void ImportProgramDataComponent::fileClicked(const File& file, const MouseEvent& /*mouseEvent*/) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
	}
}

void ImportProgramDataComponent::fileDoubleClicked(const File& file) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
		okButtonClicked();
	}
}

void ImportProgramDataComponent::browserRootChanged(const File& /*file*/) {
}

void ImportProgramDataComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	FileInputStream inputStream{ selectedFile };
	if (inputStream.openedOk()) {
		auto incomingString{ inputStream.readString() };
		auto pgmDataString{ incomingString.initialSectionContainingOnly("1234567890ABCDEF") };
		if (RawDataTools::isValidPgmDataHexString(pgmDataString)) {
			importProgramDataFromString(incomingString);
			return;
		}
		else {
			showFileNotValidAlert();
			return;
		}
	}
	else
		showFileNotValidAlert();
}

void ImportProgramDataComponent::showFileNotValidAlert() {
	fileNotValidAlert.reset(new FileNotValidAlert());
	addAndMakeVisible(fileNotValidAlert.get());
	fileNotValidAlert->setBounds(getLocalBounds());
	fileNotValidAlert->grabKeyboardFocus();
}

void ImportProgramDataComponent::importProgramDataFromString(String incomingString) {
	auto pgmDataBank{ unexposedParams->programDataBank_get() };
	pgmDataBank->storePgmDataHexStringInSlot(incomingString, slot);
	hideThisComponent();
}

void ImportProgramDataComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

ImportProgramDataComponent::~ImportProgramDataComponent() {
	fileNotValidAlert = nullptr;
}
