#pragma once

#include <JuceHeader.h>



class ProgramNameStrings
{
	ValueTree bank1ProgramNames;
	ValueTree bank2ProgramNames;
	ValueTree bank3ProgramNames;

public:
	ProgramNameStrings();
	void resetAllProgramNameStringsToFactoryDefaults();
	const String extractProgramNameFromDataVector(const std::vector<uint8>& dataVector);
	const String nameOfProgramInBankSlot(uint8 bank, uint8 slot);
	void storeNameOfProgramInBankSlot(const String programName, uint8 bank, uint8 slot);
	XmlElement* getStateXml();
	void replaceState(const ValueTree& newState);
	~ProgramNameStrings();

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNameStrings)
};