#pragma once

#include <JuceHeader.h>

#include "imEx_2_gui_layer_ImportExport_Base.h"

class GUI_Layer_FileOverwriteDialog;
class TooltipsOptions;
class VoicesBank;
class VoiceSlots;
class UnexposedParameters;

class GUI_Layer_Export_Voice :
	public GUI_Layer_ImportExport_Base,
	public Button::Listener
{
	VoicesBank* voicesBank;
	std::unique_ptr<GUI_Layer_FileOverwriteDialog> fileOverwriteDialog;

public:
	GUI_Layer_Export_Voice() = delete;

	GUI_Layer_Export_Voice(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void okButtonClicked() override;
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