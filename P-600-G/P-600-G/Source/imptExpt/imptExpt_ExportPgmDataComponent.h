#pragma once

#include <JuceHeader.h>

#include "imptExpt_BaseImptExptComponent.h"


class FileOverwriteConfirmDialogBox;
class VoiceSlotsComponent;
class UnexposedParameters;

class ExportProgramDataComponent :
	public BaseImportExportComponent,
	public Button::Listener
{
	std::unique_ptr<FileOverwriteConfirmDialogBox> fileOverwriteConfirmDialogBox;

public:
	ExportProgramDataComponent() = delete;

	ExportProgramDataComponent(VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void buttonClicked(Button* button) override;

private:
	void okButtonClicked() override;
	void showFileOverwriteConfirmDialogBox();
	void writeProgramDataIntoFile(File& file);

public:
	~ExportProgramDataComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExportProgramDataComponent)
};