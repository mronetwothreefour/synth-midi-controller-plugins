#include "gui_LookAndFeel.h"

#include "gui_Colors.h"
#include "gui_Fonts.h"
#include "../params/params_Identifiers.h"



Rectangle<int> GUILookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout tl(layoutTooltipText(tipText, Color::black));
	auto w = (int)(tl.getWidth() + 16.0f);
	auto h = (int)(tl.getHeight() + 14.0f);
	return Rectangle<int>(
		screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
		screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

void GUILookAndFeel::drawRotarySlider(Graphics& g, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float /*sliderPos*/, const float /*startAngle*/, const float /*endAngle*/, Slider& /*slider*/) {
}

void GUILookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(Color::black.brighter(0.2f));
	g.fillRect(bounds.toFloat());
	g.setColour(Color::offWhite);
	g.drawRect(bounds.toFloat(), 2.0f);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId))
		.draw(g, { static_cast<float>(width), static_cast<float>(height) });
}

TextLayout GUILookAndFeel::layoutTooltipText(const String& text, Colour colour) noexcept {
	Font tooltipFont(FontsDB::family_TooltipText, FontsDB::style_ForTooltipText, FontsDB::size_ForTooltipText);
	const int maxToolTipWidth = 400;

	AttributedString s;
	s.setJustification(Justification::centred);
	s.append(text, tooltipFont, colour);

	TextLayout tl;
	tl.createLayout(s, (float)maxToolTipWidth);
	return tl;
}

void GUILookAndFeel::drawButtonBackground(Graphics& g, Button& /*button*/, const Colour& background, bool /*isHighlighted*/, bool isDown) {
	auto baseColor{ background };
	if (isDown)
		baseColor = baseColor.darker(0.5f);
	g.setColour(baseColor);
	g.fillAll(baseColor);
}

void GUILookAndFeel::drawButtonText(Graphics& g, TextButton& button, bool /*isHighlighted*/, bool isDown) {
	auto height{ button.getHeight() };
	Font font{ FontsDB::family_HeavyText, FontsDB::style_ForHeavyText, height < 25 ? FontsDB::size_ForButtonText_Small : FontsDB::size_ForButtonText_Large };
	g.setFont(font);
	g.setColour(isDown ? Color::offWhite.darker(0.5f) : Color::offWhite);
	g.drawFittedText(button.getButtonText(), 0, 1, button.getWidth(), button.getHeight(), Justification::centred, 1);
}

