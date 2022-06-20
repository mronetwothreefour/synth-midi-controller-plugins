#pragma once

#include <JuceHeader.h>

#include "global_0_gui_layer_CommError_Base.h"



class UnexposedParameters;

class GUI_Layer_CommError_SysEx :
	public GUI_Layer_CommError_Base
{
public:
	GUI_Layer_CommError_SysEx() = delete;

	explicit GUI_Layer_CommError_SysEx(UnexposedParameters* unexposedParams);

private:
	void checkHardwareSettings() override;

public:
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CommError_SysEx)
};

