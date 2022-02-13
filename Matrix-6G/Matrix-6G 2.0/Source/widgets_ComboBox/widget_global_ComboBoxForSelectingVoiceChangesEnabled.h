#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingVoiceChangesEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingVoiceChangesEnabled() = delete;

	explicit ComboBoxForSelectingVoiceChangesEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString()  override;
	~ComboBoxForSelectingVoiceChangesEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingVoiceChangesEnabled)
};

