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

void GUILookAndFeel::drawLabel(Graphics& g, Label& label) {
	auto isInImptExptBrowser{ label.getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() ||
		label.getParentComponent()->getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString()
	};
	if (isInImptExptBrowser) {
		auto textArea{ label.getLocalBounds() };
		textArea.removeFromLeft(5);
		g.setColour(Color::offWhite);
		g.setFont(FontsMenu::fontFor_BrowserText);
		g.drawFittedText(label.getText(), textArea, Justification::centredLeft, 1, 1.0f);
	}
}

int GUILookAndFeel::getDefaultScrollbarWidth(){
	return 15;
}

void GUILookAndFeel::drawScrollbar(Graphics& g, ScrollBar& /*scrollbar*/, int x, int y, int w, int h, bool isVertical, int thumbStartPosition, int thumbSize, bool /*mouseIsOver*/, bool /*mouseIsDown*/) {
	Rectangle<int> thumbBounds;
	if (isVertical)
		thumbBounds = { x, thumbStartPosition, w, thumbSize };
	else
		thumbBounds = { thumbStartPosition, y, thumbSize, h };
	thumbBounds.reduce(2, 2);
	g.setColour(Color::knobGray.brighter(0.3f));
	g.fillRoundedRectangle(thumbBounds.toFloat(), 4.0f);
}

void GUILookAndFeel::fillTextEditorBackground(Graphics& g, int /*width*/, int /*height*/, TextEditor& textEditor) {
	textEditor.applyColourToAllText(Color::offWhite);
	textEditor.setColour(TextEditor::highlightedTextColourId, Color::offWhite);
	auto editorIsInImptExptComponent{ textEditor.getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() };
	if (editorIsInImptExptComponent) {
		textEditor.applyFontToAllText(FontsMenu::fontFor_BrowserText);
		textEditor.applyColourToAllText(Color::offWhite);
	}
	auto editorIsInPathComboBoxInImptExptComponent{ textEditor.getParentComponent()->getParentComponent()->getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() };
	if (editorIsInPathComboBoxInImptExptComponent) {
		auto fillArea{ textEditor.getLocalBounds() };
		fillArea.removeFromLeft(5);
		fillArea.reduced(0, 8);
		g.setColour(Color::black);
		textEditor.applyFontToAllText(FontsMenu::fontFor_BrowserText);
	}
	if (textEditor.getParentComponent()->getComponentID() == ID::label_VoiceNameEditor.toString() || 
		textEditor.getParentComponent()->getComponentID() == ID::label_LCDdisplayEditor.toString())
		g.fillAll(Color::black);
}

