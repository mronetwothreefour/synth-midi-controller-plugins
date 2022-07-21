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
	public Value::Listener
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	RotarySliderWithMouseDownModForSeqStep knob;
	std::unique_ptr<SliderAttachment> knobAttachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;
	const Identifier trackDestID;
	Value trackDestValue;

public:
	KnobAndAttachment_ForSeqStep() = delete;

	KnobAndAttachment_ForSeqStep(uint8 paramIndex, Track track, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void paintResetSequenceArrow(Graphics& g);
	void paintTrack1RestDot(Graphics& g);
	void paintChoiceNameString(Graphics& g, String stepChoiceName);
	void attachKnobToExposedParameter();
	void setKnobIsModifyingPitch(bool isModifyingPitch);
	void valueChanged(Value& value) override;
	void deleteAttachmentBeforeKnobToPreventMemLeak();
	~KnobAndAttachment_ForSeqStep();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForSeqStep)
};