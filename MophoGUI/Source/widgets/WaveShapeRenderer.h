#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"
#include "../helpers/ParameterTools.h"
#include "KnobWidgets.h"

//==============================================================================
// Creates graphical representations of various wave shapes.
// Oscillator KnobWidgets use this to display their current values
class WaveShapeRenderer : public Component
{
public:
	WaveShapeRenderer()
	{
		auto knob_diameter{ 30 };
		setSize(knob_diameter, knob_diameter);
	}

	void paint(Graphics& g) override
	{
		g.setColour(Color::controlText);
		Path path;
		if (selectedShape == MophoOscWaveShape::sawtooth)
		{
			Line<float> line1{ 6.0f, 20.0f, 21.0f, 8.0f };
			Line<float> line2{ 21.0f, 8.0f, 21.0f, 20.0f };
			path.addLineSegment(line1, 0.5f);
			path.addLineSegment(line2, 0.5f);
			PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
			g.strokePath(path, strokeType);
		}
		if (selectedShape == MophoOscWaveShape::triangle)
		{
			Line<float> line1{ 7.0f, 20.0f, 15.0f, 9.0f };
			Line<float> line2{ 15.0f, 9.0f, 23.0f, 20.0f };
			path.addLineSegment(line1, 0.5f);
			path.addLineSegment(line2, 0.5f);
			PathStrokeType strokeType{ 1.0f, PathStrokeType::mitered, PathStrokeType::rounded };
			g.strokePath(path, strokeType);
		}
		if (selectedShape == MophoOscWaveShape::sawTriMix)
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
		if (selectedShape == MophoOscWaveShape::pulse)
		{
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
			g.drawText((String)(pulseWidth - 1), pwTextArea, Justification::centred);
		}
	}

	void clear() noexcept { selectedShape = MophoOscWaveShape::off; repaint(); }
	void drawSawtooth() noexcept { selectedShape = MophoOscWaveShape::sawtooth; repaint(); }
	void drawTriangle() noexcept { selectedShape = MophoOscWaveShape::triangle; repaint(); }
	void drawSawTri() noexcept { selectedShape = MophoOscWaveShape::sawTriMix; repaint(); }
	void drawPulse(int width) noexcept { selectedShape = MophoOscWaveShape::pulse; pulseWidth = width;  repaint(); }

private:
	int selectedShape{ MophoOscWaveShape::sawtooth };
	int pulseWidth{ 50 };

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(WaveShapeRenderer)
};

