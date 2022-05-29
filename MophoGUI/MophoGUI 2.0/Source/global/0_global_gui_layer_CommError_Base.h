#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class GUI_Layer_CommError_Base :
	public Component,
	private Timer
{
protected:
	UnexposedParameters* unexposedParams;
	TextButton button_Close;
	TextButton button_RequestGlobalParamsDump;

public:
	GUI_Layer_CommError_Base() = delete;

	explicit GUI_Layer_CommError_Base(UnexposedParameters* unexposedParams);

private:
	void requestGlobalParamsDump();

protected:
	virtual void checkHardwareSettings() = 0;
	void hideThisLayer();

private:
	void timerCallback() override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_CommError_Base)
};

