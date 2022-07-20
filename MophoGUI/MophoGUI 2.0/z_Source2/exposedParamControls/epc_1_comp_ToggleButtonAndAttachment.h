#pragma once

#include <JuceHeader.h>

#include "epc_0_comp_TooltipUpdaterForExposedParamControl.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;



class ToggleButtonAndAttachment : 
	public Component
{
protected:
	uint8 paramIndex;
	ToggleButton toggle;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	std::unique_ptr<ButtonAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipUpdater;

public:
	ToggleButtonAndAttachment() = delete;

	explicit ToggleButtonAndAttachment(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);
	void attachToggleToExposedParameter();
	void deleteAttachmentBeforeToggleToPreventMemLeak();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonAndAttachment)
};
