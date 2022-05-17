#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class LabelForSettingTooltipDelay :
	public Label,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	LabelForSettingTooltipDelay() = delete;

	explicit LabelForSettingTooltipDelay(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~LabelForSettingTooltipDelay();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LabelForSettingTooltipDelay)
};

