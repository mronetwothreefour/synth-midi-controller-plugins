#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_LockToggleForParam.h"
#include "rndm_0_comp_TransmitTypeToggles.h"
#include "rndm_3_gui_layer_AllowedChoicesServer.h"
#include "../constants/constants_ExposedParameters.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;
using ExposedParameters = AudioProcessorValueTreeState;



class ParamRandomizationMethods;
class RandomizationOptions;
class UnexposedParameters;

class GUI_Layer_Randomization :
	public Component,
	public Button::Listener
{
	ExposedParameters* exposedParams;
	RandomizationOptions* randomization;
	ParamRandomizationMethods* randomize;
	ButtonForHidingLayer button_Close;
	TransmitTypeToggles transmitType;
	std::unique_ptr<LockToggleForParam> paramLockToggles[EP::numberOfExposedParams];
	GUI_Layer_AllowedChoicesServer allowedChoicesLayers;
	bool toggleWasRightClicked{ false };

public:
	GUI_Layer_Randomization() = delete;

	GUI_Layer_Randomization(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams, ParamRandomizationMethods* randomize);
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	~GUI_Layer_Randomization();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Randomization)
};