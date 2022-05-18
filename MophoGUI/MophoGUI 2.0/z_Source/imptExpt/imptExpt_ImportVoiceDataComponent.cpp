#include "imptExpt_ImportVoiceDataComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ImportVoiceDataComponent::ImportVoiceDataComponent(VoicesBank bank, VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::importVoice, bank, slotsComponent, unexposedParams }
{
	jassert(bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3);
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_Cancel.setTooltip("Click to cancel the data import.");
		button_OK.setTooltip("Click to import the program\ndata from the selected file.");
	}
}

void ImportVoiceDataComponent::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::WindowTitleImportProgram_png, BinaryData::WindowTitleImportProgram_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ImportVoiceDataComponent::okButtonClicked() {
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

void ImportVoiceDataComponent::importVoiceDataFromString(String incomingString) {
	auto slot{ slotsComponent->selectedSlot };
	auto voicesBanks{ unexposedParams->voicesBanks_get() };
	voicesBanks->storeVoiceDataHexStringInCustomBankSlot(incomingString, bank, slot);
	hideThisComponent();
}