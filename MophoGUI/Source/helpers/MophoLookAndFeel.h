#pragma once

#include <JuceHeader.h>

#include "../helpers/CustomColors.h"

class MophoLookAndFeel :
	public LookAndFeel_V4
{
public:
	MophoLookAndFeel() {}

	~MophoLookAndFeel() {}

	void drawRotarySlider(Graphics& g, int /*x*/, int y, int width, int /*height*/,
		float sliderPos, const float rotaryStartAngle,
		const float rotaryEndAngle, Slider& /*slider*/) override
	{
		Point<float> center{ float(width) / 2.0f, float(width) / 2.0f };

		// draw pointer and rotate it according to the slider's value
		auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
		Line<float> l;
		l.setStart(center);
		l.setEnd(center.x, float(y + 1));
		Path p;
		p.addArrow(l, 1.0f, 8.0f, 6.0f);
		p.applyTransform(AffineTransform::rotation(angle, center.x, center.y));
		g.setColour(Color::black);
		g.fillPath(p);
	};

	void drawLabel(Graphics& g, Label& label) override
	{
		Font font("Arial", "Narrow", JUCE_LIVE_CONSTANT(13.0f));
		g.setFont(font);
		g.setColour(Color::controlText);
		auto textArea = label.getLocalBounds();
		g.drawText(label.getText(), textArea, Justification::centred, false);
	}

	static TextLayout layoutTooltipText(const String& text, Colour colour) noexcept
	{
		Font tooltipFont("Arial", "Narrow Bold", 13.0f);
		const int maxToolTipWidth = 400;

		AttributedString s;
		s.setJustification(Justification::centred);
		s.append(text, tooltipFont, colour);

		TextLayout tl;
		tl.createLayout(s, (float)maxToolTipWidth);
		return tl;
	}

	void drawTooltip(Graphics& g, const String& text, int width, int height) override
	{
		Rectangle<int> bounds(width, height);
		auto cornerSize = 10.0f;

		g.setColour(Color::black);
		g.fillRoundedRectangle(bounds.toFloat(), cornerSize);

		g.setColour(Colours::white);
		g.drawRoundedRectangle(bounds.toFloat().reduced(0.5f, 0.5f), cornerSize, 1.0f);

		layoutTooltipText(text, findColour(TooltipWindow::textColourId))
			.draw(g, { static_cast<float> (width), static_cast<float> (height) });
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MophoLookAndFeel)
};