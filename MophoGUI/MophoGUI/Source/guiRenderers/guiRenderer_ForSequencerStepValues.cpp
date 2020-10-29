#include "guiRenderer_ForSequencerStepValues.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_IntToContextualStringConverters.h"



RendererForSequencerStepValues::RendererForSequencerStepValues(Slider* stepSlider, Slider* trackDestination) :
	stepSlider{ stepSlider },
	trackDestination{ trackDestination },
	resetSequence{ 126 },
	track1Rest{ 127 }
{
	stepSlider->addListener(this);
	trackDestination->addListener(this);
	sliderValueChanged(stepSlider);
}

void RendererForSequencerStepValues::sliderValueChanged(Slider* slider) {
	if (slider == stepSlider || slider == trackDestination)
		repaint();
}

void RendererForSequencerStepValues::paint(Graphics& g) {
	auto stepValue{ (uint8)roundToInt(stepSlider->getValue()) };
	g.setColour(Color::controlText);
	if (stepValue == resetSequence)
		paintResetSequenceArrow(g);
	if (stepValue == track1Rest)
		paintTrack1RestDot(g);
	if (stepValue < resetSequence)
		paintStepValueString(g, stepValue);
}

void RendererForSequencerStepValues::paintResetSequenceArrow(Graphics& g) {
	Line<float> l{ 20.0f, 13.0f, 5.0f, 13.0f };
	g.drawArrow(l, 5.0f, 10.0f, 8.0f);
}

void RendererForSequencerStepValues::paintTrack1RestDot(Graphics& g) {
	g.fillEllipse(10.0f, 10.0f, 6.0f, 6.0f);
}

void RendererForSequencerStepValues::paintStepValueString(Graphics& g, uint8 stepValue) {
	jassert(stepValue < 126);
	Font font(FontsMenu::family_Global, FontsMenu::style_ForSeqStepValueDisplay, FontsMenu::size_ForSeqStepValueDisplay);
	g.setFont(font);
	g.drawText(generateStringForValue(stepValue), getLocalBounds(), Justification::centred);
}

String RendererForSequencerStepValues::generateStringForValue(uint8 stepValue) {
	String valueString;
	auto destination{ roundToInt(trackDestination->getValue()) };
	auto osc1Pitch{ 1 };
	auto osc2Pitch{ 2 };
	auto osc1and2Pitch{ 3 };
	if (destination == osc1Pitch || destination == osc2Pitch || destination == osc1and2Pitch)
		valueString = IntToPitchName::convertToSeqStepPitchName(stepValue);
	else valueString = (String)stepValue;
	return valueString;
}

RendererForSequencerStepValues::~RendererForSequencerStepValues() {
	stepSlider->removeListener(this);
	trackDestination->removeListener(this);
}
