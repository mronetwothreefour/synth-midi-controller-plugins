#include "PrivateParameters.h"

PrivateParameters::PrivateParameters() :
	privateParamsTree{ ID::privateParams }
{
	ValueTree tooltipOptions{ ID::tooltipOptions };
	privateParamsTree.addChild(tooltipOptions, -1, nullptr);
	setPropertyValue(ID::tooltipOptions, ID::showCurrentVal, (bool)true);
	setPropertyValue(ID::tooltipOptions, ID::showParamInfo, (bool)true);
	setPropertyValue(ID::tooltipOptions, ID::tooltipDelay, 1000);
}

PrivateParameters::~PrivateParameters()
{
}

//==============================================================================

bool PrivateParameters::shouldShowValueTip() const
{
	if (properyIsSet(ID::tooltipOptions, ID::showCurrentVal))
		return (bool)getPropertyValue(ID::tooltipOptions, ID::showCurrentVal);
	else return false;
}

bool PrivateParameters::setShouldShowValueTip(bool shouldShow)
{
	Value newValue{ shouldShow };
	bool wasSet{ setPropertyValue(ID::tooltipOptions, ID::showCurrentVal, newValue) };
	return wasSet;
}

bool PrivateParameters::shouldShowInfoTip() const
{
	if (properyIsSet(ID::tooltipOptions, ID::showParamInfo))
		return (bool)getPropertyValue(ID::tooltipOptions, ID::showParamInfo);
	else return false;
}

bool PrivateParameters::setShouldShowInfoTip(bool shouldShow)
{
	Value newValue{ shouldShow };
	bool wasSet{ setPropertyValue(ID::tooltipOptions, ID::showParamInfo, newValue) };
	return wasSet;
}

int PrivateParameters::getTooltipDelay() const
{
	if (properyIsSet(ID::tooltipOptions, ID::tooltipDelay))
		return (int)getPropertyValue(ID::tooltipOptions, ID::tooltipDelay);
	else return -1;
}

bool PrivateParameters::setTooltipDelay(int delay)
{
	Value newValue{ delay };
	bool wasSet{ setPropertyValue(ID::tooltipOptions, ID::showParamInfo, newValue) };
	return wasSet;
}

//==============================================================================

bool PrivateParameters::properyIsSet(Identifier childID, Identifier propertyID) const
{
	return privateParamsTree.getChildWithName(childID).hasProperty(propertyID);
}

var PrivateParameters::getPropertyValue(Identifier childID, Identifier propertyID) const
{
	return privateParamsTree.getChildWithName(childID).getProperty(propertyID);
}

bool PrivateParameters::setPropertyValue(Identifier childID, Identifier propertyID, const juce::var& newValue)
{
	privateParamsTree.getChildWithName(childID).setProperty(propertyID, newValue, nullptr);
	return properyIsSet(childID, propertyID);
}
