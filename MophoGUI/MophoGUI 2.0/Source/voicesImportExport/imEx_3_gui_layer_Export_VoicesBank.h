#pragma once

#include <JuceHeader.h>

#include "imEx_2_gui_layer_ImportExport_Base.h"

class GUI_Layer_FileOverwriteDialog;
class VoiceSlots;
class UnexposedParameters;

class GUI_Layer_Export_VoicesBank :
	public GUI_Layer_ImportExport_Base,
	public Button::Listener
{
	std::unique_ptr<GUI_Layer_FileOverwriteDialog> fileOverwriteDialog;

public:
	GUI_Layer_Export_VoicesBank() = delete;

	explicit GUI_Layer_Export_VoicesBank(VoicesBank bank, VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void proceedButtonClicked() override;
	void showFileOverwriteDialog();

public:
	void buttonClicked(Button* button) override;

private:
	void writeVoicesBankDataIntoFile(File& file);

public:
	~GUI_Layer_Export_VoicesBank();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Export_VoicesBank)
};