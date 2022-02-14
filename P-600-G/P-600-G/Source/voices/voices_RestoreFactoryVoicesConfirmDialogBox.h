#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class RestoreFactoryProgramsConfirmDialogBox :
	public Component
{
	TextButton button_Esc;
	TextButton button_OK;

public:
	RestoreFactoryProgramsConfirmDialogBox() = delete;

	explicit RestoreFactoryProgramsConfirmDialogBox(UnexposedParameters* unexposedParams);
	void addListenerToButtons(Button::Listener* listener);
	void removeListenerFromButtons(Button::Listener* listener);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RestoreFactoryProgramsConfirmDialogBox)
};