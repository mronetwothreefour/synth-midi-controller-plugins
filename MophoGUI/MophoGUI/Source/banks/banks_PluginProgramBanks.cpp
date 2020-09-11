#include "banks_PluginProgramBanks.h"

#include "banks_FactoryProgamBanks_Singleton.h"
#include "../params/params_Identifiers.h"



PluginProgramBanks::PluginProgramBanks() :
	programBank1{ "pgmBank1" },
	programBank2{ "pgmBank2" },
	programBank3{ "pgmBank3" }
{
	resetAllProgramBanksToFactoryDefaults();
}

void PluginProgramBanks::resetAllProgramBanksToFactoryDefaults() {
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

int PluginProgramBanks::programSlotOutOfRange() {
	return programBank1.getNumProperties();
}

const String PluginProgramBanks::getProgramDataHexStringFromBankSlot(uint8 bank, uint8 slot) const {
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

void PluginProgramBanks::storeProgramDataHexStringInBankSlot(String hexString, uint8 bank, uint8 slot) {
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

XmlElement* PluginProgramBanks::getStateXml() {
	auto pluginProgramBanksStateXml{ std::make_unique<XmlElement>(ID::state_PluginProgramBanks) };
	auto programBank1StateXml{ programBank1.createXml() };
	auto programBank2StateXml{ programBank2.createXml() };
	auto programBank3StateXml{ programBank3.createXml() };
	programBank1StateXml->setTagName(ID::state_ProgramBank1);
	programBank2StateXml->setTagName(ID::state_ProgramBank2);
	programBank3StateXml->setTagName(ID::state_ProgramBank3);
	pluginProgramBanksStateXml->addChildElement(programBank1StateXml.release());
	pluginProgramBanksStateXml->addChildElement(programBank2StateXml.release());
	pluginProgramBanksStateXml->addChildElement(programBank3StateXml.release());
	return pluginProgramBanksStateXml.release();
}

void PluginProgramBanks::replaceState(const ValueTree& newState) {
	programBank1.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_ProgramBank1), nullptr);
	programBank2.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_ProgramBank2), nullptr);
	programBank3.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_ProgramBank3), nullptr);
}

PluginProgramBanks::~PluginProgramBanks() {
}
