#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class AllowedValuesTogglesComponent :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	ToggleButton allowedValuesToggles[255];
	String paramID;
	uint8 numberOfValues;
	int toggleWidth;
	int numberOfColumns;
	int numberOfRows;
	int rowForFirstValue;

public:
	AllowedValuesTogglesComponent() = delete;

	AllowedValuesTogglesComponent(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void resized() override;
	void buttonClicked(Button* button) override;
	void allowAllValues();
	~AllowedValuesTogglesComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowedValuesTogglesComponent)
};