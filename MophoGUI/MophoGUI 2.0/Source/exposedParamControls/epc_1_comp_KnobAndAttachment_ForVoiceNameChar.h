#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class KnobAndAttachment_ForVoiceNameChar :
	public Component
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	RotarySliderWithMouseWheelMoveOverride knob;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;

public:
	KnobAndAttachment_ForVoiceNameChar() = delete;

	KnobAndAttachment_ForVoiceNameChar(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void paint(Graphics& g) override;
	void attachKnobToExposedParameter();
	void limitKnobRangeToBasic_ASCII_CharsThatAreVisible();
	void deleteAttachmentBeforeKnobToPreventMemLeak();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KnobAndAttachment_ForVoiceNameChar)
};