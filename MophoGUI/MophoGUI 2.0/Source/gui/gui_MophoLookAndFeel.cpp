#include "gui_MophoLookAndFeel.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_GUI_PathData.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;
using namespace BinaryData;
using MemBlock = MemoryBlock;
using s_t = size_t;

void MophoLookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& /*background*/, bool /*isHighlighted*/, bool isDown) {
	auto buttonID{ button.getComponentID() };
	MemBlock mBlock{};

	if (buttonID == ID::btn_AllowAll.toString())
		mBlock = MemBlock{ isDown ? btn_AllowAll_Dn_png : btn_AllowAll_Up_png, isDown ? (s_t)btn_AllowAll_Dn_pngSize : (s_t)btn_AllowAll_Up_pngSize };

	if (buttonID == ID::btn_Banks.toString())
		mBlock = MemBlock{ isDown ? btn_Banks_Dn_png : btn_Banks_Up_png, isDown ? (s_t)btn_Banks_Dn_pngSize : (s_t)btn_Banks_Up_pngSize };

	if (buttonID.startsWith("btn_Cancel"))
		mBlock = MemBlock{ isDown ? btn_Cancel_Dn_png : btn_Cancel_Up_png, isDown ? (s_t)btn_Cancel_Dn_pngSize : (s_t)btn_Cancel_Up_pngSize };

	if (buttonID == ID::btn_Clear.toString())
		mBlock = MemBlock{ isDown ? btn_Clear_Dn_png : btn_Clear_Up_png, isDown ? (s_t)btn_Clear_Dn_pngSize : (s_t)btn_Clear_Up_pngSize };

	if (buttonID == ID::btn_Close.toString())
		mBlock = MemBlock{ isDown ? btn_Close_Dn_png : btn_Close_Up_png, isDown ? (s_t)btn_Close_Dn_pngSize : (s_t)btn_Close_Up_pngSize };

	if (buttonID == ID::btn_Create.toString())
		mBlock = MemBlock{ isDown ? btn_Create_Dn_png : btn_Create_Up_png, isDown ? (s_t)btn_Create_Dn_pngSize : (s_t)btn_Create_Up_pngSize };

	if (buttonID == ID::btn_Edit.toString())
		mBlock = MemBlock{ isDown ? btn_Edit_Dn_png : btn_Edit_Up_png, isDown ? (s_t)btn_Edit_Dn_pngSize : (s_t)btn_Edit_Up_pngSize };

	if (buttonID.startsWith("btn_Export"))
		mBlock = MemBlock{ isDown ? btn_Export_Dn_png : btn_Export_Up_png, isDown ? (s_t)btn_Export_Dn_pngSize : (s_t)btn_Export_Up_pngSize };

	if (buttonID == ID::btn_Global.toString())
		mBlock = MemBlock{ isDown ? btn_Global_Dn_png : btn_Global_Up_png, isDown ? (s_t)btn_Global_Dn_pngSize : (s_t)btn_Global_Up_pngSize };

	if (buttonID == ID::btn_GroupLock.toString())
		mBlock = MemBlock{ isDown ? btn_GroupLock_Dn_png : btn_GroupLock_Up_png, isDown ? (s_t)btn_GroupLock_Dn_pngSize : (s_t)btn_GroupLock_Up_pngSize };

	if (buttonID == ID::btn_GroupUnlock.toString())
		mBlock = MemBlock{ isDown ? btn_GroupUnlock_Dn_png : btn_GroupUnlock_Up_png, isDown ? (s_t)btn_GroupUnlock_Dn_pngSize : (s_t)btn_GroupUnlock_Up_pngSize };

	if (buttonID.startsWith("btn_Import"))
		mBlock = MemBlock{ isDown ? btn_Import_Dn_png : btn_Import_Up_png, isDown ? (s_t)btn_Import_Dn_pngSize : (s_t)btn_Import_Up_pngSize };

	if (buttonID == ID::btn_Load.toString())
		mBlock = MemBlock{ isDown ? btn_Load_Dn_png : btn_Load_Up_png, isDown ? (s_t)btn_Load_Dn_pngSize : (s_t)btn_Load_Up_pngSize };

	if (buttonID == ID::btn_NewFolder.toString())
		mBlock = MemBlock{ isDown ? btn_NewFolder_Dn_png : btn_NewFolder_Up_png, isDown ? (s_t)btn_NewFolder_Dn_pngSize : (s_t)btn_NewFolder_Up_pngSize };

	if (buttonID.startsWith("btn_Pull"))
		mBlock = MemBlock{ isDown ? btn_Pull_Dn_png : btn_Pull_Up_png, isDown ? (s_t)btn_Pull_Dn_pngSize : (s_t)btn_Pull_Up_pngSize };

	if (buttonID.startsWith("btn_Push"))
		mBlock = MemBlock{ isDown ? btn_Push_Dn_png : btn_Push_Up_png, isDown ? (s_t)btn_Push_Dn_pngSize : (s_t)btn_Push_Up_pngSize };

	if (buttonID == ID::btn_Randomize.toString())
		mBlock = MemBlock{ isDown ? btn_Randomize_Dn_png : btn_Randomize_Up_png, isDown ? (s_t)btn_Randomize_Dn_pngSize : (s_t)btn_Randomize_Up_pngSize };

	if (buttonID == ID::btn_Read.toString())
		mBlock = MemBlock{ isDown ? btn_Read_Dn_png : btn_Read_Up_png, isDown ? (s_t)btn_Read_Dn_pngSize : (s_t)btn_Read_Up_pngSize };

	if (buttonID == ID::btn_Redo.toString())
		mBlock = MemBlock{ isDown ? btn_Redo_Dn_png : btn_Redo_Up_png, isDown ? (s_t)btn_Redo_Dn_pngSize : (s_t)btn_Redo_Up_pngSize };

	if (buttonID == ID::btn_Retry.toString())
		mBlock = MemBlock{ isDown ? btn_Retry_Dn_png : btn_Retry_Up_png, isDown ? (s_t)btn_Retry_Dn_pngSize : (s_t)btn_Retry_Up_pngSize };

	if (buttonID == ID::btn_Save.toString())
		mBlock = MemBlock{ isDown ? btn_Save_Dn_png : btn_Save_Up_png, isDown ? (s_t)btn_Save_Dn_pngSize : (s_t)btn_Save_Up_pngSize };

	if (buttonID == ID::btn_Stop.toString())
		mBlock = MemBlock{ isDown ? btn_Stop_Dn_png : btn_Stop_Up_png, isDown ? (s_t)btn_Stop_Dn_pngSize : (s_t)btn_Stop_Up_pngSize };

	if (buttonID == ID::btn_Undo.toString())
		mBlock = MemBlock{ isDown ? btn_Undo_Dn_png : btn_Undo_Up_png, isDown ? (s_t)btn_Undo_Dn_pngSize : (s_t)btn_Undo_Up_pngSize };

	if (buttonID.startsWith("btn_Write"))
		mBlock = MemBlock{ isDown ? btn_Write_Dn_png : btn_Write_Up_png, isDown ? (s_t)btn_Write_Dn_pngSize : (s_t)btn_Write_Up_pngSize };

	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto buttonImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(buttonImage, 0, 0);
}

void MophoLookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
}




void MophoLookAndFeel::drawComboBox(Graphics& /*g*/, int /*width*/, int /*height*/, bool /*isDown*/,
	int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/)
{
}

void MophoLookAndFeel::positionComboBoxText(ComboBox& box, Label& label) {
	auto spaceForArrowIcon{ 11 };
	auto parentComponent{ box.getParentComponent() };
	if (parentComponent != nullptr) {
		auto isInImptExptFileBrowser{ parentComponent->getComponentID() == ID::comp_ImptExptBrowser.toString() };
		if (isInImptExptFileBrowser)
			spaceForArrowIcon = 20;
	}
	label.setBounds(0, 0, box.getWidth() - spaceForArrowIcon, box.getHeight());
}

PopupMenu::Options MophoLookAndFeel::getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) {
	auto numberOfColumns{ 1 };
	auto popupWidth(box.getWidth());
	if (box.getNumItems() > 20) {
		numberOfColumns = 2;
		popupWidth = box.getWidth() * 2;
	}
	if (box.getNumItems() > 40) {
		numberOfColumns = 5;
		popupWidth = box.getWidth() * 5;
	}
	return PopupMenu::Options()
		.withTargetComponent(&box)
		.withItemThatMustBeVisible(box.getSelectedId())
		.withMinimumWidth(popupWidth)
		.withMinimumNumColumns(numberOfColumns)
		.withMaximumNumColumns(numberOfColumns)
		.withStandardItemHeight(label.getHeight());
}

