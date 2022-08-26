#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../constants/constants_Enum.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using namespace MophoConstants;
using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;
using Track = SeqTrackNum;

class KnobAndAttachment_ForSeqStep :
	public Component
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	RotarySliderWithMouseDownModForSeqStep knob;
	std::unique_ptr<SliderAttachment> knobAttachment;
	Slider trackDestination;
	std::unique_ptr<SliderAttachment> trackDestinationAttachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;
	std::unique_ptr<Label> textEditor;
	const Identifier trackDestID;

public:
	KnobAndAttachment_ForSeqStep() = delete;

	KnobAndAttachment_ForSeqStep(const uint8 paramIndex, const Track track, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void paintResetSequenceArrow(Graphics& g);
	void paintTrack1RestDot(Graphics& g);
	void paintChoiceNameString(Graphics& g, String stepChoiceName);
	void mouseDoubleClick(const MouseEvent& event) override;
	void attachKnobsToExposedParameters();
	void setEditorText();
	void setKnobIsModifyingPitch(bool isModifyingPitch);
	void deleteAttachmentsBeforeKnobsToPreventMemLeaks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForSeqStep)
};