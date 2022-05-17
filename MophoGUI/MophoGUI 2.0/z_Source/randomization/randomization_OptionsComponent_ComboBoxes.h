#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class RandomizationOptionsComponent_ComboBoxes :
	public Component,
	public Button::Listener
{
	uint8 paramIndex;
	UnexposedParameters* unexposedParams;
	int numberOfItems;
	ToggleButton allowedItemToggles[200];
	TextButton button_ForAllowingAllItems;
	TextButton button_ForClosingComponent;
	int componentInset;
	int gapBetweenButtonAndItemList;
	int background_x;
	int background_y;
	int background_w;
	int background_h;
	int item_w;

public:
	RandomizationOptionsComponent_ComboBoxes() = delete;

	RandomizationOptionsComponent_ComboBoxes(uint8 paramIndex, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void buttonClicked(Button* button) override;
	void hideThisComponent();
	~RandomizationOptionsComponent_ComboBoxes();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RandomizationOptionsComponent_ComboBoxes)
};