#include "imEx_3_gui_layer_Import_Voice.h"

#include "../constants/constants_Identifiers.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_3_comp_VoiceSlots.h"

GUI_Layer_Import_Voice::GUI_Layer_Import_Voice(VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::importVoice, bank, voiceSlots, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() }
{
	jassert(bank == VoicesBank::custom_A || bank == VoicesBank::custom_B);
	if (tooltips->shouldShowDescription()) {
		btn_Cancel.setTooltip("Click to cancel the data import.");
		btn_Proceed.setTooltip("Click to import the patch\ndata from the selected file.");
	}
}

void GUI_Layer_Import_Voice::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ImportVoice_png, BinaryData::lbl_ImportVoice_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, importExportBackground_x + border_w, importExportBackground_y + border_w);
}

void GUI_Layer_Import_Voice::proceedButtonClicked() {
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
	voicesBanks->storeVoiceDataHexStringInCustomBankSlot(incomingString, bank, slot);
	hideThisLayer();
}
