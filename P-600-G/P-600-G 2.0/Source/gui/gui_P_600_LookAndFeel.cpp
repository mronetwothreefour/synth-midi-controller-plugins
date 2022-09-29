#include "gui_P_600_LookAndFeel.h"

#include "gui_build_LED_NumeralPath.h"
#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_GUI_PathData.h"

using namespace P_600_G_Constants;
using namespace BinaryData;
using MemBlock = MemoryBlock;
using s_t = size_t;

void P_600_LookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& /*background*/, bool /*isHighlighted*/, bool isDown) {
	auto buttonID{ button.getComponentID() };
	MemBlock mBlock{};

	if (buttonID.startsWith("btn_Esc"))
		mBlock = MemBlock{ isDown ? btn_Esc_Dn_png : btn_Esc_Up_png, isDown ? (s_t)btn_Esc_Dn_pngSize : (s_t)btn_Esc_Up_pngSize };

	if (buttonID == ID::btn_Exit.toString())
		mBlock = MemBlock{ isDown ? btn_Exit_Dn_png : btn_Exit_Up_png, isDown ? (s_t)btn_Exit_Dn_pngSize : (s_t)btn_Exit_Up_pngSize };

	if (buttonID.startsWith("btn_Expt"))
		mBlock = MemBlock{ isDown ? btn_Expt_Dn_png : btn_Expt_Up_png, isDown ? (s_t)btn_Expt_Dn_pngSize : (s_t)btn_Expt_Up_pngSize };

	if (buttonID.startsWith("btn_Impt"))
		mBlock = MemBlock{ isDown ? btn_Impt_Dn_png : btn_Impt_Up_png, isDown ? (s_t)btn_Impt_Dn_pngSize : (s_t)btn_Impt_Up_pngSize };

	if (buttonID == ID::btn_Load.toString())
		mBlock = MemBlock{ isDown ? btn_Load_Dn_png : btn_Load_Up_png, isDown ? (s_t)btn_Load_Dn_pngSize : (s_t)btn_Load_Up_pngSize };

	if (buttonID == ID::btn_Name.toString())
		mBlock = MemBlock{ isDown ? btn_Name_Dn_png : btn_Name_Up_png, isDown ? (s_t)btn_Name_Dn_pngSize : (s_t)btn_Name_Up_pngSize };

	if (buttonID == ID::btn_NewFolder.toString())
		mBlock = MemBlock{ isDown ? btn_NewFldr_Dn_png : btn_NewFldr_Up_png, isDown ? (s_t)btn_NewFldr_Dn_pngSize : (s_t)btn_NewFldr_Up_pngSize };

	if (buttonID.startsWith("btn_OK"))
		mBlock = MemBlock{ isDown ? btn_OK_Dn_png : btn_OK_Up_png, isDown ? (s_t)btn_OK_Dn_pngSize : (s_t)btn_OK_Up_pngSize };

	if (buttonID == ID::btn_PgmBank.toString())
		mBlock = MemBlock{ isDown ? btn_PgmBank_Dn_png : btn_PgmBank_Up_png, isDown ? (s_t)btn_PgmBank_Dn_pngSize : (s_t)btn_PgmBank_Up_pngSize };

	if (buttonID.startsWith("btn_Pull"))
		mBlock = MemBlock{ isDown ? btn_Pull_Dn_png : btn_Pull_Up_png, isDown ? (s_t)btn_Pull_Dn_pngSize : (s_t)btn_Pull_Up_pngSize };

	if (buttonID.startsWith("btn_Push"))
		mBlock = MemBlock{ isDown ? btn_Push_Dn_png : btn_Push_Up_png, isDown ? (s_t)btn_Push_Dn_pngSize : (s_t)btn_Push_Up_pngSize };

	if (buttonID == ID::btn_RestoreFactoryVoices.toString())
		mBlock = MemBlock{ isDown ? btn_Fact_Dn_png : btn_Fact_Up_png, isDown ? (s_t)btn_Fact_Dn_pngSize : (s_t)btn_Fact_Up_pngSize };

	if (buttonID == ID::btn_Save.toString())
		mBlock = MemBlock{ isDown ? btn_Save_Dn_png : btn_Save_Up_png, isDown ? (s_t)btn_Save_Dn_pngSize : (s_t)btn_Save_Up_pngSize };

	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto buttonImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(buttonImage, 0, 0);
}

void P_600_LookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
}




void P_600_LookAndFeel::drawComboBox(Graphics& g, int width, int height, bool /*isDown*/, 
	int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/)
{
	Rectangle<int> arrowZone(width - 30, 0, 20, height);
	Path path;
	path.startNewSubPath((float)arrowZone.getX() + 3.0f, (float)arrowZone.getCentreY() - 2.0f);
	path.lineTo((float)arrowZone.getCentreX(), (float)arrowZone.getCentreY() + 3.0f);
	path.lineTo((float)arrowZone.getRight() - 3.0f, (float)arrowZone.getCentreY() - 2.0f);
	g.setColour(GUI::color_OffWhite);
	g.strokePath(path, PathStrokeType(2.0f));
}

