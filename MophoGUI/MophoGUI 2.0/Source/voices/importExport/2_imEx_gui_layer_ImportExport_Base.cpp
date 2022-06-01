#include "2_imEx_gui_layer_ImportExport_Base.h"

#include "0_imEx_gui_layer_FileNotValidAlert.h"
#include "1_imEx_gui_layer_NewFolderDialog.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_Identifiers.h"
#include "../../unexposedParameters/up_facade_UnexposedParameters.h"
#include "../../voices/2_voices_comp_VoiceSlots.h"



GUI_Layer_ImportExport_Base::GUI_Layer_ImportExport_Base(
	ImportExportType type, VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	type{ type },
	bank{ bank },
	voiceSlots{ voiceSlots },
	unexposedParams{ unexposedParams }
{
	String userDocsPath{ File::getSpecialLocation(File::userDocumentsDirectory).getFullPathName() };
	String mophoGUIdir{ "\\MophoGUI\\" };
	auto defaultDirectory{ userDocsPath + mophoGUIdir };

	if (type == ImportExportType::importVoice || type == ImportExportType::importVoicesBank) {
		auto browserFlags{ FileBrowserComponent::openMode | FileBrowserComponent::canSelectFiles };
		if (type == ImportExportType::importVoice)
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory, &voiceDataFileFilter, nullptr));
		else
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory, &voicesBankFileFilter, nullptr));
	}

	if (type == ImportExportType::exportVoice || type == ImportExportType::exportVoicesBank) {
		auto browserFlags{ FileBrowserComponent::saveMode | FileBrowserComponent::canSelectFiles | FileBrowserComponent::warnAboutOverwriting | FileBrowserComponent::doNotClearFileNameOnRootChange };
		String defaultFileName{ "" };
		if (type == ImportExportType::exportVoice) {
			auto slot{ voiceSlots->selectedSlot };
			auto voicesBank{ unexposedParams->getVoicesBanks() };
			auto selectedVoiceName{ voicesBank->nameOfVoiceInBankSlot(bank, slot) };
			selectedVoiceName = selectedVoiceName.trimCharactersAtEnd(" ");
			defaultFileName = File::createLegalFileName(selectedVoiceName) + voiceDataFileFilter.getDescription();
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory + defaultFileName, &voiceDataFileFilter, nullptr));
		}
		else {
			defaultFileName = "MophoGUI Program Data Bank" + voicesBankFileFilter.getDescription();
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory + defaultFileName, &voicesBankFileFilter, nullptr));
		}
	}

	if (browserComponent != nullptr) {
		browserComponent->setComponentID(ID::component_ImportExportBrowser.toString());
		browserComponent->setFilenameBoxLabel("");
		addAndMakeVisible(browserComponent.get());
		browserComponent->addListener(this);
	}

	if (type == ImportExportType::exportVoice || type == ImportExportType::exportVoicesBank) {
		addAndMakeVisible(button_NewFolder);
		button_NewFolder.setComponentID(ID::button_NewFolder.toString());
		button_NewFolder.onClick = [this] { showNewFolderDialog(); };
	}

	addAndMakeVisible(button_Cancel);
	button_Cancel.setComponentID(ID::button_Cancel_ImportExport.toString());
	button_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));
	button_Cancel.onClick = [this] { hideThisLayer(); };

	addAndMakeVisible(button_Proceed);
	if (type == ImportExportType::exportVoice || type == ImportExportType::exportVoicesBank)
		button_Proceed.setComponentID(ID::button_Export_File.toString());
	else
		button_Proceed.setComponentID(ID::button_Import_File.toString());
	button_Proceed.addShortcut(KeyPress(KeyPress::returnKey));
	button_Proceed.onClick = [this] { proceedButtonClicked(); };

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_ImportExport_Base::resized() {
	if (browserComponent != nullptr)
		browserComponent->setBounds(401, 187, 471, 245);
	const int buttonsRow_y{ 442 };
	button_NewFolder.setBounds(401, buttonsRow_y, 78, GUI::redButton_h);
	button_Cancel.setBounds(763, buttonsRow_y, GUI::button_Cancel_w, GUI::redButton_h);
	button_Proceed.setBounds(820	, buttonsRow_y, GUI::button_Cancel_w, GUI::redButton_h);
}

void GUI_Layer_ImportExport_Base::drawBackgroundImage(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(getParentComponent()->getBounds());
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_ImportExportWindow_png, BinaryData::bkgrnd_ImportExportWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, 386, 147);
}

void GUI_Layer_ImportExport_Base::selectionChanged() {
}

void GUI_Layer_ImportExport_Base::fileClicked(const File& file, const MouseEvent& /*mouseEvent*/) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
	}
}

void GUI_Layer_ImportExport_Base::fileDoubleClicked(const File& file) {
	if (!file.isDirectory()) {
		auto fileName{ file.getFileName() };
		browserComponent->setFileName(fileName);
		proceedButtonClicked();
	}
}

void GUI_Layer_ImportExport_Base::browserRootChanged(const File& /*file*/) {
}

void GUI_Layer_ImportExport_Base::showNewFolderDialog() {
	newFolderDialog.reset(new GUI_Layer_NewFolderDialog(browserComponent.get(), unexposedParams));
	addAndMakeVisible(newFolderDialog.get());
	newFolderDialog->setBounds(getLocalBounds());
	newFolderDialog->grabKeyboardFocus();
}

File GUI_Layer_ImportExport_Base::createFileToWriteTo(File& file) {
	auto fullPath{ file.getFullPathName() };
	auto legalPath{ File::createLegalPathName(fullPath) };
	auto fileType{ type == ImportExportType::exportVoice ? voiceDataFileFilter.getDescription() : voicesBankFileFilter.getDescription() };
	if (!legalPath.endsWith(fileType))
		legalPath.append(fileType, fileType.length());
	File fileToWriteTo{ legalPath };
	fileToWriteTo.create();
	return fileToWriteTo;
}

void GUI_Layer_ImportExport_Base::showFileIsNotValidAlert() {
	fileNotValidAlert.reset(new GUI_Layer_FileNotValidAlert(unexposedParams));
	addAndMakeVisible(fileNotValidAlert.get());
	fileNotValidAlert->setBounds(getLocalBounds());
	fileNotValidAlert->grabKeyboardFocus();
}

void GUI_Layer_ImportExport_Base::hideThisLayer() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

GUI_Layer_ImportExport_Base::~GUI_Layer_ImportExport_Base() {
	fileNotValidAlert = nullptr;
	newFolderDialog = nullptr;
	if (browserComponent != nullptr)
		browserComponent->removeListener(this);
	browserComponent = nullptr;
}
