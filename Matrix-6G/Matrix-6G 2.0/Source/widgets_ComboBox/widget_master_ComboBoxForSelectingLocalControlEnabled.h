#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingLocalControlEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingLocalControlEnabled() = delete;

	explicit ComboBoxForSelectingLocalControlEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;
	~ComboBoxForSelectingLocalControlEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingLocalControlEnabled)
};