void P_600_LookAndFeel::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(GUI::color_KnobGray);
}

void P_600_LookAndFeel::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool /*isActive*/, 
	const bool isHighlighted, const bool /*isTicked*/, const bool /*hasSubMenu*/, const String& text, const String& /*shortcutText*/, 
	const Drawable* /*icon*/, const Colour* const /*textColor*/)
{
	if (isSeparator) {
		auto separatorArea = area.reduced(5, 0);
		separatorArea.removeFromTop(roundToInt(((float)separatorArea.getHeight() * 0.5f) - 0.5f));
		g.setColour(GUI::color_OffWhite);
		g.fillRect(separatorArea.removeFromTop(1));
	}
	else {
		auto highlightedArea = area.reduced(1);
		if (isHighlighted) {
			g.setColour(GUI::color_KnobGray.brighter(0.2f));
			g.fillRect(highlightedArea);
		}
		g.setColour(GUI::color_OffWhite);
		auto textArea{ highlightedArea.reduced(4, 0) };
		g.setFont(GUI::font_BrowserText);
		g.drawFittedText(text, textArea, Justification::centredLeft, 1);
	}
}




void P_600_LookAndFeel::layoutFileBrowserComponent(
	Browser& /*browser*/, DirContents* dirContents, Preview* /*preview*/, ComboBox* currentPath, TextEditor* fileName, Button* goUpButton)
{
	currentPath->setBounds(0, 0, 445, 26);
	currentPath->setJustificationType(Justification::centredLeft);
	goUpButton->setBounds(450, 0, 20, currentPath->getHeight());
	setColour(ListBox::backgroundColourId, GUI::color_Black.withAlpha(0.0f));
	setColour(ListBox::outlineColourId, GUI::color_Black.withAlpha(0.0f));
	if (auto* listAsComp = dynamic_cast<Component*> (dirContents))
		listAsComp->setBounds(0, 36, 470, 173);
	fileName->setBounds(86, 219, 384, currentPath->getHeight());
	fileName->applyFontToAllText(GUI::font_BrowserText, true);
}

void P_600_LookAndFeel::drawFileBrowserRow(Graphics& g, int w, int h, const File& /*file*/, const String& fileName, Image* /*icon*/,
	const String& fileSizeString, const String& fileTimeString, bool isDirectory, bool isSelected, int /*itemIndex*/, DirContents& /*dirContents*/)
{
	if (isSelected)
		g.fillAll(GUI::color_Black.brighter(0.3f));
	Path iconPath;
	if (isDirectory)
		iconPath.loadPathFromData(GUI::pathDataForFolderIcon.data(), GUI::pathDataForFolderIcon.size());
	else
		iconPath.loadPathFromData(GUI::pathDataForFileIcon.data(), GUI::pathDataForFileIcon.size());
	g.setColour(GUI::color_OffWhite);
	g.fillPath(iconPath);
	g.setFont(GUI::font_BrowserText);
	const int browserIcon_w{ 32 };
	if (w > 450 && !isDirectory) {
		auto sizeX = roundToInt((float)w * 0.7f);
		auto dateX = roundToInt((float)w * 0.8f);
		g.drawFittedText(fileName, browserIcon_w, 0, sizeX - browserIcon_w, h, Justification::centredLeft, 1);
		g.drawFittedText(fileSizeString, sizeX, 0, dateX - sizeX - 8, h, Justification::centredRight, 1);
		g.drawFittedText(fileTimeString, dateX, 0, w - 8 - dateX, h, Justification::centredRight, 1);
	}
	else {
		g.drawFittedText(fileName, browserIcon_w, 0, w - browserIcon_w, h, Justification::centredLeft, 1);
	}
}

Button* P_600_LookAndFeel::createFileBrowserGoUpButton() {
	auto* goUpButton = new DrawableButton("up", DrawableButton::ImageOnButtonBackgroundOriginalSize);
	Path arrowPath;
	arrowPath.addArrow({ 10, 22, 10, 4 }, 7, 15, 10);
	DrawablePath arrowImage;
	arrowImage.setFill(GUI::color_OffWhite);
	arrowImage.setPath(arrowPath);
	goUpButton->setImages(&arrowImage);
	return goUpButton;
}




