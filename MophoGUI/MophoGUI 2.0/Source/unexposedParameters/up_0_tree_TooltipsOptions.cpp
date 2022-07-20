#include "up_0_tree_TooltipsOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;

TooltipsOptions::TooltipsOptions() :
	tooltipsOptionsTree{ ID::tree_TooltipsOptions }
{
	setShouldShowCurrentChoice(true);
	setShouldShowDescription(true);
	setDelayInMilliseconds(2500);
}

const bool TooltipsOptions::shouldShowCurrentChoice() {
	return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_ShouldShowCurrentChoice) == true;
}

void TooltipsOptions::setShouldShowCurrentChoice(const bool shouldShow) {
	tooltipsOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentChoice, shouldShow ? (bool)true : (bool)false, nullptr);
}

Value TooltipsOptions::getShouldShowCurrentChoiceValue() {
	return tooltipsOptionsTree.getPropertyAsValue(ID::tooltips_ShouldShowCurrentChoice, nullptr);
}

const bool TooltipsOptions::shouldShowDescription() {
	return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_ShouldShowDescription) == true;
}

void TooltipsOptions::setShouldShowDescription(const bool shouldShow) {
	tooltipsOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, shouldShow ? (bool)true : (bool)false, nullptr);
}

Value TooltipsOptions::getShouldShowDescriptionValue() {
	return tooltipsOptionsTree.getPropertyAsValue(ID::tooltips_ShouldShowDescription, nullptr);
}

const int TooltipsOptions::delayInMilliseconds() {
	return (int)tooltipsOptionsTree.getProperty(ID::tooltips_DelayInMilliseconds);
}

void TooltipsOptions::setDelayInMilliseconds(const int newDelay) {
	tooltipsOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, newDelay, nullptr);
}

Value TooltipsOptions::getDelayInMillisecondsValue() {
	return tooltipsOptionsTree.getPropertyAsValue(ID::tooltips_DelayInMilliseconds, nullptr);
}

std::unique_ptr<XmlElement> TooltipsOptions::getStateXml() {
	auto tooltipsOptionsTreeStateXml{ tooltipsOptionsTree.createXml() };
	if (tooltipsOptionsTreeStateXml != nullptr)
		tooltipsOptionsTreeStateXml->setTagName(ID::state_TooltipsOptions);
	return tooltipsOptionsTreeStateXml;
}

void TooltipsOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		tooltipsOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
