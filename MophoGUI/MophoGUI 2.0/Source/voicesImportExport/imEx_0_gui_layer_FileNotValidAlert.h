#pragma once

#include <JuceHeader.h>

#include "../gui/gui_comp_ButtonForHidingLayer.h"



class UnexposedParameters;

class GUI_Layer_FileNotValidAlert :
	public Component
{
	ButtonForHidingLayer button_Close;

public:
	GUI_Layer_FileNotValidAlert(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_FileNotValidAlert)
};