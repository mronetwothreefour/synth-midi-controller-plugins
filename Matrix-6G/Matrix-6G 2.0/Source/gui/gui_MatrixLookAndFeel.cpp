#include "gui_MatrixLookAndFeel.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_GUI_PathData.h"
#include "../gui/gui_build_LED_Path.h"

using namespace Matrix_6G_Constants;
using namespace BinaryData;
using MemBlock = MemoryBlock;
using s_t = size_t;

void MatrixLookAndFeel::drawButtonBackground(Graphics& g, Button& button, const Colour& /*background*/, bool /*isHighlighted*/, bool isDown) {
	auto buttonID{ button.getComponentID() };
	MemBlock mBlock{};

	if (buttonID == ID::btn_ActivateQuickEdit.toString())
		mBlock = MemBlock{ isDown ? btn_ActivateQuickEdit_Dn_png : btn_ActivateQuickEdit_Up_png, isDown ? (s_t)btn_ActivateQuickEdit_Dn_pngSize : (s_t)btn_ActivateQuickEdit_Up_pngSize };

	if (buttonID == ID::btn_ActivateQuickEdit_Flash.toString())
		mBlock = MemBlock{ btn_ActivateQuickEdit_Flash_png, (s_t)btn_ActivateQuickEdit_Flash_pngSize };

	if (buttonID == ID::btn_AllowAll.toString())
		mBlock = MemBlock{ isDown ? btn_AllowAll_Dn_png : btn_AllowAll_Up_png, isDown ? (s_t)btn_AllowAll_Dn_pngSize : (s_t)btn_AllowAll_Up_pngSize };

	if (buttonID.startsWith("btn_Cancel"))
		mBlock = MemBlock{ isDown ? btn_Cancel_Dn_png : btn_Cancel_Up_png, isDown ? (s_t)btn_Cancel_Dn_pngSize : (s_t)btn_Cancel_Up_pngSize };

	if (buttonID == ID::btn_Close.toString())
		mBlock = MemBlock{ isDown ? btn_Close_Dn_png : btn_Close_Up_png, isDown ? (s_t)btn_Close_Dn_pngSize : (s_t)btn_Close_Up_pngSize };

	if (buttonID == ID::btn_Create.toString())
		mBlock = MemBlock{ isDown ? btn_Create_Dn_png : btn_Create_Up_png, isDown ? (s_t)btn_Create_Dn_pngSize : (s_t)btn_Create_Up_pngSize };

	if (buttonID == ID::btn_Edit.toString())
		mBlock = MemBlock{ isDown ? btn_EditVoiceMap_Dn_png : btn_EditVoiceMap_Up_png, isDown ? (s_t)btn_EditVoiceMap_Dn_pngSize : (s_t)btn_EditVoiceMap_Up_pngSize };

	if (buttonID.startsWith("btn_Export"))
		mBlock = MemBlock{ isDown ? btn_Export_Dn_png : btn_Export_Up_png, isDown ? (s_t)btn_Export_Dn_pngSize : (s_t)btn_Export_Up_pngSize };

	if (buttonID.startsWith("btn_Expt_"))
		mBlock = MemBlock{ isDown ? btn_Expt_Dn_png : btn_Expt_Up_png, isDown ? (s_t)btn_Expt_Dn_pngSize : (s_t)btn_Expt_Up_pngSize };

	if (buttonID == ID::btn_GroupLock.toString())
		mBlock = MemBlock{ isDown ? btn_GroupLock_Dn_png : btn_GroupLock_Up_png, isDown ? (s_t)btn_GroupLock_Dn_pngSize : (s_t)btn_GroupLock_Up_pngSize };

	if (buttonID == ID::btn_GroupLock_All.toString())
		mBlock = MemBlock{ isDown ? btn_Lock_Dn_png : btn_Lock_Up_png, isDown ? (s_t)btn_Lock_Dn_pngSize : (s_t)btn_Lock_Up_pngSize };

	if (buttonID == ID::btn_GroupUnlock.toString())
		mBlock = MemBlock{ isDown ? btn_GroupUnlock_Dn_png : btn_GroupUnlock_Up_png, isDown ? (s_t)btn_GroupUnlock_Dn_pngSize : (s_t)btn_GroupUnlock_Up_pngSize };

	if (buttonID == ID::btn_GroupUnlock_All.toString())
		mBlock = MemBlock{ isDown ? btn_Unlock_Dn_png : btn_Unlock_Up_png, isDown ? (s_t)btn_Unlock_Dn_pngSize : (s_t)btn_Unlock_Up_pngSize };

	if (buttonID.startsWith("btn_Import"))
		mBlock = MemBlock{ isDown ? btn_Import_Dn_png : btn_Import_Up_png, isDown ? (s_t)btn_Import_Dn_pngSize : (s_t)btn_Import_Up_pngSize };

	if (buttonID.startsWith("btn_Impt_"))
		mBlock = MemBlock{ isDown ? btn_Impt_Dn_png : btn_Impt_Up_png, isDown ? (s_t)btn_Impt_Dn_pngSize : (s_t)btn_Impt_Up_pngSize };

	if (buttonID == ID::btn_Load_Split.toString())
		mBlock = MemBlock{ isDown ? btn_LoadSplit_Dn_png : btn_LoadSplit_Up_png, isDown ? (s_t)btn_LoadSplit_Dn_pngSize : (s_t)btn_LoadSplit_Up_pngSize };

	if (buttonID == ID::btn_Load_Voice.toString())
		mBlock = MemBlock{ isDown ? btn_LoadVoice_Dn_png : btn_LoadVoice_Up_png, isDown ? (s_t)btn_LoadVoice_Dn_pngSize : (s_t)btn_LoadVoice_Up_pngSize };

	if (buttonID == ID::btn_NewFolder.toString())
		mBlock = MemBlock{ isDown ? btn_NewFolder_Dn_png : btn_NewFolder_Up_png, isDown ? (s_t)btn_NewFolder_Dn_pngSize : (s_t)btn_NewFolder_Up_pngSize };

	if (buttonID == ID::btn_Master.toString())
		mBlock = MemBlock{ isDown ? btn_Master_Dn_png : btn_Master_Up_png, isDown ? (s_t)btn_Master_Dn_pngSize : (s_t)btn_Master_Up_pngSize };

	if (buttonID == ID::btn_Patches.toString())
		mBlock = MemBlock{ isDown ? btn_Patches_Dn_png : btn_Patches_Up_png, isDown ? (s_t)btn_Patches_Dn_pngSize : (s_t)btn_Patches_Up_pngSize };

	if (buttonID == ID::btn_Pull.toString())
		mBlock = MemBlock{ isDown ? btn_Pull_Dn_png : btn_Pull_Up_png, isDown ? (s_t)btn_Pull_Dn_pngSize : (s_t)btn_Pull_Up_pngSize };

	if (buttonID.startsWith("btn_Pull_Split"))
		mBlock = MemBlock{ isDown ? btn_PullSplit_Dn_png : btn_PullSplit_Up_png, isDown ? (s_t)btn_PullSplit_Dn_pngSize : (s_t)btn_PullSplit_Up_pngSize };

	if (buttonID.startsWith("btn_Pull_Voice"))
		mBlock = MemBlock{ isDown ? btn_PullVoice_Dn_png : btn_PullVoice_Up_png, isDown ? (s_t)btn_PullVoice_Dn_pngSize : (s_t)btn_PullVoice_Up_pngSize };

	if (buttonID == ID::btn_Push.toString())
		mBlock = MemBlock{ isDown ? btn_Push_Dn_png : btn_Push_Up_png, isDown ? (s_t)btn_Push_Dn_pngSize : (s_t)btn_Push_Up_pngSize };

	if (buttonID == ID::btn_Push_SplitsBankAndGlobalParams.toString())
		mBlock = MemBlock{ isDown ? btn_PushSplit_Dn_png : btn_PushSplit_Up_png, isDown ? (s_t)btn_PushSplit_Dn_pngSize : (s_t)btn_PushSplit_Up_pngSize };

	if (buttonID.startsWith(ID::btn_Randomize.toString()))
		mBlock = MemBlock{ isDown ? btn_Randomize_Dn_png : btn_Randomize_Up_png, isDown ? (s_t)btn_Randomize_Dn_pngSize : (s_t)btn_Randomize_Up_pngSize };

	if (buttonID.startsWith(ID::btn_Push_VoicesBank_.toString()))
		mBlock = MemBlock{ isDown ? btn_PushVoice_Dn_png : btn_PushVoice_Up_png, isDown ? (s_t)btn_PushVoice_Dn_pngSize : (s_t)btn_PushVoice_Up_pngSize };

	if (buttonID.startsWith(ID::btn_Reset.toString()))
		mBlock = MemBlock{ isDown ? btn_ResetPatchMap_Dn_png : btn_ResetPatchMap_Up_png, isDown ? (s_t)btn_ResetPatchMap_Dn_pngSize : (s_t)btn_ResetPatchMap_Up_pngSize };

	if (buttonID.startsWith(ID::btn_Retry.toString()))
		mBlock = MemBlock{ isDown ? btn_Retry_Dn_png : btn_Retry_Up_png, isDown ? (s_t)btn_Retry_Dn_pngSize : (s_t)btn_Retry_Up_pngSize };

	if (buttonID.startsWith(ID::btn_Splits.toString()))
		mBlock = MemBlock{ isDown ? btn_Splits_Dn_png : btn_Splits_Up_png, isDown ? (s_t)btn_Splits_Dn_pngSize : (s_t)btn_Splits_Up_pngSize };

	if (buttonID == ID::btn_Save_Voice.toString())
		mBlock = MemBlock{ isDown ? btn_SaveVoice_Dn_png : btn_SaveVoice_Up_png, isDown ? (s_t)btn_SaveVoice_Dn_pngSize : (s_t)btn_SaveVoice_Up_pngSize };

	if (buttonID == ID::btn_Save_Split.toString())
		mBlock = MemBlock{ isDown ? btn_SaveSplit_Dn_png : btn_SaveSplit_Up_png, isDown ? (s_t)btn_SaveSplit_Dn_pngSize : (s_t)btn_SaveSplit_Up_pngSize };

	if (buttonID == ID::btn_Stop.toString())
		mBlock = MemBlock{ isDown ? btn_Stop_Dn_png : btn_Stop_Up_png, isDown ? (s_t)btn_Stop_Dn_pngSize : (s_t)btn_Stop_Up_pngSize };

	if (buttonID == ID::btn_Write_OverFile.toString())
		mBlock = MemBlock{ isDown ? btn_Write_Dn_png : btn_Write_Up_png, isDown ? (s_t)btn_Write_Dn_pngSize : (s_t)btn_Write_Up_pngSize };

	if (buttonID == ID::btn_X_Blue.toString())
		mBlock = MemBlock{ isDown ? btn_X_Blue_Dn_png : btn_X_Blue_Up_png, isDown ? (s_t)btn_X_Blue_Dn_pngSize : (s_t)btn_X_Blue_Up_pngSize };

	if (buttonID == ID::btn_X_Grey.toString())
		mBlock = MemBlock{ isDown ? btn_X_Grey_Dn_png : btn_X_Grey_Up_png, isDown ? (s_t)btn_X_Grey_Dn_pngSize : (s_t)btn_X_Grey_Up_pngSize };

	if (buttonID == ID::btn_X_Orange.toString())
		mBlock = MemBlock{ isDown ? btn_X_Orange_Dn_png : btn_X_Orange_Up_png, isDown ? (s_t)btn_X_Orange_Dn_pngSize : (s_t)btn_X_Orange_Up_pngSize };

	PNGImageFormat imageFormat;
	MemoryInputStream memInputStream{ mBlock, false };
	auto buttonImage{ imageFormat.decodeImage(memInputStream) };
	g.drawImageAt(buttonImage, 0, 0);
}

void MatrixLookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
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




void MatrixLookAndFeel::layoutFileBrowserComponent(
	Browser& /*browser*/, DirContents* dirContents, Preview* /*preview*/, ComboBox* currentPath, TextEditor* fileName, Button* goUpButton)
{
	const int browser_w{ 464 };
	currentPath->setBounds(0, 0, browser_w, 26);
	currentPath->setJustificationType(Justification::centredLeft);
	goUpButton->setBounds(445, 0, 20, currentPath->getHeight());
	setColour(ListBox::backgroundColourId, GUI::color_Black.withAlpha(0.0f));
	setColour(ListBox::outlineColourId, GUI::color_Black.withAlpha(0.0f));
	if (auto* listAsComp = dynamic_cast<Component*> (dirContents))
		listAsComp->setBounds(0, 36, browser_w, 173);
	fileName->setBounds(76, 219, 388, currentPath->getHeight());
	fileName->applyFontToAllText(GUI::font_BrowserText, true);
}

void MatrixLookAndFeel::drawFileBrowserRow(Graphics& g, int w, int h, const File& /*file*/, const String& fileName, Image* /*icon*/,
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

Button* MatrixLookAndFeel::createFileBrowserGoUpButton() {
	auto* goUpButton = new DrawableButton("up", DrawableButton::ImageOnButtonBackgroundOriginalSize);
	Path arrowPath;
	arrowPath.addArrow({ 10, 22, 10, 4 }, 7, 15, 10);
	DrawablePath arrowImage;
	arrowImage.setFill(GUI::color_OffWhite);
	arrowImage.setPath(arrowPath);
	goUpButton->setImages(&arrowImage);
	return goUpButton;
}




void MatrixLookAndFeel::drawLabel(Graphics& g, Label& label) {
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
	else {
		if (label.getComponentID() != ID::comp_TextEditorForSlider.toString()) {
			auto isRightJustified{ label.getComponentID() == ID::comp_VoiceNameEditor.toString() ? false : true };
			g.setColour(GUI::color_LED_Blue);
			auto text{ label.getText() };
			auto textPath{ LED_Path::buildLabelText(text, label.getWidth(), isRightJustified) };
			g.fillPath(textPath);
		}
	}
}

void MatrixLookAndFeel::fillTextEditorBackground(Graphics& g, int /*w*/, int /*h*/, TextEditor& textEditor) {
	textEditor.applyFontToAllText(GUI::font_LabelEditors);
	g.fillAll(GUI::color_Black);
}

void MatrixLookAndFeel::drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
}




