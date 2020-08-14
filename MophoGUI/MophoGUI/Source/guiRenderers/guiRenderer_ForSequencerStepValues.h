#pragma once

#include <JuceHeader.h>



class RendererForSequencerStepValues :
	public Component,
	public Slider::Listener
{
	Slider* stepSlider;
	Slider* trackDestination;
	const int resetSequence;
	const int track1Rest;

public:
	RendererForSequencerStepValues() = delete;

	RendererForSequencerStepValues(Slider* stepSlider, Slider* trackDestination);
	void sliderValueChanged(Slider* slider) override;
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

