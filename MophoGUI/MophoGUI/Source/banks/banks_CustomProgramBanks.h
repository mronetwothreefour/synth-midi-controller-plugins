#pragma once

#include <JuceHeader.h>



class CustomProgramBanks
{
	ValueTree programBank1;
	ValueTree programBank2;
	ValueTree programBank3;

public:
	CustomProgramBanks();
	void resetAllProgramBanksToFactoryDefaults();
	int programSlotOutOfRange();
	const String getProgramDataHexStringFromBankSlot(uint8 bank, uint8 slot) const;
	void storeProgramDataHexStringInBankSlot(String hexString, uint8 bank, uint8 slot);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~CustomProgramBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CustomProgramBanks)
};