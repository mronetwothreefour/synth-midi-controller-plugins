#include "banks_PluginProgramBanks_Singleton.h"

#include "banks_FactoryProgamBanks_Singleton.h"
#include "banks_ProgramNameStrings_Singleton.h"



PluginProgramBanks::PluginProgramBanks() :
	programBank1{ "pgmBank1" },
	programBank2{ "pgmBank2" },
	programBank3{ "pgmBank3" }
{
}

int PluginProgramBanks::programSlotOutOfRange() {
	return programBank1.getNumProperties();
}

void PluginProgramBanks::resetAllProgramBanksToFactoryDefaults() {
	fillProgramBanksWithFactoryDefaultPrograms();
}

void PluginProgramBanks::fillProgramBanksWithFactoryDefaultPrograms() {
	auto& factoryBanks{ FactoryProgramBanks::get() };
	auto& factoryBank1{ factoryBanks.getFactoryBank1() };
	auto& factoryBank2{ factoryBanks.getFactoryBank2() };
	auto& factoryBank3{ factoryBanks.getFactoryBank3() };
	for (uint8 programSlot = 0; programSlot != factoryBanks.programSlotOutOfRange(); ++programSlot) {
		programBank1.setProperty("pgm" + (String)programSlot, factoryBank1[programSlot], nullptr);
		programBank2.setProperty("pgm" + (String)programSlot, factoryBank2[programSlot], nullptr);
		programBank3.setProperty("pgm" + (String)programSlot, factoryBank3[programSlot], nullptr);
	}
}

PluginProgramBanks::~PluginProgramBanks() {
}

PluginProgramBanks& PluginProgramBanks::get() noexcept {
	static PluginProgramBanks pluginProgramBanks;
	return pluginProgramBanks;
}

void PluginProgramBanks::storeProgramDataInBankSlot(const uint8* data, uint8 bank, uint8 slot) {
	storeProgramDataAsHexStringInBankSlot(data, bank, slot);
}

void PluginProgramBanks::storeProgramDataAsHexStringInBankSlot(const uint8* data, uint8 bank, uint8 slot) {
	jassert(bank < 3);
	jassert(slot < 128);
	auto hexString{ String::toHexString(data, 293, 0) };
	switch (bank)
	{
	case 0:
		programBank1.setProperty("pgm" + (String)slot, hexString, nullptr);
		break;
	case 1:
		programBank2.setProperty("pgm" + (String)slot, hexString, nullptr);
		break;
	case 2:
		programBank3.setProperty("pgm" + (String)slot, hexString, nullptr);
		break;
	default:
		return;
	}
	ProgramNameStrings::get().storeProgramNameInBankSlot(bank, slot);
}

const String PluginProgramBanks::getProgramNameFromDataStoredInBankSlot(uint8 bank, uint8 slot) {
	jassert(bank < 3);
	jassert(slot < 128);
	auto programDataBuffer{ getProgramDataStoredInBankSlot(bank, slot) };
	String programName{ extractProgramNameFromDataVector(programDataBuffer) };
	return programName;
}

const std::vector<uint8> PluginProgramBanks::getProgramDataStoredInBankSlot(uint8 bank, uint8 slot) {
	jassert(bank < 3);
	jassert(slot < 128);
	const auto& hexString{ getProgramHexStringFromBankSlot(bank, slot) };
	auto programDataBuffer{ convertProgramHexStringToDataVector(hexString) };
	return programDataBuffer;
}


const String PluginProgramBanks::getProgramHexStringFromBankSlot(uint8 bank, uint8 slot) const {
	jassert(bank < 3);
	jassert(slot < 128);
	switch (bank)
	{
	case 0:
		return programBank1.getProperty("pgm" + (String)slot);
	case 1:
		return programBank2.getProperty("pgm" + (String)slot);
	case 2:
		return programBank3.getProperty("pgm" + (String)slot);
	default:
		return {};
	}
}

const std::vector<uint8> PluginProgramBanks::convertProgramHexStringToDataVector(const String& dataString) {
	std::vector<uint8> programData;
	for (auto i = 0; i != dataString.length(); i += 2) {
		auto hexValueString{ dataString.substring(i, i + 2) };
		programData.push_back((uint8)hexValueString.getHexValue32());
	}
	return programData;
}

const String PluginProgramBanks::extractProgramNameFromDataVector(std::vector<uint8> dataVector) {
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
