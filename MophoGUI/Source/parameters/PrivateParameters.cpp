#include "PrivateParameters.h"

PrivateParameters::PrivateParameters() :
	tooltipOptionsTree	{ new ValueTree(ID::tooltipOptions) },
	lfoOptionsTree	{ new ValueTree(ID::lfoOptions) }
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

//==============================================================================

int PrivateParameters::getLFOfreqRange(int lfoNumber) const
{
	Identifier propertyID{ "lfo" + (String)lfoNumber + "FreqRange" };
	if (lfoOptionsTree->hasProperty(propertyID))
		return (int)lfoOptionsTree->getProperty(propertyID);
	else return -1;
}

bool PrivateParameters::setLFOfreqRange(int lfoNumber, int range)
{
	Identifier propertyID{ "lfo" + (String)lfoNumber + "FreqRange" };
	lfoOptionsTree->setProperty(propertyID, range, nullptr);
	bool wasSet{ lfoOptionsTree->hasProperty(propertyID) };
	return wasSet;
}

double PrivateParameters::getLastValueForRange(int lfoNumber, int range) const
{
	Identifier propertyID{ "lfo" + (String)lfoNumber + "Range" + (String)range + "LastVal" };
	if (lfoOptionsTree->hasProperty(propertyID))
		return (double)lfoOptionsTree->getProperty(propertyID);
	else return -1.0;
}

bool PrivateParameters::setValueForRange(int lfoNumber, int range, double newValue)
{
	Identifier propertyID{ "lfo" + (String)lfoNumber + "Range" + (String)range + "LastVal" };
	lfoOptionsTree->setProperty(propertyID, newValue, nullptr);
	bool wasSet{ lfoOptionsTree->hasProperty(propertyID) };
	return wasSet;
}
