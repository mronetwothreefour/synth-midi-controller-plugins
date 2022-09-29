#include "imEx_2_gui_layer_ImportExport_Base.h"

#include "imEx_0_gui_layer_FileNotValidAlert.h"
#include "imEx_1_gui_layer_NewFolderDialog.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_3_comp_VoiceSlots.h"

GUI_Layer_ImportExport_Base::GUI_Layer_ImportExport_Base(
	ImportExportType type, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	type{ type },
	voiceSlots{ voiceSlots },
	tooltips{ unexposedParams->getTooltipsOptions() }
{
	String userDocsPath{ File::getSpecialLocation(File::userDocumentsDirectory).getFullPathName() };
	String p_600_G_dir{ "\\P-600-G\\" };
	auto defaultDirectory{ userDocsPath + p_600_G_dir };

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
			auto voicesBank{ unexposedParams->getVoicesBank() };
			auto selectedVoiceName{ voicesBank->nameOfVoiceInSlot(slot) };
			selectedVoiceName = selectedVoiceName.trimCharactersAtEnd(" ");
			defaultFileName = File::createLegalFileName(selectedVoiceName) + voiceDataFileFilter.getDescription();
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory + defaultFileName, &voiceDataFileFilter, nullptr));
		}
		else {
			defaultFileName = "P-600-G Program Data Bank" + voicesBankFileFilter.getDescription();
			browserComponent.reset(new FileBrowserComponent(browserFlags, defaultDirectory + defaultFileName, &voicesBankFileFilter, nullptr));
		}
	}

	if (browserComponent != nullptr) {
		browserComponent->setComponentID(ID::comp_ImptExptBrowser.toString());
		browserComponent->setFilenameBoxLabel("");
		browserComponent->addListener(this);
		browserComponent->setBounds(466, 61, 470, 245);
		addAndMakeVisible(browserComponent.get());
	}

	const int buttonsRow_y{ 316 };
	if (type == ImportExportType::exportVoice || type == ImportExportType::exportVoicesBank) {
		btn_NewFolder.setComponentID(ID::btn_NewFolder.toString());
		btn_NewFolder.onClick = [this] { showNewFolderDialog(); };
		btn_NewFolder.setBounds(466, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
		addAndMakeVisible(btn_NewFolder);
	}

	btn_Esc.setComponentID(ID::btn_Esc_ImportExport.toString());
	btn_Esc.addShortcut(KeyPress(KeyPress::escapeKey));
	btn_Esc.onClick = [this] { hideThisLayer(); };
	btn_Esc.setBounds(846, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_Esc);

	if (type == ImportExportType::exportVoice || type == ImportExportType::exportVoicesBank)
		btn_OK.setComponentID(ID::btn_OK_ExportFile.toString());
	else	
		btn_OK.setComponentID(ID::btn_OK_ImportFile.toString());
	btn_OK.addShortcut(KeyPress(KeyPress::returnKey));
	btn_OK.onClick = [this] { okButtonClicked(); };
	btn_OK.setBounds(896, buttonsRow_y, GUI::buttons_w, GUI::buttons_h);
	addAndMakeVisible(btn_OK);

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
		okButtonClicked();
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
	setVisible(false);
	getParentComponent()->grabKeyboardFocus();
}

GUI_Layer_ImportExport_Base::~GUI_Layer_ImportExport_Base() {
	fileNotValidAlert = nullptr;
	newFolderDialog = nullptr;
	if (browserComponent != nullptr)
		browserComponent->removeListener(this);
	browserComponent = nullptr;
}
