#pragma once

#include <JuceHeader.h>

class ExposedParamsRandomizationOptions;
class TooltipsOptions;

class TransmitTypeToggles :
	public Component
{
	ToggleButton toggle_TransmitViaNRPN;
	ToggleButton toggle_TransmitViaSysEx;

public:
	TransmitTypeToggles() = delete;

	explicit TransmitTypeToggles(ExposedParamsRandomizationOptions* randomization, TooltipsOptions* tooltips);
	void mouseDown(const MouseEvent& event) override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TransmitTypeToggles)
};