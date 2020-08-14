#pragma once

#include <JuceHeader.h>



struct IntToContextualStringConverter;

class RendererForKnobValueStrings :
	public Component,
	public Slider::Listener
{
	Slider* knob;
	String valueString;
	IntToContextualStringConverter* converter;

public:
	RendererForKnobValueStrings() = delete;

	RendererForKnobValueStrings(Slider* knob, uint8 param);
	void paint(Graphics& g) override;
	void sliderValueChanged(Slider* slider) override;
	~RendererForKnobValueStrings() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RendererForKnobValueStrings)
};
