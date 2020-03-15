#include "PrivateParameters.h"

PrivateParameters::PrivateParameters() :
	tooltipOptionsTree{ new ValueTree(ID::tooltipOptions) }
{
	tooltipOptionsTree->setProperty(ID::showCurrentVal, (bool)true, nullptr);
	tooltipOptionsTree->setProperty(ID::showParamInfo, (bool)true, nullptr);
	tooltipOptionsTree->setProperty(ID::tooltipDelay, 1000, nullptr);
}

PrivateParameters::~PrivateParameters()
{
	tooltipOptionsTree = nullptr;
}

//==============================================================================

bool PrivateParameters::shouldShowValueTip() const
{
	if (tooltipOptionsTree->hasProperty(ID::showCurrentVal))
		return (bool)tooltipOptionsTree->getProperty(ID::showCurrentVal);
	else return false;
}

bool PrivateParameters::setShouldShowValueTip(bool shouldShow)
{
	Value newValue{ shouldShow };
	tooltipOptionsTree->setProperty(ID::showCurrentVal, newValue, nullptr);
	bool wasSet{ tooltipOptionsTree->hasProperty(ID::showCurrentVal) };
	return wasSet;
}

bool PrivateParameters::shouldShowInfoTip() const
{
	if (tooltipOptionsTree->hasProperty(ID::showParamInfo))
		return (bool)tooltipOptionsTree->getProperty(ID::showParamInfo);
	else return false;
}

bool PrivateParameters::setShouldShowInfoTip(bool shouldShow)
{
	Value newValue{ shouldShow };
	tooltipOptionsTree->setProperty(ID::showParamInfo, newValue, nullptr);
	bool wasSet{ tooltipOptionsTree->hasProperty(ID::showParamInfo) };
	return wasSet;
}

int PrivateParameters::getTooltipDelay() const
{
	if (tooltipOptionsTree->hasProperty(ID::tooltipDelay))
		return (int)tooltipOptionsTree->getProperty(ID::tooltipDelay);
	else return -1;
}

bool PrivateParameters::setTooltipDelay(int delay)
{
	Value newValue{ delay };
	tooltipOptionsTree->setProperty(ID::tooltipDelay, newValue, nullptr);
	bool wasSet{ tooltipOptionsTree->hasProperty(ID::tooltipDelay) };
	return wasSet;
}

