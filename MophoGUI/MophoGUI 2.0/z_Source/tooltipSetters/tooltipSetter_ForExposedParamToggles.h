#pragma once

#include <JuceHeader.h>

#include "tooltipSetter_Base.h"
#include "../params/params_IntToContextualStringConverters.h"



class TooltipSetterForExposedParamToggles :
	public TooltipSetter,
	public Button::Listener
{
	Button& toggle;
	uint8 param;
	UnexposedParameters* unexposedParams;
	IntToContextualStringConverter* converter;

public:
	TooltipSetterForExposedParamToggles() = delete;

	TooltipSetterForExposedParamToggles(Button& toggle, uint8 param, UnexposedParameters* unexposedParams);
	void buttonClicked(Button* button) override;
	void buttonStateChanged(Button* button) override;

private:
	void setTooltip() override;
	String generateTooltipText() override;

public:
	~TooltipSetterForExposedParamToggles();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetterForExposedParamToggles)
};