void P_600_LookAndFeel::drawLabel(Graphics& g, Label& label) {
	auto isInImptExptBrowser{ label.getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString() ||
		label.getParentComponent()->getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString()
	};
	if (isInImptExptBrowser) {
		auto textArea{ label.getLocalBounds() };
		textArea.removeFromLeft(5);
		g.setColour(GUI::color_OffWhite);
		g.setFont(GUI::font_BrowserText);
		g.drawFittedText(label.getText(), textArea, Justification::centredLeft, 1, 1.0f);
	}
	if (label.getComponentID() == ID::comp_TextEditorForVoiceNumberSlider.toString() ||
		label.getComponentID() == ID::comp_TextEditorForTransmitTime.toString())
	{
		auto isTransmitTimeEditor{ label.getComponentID() == ID::comp_TextEditorForTransmitTime.toString() };
		Path unlitSegmentsPath;
		auto digits_x_spacing{ 26.0f };
		auto firstDigit_x{ 4.0f };
		auto secondDigit_x{ firstDigit_x + digits_x_spacing };
		auto thirdDigit_x{ firstDigit_x + (2 * digits_x_spacing) };
		auto fourthDigit_x{ firstDigit_x + (3 * digits_x_spacing) };
		auto digits_y{ 8.0f };
		unlitSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)8), AffineTransform::translation(firstDigit_x, digits_y));
		unlitSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)8), AffineTransform::translation(secondDigit_x, digits_y));
		if (isTransmitTimeEditor) {
			unlitSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)8), AffineTransform::translation(thirdDigit_x, digits_y));
			unlitSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)8), AffineTransform::translation(fourthDigit_x, digits_y));
		}
		g.setColour(GUI::color_LED_RedUnlit);
		g.fillPath(unlitSegmentsPath);
		auto numberString{ label.getText() };
		auto firstDigit{ String().charToString(numberString[0]).getIntValue() };
		auto secondDigit{ String().charToString(numberString[1]).getIntValue() };
		Path litSegmentsPath;
		litSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)firstDigit), AffineTransform::translation(firstDigit_x, digits_y));
		litSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)secondDigit), AffineTransform::translation(secondDigit_x, digits_y));
		if (isTransmitTimeEditor) {
			auto thirdDigit{ String().charToString(numberString[2]).getIntValue() };
			auto fourthDigit{ String().charToString(numberString[3]).getIntValue() };
			litSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)thirdDigit), AffineTransform::translation(thirdDigit_x, digits_y));
			litSegmentsPath.addPath(LED_NumeralPath::buildForNumeral((uint8)fourthDigit), AffineTransform::translation(fourthDigit_x, digits_y));
		}
		g.setColour(GUI::color_LED_Red);
		g.fillPath(litSegmentsPath);
	}
}

void P_600_LookAndFeel::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/, TextEditor& textEditor) {
	auto editorIsInImportExportBrowser{ textEditor.getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString() ||
		textEditor.getParentComponent()->getParentComponent()->getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString()
	};
	if (editorIsInImportExportBrowser)
		textEditor.applyFontToAllText(GUI::font_BrowserText);
	auto parentID{ textEditor.getParentComponent()->getComponentID() };
	if (parentID == ID::comp_TextEditorForKnob.toString()) {
		g.setColour(GUI::color_KnobGray);
		g.fillEllipse(4.0f, 4.0f, 26.0f, 26.0f);
	}
	else {
		if (parentID == ID::comp_TextEditorForTransmitTime.toString() || parentID == ID::comp_TextEditorForVoiceNumberSlider.toString())
			g.fillAll(GUI::color_LED_RedUnlit);
		else
			g.fillAll(GUI::color_Black);
	}
}

void P_600_LookAndFeel::drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
}




int P_600_LookAndFeel::getDefaultScrollbarWidth() {
	return 15;
}

void P_600_LookAndFeel::drawScrollbar(Graphics& g, ScrollBar& /*scrollbar*/, int x, int y, int w, int h,
	bool isVertical, int thumbStartPosition, int thumbSize, bool /*mouseIsOver*/, bool /*mouseIsDown*/)
{
	Rectangle<int> thumbBounds;
	if (isVertical)
		thumbBounds = { x, thumbStartPosition, w, thumbSize };
	else
		thumbBounds = { thumbStartPosition, y, thumbSize, h };
	thumbBounds.reduce(2, 2);
	g.setColour(GUI::color_KnobGray.brighter(0.3f));
	g.fillRoundedRectangle(thumbBounds.toFloat(), 4.0f);
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




void P_600_LookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(),
		button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void P_600_LookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, 
	const bool isTicked, const bool /*isEnabled*/, const bool isHighlighted, const bool /*isDown*/)
{
	auto componentID{ component.getComponentID() };
	if (componentID == ID::btn_VoiceSlotRadioButton.toString()) {
		auto buttonColor{ GUI::color_OffWhite.withAlpha(0.0f) };
		if (isHighlighted)
			buttonColor = buttonColor.withAlpha(0.1f);
		if (isTicked)
			buttonColor = buttonColor.withAlpha(0.25f);
		g.setColour(buttonColor);
		g.fillRect(x, y, w, h);
		g.setColour(GUI::color_OffWhite);
		g.setFont(GUI::font_VoiceSlotRadioButtons);
		Rectangle<float> textArea{ x + 2, y, w, h };
		g.drawText(component.getName(), textArea, Justification::centredLeft);
	}
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
