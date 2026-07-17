#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class InfoForExposedParameters;
class TooltipsOptions;

class TooltipUpdaterForExposedParamControl :
	public Value::Listener
{
	const uint8 paramIndex;
	SettableTooltipClient& clientComponent;
	AudioProcessorValueTreeState* state;
	InfoForExposedParameters* info;
	Value paramAsValue;
	Value shouldShowDescriptionAsValue;
	Value shouldShowCurrentChoiceAsValue;

public:
	TooltipUpdaterForExposedParamControl() = delete;

	TooltipUpdaterForExposedParamControl(const uint8 paramIndex, SettableTooltipClient& clientComponent, ExposedParameters* exposedParams, TooltipsOptions* tooltips);

private:
	void updateTooltip();
	String generateTooltipText();

public:
	void valueChanged(Value& value) override;
	~TooltipUpdaterForExposedParamControl();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipUpdaterForExposedParamControl)
};
