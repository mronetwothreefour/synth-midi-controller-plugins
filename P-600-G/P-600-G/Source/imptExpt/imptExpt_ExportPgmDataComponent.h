#pragma once

#include <JuceHeader.h>

#include "imptExpt_FileFilters.h"


class FileOverwriteConfirmDialogBox;
class FolderNameDialogBox;
class UnexposedParameters;

class ExportProgramDataComponent :
	public Component,
	public Button::Listener,
	private FileBrowserListener
{
	uint8 slot;
	UnexposedParameters* unexposedParams;
	TextButton button_NewFolder;
	TextButton button_Esc;
	TextButton button_OK;
	std::unique_ptr<FileBrowserComponent> browserComponent;
	ProgramDataFileFilter pgmDataFileFilter;
	std::unique_ptr<FolderNameDialogBox> folderNameDialogBox;
	std::unique_ptr<FileOverwriteConfirmDialogBox> fileOverwriteConfirmDialogBox;

public:
	ExportProgramDataComponent() = delete;

	ExportProgramDataComponent(uint8 slot, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;

private:
	void selectionChanged() override;
	void fileClicked(const File& file, const MouseEvent& mouseEvent) override;
	void fileDoubleClicked(const File& file) override;
	void browserRootChanged(const File& file) override;
	void showFolderNameDialogBox();
	void okButtonClicked();
	void showFileOverwriteConfirmDialogBox();
	File createFileToWriteTo(File& file);
	void writeProgramDataIntoFile(File& file);
	void hideThisComponent();

public:
	~ExportProgramDataComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExportProgramDataComponent)
};