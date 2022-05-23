#pragma once

#include <JuceHeader.h>

#include "../0_comp_TooltipUpdaterForExposedParamControl.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;



class ToggleButtonAndAttachment : 
	public Component
{
protected:
	uint8 paramIndex;
	ToggleButton toggle;
	AudioProcessorValueTreeState* exposedParams;
	std::unique_ptr<ButtonAttachment> attachment;
	TooltipUpdaterForExposedParamControl tooltipsUpdater;

public:
	ToggleButtonAndAttachment() = delete;

	explicit ToggleButtonAndAttachment(uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);
	void attachToggleToExposedParameter();
	void deleteAttachmentBeforeToggleToPreventMemLeak();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonAndAttachment)
};
