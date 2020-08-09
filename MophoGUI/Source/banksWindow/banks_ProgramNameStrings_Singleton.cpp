#include "banks_ProgramNameStrings_Singleton.h"

#include "banks_PluginProgramBanks_Singleton.h"



ProgramNameStrings::ProgramNameStrings() :
	bank1ProgramNames{ "bank1ProgramNames" },
	bank2ProgramNames{ "bank2ProgramNames" },
	bank3ProgramNames{ "bank3ProgramNames" }
{
	fillAllValueTreesWithDefaultProgramNames();
}

void ProgramNameStrings::fillAllValueTreesWithDefaultProgramNames() {
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

ProgramNameStrings::~ProgramNameStrings() {
}

ProgramNameStrings& ProgramNameStrings::get() noexcept {
	static ProgramNameStrings programNameStrings;
	return programNameStrings;
}

void ProgramNameStrings::resetAllProgramNameStringsToFactoryDefaults() {
	fillAllValueTreesWithDefaultProgramNames();
}

const String ProgramNameStrings::getNameForProgramInBankSlot(uint8 bank, uint8 programSlot) {
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

void ProgramNameStrings::storeProgramNameInBankSlot(uint8 bank, uint8 programSlot) {
	auto& programBanks{ PluginProgramBanks::get() };
	auto programName{ programBanks.getProgramNameFromDataStoredInBankSlot(bank, programSlot) };
	switch (bank) {
	case 0:
		bank1ProgramNames.setProperty("pgm" + (String)programSlot + "Name", programName, nullptr);
		break;
	case 1:
		bank2ProgramNames.setProperty("pgm" + (String)programSlot + "Name", programName, nullptr);
		break;
	case 2:
		bank3ProgramNames.setProperty("pgm" + (String)programSlot + "Name", programName, nullptr);
		break;
	};
}