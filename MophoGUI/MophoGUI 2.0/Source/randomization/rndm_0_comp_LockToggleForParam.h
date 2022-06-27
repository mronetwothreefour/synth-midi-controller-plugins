#pragma once

#include <JuceHeader.h>



class RandomizationOptions;
class UnexposedParameters;

class LockToggleForParam :
	public ToggleButton,
	public ValueTree::Listener
{
	uint8 paramIndex;
	RandomizationOptions* randomization;

public:
	LockToggleForParam() = delete;

	LockToggleForParam(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~LockToggleForParam();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LockToggleForParam)
};