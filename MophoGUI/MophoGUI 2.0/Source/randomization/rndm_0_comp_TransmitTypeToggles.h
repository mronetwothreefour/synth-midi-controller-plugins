#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class TransmitTypeToggles :
	public Component
{
	ToggleButton toggle_TransmitViaNRPN;
	ToggleButton toggle_TransmitViaSysEx;

public:
	TransmitTypeToggles() = delete;

	explicit TransmitTypeToggles(UnexposedParameters* unexposedParams);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TransmitTypeToggles)
};