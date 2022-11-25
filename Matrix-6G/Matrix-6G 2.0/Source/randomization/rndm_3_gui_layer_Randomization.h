#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_LockToggle_ExposedParam.h"
#include "rndm_0_comp_LockToggle_MatrixModParam.h"
#include "rndm_0_comp_TransmitMethodComboBox.h"
#include "rndm_1_comp_GroupLockStateButtons.h"
#include "rndm_2_gui_layer_AllowedChoices_ExposedParam.h"
#include "rndm_2_gui_layer_AllowedChoices_MatrixModParam.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_MatrixMod.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace Matrix_6G_Constants;

class ExposedParameters;
class ParamRandomizationOptions;
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
	ParamRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	Outgoing_MIDI_Buffers* outgoingBuffers;
	ButtonForHidingLayer btn_Close;
	TransmitMethodComboBox transmitMethod;
	std::unique_ptr<LockToggle_ExposedParam> lockToggles_ExposedParams[EP::numberOfExposedParams];
	std::unique_ptr<LockToggle_MatrixModParam> lockToggles_MatrixModParams[MMOD::numberOfModulators * 3];
	std::unique_ptr<GUI_Layer_AllowedChoices_ExposedParam> allowedChoices_ExposedParam;
	std::unique_ptr<GUI_Layer_AllowedChoices_MatrixModParam> allowedChoices_MatrixModParam;
	GroupLockStateButtons lockStateButtons_All;
	GroupLockStateButtons lockStateButtons_Osc;
	GroupLockStateButtons lockStateButtons_VCF;
	GroupLockStateButtons lockStateButtons_VCA;
	GroupLockStateButtons lockStateButtons_VCF_FM;
	GroupLockStateButtons lockStateButtons_Portamento;
	GroupLockStateButtons lockStateButtons_LFO;
	GroupLockStateButtons lockStateButtons_Ramp;
	GroupLockStateButtons lockStateButtons_Tracking;
	GroupLockStateButtons lockStateButtons_Envelope_1;
	GroupLockStateButtons lockStateButtons_Envelope_2;
	GroupLockStateButtons lockStateButtons_Envelope_3;
	GroupLockStateButtons lockStateButtons_MatrixMod;
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