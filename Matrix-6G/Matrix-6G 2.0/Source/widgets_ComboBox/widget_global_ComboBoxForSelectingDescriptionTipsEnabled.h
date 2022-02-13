#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingDescriptionTipsEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingDescriptionTipsEnabled() = delete;

	explicit ComboBoxForSelectingDescriptionTipsEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingDescriptionTipsEnabled)
};

