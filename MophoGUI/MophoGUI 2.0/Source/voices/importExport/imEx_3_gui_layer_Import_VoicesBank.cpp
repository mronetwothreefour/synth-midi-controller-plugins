#include "imEx_3_gui_layer_Import_VoicesBank.h"

#include "../../constants/constants_Identifiers.h"
#include "../../midi/midi_0_RawDataTools.h"
#include "../../unexposedParameters/up_facade_UnexposedParameters.h"
#include "../../voices/voices_2_comp_VoiceSlots.h"



GUI_Layer_Import_VoicesBank::GUI_Layer_Import_VoicesBank(VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams) :
	GUI_Layer_ImportExport_Base{ ImportExportType::importVoicesBank, bank, voiceSlots, unexposedParams }
{
	jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_Cancel.setTooltip("Click to cancel the data import.");
		button_Proceed.setTooltip("Click to import the program data\nbank from the selected file.");
	}
}

void GUI_Layer_Import_VoicesBank::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::lbl_ImportVoicesBank_png, BinaryData::lbl_ImportVoicesBank_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, importExportBackground_x, importExportBackground_y);
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
	for (uint8 slot = 0; slot != VCS::numberOfSlotsInVoicesBank; ++slot) {
		auto voicesBanks{ unexposedParams->getVoicesBanks() };
		voicesBanks->storeVoiceDataHexStringInCustomBankSlot(stringArray[slot], bank, slot);
	}
	hideThisLayer();
}
