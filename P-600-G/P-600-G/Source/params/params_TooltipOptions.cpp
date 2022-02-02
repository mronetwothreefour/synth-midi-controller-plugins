#include "params_TooltipOptions.h"

#include "params_Identifiers.h"



TooltipOptions::TooltipOptions() :
	tooltipOptionsTree{ ID::tooltips_Options }
{
	fillTooltipOptionsTreeWithProperties();
}

void TooltipOptions::fillTooltipOptionsTreeWithProperties() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentSettings, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescriptions, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, 1000, nullptr);
}

void TooltipOptions::addListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.addListener(listener);
}

void TooltipOptions::removeListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.removeListener(listener);
}

const bool TooltipOptions::shouldShowCurrentSettings() {
	return (bool)tooltipOptionsTree.getProperty(ID::tooltips_ShouldShowCurrentSettings);
}

const bool TooltipOptions::shouldShowDescriptions() {
	return (bool)tooltipOptionsTree.getProperty(ID::tooltips_ShouldShowDescriptions);
}

void TooltipOptions::setShouldShowCurrentSettings() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentSettings, (bool)true, nullptr);
}

void TooltipOptions::setShouldNotShowCurrentSettings() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentSettings, (bool)false, nullptr);
}

void TooltipOptions::setShouldShowDescriptions() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescriptions, (bool)true, nullptr);
}

void TooltipOptions::setShouldNotShowDescriptions() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescriptions, (bool)false, nullptr);
}

const int TooltipOptions::delayInMilliseconds() {
	return (int)tooltipOptionsTree.getProperty(ID::tooltips_DelayInMilliseconds);
}

void TooltipOptions::setDelayInMilliseconds(int newDelay) {
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, newDelay, nullptr);
}

XmlElement* TooltipOptions::getStateXml() {
	auto tooltipOptionsTreeStateXml{ tooltipOptionsTree.createXml() };
	tooltipOptionsTreeStateXml->setTagName(ID::state_TooltipOptions);
	return tooltipOptionsTreeStateXml.release();
}

void TooltipOptions::replaceState(const ValueTree& newState) {
	tooltipOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}

