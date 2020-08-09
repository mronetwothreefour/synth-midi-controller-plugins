#pragma once

#include <JuceHeader.h>



class ProgramNameStrings
{
	ValueTree bank1ProgramNames;
	ValueTree bank2ProgramNames;
	ValueTree bank3ProgramNames;

	ProgramNameStrings();
	void fillAllValueTreesWithDefaultProgramNames();
	~ProgramNameStrings();

public:
	ProgramNameStrings(ProgramNameStrings&&) = delete;
	ProgramNameStrings& operator=(ProgramNameStrings&&) = delete;

	static ProgramNameStrings& get() noexcept;
	void resetAllProgramNameStringsToFactoryDefaults();
	const String getNameForProgramInBankSlot(uint8 bank, uint8 programSlot);
	void storeProgramNameInBankSlot(uint8 bank, uint8 programSlot);

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNameStrings)
};