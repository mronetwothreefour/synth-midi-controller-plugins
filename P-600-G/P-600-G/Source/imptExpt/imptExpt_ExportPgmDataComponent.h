#pragma once

#include <JuceHeader.h>

#include "imptExpt_FileFilters.h"



class ProgramDataSlotsComponent;
class UnexposedParameters;

class ExportProgramDataComponent :
	public Component,
	private FileBrowserListener
{
	uint8 slot;
	UnexposedParameters* unexposedParams;
	Label label_Title;
	TextButton button_NewFolder;
	TextButton button_Esc;
	TextButton button_OK;
	std::unique_ptr<FileBrowserComponent> browserComponent;
	ProgramDataFileFilter pgmDataFileFilter;

public:
	ExportProgramDataComponent() = delete;

	ExportProgramDataComponent(uint8 slot, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;

private:
	void selectionChanged() override;
	void fileClicked(const File&, const MouseEvent&) override;
	void fileDoubleClicked(const File&) override;
	void browserRootChanged(const File&) override;
	void createNewFolder();
	void okButtonClicked();
	void hideThisComponent();

public:
	~ExportProgramDataComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ExportProgramDataComponent)
};