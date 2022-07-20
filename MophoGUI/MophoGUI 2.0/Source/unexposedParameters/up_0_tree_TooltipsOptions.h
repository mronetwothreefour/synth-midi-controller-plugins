#pragma once

#include <JuceHeader.h>

class TooltipsOptions
{
	ValueTree tooltipsOptionsTree;

public:
	TooltipsOptions();
	const bool shouldShowCurrentChoice();
	void setShouldShowCurrentChoice(const bool shouldShow);
	Value getShouldShowCurrentChoiceValue();
	const bool shouldShowDescription();
	void setShouldShowDescription(const bool shouldShow);
	Value getShouldShowDescriptionValue();
	const int delayInMilliseconds();
	void setDelayInMilliseconds(const int newDelay);
	Value getDelayInMillisecondsValue();
	std::unique_ptr<XmlElement> getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TooltipsOptions)
};
