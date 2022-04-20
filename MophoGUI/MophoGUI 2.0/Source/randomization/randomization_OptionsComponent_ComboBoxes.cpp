#include "randomization_OptionsComponent_ComboBoxes.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;



RandomizationOptionsComponent_ComboBoxes::RandomizationOptionsComponent_ComboBoxes(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams },
	numberOfItems{ InfoForExposedParameters::get().numberOfStepsFor(paramIndex) },
	componentInset{ 17 },
	gapBetweenButtonAndItemList{ 10 },
	background_x{ 10 },
	background_y{ 10 },
	background_w{ 10 },
	background_h{ 10 }
{
	auto& info{ InfoForExposedParameters::get() };
	jassert(info.randomizationOptionsTypeFor(paramIndex) == RandomizationOptionsType::comboBoxes);
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	item_w = info.controlWidthFor(paramIndex) - 15;
	auto converter{ info.converterFor(paramIndex) };
	for (auto itemNum = 0; itemNum != numberOfItems; ++itemNum) {
		auto toggleID{ ID::component_AllowComboBoxItem_ToggleButton_.toString() + (String)itemNum + "_For_" + paramID };
		allowedItemToggles[itemNum].setComponentID(toggleID);
		auto itemIsAllowed{ randomizationOptions->comboBoxItemIsAllowedForParam(itemNum, paramIndex) };
		allowedItemToggles[itemNum].setToggleState(itemIsAllowed, dontSendNotification);
		allowedItemToggles[itemNum].addListener(this);
		allowedItemToggles[itemNum].setHelpText(converter->convert((uint8)itemNum));
		addAndMakeVisible(allowedItemToggles[itemNum]);
		allowedItemToggles[itemNum].setSize(item_w, GUI::comboBox_h);
		if (shouldShowDescriptions) {
			String buttonTooltip{ "" };
			buttonTooltip += "Click an option name to toggle whether or not it\n";
			buttonTooltip += "is allowed when generating a random setting for\n";
			buttonTooltip += paramName + ".\n";
			buttonTooltip += "Holding down the CTRL key when clicking will\n";
			buttonTooltip += "make it the only option allowed (there must\n";
			buttonTooltip += "always be at least one allowed option).\n";
			allowedItemToggles[itemNum].setTooltip(buttonTooltip);
		}
	}

	button_ForAllowingAllItems.setComponentID(ID::button_AllItemsFor_.toString() + paramID);
	button_ForAllowingAllItems.addListener(this);
	if (shouldShowDescriptions) {
		String buttonTooltip{ "" };
		buttonTooltip += "Click to allow all the options when\n";
		buttonTooltip += "generating a random setting for\n";
		buttonTooltip += paramName + ".";
		button_ForAllowingAllItems.setTooltip(buttonTooltip);
	}
	addAndMakeVisible(button_ForAllowingAllItems);

	button_ForClosingComponent.setComponentID(ID::button_Close.toString());
	button_ForClosingComponent.addShortcut(KeyPress(KeyPress::escapeKey));
	button_ForClosingComponent.onClick = [this] { hideThisComponent(); };
	if (shouldShowDescriptions)
		button_ForClosingComponent.setTooltip("Click to close this window.");
	addAndMakeVisible(button_ForClosingComponent);

	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	auto control_w{ info.controlWidthFor(paramIndex) };
	auto control_x{ controlCenter.x - control_w / 2 };
	auto control_y{ controlCenter.y - GUI::comboBox_h / 2 };
	background_w = componentInset * 2;
	background_h = (componentInset * 2) + (gapBetweenButtonAndItemList * 2) + (GUI::secondaryWindowsControls_h * 2);
	if (numberOfItems < 20) {
		background_w += item_w;
		background_h += numberOfItems * GUI::comboBox_h;
	}
	if (numberOfItems == params::numberOfModSources) {
		background_w += item_w * 2;
		background_h += 12 * GUI::comboBox_h;
	}
	if (numberOfItems == params::numberOfModDestinations) {
		background_w += item_w * 5;
		background_h += 10 * GUI::comboBox_h;
	}
	if (numberOfItems == params::numberOfKnobAssignTargets) {
		background_w += item_w * 10;
		background_h += 17 * GUI::comboBox_h;
	}
	if (control_x < 600)
		background_x = control_x;
	else
		background_x = control_x + control_w - background_w;
	if (numberOfItems == params::numberOfKnobAssignTargets)
		background_x += 90;
	if (control_y < 400)
		background_y = control_y + GUI::comboBox_h + 20;
	else
		background_y = control_y - background_h - 20;

	setSize(GUI::editor_w, GUI::editor_h);
}

