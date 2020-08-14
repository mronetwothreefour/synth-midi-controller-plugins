#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class TooltipSetter : public ValueTree::Listener
{
	UnexposedParameters* unexposedParams;

protected:
	TooltipSetter(UnexposedParameters* unexposedParams);
	virtual void setTooltip() = 0;
	virtual String generateTooltipText() = 0;

public:
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~TooltipSetter();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipSetter)
};
