#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class DisplayLabelForBalanceTweak :
	public Label,
	public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	DisplayLabelForBalanceTweak() = delete;

	explicit DisplayLabelForBalanceTweak(UnexposedParameters* unexposedParams);
	String generateTooltipString();
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~DisplayLabelForBalanceTweak() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DisplayLabelForBalanceTweak)
};

