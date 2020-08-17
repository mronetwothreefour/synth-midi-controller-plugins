#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class ButtonForOpeningPgmNameEditor : public BaseButtonWithOnClickAndTooltipMethods
{
	AudioProcessorValueTreeState* exposedParams;
	UnexposedParameters* unexposedParams;
	Label& pgmNameEditor;

public:
	ButtonForOpeningPgmNameEditor() = delete;

	ButtonForOpeningPgmNameEditor(AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams, Label& pgmNameEditor);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

public:
	String getProgramNameFromExposedParemeters();
	~ButtonForOpeningPgmNameEditor();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForOpeningPgmNameEditor)
};

