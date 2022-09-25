#pragma once

#include <JuceHeader.h>

class GUI_Layer_FolderExistsAlert;
class TooltipsOptions;

class GUI_Layer_NewFolderDialog :
	public Component
{
	TooltipsOptions* tooltips;
	FileBrowserComponent* browserComponent;
	TextEditor lbl_FolderNameEditor;
	TextButton btn_Cancel;
	TextButton btn_Create;
	std::unique_ptr<GUI_Layer_FolderExistsAlert> folderExistsAlert;

public:
	GUI_Layer_NewFolderDialog() = delete;

	GUI_Layer_NewFolderDialog(FileBrowserComponent* browserComponent, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;

private:
	void createNewFolder();
	void showFolderExistsAlert();
	void hideThisLayer();

public:
	~GUI_Layer_NewFolderDialog();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_NewFolderDialog)
};