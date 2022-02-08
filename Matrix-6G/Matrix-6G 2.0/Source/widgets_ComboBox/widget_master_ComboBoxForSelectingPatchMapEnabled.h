#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingPatchMapEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingPatchMapEnabled() = delete;

	explicit ComboBoxForSelectingPatchMapEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;
	~ComboBoxForSelectingPatchMapEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingPatchMapEnabled)
};

