#pragma once

#include <JuceHeader.h>



class ProgramNameStrings
{
	ValueTree factoryBank1ProgramNames;
	ValueTree factoryBank2ProgramNames;
	ValueTree factoryBank3ProgramNames;
	ValueTree customBank1ProgramNames;
	ValueTree customBank2ProgramNames;
	ValueTree customBank3ProgramNames;
	String basicPatchNameString{ "Basic Patch     " };

public:
	ProgramNameStrings();
	void initializeAllProgramNameStringsInAllBanks();
	const String extractProgramNameFromDataVector(const std::vector<uint8>& dataVector);
	const String nameOfProgramInFactoryBankSlot(uint8 bank, uint8 slot);
	const String nameOfProgramInCustomBankSlot(uint8 bank, uint8 slot);
	void storeNameOfProgramInCustomBankSlot(const String programName, uint8 bank, uint8 slot);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNameStrings)
};