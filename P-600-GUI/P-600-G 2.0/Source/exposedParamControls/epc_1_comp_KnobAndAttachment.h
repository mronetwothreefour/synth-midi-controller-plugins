#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TextEditorForExposedParamKnob.h"
#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class KnobAndAttachment :
	public Component
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	RotarySliderWithMouseWheelMoveOverride knob;
	std::unique_ptr<SliderAttachment> attachment;
	TextEditorForExposedParamKnob textEditor;
	TooltipUpdaterForExposedParamControl tooltipUpdater;

public:
	KnobAndAttachment() = delete;

	KnobAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void mouseDoubleClick(const MouseEvent& event) override;
	void attachKnobToExposedParameter();
	void setKnobIsModifyingPitch(bool isModifyingPitch);
	void deleteAttachmentBeforeKnobToPreventMemLeak();
	~KnobAndAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment)
};