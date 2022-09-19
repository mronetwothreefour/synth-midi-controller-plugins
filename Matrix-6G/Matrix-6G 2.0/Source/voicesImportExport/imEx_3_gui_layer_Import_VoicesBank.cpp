#include "imEx_3_gui_layer_Import_VoicesBank.h"

#include "../constants/constants_Identifiers.h"
#include "../midi/midi_0_RawDataTools.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"
#include "../voices/voices_3_comp_VoiceSlots.h"

GUI_Layer_Import_VoicesBank::GUI_Layer_Import_VoicesBank(VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::importVoicesBank, bank, voiceSlots, unexposedParams },
	voicesBanks{ unexposedParams->getVoicesBanks() }
{
	jassert(bank == VoicesBank::custom_A || bank == VoicesBank::custom_B);
	if (tooltips->shouldShowDescription()) {
		btn_Cancel.setTooltip("Click to cancel the data import.");
		btn_Proceed.setTooltip("Click to import the patch data\nbank from the selected file.");
	}
}

void GUI_Layer_Import_VoicesBank::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ImportVoicesBank_png, BinaryData::lbl_ImportVoicesBank_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, importExportBackground_x + border_w, importExportBackground_y + border_w);
}

void GUI_Layer_Import_VoicesBank::proceedButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	FileInputStream inputStream{ selectedFile };
	if (inputStream.openedOk()) {
		StringArray voicesDataArray{};
		while (!inputStream.isExhausted()) {
			auto voiceDataString{ inputStream.readNextLine() };
			if (RawDataTools::isValidVoiceDataHexString(voiceDataString))
				voicesDataArray.add(voiceDataString);
			else {
				showFileIsNotValidAlert();
				return;
			}
		}
		if (voicesDataArray.size() == VCS::numberOfSlotsInVoicesBank)
			importVoiceDataFromStringArray(voicesDataArray);
		else {
			showFileIsNotValidAlert();
			return;
		}
	}
	else {
		showFileIsNotValidAlert();
		return;
	}
}

void GUI_Layer_Import_VoicesBank::importVoiceDataFromStringArray(StringArray stringArray) {
	for (uint8 slot = 0; slot != VCS::numberOfSlotsInVoicesBank; ++slot)
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(stringArray[slot], bank, slot);
	hideThisLayer();
}
