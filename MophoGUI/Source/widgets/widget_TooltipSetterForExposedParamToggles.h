#pragma once

#include <JuceHeader.h>

#include "widget_TooltipSetter.h"



class TooltipSetterForExposedParamToggles :
	public TooltipSetter,
	public Button::Listener
{
	Button& toggle;
	uint8 param;
	IntToContextualStringConverter* converter;

public:
	TooltipSetterForExposedParamToggles() = delete;

	TooltipSetterForExposedParamToggles(Button& toggle, uint8 param);
	~TooltipSetterForExposedParamToggles();
	void buttonClicked(Button* /*button*/) override;
	void buttonStateChanged(Button* button) override;

private:
	void setTooltip() noexcept override;
	String generateTooltipText() noexcept override;

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamToggles)
};
