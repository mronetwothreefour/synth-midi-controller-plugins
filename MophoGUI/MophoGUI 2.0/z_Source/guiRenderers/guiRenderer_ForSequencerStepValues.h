#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class RendererForSequencerStepValues :
	public Component,
	public Slider::Listener,
	public ValueTree::Listener
{
	Slider* stepSlider;
	const int trackNum;
	UnexposedParameters* unexposedParams;

public:
	RendererForSequencerStepValues() = delete;

	RendererForSequencerStepValues(Slider* stepSlider, int trackNum, UnexposedParameters* unexposedParams);
	void sliderValueChanged(Slider* slider) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	void paint(Graphics& g) override;
	void paintResetSequenceArrow(Graphics& g);
	void paintTrack1RestDot(Graphics& g);
	void paintStepValueString(Graphics& g, uint8 stepValue);
	String generateStringForValue(uint8 stepValue);
	~RendererForSequencerStepValues() override;

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(RendererForSequencerStepValues)
};

