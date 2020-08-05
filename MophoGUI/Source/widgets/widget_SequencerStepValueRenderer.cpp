#include "widget_SequencerStepValueRenderer.h"

#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Fonts.h"
#include "../helpers/helper_IntToContextualStringConverters.h"



SequencerStepValueRenderer::SequencerStepValueRenderer(Slider* stepSlider, Slider* trackDestination) :
	stepSlider{ stepSlider },
	trackDestination{ trackDestination },
	resetSequence{ 126 },
	track1Rest{ 127 }
{
	stepSlider->addListener(this);
	trackDestination->addListener(this);
	sliderValueChanged(stepSlider);
}

SequencerStepValueRenderer::~SequencerStepValueRenderer() {
	stepSlider->removeListener(this);
	trackDestination->removeListener(this);
}

void SequencerStepValueRenderer::sliderValueChanged(Slider* slider) {
	if (slider == stepSlider || slider == trackDestination)
		repaint();
}

void SequencerStepValueRenderer::paint(Graphics& g) {
	auto stepValue{ (uint8)roundToInt(stepSlider->getValue()) };
	Font font(FontsDB::family_Global, FontsDB::style_ForSeqStepValueDisplay, FontsDB::size_ForSeqStepValueDisplay);
	g.setFont(font);
	g.setColour(Color::controlText);
	if (stepValue < resetSequence)
		paintStepValueString(g, stepValue);
	if (stepValue == resetSequence) {
		Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
		g.drawArrow(l, 5.0f, 10.0f, 8.0f);
	}
	if (stepValue == track1Rest) {
		g.fillEllipse(10.0f, 10.0f, 6.0f, 6.0f);
	}
}

void SequencerStepValueRenderer::paintStepValueString(Graphics& g, uint8 stepValue) {
	jassert(stepValue < 126);
	String valueString;
	auto destination{ roundToInt(trackDestination->getValue()) };
	if (destination > 0 && destination < 4) // pitch parameters
		valueString = IntToSeqStepPitchName::convert(stepValue);
	else valueString = (String)stepValue;
	g.drawText(valueString, getLocalBounds(), Justification::centred);
}