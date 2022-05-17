#pragma once

#include <JuceHeader.h>



class FileNotValidAlert :
	public Component
{
	TextButton button_Close;

public:
	FileNotValidAlert();
	void paint(Graphics& g) override;
	void resized() override;

private:
	void hideThisComponent();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FileNotValidAlert)
};