#include "up_tree_TooltipsOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace MophoConstants;



TooltipsOptions::TooltipsOptions() :
	tooltipsOptionsTree{ ID::tooltips_Options }
{
	setShouldShowCurrentValue();
	setShouldShowDescription();
	setDelayInMilliseconds(3000);
}

void TooltipsOptions::addListener(ValueTree::Listener* listener) {
	tooltipsOptionsTree.addListener(listener);
}

void TooltipsOptions::removeListener(ValueTree::Listener* listener) {
	tooltipsOptionsTree.removeListener(listener);
}

const bool TooltipsOptions::shouldShowCurrentValue() {
	return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_CurrentValue) == show;
}

const bool TooltipsOptions::shouldShowDescriptions() {
	return (bool)tooltipsOptionsTree.getProperty(ID::tooltips_Description) == show;
}

void TooltipsOptions::setShouldShowCurrentValue() {
	tooltipsOptionsTree.setProperty(ID::tooltips_CurrentValue, show, nullptr);
}

void TooltipsOptions::setShouldNotShowCurrentValue() {
	tooltipsOptionsTree.setProperty(ID::tooltips_CurrentValue, dontShow, nullptr);
}

void TooltipsOptions::setShouldShowDescription() {
	tooltipsOptionsTree.setProperty(ID::tooltips_Description, show, nullptr);
}

void TooltipsOptions::setShouldNotShowDescription() {
	tooltipsOptionsTree.setProperty(ID::tooltips_Description, dontShow, nullptr);
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

