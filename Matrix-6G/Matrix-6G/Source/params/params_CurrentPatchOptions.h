#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class CurrentPatchOptions
{
	UnexposedParameters* unexposedParams;
	ValueTree currentPatchOptionsTree;

public:
	CurrentPatchOptions() = delete;
	explicit CurrentPatchOptions(UnexposedParameters* unexposedParams);

private:
	void fillCurrentPatchOptionsTreeWithProperties();

public:
	void addListener(ValueTree::Listener* listener);
	void removeListener(ValueTree::Listener* listener);
	const uint8 currentPatchNumber();
	void setCurrentPatchNumber(uint8 newNumber);
	const String currentPatchName();
	void setCurrentPatchName(String newName);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CurrentPatchOptions)
};