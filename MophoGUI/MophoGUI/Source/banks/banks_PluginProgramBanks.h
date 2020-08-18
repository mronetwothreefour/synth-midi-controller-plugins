#pragma once

#include <JuceHeader.h>



class PluginProgramBanks
{
	ValueTree programBank1;
	ValueTree programBank2;
	ValueTree programBank3;

public:
	PluginProgramBanks();
	void resetAllProgramBanksToFactoryDefaults();
	int programSlotOutOfRange();
	const String getProgramDataHexStringFromBankSlot(uint8 bank, uint8 slot) const;
	void storeProgramDataHexStringInBankSlot(String hexString, uint8 bank, uint8 slot);
	~PluginProgramBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PluginProgramBanks)
};