#pragma once

#include <JuceHeader.h>




class UnexposedParameters;

class AllowChoiceToggles :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	std::vector<std::unique_ptr<ToggleButton>> allowedChoiceToggles;
	int numberOfChoices;
	int numberOfColumns;
	int numberOfRows;
	int toggle_w;

public:
	AllowChoiceToggles() = delete;

	AllowChoiceToggles(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void resized() override;
	void buttonClicked(Button* button) override;
	void allowAllChoices();
	~AllowChoiceToggles();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles)
};