#include "gui_LookAndFeel.h"

#include "gui_Colors.h"
#include "gui_Constants.h"
#include "gui_Fonts.h"
#include "../params/params_Identifiers.h"

using namespace constants;



void GUILookAndFeel::drawRotarySlider(Graphics& g, int /*x*/, int y,  int w, int /*h*/, float sliderPos, const float startAngle, const float endAngle, Slider& /*slider*/) {
	Point<float> sliderCenter{ float(w) / 2.0f, float(w) / 2.0f };
	auto pointerAngle = startAngle + sliderPos * (endAngle - startAngle);
	Line<float> line;
	line.setStart(sliderCenter.x, float(y + 7));
	line.setEnd(sliderCenter.x, float(y + 1));
	Path pointerPath;
	pointerPath.addArrow(line, 1.0f, 8.0f, 6.0f);
	pointerPath.applyTransform(AffineTransform::rotation(pointerAngle, sliderCenter.x, sliderCenter.y));
	g.setColour(Color::black);
	g.fillPath(pointerPath);
}

void GUILookAndFeel::drawLabel(Graphics& g, Label& label) {
	auto isInImptExptBrowser{ label.getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() ||
		label.getParentComponent()->getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString()
	};
	if (isInImptExptBrowser) {
		auto textArea{ label.getLocalBounds() };
		textArea.removeFromLeft(5);
		g.setColour(Color::controlText);
		g.setFont(FontsMenu::fontFor_BrowserText);
		g.drawFittedText(label.getText(), textArea, Justification::centredLeft, 1, 1.0f);
	}
	else {
		g.setFont(FontsMenu::fontFor_Labels);
		g.setColour(Color::controlText);
		if (label.getComponentID() != "") {
			if (label.getComponentID() == ID::component_EditLabel.toString()) {
				g.fillAll(Color::black);
				g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
			}
			if (label.getComponentID() == ID::component_DisplayLabel.toString()) {
				g.setFont(FontsMenu::fontFor_DisplayLabels);
				g.setColour(label.findColour(label.textColourId));
				g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
			}
			if (label.getComponentID() == ID::component_VoiceNameEditLabel.toString()) {
				g.setFont(FontsMenu::fontFor_VoiceNameEditorText);
				g.setColour(Colours::transparentBlack);
				g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
			}
		}
		else
			g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
	}
}

void GUILookAndFeel::fillTextEditorBackground(Graphics& g, int /*width*/, int /*height*/, TextEditor& textEditor) {
	auto editorIsInImptExptComponent{ textEditor.getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() };
	auto editorIsInPathComboBoxInImptExptComponent{ textEditor.getParentComponent()->getParentComponent()->getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() };
	if (editorIsInImptExptComponent || editorIsInPathComboBoxInImptExptComponent)
		textEditor.applyFontToAllText(FontsMenu::fontFor_BrowserText);
	g.fillAll(Color::black);
}

void GUILookAndFeel::drawTextEditorOutline(Graphics& /*g*/, int /*w*/, int /*h*/, TextEditor& /*textEditor*/) {
}

Rectangle<int> GUILookAndFeel::getTooltipBounds(const String& tipText, Point<int> screenPos, Rectangle<int> parentArea) {
	const TextLayout tl(layoutTooltipText(tipText, Color::black));
	auto w = (int)(tl.getWidth() + 16.0f);
	auto h = (int)(tl.getHeight() + 14.0f);
	return Rectangle<int>(
			screenPos.x > parentArea.getCentreX() ? screenPos.x - (w + 12) : screenPos.x + 24,
			screenPos.y > parentArea.getCentreY() ? screenPos.y - (h + 6) : screenPos.y + 6, w, h).constrainedWithin(parentArea);
}

void GUILookAndFeel::drawTooltip(Graphics& g, const String& text, int width, int height) {
	Rectangle<int> bounds(width, height);
	g.setColour(Color::black.brighter(0.1f));
	g.fillRect(bounds.toFloat());
	g.setColour(Color::controlText);
	g.drawRect(bounds.toFloat(), 2.0f);
	layoutTooltipText(text, findColour(TooltipWindow::textColourId))
		.draw(g, { static_cast<float>(width), static_cast<float>(height) });
}

