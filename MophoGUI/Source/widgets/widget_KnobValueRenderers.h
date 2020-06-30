#pragma once

#include <JuceHeader.h>

#include "../helpers/helper_CustomColors.h"
#include "../helpers/helper_Fonts.h"
#include "../helpers/helper_Identifiers.h"
#include "../parameters/parameters_SynthParameters.h"


class ValueStringRendererForKnobs :
	public Component,
	public Slider::Listener
{
	Slider* knob;
	String valueString;
	IntToContextualStringConverter* converter;

public:
	ValueStringRendererForKnobs(Slider* knob, SynthParameter param) :
		knob{ knob },
		converter{ param.converter }
	{
		knob->addListener(this);
		sliderValueChanged(knob);
	}

	~ValueStringRendererForKnobs() { knob->removeListener(this); }

	void paint(Graphics& g) override
	{
		Font font(FontsDB::family_Global, FontsDB::style_ForKnobValueDisplay, FontsDB::size_ForKnobValueDisplay);
		g.setFont(font);
		g.setColour(Color::controlText);
		g.drawText(valueString, getLocalBounds(), Justification::centred);
	}

	void sliderValueChanged(Slider* slider) override
	{
		if (slider == knob)
		{
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

	enum class OscWaveShape
	{
		off, sawtooth, triangle, sawTriMix, pulse
	};

public:
	explicit WaveShapeRendererForKnobs(Slider* knob) :
		knob{ knob }
	{
		knob->addListener(this);
	}

	~WaveShapeRendererForKnobs() { knob->removeListener(this); }

	void paint(Graphics& g) override
	{
		if (knob != nullptr)
		{
			auto knobValue{ roundToInt(knob->getValue()) };
			g.setColour(Color::controlText);
			if (knobValue == (int)OscWaveShape::off)
			{
				Font font{ FontsDB::family_Global, FontsDB::style_ForKnobValueDisplay, FontsDB::size_ForKnobValueDisplay };
				g.setFont(font);
				g.drawText("OFF", getLocalBounds(), Justification::centred);
			}
			Path path;
			if (knobValue == (int)OscWaveShape::sawtooth)
			{
				Line<float> line1{ 6.0f, 20.0f, 21.0f, 8.0f };
				Line<float> line2{ 21.0f, 8.0f, 21.0f, 20.0f };
				path.addLineSegment(line1, 0.5f);
				path.addLineSegment(line2, 0.5f);
				PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
				g.strokePath(path, strokeType);
			}
			if (knobValue == (int)OscWaveShape::triangle)
			{
				Line<float> line1{ 7.0f, 20.0f, 15.0f, 9.0f };
				Line<float> line2{ 15.0f, 9.0f, 23.0f, 20.0f };
				path.addLineSegment(line1, 0.5f);
				path.addLineSegment(line2, 0.5f);
				PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
				g.strokePath(path, strokeType);
			}
			if (knobValue == (int)OscWaveShape::sawTriMix)
			{
				Line<float> line1{ 5.0f, 15.0f, 10.0f, 8.0f };
				Line<float> line2{ 10.0f, 8.0f, 15.0f, 15.0f };
				Line<float> line3{ 15.0f, 15.0f, 15.0f, 23.0f };
				Line<float> line4{ 15.0f, 23.0f, 25.0f, 15.0f };
				path.addLineSegment(line1, 0.5f);
				path.addLineSegment(line2, 0.5f);
				path.addLineSegment(line3, 0.5f);
				path.addLineSegment(line4, 0.5f);
				PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
				g.strokePath(path, strokeType);
			}
			if (knobValue >= (int)OscWaveShape::pulse)
			{
				int pulseWidth{ knobValue - 4 };
				auto polaritySwitch_x{ 6.0f + (18.0f * (pulseWidth * .01f)) };
				Line<float> line1{ 6.0f, 17.0f, 6.0f, 8.0f };
				Line<float> line2{ 6.0f, 8.0f, polaritySwitch_x, 8.0f };
				Line<float> line3{ polaritySwitch_x, 8.0f, polaritySwitch_x, 17.0f };
				Line<float> line4{ polaritySwitch_x, 17.0f, 24.0f, 17.0f };
				path.addLineSegment(line1, 0.5f);
				path.addLineSegment(line2, 0.5f);
				path.addLineSegment(line3, 0.5f);
				path.addLineSegment(line4, 0.5f);
				PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
				g.strokePath(path, strokeType);

				Font pwText{ "Arial", "Narrow", 11.0f };
				g.setFont(pwText);

				Rectangle<int> pwTextArea{ 6, 18, 18, 11 };
				g.drawText((String)(pulseWidth), pwTextArea, Justification::centred);
			}
		}
		else
		{
			Font font{ FontsDB::family_Global, FontsDB::style_ForKnobValueDisplay, FontsDB::size_ForKnobValueDisplay };
			g.setFont(font);
			g.drawText("ERR", getLocalBounds(), Justification::centred);
		}
	}

	void sliderValueChanged(Slider* slider) override
	{
		if (slider == knob)
			repaint();
	}
};

