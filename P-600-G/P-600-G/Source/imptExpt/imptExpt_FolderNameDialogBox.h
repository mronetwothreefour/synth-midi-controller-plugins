#pragma once

#include <JuceHeader.h>

#include "imptExpt_FolderExistsAlert.h"



class UnexposedParameters;

class FolderNameDialogBox :
	public Component
{
	FileBrowserComponent* browserComponent;
	TextEditor label_FolderName;
	TextButton button_Esc;
	TextButton button_OK;
	std::unique_ptr<FolderExistsAlert> folderExistsAlert;

public:
	FolderNameDialogBox(FileBrowserComponent* browserComponent, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;

private:
	void createNewFolder();
	void showFolderExistsAlert();
	void hideThisComponent();

public:
	~FolderNameDialogBox();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FolderNameDialogBox)
};