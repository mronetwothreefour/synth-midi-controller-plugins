#pragma once

#include <JuceHeader.h>



class ProgramBanks
{
	ValueTree programBank1;
	ValueTree programBank2;
	ValueTree programBank3;
	const String basicPatchDataHexString{ "00183101000100180033010001000000400204004000001400000000017F00000000000000007F00000000004040785000010000005001000000005001000000005001000000007F000000000000000000007F00007F0000007F00007F007F00007F007F007F007F00003C6400780200000000000101090000050B2B170000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000426173696300205061746368200020202020" };

public:
	ProgramBanks();
	void resetAllProgramBanksToFactoryDefaults();
	int programSlotOutOfRange();
	const String getProgramDataHexStringFromBankSlot(uint8 bank, uint8 slot) const;
	void storeProgramDataHexStringInBankSlot(String hexString, uint8 bank, uint8 slot);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~ProgramBanks();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramBanks)
};