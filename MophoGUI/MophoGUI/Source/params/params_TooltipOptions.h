#pragma once

#include <JuceHeader.h>



class TooltipOptions
{
	ValueTree tooltipOptionsTree;

public: TooltipOptions();
private: void addTooltipOptionsProperties();
public:
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
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~TooltipOptions();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipOptions)
};
