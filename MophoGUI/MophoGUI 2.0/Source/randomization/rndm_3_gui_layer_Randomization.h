#pragma once

#include <JuceHeader.h>

#include "../constants/constants_ExposedParameters.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;
using ExposedParameters = AudioProcessorValueTreeState;



class ParamRandomizationMethods;
class RandomizationOptions;
class UnexposedParameters;

class GUI_Layer_Randomization :
	public Component
{
	ExposedParameters* exposedParams;
	RandomizationOptions* randomization;
	ParamRandomizationMethods* randomize;
	ButtonForHidingLayer button_Close;

public:
	GUI_Layer_Randomization() = delete;

	GUI_Layer_Randomization(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, ParamRandomizationMethods* randomize);
	void paint(Graphics& g) override;
	~GUI_Layer_Randomization();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Randomization)
};