#include "0_rndm_comp_AllowChoiceToggles.h"

#include "../constants/constants_GUI_Colors.h"
#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"
#include "../unexposedParameters/up_facade_UnexposedParameters.h"

using namespace MophoConstants;


AllowChoiceToggles::AllowChoiceToggles(uint8 paramIndex, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	unexposedParams{ unexposedParams }
{
	jassert(paramIndex < EP::numberOfExposedParams);

	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	auto paramName{ info.exposedNameFor(paramIndex) };
	numberOfChoices = info.numberOfChoicesFor(paramIndex);
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	auto tooltipOptions{ unexposedParams->getTooltipsOptions() };
	auto shouldShowDescriptions{ tooltipOptions->shouldShowDescriptions() };
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		allowedChoiceToggles.push_back(std::make_unique<ToggleButton>(info.choiceNameFor(choiceNum, paramIndex)));
		allowedChoiceToggles[choiceNum]->setComponentID(ID::component_ToggleAllowChoice_.toString() + (String)choiceNum + "_For_" + paramID);
		auto choiceIsAllowed{ randomizationOptions->choiceIsAllowedForParam(choiceNum, paramIndex) };
		allowedChoiceToggles[choiceNum]->setToggleState(choiceIsAllowed, dontSendNotification);
		allowedChoiceToggles[choiceNum]->addListener(this);
		addAndMakeVisible(allowedChoiceToggles[choiceNum].get());
		if (shouldShowDescriptions) {
			String buttonTooltip{ "" };
			buttonTooltip += "Click a choice to toggle whether or not it\n";
			buttonTooltip += "is allowed when generating a random setting\n";
			buttonTooltip += "for " + paramName + ".\n";
			buttonTooltip += "CTRL-click a choice to make it the only one\n";
			buttonTooltip += "allowed. SHIFT-click to allow a range of\n";
			buttonTooltip += "choices. ALT-click to allow a range of choices\n";
			buttonTooltip += "that are all in the same row.";
			allowedChoiceToggles[choiceNum]->setTooltip(buttonTooltip);
		}
	}
	numberOfColumns = info.numberOfAllowChoiceToggleColumnsFor(paramIndex);
	numberOfRows = info.numberOfAllowChoiceToggleRowsFor(paramIndex);
	toggle_w = info.widthOfAllowChoiceToggleColumnFor(paramIndex);
	auto component_w{ numberOfColumns * toggle_w };
	auto component_h{ numberOfRows * GUI::allowChoiceToggle_h };
	setSize(component_w, component_h);
}

void AllowChoiceToggles::resized() {
	auto& info{ InfoForExposedParameters::get() };
	auto rowCount{ info.firstAllowChoiceToggleRowFor(paramIndex) };
	auto colCount{ 0 };
	for (auto choiceNum = 0; choiceNum < numberOfChoices; ++choiceNum) {
		if (rowCount == numberOfRows) {
			rowCount = 0;
			++colCount;
		}
		allowedChoiceToggles[choiceNum]->setBounds(colCount * toggle_w, rowCount * GUI::allowChoiceToggle_h, toggle_w, GUI::allowChoiceToggle_h);
		++rowCount;
	}
}

