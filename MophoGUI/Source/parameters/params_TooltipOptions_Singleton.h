#pragma once

#include <JuceHeader.h>



class TooltipOptions
{
	ValueTree tooltipOptionsTree;

	TooltipOptions();
	~TooltipOptions();

	void addTooltipOptionsProperties();

public:
	TooltipOptions(TooltipOptions&&) = delete;
	TooltipOptions& operator=(TooltipOptions&&) = delete;

	static TooltipOptions& get();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	bool shouldShowCurrentValue();
	bool shouldShowDescription();
	void setShouldShowCurrentValue();
	void setShouldNotShowCurrentValue();
	void setShouldShowDescription();
	void setShouldNotShowDescription();
	int delayInMilliseconds();
	void setDelayInMilliseconds(int newDelay);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipOptions)
};