TextLayout GUILookAndFeel::layoutTooltipText(const String& text, Colour colour) noexcept {
	AttributedString s;
	s.setJustification(Justification::centred);
	s.append(text, FontsMenu::fontFor_Tooltips, colour);
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
	if (button.getComponentID().startsWith("button_AllItems"))
		return isDown ? BinaryData::ButtonDownAllowAll_png : BinaryData::ButtonUpAllowAll_png;

	if (button.getComponentID().startsWith("button_AllNotes"))
		return isDown ? BinaryData::ButtonDownAllNotes_png : BinaryData::ButtonUpAllNotes_png;

	if (button.getComponentID().startsWith("button_AllOctaves"))
		return isDown ? BinaryData::ButtonDownAllOctaves_png : BinaryData::ButtonUpAllOctaves_png;

	if (button.getComponentID().startsWith("button_AllShapes"))
		return isDown ? BinaryData::ButtonDownAllShapes_png : BinaryData::ButtonUpAllShapes_png;

	if (button.getComponentID().startsWith("button_AllSynced"))
		return isDown ? BinaryData::ButtonDownAllSynced_png : BinaryData::ButtonUpAllSynced_png;

	if (button.getComponentID() == ID::button_Banks.toString())
		return isDown ? BinaryData::ButtonDownBanks_png : BinaryData::ButtonUpBanks_png;

	if (button.getComponentID().startsWith("button_Cancel"))
		return isDown ? BinaryData::ButtonDownCancel_png : BinaryData::ButtonUpCancel_png;

	if (button.getComponentID() == ID::button_Clear.toString())
		return isDown ? BinaryData::ButtonDownClear_png : BinaryData::ButtonUpClear_png;

	if (button.getComponentID().startsWith("button_Close"))
		return isDown ? BinaryData::ButtonDownClose_png : BinaryData::ButtonUpClose_png;

	if (button.getComponentID() == ID::button_Create.toString())
		return isDown ? BinaryData::ButtonDownCreate_png : BinaryData::ButtonUpCreate_png;

	if (button.getComponentID().startsWith("button_Export"))
		return isDown ? BinaryData::ButtonDownExport_png : BinaryData::ButtonUpExport_png;

	if (button.getComponentID() == ID::button_FileOverwrite.toString())
		return isDown ? BinaryData::ButtonDownFileOverwrite_png : BinaryData::ButtonUpFileOverwrite_png;

	if (button.getComponentID() == ID::button_Global.toString())
		return isDown ? BinaryData::ButtonDownGlobal_png : BinaryData::ButtonUpGlobal_png;

	if (button.getComponentID().startsWith("button_Import"))
		return isDown ? BinaryData::ButtonDownImport_png : BinaryData::ButtonUpImport_png;

	if (button.getComponentID() == ID::button_Load.toString())
		return isDown ? BinaryData::ButtonDownLoad_png : BinaryData::ButtonUpLoad_png;

	if (button.getComponentID() == ID::button_Lock.toString())
		return isDown ? BinaryData::ButtonDownLock_png : BinaryData::ButtonUpLock_png;

	if (button.getComponentID() == ID::button_NewFolder.toString())
		return isDown ? BinaryData::ButtonDownNewFolder_png : BinaryData::ButtonUpNewFolder_png;

	if (button.getComponentID() == ID::button_Random.toString())
		return isDown ? BinaryData::ButtonDownRandom_png : BinaryData::ButtonUpRandom_png;

	if (button.getComponentID() == ID::button_Randomize.toString())
		return isDown ? BinaryData::ButtonDownRandomize_png : BinaryData::ButtonUpRandomize_png;

	if (button.getComponentID() == ID::button_Unlock.toString())
		return isDown ? BinaryData::ButtonDownUnlock_png : BinaryData::ButtonUpUnlock_png;

	if (button.getComponentID() == ID::button_VoiceNameEdit.toString())
		return isDown ? BinaryData::ButtonDownProgramNameEdit_png : BinaryData::ButtonUpProgramNameEdit_png;

	if (button.getComponentID().startsWith(ID::button_PullCustomBank1.toString().dropLastCharacters(1)) ||
		button.getComponentID() == ID::button_PullSelectedVoice.toString())
		return isDown ? BinaryData::ButtonDownPull_png : BinaryData::ButtonUpPull_png;

	if (button.getComponentID().startsWith(ID::button_PushCustomBank1.toString().dropLastCharacters(1)) ||
		button.getComponentID().startsWith(ID::button_PushFactoryBank1.toString().dropLastCharacters(1)) ||
		button.getComponentID() == ID::button_PushSelectedVoice.toString())
		return isDown ? BinaryData::ButtonDownPush_png : BinaryData::ButtonUpPush_png;

	if (button.getComponentID() == ID::button_Read.toString()) 
		return isDown ? BinaryData::ButtonDownRead_png : BinaryData::ButtonUpRead_png;

	if (button.getComponentID() == ID::button_Redo.toString()) 
		return isDown ? BinaryData::ButtonDownRedo_png : BinaryData::ButtonUpRedo_png;

	if (button.getComponentID() == ID::button_Retry.toString()) 
		return isDown ? BinaryData::ButtonDownRetry_png : BinaryData::ButtonUpRetry_png;

	if (button.getComponentID() == ID::button_Save.toString())
		return isDown ? BinaryData::ButtonDownSave_png : BinaryData::ButtonUpSave_png;

	if (button.getComponentID() == ID::button_Stop.toString())
		return isDown ? BinaryData::ButtonDownStop_png : BinaryData::ButtonUpStop_png;

	if (button.getComponentID() == ID::button_Undo.toString()) 
		return isDown ? BinaryData::ButtonDownUndo_png : BinaryData::ButtonUpUndo_png;

	if (button.getComponentID() == ID::button_Write.toString()) 
		return isDown ? BinaryData::ButtonDownWrite_png : BinaryData::ButtonUpWrite_png;

	return nullptr;
}

