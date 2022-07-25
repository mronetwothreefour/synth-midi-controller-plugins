#pragma once

#include <JuceHeader.h>

class ExposedParamsRandomizationOptions;
class UnexposedParameters;

class TransmitTypeToggles :
	public Component
{
	ToggleButton toggle_TransmitViaNRPN;
	ToggleButton toggle_TransmitViaSysEx;

public:
	TransmitTypeToggles() = delete;

	explicit TransmitTypeToggles(ExposedParamsRandomizationOptions* randomization,UnexposedParameters* unexposedParams);
	void mouseDown(const MouseEvent& event) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TransmitTypeToggles)
};