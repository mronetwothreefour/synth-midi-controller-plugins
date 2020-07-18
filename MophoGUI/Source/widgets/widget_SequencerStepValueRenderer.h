#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Fonts.h"



class SequencerStepValueRenderer :
	public Component,
	public Slider::Listener
{
	Slider* stepSlider;
	Slider* trackDestination;

public:
	SequencerStepValueRenderer(Slider* stepSlider, Slider* trackDestination) :
		stepSlider{ stepSlider },
		trackDestination{ trackDestination }
	{
		stepSlider->addListener(this);
		trackDestination->addListener(this);
		sliderValueChanged(stepSlider);
	}

	~SequencerStepValueRenderer() {
		stepSlider->removeListener(this);
		trackDestination->removeListener(this);
	}

	void paint(Graphics& g) override {
		auto stepValue{ (uint8)roundToInt(stepSlider->getValue()) };
		Font font(FontsDB::family_Global, FontsDB::style_ForSeqStepValueDisplay, FontsDB::size_ForSeqStepValueDisplay);
		g.setFont(font);
		g.setColour(Color::controlText);
		if (stepValue < 126)
			paintStepValueString(g, stepValue);
		if (stepValue == 126) { // reset sequence
			Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
			g.drawArrow(l, 5.0f, 10.0f, 8.0f);
		}
		if (stepValue == 127) { // rest (sequencer track 1 only)
			g.fillEllipse(10.0f, 10.0f, 6.0f, 6.0f);
		}
	}

	void paintStepValueString(Graphics& g, uint8 stepValue) {
		jassert(stepValue < 126);
		String valueString;
		auto destination{ roundToInt(trackDestination->getValue()) };
		if (destination > 0 && destination < 4) // pitch parameters
			valueString = IntToSeqStepPitchName::convert(stepValue);
		else valueString = (String)stepValue;
		g.drawText(valueString, getLocalBounds(), Justification::centred);
	}

	void sliderValueChanged(Slider* slider) override {
		if (slider == stepSlider || slider == trackDestination) {
			repaint();
		}
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SequencerStepValueRenderer)
};