void MophoLookAndFeel::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(GUI::color_Black.brighter(0.2f));
}

void MophoLookAndFeel::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive,
	const bool isHighlighted, const bool isTicked, const bool hasSubMenu, const String& text, const String& /*shortcutText*/,
	const Drawable* /*icon*/, const Colour* const /*textColor*/)
{
	if (isSeparator) {
		auto separatorArea = area.reduced(5, 0);
		separatorArea.removeFromTop(roundToInt(((float)separatorArea.getHeight() * 0.5f) - 0.5f));
		g.setColour(GUI::color_White);
		g.fillRect(separatorArea.removeFromTop(1));
	}
	else {
		auto reducedArea = area.reduced(1);
		if (isHighlighted && isActive) {
			g.setColour(findColour(PopupMenu::highlightedBackgroundColourId));
			g.fillRect(reducedArea);
		}
		reducedArea.reduce(5, 0);
		g.setFont(GUI::font_PopupMenuItems);
		auto iconArea = reducedArea.removeFromLeft(5).toFloat();
		if (isTicked) {
			g.setColour(GUI::color_Bullseye);
			g.fillEllipse(4.0f, 6.0f, 4.0f, 4.0f);
		}
		else
			g.setColour(GUI::color_White);
		if (hasSubMenu) {
			auto arrowH = 0.6f * getPopupMenuFont().getAscent();
			auto x = static_cast<float> (reducedArea.removeFromRight((int)arrowH).getX());
			auto halfH = static_cast<float> (reducedArea.getCentreY());
			Path path;
			path.startNewSubPath(x, halfH - arrowH * 0.5f);
			path.lineTo(x + arrowH * 0.6f, halfH);
			path.lineTo(x, halfH + arrowH * 0.5f);
			g.strokePath(path, PathStrokeType(2.0f));
		}
		reducedArea.removeFromRight(3);
		g.drawFittedText(text, reducedArea, Justification::centredLeft, 1);
	}
}

void MophoLookAndFeel::getIdealPopupMenuItemSize(const String& /*text*/, const bool /*isSeparator*/,
	int itemHeight, int& /*idealWidth*/, int& idealHeight)
{
	auto font = getPopupMenuFont();
	if (itemHeight > 0 && font.getHeight() > itemHeight / 1.3f)
		font.setHeight(itemHeight / 1.3f);
	idealHeight = itemHeight > 0 ? itemHeight : roundToInt(font.getHeight() * 1.3f);
}




void MophoLookAndFeel::layoutFileBrowserComponent(
	Browser& /*browser*/, DirContents* dirContents, Preview* /*preview*/, ComboBox* currentPath, TextEditor* fileName, Button* goUpButton)
{
	const int browser_w{ 471 };
	currentPath->setBounds(0, 0, browser_w, 26);
	currentPath->setJustificationType(Justification::centredLeft);
	goUpButton->setBounds(450, 0, 20, currentPath->getHeight());
	setColour(ListBox::backgroundColourId, GUI::color_Black.withAlpha(0.0f));
	setColour(ListBox::outlineColourId, GUI::color_Black.withAlpha(0.0f));
	if (auto* listAsComp = dynamic_cast<Component*> (dirContents))
		listAsComp->setBounds(0, 36, browser_w, 173);
	fileName->setBounds(86, 219, 385, currentPath->getHeight());
	fileName->applyFontToAllText(GUI::font_BrowserText, true);
}

