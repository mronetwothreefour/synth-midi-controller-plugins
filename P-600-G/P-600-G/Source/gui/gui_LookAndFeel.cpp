#include "gui_LookAndFeel.h"

#include "gui_Colors.h"
#include "gui_Constants.h"
#include "gui_Fonts.h"
#include "../params/params_Identifiers.h"

using namespace constants;



void GUILookAndFeel::drawRotarySlider(Graphics& g, int /*x*/, int y, int w, int /*h*/, float sliderPos, const float startAngle, const float endAngle, Slider& slider) {
	if (slider.getComponentID() == ID::component_Knob.toString()) {
		Point<float> sliderCenter{ float(w) / 2.0f, float(w) / 2.0f };
		auto pointerAngle = startAngle + sliderPos * (endAngle - startAngle);
		Line<float> line;
		line.setStart(sliderCenter.x, float(y + 34));
		line.setEnd(sliderCenter.x, float(y + 30));
		Path pointerPath;
		pointerPath.addLineSegment(line, 1.5f);
		g.setColour(Color::offWhite);
		PathStrokeType stroke{ 1.5f, PathStrokeType::mitered };
		g.strokePath(pointerPath, stroke, AffineTransform::rotation(pointerAngle, sliderCenter.x, sliderCenter.y));
	}
}

void GUILookAndFeel::drawLinearSlider(Graphics& g, int x, int /*y*/, int /*w*/, int h, float /*sliderPos*/, float /*minSliderPos*/, float /*maxSliderPos*/, const Slider::SliderStyle /*sliderStyle*/, Slider& slider) {
	MemoryInputStream memInputStream{ BinaryData::Switch_png, BinaryData::Switch_pngSize, false };
	PNGImageFormat imageFormat;
	auto switchTab{ imageFormat.decodeImage(memInputStream) };
	auto currentValue{ (int)slider.getValue() };
	g.drawImageAt(switchTab, x, h - (currentValue * GUI::switchTabs_h) + GUI::theWeirdOffsetThatJucePutsOnLinearSliders);
}

void GUILookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(Color::knobGray);
	g.fillRect(bounds.toFloat());
	g.setColour(Color::offWhite);
	g.drawRect(bounds.toFloat(), 1.0f);
	g.setColour(Color::offWhite);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId)).draw(g, { static_cast<float>(width), static_cast<float>(height) });
}

Rectangle<int> GUILookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout tl(layoutTooltipText(tipText, Color::black));
	auto w = (int)(tl.getWidth() + 16.0f);
	auto h = (int)(tl.getHeight() + 14.0f);
	return Rectangle<int>(
		screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
		screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

TextLayout GUILookAndFeel::layoutTooltipText(const String& text, Colour colour) noexcept {
	AttributedString s;
	s.setJustification(Justification::centred);
	s.append(text, FontsMenu::fontFor_TooltipText, colour);

	TextLayout tl;
	tl.createLayout(s, GUI::tooltipMaxWidth);
	return tl;
}

void GUILookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& /*background*/, bool /*isHighlighted*/, bool isDown) {
	PNGImageFormat imageFormat;
	auto buttonImageData{ getButtonImageData(button, isDown) };
	auto buttonImageDataSize{ getButtonImageDataSize(button, isDown) };
	if (buttonImageData != nullptr) {
		MemoryInputStream memInputStream{ buttonImageData, buttonImageDataSize, false };
		auto buttonImage{ imageFormat.decodeImage(memInputStream) };
		g.drawImageAt(buttonImage, 0, 0);
	}
}

const char* GUILookAndFeel::getButtonImageData(Button& button, bool isDown) {
	if (button.getComponentID() == ID::button_PgmBank.toString())
		return isDown ? BinaryData::ButtonPgmBankDown_png : BinaryData::ButtonPgmBankUp_png;
	if (button.getComponentID().startsWith("button_Pull"))
		return isDown ? BinaryData::ButtonPullDown_png : BinaryData::ButtonPullUp_png;
	if (button.getComponentID().startsWith("button_Push"))
		return isDown ? BinaryData::ButtonPushDown_png : BinaryData::ButtonPushUp_png;
	if (button.getComponentID() == ID::button_Rand.toString())
		return isDown ? BinaryData::ButtonRandDown_png : BinaryData::ButtonRandUp_png;
	if (button.getComponentID() == ID::button_Redo.toString())
		return isDown ? BinaryData::ButtonRedoDown_png : BinaryData::ButtonRedoUp_png;
	if (button.getComponentID() == ID::button_Tips.toString())
		return isDown ? BinaryData::ButtonTipsDown_png : BinaryData::ButtonTipsUp_png;
	if (button.getComponentID() == ID::button_Undo.toString())
		return isDown ? BinaryData::ButtonUndoDown_png : BinaryData::ButtonUndoUp_png;
	return nullptr;
}

size_t GUILookAndFeel::getButtonImageDataSize(Button& button, bool isDown) {
	if (button.getComponentID() == ID::button_PgmBank.toString())
		return isDown ? BinaryData::ButtonPgmBankDown_pngSize : BinaryData::ButtonPgmBankUp_pngSize;
	if (button.getComponentID().startsWith("button_Pull"))
		return isDown ? BinaryData::ButtonPullDown_pngSize : BinaryData::ButtonPullUp_pngSize;
	if (button.getComponentID().startsWith("button_Push"))
		return isDown ? BinaryData::ButtonPushDown_pngSize : BinaryData::ButtonPushUp_pngSize;
	if (button.getComponentID() == ID::button_Rand.toString())
		return isDown ? BinaryData::ButtonRandDown_pngSize : BinaryData::ButtonRandUp_pngSize;
	if (button.getComponentID() == ID::button_Redo.toString())
		return isDown ? BinaryData::ButtonRedoDown_pngSize : BinaryData::ButtonRedoUp_pngSize;
	if (button.getComponentID() == ID::button_Tips.toString())
		return isDown ? BinaryData::ButtonTipsDown_pngSize : BinaryData::ButtonTipsUp_pngSize;
	if (button.getComponentID() == ID::button_Undo.toString())
		return isDown ? BinaryData::ButtonUndoDown_pngSize : BinaryData::ButtonUndoUp_pngSize;
	return size_t();
}

void GUILookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
}

