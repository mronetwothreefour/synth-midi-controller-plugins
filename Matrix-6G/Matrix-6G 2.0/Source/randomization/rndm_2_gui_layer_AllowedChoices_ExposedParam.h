#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesComboBox_ExposedParam.h"
#include "rndm_0_comp_RandomizeButton_ExposedParam.h"
#include "rndm_1_comp_AllowChoiceToggles_ExposedParam.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

class ExposedParameters;
class InfoForExposedParameters;
class UnexposedParameters;

class GUI_Layer_AllowedChoices_ExposedParam :
	public Component
{
	uint8 paramIndex;
	ExposedParameters* exposedParams;
	InfoForExposedParameters* info;
	ButtonForHidingLayer btn_Close;
	AllowRepeatChoicesComboBox_ExposedParam comboBox_Repeats;
	AllowChoiceToggles_ExposedParam allowChoiceToggles;
	TextButton btn_AllowAll;
	RandomizeButton_ExposedParam btn_Randomize;
	bool childrenShouldBeStackedVertically;
	const int background_x;
	const int background_y;
	int background_w;
	int background_h;

public:
	GUI_Layer_AllowedChoices_ExposedParam() = delete;

	GUI_Layer_AllowedChoices_ExposedParam(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_ExposedParam)
};