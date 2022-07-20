#include "imEx_3_gui_layer_Export_VoicesBank.h"

#include "imEx_0_gui_layer_FileOverwriteDialog.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"
#include "../voices/voices_2_comp_VoiceSlots.h"



GUI_Layer_Export_VoicesBank::GUI_Layer_Export_VoicesBank(VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::exportVoicesBank, bank, voiceSlots, unexposedParams }
{
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescriptions()) {
		button_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		button_Cancel.setTooltip("Click to cancel the file export.");
		button_Proceed.setTooltip("Click to export the program data\nbank to the specified file.");
	}
}

void GUI_Layer_Export_VoicesBank::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ExportVoicesBank_png, BinaryData::lbl_ExportVoicesBank_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, importExportBackground_x, importExportBackground_y);
}

void GUI_Layer_Export_VoicesBank::proceedButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile()) {
		showFileOverwriteDialog();
	}
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeVoicesBankDataIntoFile(fileToWriteTo);
	}
}

void GUI_Layer_Export_VoicesBank::showFileOverwriteDialog() {
	fileOverwriteDialog.reset(new GUI_Layer_FileOverwriteDialog(unexposedParams));
	fileOverwriteDialog->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteDialog.get());
	fileOverwriteDialog->setBounds(getLocalBounds());
	fileOverwriteDialog->grabKeyboardFocus();
}

void GUI_Layer_Export_VoicesBank::buttonClicked(Button* button) {
	if (fileOverwriteDialog != nullptr) {
		if (button->getComponentID() == ID::button_Cancel_FileOverwrite.toString()) {
			grabKeyboardFocus();
			fileOverwriteDialog->setVisible(false);
		}
		if (button->getComponentID() == ID::button_Write_OverFile.toString()) {
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeVoicesBankDataIntoFile(selectedFile);
			fileOverwriteDialog->setVisible(false);
			hideThisLayer();
		}
	}
}

void GUI_Layer_Export_VoicesBank::writeVoicesBankDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto voicesBanks{ unexposedParams->getVoicesBanks() };
		for (uint8 slot = 0; slot != VCS::numberOfSlotsInVoicesBank; ++slot) {
			auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slot) };
			outStream.writeText(voiceDataHexString + "\r\n", false, false, nullptr);
		}
		hideThisLayer();
	}
}

GUI_Layer_Export_VoicesBank::~GUI_Layer_Export_VoicesBank() {
	if (fileOverwriteDialog != nullptr)
		fileOverwriteDialog->removeListenerFromButtons(this);
	fileOverwriteDialog = nullptr;
}
