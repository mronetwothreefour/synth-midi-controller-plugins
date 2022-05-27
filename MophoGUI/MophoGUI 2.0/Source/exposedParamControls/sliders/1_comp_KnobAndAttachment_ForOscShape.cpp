#include "1_comp_KnobAndAttachment_ForOscShape.h"

#include "../../constants/constants_Enum.h"
#include "../../constants/constants_ExposedParameters.h"
#include "../../constants/constants_GUI_Dimensions.h"
#include "../../constants/constants_GUI_Colors.h"
#include "../../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../../constants/constants_Identifiers.h"
#include "../../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;



KnobAndAttachment_ForOscShape::KnobAndAttachment_ForOscShape(
	uint8 paramIndex, AudioProcessorValueTreeState* exposedParams, UnexposedParameters* unexposedParams) :
		paramIndex{ paramIndex },
		exposedParams{ exposedParams },
		unexposedParams{ unexposedParams },
		knob{ unexposedParams },
		tooltipsUpdater{ paramIndex, knob, exposedParams, unexposedParams },
		choiceNum{ 0 },
		strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded }
{
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->addListener(this);

	addAndMakeVisible(knob);
	knob.setMouseDragSensitivity(info.mouseDragSensitivityFor(paramIndex));
	knob.setComponentID(ID::component_Knob.toString());
	knob.isModifyingPitch = false;
	setSize(GUI::knob_diameter, GUI::knob_diameter);
	knob.setBounds(getLocalBounds());

	parameterValueChanged(paramIndex, paramaterPtr->getValue());
}

void KnobAndAttachment_ForOscShape::paint(Graphics& g) {
	Path path;
	g.setColour(GUI::color_White);
	if (choiceNum > -1 && choiceNum < EP::numberOfChoicesForOscWaveShape) {
		if (choiceNum == (int)OscWaveShape::off)
			paintText(g, "OFF");
		if (choiceNum == (int)OscWaveShape::sawtooth)
			paintSawtooth(g, path);
		if (choiceNum == (int)OscWaveShape::triangle)
			paintTriangle(g, path);
		if (choiceNum == (int)OscWaveShape::sawTriMix)
			paintSawTriMix(g, path);
		if (choiceNum >= (int)OscWaveShape::pulse)
			paintPulse(g, path, choiceNum - (int)OscWaveShape::pulse);
	}
	else
		paintText(g, "ERR");
}

void KnobAndAttachment_ForOscShape::paintText(Graphics& g, String text) {
	g.setFont(GUI::fontFor_KnobValueDisplays);
	g.drawText(text, getLocalBounds(), Justification::centred);
}

void KnobAndAttachment_ForOscShape::paintSawtooth(Graphics& g, Path path) {
	Line<float> line1{ 6.0f, 20.0f, 21.0f, 8.0f };
	Line<float> line2{ 21.0f, 8.0f, 21.0f, 20.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	path.applyTransform(AffineTransform::translation(5.0f, 5.0f));
	g.strokePath(path, strokeType);
}

void KnobAndAttachment_ForOscShape::paintTriangle(Graphics& g, Path path) {
	Line<float> line1{ 7.0f, 20.0f, 15.0f, 9.0f };
	Line<float> line2{ 15.0f, 9.0f, 23.0f, 20.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	path.applyTransform(AffineTransform::translation(5.0f, 5.0f));
	g.strokePath(path, strokeType);
}

void KnobAndAttachment_ForOscShape::paintSawTriMix(Graphics& g, Path path) {
	Line<float> line1{ 5.0f, 15.0f, 10.0f, 8.0f };
	Line<float> line2{ 10.0f, 8.0f, 15.0f, 15.0f };
	Line<float> line3{ 15.0f, 15.0f, 15.0f, 23.0f };
	Line<float> line4{ 15.0f, 23.0f, 25.0f, 15.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	path.addLineSegment(line3, 0.5f);
	path.addLineSegment(line4, 0.5f);
	path.applyTransform(AffineTransform::translation(5.0f, 5.0f));
	g.strokePath(path, strokeType);
}

void KnobAndAttachment_ForOscShape::paintPulse(Graphics& g, Path path, int pulseWidth) {
	auto polarityChange_x{ 6.0f + (18.0f * (pulseWidth * .01f)) };
	Line<float> line1{ 6.0f, 17.0f, 6.0f, 8.0f };
	Line<float> line2{ 6.0f, 8.0f, polarityChange_x, 8.0f };
	Line<float> line3{ polarityChange_x, 8.0f, polarityChange_x, 17.0f };
	Line<float> line4{ polarityChange_x, 17.0f, 24.0f, 17.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	path.addLineSegment(line3, 0.5f);
	path.addLineSegment(line4, 0.5f);
	path.applyTransform(AffineTransform::translation(5.0f, 5.0f));
	g.strokePath(path, strokeType);
	g.setFont(GUI::fontFor_PulseWidthText);
	Rectangle<int> pwTextArea{ 11, 23, 18, 11 };
	g.drawText((String)(pulseWidth), pwTextArea, Justification::centred);
}

void KnobAndAttachment_ForOscShape::attachKnobToExposedParameter() {
	attachment.reset(new SliderAttachment(*exposedParams, InfoForExposedParameters::get().IDfor(paramIndex).toString(), knob));
}

void KnobAndAttachment_ForOscShape::parameterValueChanged(int changedParamIndex, float newValue) {
	if (changedParamIndex == paramIndex) {
		auto& info{ InfoForExposedParameters::get() };
		auto paramID{ info.IDfor(paramIndex) };
		auto paramaterPtr{ exposedParams->getParameter(paramID) };
		auto currentChoice{ roundToInt(paramaterPtr->convertFrom0to1(newValue)) };
		choiceNum = currentChoice;
		MessageManagerLock mmLock;
		repaint();
	}
}

void KnobAndAttachment_ForOscShape::parameterGestureChanged(int /*paramIndex*/, bool /*gestureIsStarting*/) {
}

void KnobAndAttachment_ForOscShape::deleteAttachmentBeforeKnobToPreventMemLeak() {
	attachment = nullptr;
}

KnobAndAttachment_ForOscShape::~KnobAndAttachment_ForOscShape() {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex) };
	auto paramaterPtr{ exposedParams->getParameter(paramID) };
	paramaterPtr->removeListener(this);
}
