#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TextEditorForExposedParamSlider.h"
#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class SliderAndAttachment :
	public Component
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	RotarySliderWithMouseWheelMoveOverride slider;
	std::unique_ptr<SliderAttachment> attachment;
	TextEditorForExposedParamSlider textEditor;
	TooltipUpdaterForExposedParamControl tooltipUpdater;
	const int slider_w;

public:
	SliderAndAttachment() = delete;

	SliderAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void mouseDoubleClick(const MouseEvent& event) override;
	void attachSliderToExposedParameter();
	void setKnobIsModifyingPitch(bool isModifyingPitch);
	void deleteAttachmentBeforeSliderToPreventMemLeak();
	~SliderAndAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderAndAttachment)
};