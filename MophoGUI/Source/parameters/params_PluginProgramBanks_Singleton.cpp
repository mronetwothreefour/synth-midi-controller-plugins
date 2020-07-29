#include "params_PluginProgramBanks_Singleton.h"



PluginProgramBanks::PluginProgramBanks() :
	programBank1{ "pgmBank1" },
	programBank2{ "pgmBank2" },
	programBank3{ "pgmBank3" }
{
	resetAllProgramBanksToFactoryDefaults();
}

int PluginProgramBanks::programSlotOutOfRange() {
	return programBank1.getNumProperties();
}

void PluginProgramBanks::resetAllProgramBanksToFactoryDefaults() {
	fillProgramBanksWithFactoryDefaultPrograms();
}

void PluginProgramBanks::fillProgramBanksWithFactoryDefaultPrograms() {
	auto& factoryBanks{ FactoryProgramBanks::get() };
	for (uint8 programSlot = 0; programSlot != factoryBanks.programSlotOutOfRange(); ++programSlot) {
		programBank1.setProperty("pgm" + (String)programSlot, factoryBanks.getProgramStringFromBankSlot(0, programSlot), nullptr);
		programBank2.setProperty("pgm" + (String)programSlot, factoryBanks.getProgramStringFromBankSlot(1, programSlot), nullptr);
		programBank3.setProperty("pgm" + (String)programSlot, factoryBanks.getProgramStringFromBankSlot(2, programSlot), nullptr);
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
}

const String PluginProgramBanks::getNameForProgramStoredInBankSlot(uint8 bank, uint8 slot) {
	jassert(bank < 3);
	jassert(slot < 128);
	const auto& hexString{ getProgramHexStringFromBankSlot(bank, slot) };
	auto programDataBuffer{ convertProgramHexStringToDataBuffer(hexString) };
	String programName{ extractProgramNameFromDataBuffer(programDataBuffer) };
	return programName;
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

const uint8* PluginProgramBanks::convertProgramHexStringToDataBuffer(const String& dataString) {
	static uint8 programData[293]{};
	for (auto i = 0; i != 460; i += 2) {
		auto hexValueString{ dataString.substring(i, i + 2) };
		programData[i / 2] = (uint8)hexValueString.getHexValue32();
	}
	return programData;
}

const String PluginProgramBanks::extractProgramNameFromDataBuffer(const uint8* data) {
	String programName{ "" };
	auto firstCharByte{ 211 };
	auto lastCharByte{ 229 };
	auto ignoredPackByte1{ 216 };
	auto ignoredPackByte2{ 224 };
	for (auto byte = firstCharByte; byte <= lastCharByte; byte += 1) {
		if (byte != ignoredPackByte1 && byte != ignoredPackByte2)
			programName += (String)std::string(1, (char)*(data + byte));
	}
	return programName;
}
