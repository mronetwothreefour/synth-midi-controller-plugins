#pragma once

#include <JuceHeader.h>

#include "../guiRenderers/guiRenderer_ForKnobValueStrings.h"
#include "../widgets_Slider/widget_ModifiedJuceSliders.h"



class UnexposedParameters;

class ProbabilitiesForSeqTrackComponent :
	public Component,
	public Slider::Listener,
	public ValueTree::Listener
{
	int trackNum;
	UnexposedParameters* unexposedParams;
	RotarySliderWithMouseWheelMod knob_ForRestProbability;
	RendererForKnobValueStrings valueDisplay_ForRestProbability;
	RotarySliderWithMouseWheelMod knob_ForRepeatValueProbability;
	RendererForKnobValueStrings valueDisplay_ForRepeatValueProbability;
	RotarySliderWithMouseWheelMod knob_ForResetProbability;
	RendererForKnobValueStrings valueDisplay_ForResetProbability;

public:
	ProbabilitiesForSeqTrackComponent() = delete;

	ProbabilitiesForSeqTrackComponent(int trackNum, UnexposedParameters* unexposedParams);
	void generateTooltips();
	void paint(Graphics& g) override;
	const char* getBackgroundImageData();
	size_t getBackgroundImageDataSize();
	void resized() override;
	void sliderValueChanged(Slider* slider) override;
	void valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) override;
	~ProbabilitiesForSeqTrackComponent();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProbabilitiesForSeqTrackComponent)
};