#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class OscillatorRandomizationOptionsComponent :
	public Component
{
	TextButton button_ForClosingOscOptionsComponent;

public:
	OscillatorRandomizationOptionsComponent() = delete;

	explicit OscillatorRandomizationOptionsComponent(UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void hideThisComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(OscillatorRandomizationOptionsComponent)
};
