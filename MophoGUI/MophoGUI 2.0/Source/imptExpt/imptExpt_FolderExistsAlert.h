#pragma once

#include <JuceHeader.h>



class FolderExistsAlert :
	public Component
{
	TextButton button_Close;

public:
	FolderExistsAlert();
	void paint(Graphics& g) override;
	void resized() override;

private:
	void hideThisComponent();

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FolderExistsAlert)
};