size_t GUILookAndFeel::getButtonImageDataSize(Button& button, bool isDown) {
	if (button.getComponentID().startsWith("button_AllItems"))
		return size_t(isDown ? BinaryData::ButtonDownAllowAll_pngSize : BinaryData::ButtonUpAllowAll_pngSize);

	if (button.getComponentID().startsWith("button_AllNotes"))
		return size_t(isDown ? BinaryData::ButtonDownAllNotes_pngSize : BinaryData::ButtonUpAllNotes_pngSize);

	if (button.getComponentID().startsWith("button_AllOctaves"))
		return size_t(isDown ? BinaryData::ButtonDownAllOctaves_pngSize : BinaryData::ButtonUpAllOctaves_pngSize);

	if (button.getComponentID().startsWith("button_AllShapes"))
		return size_t(isDown ? BinaryData::ButtonDownAllShapes_pngSize : BinaryData::ButtonUpAllShapes_pngSize);

	if (button.getComponentID().startsWith("button_AllSynced"))
		return size_t(isDown ? BinaryData::ButtonDownAllSynced_pngSize : BinaryData::ButtonUpAllSynced_pngSize);

	if (button.getComponentID() == ID::button_Banks.toString())
		return size_t(isDown ? BinaryData::ButtonDownBanks_pngSize : BinaryData::ButtonUpBanks_pngSize);

	if (button.getComponentID().startsWith("button_Cancel"))
		return size_t(isDown ? BinaryData::ButtonDownCancel_pngSize : BinaryData::ButtonUpCancel_pngSize);

	if (button.getComponentID() == ID::button_Clear.toString())
		return size_t(isDown ? BinaryData::ButtonDownClear_pngSize : BinaryData::ButtonUpClear_pngSize);

	if (button.getComponentID().startsWith("button_Close"))
		return size_t(isDown ? BinaryData::ButtonDownClose_pngSize : BinaryData::ButtonUpClose_pngSize);

	if (button.getComponentID() == ID::button_Create.toString())
		return size_t(isDown ? BinaryData::ButtonDownCreate_pngSize : BinaryData::ButtonUpCreate_pngSize);

	if (button.getComponentID().startsWith("button_Export"))
		return size_t(isDown ? BinaryData::ButtonDownExport_pngSize : BinaryData::ButtonUpExport_pngSize);

	if (button.getComponentID() == ID::button_FileOverwrite.toString())
		return size_t(isDown ? BinaryData::ButtonDownFileOverwrite_pngSize : BinaryData::ButtonUpFileOverwrite_pngSize);

	if (button.getComponentID() == ID::button_Global.toString())
		return size_t(isDown ? BinaryData::ButtonDownGlobal_pngSize : BinaryData::ButtonUpGlobal_pngSize);

	if (button.getComponentID().startsWith("button_Import"))
		return size_t(isDown ? BinaryData::ButtonDownImport_pngSize : BinaryData::ButtonUpImport_pngSize);

	if (button.getComponentID() == ID::button_Load.toString())
		return size_t(isDown ? BinaryData::ButtonDownLoad_pngSize : BinaryData::ButtonUpLoad_pngSize);

	if (button.getComponentID() == ID::button_Lock.toString())
		return size_t(isDown ? BinaryData::ButtonDownLock_pngSize : BinaryData::ButtonUpLock_pngSize);

	if (button.getComponentID() == ID::button_NewFolder.toString())
		return size_t(isDown ? BinaryData::ButtonDownNewFolder_pngSize : BinaryData::ButtonUpNewFolder_pngSize);

	if (button.getComponentID() == ID::button_Random.toString())
		return size_t(isDown ? BinaryData::ButtonDownRandom_pngSize : BinaryData::ButtonUpRandom_pngSize);

	if (button.getComponentID() == ID::button_Randomize.toString())
		return size_t(isDown ? BinaryData::ButtonDownRandomize_pngSize : BinaryData::ButtonUpRandomize_pngSize);

	if (button.getComponentID() == ID::button_Unlock.toString())
		return size_t(isDown ? BinaryData::ButtonDownUnlock_pngSize : BinaryData::ButtonUpUnlock_pngSize);

	if (button.getComponentID() == ID::button_VoiceNameEdit.toString())
		return size_t(isDown ? BinaryData::ButtonDownProgramNameEdit_pngSize : BinaryData::ButtonUpProgramNameEdit_pngSize);

	if (button.getComponentID().startsWith(ID::button_PullCustomBank1.toString().dropLastCharacters(1)) ||
		button.getComponentID() == ID::button_PullSelectedVoice.toString())
		return size_t(isDown ? BinaryData::ButtonDownPull_pngSize : BinaryData::ButtonUpPull_pngSize);

	if (button.getComponentID().startsWith(ID::button_PushCustomBank1.toString().dropLastCharacters(1)) ||
		button.getComponentID().startsWith(ID::button_PushFactoryBank1.toString().dropLastCharacters(1)) ||
		button.getComponentID() == ID::button_PushSelectedVoice.toString())
		return size_t(isDown ? BinaryData::ButtonDownPush_pngSize : BinaryData::ButtonUpPush_pngSize);

	if (button.getComponentID() == ID::button_Read.toString())
		return size_t(isDown ? BinaryData::ButtonDownRead_pngSize : BinaryData::ButtonUpRead_pngSize);

	if (button.getComponentID() == ID::button_Redo.toString())
		return size_t(isDown ? BinaryData::ButtonDownRedo_pngSize : BinaryData::ButtonUpRedo_pngSize);

	if (button.getComponentID() == ID::button_Retry.toString())
		return size_t(isDown ? BinaryData::ButtonDownRetry_pngSize : BinaryData::ButtonUpRetry_pngSize);

	if (button.getComponentID() == ID::button_Save.toString())
		return size_t(isDown ? BinaryData::ButtonDownSave_pngSize : BinaryData::ButtonUpSave_pngSize);

	if (button.getComponentID() == ID::button_Stop.toString())
		return size_t(isDown ? BinaryData::ButtonDownStop_pngSize : BinaryData::ButtonUpStop_pngSize);

	if (button.getComponentID() == ID::button_Undo.toString())
		return size_t(isDown ? BinaryData::ButtonDownUndo_pngSize : BinaryData::ButtonUpUndo_pngSize);

	if (button.getComponentID() == ID::button_Write.toString())
		return size_t(isDown ? BinaryData::ButtonDownWrite_pngSize : BinaryData::ButtonUpWrite_pngSize);

	return (size_t)0;
}

