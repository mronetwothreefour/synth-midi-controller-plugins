#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_LockToggleForParam.h"
#include "rndm_1_comp_GroupLockStateButtons.h"
#include "rndm_2_gui_layer_AllowedChoices_Binary.h"
#include "rndm_2_gui_layer_AllowedChoices_FilterKeyTrack.h"
#include "rndm_2_gui_layer_AllowedChoices_Numeric.h"
#include "rndm_2_gui_layer_AllowedChoices_OscPitch.h"
#include "../constants/constants_ExposedParameters.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace P_600_G_Constants;

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class Outgoing_MIDI_Buffers;
class TooltipsOptions;

class GUI_Layer_Randomization :
	public Component,
	public Button::Listener
{
	AudioProcessorValueTreeState* state;
	ExposedParameters* exposedParams;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	ButtonForHidingLayer btn_Exit;
	std::unique_ptr<LockToggleForParam> lockTogglesForParams[EP::numberOfExposedParams];
	std::unique_ptr<GUI_Layer_AllowedChoices_Binary> allowedChoices_Binary;
	std::unique_ptr<GUI_Layer_AllowedChoices_FilterKeyTrack> allowedChoices_FilterKeyTrack;
	std::unique_ptr<GUI_Layer_AllowedChoices_Numeric> allowedChoices_Numeric;
	std::unique_ptr<GUI_Layer_AllowedChoices_OscPitch> allowedChoices_OscPitch;
	GroupLockStateButtons lockStateButtons_All;
	GroupLockStateButtons lockStateButtons_Osc_A;
	GroupLockStateButtons lockStateButtons_Osc_B;
	GroupLockStateButtons lockStateButtons_Filter;
	GroupLockStateButtons lockStateButtons_Amp;
	GroupLockStateButtons lockStateButtons_PolyMod;
	GroupLockStateButtons lockStateButtons_LFO;
	TextButton btn_RandomizeAllUnlocked;
	bool toggleWasRightClicked{ false };

public:
	GUI_Layer_Randomization() = delete;

	GUI_Layer_Randomization(ExposedParameters* exposedParams, TooltipsOptions* tooltips, Outgoing_MIDI_Buffers* outgoingBuffers);
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	~GUI_Layer_Randomization();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Randomization)
};