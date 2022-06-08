#pragma once

#include <JuceHeader.h>

#include "../gui/gui_comp_ButtonForHidingLayer.h"



class UnexposedParameters;

class GUI_Layer_CommError_Base :
	public Component,
	private Timer
{
protected:
	UnexposedParameters* unexposedParams;
	ButtonForHidingLayer button_Close;
	TextButton button_RequestGlobalParamsDump;

public:
	GUI_Layer_CommError_Base() = delete;

	explicit GUI_Layer_CommError_Base(UnexposedParameters* unexposedParams);

private:
	void requestGlobalParamsDump();

protected:
	virtual void checkHardwareSettings() = 0;

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CommError_Base)
};

