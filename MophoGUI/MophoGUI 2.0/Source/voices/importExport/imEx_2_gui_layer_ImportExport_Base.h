#pragma once

#include <JuceHeader.h>

#include "imEx_0_FileFilters.h"
#include "../../constants/constants_Enum.h"
#include "../voices_1_tree_VoicesBanks.h"



class GUI_Layer_FileNotValidAlert;
class GUI_Layer_NewFolderDialog;
class UnexposedParameters;
class VoiceSlots;

class GUI_Layer_ImportExport_Base :
	public Component,
	private FileBrowserListener
{
protected:
	ImportExportType type;
	VoicesBank bank;
	VoiceSlots* voiceSlots;
	UnexposedParameters* unexposedParams;
	TextButton button_NewFolder;
	TextButton button_Cancel;
	TextButton button_Proceed;
	std::unique_ptr<FileBrowserComponent> browserComponent;
	VoiceDataFileFilter voiceDataFileFilter;
	VoicesBankFileFilter voicesBankFileFilter;
	std::unique_ptr<GUI_Layer_NewFolderDialog> newFolderDialog;
	std::unique_ptr<GUI_Layer_FileNotValidAlert> fileNotValidAlert;
	const int importExportBackground_x{ 386 };
	const int importExportBackground_y{ 147 };

public:
	GUI_Layer_ImportExport_Base() = delete;

	GUI_Layer_ImportExport_Base(ImportExportType type, VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams);
	void resized() override;

protected:
	void drawBackgroundImage(Graphics& g);
	void selectionChanged() override;
	void fileClicked(const File& file, const MouseEvent& mouseEvent) override;
	void fileDoubleClicked(const File& file) override;
	void browserRootChanged(const File& file) override;
	void showNewFolderDialog();
	virtual void proceedButtonClicked() = 0;
	File createFileToWriteTo(File& file);
	void showFileIsNotValidAlert();
	void hideThisLayer();

public:
	~GUI_Layer_ImportExport_Base();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_ImportExport_Base)
};