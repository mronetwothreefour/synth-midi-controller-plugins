#pragma once

#include <JuceHeader.h>

#include "banks_PluginProgramBanks_Singleton.h"



class ProgramNameStrings
{
	ValueTree bank1ProgramNames;
	ValueTree bank2ProgramNames;
	ValueTree bank3ProgramNames;

	ProgramNameStrings() :
		bank1ProgramNames{ "bank1ProgramNames" },
		bank2ProgramNames{ "bank2ProgramNames" },
		bank3ProgramNames{ "bank3ProgramNames" }
	{
		fillAllValueTreesWithDefaultProgramNames();
	}

	void fillAllValueTreesWithDefaultProgramNames() {
		auto& programBanks{ PluginProgramBanks::get() };
		for (uint8 programSlot = 0; programSlot != programBanks.programSlotOutOfRange(); ++programSlot) {
			auto bank1Name(programBanks.getProgramNameFromDataStoredInBankSlot((uint8)0, programSlot));
			bank1ProgramNames.setProperty("pgm" + (String)programSlot + "Name", bank1Name, nullptr);
			auto bank2Name(programBanks.getProgramNameFromDataStoredInBankSlot((uint8)1, programSlot));
			bank2ProgramNames.setProperty("pgm" + (String)programSlot + "Name", bank2Name, nullptr);
			auto bank3Name(programBanks.getProgramNameFromDataStoredInBankSlot((uint8)2, programSlot));
			bank3ProgramNames.setProperty("pgm" + (String)programSlot + "Name", bank3Name, nullptr);
		}
	}

	~ProgramNameStrings() {
	}

public:
	ProgramNameStrings(ProgramNameStrings&&) = delete;
	ProgramNameStrings& operator=(ProgramNameStrings&&) = delete;

	static ProgramNameStrings& get() noexcept {
		static ProgramNameStrings programNameStrings;
		return programNameStrings;
	}

	const String getNameForProgramInBankSlot(uint8 bank, uint8 programSlot) {
		String programName;
		switch (bank) {
		case 0:
			programName = bank1ProgramNames.getProperty("pgm" + (String)programSlot + "Name");
			break;
		case 1:
			programName = bank2ProgramNames.getProperty("pgm" + (String)programSlot + "Name");
			break;
		case 2:
			programName = bank3ProgramNames.getProperty("pgm" + (String)programSlot + "Name");
			break;
		};
		return programName;
	}

private:
	//==============================================================================
	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ProgramNameStrings)
};