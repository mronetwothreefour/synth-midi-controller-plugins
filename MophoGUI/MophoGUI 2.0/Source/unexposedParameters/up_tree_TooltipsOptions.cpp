#include "up_tree_TooltipsOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



TooltipsOptions::TooltipsOptions() :
	tooltipsOptionsTree{ ID::tooltips_Options }
{
	setShouldShowCurrentValue(true);
	setShouldShowDescription(true);
	setDelayInMilliseconds(3000);
}

void TooltipsOptions::addListener(ValueTree::Listener* listener) {
	tooltipsOptionsTree.addListener(listener);
}

void TooltipsOptions::removeListener(ValueTree::Listener* listener) {
	tooltipsOptionsTree.removeListener(listener);
}

const bool TooltipsOptions::shouldShowCurrentValue() {
	return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_ShowCurrentValue) == true;
}

void TooltipsOptions::setShouldShowCurrentValue(bool shouldShow) {
	tooltipsOptionsTree.setProperty(ID::tooltips_ShowCurrentValue, shouldShow, nullptr);
}

const bool TooltipsOptions::shouldShowDescriptions() {
	return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_ShowDescription) == true;
}

void TooltipsOptions::setShouldShowDescription(bool shouldShow) {
	tooltipsOptionsTree.setProperty(ID::tooltips_ShowDescription, shouldShow, nullptr);
}

const int TooltipsOptions::delayInMilliseconds() {
	return (int)tooltipsOptionsTree.getProperty(ID::tooltips_DelayInMilliseconds);
}

void TooltipsOptions::setDelayInMilliseconds(int newDelay) {
	tooltipsOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, newDelay, nullptr);
}

XmlElement* TooltipsOptions::getStateXml() {
	auto tooltipsOptionsTreeStateXml{ tooltipsOptionsTree.createXml() };
	if (tooltipsOptionsTreeStateXml != nullptr)
		tooltipsOptionsTreeStateXml->setTagName(ID::state_TooltipsOptions);
	return tooltipsOptionsTreeStateXml.release();
}

void TooltipsOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		tooltipsOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}

