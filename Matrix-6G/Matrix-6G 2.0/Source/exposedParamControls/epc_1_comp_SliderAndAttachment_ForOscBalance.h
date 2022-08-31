#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TextEditorForExposedParamSlider.h"
#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"
#include "../gui/gui_comp_JuceSlidersWithMouseMods.h"

using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

class SliderAndAttachment_ForOscBalance :
	public Component
{
	const uint8 paramIndex;
	AudioProcessorValueTreeState* state;
	LinearSliderWithMouseWheelMoveOverrideAndInvertedRange slider;
	std::unique_ptr<SliderAttachment> attachment;
	TextEditorForExposedParamSlider textEditor;
	TooltipUpdaterForExposedParamControl tooltipUpdater;

public:
	SliderAndAttachment_ForOscBalance() = delete;

	SliderAndAttachment_ForOscBalance(ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void mouseDoubleClick(const MouseEvent& event) override;
	void attachSliderToExposedParameter();
	void deleteAttachmentBeforeSliderToPreventMemLeak();
	~SliderAndAttachment_ForOscBalance();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SliderAndAttachment_ForOscBalance)
};