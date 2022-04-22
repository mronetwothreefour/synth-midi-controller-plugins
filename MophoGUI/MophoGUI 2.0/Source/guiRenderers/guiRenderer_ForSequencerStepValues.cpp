#include "guiRenderer_ForSequencerStepValues.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"



RendererForSequencerStepValues::RendererForSequencerStepValues(Slider* stepSlider, int trackNum, UnexposedParameters* unexposedParams) :
	stepSlider{ stepSlider },
	trackNum{ trackNum },
	unexposedParams{ unexposedParams },
	resetSequence{ 126 },
	track1Rest{ 127 }
{
	stepSlider->addListener(this);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->addListenerToSeqTrackOptionsTree(this);
	sliderValueChanged(stepSlider);
}

void RendererForSequencerStepValues::sliderValueChanged(Slider* slider) {
	if (slider == stepSlider)
		repaint();
}

void RendererForSequencerStepValues::valueTreePropertyChanged(ValueTree& /*tree*/, const Identifier& propertyID) {
	if (propertyID.toString() == "DestinationForTrack" + String(trackNum) + "_IsAnOscPitchParameter")
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
	g.setFont(FontsMenu::fontFor_SeqSteps);
	g.drawText(generateStringForValue(stepValue), getLocalBounds(), Justification::centred, false);
}

String RendererForSequencerStepValues::generateStringForValue(uint8 stepValue) {
	String valueString;
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto destinationIsAnOscPitchParam{ randomizationOptions->trackDestinationIsAnOscPitchParameter(trackNum) };
	if (destinationIsAnOscPitchParam)
		valueString = IntToPitchName::convertToSeqStepPitchName(stepValue);
	else 
		valueString = (String)stepValue;
	return valueString;
}

RendererForSequencerStepValues::~RendererForSequencerStepValues() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	randomizationOptions->removeListenerFromSeqTrackOptionsTree(this);
	stepSlider->removeListener(this);
}
