#include "PrivateParameters.h"

PrivateParameters::PrivateParameters() :
	tooltipOptionsTree	{ new ValueTree(ID::tooltipOptions) }
{
	updateFromPreset = (bool)false;

	setShouldShowValueTip(true);
	setShouldShowInfoTip(true);
	setTooltipDelay(1000);
}

PrivateParameters::~PrivateParameters()
{
	tooltipOptionsTree = nullptr;
}

//==============================================================================

//==============================================================================

bool PrivateParameters::shouldShowValueTip() const
{
	if (tooltipOptionsTree->hasProperty(ID::showCurrentVal))
		return (bool)tooltipOptionsTree->getProperty(ID::showCurrentVal);
	else return false;
}

bool PrivateParameters::setShouldShowValueTip(bool shouldShow)
{
	tooltipOptionsTree->setProperty(ID::showCurrentVal, shouldShow, nullptr);
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
	tooltipOptionsTree->setProperty(ID::showParamInfo, shouldShow, nullptr);
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
	tooltipOptionsTree->setProperty(ID::tooltipDelay, delay, nullptr);
	bool wasSet{ tooltipOptionsTree->hasProperty(ID::tooltipDelay) };
	return wasSet;
}

