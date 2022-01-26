#pragma once

#include <JuceHeader.h>

#include "imptExpt_FileFilters.h"



class FileNotValidAlert;
class UnexposedParameters;

class ImportProgramDataComponent :
	public Component,
	private FileBrowserListener
{
	uint8 slot;
	UnexposedParameters* unexposedParams;
	TextButton button_Esc;
	TextButton button_OK;
	std::unique_ptr<FileBrowserComponent> browserComponent;
	ProgramDataFileFilter pgmDataFileFilter;
	std::unique_ptr<FileNotValidAlert> fileNotValidAlert;

public:
	ImportProgramDataComponent() = delete;

	ImportProgramDataComponent(uint8 slot, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;

private:
	void selectionChanged() override;
	void fileClicked(const File& file, const MouseEvent& mouseEvent) override;
	void fileDoubleClicked(const File& file) override;
	void browserRootChanged(const File& file) override;
	void okButtonClicked();
	void showFileNotValidAlert();
	void importProgramDataFromString(String incomingString);
	void hideThisComponent();

public:
	~ImportProgramDataComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ImportProgramDataComponent)
};