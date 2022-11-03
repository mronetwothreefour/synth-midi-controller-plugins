#include "rndm_0_comp_AllowChoiceToggles.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_3_facade_ExposedParameters.h"
#include "../unexposedParameters/up_1_facade_UnexposedParameters.h"

using namespace P_600_G_Constants;

AllowChoiceToggles::AllowChoiceToggles(uint8 paramIndex, ExposedParameters* exposedParams, UnexposedParameters* unexposedParams) :
	paramIndex{ paramIndex },
	info{ exposedParams->info.get() },
	randomization{ exposedParams->randomization.get() },
	tooltips{ unexposedParams->getTooltipsOptions() },
	numberOfChoices{ exposedParams->info->numberOfChoicesFor(paramIndex) },
	numberOfColumns{ exposedParams->info->numberOfAllowChoiceToggleColumnsFor(paramIndex) },
	numberOfRows{ exposedParams->info->numberOfAllowChoiceToggleRowsFor(paramIndex) },
	firstChoiceRow{ exposedParams->info->firstAllowChoiceToggleRowFor(paramIndex) },
	toggle_w{ exposedParams->info->widthOfAllowChoiceToggleColumnFor(paramIndex) }
{
	jassert(paramIndex < EP::numberOfExposedParams);

	auto rowCount{ firstChoiceRow };
	auto colCount{ 0 };
	for (auto choiceNum = (uint8)0; choiceNum < numberOfChoices; ++choiceNum) {
		if (rowCount == numberOfRows) {
			rowCount = 0;
			++colCount;
		}
		allowedChoiceToggles.push_back(std::make_unique<ToggleButton>());
		allowedChoiceToggles[choiceNum]->setComponentID(ID::comp_ToggleAllow_Choice_.toString() + (String)choiceNum);
		allowedChoiceToggles[choiceNum]->addListener(this);
		allowedChoiceToggles[choiceNum]->setSize(toggle_w, GUI::voiceSlotAndAllowChoiceRadioButtton_h);
		allowedChoiceToggles[choiceNum]->setTopLeftPosition(colCount * toggle_w, rowCount * GUI::voiceSlotAndAllowChoiceRadioButtton_h);
		allowedChoiceToggles[choiceNum]->setName(info->choiceNameFor(choiceNum, paramIndex));
		String tip{ "" };
		if (tooltips->shouldShowDescription()) {
			auto paramName{ info->exposedNameFor(paramIndex) };
			tip += "Click a choice to toggle whether or not it\n";
			tip += "is allowed when generating a random setting\n";
			tip += "for " + paramName + ".\n";
			tip += "CTRL-click a choice to make it the only one\n";
			tip += "allowed. SHIFT-click to allow a range of choices.\n";
			if (info->numberOfAllowChoiceToggleColumnsFor(paramIndex) > 2) {
				tip += "ALT-click to allow a range of choices that\n";
				if (info->controlTypeFor(paramIndex) == ControlType::knobForPitch)
					tip += "are all in the same note row.";
				else
					tip += "are all in the same row.";
			}
		}
		allowedChoiceToggles[choiceNum]->setTooltip(tip);
		addAndMakeVisible(allowedChoiceToggles[choiceNum].get());
		++rowCount;
	}

	auto component_w{ numberOfColumns * toggle_w };
	auto component_h{ numberOfRows * GUI::voiceSlotAndAllowChoiceRadioButtton_h };
	setSize(component_w, component_h);
}

const bool AllowChoiceToggles::choiceIsAllowed(uint8 choiceNum) {
	return randomization->choiceIsAllowedForParam(choiceNum, paramIndex) == true;
}

void AllowChoiceToggles::setChoiceIsAllowed(uint8 choiceNum, bool shouldBeAllowed) {
	randomization->setChoiceIsAllowedForParam(choiceNum, shouldBeAllowed, paramIndex);
}

void AllowChoiceToggles::clearAllowedChoices() {
	randomization->clearAllowedChoicesForParam(paramIndex);
}

const bool AllowChoiceToggles::noChoiceIsAllowed() {
	return randomization->noChoiceIsAllowedForParam(paramIndex) == true;
}

void AllowChoiceToggles::buttonClicked(Button* button) {
	auto noModKeyIsDown{ ModifierKeys::currentModifiers == ModifierKeys::noModifiers };
	auto ctrlKeyIsDown{ ModifierKeys::currentModifiers == ModifierKeys::ctrlModifier };
	auto shiftKeyIsDown{ ModifierKeys::currentModifiers == ModifierKeys::shiftModifier };
	auto altKeyIsDown{ ModifierKeys::currentModifiers == ModifierKeys::altModifier };
	auto buttonID{ button->getComponentID() };
	auto clickedChoice{ (uint8)buttonID.fromFirstOccurrenceOf("Choice_", false, false).getIntValue() };
	if (noModKeyIsDown) {
		auto isAllowed{ button->getToggleState() };
		setChoiceIsAllowed((uint8)clickedChoice, isAllowed ? true : false);
	}
	if (ctrlKeyIsDown) {
		for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
			allowedChoiceToggles[choiceNum]->setToggleState(choiceNum == clickedChoice ? true : false, dontSendNotification);
		clearAllowedChoices();
		setChoiceIsAllowed(clickedChoice, true);
	}
	if (shiftKeyIsDown || (altKeyIsDown && numberOfColumns > 2))
	{
		auto increment{ altKeyIsDown ? (uint8)numberOfRows : (uint8)1 };
		int nextAllowedChoice{ numberOfChoices };
		for (auto previousChoice = clickedChoice - increment; previousChoice > -1; previousChoice -= increment) {
			if (choiceIsAllowed((uint8)previousChoice)) {
				nextAllowedChoice = previousChoice;
				break;
			}
		}
		if (nextAllowedChoice == numberOfChoices) {
			for (auto subsequentChoice = clickedChoice + increment; subsequentChoice < numberOfChoices; subsequentChoice += increment) {
				if (choiceIsAllowed((uint8)subsequentChoice)) {
					nextAllowedChoice = subsequentChoice;
					break;
				}
			}
		}
		if (nextAllowedChoice < numberOfChoices) {
			if (nextAllowedChoice < clickedChoice) {
				for (int choice = nextAllowedChoice; choice <= clickedChoice && choice < numberOfChoices; choice += increment) {
					allowedChoiceToggles[choice]->setToggleState(true, dontSendNotification);
					setChoiceIsAllowed((uint8)choice, true);
				}
			}
			else {
				for (int choice = clickedChoice; choice <= nextAllowedChoice && choice < numberOfChoices; choice += increment) {
					allowedChoiceToggles[choice]->setToggleState(true, dontSendNotification);
					setChoiceIsAllowed((uint8)choice, true);
				}
			}
		}
		else {
			allowedChoiceToggles[clickedChoice]->setToggleState(true, dontSendNotification);
			setChoiceIsAllowed(clickedChoice, true);
		}
	}
	if (noChoiceIsAllowed()) {
		allowedChoiceToggles[clickedChoice]->setToggleState(true, dontSendNotification);
		setChoiceIsAllowed(clickedChoice, true);
	}
}

AllowChoiceToggles::~AllowChoiceToggles() {
	for (auto choiceNum = 0; choiceNum < numberOfChoices; ++choiceNum)
		allowedChoiceToggles[choiceNum]->removeListener(this);
	allowedChoiceToggles.clear();
}
