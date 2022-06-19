#pragma once

#include <JuceHeader.h>

#include "../exposedParamControls/sliders/epc_0_slider_JuceSlidersWithMouseMods.h"



class RandomizationOptions;
class TooltipsOptions;
class UnexposedParameters;

class SeqTrackProbabilities :
	public Component,
	public Slider::Listener,
	public ValueTree::Listener
{
	int trackNum;
	RandomizationOptions* randomizationOptions;
	TooltipsOptions* tooltips;
	RotarySliderWithMouseWheelMoveOverride knob_RestProbability;
	RotarySliderWithMouseWheelMoveOverride knob_DuplicateProbability;
	RotarySliderWithMouseWheelMoveOverride knob_ResetProbability;

public:
	SeqTrackProbabilities() = delete;

	SeqTrackProbabilities(int trackNum, UnexposedParameters* unexposedParams);
	void generateTooltips();
	void paint(Graphics& g) override;
	void sliderValueChanged(Slider* slider) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~SeqTrackProbabilities();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SeqTrackProbabilities)
};