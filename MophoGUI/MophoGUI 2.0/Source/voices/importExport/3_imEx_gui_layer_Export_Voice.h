#pragma once

#include <JuceHeader.h>

#include "2_imEx_gui_layer_ImportExport_Base.h"


class GUI_Layer_FileOverwriteDialog;
class VoiceSlots;
class UnexposedParameters;

class GUI_Layer_Export_Voice :
	public GUI_Layer_ImportExport_Base,
	public Button::Listener
{
	std::unique_ptr<GUI_Layer_FileOverwriteDialog> fileOverwriteDialog;

public:
	GUI_Layer_Export_Voice() = delete;

	GUI_Layer_Export_Voice(VoicesBank bank, VoiceSlots * voiceSlots, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void proceedButtonClicked() override;
	void showFileOverwriteDialog();

public:
	void buttonClicked(Button* button) override;

private:
	void writeVoiceDataIntoFile(File& file);

public:
	~GUI_Layer_Export_Voice();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Export_Voice)
};