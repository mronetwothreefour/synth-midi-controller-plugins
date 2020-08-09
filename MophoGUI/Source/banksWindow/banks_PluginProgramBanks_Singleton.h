#pragma once

#include <JuceHeader.h>



class PluginProgramBanks
{
	ValueTree programBank1;
	ValueTree programBank2;
	ValueTree programBank3;

	PluginProgramBanks();
	void fillProgramBanksWithFactoryDefaultPrograms();
	~PluginProgramBanks();

public:
	PluginProgramBanks(PluginProgramBanks&&) = delete;
	PluginProgramBanks& operator=(PluginProgramBanks&&) = delete;

	static PluginProgramBanks& get() noexcept;
	int programSlotOutOfRange();
	void resetAllProgramBanksToFactoryDefaults();
	void storeProgramDataInBankSlot(const uint8* data, uint8 bank, uint8 slot);
	const String getProgramNameFromDataStoredInBankSlot(uint8 bank, uint8 slot);
	const std::vector<uint8> getProgramDataStoredInBankSlot(uint8 bank, uint8 slot);
	const String getProgramHexStringFromBankSlot(uint8 bank, uint8 slot) const;
	void storeProgramHexStringInBankSlot(String hexString, uint8 bank, uint8 slot);

private:
	void storeProgramDataAsHexStringInBankSlot(const uint8* data, uint8 bank, uint8 slot);
	const std::vector<uint8> convertProgramHexStringToDataVector(const String& dataString);
	const String extractProgramNameFromDataVector(const std::vector<uint8> dataVector);

	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProgramBanks)
};