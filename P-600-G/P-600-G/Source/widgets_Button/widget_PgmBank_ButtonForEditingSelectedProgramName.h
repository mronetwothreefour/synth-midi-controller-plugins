#pragma once

#include <JuceHeader.h>

#include "widget_BaseButtonWithOnClickAndTooltipMethods.h"



class VoiceSlotsComponent;
class UnexposedParameters;

class ButtonForEditingSelectedProgramName :
	public BaseButtonWithOnClickAndTooltipMethods
{
	Label& nameEditor;
	VoiceSlotsComponent& slotsComponent;
	UnexposedParameters* unexposedParams;

public:
	ButtonForEditingSelectedProgramName() = delete;

	ButtonForEditingSelectedProgramName(Label& nameEditor, VoiceSlotsComponent& slotsComponent, UnexposedParameters* unexposedParams);

protected:
	const String createButtonTooltipString() override;
	void onClickMethod() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ButtonForEditingSelectedProgramName)
};
