#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingPatchChangesEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingPatchChangesEnabled() = delete;

	ComboBoxForSelectingPatchChangesEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString()  override;
	~ComboBoxForSelectingPatchChangesEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingPatchChangesEnabled)
};

