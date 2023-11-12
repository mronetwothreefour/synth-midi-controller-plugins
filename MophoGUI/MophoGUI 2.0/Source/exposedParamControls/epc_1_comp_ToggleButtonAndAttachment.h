#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;

class ToggleButtonAndAttachment : 
	public Component
{
protected:
	const uint8 paramIndex;
	ToggleButton redToggle;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	std::unique_ptr<ButtonAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;

public:
	ToggleButtonAndAttachment() = delete;

	explicit ToggleButtonAndAttachment(const uint8 paramIndex, ExposedParameters* exposedParams, TooltipsOptions* tooltips);
	void attachToggleToExposedParameter();
	void deleteAttachmentBeforeToggleToPreventMemLeak();
	void mouseDown(const MouseEvent& event) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonAndAttachment)
};
