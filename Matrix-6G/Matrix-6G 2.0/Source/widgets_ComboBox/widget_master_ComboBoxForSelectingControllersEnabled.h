#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingControllersEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingControllersEnabled() = delete;

	explicit ComboBoxForSelectingControllersEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;
	~ComboBoxForSelectingControllersEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingControllersEnabled)
};