void GUILookAndFeel::drawButtonText(Graphics& /*g*/, TextButton& /*button*/, bool /*isHighlighted*/, bool /*isDown*/) {
}

void GUILookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(), button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void GUILookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, const bool isTicked, const bool /*isEnabled*/, const bool isHighlighted, const bool /*isDown*/) {
	auto componentID{ component.getComponentID() };
	if (componentID.startsWith(ID::component_ToggleButton.toString())) {
		g.setColour(isTicked ? Color::switchOn : Color::switchOff);
		g.fillEllipse(x, y, w, h);
	}
	if (componentID == ID::component_VoiceSlotRadioButton.toString()) {
		auto buttonColor{ Color::device };
		if (isHighlighted)
			buttonColor = buttonColor.brighter(0.4f);
		if (isTicked)
			buttonColor = buttonColor.brighter(0.7f);
		g.setColour(buttonColor);
		g.fillRect(x, y, w, h);
		g.setColour(Color::black);
		g.setFont(FontsMenu::fontFor_VoiceSlotButtons);
		Rectangle<float> textArea{ x + 3, y, w - 3, h };
		g.drawText(component.getName(), textArea, Justification::centredLeft);
	}
	if (componentID.startsWith(ID::component_AllowComboBoxItem_ToggleButton_.toString())) {
		if (isTicked) {
			g.setColour(Color::white.withAlpha(0.2f));
			g.fillRect(x, y, w, h);
		}
		g.setColour(Color::black);
		g.setFont(FontsMenu::fontFor_Labels);
		Rectangle<float> textArea{ x + 3, y, w - 3, h };
		g.drawText(component.getHelpText(), textArea, Justification::centredLeft);
	}
	if (componentID.startsWith("lockButtonForComboBox_")) {
		if (isTicked) {
			g.setColour(Color::black.withAlpha(0.3f));
			g.fillRect(x, y + 2, w, h - 4);
			g.setOpacity(1.0f);
			PNGImageFormat imageFormat;
			MemoryInputStream memInputStream{ BinaryData::LockIcon_png, BinaryData::LockIcon_pngSize, false };
			auto buttonImage{ imageFormat.decodeImage(memInputStream) };
			g.drawImageAt(buttonImage, int(w / 2) - (GUI::randomizationLockAndUnlockButtons_w / 2), 0);
		}
		else {
			g.setColour(Color::switchOn.withAlpha(.2f));
			g.fillRect(x, y + 2, w, h - 4);
		}
	}
	if (componentID.startsWith("lockButtonForKnob_")) {
		if (isTicked) {
			g.setColour(Color::black.withAlpha(0.3f));
			g.fillEllipse(x, y, w, h);
			g.setOpacity(1.0f);
			PNGImageFormat imageFormat;
			MemoryInputStream memInputStream{ BinaryData::LockIcon_png, BinaryData::LockIcon_pngSize, false };
			auto buttonImage{ imageFormat.decodeImage(memInputStream) };
			g.drawImageAt(buttonImage, GUI::lockIconForKnobs_x, GUI::lockIconForKnobs_y);
		}
		else {
			g.setColour(Color::switchOn.withAlpha(.2f));
			g.fillEllipse(x, y, w, h);
		}
	}
	if (componentID.startsWith("lockButtonForSeqStep_")) {
		if (isTicked) {
			g.setColour(Color::black.withAlpha(0.3f));
			g.fillRect(x, y, w, h);
			g.setOpacity(1.0f);
			PNGImageFormat imageFormat;
			MemoryInputStream memInputStream{ BinaryData::LockIcon_png, BinaryData::LockIcon_pngSize, false };
			auto buttonImage{ imageFormat.decodeImage(memInputStream) };
			g.drawImageAt(buttonImage, GUI::lockIconForSeqSteps_x, GUI::lockIconForSeqSteps_y);
		}
		else {
			g.setColour(Color::switchOn.withAlpha(.2f));
			g.fillRect(x, y, w, h);
		}
	}
	if (component.getComponentID().startsWith("lockButtonForToggle_")) {
		if (isTicked) {
			g.setColour(Color::black.withAlpha(0.3f));
			g.fillEllipse(x, y, w, h);
			g.setOpacity(1.0f);
			PNGImageFormat imageFormat;
			MemoryInputStream memInputStream{ BinaryData::LockIcon_png, BinaryData::LockIcon_pngSize, false };
			auto buttonImage{ imageFormat.decodeImage(memInputStream) };
			g.drawImageAt(buttonImage, GUI::lockIconForToggle_x, GUI::lockIconForToggle_y);
		}
		else {
			g.setColour(Color::switchOn.withAlpha(.2f));
			g.fillEllipse(x, y, w, h);
		}
	}
	if (component.getComponentID().startsWith("lockButtonForVoiceNameChar_")) {
		if (isTicked) {
			g.setColour(Color::black.withAlpha(0.3f));
			g.fillRect(x, y, w, h);
			g.setOpacity(1.0f);
			PNGImageFormat imageFormat;
			MemoryInputStream memInputStream{ BinaryData::LockIcon_png, BinaryData::LockIcon_pngSize, false };
			auto buttonImage{ imageFormat.decodeImage(memInputStream) };
			g.drawImageAt(buttonImage, (int)x - 1, (int)y - 1);
		}
		else {
			g.setColour(Color::switchOn.withAlpha(.2f));
			g.fillRect(x, y, w, h);
		}
	}
}