void MophoLookAndFeel::drawFileBrowserRow(Graphics& g, int w, int h, const File& /*file*/, const String& fileName, Image* /*icon*/,
	const String& fileSizeString, const String& fileTimeString, bool isDirectory, bool isSelected, int /*itemIndex*/, DirContents& /*dirContents*/)
{
	if (isSelected)
		g.fillAll(GUI::color_Black.brighter(0.3f));
	Path iconPath;
	if (isDirectory)
		iconPath.loadPathFromData(GUI::pathDataForFolderIcon.data(), GUI::pathDataForFolderIcon.size());
	else
		iconPath.loadPathFromData(GUI::pathDataForFileIcon.data(), GUI::pathDataForFileIcon.size());
	g.setColour(GUI::color_White);
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

Button* MophoLookAndFeel::createFileBrowserGoUpButton() {
	auto* goUpButton = new DrawableButton("up", DrawableButton::ImageOnButtonBackgroundOriginalSize);
	Path arrowPath;
	arrowPath.addArrow({ 10, 22, 10, 4 }, 7, 15, 10);
	DrawablePath arrowImage;
	arrowImage.setFill(GUI::color_Black);
	arrowImage.setPath(arrowPath);
	goUpButton->setImages(&arrowImage);
	return goUpButton;
}




void MophoLookAndFeel::drawLabel(Graphics& g, Label& label) {
	auto isInImptExptBrowser{ label.getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString() ||
		label.getParentComponent()->getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString()
	};
	if (isInImptExptBrowser) {
		auto textArea{ label.getLocalBounds() };
		textArea.removeFromLeft(5);
		g.setColour(GUI::color_White);
		g.setFont(GUI::font_BrowserText);
		g.drawFittedText(label.getText(), textArea, Justification::centredLeft, 1, 1.0f);
	}
	else {
		g.setFont(GUI::font_Labels);
		g.setColour(GUI::color_White);
		if (label.getComponentID() != "") {
			if (label.getComponentID() == ID::lbl_EditLabel.toString()) {
				g.fillAll(GUI::color_Black);
				g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
			}
			if (label.getComponentID() == ID::lbl_DisplayLabel.toString()) {
				g.setFont(GUI::font_DisplayLabels);
				g.setColour(label.findColour(label.textColourId));
				g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
			}
			if (label.getComponentID() == ID::lbl_VoiceNameEditor.toString()) {
				g.setFont(GUI::font_VoiceNameEditorText);
				g.setColour(GUI::color_Black.withAlpha(0.0f));
				g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
			}
		}
		else
			g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
	}
}

void MophoLookAndFeel::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/, TextEditor& textEditor) {
	auto editorIsInImportExportBrowser{ textEditor.getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString() ||
		textEditor.getParentComponent()->getParentComponent()->getParentComponent()->getComponentID() == ID::comp_ImptExptBrowser.toString()
	};
	if (editorIsInImportExportBrowser)
		textEditor.applyFontToAllText(GUI::font_BrowserText);
	if (textEditor.getParentComponent()->getComponentID() == ID::comp_TextEditorForKnob.toString() ||
		textEditor.getParentComponent()->getComponentID() == ID::comp_TextEditorForSeqStep.toString()) {
		textEditor.setJustification(Justification::centred);
		g.setColour(GUI::color_Black);
		if (textEditor.getParentComponent()->getComponentID() == ID::comp_TextEditorForKnob.toString())
			g.fillEllipse(5.0f, 5.0f, 30.0f, 30.0f);
		else
			g.fillAll();
	}
	else
		g.fillAll(GUI::color_Black);
}

void MophoLookAndFeel::drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
}




void MophoLookAndFeel::drawProgressBar(Graphics& g, ProgressBar& bar, int w, int h, double percentDone, const String& textToShow) {
	auto background{ bar.findColour(ProgressBar::backgroundColourId) };
	auto foreground{ bar.findColour(ProgressBar::foregroundColourId) };
	auto barBounds{ bar.getLocalBounds().toFloat() };
	g.setColour(background);
	g.fillRoundedRectangle(barBounds, bar.getHeight() * 0.5f);
	if (percentDone >= 0.0f && percentDone <= 1.0f) {
		Path p;
		p.addRoundedRectangle(barBounds, bar.getHeight() * 0.5f);
		g.reduceClipRegion(p);
		barBounds.setWidth(barBounds.getWidth() * (float)percentDone);
		g.setColour(foreground);
		g.fillRoundedRectangle(barBounds, bar.getHeight() * 0.5f);
	}
	else {
		// spinning bar..
		g.setColour(background);
		auto stripeWidth = h * 2;
		auto position = static_cast<int> (Time::getMillisecondCounter() / 15) % stripeWidth;
		Path p;
		for (auto x = static_cast<float> (-position); x < w + stripeWidth; x += stripeWidth)
			p.addQuadrilateral(x, 0.0f,
				x + stripeWidth * 0.5f, 0.0f,
				x, static_cast<float> (h),
				x - stripeWidth * 0.5f, static_cast<float> (h));
		Image im(Image::ARGB, w, h, true);
		{
			Graphics g2(im);
			g2.setColour(foreground);
			g2.fillRoundedRectangle(barBounds, bar.getHeight() * 0.5f);
		}
		g.setTiledImageFill(im, 0, 0, 0.85f);
		g.fillPath(p);
	}
	if (textToShow.isNotEmpty()) {
		g.setColour(GUI::color_White);
		g.setFont(GUI::font_ProgressBar);
		g.drawText(textToShow, 0, 0, w, h, Justification::centred, false);
	}
}




