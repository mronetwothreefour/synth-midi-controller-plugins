#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class RestoreFactoryVoicesConfirmDialogBox :
	public Component
{
	TextButton button_Esc;
	TextButton button_OK;

public:
	RestoreFactoryVoicesConfirmDialogBox() = delete;

	explicit RestoreFactoryVoicesConfirmDialogBox(UnexposedParameters* unexposedParams);
	void addListenerToButtons(Button::Listener* listener);
	void removeListenerFromButtons(Button::Listener* listener);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RestoreFactoryVoicesConfirmDialogBox)
};