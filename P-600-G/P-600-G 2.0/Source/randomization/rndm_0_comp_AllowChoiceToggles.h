#pragma once

#include <JuceHeader.h>

class ExposedParameters;
class ExposedParamsRandomizationOptions;
class InfoForExposedParameters;
class TooltipsOptions;
class UnexposedParameters;

class AllowChoiceToggles :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	InfoForExposedParameters* info;
	ExposedParamsRandomizationOptions* randomization;
	TooltipsOptions* tooltips;
	const uint8 numberOfChoices;
	const int numberOfColumns;
	const int numberOfRows;
	const int firstChoiceRow;
	const int toggle_w;

protected:
	std::vector<std::unique_ptr<ToggleButton>> allowedChoiceToggles;

public:
	AllowChoiceToggles() = delete;

	AllowChoiceToggles(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams);

protected:
	virtual const bool choiceIsAllowed(uint8 choiceNum);
	virtual void setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed);
	virtual void clearAllowedChoices();
	virtual const bool noChoiceIsAllowed();

public:
	void buttonClicked(Button* button) override;
	~AllowChoiceToggles();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles)
};