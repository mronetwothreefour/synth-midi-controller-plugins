#include "randomization_AllowedValuesTogglesComponent.h"

#include "../gui/gui_Colors.h"
#include "../gui/gui_Constants.h"
#include "../params/params_Constants.h"
#include "../params/params_ExposedParamsInfo_Singleton.h"
#include "../params/params_Identifiers.h"
#include "../params/params_IntToContextualStringConverters.h"
#include "../params/params_UnexposedParameters_Facade.h"

using namespace constants;


AllowedValuesTogglesComponent::AllowedValuesTogglesComponent(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	jassert(paramIndex < params::numberOfExposedParams);

	auto& info{ InfoForExposedParameters::get() };
	paramID = info.IDfor(paramIndex).toString();
	auto paramName{ info.exposedNameFor(paramIndex) };
	auto converter{ info.converterFor(paramIndex) };
	numberOfValues = info.numberOfStepsFor(paramIndex);
	toggleWidth = info.widthOfAllowedValuesColumnFor(paramIndex);
	numberOfColumns = info.numberOfAllowedValuesColumnsFor(paramIndex);
	numberOfRows = info.numberOfAllowedValuesRowsFor(paramIndex);
	rowForFirstValue = info.firstAllowedValuesRowFor(paramIndex);
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	auto tooltipOptions{ unexposedParams->tooltipOptions_get() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto value = 0; value < numberOfValues; ++value) {
		allowedValuesToggles[value].setComponentID(ID::component_Allow_ToggleButton_Value_.toString() + (String)value + "_For_" + paramID);
		auto valueIsAllowed{ randomizationOptions->valueIsAllowedForParam((uint8)value, paramIndex) };
		allowedValuesToggles[value].setToggleState(valueIsAllowed, dontSendNotification);
		allowedValuesToggles[value].addListener(this);
		allowedValuesToggles[value].setHelpText(converter->convert((uint8)value));
		addAndMakeVisible(allowedValuesToggles[value]);
		if (shouldShowDescriptions) {
			String buttonTooltip{ "" };
			buttonTooltip += "Click a value to toggle whether or not it\n";
			buttonTooltip += "is allowed when generating a random setting\n";
			buttonTooltip += "for " + paramName + ".\n";
			buttonTooltip += "CTRL-click a value to make it the only one\n";
			buttonTooltip += "allowed. SHIFT-click to allow a range of\n";
			buttonTooltip += "values. ALT-click to allow a range of values\n";
			buttonTooltip += "that are all in the same row.";
			allowedValuesToggles[value].setTooltip(buttonTooltip);
		}
	}
	auto component_w{ numberOfColumns * toggleWidth };
	auto component_h{ numberOfRows * GUI::allowValueToggle_h };
	setSize(component_w, component_h);
}

void AllowedValuesTogglesComponent::resized() {
	auto rowCount{ rowForFirstValue };
	auto colCount{ 0 };
	for (auto value = 0; value < numberOfValues; ++value) {
		if (rowCount == numberOfRows) {
			rowCount = 0;
			++colCount;
		}
		allowedValuesToggles[value].setBounds(colCount * toggleWidth, rowCount * GUI::allowValueToggle_h, toggleWidth, GUI::allowValueToggle_h);
		++rowCount;
	}
}

