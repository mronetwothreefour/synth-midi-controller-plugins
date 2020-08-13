#pragma once

#include <JuceHeader.h>

#include "params_UnexposedTooltipOptions.h"



class UnexposedParameters
{
	TooltipOptions tooltips;

public:
	UnexposedParameters();

	void tooltips_addListener(ValueTree::Listener* listener);
	void tooltips_removeListener(ValueTree::Listener* listener);
	bool tooltips_shouldShowCurrentValue();
	bool tooltips_shouldShowDescription();
	void tooltips_setShouldShowCurrentValue();
	void tooltips_setShouldNotShowCurrentValue();
	void tooltips_setShouldShowDescription();
	void tooltips_setShouldNotShowDescription();
	int tooltips_delayInMilliseconds();
	void tooltips_setDelayInMilliseconds(int newDelay);

	~UnexposedParameters();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(UnexposedParameters)
};

