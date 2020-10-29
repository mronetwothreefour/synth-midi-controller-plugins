#include "guiRenderer_ForKnobWaveShapes.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Fonts.h"



RendererForKnobWaveShapes::RendererForKnobWaveShapes(Slider* knob) :
	knob{ knob }
{
	knob->addListener(this);
}

void RendererForKnobWaveShapes::sliderValueChanged(Slider* slider) {
	if (slider == knob)
		repaint();
}

void RendererForKnobWaveShapes::paint(Graphics& g) {
	if (knob != nullptr) {
		auto knobValue{ roundToInt(knob->getValue()) };
		Path path;
		PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
		g.setColour(Color::controlText);
		if (knobValue == (int)OscWaveShape::off)
			paintText(g, "OFF");
		if (knobValue == (int)OscWaveShape::sawtooth)
			paintSawtooth(g, path, strokeType);
		if (knobValue == (int)OscWaveShape::triangle)
			paintTriangle(g, path, strokeType);
		if (knobValue == (int)OscWaveShape::sawTriMix)
			paintSawTriMix(g, path, strokeType);
		if (knobValue >= (int)OscWaveShape::pulse)
			paintPulse(g, path, strokeType, knobValue - (int)OscWaveShape::pulse);
	}
	else
		paintText(g, "ERR");
}

void RendererForKnobWaveShapes::paintText(Graphics& g, String text) {
	g.setFont(FontsMenu::fontFor_KnobValueDisplays);
	g.drawText(text, getLocalBounds(), Justification::centred);
}

void RendererForKnobWaveShapes::paintSawtooth(Graphics& g, Path path, PathStrokeType strokeType) {
	Line<float> line1{ 6.0f, 20.0f, 21.0f, 8.0f };
	Line<float> line2{ 21.0f, 8.0f, 21.0f, 20.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	g.strokePath(path, strokeType);
}

void RendererForKnobWaveShapes::paintTriangle(Graphics& g, Path path, PathStrokeType strokeType) {
	Line<float> line1{ 7.0f, 20.0f, 15.0f, 9.0f };
	Line<float> line2{ 15.0f, 9.0f, 23.0f, 20.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	g.strokePath(path, strokeType);
}

void RendererForKnobWaveShapes::paintSawTriMix(Graphics& g, Path path, PathStrokeType strokeType) {
	Line<float> line1{ 5.0f, 15.0f, 10.0f, 8.0f };
	Line<float> line2{ 10.0f, 8.0f, 15.0f, 15.0f };
	Line<float> line3{ 15.0f, 15.0f, 15.0f, 23.0f };
	Line<float> line4{ 15.0f, 23.0f, 25.0f, 15.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	path.addLineSegment(line3, 0.5f);
	path.addLineSegment(line4, 0.5f);
	g.strokePath(path, strokeType);
}

void RendererForKnobWaveShapes::paintPulse(Graphics& g, Path path, PathStrokeType strokeType, int pulseWidth) {
	auto polarityChange_x{ 6.0f + (18.0f * (pulseWidth * .01f)) };
	Line<float> line1{ 6.0f, 17.0f, 6.0f, 8.0f };
	Line<float> line2{ 6.0f, 8.0f, polarityChange_x, 8.0f };
	Line<float> line3{ polarityChange_x, 8.0f, polarityChange_x, 17.0f };
	Line<float> line4{ polarityChange_x, 17.0f, 24.0f, 17.0f };
	path.addLineSegment(line1, 0.5f);
	path.addLineSegment(line2, 0.5f);
	path.addLineSegment(line3, 0.5f);
	path.addLineSegment(line4, 0.5f);
	g.strokePath(path, strokeType);
	Font pwText{ FontsMenu::family_Global, FontsMenu::style_ForPulseWidthText, FontsMenu::size_ForPulseWidthText };
	g.setFont(pwText);
	Rectangle<int> pwTextArea{ 6, 18, 18, 11 };
	g.drawText((String)(pulseWidth), pwTextArea, Justification::centred);
}

RendererForKnobWaveShapes::~RendererForKnobWaveShapes() {
	knob->removeListener(this);
}