void GUILookAndFeel::layoutFileBrowserComponent(FileBrowserComponent& /*browser*/, DirectoryContentsDisplayComponent* dirContentsBox, FilePreviewComponent* /*previewComponent*/, ComboBox* currentPathBox, TextEditor* fileNameBox, Button* goUpButton) {
	currentPathBox->setBounds(GUI::bounds_ImptExptCurrentPathBox);
	currentPathBox->setJustificationType(Justification::centredLeft);
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
		g.fillAll(Color::black.brighter(0.3f));
	g.setColour(Color::black);
	Path iconPath;
	if (isDirectory)
		iconPath.loadPathFromData(GUI::pathDataForFolderIcon.data(), GUI::pathDataForFolderIcon.size());
	else
		iconPath.loadPathFromData(GUI::pathDataForFileIcon.data(), GUI::pathDataForFileIcon.size());
	g.setColour(Color::controlText);
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
	arrowImage.setFill(Color::black);
	arrowImage.setPath(arrowPath);
	goUpButton->setImages(&arrowImage);
	return goUpButton;
}

void GUILookAndFeel::drawComboBox(Graphics& /*g*/, int /*width*/, int /*height*/, bool /*isDown*/, int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/) {
}

void GUILookAndFeel::positionComboBoxText(ComboBox& box, Label& label) {
	auto spaceForArrowIcon{ 11 };
	auto isInImptExptFileBrowser{ box.getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() };
	if (isInImptExptFileBrowser)
		spaceForArrowIcon = 20;
	label.setBounds(0, 0, box.getWidth() - spaceForArrowIcon, box.getHeight());
}

