#include "imptExpt_ImportPgmDataBankComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_Constants.h"
#include "../pgmData/pgmData_PgmDataSlotsComponent.h"

using namespace constants;



ImportProgramDataBankComponent::ImportProgramDataBankComponent(ProgramDataSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::importProgramBank, slotsComponent, unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescription()) {
		button_Esc.setTooltip("Click to cancel the data import.");
		button_OK.setTooltip("Click to import the program data\nbank from the selected file.");
	}
}

void ImportProgramDataBankComponent::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::WindowTitleImportProgramBank_png, BinaryData::WindowTitleImportProgramBank_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ImportProgramDataBankComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	FileInputStream inputStream{ selectedFile };
	if (inputStream.openedOk()) {
		StringArray pgmDataArray{};
		while (!inputStream.isExhausted()) {
			auto pgmDataString{ inputStream.readNextLine() };
			if (RawDataTools::isValidPgmDataHexString(pgmDataString))
				pgmDataArray.add(pgmDataString);
			else {
				showFileIsNotValidAlert();
				return;
			}
		}
		if (pgmDataArray.size() == pgmData::numberOfSlotsInPgmDataBank)
			importProgramDataFromStringArray(pgmDataArray);
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

void ImportProgramDataBankComponent::importProgramDataFromStringArray(StringArray stringArray) {
	for (uint8 slot = 0; slot != pgmData::numberOfSlotsInPgmDataBank; ++slot) {
		auto pgmDataBank{ unexposedParams->programDataBank_get() };
		pgmDataBank->storePgmDataHexStringInSlot(stringArray[slot], slot);
	}
	hideThisComponent();
}
