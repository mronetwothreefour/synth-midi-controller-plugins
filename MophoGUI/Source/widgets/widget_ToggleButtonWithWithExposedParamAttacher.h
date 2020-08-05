#pragma once

#include <JuceHeader.h>

#include "widget_TooltipSetterForExposedParamToggles.h"

using ButtonAttachment = AudioProcessorValueTreeState::ButtonAttachment;



class ToggleButtonWithWithExposedParamAttacher : public Component
{
protected:
	ToggleButton toggle;
	std::unique_ptr<ButtonAttachment> attachment;
	uint8 param;
	TooltipSetterForExposedParamToggles tooltipSetter;

public:
	ToggleButtonWithWithExposedParamAttacher() = delete;

	explicit ToggleButtonWithWithExposedParamAttacher(uint8 param);
	~ToggleButtonWithWithExposedParamAttacher();
	void attachToExposedParameter(AudioProcessorValueTreeState* exposedParams);
	void deleteAttachment();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleButtonWithWithExposedParamAttacher)
};
