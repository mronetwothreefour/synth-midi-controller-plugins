#include "PrivateParameters.h"

PrivateParameters::PrivateParameters() :
	lfoOptionsTree		{ new ValueTree(ID::lfoOptions)		},
	tooltipOptionsTree	{ new ValueTree(ID::tooltipOptions) }
{
	updateFromPreset = (bool)false;

	for (int i = 1; i != 5; ++i)
	{
		setLfoType(i, unSynced);
		setLfoUnSyncedValue(i, 80);
		setLfoPitchValue(i, 90); // C 0
		setLfoSyncedValue(i, 159); // 1 cycle lasts 1 step
	}

	setShouldShowValueTip(true);
	setShouldShowInfoTip(true);
	setTooltipDelay(1000);
}

PrivateParameters::~PrivateParameters()
{
	tooltipOptionsTree = nullptr;
	lfoOptionsTree = nullptr;
}

//==============================================================================

int PrivateParameters::getLfoType(int& lfoNumber) const
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	Identifier propertyID{ "lfo" + (String)lfoNumber + "Type" };
	if (lfoOptionsTree->hasProperty(propertyID))
		return (int)lfoOptionsTree->getProperty(propertyID);
	else return -1;
}

bool PrivateParameters::setLfoType(int& lfoNumber, int newType)
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	jassert(newType > -1 && newType < 3); // LFO type must be 0, 1, or 2
	if (lfoNumber > 0 && lfoNumber < 5 && newType > -1 && newType < 3)
	{
		Identifier propertyID{ "lfo" + (String)lfoNumber + "Type" };
		lfoOptionsTree->setProperty(propertyID, newType, nullptr);
		bool wasSet{ tooltipOptionsTree->hasProperty(propertyID) };
		return wasSet;
	}
	else return false;
}

int PrivateParameters::getLfoUnSyncedValue(int& lfoNumber) const
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	Identifier propertyID{ "lfo" + (String)lfoNumber + "UnSyncedVal" };
	if (lfoOptionsTree->hasProperty(propertyID))
		return (int)lfoOptionsTree->getProperty(propertyID);
	else return -1;
}

bool PrivateParameters::setLfoUnSyncedValue(int& lfoNumber, int newValue)
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	jassert(newValue > -1 && newValue < 90); // Un-Synced LFO value range is 0..89 
	if (lfoNumber > 0 && lfoNumber < 5 && newValue > -1 && newValue < 90)
	{
		Identifier propertyID{ "lfo" + (String)lfoNumber + "UnSyncedVal" };
		lfoOptionsTree->setProperty(propertyID, newValue, nullptr);
		bool wasSet{ tooltipOptionsTree->hasProperty(propertyID) };
		return wasSet;
	}
	else return false;
}

int PrivateParameters::getLfoPitchValue(int& lfoNumber) const
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	Identifier propertyID{ "lfo" + (String)lfoNumber + "PitchVal" };
	if (lfoOptionsTree->hasProperty(propertyID))
		return (int)lfoOptionsTree->getProperty(propertyID);
	else return -1;
}

bool PrivateParameters::setLfoPitchValue(int& lfoNumber, int newValue)
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	jassert(newValue > 89 && newValue < 151); // Pitch LFO value range is 90..150 
	if (lfoNumber > 0 && lfoNumber < 5 && newValue > 89 && newValue < 151)
	{
		Identifier propertyID{ "lfo" + (String)lfoNumber + "PitchVal" };
		lfoOptionsTree->setProperty(propertyID, newValue, nullptr);
		bool wasSet{ tooltipOptionsTree->hasProperty(propertyID) };
		return wasSet;
	}
	else return false;
}

int PrivateParameters::getLfoSyncedValue(int& lfoNumber) const
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	Identifier propertyID{ "lfo" + (String)lfoNumber + "SyncedVal" };
	if (lfoOptionsTree->hasProperty(propertyID))
		return (int)lfoOptionsTree->getProperty(propertyID);
	else return -1;
}

bool PrivateParameters::setLfoSyncedValue(int& lfoNumber, int newValue)
{
	jassert(lfoNumber > 0 && lfoNumber < 5); // LFO number must be 1, 2, 3, or 4
	jassert(newValue > 150 && newValue < 167); // Synced LFO value range is 151..166 
	if (lfoNumber > 0 && lfoNumber < 5 && newValue > 150 && newValue < 167)
	{
		Identifier propertyID{ "lfo" + (String)lfoNumber + "SyncedVal" };
		lfoOptionsTree->setProperty(propertyID, newValue, nullptr);
		bool wasSet{ tooltipOptionsTree->hasProperty(propertyID) };
		return wasSet;
	}
	else return false;
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

