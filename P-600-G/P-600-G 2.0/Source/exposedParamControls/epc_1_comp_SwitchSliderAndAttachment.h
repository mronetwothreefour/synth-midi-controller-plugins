#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class SwitchSliderAndAttachment :
	public Component
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	LinearSliderWithMouseWheelMoveOverride switchSlider;
	std::unique_ptr<SliderAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;

public:
	SwitchSliderAndAttachment() = delete;

	SwitchSliderAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void attachSwitchSliderToExposedParameter();
	void deleteAttachmentBeforeSwitchSliderToPreventMemLeak();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SwitchSliderAndAttachment)
};