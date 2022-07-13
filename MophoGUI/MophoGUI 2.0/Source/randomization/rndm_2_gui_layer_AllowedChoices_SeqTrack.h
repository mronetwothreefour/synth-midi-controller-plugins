#pragma once

#include <JuceHeader.h>

#include "rndm_0_comp_AllowRepeatChoicesToggle_SeqTrackStep.h"
#include "rndm_0_comp_RandomizeButtonForAllowedChoices_SeqTrack.h"
#include "rndm_0_comp_SeqTrackTargetStep.h"
#include "rndm_1_comp_AllowChoiceToggles_SeqTrackStep.h"
#include "rndm_1_comp_SeqTrackProbabilities.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_ButtonForHidingLayer.h"

using namespace MophoConstants;
using Step = SeqTrackStepNum;
using Track = SeqTrackNum;



class ExposedParameters;
class ExposedParamsRandomizationOptions;
class UnexposedParameters;

class GUI_Layer_AllowedChoices_SeqTrack :
	public Component,
	public ValueTree::Listener
{
	Track track;
	bool destIsPitched;
	UnexposedParameters* unexposedParams;
	ExposedParamsRandomizationOptions* randomization;
	ValueTree trackTree;
	TextButton button_AllowAll;
	std::unique_ptr<AllowRepeatChoicesToggle_SeqTrackStep> repeatChoices;
	ButtonForHidingLayer button_Close;
	SeqTrackTargetStep targetStepSelector;
	SeqTrackProbabilities probabilities;
	std::unique_ptr <AllowChoiceToggles_SeqTrackStep> allowChoiceToggles;
	RandomizeButtonForAllowedChoices_SeqTrack button_Randomize;
	int background_x;
	int background_y;
	int background_w;
	int background_h;
	int center_x;

public:
	GUI_Layer_AllowedChoices_SeqTrack() = delete;

	GUI_Layer_AllowedChoices_SeqTrack(Track track, bool destIsPitched, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

private:
	void resetToggles();

public:
	void paint(Graphics& g) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~GUI_Layer_AllowedChoices_SeqTrack();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_AllowedChoices_SeqTrack)
};