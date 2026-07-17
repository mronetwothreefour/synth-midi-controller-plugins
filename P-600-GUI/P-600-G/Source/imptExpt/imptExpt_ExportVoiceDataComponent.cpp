#include "imptExpt_ExportVoiceDataComponent.h"

#include "imptExpt_FileOverwriteConfirmDialogBox.h"
#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"
#include "../voices/voices_VoiceSlotsComponent.h"

using namespace constants;



ExportVoiceDataComponent::ExportVoiceDataComponent(VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams) :
	BaseImportExportComponent{ ImptExptType::exportVoice, slotsComponent, unexposedParams }
{
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	if (tooltipOptions->shouldShowDescriptions()) {
		button_NewFolder.setTooltip("Click to create a new folder\nin the current directory.");
		button_Esc.setTooltip("Click to cancel the file export.");
		button_OK.setTooltip("Click to export the selected program" + GUI::apostrophe + "s\ndata to the specified file.");
	}
}

void ExportVoiceDataComponent::paint(Graphics& g) {
	drawBackgroundImage(g);
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ BinaryData::WindowTitleExportProgram_png, BinaryData::WindowTitleExportProgram_pngSize, false };
	auto titleImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(titleImage, GUI::imptExptWindow_x, GUI::imptExptWindow_y);
}

void ExportVoiceDataComponent::buttonClicked(Button* button) {
	if (fileOverwriteConfirmDialogBox != nullptr) {
		if (button->getComponentID() == ID::button_EscFileOverwrite.toString())
			fileOverwriteConfirmDialogBox->hideThisComponent();
		if (button->getComponentID() == ID::button_OKfileOverwrite.toString()) {
			fileOverwriteConfirmDialogBox->hideThisComponent();
			auto selectedFile{ browserComponent->getSelectedFile(0) };
			writeVoiceDataIntoFile(selectedFile);
		}
	}
}

void ExportVoiceDataComponent::okButtonClicked() {
	auto selectedFile{ browserComponent->getSelectedFile(0) };
	if (selectedFile.existsAsFile()) {
		showFileOverwriteConfirmDialogBox();
	}
	else {
		auto fileToWriteTo{ createFileToWriteTo(selectedFile) };
		writeVoiceDataIntoFile(fileToWriteTo);
	}
}

void ExportVoiceDataComponent::showFileOverwriteConfirmDialogBox() {
	fileOverwriteConfirmDialogBox.reset(new FileOverwriteConfirmDialogBox(unexposedParams));
	fileOverwriteConfirmDialogBox->addListenerToButtons(this);
	addAndMakeVisible(fileOverwriteConfirmDialogBox.get());
	fileOverwriteConfirmDialogBox->setBounds(getLocalBounds());
	fileOverwriteConfirmDialogBox->grabKeyboardFocus();
}

void ExportVoiceDataComponent::writeVoiceDataIntoFile(File& file) {
	FileOutputStream outStream{ file };
	if (outStream.openedOk()) {
		outStream.setPosition(0);
		outStream.truncate();
		auto slot{ slotsComponent->selectedSlot };
		auto voicesBank{ unexposedParams->voicesBank_get() };
		auto voiceDataHexString{ voicesBank->getVoiceDataHexStringFromSlot(slot) };
		outStream.writeText(voiceDataHexString, false, false, nullptr);
		hideThisComponent();
	}
}

ExportVoiceDataComponent::~ExportVoiceDataComponent() {
	if (fileOverwriteConfirmDialogBox != nullptr)
		fileOverwriteConfirmDialogBox->removeListenerFromButtons(this);
	fileOverwriteConfirmDialogBox = nullptr;
}
