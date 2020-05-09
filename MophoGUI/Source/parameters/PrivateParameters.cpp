#include "PrivateParameters.h"

PrivateParameters::PrivateParameters() :
	tooltipOptionsTree	{ new ValueTree(ID::tooltipOptions) },
	programBank1Tree	{ new ValueTree(ID::programBank1)   },
	programBank2Tree	{ new ValueTree(ID::programBank2)   },
	programBank3Tree	{ new ValueTree(ID::programBank3)   }
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
		programBank1Tree->setProperty("pgm" + (String)i, DefaultProgamBanks::bank1[i], nullptr);
		programBank2Tree->setProperty("pgm" + (String)i, DefaultProgamBanks::bank2[i], nullptr);
		programBank3Tree->setProperty("pgm" + (String)i, DefaultProgamBanks::bank3[i], nullptr);
	}
}

const uint8* PrivateParameters::getProgramDataFromStorageString(int bank, int pgmSlot)
{
	if (bank > -1 && bank < 3)
	{
		if (pgmSlot > -1 && pgmSlot < 128)
		{
			String programDataString{ "" };
			if (bank == 0) { programDataString = programBank1Tree->getProperty("pgm" + (String)pgmSlot); }
			if (bank == 1) { programDataString = programBank2Tree->getProperty("pgm" + (String)pgmSlot); }
			if (bank == 2) { programDataString = programBank3Tree->getProperty("pgm" + (String)pgmSlot); }

			static uint8 programData[293]{};

			// convert the hex string values to integer values and add them to the data array
			for (auto i = 0; i != 460; i += 2)
			{
				auto hexValueString{ programDataString.substring(i, i + 2) };
				programData[i / 2] = (uint8)hexValueString.getHexValue32();
			}

			return programData;
		}
		else return nullptr;
	}
	else return nullptr;
}

void PrivateParameters::setProgramDataString(const uint8* data, int bank, int pgmSlot)
{
	if (bank > -1 && bank < 3)
	{
		if (pgmSlot > -1 && pgmSlot < 128)
		{
			String programDataString{ String::toHexString(data, 293, 0) };
			if (bank == 0) { programBank1Tree->setProperty("pgm" + (String)pgmSlot, programDataString, nullptr); }
			if (bank == 1) { programBank2Tree->setProperty("pgm" + (String)pgmSlot, programDataString, nullptr); }
			if (bank == 2) { programBank3Tree->setProperty("pgm" + (String)pgmSlot, programDataString, nullptr); }
		}
	}
}

String PrivateParameters::getStoredProgramName(int bank, int pgmSlot)
{
	if (bank > -1 && bank < 3)
	{
		if (pgmSlot > -1 && pgmSlot < 128)
		{
			auto programData{ getProgramDataFromStorageString(bank, pgmSlot) };
			if (programData != nullptr)
			{
				String programName{ "" };
				for (auto i = 211; i != 230; i += 1) // name character parameters start at character 422 in the storage string
				{
					if (i != 216 && i != 224) // skip the bytes that hold MS bit information, as they are irrelevant for name characters
					{
						programName += (String)std::string(1, (char)*(programData + i));
					}
				}
				return programName;
			}
			else return "invalid data";
		}
		else return "invalid slot";
	}
	else return "invalid bank";
}

void PrivateParameters::copySelectedProgramToBuffer(int bank, int pgmSlot)
{
	if (bank > -1 && bank < 3)
	{
		if (pgmSlot > -1 && pgmSlot < 128)
		{
			if (bank == 0) { programBuffer = programBank1Tree->getProperty("pgm" + (String)pgmSlot); }
			if (bank == 1) { programBuffer = programBank2Tree->getProperty("pgm" + (String)pgmSlot); }
			if (bank == 2) { programBuffer = programBank3Tree->getProperty("pgm" + (String)pgmSlot); }
		}
	}
	else programBuffer = "";
}

void PrivateParameters::replaceSelectedProgramWithBuffer(int bank, int pgmSlot)
{
	if (programBuffer != "")
	{
		if (bank > -1 && bank < 3)
		{
			if (pgmSlot > -1 && pgmSlot < 128)
			{
				if (bank == 0) { programBank1Tree->setProperty("pgm" + (String)pgmSlot, programBuffer, nullptr); }
				if (bank == 1) { programBank2Tree->setProperty("pgm" + (String)pgmSlot, programBuffer, nullptr); }
				if (bank == 2) { programBank3Tree->setProperty("pgm" + (String)pgmSlot, programBuffer, nullptr); }
			}
		}
	}
}

