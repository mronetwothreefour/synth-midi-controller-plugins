#include "banks_ProgramBanks.h"

#include "banks_FactoryProgamDataHexStrings_Singleton.h"
#include "../params/params_Identifiers.h"



ProgramBanks::ProgramBanks() :
	factoryBank1{ "factoryBank1" },
	factoryBank2{ "factoryBank2" },
	factoryBank3{ "factoryBank3" },
	customBank1{ "customBank1" },
	customBank2{ "customBank2" },
	customBank3{ "customBank3" }
{
	fillAllProgramDataBanks();
}

void ProgramBanks::fillAllProgramDataBanks() {
	auto& factoryDataHexStrings{ FactoryProgramDataHexStrings::get() };
	auto& factoryProgramDataBank1{ factoryDataHexStrings.getBank1() };
	auto& factoryProgramDataBank2{ factoryDataHexStrings.getBank2() };
	auto& factoryProgramDataBank3{ factoryDataHexStrings.getBank3() };
	for (uint8 programSlot = 0; programSlot != factoryDataHexStrings.programSlotOutOfRange(); ++programSlot) {
		factoryBank1.setProperty("pgm" + (String)programSlot, factoryProgramDataBank1[programSlot], nullptr);
		factoryBank2.setProperty("pgm" + (String)programSlot, factoryProgramDataBank2[programSlot], nullptr);
		factoryBank3.setProperty("pgm" + (String)programSlot, factoryProgramDataBank3[programSlot], nullptr);
		customBank1.setProperty("pgm" + (String)programSlot, basicPatchDataHexString, nullptr);
		customBank2.setProperty("pgm" + (String)programSlot, basicPatchDataHexString, nullptr);
		customBank3.setProperty("pgm" + (String)programSlot, basicPatchDataHexString, nullptr);
	}
}

int ProgramBanks::programSlotOutOfRange() {
	return factoryBank1.getNumProperties();
}

const String ProgramBanks::getProgramDataHexStringFromBankSlot(ProgramBank bank, uint8 slot) const {
	jassert(slot < 128);
	switch (bank)
	{
	case ProgramBank::factory1:
		return factoryBank1.getProperty("pgm" + (String)slot);
	case ProgramBank::factory2:
		return factoryBank2.getProperty("pgm" + (String)slot);
	case ProgramBank::factory3:
		return factoryBank3.getProperty("pgm" + (String)slot);
	case ProgramBank::custom1:
		return customBank1.getProperty("pgm" + (String)slot);
	case ProgramBank::custom2:
		return customBank2.getProperty("pgm" + (String)slot);
	case ProgramBank::custom3:
		return customBank3.getProperty("pgm" + (String)slot);
	default:
		return {};
	}
}

void ProgramBanks::storeProgramDataHexStringInCustomBankSlot(String hexString, ProgramBank bank, uint8 slot) {
	jassert(bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3);
	jassert(slot < 128);
	switch (bank)
	{
	case ProgramBank::custom1:
		customBank1.setProperty("pgm" + (String)slot, hexString, nullptr);
		break;
	case ProgramBank::custom2:
		customBank2.setProperty("pgm" + (String)slot, hexString, nullptr);
		break;
	case ProgramBank::custom3:
		customBank3.setProperty("pgm" + (String)slot, hexString, nullptr);
		break;
	default:
		return;
	}
}

XmlElement* ProgramBanks::getStateXml() {
	auto pluginProgramBanksStateXml{ std::make_unique<XmlElement>(ID::state_ProgramBanks) };
	auto factoryBank1StateXml{ factoryBank1.createXml() };
	auto factoryBank2StateXml{ factoryBank2.createXml() };
	auto factoryBank3StateXml{ factoryBank3.createXml() };
	auto customBank1StateXml{ customBank1.createXml() };
	auto customBank2StateXml{ customBank2.createXml() };
	auto customBank3StateXml{ customBank3.createXml() };
	factoryBank1StateXml->setTagName(ID::state_FactoryProgramBank1);
	factoryBank2StateXml->setTagName(ID::state_FactoryProgramBank2);
	factoryBank3StateXml->setTagName(ID::state_FactoryProgramBank3);
	customBank1StateXml->setTagName(ID::state_CustomProgramBank1);
	customBank2StateXml->setTagName(ID::state_CustomProgramBank2);
	customBank3StateXml->setTagName(ID::state_CustomProgramBank3);
	pluginProgramBanksStateXml->addChildElement(factoryBank1StateXml.release());
	pluginProgramBanksStateXml->addChildElement(factoryBank2StateXml.release());
	pluginProgramBanksStateXml->addChildElement(factoryBank3StateXml.release());
	pluginProgramBanksStateXml->addChildElement(customBank1StateXml.release());
	pluginProgramBanksStateXml->addChildElement(customBank2StateXml.release());
	pluginProgramBanksStateXml->addChildElement(customBank3StateXml.release());
	return pluginProgramBanksStateXml.release();
}

void ProgramBanks::replaceState(const ValueTree& newState) {
	factoryBank1.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryProgramBank1), nullptr);
	factoryBank2.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryProgramBank2), nullptr);
	factoryBank3.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryProgramBank3), nullptr);
	customBank1.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomProgramBank1), nullptr);
	customBank2.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomProgramBank2), nullptr);
	customBank3.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomProgramBank3), nullptr);
}

ProgramBanks::~ProgramBanks() {
}
