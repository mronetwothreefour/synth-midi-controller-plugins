#pragma once

#include <JuceHeader.h>



class FolderExistsAlert;
class UnexposedParameters;

class FolderNameDialogBox :
	public Component
{
	FileBrowserComponent* browserComponent;
	TextEditor label_FolderName;
	TextButton button_Cancel;
	TextButton button_Create;
	std::unique_ptr<FolderExistsAlert> folderExistsAlert;

public:
	FolderNameDialogBox() = delete;

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