void GUILookAndFeel::drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
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
	if (button.getComponentID().startsWith("button_Esc"))
		return isDown ? BinaryData::ButtonEscDown_png : BinaryData::ButtonEscUp_png;
	if (button.getComponentID() == ID::button_Exit.toString())
		return isDown ? BinaryData::ButtonExitDown_png : BinaryData::ButtonExitUp_png;
	if (button.getComponentID().startsWith("button_Expt"))
		return isDown ? BinaryData::ButtonExptDown_png : BinaryData::ButtonExptUp_png;
	if (button.getComponentID() == ID::button_Fact.toString())
		return isDown ? BinaryData::ButtonFactDown_png : BinaryData::ButtonFactUp_png;
	if (button.getComponentID().startsWith("button_Impt"))
		return isDown ? BinaryData::ButtonImptDown_png : BinaryData::ButtonImptUp_png;
	if (button.getComponentID() == ID::button_Load.toString())
		return isDown ? BinaryData::ButtonLoadDown_png : BinaryData::ButtonLoadUp_png;
	if (button.getComponentID() == ID::button_LockAll.toString())
		return isDown ? BinaryData::ButtonLockAllDown_png : BinaryData::ButtonLockAllUp_png;
	if (button.getComponentID() == ID::button_LockNone.toString())
		return isDown ? BinaryData::ButtonLockNoneDown_png : BinaryData::ButtonLockNoneUp_png;
	if (button.getComponentID() == ID::button_Name.toString())
		return isDown ? BinaryData::ButtonNameDown_png : BinaryData::ButtonNameUp_png;
	if (button.getComponentID() == ID::button_NewFldr.toString())
		return isDown ? BinaryData::ButtonNewFldrDown_png : BinaryData::ButtonNewFldrUp_png;
	if (button.getComponentID().startsWith("button_OK"))
		return isDown ? BinaryData::ButtonOKDown_png : BinaryData::ButtonOKUp_png;
	if (button.getComponentID() == ID::button_VoicesBank.toString())
		return isDown ? BinaryData::ButtonPgmBankDown_png : BinaryData::ButtonPgmBankUp_png;
	if (button.getComponentID().startsWith("button_Pull"))
		return isDown ? BinaryData::ButtonPullDown_png : BinaryData::ButtonPullUp_png;
	if (button.getComponentID().startsWith("button_Push"))
		return isDown ? BinaryData::ButtonPushDown_png : BinaryData::ButtonPushUp_png;
	if (button.getComponentID() == ID::button_Rand.toString())
		return isDown ? BinaryData::ButtonRandDown_png : BinaryData::ButtonRandUp_png;
	if (button.getComponentID() == ID::button_Redo.toString())
		return isDown ? BinaryData::ButtonRedoDown_png : BinaryData::ButtonRedoUp_png;
	if (button.getComponentID() == ID::button_Save.toString())
		return isDown ? BinaryData::ButtonSaveDown_png : BinaryData::ButtonSaveUp_png;
	if (button.getComponentID() == ID::button_Tips.toString())
		return isDown ? BinaryData::ButtonTipsDown_png : BinaryData::ButtonTipsUp_png;
	if (button.getComponentID() == ID::button_Undo.toString())
		return isDown ? BinaryData::ButtonUndoDown_png : BinaryData::ButtonUndoUp_png;
	return nullptr;
}

size_t GUILookAndFeel::getButtonImageDataSize(Button& button, bool isDown) {
	if (button.getComponentID().startsWith("button_Esc"))
		return isDown ? BinaryData::ButtonEscDown_pngSize : BinaryData::ButtonEscUp_pngSize;
	if (button.getComponentID() == ID::button_Exit.toString())
		return isDown ? BinaryData::ButtonExitDown_pngSize : BinaryData::ButtonExitUp_pngSize;
	if (button.getComponentID().startsWith("button_Expt"))
		return isDown ? BinaryData::ButtonExptDown_pngSize : BinaryData::ButtonExptUp_pngSize;
	if (button.getComponentID() == ID::button_Fact.toString())
		return isDown ? BinaryData::ButtonFactDown_pngSize : BinaryData::ButtonFactUp_pngSize;
	if (button.getComponentID().startsWith("button_Impt"))
		return isDown ? BinaryData::ButtonImptDown_pngSize : BinaryData::ButtonImptUp_pngSize;
	if (button.getComponentID() == ID::button_Load.toString())
		return isDown ? BinaryData::ButtonLoadDown_pngSize : BinaryData::ButtonLoadUp_pngSize;
	if (button.getComponentID() == ID::button_LockAll.toString())
		return isDown ? BinaryData::ButtonLockAllDown_pngSize : BinaryData::ButtonLockAllUp_pngSize;
	if (button.getComponentID() == ID::button_LockNone.toString())
		return isDown ? BinaryData::ButtonLockNoneDown_pngSize : BinaryData::ButtonLockNoneUp_pngSize;
	if (button.getComponentID() == ID::button_Name.toString())
		return isDown ? BinaryData::ButtonNameDown_pngSize : BinaryData::ButtonNameUp_pngSize;
	if (button.getComponentID() == ID::button_NewFldr.toString())
		return isDown ? BinaryData::ButtonNewFldrDown_pngSize : BinaryData::ButtonNewFldrUp_pngSize;
	if (button.getComponentID().startsWith("button_OK"))
		return isDown ? BinaryData::ButtonOKDown_pngSize : BinaryData::ButtonOKUp_pngSize;
	if (button.getComponentID() == ID::button_VoicesBank.toString())
		return isDown ? BinaryData::ButtonPgmBankDown_pngSize : BinaryData::ButtonPgmBankUp_pngSize;
	if (button.getComponentID().startsWith("button_Pull"))
		return isDown ? BinaryData::ButtonPullDown_pngSize : BinaryData::ButtonPullUp_pngSize;
	if (button.getComponentID().startsWith("button_Push"))
		return isDown ? BinaryData::ButtonPushDown_pngSize : BinaryData::ButtonPushUp_pngSize;
	if (button.getComponentID() == ID::button_Rand.toString())
		return isDown ? BinaryData::ButtonRandDown_pngSize : BinaryData::ButtonRandUp_pngSize;
	if (button.getComponentID() == ID::button_Redo.toString())
		return isDown ? BinaryData::ButtonRedoDown_pngSize : BinaryData::ButtonRedoUp_pngSize;
	if (button.getComponentID() == ID::button_Save.toString())
		return isDown ? BinaryData::ButtonSaveDown_pngSize : BinaryData::ButtonSaveUp_pngSize;
	if (button.getComponentID() == ID::button_Tips.toString())
		return isDown ? BinaryData::ButtonTipsDown_pngSize : BinaryData::ButtonTipsUp_pngSize;
	if (button.getComponentID() == ID::button_Undo.toString())
		return isDown ? BinaryData::ButtonUndoDown_pngSize : BinaryData::ButtonUndoUp_pngSize;
	return size_t();
}

void GUILookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
}

void GUILookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(), button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void GUILookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, const bool isTicked, const bool /*isEnabled*/, const bool isHighlighted, const bool /*isDown*/) {
	if (component.getComponentID() == ID::button_VoiceDataSlotRadioButton.toString()) {
		auto buttonColor{ Color::offWhite.withAlpha(0.0f) };
		if (isHighlighted)
			buttonColor = buttonColor.withAlpha(0.1f);
		if (isTicked)
			buttonColor = buttonColor.withAlpha(0.25f);
		g.setColour(buttonColor);
		g.fillRect(x, y, w, h);
		g.setColour(Color::offWhite);
		g.setFont(FontsMenu::fontFor_VoiceSlotRadioButtons);
		Rectangle<float> textArea{ x + 2, y, w, h };
		g.drawText(component.getName(), textArea, Justification::centredLeft);
	}
	if (component.getComponentID().startsWith("lockButton_")) {
		auto imageData{ isTicked ? BinaryData::ButtonLockClosed_png : BinaryData::ButtonLockOpen_png };
		auto imageSize{ isTicked ? BinaryData::ButtonLockClosed_pngSize : BinaryData::ButtonLockOpen_pngSize };
		if (imageData != nullptr) {
			PNGImageFormat imageFormat;
			MemoryInputStream memInputStream{ imageData, (size_t)imageSize, false };
			auto buttonImage{ imageFormat.decodeImage(memInputStream) };
			g.drawImageAt(buttonImage, 0, 0);
		}
	}
}

void GUILookAndFeel::layoutFileBrowserComponent(FileBrowserComponent& /*browser*/, DirectoryContentsDisplayComponent* dirContentsBox, FilePreviewComponent* /*previewComponent*/, ComboBox* currentPathBox, TextEditor* fileNameBox, Button* goUpButton) {
	currentPathBox->setBounds(GUI::bounds_ImptExptCurrentPathBox);
	goUpButton->setBounds(GUI::bounds_ImptExptGoUpButton);
	setColour(ListBox::backgroundColourId, Colours::transparentBlack);
	setColour(ListBox::outlineColourId, Colours::transparentBlack);
	if (auto* listAsComp = dynamic_cast<Component*> (dirContentsBox))
		listAsComp->setBounds(GUI::bounds_ImptExptDirContentsBox);
	fileNameBox->setBounds(GUI::bounds_ImptExptFileNameBox);
	fileNameBox->applyFontToAllText(FontsMenu::fontFor_BrowserText, true);
}

