#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingSysExEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingSysExEnabled() = delete;

	ComboBoxForSelectingSysExEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;
	~ComboBoxForSelectingSysExEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingSysExEnabled)
};

