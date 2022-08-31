#include "gui_MatrixLookAndFeel.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../gui/gui_build_LED_Path.h"

using namespace Matrix_6G_Constants;
using namespace BinaryData;
using MemBlock = MemoryBlock;
using s_t = size_t;

void MatrixLookAndFeel::drawLabel(Graphics& g, Label& label) {
	if (label.getComponentID() != ID::comp_TextEditorForSlider.toString()) {
		auto isRightJustified{ label.getComponentID() == ID::comp_VoiceNameEditor.toString() ? false : true};
		g.setColour(GUI::color_LED_Blue);
		auto text{ label.getText() };
		auto textPath{ LED_Path::buildLabelText(text, label.getWidth(), isRightJustified) };
		g.fillPath(textPath);
	}
}

void MatrixLookAndFeel::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
	g.fillAll(GUI::color_Black);
}

void MatrixLookAndFeel::drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
}

void MatrixLookAndFeel::drawRotarySlider(
    Graphics& /*g*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float /*sliderPos*/, 
    const float /*startAngle*/, const float /*endAngle*/, Slider& /*slider*/) 
{
}

void MatrixLookAndFeel::drawLinearSlider(
    Graphics& g, int /*x*/, int /*y*/, int /*width*/, int /*height*/, float sliderPos, float /*minSliderPos*/, 
	float /*maxSliderPos*/, const Slider::SliderStyle /*style*/, Slider& /*slider*/) 
{
	auto sliderTab{ LED_Path::buildForSliderTab() };
	g.setColour(GUI::color_LED_Blue);
	g.fillPath(sliderTab, AffineTransform::translation(sliderPos - 8.0f, 0.0f));
}

void MatrixLookAndFeel::drawComboBox(
	Graphics& /*g*/, int /*width*/, int /*height*/, bool /*isDown*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/) 
{
}

void MatrixLookAndFeel::positionComboBoxText(ComboBox& comboBox, Label& label) {
	label.setBounds(0, 0, comboBox.getWidth(), comboBox.getHeight());
}

PopupMenu::Options MatrixLookAndFeel::getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) {
	return PopupMenu::Options()
		.withTargetComponent(&box)
		.withItemThatMustBeVisible(box.getSelectedId())
		.withMinimumWidth(box.getWidth())
		.withMaximumNumColumns(1)
		.withStandardItemHeight(label.getHeight() + 2);
}

void MatrixLookAndFeel::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(GUI::color_Black.brighter(0.06f));
}

void MatrixLookAndFeel::drawPopupMenuItem(
	Graphics& g, const Rectangle<int>& area, const bool /*isSeparator*/, const bool isActive, const bool isHighlighted, const bool isTicked,
	const bool /*hasSubMenu*/, const String& text, const String& /*shortcutText*/, const Drawable* /*icon*/, const Colour* const /*textColor*/) 
{
	if (isHighlighted && isActive) {
		g.setColour(findColour(PopupMenu::highlightedBackgroundColourId));
		g.fillRect(area);
		g.setColour(findColour(PopupMenu::highlightedTextColourId));
	}
	g.setColour(GUI::color_LED_Blue);
	if (isTicked) {
		auto vertBarTick{ LED_Path::buildForVertBar() };
		g.fillPath(vertBarTick, AffineTransform::translation(1.0f, 0.0f));
	}
	auto textPath{ LED_Path::buildLabelText(text, area.getWidth()) };
	g.fillPath(textPath);
}

void MatrixLookAndFeel::getIdealPopupMenuItemSize(
	const String& /*text*/, const bool /*isSeparator*/, int itemHeight, int& /*idealWidth*/, int& idealHeight) 
{
	auto font = getPopupMenuFont();
	if (itemHeight > 0 && font.getHeight() > itemHeight / 1.3f)
		font.setHeight(itemHeight / 1.3f);
	idealHeight = itemHeight > 0 ? itemHeight : roundToInt(font.getHeight() * 1.3f);
}

void MatrixLookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(GUI::color_Device);
	g.fillRect(bounds.toFloat());
	g.setColour(GUI::color_LED_Blue);
	g.drawRect(bounds.toFloat(), 1.0f);
	g.setColour(GUI::color_OffWhite);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId)).draw(g, { static_cast<float>(width), static_cast<float>(height) });
}

Rectangle<int> MatrixLookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout textLayout(layoutTooltipText(tipText, GUI::color_Black));
	auto w = (int)(textLayout.getWidth() + 16.0f);
	auto h = (int)(textLayout.getHeight() + 14.0f);
	return Rectangle<int>(
		screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
		screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

TextLayout MatrixLookAndFeel::layoutTooltipText(const String& text, Colour colour) noexcept {
	AttributedString attribString;
	attribString.setJustification(Justification::centred);
	attribString.append(text, GUI::font_Tooltips, colour);
	TextLayout textLayout;
	const float tooltipMaxWidth{ 400.0f };
	textLayout.createLayout(attribString, tooltipMaxWidth);
	return textLayout;
}
