#include "imEx_3_gui_layer_Import_Voice.h"

#include "../../constants/constants_Identifiers.h"
#include "../../midi/midi_0_RawDataTools.h"
#include "../../unexposedParameters/up_facade_UnexposedParameters.h"
#include "../../voices/voices_2_comp_VoiceSlots.h"



GUI_Layer_Import_Voice::GUI_Layer_Import_Voice(VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::importVoice, bank, voiceSlots, unexposedParams }
{
	jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
	auto tooltips{ unexposedParams->getTooltipsOptions() };
	if (tooltips->shouldShowDescriptions()) {
		button_Cancel.setTooltip("Click to cancel the data import.");
		button_Proceed.setTooltip("Click to import the program\ndata from the selected file.");
	}
}

void GUI_Layer_Import_Voice::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ImportVoice_png, BinaryData::lbl_ImportVoice_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage,importExportBackground_x, importExportBackground_y);
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
	auto voicesBanks{ unexposedParams->getVoicesBanks() };
	voicesBanks->storeVoiceDataHexStringInCustomBankSlot(incomingString, bank, slot);
	hideThisLayer();
}
