#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_LockToggleForParam.h"
#include "rndm_0_comp_TransmitTypeToggles.h"
#include "rndm_1_comp_GroupLockStateButtons.h"
#include "rndm_3_gui_layer_AllowedChoicesServer.h"
#include "../constants/constants_ExposedParameters.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;



class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class UnexposedParameters;

class GUI_Layer_Randomization :
	public Component,
	public Button::Listener
{
	AudioProcessorValueTreeState* state;
	ExposedParameters* exposedParams;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	ButtonForHidingLayer button_Close;
	TransmitTypeToggles transmitType;
	std::unique_ptr<LockToggleForParam> paramLockToggles[EP::numberOfExposedParams];
	GUI_Layer_AllowedChoicesServer allowedChoicesLayers;
	GroupLockStateButtons lockStateButtons_All;
	GroupLockStateButtons lockStateButtons_Osc;
	GroupLockStateButtons lockStateButtons_LPF;
	GroupLockStateButtons lockStateButtons_VCA;
	GroupLockStateButtons lockStateButtons_LFO_1;
	GroupLockStateButtons lockStateButtons_LFO_2;
	GroupLockStateButtons lockStateButtons_LFO_3;
	GroupLockStateButtons lockStateButtons_LFO_4;
	GroupLockStateButtons lockStateButtons_Env_3;
	GroupLockStateButtons lockStateButtons_Modulators;
	GroupLockStateButtons lockStateButtons_MIDI_Controllers;
	GroupLockStateButtons lockStateButtons_PushIt;
	GroupLockStateButtons lockStateButtons_KnobAssign;
	GroupLockStateButtons lockStateButtons_SeqTrack_1;
	GroupLockStateButtons lockStateButtons_SeqTrack_2;
	GroupLockStateButtons lockStateButtons_SeqTrack_3;
	GroupLockStateButtons lockStateButtons_SeqTrack_4;
	GroupLockStateButtons lockStateButtons_VoiceNamerChars;
	bool toggleWasRightClicked{ false };

public:
	GUI_Layer_Randomization() = delete;

	GUI_Layer_Randomization(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void mouseDown(const MouseEvent& event) override;
	void buttonClicked(Button* button) override;
	~GUI_Layer_Randomization();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_Randomization)
};