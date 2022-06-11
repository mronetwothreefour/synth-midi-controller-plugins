#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoicesLayers.h"
#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Pitched.h"
#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Synced.h"
#include "rndm_1_comp_AllowChoiceToggles_LFO_Freq_Unsynced.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;
using Category = LFO_FreqCategory;



class UnexposedParameters;

class GUI_Layer_AllowedChoices_LFO_Freq :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	TextButton button_AllowAll;
	AllowRepeatChoicesToggle repeatValues;
	ButtonForHidingLayer button_Close;
	ToggleButton toggle_Unsynced;
	ToggleButton toggle_Pitched;
	ToggleButton toggle_Synced;
	AllowChoiceToggles_LFO_Freq_Unsynced allowUnsyncedFreqToggles;
	AllowChoiceToggles_LFO_Freq_Pitched allowPitchedFreqToggles;
	AllowChoiceToggles_LFO_Freq_Synced allowSyncedFreqToggles;
	RandomizeButtonForAllowedChoicesLayers button_Randomize;
	const int numberOfUnsyncedRows{ 9 };
	const int numberOfPitchedRows{ 12 };
	const int numberOfSyncedRows{ 8 };
	const int unsyncedFreqToggle_w{ 20 };
	const int pitchedFreqToggle_w{ 36 };
	const int syncedFreqToggle_w{ 100 };
	const int background_x;
	const int background_y;
	const int background_w{ 668 };
	const int background_h{ 315 };

public:
	GUI_Layer_AllowedChoices_LFO_Freq() = delete;

	GUI_Layer_AllowedChoices_LFO_Freq(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void makeCategoryTheOnlyOneAllowed(Category allowedCategory);
	void allowAllChoices();
	~GUI_Layer_AllowedChoices_LFO_Freq();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_LFO_Freq)
};