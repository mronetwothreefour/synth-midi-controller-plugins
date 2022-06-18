#pragma once

#include <JuceHeader.h>



class RandomizationOptions;
class UnexposedParameters;

class AllowRepeatChoicesToggle :
	public Component,
	public ValueTree::Listener
{
	uint8 paramIndex;
	RandomizationOptions* randomizationOptions;
	ToggleButton toggle_AllowRepeatChoices;

public:
	AllowRepeatChoicesToggle() = delete;

	AllowRepeatChoicesToggle(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~AllowRepeatChoicesToggle();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowRepeatChoicesToggle)
};