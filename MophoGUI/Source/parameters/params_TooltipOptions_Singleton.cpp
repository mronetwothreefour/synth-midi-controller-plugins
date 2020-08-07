#include "params_TooltipOptions_Singleton.h"

#include "../helpers/helper_Identifiers.h"



TooltipOptions::TooltipOptions() :
	tooltipOptionsTree{ ID::tooltips_Options }
{
	addTooltipOptionsProperties();
}

TooltipOptions::~TooltipOptions() {
}

void TooltipOptions::addTooltipOptionsProperties() {
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowCurrentValue, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_ShouldShowDescription, (bool)true, nullptr);
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, 1000, nullptr);
}

TooltipOptions& TooltipOptions::get() {
	static TooltipOptions tooltipOptions_Singleton;
	return tooltipOptions_Singleton;
}

void TooltipOptions::addListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.addListener(listener);
}

void TooltipOptions::removeListener(ValueTree::Listener* listener) {
	tooltipOptionsTree.removeListener(listener);
}

bool TooltipOptions::shouldShowCurrentValue() {
	return (bool)tooltipOptionsTree.getProperty(ID::tooltips_ShouldShowCurrentValue);
}

bool TooltipOptions::shouldShowDescription() {
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

int TooltipOptions::delayInMilliseconds() {
	return (int)tooltipOptionsTree.getProperty(ID::tooltips_DelayInMilliseconds);
}

void TooltipOptions::setDelayInMilliseconds(int newDelay) {
	tooltipOptionsTree.setProperty(ID::tooltips_DelayInMilliseconds, newDelay, nullptr);
}


//================================================================================

