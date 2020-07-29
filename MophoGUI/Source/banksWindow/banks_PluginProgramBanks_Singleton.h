#pragma once

#include <JuceHeader.h>

#include "banks_FactoryProgamBanks_Singleton.h"



class PluginProgramBanks
{
	ValueTree programBank1;
	ValueTree programBank2;
	ValueTree programBank3;

	PluginProgramBanks();
	void fillProgramBanksWithFactoryDefaultPrograms();
	~PluginProgramBanks();

	void storeProgramDataAsHexStringInBankSlot(const uint8* data, uint8 bank, uint8 slot);
	const String getProgramHexStringFromBankSlot(uint8 bank, uint8 slot) const;
	const uint8* convertProgramHexStringToDataBuffer(const String& dataString);
	const String extractProgramNameFromDataBuffer(const uint8* data);

public:
	PluginProgramBanks(PluginProgramBanks&&) = delete;
	PluginProgramBanks& operator=(PluginProgramBanks&&) = delete;

	static PluginProgramBanks& get() noexcept;
	int programSlotOutOfRange();
	void resetAllProgramBanksToFactoryDefaults();
	void storeProgramDataInBankSlot(const uint8* data, uint8 bank, uint8 slot);
	const String getNameForProgramStoredInBankSlot(uint8 bank, uint8 slot);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProgramBanks)
};