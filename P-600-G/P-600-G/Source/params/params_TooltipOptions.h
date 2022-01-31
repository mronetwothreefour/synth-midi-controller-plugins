#pragma once

#include <JuceHeader.h>



class TooltipOptions
{
	ValueTree tooltipOptionsTree;

public:
	TooltipOptions();

private:
	void addTooltipOptionsProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const bool shouldShowCurrentSettings();
	const bool shouldShowDescriptions();
	void setShouldShowCurrentSettings();
	void setShouldNotShowCurrentSettings();
	void setShouldShowDescriptions();
	void setShouldNotShowDescriptions();
	const int delayInMilliseconds();
	void setDelayInMilliseconds(int newDelay);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipOptions)
};
