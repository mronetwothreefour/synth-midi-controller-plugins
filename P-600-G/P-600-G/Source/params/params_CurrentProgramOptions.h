#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class CurrentProgramOptions
{
	UnexposedParameters* unexposedParams;
	ValueTree currentProgramOptionsTree;

public:
	CurrentProgramOptions() = delete;

	explicit CurrentProgramOptions(UnexposedParameters* unexposedParams);

private:
	void fillCurrentProgramOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 currentProgramNumber();
	void setCurrentProgramNumber(uint8 newNumber);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CurrentProgramOptions)
};