#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingMIDIechoEnabled :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;

public:
	ComboBoxForSelectingMIDIechoEnabled() = delete;

	explicit ComboBoxForSelectingMIDIechoEnabled(UnexposedParameters* unexposedParams);
	String generateTooltipString() override;
	~ComboBoxForSelectingMIDIechoEnabled() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingMIDIechoEnabled)
};

