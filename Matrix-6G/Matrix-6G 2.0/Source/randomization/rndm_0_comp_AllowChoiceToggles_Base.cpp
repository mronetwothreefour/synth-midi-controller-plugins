#include "rndm_0_comp_AllowChoiceToggles_Base.h"

#include "../constants/constants_GUI_Dimensions.h"
#include "../constants/constants_Identifiers.h"

using namespace Matrix_6G_Constants;

AllowChoiceToggles_Base::AllowChoiceToggles_Base(uint8 numberOfChoices, int numberOfColumns, int numberOfRows, int firstChoiceRow, int toggle_w) :
	numberOfChoices{ numberOfChoices },
	numberOfColumns{ numberOfColumns },
	numberOfRows{ numberOfRows },
	firstChoiceRow{ firstChoiceRow },
	toggle_w{ toggle_w }
{
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
		allowedChoiceToggles[choiceNum]->setSize(toggle_w, GUI::allowChoiceToggle_h);
		allowedChoiceToggles[choiceNum]->setTopLeftPosition(colCount * toggle_w, rowCount * GUI::allowChoiceToggle_h);
		addAndMakeVisible(allowedChoiceToggles[choiceNum].get());
		++rowCount;
	}
	auto component_w{ numberOfColumns * toggle_w };
	auto component_h{ numberOfRows * GUI::allowChoiceToggle_h };
	setSize(component_w, component_h);
}

void AllowChoiceToggles_Base::buttonClicked(Button* button) {
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

AllowChoiceToggles_Base::~AllowChoiceToggles_Base() {
	for (auto choiceNum = 0; choiceNum < numberOfChoices; ++choiceNum)
		allowedChoiceToggles[choiceNum]->removeListener(this);
	allowedChoiceToggles.clear();
}
