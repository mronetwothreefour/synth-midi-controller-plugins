#include "banks_ProgramNameStrings.h"

#include "banks_ConvertRawProgramDataFormat.h"
#include "banks_FactoryProgamBanks_Singleton.h"



ProgramNameStrings::ProgramNameStrings() :
	bank1ProgramNames{ "bank1ProgramNames" },
	bank2ProgramNames{ "bank2ProgramNames" },
	bank3ProgramNames{ "bank3ProgramNames" }
{
	resetAllProgramNameStringsToFactoryDefaults();
}

void ProgramNameStrings::resetAllProgramNameStringsToFactoryDefaults() {
	auto& factoryBanks{ FactoryProgramBanks::get() };
	for (uint8 programSlot = 0; programSlot != factoryBanks.programSlotOutOfRange(); ++programSlot) {
		auto bank1ProgramHexString{factoryBanks.getFactoryBank1()[programSlot]};
		auto bank2ProgramHexString{factoryBanks.getFactoryBank2()[programSlot]};
		auto bank3ProgramHexString{factoryBanks.getFactoryBank3()[programSlot]};
		auto bank1ProgramDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(bank1ProgramHexString) };
		auto bank2ProgramDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(bank2ProgramHexString) };
		auto bank3ProgramDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(bank3ProgramHexString) };
		auto bank1ProgramName{ extractProgramNameFromDataVector(bank1ProgramDataVector) };
		auto bank2ProgramName{ extractProgramNameFromDataVector(bank2ProgramDataVector) };
		auto bank3ProgramName{ extractProgramNameFromDataVector(bank3ProgramDataVector) };
		bank1ProgramNames.setProperty("pgm" + (String)programSlot + "Name", bank1ProgramName, nullptr);
		bank2ProgramNames.setProperty("pgm" + (String)programSlot + "Name", bank2ProgramName, nullptr);
		bank3ProgramNames.setProperty("pgm" + (String)programSlot + "Name", bank3ProgramName, nullptr);
	}
}

const String ProgramNameStrings::extractProgramNameFromDataVector(const std::vector<uint8>& dataVector) {
	String programName{ "" };
	auto firstCharByte{ 211 };
	auto lastCharByte{ 229 };
	auto ignoredPackByte1{ 216 };
	auto ignoredPackByte2{ 224 };
	auto data{ dataVector.data() };
	for (auto byte = firstCharByte; byte <= lastCharByte; byte += 1) {
		if (byte != ignoredPackByte1 && byte != ignoredPackByte2)
			programName += (String)std::string(1, (char)*(data + byte));
	}
	return programName;
}

const String ProgramNameStrings::nameOfProgramInBankSlot(uint8 bank, uint8 slot) {
	String programName;
	switch (bank) {
	case 0:
		programName = bank1ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	case 1:
		programName = bank2ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	case 2:
		programName = bank3ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	};
	return programName;
}

void ProgramNameStrings::storeNameOfProgramInBankSlot(const String programName, uint8 bank, uint8 slot) {
	switch (bank) {
	case 0:
		bank1ProgramNames.setProperty("pgm" + (String)slot + "Name", programName, nullptr);
		break;
	case 1:
		bank2ProgramNames.setProperty("pgm" + (String)slot + "Name", programName, nullptr);
		break;
	case 2:
		bank3ProgramNames.setProperty("pgm" + (String)slot + "Name", programName, nullptr);
		break;
	};
}

ProgramNameStrings::~ProgramNameStrings() {
}
