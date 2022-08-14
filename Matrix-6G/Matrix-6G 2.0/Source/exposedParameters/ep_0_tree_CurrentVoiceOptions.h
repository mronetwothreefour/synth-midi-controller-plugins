#pragma once

#include <JuceHeader.h>

class CurrentVoiceOptions
{
	ValueTree currentVoiceOptionsTree;
	UndoManager* undoManager;

public:
	CurrentVoiceOptions() = delete;

	explicit CurrentVoiceOptions(UndoManager* undoManager);

	const String currentVoiceName();
	void setCurrentVoiceName(String newName);

	const uint8 currentVoiceNumber();
	void setCurrentVoiceNumber(uint8 newNumber);

	Value getCurrentVoicePropertyAsValue(const Identifier propertyID);

	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CurrentVoiceOptions)
};