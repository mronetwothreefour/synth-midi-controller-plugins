#include "imptExpt_ExportPgmDataBankComponent.h"

#include "imptExpt_FileOverwriteConfirmDialogBox.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ExportProgramDataBankComponent::ExportProgramDataBankComponent(VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::exportProgramBank, slotsComponent, unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		button_Esc.setTooltip("Click to cancel the file export.");
		button_OK.setTooltip("Click to export the program data\nbank to the specified file.");
	}
}

void ExportProgramDataBankComponent::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::WindowTitleExportProgramBank_png, BinaryData::WindowTitleExportProgramBank_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ExportProgramDataBankComponent::buttonClicked(Button* button) {
	if (fileOverwriteConfirmDialogBox != nullptr) {
		if (button->getComponentID() == ID::button_EscFileOverwrite.toString())
			fileOverwriteConfirmDialogBox->hideThisComponent();
		if (button->getComponentID() == ID::button_OKfileOverwrite.toString()) {
			fileOverwriteConfirmDialogBox->hideThisComponent();
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeProgramBankDataIntoFile(selectedFile);
		}
	}
}

void ExportProgramDataBankComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile()) {
		showFileOverwriteConfirmDialogBox();
	}
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeProgramBankDataIntoFile(fileToWriteTo);
	}
}

void ExportProgramDataBankComponent::showFileOverwriteConfirmDialogBox() {
	fileOverwriteConfirmDialogBox.reset(new FileOverwriteConfirmDialogBox(unexposedParams));
	fileOverwriteConfirmDialogBox->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteConfirmDialogBox.get());
	fileOverwriteConfirmDialogBox->setBounds(getLocalBounds());
	fileOverwriteConfirmDialogBox->grabKeyboardFocus();
}

void ExportProgramDataBankComponent::writeProgramBankDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto voicesBank{ unexposedParams->voicesBank_get() };
		for (uint8 slot = 0; slot != voices::numberOfSlotsInVoicesBank; ++slot) {
			auto pgmDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(slot) };
			outStream.writeText(pgmDataHexString + "\r\n", false, false, nullptr);
		}
		hideThisComponent();
	}
}

ExportProgramDataBankComponent::~ExportProgramDataBankComponent() {
	if (fileOverwriteConfirmDialogBox != nullptr)
		fileOverwriteConfirmDialogBox->removeListenerFromButtons(this);
	fileOverwriteConfirmDialogBox = nullptr;
}
