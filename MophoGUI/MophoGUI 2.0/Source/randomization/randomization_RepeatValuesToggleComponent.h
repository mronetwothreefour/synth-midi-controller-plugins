#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class RepeatValuesToggleComponent :
	public Component,
	public Button::Listener
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
	void disableToggle();
	void restoreToggle();
	~RepeatValuesToggleComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RepeatValuesToggleComponent)
};