void AllowedValuesTogglesComponent::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	if (buttonID.startsWith(ID::component_Allow_ToggleButton_Value_.toString()) && buttonID.endsWith(paramID)) {
		auto clickedValue{ (uint8)buttonID.fromFirstOccurrenceOf("Value_", false, false).upToFirstOccurrenceOf("_For_", false, false).getIntValue() };
		auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto value = (uint8)0; value != numberOfValues; ++value) {
				if (value == clickedValue) {
					allowedValuesToggles[clickedValue].setToggleState(true, dontSendNotification);
					randomizationOptions->setValueIsAllowedForParam(clickedValue, paramIndex);
				}
				else {
					allowedValuesToggles[value].setToggleState(false, dontSendNotification);
					randomizationOptions->setValueIsNotAllowedForParam(value, paramIndex);
				}
			}
		}
		else if (ModifierKeys::currentModifiers == ModifierKeys::shiftModifier) {
			auto nextAllowedValue{ numberOfValues };
			for (auto nextValue = clickedValue - 1; nextValue > -1; --nextValue) {
				if (randomizationOptions->valueIsAllowedForParam((uint8)nextValue, paramIndex)) {
					nextAllowedValue = (uint8)nextValue;
					break;
				}
			}
			if (nextAllowedValue == numberOfValues) {
				for (auto nextValue = clickedValue + 1; nextValue < numberOfValues; ++nextValue) {
					if (randomizationOptions->valueIsAllowedForParam((uint8)nextValue, paramIndex)) {
						nextAllowedValue = (uint8)nextValue;
						break;
					}
				}
			}
			if (nextAllowedValue != numberOfValues) {
				if (nextAllowedValue < clickedValue) {
					for (auto value = nextAllowedValue; value <= clickedValue; ++value) {
						allowedValuesToggles[value].setToggleState(true, dontSendNotification);
						randomizationOptions->setValueIsAllowedForParam(value, paramIndex);
					}
				}
				else {
					for (auto value = clickedValue; value <= nextAllowedValue; ++value) {
						allowedValuesToggles[value].setToggleState(true, dontSendNotification);
						randomizationOptions->setValueIsAllowedForParam(value, paramIndex);
					}
				}
			}
			else {
				allowedValuesToggles[clickedValue].setToggleState(true, dontSendNotification);
				randomizationOptions->setValueIsAllowedForParam(clickedValue, paramIndex);
			}
		}
		else if (ModifierKeys::currentModifiers == ModifierKeys::altModifier) {
			auto nextAllowedValue{ numberOfValues };
			for (auto nextValue = clickedValue - numberOfRows; nextValue > -1; nextValue -= (uint8)numberOfRows) {
				if (randomizationOptions->valueIsAllowedForParam((uint8)nextValue, paramIndex)) {
					nextAllowedValue = (uint8)nextValue;
					break;
				}
			}
			if (nextAllowedValue == numberOfValues) {
				for (auto nextValue = clickedValue + numberOfRows; nextValue < numberOfValues; nextValue += (uint8)numberOfRows) {
					if (randomizationOptions->valueIsAllowedForParam((uint8)nextValue, paramIndex)) {
						nextAllowedValue = (uint8)nextValue;
						break;
					}
				}
			}
			if (nextAllowedValue != numberOfValues) {
				if (nextAllowedValue < clickedValue) {
					for (auto value = nextAllowedValue; value <= clickedValue; value += (uint8)numberOfRows) {
						allowedValuesToggles[value].setToggleState(true, dontSendNotification);
						randomizationOptions->setValueIsAllowedForParam(value, paramIndex);
					}
				}
				else {
					for (auto value = clickedValue; value <= nextAllowedValue; value += (uint8)numberOfRows) {
						allowedValuesToggles[value].setToggleState(true, dontSendNotification);
						randomizationOptions->setValueIsAllowedForParam(value, paramIndex);
					}
				}
			}
			else {
				allowedValuesToggles[clickedValue].setToggleState(true, dontSendNotification);
				randomizationOptions->setValueIsAllowedForParam(clickedValue, paramIndex);
			}
		}
		else {
			auto valueIsAllowed{ button->getToggleState() };
			if (valueIsAllowed)
				randomizationOptions->setValueIsAllowedForParam(clickedValue, paramIndex);
			else
				randomizationOptions->setValueIsNotAllowedForParam(clickedValue, paramIndex);
		}
		randomizationOptions->checkNumberOfAllowedValuesForParam(paramIndex);
		if (randomizationOptions->noValueIsAllowedForParam(paramIndex)) {
			allowedValuesToggles[clickedValue].setToggleState(true, dontSendNotification);
			randomizationOptions->setValueIsAllowedForParam(clickedValue, paramIndex);
			randomizationOptions->checkNumberOfAllowedValuesForParam(paramIndex);
		}
	}
}

void AllowedValuesTogglesComponent::allowAllValues() {
	auto randomizationOptions{ unexposedParams->randomizationOptions_get() };
	for (auto value = 0; value < numberOfValues; ++value) {
		allowedValuesToggles[value].setToggleState(true, dontSendNotification);
		randomizationOptions->setValueIsAllowedForParam((uint8)value, paramIndex);
	}
	randomizationOptions->setMoreThanOneValueIsAllowedForParam(paramIndex);
}

AllowedValuesTogglesComponent::~AllowedValuesTogglesComponent() {
	for (auto value = 0; value < numberOfValues; ++value) {
		allowedValuesToggles[value].removeListener(this);
	}
}