int MophoLookAndFeel::getDefaultScrollbarWidth() {
	return 10;
}

void MophoLookAndFeel::drawScrollbar(Graphics& g, ScrollBar& /*scrollbar*/, int x, int y, int w, int h,
	bool isVertical, int thumbStartPosition, int thumbSize, bool /*mouseIsOver*/, bool /*mouseIsDown*/)
{
	Rectangle<int> thumbBounds;
	if (isVertical)
		thumbBounds = { x, thumbStartPosition, w, thumbSize };
	else
		thumbBounds = { thumbStartPosition, y, thumbSize, h };
	thumbBounds.reduce(2, 2);
	g.setColour(GUI::color_White);
	g.fillRect(thumbBounds.toFloat());
}




void MophoLookAndFeel::drawRotarySlider(
	Graphics& g, int /*x*/, int y, int w, int /*h*/, float sliderPos, const float startAngle, const float endAngle, Slider& /*slider*/)
{
	auto diameter{ (float)w };
	Point<float> sliderCenter{ diameter / 2.0f, diameter / 2.0f };
	auto pointerAngle = startAngle + sliderPos * (endAngle - startAngle);
	Line<float> line;
	line.setStart(sliderCenter.x, float(y + 7));
	line.setEnd(sliderCenter.x, float(y + 1));
	Path pointerPath;
	pointerPath.addArrow(line, 1.0f, 8.0f, 6.0f);
	pointerPath.applyTransform(AffineTransform::rotation(pointerAngle, sliderCenter.x, sliderCenter.y));
	g.setColour(GUI::color_Black);
	g.fillPath(pointerPath);
}




void MophoLookAndFeel::drawTabButton(TabBarButton& button, Graphics& g, bool /*isMouseOver*/, bool /*isMouseDown*/) {
	const Rectangle<int> activeArea(button.getActiveArea());
	const Colour bkg(button.getTabBackgroundColour());
	if (button.getToggleState())
		g.setColour(bkg);
	else {
		Point<int> tabTopCoordinate{ activeArea.getTopLeft() };
		Point<int> tabBottomCoordinate{ activeArea.getBottomLeft() };
		g.setColour(bkg.darker(0.06f));
	}
	g.fillRect(activeArea);

	auto buttonIndex{ button.getIndex() };
	MemBlock mBlock{};
	if (button.getParentComponent()->getParentComponent()->getComponentID() == ID::comp_TabbedComponentForAllBanks.toString()) {
		if (buttonIndex == 0)
			mBlock = MemBlock{ BinaryData::lbl_FactoryVoiceBanks_png, BinaryData::lbl_FactoryVoiceBanks_pngSize };
		else
			mBlock = MemBlock{ BinaryData::lbl_CustomVoiceBanks_png, BinaryData::lbl_CustomVoiceBanks_pngSize };
	}
	else {
		if (buttonIndex == 0)
			mBlock = MemBlock{ BinaryData::lbl_VoiceBankTab_1_png, BinaryData::lbl_VoiceBankTab_1_pngSize };
		if (button.getIndex() == 1)
			mBlock = MemBlock{ BinaryData::lbl_VoiceBankTab_2_png, BinaryData::lbl_VoiceBankTab_2_pngSize };
		if (button.getIndex() == 2)
			mBlock = MemBlock{ BinaryData::lbl_VoiceBankTab_3_png, BinaryData::lbl_VoiceBankTab_3_pngSize };
	}
	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto buttonImage{ imageFormat.decodeImage(memInputStream) };
	auto image_x{ (activeArea.getWidth() - buttonImage.getWidth()) / 2 };
	auto image_y{ (activeArea.getHeight() - buttonImage.getHeight()) / 2 };
	g.drawImageAt(buttonImage, image_x, image_y);
}




void MophoLookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(),
		button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void MophoLookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h,
	const bool isTicked, const bool /*isEnabled*/, const bool isHighlighted, const bool /*isDown*/)
{
	auto componentID{ component.getComponentID() };
	if (componentID == ID::comp_RedToggle.toString()) {
		g.setColour(isTicked ? GUI::color_ToggleOn : GUI::color_ToggleOff);
		g.fillEllipse(x, y, w, h);
	}
	if (componentID == ID::btn_VoiceSlotRadioButton.toString()) {
		auto buttonColor{ GUI::color_Device };
		if (isHighlighted)
			buttonColor = buttonColor.brighter(0.4f);
		if (isTicked)
			buttonColor = buttonColor.brighter(0.7f);
		g.setColour(buttonColor);
		g.fillRect(x, y, w, h);
		g.setColour(GUI::color_Black);
		g.setFont(GUI::font_VoiceSlotButtons);
		Rectangle<float> textArea{ x + 3, y, w - 3, h };
		g.drawText(component.getName(), textArea, Justification::centredLeft);
	}
	if (componentID.startsWith(ID::comp_ToggleAllow_Choice_.toString())) {
		if (isTicked) {
			g.setColour(GUI::color_White.withAlpha(0.2f));
			g.fillRect(x, y, w, h);
		}
		g.setColour(GUI::color_Black);
		g.setFont(GUI::font_VoiceSlotButtons);
		Rectangle<float> textArea{ x + 3, y, w - 3, h };
		g.drawText(component.getName(), textArea, Justification::centredLeft);
	}
	if (componentID.startsWith("comp_ToggleLock")) {
		PNGImageFormat imageFormat;
		MemoryInputStream memInputStream{ BinaryData::icon_Locked_png, BinaryData::icon_Locked_pngSize, false };
		auto lockedIcon{ imageFormat.decodeImage(memInputStream) };
		g.setColour(isTicked ? GUI::color_Black.withAlpha(0.3f) : GUI::color_ToggleOn.withAlpha(0.2f));
		if (componentID.contains("ComboBox")) {
			if (isTicked) {
				g.fillRect(x, y + 2, w, h - 4);
				g.setOpacity(1.0f);
				g.drawImageAt(lockedIcon, int(w / 2) - (GUI::lockAndUnlockIcons_w / 2), 0);
			}
			else
				g.fillRect(x, y + 2, w, h - 4);
		}
		if (componentID.contains("Knob")) {
			if (isTicked) {
				g.fillEllipse(x, y, w, h);
				g.setOpacity(1.0f);
				g.drawImageAt(lockedIcon, 8, 5);
			}
			else
				g.fillEllipse(x, y, w, h);
		}
		if (componentID.contains("SeqStep")) {
			if (isTicked) {
				g.fillRect(x, y, w, h);
				g.setOpacity(1.0f);
				g.drawImageAt(lockedIcon, 6, 3);
			}
			else
				g.fillRect(x, y, w, h);
		}
		if (componentID.contains("_Toggle_")) {
			if (isTicked) {
				g.fillEllipse(x, y, w, h);
				g.setOpacity(1.0f);
				g.drawImageAt(lockedIcon, 4, 1);
			}
			else
				g.fillEllipse(x, y, w, h);
		}
		if (componentID.contains("VoiceNameChar")) {
			if (isTicked) {
				g.fillRect(x, y, w, h);
				g.setOpacity(1.0f);
				g.drawImageAt(lockedIcon, (int)x - 1, (int)y - 1);
			}
			else
				g.fillRect(x, y, w, h);
		}
		g.setColour(GUI::color_Black);
		g.setFont(GUI::font_Labels);
		Rectangle<float> textArea{ x + 3, y, w - 3, h };
		g.drawText(component.getName(), textArea, Justification::centredLeft);
	}
}




Rectangle<int> MophoLookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout textLayout(layoutTooltipText(tipText, GUI::color_Black));
	auto w = (int)(textLayout.getWidth() + 16.0f);
	auto h = (int)(textLayout.getHeight() + 14.0f);
	return Rectangle<int>(
		screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
		screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

void MophoLookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(GUI::color_Black.brighter(0.1f));
	g.fillRect(bounds.toFloat());
	g.setColour(GUI::color_White);
	g.drawRect(bounds.toFloat(), 2.0f);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId)).draw(g, { static_cast<float>(width), static_cast<float>(height) });
}

TextLayout MophoLookAndFeel::layoutTooltipText(const String& text, Colour colour) noexcept {
	AttributedString attribString;
	attribString.setJustification(Justification::centred);
	attribString.append(text, GUI::font_Tooltips, colour);
	TextLayout textLayout;
	const float tooltipMaxWidth{ 400.0f };
	textLayout.createLayout(attribString, tooltipMaxWidth);
	return textLayout;
}
