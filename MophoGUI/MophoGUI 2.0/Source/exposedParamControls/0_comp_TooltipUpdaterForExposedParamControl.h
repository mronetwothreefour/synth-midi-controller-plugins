#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class TooltipUpdaterForExposedParamControl : 
	public AudioProcessorParameter::Listener,
	public ValueTree::Listener
{
	uint8 paramIndex;
	SettableTooltipClient& clientControl;
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;

public:
	TooltipUpdaterForExposedParamControl() = delete;
	
	TooltipUpdaterForExposedParamControl(uint8 paramIndex, SettableTooltipClient& paramControl, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams);

private:
	void setTooltip();
	String generateTooltipText();

public:
	void parameterValueChanged(int changedParamIndex, float newValue);
	void parameterGestureChanged(int paramIndex, bool gestureIsStarting);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~TooltipUpdaterForExposedParamControl();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipUpdaterForExposedParamControl)
};