void RandomizationOptionsComponent_ComboBoxes::paint(Graphics& g) {
	g.fillAll(Color::black.withAlpha(0.4f));
	auto& info{ InfoForExposedParameters::get() };
	auto controlCenter{ info.controlCenterPointFor(paramIndex) };
	auto control_w{ info.controlWidthFor(paramIndex) };
	g.setColour(Color::switchOn);
	g.drawRect(controlCenter.x - control_w / 2 - 2, controlCenter.y - GUI::comboBox_h / 2 - 2, control_w + 4, GUI::comboBox_h + 4, 2);
	g.setColour(Color::black);
	g.fillRect(background_x, background_y, background_w, background_h);
	g.setColour(Color::device);
	g.fillRect(background_x + 2, background_y + 2, background_w - 4, background_h - 4);
}

void RandomizationOptionsComponent_ComboBoxes::resized() {
	auto allowAllButton_x{ background_x + background_w / 2 - GUI::randomizationAllowAllItemsButton_w / 2 };
	auto allowAllButton_y{ background_y + componentInset };
	button_ForAllowingAllItems.setBounds(allowAllButton_x, allowAllButton_y, GUI::randomizationAllowAllItemsButton_w, GUI::secondaryWindowsControls_h);

	for (auto itemNum = 0; itemNum != numberOfItems; ++itemNum) {
		auto toggle_x{ background_x + componentInset };
		auto toggle_y{ background_y + componentInset + GUI::secondaryWindowsControls_h + gapBetweenButtonAndItemList };
		if (numberOfItems < 20)
			toggle_y += itemNum * GUI::comboBox_h;
		if (numberOfItems == params::numberOfModSources) {
			toggle_x += itemNum / 12 * item_w;
			toggle_y += itemNum % 12 * GUI::comboBox_h;
		}
		if (numberOfItems == params::numberOfModDestinations) {
			toggle_x += itemNum / 10 * item_w;
			toggle_y += itemNum % 10 * GUI::comboBox_h;
		}
		if (numberOfItems == params::numberOfKnobAssignTargets) {
			toggle_x += itemNum / 17 * item_w;
			toggle_y += itemNum % 17 * GUI::comboBox_h;
		}
		allowedItemToggles[itemNum].setBounds(toggle_x, toggle_y, item_w, GUI::comboBox_h);
	}

	auto closeButton_x{ background_x + background_w / 2 - GUI::secondaryWindowsControls_w / 2 };
	auto closeButton_y{ background_y + background_h - componentInset - GUI::secondaryWindowsControls_h };
	button_ForClosingComponent.setBounds(closeButton_x, closeButton_y, GUI::secondaryWindowsControls_w, GUI::secondaryWindowsControls_h);
}

void RandomizationOptionsComponent_ComboBoxes::buttonClicked(Button* button) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto buttonID{ button->getComponentID() };
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	if (buttonID.startsWith(ID::component_AllowComboBoxItem_ToggleButton_.toString()) && buttonID.endsWith(paramID)) {
		auto clickedItemNum{ buttonID.fromFirstOccurrenceOf("Button_", false, false).upToFirstOccurrenceOf("_For", false, false).getIntValue()};
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto itemNum = 0; itemNum != info.numberOfStepsFor(paramIndex); ++itemNum) {
				if (itemNum == clickedItemNum) {
					allowedItemToggles[itemNum].setToggleState(true, dontSendNotification);
					randomizationOptions->setComboBoxItemIsAllowedForParam(itemNum, paramIndex);
				}
				else {
					allowedItemToggles[itemNum].setToggleState(false, dontSendNotification);
					randomizationOptions->setComboBoxItemIsNotAllowedForParam(itemNum, paramIndex);
				}
			}
		}
		else {
			auto isAllowed{ button->getToggleState() };
			if (isAllowed)
				randomizationOptions->setComboBoxItemIsAllowedForParam(clickedItemNum, paramIndex);
			else
				randomizationOptions->setComboBoxItemIsNotAllowedForParam(clickedItemNum, paramIndex);
		}
		if (randomizationOptions->noComboBoxItemIsAllowedForParam(paramIndex)) {
			button->setToggleState(true, dontSendNotification);
			randomizationOptions->setComboBoxItemIsAllowedForParam(clickedItemNum, paramIndex);
		}
	}
	if (buttonID == ID::button_AllItemsFor_.toString() + paramID) {
		for (auto itemNum = 0; itemNum != info.numberOfStepsFor(paramIndex); ++itemNum) {
			allowedItemToggles[itemNum].setToggleState(true, dontSendNotification);
			randomizationOptions->setComboBoxItemIsAllowedForParam(itemNum, paramIndex);
		}
	}
}

void RandomizationOptionsComponent_ComboBoxes::hideThisComponent() {
	getParentComponent()->grabKeyboardFocus();
	setVisible(false);
}

RandomizationOptionsComponent_ComboBoxes::~RandomizationOptionsComponent_ComboBoxes() {
	for (auto itemNum = 0; itemNum != numberOfItems; ++itemNum)
		allowedItemToggles[itemNum].removeListener(this);
	button_ForAllowingAllItems.removeListener(this);
}