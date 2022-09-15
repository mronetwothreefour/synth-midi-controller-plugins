#include "gui_P_600_LookAndFeel.h"

#include "gui_build_LED_NumeralPath.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"

using namespace P_600_G_Constants;
using namespace BinaryData;
using MemBlock = MemoryBlock;
using s_t = size_t;

void P_600_LookAndFeel::drawRotarySlider(
	Graphics& g, int /*x*/, int y, int w, int /*h*/, float sliderPos, const float startAngle, const float endAngle, Slider& slider) 
{
	if (slider.getComponentID() != ID::comp_VoiceNumberSlider.toString()) {
		Point<float> sliderCenter{ float(w) / 2.0f, float(w) / 2.0f };
		auto pointerAngle = startAngle + sliderPos * (endAngle - startAngle);
		Line<float> line;
		line.setStart(sliderCenter.x, float(y + 34));
		line.setEnd(sliderCenter.x, float(y + 30));
		Path pointerPath;
		pointerPath.addLineSegment(line, 1.5f);
		g.setColour(GUI::color_OffWhite);
		PathStrokeType stroke{ 1.5f, PathStrokeType::mitered };
		g.strokePath(pointerPath, stroke, AffineTransform::rotation(pointerAngle, sliderCenter.x, sliderCenter.y));
	}
}

void P_600_LookAndFeel::drawLinearSlider(
	Graphics& g, int x, int /*y*/, int /*w*/, int h, float /*sliderPos*/, float /*minSliderPos*/, 
	float /*maxSliderPos*/, const Slider::SliderStyle /*sliderStyle*/, Slider& slider) 
{
	MemoryInputStream memInputStream{ BinaryData::btn_SwitchTab_png, BinaryData::btn_SwitchTab_pngSize, false };
	PNGImageFormat imageFormat;
	auto switchTab{ imageFormat.decodeImage(memInputStream) };
	auto currentValue{ (int)slider.getValue() };
	auto switchTab_h{ 16 };
	auto offsetForLinearSliderTab{ 4 };
	g.drawImageAt(switchTab, x, h - (currentValue * switchTab_h) + offsetForLinearSliderTab);
}

void P_600_LookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& /*background*/, bool /*isHighlighted*/, bool isDown) {
	auto buttonID{ button.getComponentID() };
	MemBlock mBlock{};

	if (buttonID.startsWith("btn_Esc"))
		mBlock = MemBlock{ isDown ? btn_Esc_Dn_png : btn_Esc_Up_png, isDown ? (s_t)btn_Esc_Dn_pngSize : (s_t)btn_Esc_Up_pngSize };

	if (buttonID.startsWith("btn_OK"))
		mBlock = MemBlock{ isDown ? btn_OK_Dn_png : btn_OK_Up_png, isDown ? (s_t)btn_OK_Dn_pngSize : (s_t)btn_OK_Up_pngSize };

	if (buttonID == ID::btn_Pull.toString())
		mBlock = MemBlock{ isDown ? btn_Pull_Dn_png : btn_Pull_Up_png, isDown ? (s_t)btn_Pull_Dn_pngSize : (s_t)btn_Pull_Up_pngSize };

	if (buttonID == ID::btn_Push.toString())
		mBlock = MemBlock{ isDown ? btn_Push_Dn_png : btn_Push_Up_png, isDown ? (s_t)btn_Push_Dn_pngSize : (s_t)btn_Push_Up_pngSize };

	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto buttonImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(buttonImage, 0, 0);
}

void P_600_LookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
}

void P_600_LookAndFeel::drawLabel(Graphics& g, Label& label) {
	if (label.getComponentID() == ID::comp_TextEditorForVoiceNumberSlider.toString()) {
		g.setColour(GUI::color_LED_RedUnlit);
		Path unlitSegmentsPath;
		auto firstDigit_x{ 4.0f };
		auto secondDigit_x{ 30.0f };
		auto digits_y{ 8.0f };
		unlitSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)8), AffineTransform::translation(firstDigit_x, digits_y));
		unlitSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)8), AffineTransform::translation(secondDigit_x, digits_y));
		g.fillPath(unlitSegmentsPath);
		g.setColour(GUI::color_LED_Red);
		auto numberString{ label.getText() };
		auto firstDigit{ String().charToString(numberString[0]).getIntValue() };
		auto secondDigit{ String().charToString(numberString[1]).getIntValue() };
		Path litSegmentsPath;
		litSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)firstDigit), AffineTransform::translation(firstDigit_x, digits_y));
		litSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)secondDigit), AffineTransform::translation(secondDigit_x, digits_y));
		g.fillPath(litSegmentsPath);
	}
}

void P_600_LookAndFeel::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/, TextEditor& textEditor) {
	if (textEditor.getParentComponent()->getComponentID() == ID::comp_TextEditorForKnob.toString()) {
		g.setColour(GUI::color_KnobGray);
		g.fillEllipse(4.0f, 4.0f, 26.0f, 26.0f);
	}
	else
		g.fillAll(GUI::color_LED_RedUnlit);
}

void P_600_LookAndFeel::drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
}

void P_600_LookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(GUI::color_KnobGray);
	g.fillRect(bounds.toFloat());
	g.setColour(GUI::color_OffWhite);
	g.drawRect(bounds.toFloat(), 1.0f);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId)).draw(g, { static_cast<float>(width), static_cast<float>(height) });
}

Rectangle<int> P_600_LookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout textLayout(layoutTooltipText(tipText, GUI::color_Black));
	auto w = (int)(textLayout.getWidth() + 16.0f);
	auto h = (int)(textLayout.getHeight() + 14.0f);
	return Rectangle<int>(
		screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
		screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

TextLayout P_600_LookAndFeel::layoutTooltipText(const String& text, Colour colour) noexcept {
	AttributedString attribString;
	attribString.setJustification(Justification::centred);
	attribString.append(text, GUI::font_Tooltips, colour);
	TextLayout textLayout;
	const float tooltipMaxWidth{ 400.0f };
	textLayout.createLayout(attribString, tooltipMaxWidth);
	return textLayout;
}
