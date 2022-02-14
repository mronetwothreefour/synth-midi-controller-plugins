#pragma once

#include <JuceHeader.h>

#include "imptExpt_BaseImptExptComponent.h"


class FileOverwriteConfirmDialogBox;
class VoiceSlotsComponent;
class UnexposedParameters;

class ExportProgramDataBankComponent :
	public BaseImportExportComponent,
	public Button::Listener
{
	std::unique_ptr<FileOverwriteConfirmDialogBox> fileOverwriteConfirmDialogBox;

public:
	ExportProgramDataBankComponent() = delete;

	explicit ExportProgramDataBankComponent(VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void buttonClicked(Button* button) override;

private:
	void okButtonClicked();
	void showFileOverwriteConfirmDialogBox();
	void writeProgramBankDataIntoFile(File& file);

public:
	~ExportProgramDataBankComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExportProgramDataBankComponent)
};