void MatrixLookAndFeel::drawProgressBar(Graphics& g, ProgressBar& bar, int w, int h, double percentDone, const String& textToShow) {
	auto background{ GUI::color_Black };
	auto foreground{ bar.getComponentID() == ID::comp_ProgressBar_VoicesBank.toString() ? GUI::color_ButtonBlue : GUI::color_ButtonGray };
	auto barBounds{ bar.getLocalBounds().toFloat() };
	g.setColour(background);
	g.fillRect(barBounds);
	if (percentDone >= 0.0f && percentDone <= 1.0f) {
		Path p;
		p.addRectangle(barBounds);
		g.reduceClipRegion(p);
		barBounds.setWidth(barBounds.getWidth() * (float)percentDone);
		g.setColour(foreground);
		g.fillRect(barBounds);
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
			g2.fillRect(barBounds);
		}
		g.setTiledImageFill(im, 0, 0, 0.85f);
		g.fillPath(p);
	}
	if (textToShow.isNotEmpty()) {
		g.setColour(GUI::color_OffWhite);
		g.setFont(GUI::font_ProgressBar);
		g.drawText(textToShow, 0, 0, w, h, Justification::centred, false);
	}
}




int MatrixLookAndFeel::getDefaultScrollbarWidth() {
	return 10;
}

