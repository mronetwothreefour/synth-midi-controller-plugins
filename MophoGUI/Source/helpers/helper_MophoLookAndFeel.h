#pragma once

#include <JuceHeader.h>

#include "helper_CustomColors.h"
#include "helper_Identifiers.h"

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
		if (label.getComponentID() == "label_txTime")
			g.fillAll(Color::black);
		Font pgmNameEditorFont{ "Arial", "Black", 18.0f };
		Font font{ "Arial", "Narrow Bold", 13.0f };
		label.setFont(label.getComponentID() == "pgmNameEditor" ? pgmNameEditorFont : font);
		g.setFont(label.getComponentID() == "pgmNameEditor" ? pgmNameEditorFont : font);
		g.setColour(label.getComponentID() == "pgmNameEditor" ? Colours::transparentBlack : Color::controlText);
		auto textArea = label.getLocalBounds();
		g.drawText(label.getText(), textArea, Justification::centred, false);
	}

	void fillTextEditorBackground(Graphics& g, int /*width*/, int /*height*/, TextEditor& /*textEditor*/) override
	{
		g.fillAll(Color::black);
	}

	void drawTextEditorOutline(Graphics& /*g*/, int /*width*/, int /*height*/, TextEditor& /*textEditor*/) override {}

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

	//void drawTickBox
	//(
	//	Graphics& g,
	//	Component& component,
	//	float x, float y, float w, float h,
	//	const bool ticked,
	//	const bool /*isEnabled*/,
	//	const bool shouldDrawButtonAsHighlighted,
	//	const bool /*shouldDrawButtonAsDown*/
	//	) override
	//{
	//	if (component.getComponentID() == ID::paramToggle.toString())
	//	{
	//		g.setColour(ticked ? Color::switchOn : Color::switchOff);
	//		g.fillEllipse(x, y, w, h);
	//	}

	//	if (component.getComponentID() == ID::pgmSlotToggle.toString())
	//	{
	//		auto buttonColor{ Color::device };
	//		if (shouldDrawButtonAsHighlighted) buttonColor = buttonColor.brighter(0.4f);
	//		if (ticked) buttonColor = buttonColor.brighter(0.7f);
	//		g.setColour(buttonColor);
	//		g.fillRect(x, y, w, h);
	//		g.setColour(Color::black);
	//		Font font{ "Arial", "Regular", 11.0f };
	//		g.setFont(font);
	//		Rectangle<float> textArea{ x + 3, y, w - 3, h };
	//		g.drawText(component.getName(), textArea, Justification::centredLeft);
	//	}
	//}

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

	//==============================================================================

	class LookAndFeel_V4_DocumentWindowButton : public Button
	{
	public:
		LookAndFeel_V4_DocumentWindowButton(const String& name, Colour c, const Path& normal, const Path& toggled)
			: Button(name), colour(c), normalShape(normal), toggledShape(toggled)
		{
		}

		void paintButton(Graphics& g, bool shouldDrawButtonAsHighlighted, bool /*shouldDrawButtonAsDown*/) override
		{
			auto background = Color::black;

			g.fillAll(shouldDrawButtonAsHighlighted ? background.brighter(0.34f) : background);

			g.setColour(Color::controlText);

			auto& p = normalShape;

			auto reducedRect = Justification(Justification::centred)
				.appliedToRectangle(Rectangle<int>(getHeight(), getHeight()), getLocalBounds())
				.toFloat()
				.reduced(getHeight() * 0.3f);

			g.fillPath(p, p.getTransformToScaleToFit(reducedRect, true));
		}

	private:
		Colour colour;
		Path normalShape, toggledShape;

		JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(LookAndFeel_V4_DocumentWindowButton)
	};

	Button* createDocumentWindowButton(int buttonType) override
	{
		Path shape;
		auto crossThickness = 0.25f;

		if (buttonType == DocumentWindow::closeButton)
		{
			shape.addLineSegment({ 0.0f, 0.0f, 1.0f, 1.0f }, crossThickness);
			shape.addLineSegment({ 1.0f, 0.0f, 0.0f, 1.0f }, crossThickness);

			return new LookAndFeel_V4_DocumentWindowButton("close", Color::controlText, shape, shape);
		}

		jassertfalse;
		return nullptr;
	}

	void positionDocumentWindowButtons
	(
		DocumentWindow&,
		int titleBarX, int titleBarY,
		int titleBarW, int titleBarH,
		Button* minimiseButton,
		Button* maximiseButton,
		Button* closeButton,
		bool positionTitleBarButtonsOnLeft
	) override
	{
		titleBarH = jmin(titleBarH, titleBarH - titleBarY);

		auto buttonW = static_cast<int> (titleBarH * 1.2);

		auto x = positionTitleBarButtonsOnLeft ? titleBarX
			: titleBarX + titleBarW - buttonW;

		if (closeButton != nullptr)
		{
			closeButton->setBounds(x, titleBarY, buttonW, titleBarH);
			x += positionTitleBarButtonsOnLeft ? buttonW : -buttonW;
		}

		if (positionTitleBarButtonsOnLeft)
			std::swap(minimiseButton, maximiseButton);

		if (maximiseButton != nullptr)
		{
			maximiseButton->setBounds(x, titleBarY, buttonW, titleBarH);
			x += positionTitleBarButtonsOnLeft ? buttonW : -buttonW;
		}

		if (minimiseButton != nullptr)
			minimiseButton->setBounds(x, titleBarY, buttonW, titleBarH);
	}

	void drawDocumentWindowTitleBar
	(
		DocumentWindow& window, 
		Graphics& g,
		int w, 
		int h, 
		int titleSpaceX, 
		int titleSpaceW,
		const Image* icon, 
		bool drawTitleTextOnLeft
	) override
	{
		if (w * h == 0)
			return;

		auto isActive = window.isActiveWindow();

		g.fillAll(Color::black);

		Font font("Arial", "Black", 18.0f);
		g.setFont(font);

		auto textW = font.getStringWidth(window.getName());
		auto iconW = 0;
		auto iconH = 0;

		if (icon != nullptr)
		{
			iconH = static_cast<int> (font.getHeight());
			iconW = icon->getWidth() * iconH / icon->getHeight() + 4;
		}

		textW = jmin(titleSpaceW, textW + iconW);
		auto textX = drawTitleTextOnLeft ? titleSpaceX
			: jmax(titleSpaceX, (w - textW) / 2);

		if (textX + textW > titleSpaceX + titleSpaceW)
			textX = titleSpaceX + titleSpaceW - textW;

		if (icon != nullptr)
		{
			g.setOpacity(isActive ? 1.0f : 0.6f);
			g.drawImageWithin(*icon, textX, (h - iconH) / 2, iconW, iconH,
				RectanglePlacement::centred, false);
			textX += iconW;
			textW -= iconW;
		}

		if (window.isColourSpecified(DocumentWindow::textColourId) || isColourSpecified(DocumentWindow::textColourId))
			g.setColour(window.findColour(DocumentWindow::textColourId));
		else
			g.setColour(getCurrentColourScheme().getUIColour(ColourScheme::defaultText));

		g.drawText(window.getName(), textX, 0, textW, h, Justification::centredLeft, true);
	}

	//==============================================================================

	void createTabTextLayout
	(
		const TabBarButton& button, 
		float length, float /*depth*/,
		Colour colour, TextLayout& textLayout
	)
	{
		Font font("Arial", "Black", 18.0f);

		AttributedString s;
		s.setJustification(Justification::centred);
		s.append(button.getButtonText().trim(), font, colour);

		textLayout.createLayout(s, length);
	}

	void drawTabButton
	(
		TabBarButton& button, 
		Graphics& g, 
		bool isMouseOver, 
		bool isMouseDown
	) override
	{
		const Rectangle<int> activeArea(button.getActiveArea());

		const TabbedButtonBar::Orientation o = button.getTabbedButtonBar().getOrientation();

		const Colour bkg(button.getTabBackgroundColour());

		if (button.getToggleState())
		{
			g.setColour(bkg);
		}
		else
		{
			Point<int> p1, p2;

			switch (o)
			{
			case TabbedButtonBar::TabsAtBottom:   p1 = activeArea.getBottomLeft(); p2 = activeArea.getTopLeft();    break;
			case TabbedButtonBar::TabsAtTop:      p1 = activeArea.getTopLeft();    p2 = activeArea.getBottomLeft(); break;
			case TabbedButtonBar::TabsAtRight:    p1 = activeArea.getTopRight();   p2 = activeArea.getTopLeft();    break;
			case TabbedButtonBar::TabsAtLeft:     p1 = activeArea.getTopLeft();    p2 = activeArea.getTopRight();   break;
			default:                              jassertfalse; break;
			}

			g.setGradientFill(ColourGradient(bkg.brighter(0.2f), p1.toFloat(),
				bkg.darker(0.1f), p2.toFloat(), false));
		}

		g.fillRect(activeArea);

		g.setColour(button.findColour(TabbedButtonBar::tabOutlineColourId));

		Rectangle<int> r(activeArea);

		if (o != TabbedButtonBar::TabsAtBottom)   g.fillRect(r.removeFromTop(1));
		if (o != TabbedButtonBar::TabsAtTop)      g.fillRect(r.removeFromBottom(1));
		if (o != TabbedButtonBar::TabsAtRight)    g.fillRect(r.removeFromLeft(1));
		if (o != TabbedButtonBar::TabsAtLeft)     g.fillRect(r.removeFromRight(1));

		const float alpha = button.isEnabled() ? ((isMouseOver || isMouseDown) ? 1.0f : 0.8f) : 0.3f;

		Colour col(bkg.contrasting().withMultipliedAlpha(alpha));

		if (TabbedButtonBar* bar = button.findParentComponentOfClass<TabbedButtonBar>())
		{
			TabbedButtonBar::ColourIds colID = button.isFrontTab() ? TabbedButtonBar::frontTextColourId
				: TabbedButtonBar::tabTextColourId;

			if (bar->isColourSpecified(colID))
				col = bar->findColour(colID);
			else if (isColourSpecified(colID))
				col = findColour(colID);
		}

		const Rectangle<float> area(button.getTextArea().toFloat());

		float length = area.getWidth();
		float depth = area.getHeight();

		if (button.getTabbedButtonBar().isVertical())
			std::swap(length, depth);

		TextLayout textLayout;
		createTabTextLayout(button, length, depth, col, textLayout);

		AffineTransform t;

		switch (o)
		{
		case TabbedButtonBar::TabsAtLeft:   t = t.rotated(MathConstants<float>::pi * -0.5f).translated(area.getX(), area.getBottom()); break;
		case TabbedButtonBar::TabsAtRight:  t = t.rotated(MathConstants<float>::pi * 0.5f).translated(area.getRight(), area.getY()); break;
		case TabbedButtonBar::TabsAtTop:
		case TabbedButtonBar::TabsAtBottom: t = t.translated(area.getX(), area.getY()); break;
		default:                            jassertfalse; break;
		}

		textLayout.draw(g, Rectangle<float>(depth, length));
	}

	//==============================================================================
	AlertWindow* createAlertWindow(const String& title, const String& message,
		const String& button1, const String& button2, const String& button3,
		AlertWindow::AlertIconType iconType,
		int numButtons, Component* associatedComponent)
	{
		setColour(AlertWindow::textColourId, Color::black);

		auto boundsOffset = 50;

		auto* aw = LookAndFeel_V2::createAlertWindow(title, message, button1, button2, button3,
			iconType, numButtons, associatedComponent);

		auto bounds = aw->getBounds();
		bounds = bounds.withSizeKeepingCentre(bounds.getWidth() + boundsOffset, bounds.getHeight() + boundsOffset);
		aw->setBounds(bounds);

		for (auto* child : aw->getChildren())
			if (auto* button = dynamic_cast<TextButton*> (child))
			{
				button->setSize(50, 21);
				button->setBounds(button->getBounds() + Point<int>(25, 40));
			}

		return aw;
	}

	void drawAlertBox(Graphics& g, AlertWindow& alert,
		const Rectangle<int>& textArea, TextLayout& textLayout)
	{
		g.setColour(Color::black);
		g.drawRect(alert.getLocalBounds().toFloat(), 2.0f);

		auto bounds = alert.getLocalBounds().reduced(1);
		g.reduceClipRegion(bounds);

		g.setColour(Color::device);
		g.fillRect(bounds.toFloat());

		auto iconSpaceUsed = 0;

		auto iconWidth = 80;
		auto iconSize = jmin(iconWidth + 50, bounds.getHeight() + 20);

		if (alert.containsAnyExtraComponents() || alert.getNumButtons() > 2)
			iconSize = jmin(iconSize, textArea.getHeight() + 50);

		Rectangle<int> iconRect(iconSize / -10, iconSize / -10,
			iconSize, iconSize);

		if (alert.getAlertType() != AlertWindow::NoIcon)
		{
			Path icon;
			char character;
			uint32 colour;

			if (alert.getAlertType() == AlertWindow::WarningIcon)
			{
				character = '!';

				icon.addTriangle(iconRect.getX() + iconRect.getWidth() * 0.5f, (float)iconRect.getY(),
					static_cast<float> (iconRect.getRight()), static_cast<float> (iconRect.getBottom()),
					static_cast<float> (iconRect.getX()), static_cast<float> (iconRect.getBottom()));

				icon = icon.createPathWithRoundedCorners(5.0f);
				colour = 0x66ff2a00;
			}
			else
			{
				colour = Colour(0xff00b0b9).withAlpha(0.4f).getARGB();
				character = alert.getAlertType() == AlertWindow::InfoIcon ? 'i' : '?';

				icon.addEllipse(iconRect.toFloat());
			}

			GlyphArrangement ga;
			ga.addFittedText({ iconRect.getHeight() * 0.9f, Font::bold },
				String::charToString((juce_wchar)(uint8)character),
				static_cast<float> (iconRect.getX()), static_cast<float> (iconRect.getY()),
				static_cast<float> (iconRect.getWidth()), static_cast<float> (iconRect.getHeight()),
				Justification::centred, false);
			ga.createPath(icon);

			icon.setUsingNonZeroWinding(false);
			g.setColour(Colour(colour));
			g.fillPath(icon);

			iconSpaceUsed = iconWidth;
		}

		Rectangle<int> alertBounds(bounds.getX() + iconSpaceUsed, 30,
			bounds.getWidth(), bounds.getHeight() - getAlertWindowButtonHeight() - 20);

		textLayout.draw(g, alertBounds.toFloat());
	}

	int getAlertWindowButtonHeight() { return 21; }
	Font getAlertWindowTitleFont() { return { "Arial", "Black", 18.0f }; }
	Font getAlertWindowMessageFont() { return { "Arial", "Bold", 14.0f }; }
	Font getAlertWindowFont() { return { "Arial", "Bold", 14.0f }; }

	//==============================================================================
	void drawProgressBar(Graphics& g, ProgressBar& progressBar,
		int width, int height, double progress, const String& textToShow)
	{
			drawLinearProgressBar(g, progressBar, width, height, progress, textToShow);
	}

	void drawLinearProgressBar(Graphics& g, ProgressBar& progressBar,
		int width, int height,
		double progress, const String& textToShow)
	{
		auto background = progressBar.findColour(ProgressBar::backgroundColourId);
		auto foreground = progressBar.findColour(ProgressBar::foregroundColourId);

		auto barBounds = progressBar.getLocalBounds().toFloat();

		g.setColour(background);
		g.fillRoundedRectangle(barBounds, progressBar.getHeight() * 0.5f);

		if (progress >= 0.0f && progress <= 1.0f)
		{
			Path p;
			p.addRoundedRectangle(barBounds, progressBar.getHeight() * 0.5f);
			g.reduceClipRegion(p);

			barBounds.setWidth(barBounds.getWidth() * (float)progress);
			g.setColour(foreground);
			g.fillRoundedRectangle(barBounds, progressBar.getHeight() * 0.5f);
		}
		else
		{
			// spinning bar..
			g.setColour(background);

			auto stripeWidth = height * 2;
			auto position = static_cast<int> (Time::getMillisecondCounter() / 15) % stripeWidth;

			Path p;

			for (auto x = static_cast<float> (-position); x < width + stripeWidth; x += stripeWidth)
				p.addQuadrilateral(x, 0.0f,
					x + stripeWidth * 0.5f, 0.0f,
					x, static_cast<float> (height),
					x - stripeWidth * 0.5f, static_cast<float> (height));

			Image im(Image::ARGB, width, height, true);

			{
				Graphics g2(im);
				g2.setColour(foreground);
				g2.fillRoundedRectangle(barBounds, progressBar.getHeight() * 0.5f);
			}

			g.setTiledImageFill(im, 0, 0, 0.85f);
			g.fillPath(p);
		}

		if (textToShow.isNotEmpty())
		{
			g.setColour(Colour::contrasting(background, foreground));
			g.setFont(height * 0.6f);

			g.drawText(textToShow, 0, 0, width, height, Justification::centred, false);
		}
	}

private:

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MophoLookAndFeel)
};