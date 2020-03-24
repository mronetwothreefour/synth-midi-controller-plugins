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
		l.setStart(center.x, float(y + 7));
		l.setEnd(center.x, float(y + 1));
		Path p;
		p.addArrow(l, 1.0f, 8.0f, 6.0f);
		p.applyTransform(AffineTransform::rotation(angle, center.x, center.y));
		g.setColour(Color::black);
		g.fillPath(p);
	};

	void drawLabel(Graphics& g, Label& label) override
	{
		Font font{ "Arial", "Narrow Bold", 13.0f };
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

	Rectangle<int> getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) override
	{
		const TextLayout tl(layoutTooltipText(tipText, Colours::black));

		auto w = (int)(tl.getWidth() + 16.0f);
		auto h = (int)(tl.getHeight() + 14.0f);

		return Rectangle<int>(screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
			screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6,
			w, h)
			.constrainedWithin(parentArea);
	}

	void drawTooltip(Graphics& g, const String& text, int width, int height) override
	{
		Rectangle<int> bounds(width, height);

		g.setColour(Color::black.brighter(0.2f));
		g.fillRect(bounds.toFloat());

		g.setColour(Colours::white);
		g.drawRect(bounds.toFloat(), 2.0f);

		layoutTooltipText(text, findColour(TooltipWindow::textColourId))
			.draw(g, { static_cast<float> (width), static_cast<float> (height) });
	}

	void drawToggleButton
	(
		Graphics& g,
		ToggleButton& button,
		bool shouldDrawButtonAsHighlighted,
		bool shouldDrawButtonAsDown
	) override
	{
		drawTickBox(g, button,
			0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(),
			button.getToggleState(),
			button.isEnabled(),
			shouldDrawButtonAsHighlighted,
			shouldDrawButtonAsDown);
	}

	void drawTickBox
	(
		Graphics& g,
		Component& /*component*/,
		float x, float y, float w, float h,
		const bool ticked,
		const bool /*isEnabled*/,
		const bool /*shouldDrawButtonAsHighlighted*/,
		const bool /*shouldDrawButtonAsDown*/
		) override
	{
		g.setColour(ticked ? Color::switchOn : Color::switchOff);
		g.fillEllipse(x, y, w, h);
	}

	void drawComboBox(Graphics& g, int width, int height, bool /*isButtonDown*/,
		int /*buttonX*/, int /*buttonY*/, int /*buttonW*/, int /*buttonH*/, ComboBox& /*box*/) override
	{
		Rectangle<int> boxBounds(0, 0, width, height);

		g.setColour(Color::black);
		g.fillRect(boxBounds);

		g.setColour(Color::device);
		Path path;
		path.addTriangle(float(width - 11), 6.0f, float(width - 3), 6.0f, float(width - 7), 10.0f);
		g.fillPath(path);
	}

	void positionComboBoxText(ComboBox& box, Label& label) override
	{
		label.setBounds(0, 0, box.getWidth() - 11, box.getHeight());
	};

	PopupMenu::Options getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) override
	{
		return PopupMenu::Options().withTargetComponent(&box)
			.withItemThatMustBeVisible(box.getSelectedId())
			.withMinimumWidth(box.getWidth())
			.withMaximumNumColumns(1)
			.withStandardItemHeight(label.getHeight());
	}

	void drawPopupMenuBackground(Graphics& g, int /*width*/, int /*height*/) override
	{
		g.fillAll(Color::black.brighter(0.2f));
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MophoLookAndFeel)
};