void AllowChoiceToggles::buttonClicked(Button* button) {
	auto buttonID{ button->getComponentID() };
	auto& info{ InfoForExposedParameters::get() };
	auto paramID{ info.IDfor(paramIndex).toString() };
	if (buttonID.startsWith(ID::component_ToggleAllowChoice_.toString()) && buttonID.endsWith(paramID)) {
		auto clickedChoice{ (uint8)buttonID.fromFirstOccurrenceOf("Choice_", false, false).upToFirstOccurrenceOf("_For_", false, false).getIntValue() };
		auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
		if (ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier) {
			for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum) {
				if (choiceNum == clickedChoice) {
					allowedChoiceToggles[clickedChoice]->setToggleState(true, dontSendNotification);
					randomizationOptions->allowChoiceForParam(clickedChoice, paramIndex);
				}
				else {
					allowedChoiceToggles[choiceNum]->setToggleState(false, dontSendNotification);
					randomizationOptions->forbidChoiceForParam(choiceNum, paramIndex);
				}
			}
		}
		else if (ModifierKeys::currentModifiers == ModifierKeys::shiftModifier) {
			auto nextAllowedChoice{ numberOfChoices };
			for (auto nextChoice = clickedChoice - 1; nextChoice > -1; --nextChoice) {
				if (randomizationOptions->choiceIsAllowedForParam((uint8)nextChoice, paramIndex)) {
					nextAllowedChoice = (uint8)nextChoice;
					break;
				}
			}
			if (nextAllowedChoice == numberOfChoices) {
				for (auto nextChoice = clickedChoice + 1; nextChoice < numberOfChoices; ++nextChoice) {
					if (randomizationOptions->choiceIsAllowedForParam((uint8)nextChoice, paramIndex)) {
						nextAllowedChoice = (uint8)nextChoice;
						break;
					}
				}
			}
			if (nextAllowedChoice != numberOfChoices) {
				if (nextAllowedChoice < clickedChoice) {
					for (auto choice = nextAllowedChoice; choice <= clickedChoice; ++choice) {
						allowedChoiceToggles[choice]->setToggleState(true, dontSendNotification);
						randomizationOptions->allowChoiceForParam(choice, paramIndex);
					}
				}
				else {
					for (auto choice = clickedChoice; choice <= nextAllowedChoice; ++choice) {
						allowedChoiceToggles[choice]->setToggleState(true, dontSendNotification);
						randomizationOptions->allowChoiceForParam(choice, paramIndex);
					}
				}
			}
			else {
				allowedChoiceToggles[clickedChoice]->setToggleState(true, dontSendNotification);
				randomizationOptions->allowChoiceForParam(clickedChoice, paramIndex);
			}
		}
		else if (ModifierKeys::currentModifiers == ModifierKeys::altModifier) {
			auto nextAllowedChoice{ numberOfChoices };
			for (auto nextChoice = clickedChoice - numberOfRows; nextChoice > -1; nextChoice -= (uint8)numberOfRows) {
				if (randomizationOptions->choiceIsAllowedForParam((uint8)nextChoice, paramIndex)) {
					nextAllowedChoice = (uint8)nextChoice;
					break;
				}
			}
			if (nextAllowedChoice == numberOfChoices) {
				for (auto nextChoice = clickedChoice + numberOfRows; nextChoice < numberOfChoices; nextChoice += (uint8)numberOfRows) {
					if (randomizationOptions->choiceIsAllowedForParam((uint8)nextChoice, paramIndex)) {
						nextAllowedChoice = (uint8)nextChoice;
						break;
					}
				}
			}
			if (nextAllowedChoice != numberOfChoices) {
				if (nextAllowedChoice < clickedChoice) {
					for (auto choice = nextAllowedChoice; choice <= clickedChoice; choice += (uint8)numberOfRows) {
						allowedChoiceToggles[choice]->setToggleState(true, dontSendNotification);
						randomizationOptions->allowChoiceForParam(choice, paramIndex);
					}
				}
				else {
					for (auto choice = clickedChoice; choice <= nextAllowedChoice; choice += (uint8)numberOfRows) {
						allowedChoiceToggles[choice]->setToggleState(true, dontSendNotification);
						randomizationOptions->allowChoiceForParam(choice, paramIndex);
					}
				}
			}
			else {
				allowedChoiceToggles[clickedChoice]->setToggleState(true, dontSendNotification);
				randomizationOptions->allowChoiceForParam(clickedChoice, paramIndex);
			}
		}
		else {
			auto choiceIsAllowed{ button->getToggleState() };
			if (choiceIsAllowed)
				randomizationOptions->allowChoiceForParam(clickedChoice, paramIndex);
			else
				randomizationOptions->forbidChoiceForParam(clickedChoice, paramIndex);
		}
		if (randomizationOptions->noChoiceIsAllowedForParam(paramIndex)) {
			allowedChoiceToggles[clickedChoice]->setToggleState(true, dontSendNotification);
			randomizationOptions->allowChoiceForParam(clickedChoice, paramIndex);
		}
	}
}

void AllowChoiceToggles::allowAllChoices() {
	auto randomizationOptions{ unexposedParams->getRandomizationOptions() };
	for (auto choice = 0; choice < numberOfChoices; ++choice) {
		allowedChoiceToggles[choice]->setToggleState(true, dontSendNotification);
		randomizationOptions->allowChoiceForParam((uint8)choice, paramIndex);
	}
}

AllowChoiceToggles::~AllowChoiceToggles() {
	for (auto choice = 0; choice < numberOfChoices; ++choice) {
		allowedChoiceToggles[choice]->removeListener(this);
	}
	allowedChoiceToggles.clear();
}
