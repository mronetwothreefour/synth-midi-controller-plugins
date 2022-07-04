#pragma once

#include <JuceHeader.h>



class TooltipsOptions
{
	ValueTree tooltipsOptionsTree;

public:
	TooltipsOptions();
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const bool shouldShowCurrentValue();
	void setShouldShowCurrentValue(bool shouldShow);
	const bool shouldShowDescriptions();
	void setShouldShowDescription(bool shouldShow);
	const int delayInMilliseconds();
	void setDelayInMilliseconds(int newDelay);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipsOptions)
};
