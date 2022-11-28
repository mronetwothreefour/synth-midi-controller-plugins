#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesComboBox_MatrixModParam.h"
#include "rndm_0_comp_RandomizeButton_MatrixModParam.h"
#include "rndm_1_comp_AllowChoiceToggles_MatrixModParam.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace Matrix_6G_Constants;
using MM_Type = MatrixModParamType;

class ExposedParameters;
class InfoForExposedParameters;
class MatrixModOptions;
class Outgoing_MIDI_Buffers;
class TooltipsOptions;

class GUI_Layer_AllowedChoices_MatrixModParam :
	public Component
{
	int modNum;
	MM_Type paramType;
	MatrixModOptions* matrixModOptions;
	ButtonForHidingLayer btn_Close;
	AllowRepeatChoicesComboBox_MatrixModParam comboBox_Repeats;
	AllowChoiceToggles_MatrixModParam allowChoiceToggles;
	TextButton btn_AllowAll;
	RandomizeButton_MatrixModParam btn_Randomize;
	const int background_x;
	const int background_y;
	const int background_w;
	const int background_h;
	const int modDestOffset;

public:
	GUI_Layer_AllowedChoices_MatrixModParam() = delete;

	GUI_Layer_AllowedChoices_MatrixModParam(
		int modNum, MM_Type paramType, ExposedParameters* exposedParams, TooltipsOptions* tooltips, Outgoing_MIDI_Buffers* outgoingBuffers);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_MatrixModParam)
};