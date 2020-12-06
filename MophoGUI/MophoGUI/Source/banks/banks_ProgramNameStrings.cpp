#include "banks_ProgramNameStrings.h"

#include "banks_ConvertRawProgramDataFormat.h"
#include "banks_FactoryProgamDataHexStrings_Singleton.h"
#include "../params/params_Identifiers.h"



ProgramNameStrings::ProgramNameStrings() :
	bank1ProgramNames{ "bank1ProgramNames" },
	bank2ProgramNames{ "bank2ProgramNames" },
	bank3ProgramNames{ "bank3ProgramNames" }
{
	resetAllProgramNameStringsToFactoryDefaults();
}

void ProgramNameStrings::resetAllProgramNameStringsToFactoryDefaults() {
	auto& factoryDataHexStrings{ FactoryProgramDataHexStrings::get() };
	for (uint8 programSlot = 0; programSlot != factoryDataHexStrings.programSlotOutOfRange(); ++programSlot) {
		auto bank1ProgramHexString{factoryDataHexStrings.getBank1()[programSlot]};
		auto bank2ProgramHexString{factoryDataHexStrings.getBank2()[programSlot]};
		auto bank3ProgramHexString{factoryDataHexStrings.getBank3()[programSlot]};
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

XmlElement* ProgramNameStrings::getStateXml() {
	auto programNameStringsStateXml{ std::make_unique<XmlElement>(ID::state_ProgramNameStrings) };
	auto bank1ProgramNamesStateXml{ bank1ProgramNames.createXml() };
	auto bank2ProgramNamesStateXml{ bank2ProgramNames.createXml() };
	auto bank3ProgramNamesStateXml{ bank3ProgramNames.createXml() };
	bank1ProgramNamesStateXml->setTagName(ID::state_FactoryBank1ProgramNames);
	bank2ProgramNamesStateXml->setTagName(ID::state_FactoryBank2ProgramNames);
	bank3ProgramNamesStateXml->setTagName(ID::state_FactoryBank3ProgramNames);
	programNameStringsStateXml->addChildElement(bank1ProgramNamesStateXml.release());
	programNameStringsStateXml->addChildElement(bank2ProgramNamesStateXml.release());
	programNameStringsStateXml->addChildElement(bank3ProgramNamesStateXml.release());
	return programNameStringsStateXml.release();
}

void ProgramNameStrings::replaceState(const ValueTree& newState) {
	bank1ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryBank1ProgramNames), nullptr);
	bank2ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryBank2ProgramNames), nullptr);
	bank3ProgramNames.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_FactoryBank3ProgramNames), nullptr);
}

ProgramNameStrings::~ProgramNameStrings() {
}
