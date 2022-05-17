#include "params_TooltipOptions.h"

#include "params_Identifiers.h"



TooltipOptions::TooltipOptions() :
	tooltipOptionsTree{ ID::tooltips_Options } 
{
	addTooltipOptionsProperties();
}

void TooltipOptions::addTooltipOptionsProperties() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, 1000, nullptr);
}

void TooltipOptions::addListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.addListener(listener);
}

void TooltipOptions::removeListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.removeListener(listener);
}

const bool TooltipOptions::shouldShowCurrentValue() {
	return (bool)tooltipOptionsTree.getProperty(ID::tooltips_ShouldShowCurrentValue);
}

const bool TooltipOptions::shouldShowDescriptions() {
	return (bool)tooltipOptionsTree.getProperty(ID::tooltips_ShouldShowDescription);
}

void TooltipOptions::setShouldShowCurrentValue() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)true, nullptr);
}

void TooltipOptions::setShouldNotShowCurrentValue() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)false, nullptr);
}

void TooltipOptions::setShouldShowDescription() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)true, nullptr);
}

void TooltipOptions::setShouldNotShowDescription() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)false, nullptr);
}

const int TooltipOptions::delayInMilliseconds() {
	return (int)tooltipOptionsTree.getProperty(ID::tooltips_DelayInMilliseconds);
}

void TooltipOptions::setDelayInMilliseconds(int newDelay) {
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, newDelay, nullptr);
}

XmlElement* TooltipOptions::getStateXml() {
	auto tooltipOptionsTreeStateXml{ tooltipOptionsTree.createXml() };
	if (tooltipOptionsTreeStateXml != nullptr)
		tooltipOptionsTreeStateXml->setTagName(ID::state_TooltipOptions);
	return tooltipOptionsTreeStateXml.release();
}

void TooltipOptions::replaceState(const ValueTree& newState) {
	tooltipOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}

