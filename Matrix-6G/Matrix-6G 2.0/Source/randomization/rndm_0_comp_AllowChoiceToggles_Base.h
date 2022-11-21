#pragma once

#include <JuceHeader.h>

class AllowChoiceToggles_Base :
	public Component,
	public Button::Listener
{
	const uint8 numberOfChoices;
	const int numberOfColumns;
	const int numberOfRows;
	const int firstChoiceRow;
	const int toggle_w;

protected:
	std::vector<std::unique_ptr<ToggleButton>> allowedChoiceToggles;

public:
	AllowChoiceToggles_Base() = delete;

	AllowChoiceToggles_Base(uint8 numberOfChoices, int numberOfColumns, int numberOfRows, int firstChoiceRow, int toggle_w);

protected:
	virtual String buildChoiceName(uint8 choiceNum) = 0;
	virtual String buildTooltip() = 0;
	virtual const bool choiceIsAllowed(uint8 choiceNum) = 0;
	virtual void setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) = 0;
	virtual void clearAllowedChoices() = 0;
	virtual const bool noChoiceIsAllowed() = 0;

public:
	void buttonClicked(Button* button) override;
	virtual void restoreToggles() = 0;
	~AllowChoiceToggles_Base();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(AllowChoiceToggles_Base)
};