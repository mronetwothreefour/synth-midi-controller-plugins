#include "gui_LookAndFeel.h"

#include "gui_Colors.h"
#include "gui_Constants.h"
#include "gui_Fonts.h"
#include "gui_Path_LEDsliderTab.h"
#include "gui_Path_VerticalBarLED.h"
#include "../guiRenderers/guiRenderer_PopupMenuItem.h"
#include "../params/params_Identifiers.h"

using namespace constants;



Rectangle<int> GUILookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout tl(layoutTooltipText(tipText, Color::black));
	auto w = (int)(tl.getWidth() + 16.0f);
	auto h = (int)(tl.getHeight() + 14.0f);
	return Rectangle<int>(
		screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
		screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

void GUILookAndFeel::drawLinearSlider(Graphics& g, int /*x*/, int /*y*/, int /*width*/, int /*height*/, float sliderPos, float /*minSliderPos*/, float /*maxSliderPos*/, const Slider::SliderStyle /*style*/, Slider& /*slider*/) {
	auto sliderTab{ LEDsliderTab::createPath() };
	g.setColour(Color::led_blue);
	g.fillPath(sliderTab, AffineTransform::translation(sliderPos - 8.0f, 0.0f));
}

void GUILookAndFeel::drawRotarySlider(Graphics& /*g*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, float /*sliderPos*/, const float /*startAngle*/, const float /*endAngle*/, Slider& /*slider*/) {
}

void GUILookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(Color::device);
	g.fillRect(bounds.toFloat());
	g.setColour(Color::led_blue);
	g.drawRect(bounds.toFloat(), 1.0f);
	g.setColour(Color::offWhiteText);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId))
		.draw(g, { static_cast<float>(width), static_cast<float>(height) });
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
	if (button.getComponentID() == ID::button_Close.toString())
		return isDown ? BinaryData::ButtonCloseDown_png : BinaryData::ButtonCloseUp_png;
	if (button.getComponentID() == ID::button_Edit.toString())
		return isDown ? BinaryData::ButtonEditDown_png : BinaryData::ButtonEditUp_png;
	if (button.getComponentID() == ID::button_Load.toString())
		return isDown ? BinaryData::ButtonLoadDown_png : BinaryData::ButtonLoadUp_png;
	if (button.getComponentID() == ID::button_Master.toString())
		return isDown ? BinaryData::ButtonMasterDown_png : BinaryData::ButtonMasterUp_png;
	if (button.getComponentID() == ID::button_Patches.toString())
		return isDown ? BinaryData::ButtonPatchesDown_png : BinaryData::ButtonPatchesUp_png;
	if (button.getComponentID().startsWith("button_Pull"))
		return isDown ? BinaryData::ButtonPullDown_png : BinaryData::ButtonPullUp_png;
	if (button.getComponentID().startsWith("button_Push"))
		return isDown ? BinaryData::ButtonPushDown_png : BinaryData::ButtonPushUp_png;
	if (button.getComponentID() == ID::button_QuickEdit.toString())
		return isDown ? BinaryData::ButtonQuickEditDown_png : BinaryData::ButtonQuickEditUp_png;
	if (button.getComponentID() == ID::button_QuickEdit_Flash.toString())
		return BinaryData::ButtonQuickEditFlash_png;
	if (button.getComponentID() == ID::button_Redo.toString())
		return isDown ? BinaryData::ButtonRedoDown_png : BinaryData::ButtonRedoUp_png;
	if (button.getComponentID() == ID::button_Reset.toString())
		return isDown ? BinaryData::ButtonResetDown_png : BinaryData::ButtonResetUp_png;
	if (button.getComponentID() == ID::button_Retry.toString())
		return isDown ? BinaryData::ButtonRetryDown_png : BinaryData::ButtonRetryUp_png;
	if (button.getComponentID() == ID::button_Save.toString())
		return isDown ? BinaryData::ButtonSaveDown_png : BinaryData::ButtonSaveUp_png;
	if (button.getComponentID() == ID::button_Splits.toString())
		return isDown ? BinaryData::ButtonSplitsDown_png : BinaryData::ButtonSplitsUp_png;
	if (button.getComponentID() == ID::button_Stop.toString())
		return isDown ? BinaryData::ButtonStopDown_png : BinaryData::ButtonStopUp_png;
	if (button.getComponentID() == ID::button_Undo.toString())
		return isDown ? BinaryData::ButtonUndoDown_png : BinaryData::ButtonUndoUp_png;
	if (button.getComponentID() == ID::button_X_Master.toString() || button.getComponentID() == ID::button_X_PatchMap.toString())
		return isDown ? BinaryData::ButtonXOrangeDown_png : BinaryData::ButtonXOrangeUp_png;
	if (button.getComponentID() == ID::button_X_Patches.toString())
		return isDown ? BinaryData::ButtonXDown_png : BinaryData::ButtonXUp_png;
	if (button.getComponentID() == ID::button_X_Splits.toString())
		return isDown ? BinaryData::ButtonXGrayDown_png : BinaryData::ButtonXGrayUp_png;
	return nullptr;
}

