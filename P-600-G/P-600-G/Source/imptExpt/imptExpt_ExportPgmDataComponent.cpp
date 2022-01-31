#include "imptExpt_ExportPgmDataComponent.h"

#include "imptExpt_FileOverwriteConfirmDialogBox.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../pgmData/pgmData_PgmDataSlotsComponent.h"

using namespace constants;



ExportProgramDataComponent::ExportProgramDataComponent(ProgramDataSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::exportProgram, slotsComponent, unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		button_Esc.setTooltip("Click to cancel the file export.");
		button_OK.setTooltip("Click to export the selected program" + GUI::apostrophe + "s\ndata to the specified file.");
	}
}

void ExportProgramDataComponent::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::WindowTitleExportProgram_png, BinaryData::WindowTitleExportProgram_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ExportProgramDataComponent::buttonClicked(Button* button) {
	if (fileOverwriteConfirmDialogBox != nullptr) {
		if (button->getComponentID() == ID::button_EscFileOverwrite.toString())
			fileOverwriteConfirmDialogBox->hideThisComponent();
		if (button->getComponentID() == ID::button_OKfileOverwrite.toString()) {
			fileOverwriteConfirmDialogBox->hideThisComponent();
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeProgramDataIntoFile(selectedFile);
		}
	}
}

void ExportProgramDataComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile()) {
		showFileOverwriteConfirmDialogBox();
	}
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeProgramDataIntoFile(fileToWriteTo);
	}
}

void ExportProgramDataComponent::showFileOverwriteConfirmDialogBox() {
	fileOverwriteConfirmDialogBox.reset(new FileOverwriteConfirmDialogBox(unexposedParams));
	fileOverwriteConfirmDialogBox->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteConfirmDialogBox.get());
	fileOverwriteConfirmDialogBox->setBounds(getLocalBounds());
	fileOverwriteConfirmDialogBox->grabKeyboardFocus();
}

void ExportProgramDataComponent::writeProgramDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto slot{ slotsComponent->selectedSlot };
		auto pgmDataBank{ unexposedParams->programDataBank_get() };
		auto pgmDataHexString{ pgmDataBank->getPgmDataHexStringFromSlot(slot) };
		outStream.writeText(pgmDataHexString, false, false, nullptr);
		hideThisComponent();
	}
}

ExportProgramDataComponent::~ExportProgramDataComponent() {
	if (fileOverwriteConfirmDialogBox != nullptr)
		fileOverwriteConfirmDialogBox->removeListenerFromButtons(this);
	fileOverwriteConfirmDialogBox = nullptr;
}
