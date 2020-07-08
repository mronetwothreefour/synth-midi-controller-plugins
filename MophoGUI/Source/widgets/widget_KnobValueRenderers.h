#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Fonts.h"
#include "../helpers/helper_Identifiers.h"



class ValueStringRendererForKnobs :
	public Component,
	public Slider::Listener
{
	Slider* knob;
	String valueString;
	IntToContextualStringConverter* converter;

public:
	ValueStringRendererForKnobs(Slider* knob, uint8 param) :
		knob{ knob },
		converter{ InfoForExposedParameters::get().converterFor(param) }
	{
		knob->addListener(this);
		sliderValueChanged(knob);
	}

	~ValueStringRendererForKnobs() { 
		knob->removeListener(this); 
	}

	void paint(Graphics& g) override {
		Font font(FontsDB::family_Global, FontsDB::style_ForKnobValueDisplay, FontsDB::size_ForKnobValueDisplay);
		g.setFont(font);
		g.setColour(Color::controlText);
		g.drawText(valueString, getLocalBounds(), Justification::centred);
	}

	void sliderValueChanged(Slider* slider) override {
		if (slider == knob) {
			auto newValue{ (uint8)roundToInt(slider->getValue()) };
			valueString = converter->convert(newValue);
			repaint();
		}
	}
};



class WaveShapeRendererForKnobs :
	public Component,
	public Slider::Listener
{
	Slider* knob;
	enum class OscWaveShape { off, sawtooth, triangle, sawTriMix, pulse };

public:
	explicit WaveShapeRendererForKnobs(Slider* knob) :
		knob{ knob }
	{
		knob->addListener(this);
	}

	~WaveShapeRendererForKnobs() { 
		knob->removeListener(this); 
	}

	void paint(Graphics& g) override {
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

	void paintText(Graphics& g, String text) {
		Font font{ FontsDB::family_Global, FontsDB::style_ForKnobValueDisplay, FontsDB::size_ForKnobValueDisplay };
		g.setFont(font);
		g.drawText(text, getLocalBounds(), Justification::centred);
	}

	void paintSawtooth(Graphics& g, Path path, PathStrokeType strokeType) {
		Line<float> line1{ 6.0f, 20.0f, 21.0f, 8.0f };
		Line<float> line2{ 21.0f, 8.0f, 21.0f, 20.0f };
		path.addLineSegment(line1, 0.5f);
		path.addLineSegment(line2, 0.5f);
		g.strokePath(path, strokeType);
	}

	void paintTriangle(Graphics& g, Path path, PathStrokeType strokeType) {
		Line<float> line1{ 7.0f, 20.0f, 15.0f, 9.0f };
		Line<float> line2{ 15.0f, 9.0f, 23.0f, 20.0f };
		path.addLineSegment(line1, 0.5f);
		path.addLineSegment(line2, 0.5f);
		g.strokePath(path, strokeType);
	}

	void paintSawTriMix(Graphics& g, Path path, PathStrokeType strokeType) {
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

	void paintPulse(Graphics& g, Path path, PathStrokeType strokeType, int pulseWidth) {
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

		Font pwText{ FontsDB::family_Global, FontsDB::style_ForPulseWidthText, FontsDB::size_ForPulseWidthText };
		g.setFont(pwText);

		Rectangle<int> pwTextArea{ 6, 18, 18, 11 };
		g.drawText((String)(pulseWidth), pwTextArea, Justification::centred);
	}

	void sliderValueChanged(Slider* slider) override {
		if (slider == knob) 
			repaint(); 
	}
};