size_t GUILookAndFeel::getButtonImageDataSize(Button& button, bool isDown) {
	if (button.getComponentID() == ID::button_Close.toString())
		return isDown ? BinaryData::ButtonCloseDown_pngSize : BinaryData::ButtonCloseUp_pngSize;
	if (button.getComponentID() == ID::button_Edit.toString())
		return isDown ? BinaryData::ButtonEditDown_pngSize : BinaryData::ButtonEditUp_pngSize;
	if (button.getComponentID() == ID::button_Load.toString())
		return isDown ? BinaryData::ButtonLoadDown_pngSize : BinaryData::ButtonLoadUp_pngSize;
	if (button.getComponentID() == ID::button_Master.toString())
		return isDown ? BinaryData::ButtonMasterDown_pngSize : BinaryData::ButtonMasterUp_pngSize;
	if (button.getComponentID() == ID::button_Patches.toString())
		return isDown ? BinaryData::ButtonPatchesDown_pngSize : BinaryData::ButtonPatchesUp_pngSize;
	if (button.getComponentID().startsWith("button_Pull"))
		return isDown ? BinaryData::ButtonPullDown_pngSize : BinaryData::ButtonPullUp_pngSize;
	if (button.getComponentID().startsWith("button_Push"))
		return isDown ? BinaryData::ButtonPushDown_pngSize : BinaryData::ButtonPushUp_pngSize;
	if (button.getComponentID() == ID::button_QuickEdit.toString())
		return isDown ? BinaryData::ButtonQuickEditDown_pngSize : BinaryData::ButtonQuickEditUp_pngSize;
	if (button.getComponentID() == ID::button_QuickEdit_Flash.toString())
		return BinaryData::ButtonQuickEditFlash_pngSize;
	if (button.getComponentID() == ID::button_Redo.toString())
		return isDown ? BinaryData::ButtonRedoDown_pngSize : BinaryData::ButtonRedoUp_pngSize;
	if (button.getComponentID() == ID::button_Reset.toString())
		return isDown ? BinaryData::ButtonResetDown_pngSize : BinaryData::ButtonResetUp_pngSize;
	if (button.getComponentID() == ID::button_Retry.toString())
		return isDown ? BinaryData::ButtonRetryDown_pngSize : BinaryData::ButtonRetryUp_pngSize;
	if (button.getComponentID() == ID::button_Save.toString())
		return isDown ? BinaryData::ButtonSaveDown_pngSize : BinaryData::ButtonSaveUp_pngSize;
	if (button.getComponentID() == ID::button_Splits.toString())
		return isDown ? BinaryData::ButtonSplitsDown_pngSize : BinaryData::ButtonSplitsUp_pngSize;
	if (button.getComponentID() == ID::button_Stop.toString())
		return isDown ? BinaryData::ButtonStopDown_pngSize : BinaryData::ButtonStopUp_pngSize;
	if (button.getComponentID() == ID::button_Undo.toString())
		return isDown ? BinaryData::ButtonUndoDown_pngSize : BinaryData::ButtonUndoUp_pngSize;
	if (button.getComponentID() == ID::button_X_Master.toString() || button.getComponentID() == ID::button_X_PatchMap.toString())
		return isDown ? BinaryData::ButtonXOrangeDown_pngSize : BinaryData::ButtonXOrangeUp_pngSize;
	if (button.getComponentID() == ID::button_X_Patches.toString())
		return isDown ? BinaryData::ButtonXDown_pngSize : BinaryData::ButtonXUp_pngSize;
	if (button.getComponentID() == ID::button_X_Splits.toString())
		return isDown ? BinaryData::ButtonXGrayDown_pngSize : BinaryData::ButtonXGrayUp_pngSize;
	return size_t();
}

void GUILookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
}

void GUILookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(), button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void GUILookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, const bool isTicked, const bool /*isEnabled*/, const bool isHighlighted, const bool /*isDown*/) {
	if (component.getComponentID() == ID::button_PatchSlotRadioButton.toString() || component.getComponentID() == ID::button_SplitSlotRadioButton.toString()) {
		auto buttonColor{ Color::device };
		if (isHighlighted)
			buttonColor = buttonColor.brighter(0.4f);
		if (isTicked)
			buttonColor = buttonColor.brighter(0.7f);
		g.setColour(buttonColor);
		g.fillRect(x, y, w, h);
		g.setColour(Color::offWhiteText);
		g.setFont(FontsMenu::fontFor_PatchAndSplitSlotRadioButtons);
		Rectangle<float> textArea{ x + 3, y + 2, w - 3, h };
		g.drawText(component.getName(), textArea, Justification::topLeft);
	}
}

void GUILookAndFeel::drawComboBox(Graphics& /*g*/, int /*width*/, int /*height*/, bool /*isDown*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/) {
}

PopupMenu::Options GUILookAndFeel::getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) {
	return PopupMenu::Options()
		.withTargetComponent(&box)
		.withItemThatMustBeVisible(box.getSelectedId())
		.withMinimumWidth(box.getWidth())
		.withMaximumNumColumns(1)
		.withStandardItemHeight(label.getHeight() + 2);
}

void GUILookAndFeel::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(Color::black.brighter(0.06f));
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

void GUILookAndFeel::getIdealPopupMenuItemSize(const String& /*text*/, const bool /*isSeparator*/, int itemHeight, int& /*idealWidth*/, int& idealHeight) {
	auto font = getPopupMenuFont();
	if (itemHeight > 0 && font.getHeight() > itemHeight / 1.3f)
		font.setHeight(itemHeight / 1.3f);
	idealHeight = itemHeight > 0 ? itemHeight : roundToInt(font.getHeight() * 1.3f);
}

