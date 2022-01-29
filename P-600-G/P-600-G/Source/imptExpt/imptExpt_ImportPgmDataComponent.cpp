#include "imptExpt_ImportPgmDataComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_Constants.h"
#include "../pgmData/pgmData_PgmDataSlotsComponent.h"

using namespace constants;



ImportProgramDataComponent::ImportProgramDataComponent(ProgramDataSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::importProgram, slotsComponent, unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		button_Esc.setTooltip("Click to cancel the data import.");
		button_OK.setTooltip("Click to import program data\nfrom the selected file.");
	}
}

void ImportProgramDataComponent::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::WindowTitleImportProgram_png, BinaryData::WindowTitleImportProgram_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ImportProgramDataComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	FileInputStream inputStream{ selectedFile };
	if (inputStream.openedOk()) {
		auto incomingString{ inputStream.readString() };
		auto pgmDataString{ incomingString.initialSectionContainingOnly("1234567890ABCDEF") };
		if (RawDataTools::isValidPgmDataHexString(pgmDataString)) {
			importProgramDataFromString(incomingString);
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

void ImportProgramDataComponent::importProgramDataFromString(String incomingString) {
	auto slot{ slotsComponent->selectedSlot };
	auto pgmDataBank{ unexposedParams->programDataBank_get() };
	pgmDataBank->storePgmDataHexStringInSlot(incomingString, slot);
	hideThisComponent();
}