PopupMenu::Options GUILookAndFeel::getOptionsForComboBoxPopupMenu(ComboBox& box, Label& label) {
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

void GUILookAndFeel::drawPopupMenuBackground(Graphics& g, int /*w*/, int /*h*/) {
	g.fillAll(Color::black.brighter(0.2f));
}

void GUILookAndFeel::drawPopupMenuItem(Graphics& g, const Rectangle<int>& area, const bool isSeparator, const bool isActive, const bool isHighlighted, 
	const bool isTicked, const bool hasSubMenu, const String& text, const String& /*shortcutText*/, const Drawable* /*icon*/, const Colour* const /*textColor*/)
{
	if (isSeparator) {
		auto separatorArea = area.reduced(5, 0);
		separatorArea.removeFromTop(roundToInt(((float)separatorArea.getHeight() * 0.5f) - 0.5f));
		g.setColour(Color::white);
		g.fillRect(separatorArea.removeFromTop(1));
	}
	else {
		auto reducedArea = area.reduced(1);
		if (isHighlighted && isActive) {
			g.setColour(findColour(PopupMenu::highlightedBackgroundColourId));
			g.fillRect(reducedArea);
		}
		reducedArea.reduce(5, 0);
		g.setFont(FontsMenu::fontFor_PopupMenuItems);
		auto iconArea = reducedArea.removeFromLeft(5).toFloat();
		if (isTicked) {
			g.setColour(Color::bullseye);
			g.fillEllipse(4.0f, 6.0f, 4.0f, 4.0f);
		}
		else
			g.setColour(Color::controlText);
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

void GUILookAndFeel::getIdealPopupMenuItemSize(const String& /*text*/, const bool /*isSeparator*/, int itemHeight, int& /*idealWidth*/, int& idealHeight) {
	auto font = getPopupMenuFont();
	if (itemHeight > 0 && font.getHeight() > itemHeight / 1.3f)
		font.setHeight(itemHeight / 1.3f);
	idealHeight = itemHeight > 0 ? itemHeight : roundToInt(font.getHeight() * 1.3f);
}

void GUILookAndFeel::drawTabButton(TabBarButton& button, Graphics& g, bool /*isMouseOver*/, bool /*isMouseDown*/) {
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
	PNGImageFormat imageFormat;
	Image buttonImage;
	if (button.getParentComponent()->getParentComponent()->getComponentID() == ID::component_TabbedComponentForAllBanks.toString())
	{
		if (button.getIndex() == 0) {
			MemoryInputStream memInputStream{ BinaryData::LabelFactoryBanks_png, BinaryData::LabelFactoryBanks_pngSize, false };
			buttonImage = imageFormat.decodeImage(memInputStream);
		}
		if (button.getIndex() == 1) {
			MemoryInputStream memInputStream{ BinaryData::LabelCustomBanks_png, BinaryData::LabelCustomBanks_pngSize, false };
			buttonImage = imageFormat.decodeImage(memInputStream);
		}
	}
	else {
		if (button.getIndex() == 0) {
			MemoryInputStream memInputStream{ BinaryData::LabelBank1_png, BinaryData::LabelBank1_pngSize, false };
			buttonImage = imageFormat.decodeImage(memInputStream);
		}
		if (button.getIndex() == 1) {
			MemoryInputStream memInputStream{ BinaryData::LabelBank2_png, BinaryData::LabelBank2_pngSize, false };
			buttonImage = imageFormat.decodeImage(memInputStream);
		}
		if (button.getIndex() == 2) {
			MemoryInputStream memInputStream{ BinaryData::LabelBank3_png, BinaryData::LabelBank3_pngSize, false };
			buttonImage = imageFormat.decodeImage(memInputStream);
		}
	}
	auto image_x{ (activeArea.getWidth() - buttonImage.getWidth()) / 2 };
	auto image_y{ (activeArea.getHeight() - buttonImage.getHeight()) / 2 };
	g.drawImageAt(buttonImage, image_x, image_y);
}

void GUILookAndFeel::drawProgressBar(Graphics& g, ProgressBar& bar, int w, int h, double percentDone, const String& textToShow) {
	auto background = bar.findColour(ProgressBar::backgroundColourId);
	auto foreground = bar.findColour(ProgressBar::foregroundColourId);
	auto barBounds = bar.getLocalBounds().toFloat();
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
		g.setColour(Color::controlText);
		g.setFont(FontsMenu::fontFor_ProgressBar);
		g.drawText(textToShow, 0, 0, w, h, Justification::centred, false);
	}
}

