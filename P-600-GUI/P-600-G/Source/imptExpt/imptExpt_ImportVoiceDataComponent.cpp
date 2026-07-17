#include "imptExpt_ImportVoiceDataComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ImportVoiceDataComponent::ImportVoiceDataComponent(VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::importVoice, slotsComponent, unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_Esc.setTooltip("Click to cancel the data import.");
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
		auto voiceDataHexString{ incomingString.initialSectionContainingOnly("1234567890ABCDEFabcdef") };
		if (RawDataTools::isValidVoiceDataHexString(voiceDataHexString)) {
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
	auto voicesBank{ unexposedParams->voicesBank_get() };
	voicesBank->storeVoiceDataHexStringInSlot(incomingString, slot);
	hideThisComponent();
}