void GUILookAndFeel::drawFileBrowserRow(Graphics& g, int w, int h, const File& /*file*/, const String& filename, Image* /*icon*/, const String& fileSizeDescription, 
	const String& fileTimeDescription, bool isDirectory, bool itemIsSelected, int /*itemIndex*/, DirectoryContentsDisplayComponent& /*dirContentsDisplay*/) {
	if (itemIsSelected)
		g.fillAll(Color::knobGray.brighter(0.2f));
	g.setColour(Color::black);
	Path iconPath;
	if (isDirectory)
		iconPath.loadPathFromData(GUI::pathDataForFolderIcon.data(), GUI::pathDataForFolderIcon.size());
	else
		iconPath.loadPathFromData(GUI::pathDataForFileIcon.data(), GUI::pathDataForFileIcon.size());
	g.setColour(Color::offWhite);
	g.fillPath(iconPath);
	g.setFont(FontsMenu::fontFor_BrowserText);
	if (w > 450 && !isDirectory) {
		auto sizeX = roundToInt((float)w * 0.7f);
		auto dateX = roundToInt((float)w * 0.8f);
		g.drawFittedText(filename, GUI::fileBrowserIcon_w, 0, sizeX - GUI::fileBrowserIcon_w, h, Justification::centredLeft, 1);
		g.drawFittedText(fileSizeDescription, sizeX, 0, dateX - sizeX - 8, h, Justification::centredRight, 1);
		g.drawFittedText(fileTimeDescription, dateX, 0, w - 8 - dateX, h, Justification::centredRight, 1);
	}
	else {
		g.drawFittedText(filename, GUI::fileBrowserIcon_w, 0, w - GUI::fileBrowserIcon_w, h, Justification::centredLeft, 1);
	}
}

Button* GUILookAndFeel::createFileBrowserGoUpButton() {
	auto* goUpButton = new DrawableButton("up", DrawableButton::ImageOnButtonBackgroundOriginalSize);
	Path arrowPath;
	arrowPath.addArrow({ 10, 22, 10, 4 }, 7, 15, 10);
	DrawablePath arrowImage;
	arrowImage.setFill(Color::offWhite);
	arrowImage.setPath(arrowPath);
	goUpButton->setImages(&arrowImage);
	return goUpButton;
}

void GUILookAndFeel::drawComboBox(Graphics& g, int width, int height, bool /*isDown*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/) {
	Rectangle<int> arrowZone(width - 30, 0, 20, height);
	Path path;
	path.startNewSubPath((float)arrowZone.getX() + 3.0f, (float)arrowZone.getCentreY() - 2.0f);
	path.lineTo((float)arrowZone.getCentreX(), (float)arrowZone.getCentreY() + 3.0f);
	path.lineTo((float)arrowZone.getRight() - 3.0f, (float)arrowZone.getCentreY() - 2.0f);
	g.setColour(Color::offWhite);
	g.strokePath(path, PathStrokeType(2.0f));
}

void GUILookAndFeel::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(Color::knobGray);
}

void GUILookAndFeel::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool /*isActive*/, const bool isHighlighted, 
	const bool /*isTicked*/, const bool /*hasSubMenu*/, const String& text, const String& /*shortcutText*/, const Drawable* /*icon*/, const Colour* const /*textColor*/) {
	if (isSeparator) {
		auto separatorArea = area.reduced(5, 0);
		separatorArea.removeFromTop(roundToInt(((float)separatorArea.getHeight() * 0.5f) - 0.5f));
		g.setColour(Color::offWhite);
		g.fillRect(separatorArea.removeFromTop(1));
	}
	else {
		auto highlightedArea = area.reduced(1);
		if (isHighlighted) 		{
			g.setColour(Color::knobGray.brighter(0.2f));
			g.fillRect(highlightedArea);
		}
		g.setColour(Color::offWhite);
		auto textArea{ highlightedArea.reduced(4, 0) };
		g.setFont(FontsMenu::fontFor_BrowserText);
		g.drawFittedText(text, textArea, Justification::centredLeft, 1);
	}
}

