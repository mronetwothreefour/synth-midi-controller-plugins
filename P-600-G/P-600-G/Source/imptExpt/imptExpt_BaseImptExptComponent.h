#pragma once

#include <JuceHeader.h>

#include "imptExpt_FileFilters.h"



enum class ImptExptType {
	exportVoice,
	exportVoicesBank,
	importVoice,
	importVoicesBank
};




class FileNotValidAlert;
class FolderNameDialogBox;
class VoiceSlotsComponent;
class UnexposedParameters;

class BaseImportExportComponent  :
	public Component,
	private FileBrowserListener
{
protected:
	ImptExptType type;
	VoiceSlotsComponent* slotsComponent;
	UnexposedParameters* unexposedParams;
	TextButton button_NewFolder;
	TextButton button_Esc;
	TextButton button_OK;
	std::unique_ptr<FileBrowserComponent> browserComponent;
	VoiceDataFileFilter voiceDataFileFilter;
	VoicesBankFileFilter voicesBankFileFilter;
	std::unique_ptr<FolderNameDialogBox> folderNameDialogBox;
	std::unique_ptr<FileNotValidAlert> fileNotValidAlert;

public:
	BaseImportExportComponent() = delete;

	BaseImportExportComponent(ImptExptType type, VoiceSlotsComponent* slotsComponent, UnexposedParameters* unexposedParams);
	void resized() override;

protected:
	void drawBackgroundImage(Graphics& g);
	void selectionChanged() override;
	void fileClicked(const File& file, const MouseEvent& mouseEvent) override;
	void fileDoubleClicked(const File& file) override;
	void browserRootChanged(const File& file) override;
	void showFolderNameDialogBox();
	virtual void okButtonClicked() = 0;
	File createFileToWriteTo(File& file);
	void showFileIsNotValidAlert();
	void hideThisComponent();

public:
	~BaseImportExportComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(BaseImportExportComponent)
};