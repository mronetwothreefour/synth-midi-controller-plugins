#include "imptExpt_ExportVoicesBankComponent.h"

#include "imptExpt_FileOverwriteConfirmDialogBox.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_Constants.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ExportVoicesBankComponent::ExportVoicesBankComponent(VoicesBank bank, VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::exportVoicesBank, bank, slotsComponent, unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		button_Cancel.setTooltip("Click to cancel the file export.");
		button_OK.setTooltip("Click to export the program data\nbank to the specified file.");
	}
}

void ExportVoicesBankComponent::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::WindowTitleExportProgramBank_png, BinaryData::WindowTitleExportProgramBank_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ExportVoicesBankComponent::buttonClicked(Button* button) {
	if (fileOverwriteConfirmDialogBox != nullptr) {
		if (button->getComponentID() == ID::button_CancelFileOverwrite.toString())
			fileOverwriteConfirmDialogBox->hideThisComponent();
		if (button->getComponentID() == ID::button_FileOverwrite.toString()) {
			fileOverwriteConfirmDialogBox->hideThisComponent();
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeVoicesBankDataIntoFile(selectedFile);
		}
	}
}

void ExportVoicesBankComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile()) {
		showFileOverwriteConfirmDialogBox();
	}
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeVoicesBankDataIntoFile(fileToWriteTo);
	}
}

void ExportVoicesBankComponent::showFileOverwriteConfirmDialogBox() {
	fileOverwriteConfirmDialogBox.reset(new FileOverwriteConfirmDialogBox(unexposedParams));
	fileOverwriteConfirmDialogBox->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteConfirmDialogBox.get());
	fileOverwriteConfirmDialogBox->setBounds(getLocalBounds());
	fileOverwriteConfirmDialogBox->grabKeyboardFocus();
}

void ExportVoicesBankComponent::writeVoicesBankDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto voicesBanks{ unexposedParams->voicesBanks_get() };
		for (uint8 slot = 0; slot != voices::numberOfSlotsInVoicesBank; ++slot) {
			auto voiceDataHexString{ voicesBanks->getVoiceDataHexStringFromBankSlot(bank, slot) };
			outStream.writeText(voiceDataHexString + "\r\n", false, false, nullptr);
		}
		hideThisComponent();
	}
}

ExportVoicesBankComponent::~ExportVoicesBankComponent() {
	if (fileOverwriteConfirmDialogBox != nullptr)
		fileOverwriteConfirmDialogBox->removeListenerFromButtons(this);
	fileOverwriteConfirmDialogBox = nullptr;
}
