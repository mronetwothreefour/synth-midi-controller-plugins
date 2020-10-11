#include "gui_LookAndFeel.h"

#include "gui_Colors.h"
#include "gui_Fonts.h"
#include "gui_Path_VerticalBarLED.h"
#include "../guiRenderers/guiRenderer_PopupMenuItem.h"
#include "../params/params_Identifiers.h"



Rectangle<int> GUILookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout tl(layoutTooltipText(tipText, Color::black));
	auto w = (int)(tl.getWidth() + 16.0f);
	auto h = (int)(tl.getHeight() + 14.0f);
	return Rectangle<int>(
		screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
		screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

void GUILookAndFeel::drawRotarySlider(Graphics& /*g*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float /*sliderPos*/, const float /*startAngle*/, const float /*endAngle*/, Slider& /*slider*/) {
}

void GUILookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(Color::device);
	g.fillRect(bounds.toFloat());
	g.setColour(Color::led_blue);
	g.drawRect(bounds.toFloat(), 1.0f);
	g.setColour(Color::offWhite);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId))
		.draw(g, { static_cast<float>(width), static_cast<float>(height) });
}

TextLayout GUILookAndFeel::layoutTooltipText(const String& text, Colour colour) noexcept {
	const int maxToolTipWidth = 400;

	AttributedString s;
	s.setJustification(Justification::centred);
	s.append(text, FontsMenu::fontFor_TooltipText, colour);

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
	g.setFont(height < 25 ? FontsMenu::fontFor_ButtonText_Small : FontsMenu::fontFor_ButtonText_Large);
	g.setColour(isDown ? Color::offWhite.darker(0.5f) : Color::offWhite);
	g.drawFittedText(button.getButtonText(), 0, 1, button.getWidth(), button.getHeight(), Justification::centred, 1);
}

void GUILookAndFeel::drawComboBox(Graphics& /*g*/, int /*width*/, int /*height*/, bool /*isDown*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/) {
}

PopupMenu::Options GUILookAndFeel::getOptionsForComboBoxPopupMenu(ComboBox& box, Label& /*label*/) {
	return PopupMenu::Options()
		.withTargetComponent(&box)
		.withItemThatMustBeVisible(box.getSelectedId())
		.withMinimumWidth(box.getWidth())
		.withMaximumNumColumns(1)
		.withStandardItemHeight(20);
}

void GUILookAndFeel::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(Color::black);
}

void GUILookAndFeel::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool /*isSeparator*/, const bool isActive, const bool isHighlighted, const bool isTicked, 
	const bool /*hasSubMenu*/, const String& text, const String& /*shortcutText*/, const Drawable* /*icon*/, const Colour* const /*textColor*/) {
	if (isHighlighted && isActive) {
		g.setColour(findColour(PopupMenu::highlightedBackgroundColourId));
		g.fillRect(area);
		g.setColour(findColour(PopupMenu::highlightedTextColourId));
	}
	g.setColour(Color::led_blue);
	if (isTicked) {
		auto tick{ VerticalBarLED::createPath() };
		g.fillPath(tick, AffineTransform::translation(1.0f, 0.0f));
	}
	PopupMenuItemRenderer::paintTextInArea(g, text, area);
}

void GUILookAndFeel::getIdealPopupMenuItemSize(const String& /*text*/, const bool isSeparator, int itemHeight, int& idealWidth, int& idealHeight) {
	if (isSeparator) {
		idealWidth = 50;
		idealHeight = itemHeight > 0 ? itemHeight / 10 : 10;
	}
	else {
		auto font = getPopupMenuFont();
		if (itemHeight > 0 && font.getHeight() > itemHeight / 1.3f)
			font.setHeight(itemHeight / 1.3f);
		idealHeight = itemHeight > 0 ? itemHeight : roundToInt(font.getHeight() * 1.3f);
	}
}

