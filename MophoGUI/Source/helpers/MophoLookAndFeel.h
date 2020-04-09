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

	void drawButtonBackground
	(
		Graphics& g, 
		Button& button, 
		const Colour& /*backgroundColour*/, 
		bool /*shouldDrawButtonAsHighlighted*/, 
		bool shouldDrawButtonAsDown
	) override
	{
		auto baseColour{ Color::button };

		if (shouldDrawButtonAsDown)
			baseColour = baseColour.darker(0.5f);

		g.setColour(baseColour);

		g.fillAll(baseColour);
		LookAndFeel_V2::drawBevel(g, 0, 0, button.getWidth(), button.getHeight(), 2, 
			shouldDrawButtonAsDown ? Color::button.darker(1.0f) : Color::button.brighter(0.5f),
			shouldDrawButtonAsDown ? Color::button.brighter(0.45f) : Color::button.darker(1.5f), false);
	}

	void drawButtonText
	(
		Graphics& g, 
		TextButton& button,
		bool /*shouldDrawButtonAsHighlighted*/, 
		bool shouldDrawButtonAsDown
	) override
	{
		Font font{ "Arial", "Black", 11.0f };
		g.setFont(font);
		g.setColour(shouldDrawButtonAsDown ? Color::controlText.darker(0.5f) : Color::controlText);
		g.drawFittedText(button.getButtonText(), 0, 0, button.getWidth(), button.getHeight(), Justification::centred, 1);
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
		return PopupMenu::Options()
			.withTargetComponent(&box)
			.withItemThatMustBeVisible(box.getSelectedId())
			.withMinimumWidth(box.getWidth())
			.withMaximumNumColumns(1)
			.withStandardItemHeight(label.getHeight());
	}

	void drawPopupMenuBackground(Graphics& g, int /*width*/, int /*height*/) override
	{
		g.fillAll(Color::black.brighter(0.2f));
	}

	void drawPopupMenuItem
	(
		Graphics& g, 
		const Rectangle<int>& area,
		const bool /*isSeparator*/, 
		const bool isActive,
		const bool isHighlighted, 
		const bool isTicked,
		const bool hasSubMenu, 
		const String& text,
		const String& /*shortcutKeyText*/,
		const Drawable* /*icon*/, 
		const Colour* const /*textColourToUse*/
	) override
	{
		auto textColour{ Color::controlText };
		
		auto r = area.reduced(1);

		if (isHighlighted && isActive)
		{
			g.setColour(findColour(PopupMenu::highlightedBackgroundColourId));
			g.fillRect(r);

			g.setColour(findColour(PopupMenu::highlightedTextColourId));
		}
		else
		{
			g.setColour(textColour.withMultipliedAlpha(isActive ? 1.0f : 0.5f));
		}

		r.reduce(jmin(5, area.getWidth() / 20), 0);

		Font font{ "Arial", "Narrow Bold", 12.0f };
		g.setFont(font);

		auto iconArea = r.removeFromLeft(8).toFloat();

		if (isTicked)
		{
			auto tick{ getTickShape(8.0f) };
			g.fillPath(tick, AffineTransform::translation(0.0f, 4.0f));
		}

		if (hasSubMenu)
		{
			auto arrowH = 0.6f * getPopupMenuFont().getAscent();

			auto x = static_cast<float> (r.removeFromRight((int)arrowH).getX());
			auto halfH = static_cast<float> (r.getCentreY());

			Path path;
			path.startNewSubPath(x, halfH - arrowH * 0.5f);
			path.lineTo(x + arrowH * 0.6f, halfH);
			path.lineTo(x, halfH + arrowH * 0.5f);

			g.strokePath(path, PathStrokeType(2.0f));
		}

		r.removeFromRight(3);
		g.drawFittedText(text, r, Justification::centredLeft, 1);
	}

	void getIdealPopupMenuItemSize
	(
		const String& /*text*/, 
		const bool isSeparator,
		int standardMenuItemHeight, 
		int& idealWidth, 
		int& idealHeight
	) override
	{
		if (isSeparator)
		{
			idealWidth = 50;
			idealHeight = standardMenuItemHeight > 0 ? standardMenuItemHeight / 10 : 10;
		}
		else
		{
			auto font = getPopupMenuFont();

			if (standardMenuItemHeight > 0 && font.getHeight() > standardMenuItemHeight / 1.3f)
				font.setHeight(standardMenuItemHeight / 1.3f);

			idealHeight = standardMenuItemHeight > 0 ? standardMenuItemHeight : roundToInt(font.getHeight() * 1.3f);
		}
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MophoLookAndFeel)
};