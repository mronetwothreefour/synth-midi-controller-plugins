#include "PrivateParameters.h"

PrivateParameters::PrivateParameters() :
	tooltipOptionsTree	{ new ValueTree(ID::tooltipOptions) },
	programBankATree	{ new ValueTree(ID::programBankA)   },
	programBankBTree	{ new ValueTree(ID::programBankB)   },
	programBankCTree	{ new ValueTree(ID::programBankC)   }
{
	updateFromPreset = (bool)false;

	setShouldShowValueTip(true);
	setShouldShowInfoTip(true);
	setTooltipDelay(1000);

	setProgramBanksToDefaults();
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

void PrivateParameters::setProgramBanksToDefaults()
{
	for (auto i = 0; i != 128; ++i)
	{
		programBankATree->setProperty("pgm" + (String)i, DefaultProgamBanks::bankA[i], nullptr);
		programBankBTree->setProperty("pgm" + (String)i, DefaultProgamBanks::bankB[i], nullptr);
		programBankCTree->setProperty("pgm" + (String)i, DefaultProgamBanks::bankC[i], nullptr);
	}
}

String PrivateParameters::getProgramDataString(int bank, int pgmSlot)
{
	if (bank >= A && bank <= C)
	{
		if (pgmSlot > -1 && pgmSlot < 128)
		{
			String programDataString{ "" };
			if (bank == A) { programDataString = programBankATree->getProperty("pgm" + (String)pgmSlot); }
			if (bank == B) { programDataString = programBankBTree->getProperty("pgm" + (String)pgmSlot); }
			if (bank == C) { programDataString = programBankCTree->getProperty("pgm" + (String)pgmSlot); }
			return programDataString;
		}
		else return "invalid slot";
	}
	else return "invalid bank";
}

String PrivateParameters::getStoredProgramName(int bank, int pgmSlot)
{
	if (bank >= A && bank <= C)
	{
		if (pgmSlot > -1 && pgmSlot < 128)
		{
			auto programData{ getProgramDataString(bank, pgmSlot) };
			String programName{ "" };
			for (auto i = 422; i != 459; i += 2) // name character parameters start at character 422 in the storage string
			{
				if (i != 432 && i != 448) // skip the bytes that hold MS bit information, as they are irrelevant for name characters
				{
					auto hexValueString{ programData.substring(i, i + 2) };
					auto charValue{ hexValueString.getHexValue32() };
					programName += (String)std::string(1, (char)charValue);
				}
			}
			return programName;
		}
		else return "invalid slot";
	}
	else return "invalid bank";
}

