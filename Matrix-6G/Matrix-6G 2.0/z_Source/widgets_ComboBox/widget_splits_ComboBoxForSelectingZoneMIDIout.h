#pragma once

#include <JuceHeader.h>

#include "widget_BaseComboBoxForOffOnValueTreeProperty.h"



class UnexposedParameters;

class ComboBoxForSelectingZoneMIDIout :
	public BaseComboBoxForOffOnValueTreeProperty
{
	UnexposedParameters* unexposedParams;
	Identifier parameterID;

public:
	ComboBoxForSelectingZoneMIDIout() = delete;

	ComboBoxForSelectingZoneMIDIout(UnexposedParameters* unexposedParams, Identifier parameterID);
	String generateTooltipString() override;
	~ComboBoxForSelectingZoneMIDIout() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ComboBoxForSelectingZoneMIDIout)
};

