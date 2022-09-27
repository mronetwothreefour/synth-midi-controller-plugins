#include "imEx_2_gui_layer_ImportExport_Base.h"

#include "imEx_0_gui_layer_FileNotValidAlert.h"
#include "imEx_1_gui_layer_NewFolderDialog.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_3_comp_VoiceSlots.h"

GUI_Layer_ImportExport_Base::GUI_Layer_ImportExport_Base(
	ImportExportType type, VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	type{ type },
	bank{ bank },
	voiceSlots{ voiceSlots },
	tooltips{ unexposedParams->getTooltipsOptions() }
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
			auto voicesBanks{ unexposedParams->getVoicesBanks() };
			auto selectedVoiceName{ voicesBanks->nameOfVoiceInBankSlot(bank, slot) };
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
		browserComponent->setComponentID(ID::comp_ImportExportBrowser.toString());
		browserComponent->setFilenameBoxLabel("");
		browserComponent->addListener(this);
		browserComponent->setBounds(401, 187, 471, 245);
		addAndMakeVisible(browserComponent.get());
	}

	const int buttonsRow_y{ 442 };
	if (type == ImportExportType::exportVoice || type == ImportExportType::exportVoicesBank) {
		btn_NewFolder.setComponentID(ID::btn_NewFolder.toString());
		btn_NewFolder.onClick = [this] { showNewFolderDialog(); };
		btn_NewFolder.setBounds(401, buttonsRow_y, 78, GUI::redButton_h);
		addAndMakeVisible(btn_NewFolder);
	}

	btn_Cancel.setComponentID(ID::btn_Cancel_ImportExport.toString());
	btn_Cancel.addShortcut(KeyPress(KeyPress::escapeKey));
	btn_Cancel.onClick = [this] { hideThisLayer(); };
	btn_Cancel.setBounds(763, buttonsRow_y, GUI::btn_Cancel_w, GUI::redButton_h);
	addAndMakeVisible(btn_Cancel);

	if (type == ImportExportType::exportVoice || type == ImportExportType::exportVoicesBank)
		btn_Proceed.setComponentID(ID::btn_Export_File.toString());
	else
		btn_Proceed.setComponentID(ID::btn_Import_File.toString());
	btn_Proceed.addShortcut(KeyPress(KeyPress::returnKey));
	btn_Proceed.onClick = [this] { proceedButtonClicked(); };
	btn_Proceed.setBounds(820, buttonsRow_y, GUI::btn_Cancel_w, GUI::redButton_h);
	addAndMakeVisible(btn_Proceed);

	setSize(GUI::editor_w, GUI::editor_h);
}

void GUI_Layer_ImportExport_Base::drawBackgroundImage(Graphics& g) {
	g.setColour(GUI::color_Black.withAlpha(0.4f));
	g.fillRect(GUI::bounds_VoicesBanks);
	g.setOpacity(1.0f);
	MemoryInputStream memInputStream{ BinaryData::bkgrnd_ImportExportWindow_png, BinaryData::bkgrnd_ImportExportWindow_pngSize, false };
	PNGImageFormat imageFormat;
	auto backgroundImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(backgroundImage, GUI::bounds_ImportExport.getX(), GUI::bounds_ImportExport.getY());
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
	newFolderDialog.reset(new GUI_Layer_NewFolderDialog(browserComponent.get(), tooltips));
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
	fileNotValidAlert.reset(new GUI_Layer_FileNotValidAlert(tooltips));
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
