#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class CurrentVoiceOptions
{
	UnexposedParameters* unexposedParams;
	ValueTree currentVoiceOptionsTree;

public:
	CurrentVoiceOptions() = delete;

	explicit CurrentVoiceOptions(UnexposedParameters* unexposedParams);

private:
	void fillCurrentVoiceOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 currentVoiceNumber();
	void setCurrentVoiceNumber(uint8 newNumber);
	const String currentVoiceName();
	void setCurrentVoiceName(String newName);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CurrentVoiceOptions)
};