#pragma once

#include <JuceHeader.h>

#include "epc_0_slider_JuceSlidersWithMouseMods.h"
#include "../epc_0_comp_TooltipUpdaterForExposedParamControl.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;



class KnobAndAttachment_ForSeqStep :
	public Component,
	public Slider::Listener
	// Note: listening to a slider with an exposed parameter attachment is
	// much, much faster than listening directly to an exposed parameter
{
	uint8 paramIndex;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseDownModForSeqStep knob;
	std::unique_ptr<SliderAttachment> knobAttachment;
	Slider trackDestination;
	std::unique_ptr<SliderAttachment> trackDestinationAttachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;
	int choiceNum;
	uint8 trackDestIndex;

public:
	KnobAndAttachment_ForSeqStep() = delete;

	KnobAndAttachment_ForSeqStep(uint8 paramIndex, int trackNum, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void paintResetSequenceArrow(Graphics& g);
	void paintTrack1RestDot(Graphics& g);
	void paintChoiceNameString(Graphics& g, String stepChoiceName);
	void attachKnobsToExposedParameters();
	void setKnobIsModifyingPitch();
	void setKnobIsNotModifyingPitch();
	void sliderValueChanged(Slider* slider) override;
	void deleteAttachmentsBeforeKnobsToPreventMemLeaks();
	~KnobAndAttachment_ForSeqStep();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForSeqStep)
};