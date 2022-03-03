#include "imptExpt_BaseImptExptComponent.h"

#include "imptExpt_FileNotValidAlert.h"
#include "imptExpt_FolderNameDialogBox.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



BaseImportExportComponent::BaseImportExportComponent(ImptExptType type, VoicesBank bank, VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	type{ type },
	bank{ bank },
	slotsComponent{ slotsComponent },
	unexposedParams{ unexposedParams }
{
	String userDocsPath{ File::getSpecialLocation(File::userDocumentsDirectory).getFullPathName() };
	String mophoGUIdir{ "\\MophoGUI\\" };
	auto defaultDirectory{ userDocsPath + mophoGUIdir };

	if (type == ImptExptType::importVoice || type == ImptExptType::importVoicesBank) {
		auto browserFlags{ FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles };
		if (type == ImptExptType::importVoice)
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory, &voiceDataFileFilter, nullptr));
		else
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory, &voicesBankFileFilter, nullptr));
	}

	if (type == ImptExptType::exportVoice || type == ImptExptType::exportVoicesBank) {
		auto browserFlags{ FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles | FileBrowserComponent::warnAboutOverwriting | FileBrowserComponent::doNotClearFileNameOnRootChange };
		String defaultFileName{ "" };
		if (type == ImptExptType::exportVoice) {
			auto slot{ slotsComponent->selectedSlot };
			auto voicesBank{ unexposedParams->voicesBanks_get() };
			auto selectedVoiceName{ voicesBank->nameOfVoiceInBankSlot(bank, slot) };
			defaultFileName = File::createLegalFileName(selectedVoiceName) + voiceDataFileFilter.getDescription();
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory + defaultFileName, &voiceDataFileFilter, nullptr));
		}
		else {
			defaultFileName = "MophoGUI Program Data Bank" + voicesBankFileFilter.getDescription();
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory + defaultFileName, &voicesBankFileFilter, nullptr));
		}
	}

	if (browserComponent != nullptr) {
		browserComponent->setComponentID(ID::component_ImptExptBrowser.toString());
		browserComponent->setFilenameBoxLabel("");
		addAndMakeVisible(browserComponent.get());
		browserComponent->addListener(this);
	}

	if (type == ImptExptType::exportVoice || type == ImptExptType::exportVoicesBank) {
		addAndMakeVisible(button_NewFolder);
		button_NewFolder.setComponentID(ID::button_NewFolder.toString());
		button_NewFolder.onClick = [this] { showFolderNameDialogBox(); };
	}

	addAndMakeVisible(button_Cancel);
	button_Cancel.setComponentID(ID::button_CancelImptExpt.toString());
	button_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));
	button_Cancel.onClick = [this] { hideThisComponent(); };

	addAndMakeVisible(button_OK);
	button_OK.setComponentID(type == ImptExptType::exportVoice || type == ImptExptType::exportVoicesBank ?  ID::button_Export.toString() : ID::button_Import.toString());
	button_OK.addShortcut(KeyPress(KeyPress::returnKey));
	button_OK.onClick = [this] { okButtonClicked(); };

	setSize(GUI::editor_w, GUI::editor_h);
}

void BaseImportExportComponent::resized() {
	if (browserComponent != nullptr)
		browserComponent->setBounds(GUI::bounds_ImptExptBrowserComponent);
	button_NewFolder.setBounds(GUI::bounds_ImptExptNewFolderButton);
	button_Cancel.setBounds(GUI::bounds_ImptExptCancelButton);
	button_OK.setBounds(GUI::bounds_ImptExptOKbutton);
}

void BaseImportExportComponent::drawBackgroundImage(Graphics& g) {
	g.setColour(Color::black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_VoicesBanksTabbedComponent.expanded(GUI::windowOutlineThickness));
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::ImportExportWindowBackground_png, BinaryData::ImportExportWindowBackground_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void BaseImportExportComponent::selectionChanged() {
}

void BaseImportExportComponent::fileClicked(const File& file, const MouseEvent& /*mouseEvent*/) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
	}
}

void BaseImportExportComponent::fileDoubleClicked(const File& file) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
		okButtonClicked();
	}
}

void BaseImportExportComponent::browserRootChanged(const File& /*file*/) {
}

void BaseImportExportComponent::showFolderNameDialogBox() {
	folderNameDialogBox.reset(new FolderNameDialogBox(browserComponent.get(), unexposedParams));
	addAndMakeVisible(folderNameDialogBox.get());
	folderNameDialogBox->setBounds(getLocalBounds());
	folderNameDialogBox->grabKeyboardFocus();
}

File BaseImportExportComponent::createFileToWriteTo(File& file) {
	auto fullPath{ file.getFullPathName() };
	auto legalPath{ File::createLegalPathName(fullPath) };
	auto fileType{ type == ImptExptType::exportVoice ? voiceDataFileFilter.getDescription() : voicesBankFileFilter.getDescription() };
	if (!legalPath.endsWith(fileType))
		legalPath.append(fileType, fileType.length());
	File fileToWriteTo{ legalPath };
	fileToWriteTo.create();
	return fileToWriteTo;
}

void BaseImportExportComponent::showFileIsNotValidAlert() {
	fileNotValidAlert.reset(new FileNotValidAlert());
	addAndMakeVisible(fileNotValidAlert.get());
	fileNotValidAlert->setBounds(getLocalBounds());
	fileNotValidAlert->grabKeyboardFocus();
}

void BaseImportExportComponent::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

BaseImportExportComponent::~BaseImportExportComponent() {
	fileNotValidAlert = nullptr;
	folderNameDialogBox = nullptr;
	if (browserComponent != nullptr)
		browserComponent->removeListener(this);
	browserComponent = nullptr;
}
