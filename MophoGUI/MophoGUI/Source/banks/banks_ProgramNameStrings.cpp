#include "banks_ProgramNameStrings.h"

#include "banks_ConvertRawProgramDataFormat.h"
#include "banks_FactoryProgamDataHexStrings_Singleton.h"
#include "../params/params_Identifiers.h"



ProgramNameStrings::ProgramNameStrings() :
	factoryBank1ProgramNames{ "factoryBank1ProgramNames" },
	factoryBank2ProgramNames{ "factoryBank2ProgramNames" },
	factoryBank3ProgramNames{ "factoryBank3ProgramNames" },
	customBank1ProgramNames{ "customBank1ProgramNames" },
	customBank2ProgramNames{ "customBank2ProgramNames" },
	customBank3ProgramNames{ "customBank3ProgramNames" }
{
	initializeAllProgramNameStringsInAllBanks();
}

void ProgramNameStrings::initializeAllProgramNameStringsInAllBanks() {
	auto& factoryDataHexStrings{ FactoryProgramDataHexStrings::get() };
	for (uint8 programSlot = 0; programSlot != factoryDataHexStrings.programSlotOutOfRange(); ++programSlot) {
		auto factoryBank1ProgramHexString{factoryDataHexStrings.getBank1()[programSlot]};
		auto factoryBank2ProgramHexString{factoryDataHexStrings.getBank2()[programSlot]};
		auto factoryBank3ProgramHexString{factoryDataHexStrings.getBank3()[programSlot]};
		auto factoryBank1ProgramDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(factoryBank1ProgramHexString) };
		auto factoryBank2ProgramDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(factoryBank2ProgramHexString) };
		auto factoryBank3ProgramDataVector{ ConvertRawProgramDataFormat::hexStringToDataVector(factoryBank3ProgramHexString) };
		auto factoryBank1ProgramName{ extractProgramNameFromDataVector(factoryBank1ProgramDataVector) };
		auto factoryBank2ProgramName{ extractProgramNameFromDataVector(factoryBank2ProgramDataVector) };
		auto factoryBank3ProgramName{ extractProgramNameFromDataVector(factoryBank3ProgramDataVector) };
		factoryBank1ProgramNames.setProperty("pgm" + (String)programSlot + "Name", factoryBank1ProgramName, nullptr);
		factoryBank2ProgramNames.setProperty("pgm" + (String)programSlot + "Name", factoryBank2ProgramName, nullptr);
		factoryBank3ProgramNames.setProperty("pgm" + (String)programSlot + "Name", factoryBank3ProgramName, nullptr);
		customBank1ProgramNames.setProperty("pgm" + (String)programSlot + "Name", basicPatchNameString, nullptr);
		customBank2ProgramNames.setProperty("pgm" + (String)programSlot + "Name", basicPatchNameString, nullptr);
		customBank3ProgramNames.setProperty("pgm" + (String)programSlot + "Name", basicPatchNameString, nullptr);
	}
}

const String ProgramNameStrings::extractProgramNameFromDataVector(const std::vector<uint8>& dataVector) {
	String programName{ "" };
	auto firstCharByte{ 211 };
	auto lastCharByte{ 228 };
	auto ignoredPackByte1{ 216 };
	auto ignoredPackByte2{ 224 };
	auto data{ dataVector.data() };
	for (auto byte = firstCharByte; byte <= lastCharByte; byte += 1) {
		if (byte != ignoredPackByte1 && byte != ignoredPackByte2)
			programName += (String)std::string(1, (char)*(data + byte));
	}
	return programName;
}

const String ProgramNameStrings::nameOfProgramInFactoryBankSlot(uint8 bank, uint8 slot) {
	String programName;
	switch (bank) {
	case 0:
		programName = factoryBank1ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	case 1:
		programName = factoryBank2ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	case 2:
		programName = factoryBank3ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	};
	return programName;
}

const String ProgramNameStrings::nameOfProgramInCustomBankSlot(uint8 bank, uint8 slot) {
	String programName;
	switch (bank) {
	case 0:
		programName = customBank1ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	case 1:
		programName = customBank2ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	case 2:
		programName = customBank3ProgramNames.getProperty("pgm" + (String)slot + "Name");
		break;
	};
	return programName;
}

void ProgramNameStrings::storeNameOfProgramInCustomBankSlot(const String programName, uint8 bank, uint8 slot) {
	switch (bank) {
	case 0:
		customBank1ProgramNames.setProperty("pgm" + (String)slot + "Name", programName, nullptr);
		break;
	case 1:
		customBank2ProgramNames.setProperty("pgm" + (String)slot + "Name", programName, nullptr);
		break;
	case 2:
		customBank3ProgramNames.setProperty("pgm" + (String)slot + "Name", programName, nullptr);
		break;
	};
}

XmlElement* ProgramNameStrings::getStateXml() {
	auto programNameStringsStateXml{ std::make_unique<XmlElement>(ID::state_ProgramNameStrings) };
	auto factoryBank1ProgramNamesStateXml{ factoryBank1ProgramNames.createXml() };
	auto factoryBank2ProgramNamesStateXml{ factoryBank2ProgramNames.createXml() };
	auto factoryBank3ProgramNamesStateXml{ factoryBank3ProgramNames.createXml() };
	auto customBank1ProgramNamesStateXml{ customBank1ProgramNames.createXml() };
	auto customBank2ProgramNamesStateXml{ customBank2ProgramNames.createXml() };
	auto customBank3ProgramNamesStateXml{ customBank3ProgramNames.createXml() };
	factoryBank1ProgramNamesStateXml->setTagName(ID::state_FactoryBank1ProgramNames);
	factoryBank2ProgramNamesStateXml->setTagName(ID::state_FactoryBank2ProgramNames);
	factoryBank3ProgramNamesStateXml->setTagName(ID::state_FactoryBank3ProgramNames);
	customBank1ProgramNamesStateXml->setTagName(ID::state_CustomBank1ProgramNames);
	customBank2ProgramNamesStateXml->setTagName(ID::state_CustomBank2ProgramNames);
	customBank3ProgramNamesStateXml->setTagName(ID::state_CustomBank3ProgramNames);
	programNameStringsStateXml->addChildElement(factoryBank1ProgramNamesStateXml.release());
	programNameStringsStateXml->addChildElement(factoryBank2ProgramNamesStateXml.release());
	programNameStringsStateXml->addChildElement(factoryBank3ProgramNamesStateXml.release());
	programNameStringsStateXml->addChildElement(customBank1ProgramNamesStateXml.release());
	programNameStringsStateXml->addChildElement(customBank2ProgramNamesStateXml.release());
	programNameStringsStateXml->addChildElement(customBank3ProgramNamesStateXml.release());
	return programNameStringsStateXml.release();
}

void ProgramNameStrings::replaceState(const ValueTree& newState) {
	factoryBank1ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryBank1ProgramNames), nullptr);
	factoryBank2ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryBank2ProgramNames), nullptr);
	factoryBank3ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryBank3ProgramNames), nullptr);
	customBank1ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomBank1ProgramNames), nullptr);
	customBank2ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomBank2ProgramNames), nullptr);
	customBank3ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomBank3ProgramNames), nullptr);
}

