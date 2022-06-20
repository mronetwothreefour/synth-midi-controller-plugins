#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class GUI_Layer_FileOverwriteDialog :
	public Component
{
	TextButton button_Cancel;
	TextButton button_Write;

public:
	GUI_Layer_FileOverwriteDialog() = delete;

	explicit GUI_Layer_FileOverwriteDialog(UnexposedParameters* unexposedParams);
	void addListenerToButtons(Button::Listener* listener);
	void removeListenerFromButtons(Button::Listener* listener);
	void paint(Graphics& g) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GUI_Layer_FileOverwriteDialog)
};