#pragma once

#include <JuceHeader.h>

#include "imEx_2_gui_layer_ImportExport_Base.h"

class VoicesBank;
class VoiceSlots;
class UnexposedParameters;

class GUI_Layer_Import_VoicesBank :
	public GUI_Layer_ImportExport_Base
{
	VoicesBank* voicesBank;

public:
	GUI_Layer_Import_VoicesBank() = delete;

	GUI_Layer_Import_VoicesBank(VoiceSlots* voiceSlots, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	void okButtonClicked() override;
	void importVoiceDataFromStringArray(StringArray stringArray);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Import_VoicesBank)
};