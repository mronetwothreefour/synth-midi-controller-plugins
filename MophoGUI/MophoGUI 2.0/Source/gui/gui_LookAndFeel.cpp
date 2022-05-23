#include "gui_LookAndFeel.h"
#pragma once

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_FontsAndSpecialCharacters.h"
#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



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




void MophoLookAndFeel::drawLabel(Graphics& g, Label& label) {
	//auto isInImptExptBrowser{ label.getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() ||
	//	label.getParentComponent()->getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString()
	//};
	//if (isInImptExptBrowser) {
	//	auto textArea{ label.getLocalBounds() };
	//	textArea.removeFromLeft(5);
	//	g.setColour(Color::controlText);
	//	g.setFont(FontsMenu::fontFor_BrowserText);
	//	g.drawFittedText(label.getText(), textArea, Justification::centredLeft, 1, 1.0f);
	//}
	//else {
		g.setFont(GUI::fontFor_Labels);
		g.setColour(GUI::color_White);
		//if (label.getComponentID() != "") {
		//	if (label.getComponentID() == ID::component_EditLabel.toString()) {
		//		g.fillAll(Color::black);
		//		g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
		//	}
		//	if (label.getComponentID() == ID::component_DisplayLabel.toString()) {
		//		g.setFont(FontsMenu::fontFor_DisplayLabels);
		//		g.setColour(label.findColour(label.textColourId));
		//		g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
		//	}
		//	if (label.getComponentID() == ID::component_VoiceNameEditLabel.toString()) {
		//		g.setFont(FontsMenu::fontFor_VoiceNameEditorText);
		//		g.setColour(Colours::transparentBlack);
		//		g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
		//	}
		//}
		//else
			g.drawText(label.getText(), label.getLocalBounds(), Justification::centred, false);
	//}
}




void MophoLookAndFeel::drawToggleButton(Graphics& g, ToggleButton& button, bool isHighlighted, bool isDown) {
	drawTickBox(g, button, 0.0f, 0.0f, (float)button.getWidth(), (float)button.getHeight(), 
		button.getToggleState(), button.isEnabled(), isHighlighted, isDown);
}

void MophoLookAndFeel::drawTickBox(Graphics& g, Component& component, float x, float y, float w, float h, 
	const bool isTicked, const bool /*isEnabled*/, const bool /*isHighlighted*/, const bool /*isDown*/)
{
	auto componentID{ component.getComponentID() };
	if (componentID.startsWith(ID::component_ParamToggle.toString())) {
		g.setColour(isTicked ? GUI::color_ToggleOn : GUI::color_ToggleOff);
		g.fillEllipse(x, y, w, h);
	}
}




void MophoLookAndFeel::drawComboBox(Graphics& /*g*/, int /*width*/, int /*height*/, bool /*isDown*/,
	int /*x*/, int /*y*/, int /*w*/, int /*h*/, ComboBox& /*comboBox*/)
{
}

void MophoLookAndFeel::positionComboBoxText(ComboBox& box, Label& label) {
	auto spaceForArrowIcon{ 11 };
	//auto isInImptExptFileBrowser{ box.getParentComponent()->getComponentID() == ID::component_ImptExptBrowser.toString() };
	//if (isInImptExptFileBrowser)
	//	spaceForArrowIcon = 20;
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
	const bool isHighlighted, 	const bool isTicked, const bool hasSubMenu, const String& text, const String& /*shortcutText*/,
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
		g.setFont(GUI::fontFor_PopupMenuItems);
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
