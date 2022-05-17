#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class RepeatValuesToggleComponent :
	public Component,
	public Button::Listener,
	public ValueTree::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton toggle_AllowRepeatValues;

public:
	RepeatValuesToggleComponent() = delete;

	RepeatValuesToggleComponent(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~RepeatValuesToggleComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RepeatValuesToggleComponent)
};