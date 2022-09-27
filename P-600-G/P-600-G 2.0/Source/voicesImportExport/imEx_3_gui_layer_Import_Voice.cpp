#include "imEx_3_gui_layer_Import_Voice.h"

#include "../constants/constants_Identifiers.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_3_comp_VoiceSlots.h"

GUI_Layer_Import_Voice::GUI_Layer_Import_Voice(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::importVoice, voiceSlots, unexposedParams },
	voicesBank{ unexposedParams->getVoicesBank() }
{
	if (tooltips->shouldShowDescription()) {
		btn_Esc.setTooltip("Click to cancel the data import.");
		btn_OK.setTooltip("Click to import the program\ndata from the selected file.");
	}
}

void GUI_Layer_Import_Voice::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ImportVoice_png, BinaryData::lbl_ImportVoice_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::bounds_ImportExport.getX(), GUI::bounds_ImportExport.getY());
}

void GUI_Layer_Import_Voice::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	FileInputStream inputStream{ selectedFile };
	if (inputStream.openedOk()) {
		auto incomingString{ inputStream.readString() };
		if (RawDataTools::isValidVoiceDataHexString(incomingString)) {
			importVoiceDataFromString(incomingString);
			return;
		}
		else {
			showFileIsNotValidAlert();
			return;
		}
	}
	else
		showFileIsNotValidAlert();
}

void GUI_Layer_Import_Voice::importVoiceDataFromString(String incomingString) {
	auto slot{ voiceSlots->selectedSlot };
	voicesBank->storeVoiceDataHexStringInSlot(incomingString, slot);
	hideThisLayer();
}