void MatrixLookAndFeel::drawScrollbar(Graphics& g, ScrollBar& /*scrollbar*/, int x, int y, int w, int h,
	bool isVertical, int thumbStartPosition, int thumbSize, bool /*mouseIsOver*/, bool /*mouseIsDown*/)
{
	Rectangle<int> thumbBounds;
	if (isVertical)
		thumbBounds = { x, thumbStartPosition, w, thumbSize };
	else
		thumbBounds = { thumbStartPosition, y, thumbSize, h };
	thumbBounds.reduce(2, 2);
	g.setColour(GUI::color_LED_Blue);
	g.fillRect(thumbBounds.toFloat());
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




void MatrixLookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(),
		button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void MatrixLookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, 
	const bool isTicked, const bool /*isEnabled*/, const bool isHighlighted, const bool /*isDown*/)
{
	auto componentID{ component.getComponentID() };
	if (componentID == ID::btn_RadioButton_VoiceSlot.toString() || componentID == ID::btn_RadioButton_SplitSlot.toString()) {
		auto buttonColor{ GUI::color_Device };
		if (isHighlighted)
			buttonColor = buttonColor.brighter(0.4f);
		if (isTicked)
			buttonColor = buttonColor.brighter(0.7f);
		g.setColour(buttonColor);
		g.fillRect(x, y, w, h);
		g.setColour(GUI::color_OffWhite);
		g.setFont(GUI::font_VoiceAndSplitSlotRadioButtons);
		Rectangle<float> textArea{ x + 3, y + 2, w - 3, h };
		g.drawText(component.getName(), textArea, Justification::topLeft);
	}
	if (componentID.startsWith(ID::comp_ToggleAllow_Choice_.toString())) {
		if (isTicked) {
			g.setColour(GUI::color_OffWhite.withAlpha(0.1f));
			g.fillRect(x, y, w, h);
		}
		g.setColour(GUI::color_OffWhite);
		g.setFont(GUI::font_VoiceAndSplitSlotRadioButtons);
		Rectangle<float> textArea{ x + 3, y, w - 3, h };
		g.drawText(component.getName(), textArea, Justification::centredLeft);
	}
	if (componentID.startsWith("comp_ToggleLock")) {
		PNGImageFormat imageFormat;
		MemoryInputStream memInputStream{ BinaryData::icon_Locked_png, BinaryData::icon_Locked_pngSize, false };
		auto lockedIcon{ imageFormat.decodeImage(memInputStream) };
		g.setColour(isTicked ? GUI::color_Black.withAlpha(0.3f) : GUI::color_ButtonOrange.withAlpha(0.2f));
		if (isTicked) {
			g.setColour(GUI::color_Black.withAlpha(0.3f));
			g.fillRect(x, y, w, h);
			g.setOpacity(1.0f);
			g.drawImageAt(lockedIcon, int(w / 2) - (GUI::lockAndUnlockIcons_w / 2), 0);
		}
		else {
			g.setColour(GUI::color_ButtonOrange.withAlpha(0.2f));
			g.fillRect(x, y, w, h);
		}
	}
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
