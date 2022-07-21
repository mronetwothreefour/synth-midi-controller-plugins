#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using namespace MophoConstants;
using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;
using Track = SeqTrackNum;

class KnobAndAttachment_ForSeqStep :
	public Component,
	public Slider::Listener
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	RotarySliderWithMouseDownModForSeqStep knob;
	std::unique_ptr<SliderAttachment> knobAttachment;
	Slider trackDestination;
	std::unique_ptr<SliderAttachment> trackDestinationAttachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;
	const Identifier trackDestID;

public:
	KnobAndAttachment_ForSeqStep() = delete;

	KnobAndAttachment_ForSeqStep(const uint8 paramIndex, const Track track, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void paintResetSequenceArrow(Graphics& g);
	void paintTrack1RestDot(Graphics& g);
	void paintChoiceNameString(Graphics& g, String stepChoiceName);
	void attachKnobsToExposedParameters();
	void setKnobIsModifyingPitch(bool isModifyingPitch);
	void sliderValueChanged(Slider* slider) override;
	void deleteAttachmentsBeforeKnobsToPreventMemLeaks();
	~KnobAndAttachment_ForSeqStep();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForSeqStep)
};