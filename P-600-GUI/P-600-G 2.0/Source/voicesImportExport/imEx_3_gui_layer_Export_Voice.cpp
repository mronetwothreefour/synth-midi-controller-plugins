#include "imEx_3_gui_layer_Export_Voice.h"

#include "imEx_0_gui_layer_FileOverwriteDialog.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_3_comp_VoiceSlots.h"

GUI_Layer_Export_Voice::GUI_Layer_Export_Voice(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::exportVoice, voiceSlots, unexposedParams },
	voicesBank{ unexposedParams->getVoicesBank() }
{
	if (tooltips->shouldShowDescription()) {
		btn_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		btn_Esc.setTooltip("Click to cancel the file export.");
		btn_OK.setTooltip("Click to export the selected program" + GUI::apostrophe + "s\ndata to the specified file.");
	}
}

void GUI_Layer_Export_Voice::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ExportVoice_png, BinaryData::lbl_ExportVoice_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::bounds_ImportExport.getX(), GUI::bounds_ImportExport.getY());
}

void GUI_Layer_Export_Voice::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile())
		showFileOverwriteDialog();
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeVoiceDataIntoFile(fileToWriteTo);
	}
}

void GUI_Layer_Export_Voice::showFileOverwriteDialog() {
	fileOverwriteDialog.reset(new GUI_Layer_FileOverwriteDialog(tooltips));
	fileOverwriteDialog->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteDialog.get());
	fileOverwriteDialog->setBounds(getLocalBounds());
	fileOverwriteDialog->grabKeyboardFocus();
}

void GUI_Layer_Export_Voice::buttonClicked(Button* button) {
	if (fileOverwriteDialog != nullptr) {
		if (button->getComponentID() == ID::btn_Esc_FileOverwrite.toString()) {
			fileOverwriteDialog->setVisible(false);
			grabKeyboardFocus();
		}
		if (button->getComponentID() == ID::btn_OK_FileOverwrite.toString()) {
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeVoiceDataIntoFile(selectedFile);
			fileOverwriteDialog->setVisible(false);
			hideThisLayer();
		}
	}
}

void GUI_Layer_Export_Voice::writeVoiceDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto slot{ voiceSlots->selectedSlot };
		auto voiceDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(slot) };
		outStream.writeText(voiceDataHexString, false, false, nullptr);
		hideThisLayer();
	}
}

GUI_Layer_Export_Voice::~GUI_Layer_Export_Voice() {
	if (fileOverwriteDialog != nullptr)
		fileOverwriteDialog->removeListenerFromButtons(this);
	fileOverwriteDialog = nullptr;
}
