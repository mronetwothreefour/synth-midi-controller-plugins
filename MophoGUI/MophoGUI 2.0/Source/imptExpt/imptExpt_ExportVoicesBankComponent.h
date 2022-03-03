#pragma once

#include <JuceHeader.h>

#include "imptExpt_BaseImptExptComponent.h"


class FileOverwriteConfirmDialogBox;
class VoiceSlotsComponent;
class UnexposedParameters;

class ExportVoicesBankComponent :
	public BaseImportExportComponent,
	public Button::Listener
{
	std::unique_ptr<FileOverwriteConfirmDialogBox> fileOverwriteConfirmDialogBox;

public:
	ExportVoicesBankComponent() = delete;

	explicit ExportVoicesBankComponent(VoicesBank bank, VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void buttonClicked(Button* button) override;

private:
	void okButtonClicked();
	void showFileOverwriteConfirmDialogBox();
	void writeVoicesBankDataIntoFile(File& file);

public:
	~ExportVoicesBankComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExportVoicesBankComponent)
};