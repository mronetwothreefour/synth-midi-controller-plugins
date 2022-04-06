#pragma once

#include <JuceHeader.h>



class UnexposedParameters;

class ProbabilitiesForSeqTrackComponent :
	public Component,
	public Slider::Listener,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	Slider knob_ForRepeatValueProbability;
	Slider knob_ForRestProbability;
	Slider knob_ForResetProbability;

public:
	ProbabilitiesForSeqTrackComponent() = delete;

	ProbabilitiesForSeqTrackComponent(int trackNum, UnexposedParameters* unexposedParams);
	void paint(Graphics& g) override;
	void resized() override;
	void sliderValueChanged(Slider* slider) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& property) override;
	~ProbabilitiesForSeqTrackComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProbabilitiesForSeqTrackComponent)
};