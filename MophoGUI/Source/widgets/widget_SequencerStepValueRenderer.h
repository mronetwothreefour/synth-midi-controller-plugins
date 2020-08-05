#pragma once

#include <JuceHeader.h>



class SequencerStepValueRenderer :
	public Component,
	public Slider::Listener
{
	Slider* stepSlider;
	Slider* trackDestination;
	const int resetSequence;
	const int track1Rest;

public:
	SequencerStepValueRenderer() = delete;

	SequencerStepValueRenderer(Slider* stepSlider, Slider* trackDestination);
	~SequencerStepValueRenderer();
	void sliderValueChanged(Slider* slider) override;
	void paint(Graphics& g) override;
	void paintStepValueString(Graphics& g, uint8 stepValue);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerStepValueRenderer)
};

