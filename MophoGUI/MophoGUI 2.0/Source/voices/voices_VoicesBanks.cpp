#include "voices_VoicesBanks.h"

#include "voices_Constants.h"
#include "voices_FactoryVoiceDataHexStrings_Singleton.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"

using namespace constants;



ProgramBanks::ProgramBanks() :
	customBank1ProgramDataHexStrings{ ID::bank_custom1_VoiceDataHexStrings },
	customBank2ProgramDataHexStrings{ ID::bank_custom2_VoiceDataHexStrings },
	customBank3ProgramDataHexStrings{ ID::bank_custom3_VoiceDataHexStrings },
	factoryBank1ProgramNameStrings{ ID::bank_factory1_VoiceNameStrings },
	factoryBank2ProgramNameStrings{ ID::bank_factory2_VoiceNameStrings },
	factoryBank3ProgramNameStrings{ ID::bank_factory3_VoiceNameStrings },
	customBank1ProgramNameStrings{ ID::bank_custom1_VoiceNameStrings },
	customBank2ProgramNameStrings{ ID::bank_custom2_VoiceNameStrings },
	customBank3ProgramNameStrings{ ID::bank_custom3_VoiceNameStrings }
{
	fillAllCustomProgramDataBanks();
	fillAllProgramNameBanks();
	customBank1ProgramDataHexStrings.addListener(this);
	customBank2ProgramDataHexStrings.addListener(this);
	customBank3ProgramDataHexStrings.addListener(this);
}

void ProgramBanks::fillAllCustomProgramDataBanks() {
	for (uint8 programSlot = 0; programSlot != banks::numberOfSlotsInBank; ++programSlot) {
		customBank1ProgramDataHexStrings.setProperty("pgm" + (String)programSlot, banks::basicVoiceDataHexString, nullptr);
		customBank2ProgramDataHexStrings.setProperty("pgm" + (String)programSlot, banks::basicVoiceDataHexString, nullptr);
		customBank3ProgramDataHexStrings.setProperty("pgm" + (String)programSlot, banks::basicVoiceDataHexString, nullptr);
	}
}

void ProgramBanks::fillAllProgramNameBanks() {
	String programName;
	String programDataString;
	for (uint8 programSlot = 0; programSlot != banks::numberOfSlotsInBank; ++programSlot) {
		programDataString = getProgramDataHexStringFromBankSlot(ProgramBank::factory1, programSlot);
		programName = extractProgramNameFromDataVector(RawDataTools::convertHexStringToDataVector(programDataString));
		factoryBank1ProgramNameStrings.setProperty("pgm" + (String)programSlot, programName, nullptr);
		programDataString = getProgramDataHexStringFromBankSlot(ProgramBank::factory2, programSlot);
		programName = extractProgramNameFromDataVector(RawDataTools::convertHexStringToDataVector(programDataString));
		factoryBank2ProgramNameStrings.setProperty("pgm" + (String)programSlot, programName, nullptr);
		programDataString = getProgramDataHexStringFromBankSlot(ProgramBank::factory3, programSlot);
		programName = extractProgramNameFromDataVector(RawDataTools::convertHexStringToDataVector(programDataString));
		factoryBank3ProgramNameStrings.setProperty("pgm" + (String)programSlot, programName, nullptr);
		customBank1ProgramNameStrings.setProperty("pgm" + (String)programSlot, banks::basicVoiceNameString, nullptr);
		customBank2ProgramNameStrings.setProperty("pgm" + (String)programSlot, banks::basicVoiceNameString, nullptr);
		customBank3ProgramNameStrings.setProperty("pgm" + (String)programSlot, banks::basicVoiceNameString, nullptr);
	}
}

const String ProgramBanks::nameOfProgramInBankSlot(ProgramBank bank, uint8 slot) {
	jassert(slot < banks::numberOfSlotsInBank);
	switch (bank) {
	case ProgramBank::factory1:
		return factoryBank1ProgramNameStrings.getProperty("pgm" + (String)slot);
	case ProgramBank::factory2:
		return factoryBank2ProgramNameStrings.getProperty("pgm" + (String)slot);
	case ProgramBank::factory3:
		return factoryBank3ProgramNameStrings.getProperty("pgm" + (String)slot);
	case ProgramBank::custom1:
		return customBank1ProgramNameStrings.getProperty("pgm" + (String)slot);
	case ProgramBank::custom2:
		return customBank2ProgramNameStrings.getProperty("pgm" + (String)slot);
	case ProgramBank::custom3:
		return customBank3ProgramNameStrings.getProperty("pgm" + (String)slot);
	default:
		return "error";
	};
}

const String ProgramBanks::getProgramDataHexStringFromBankSlot(ProgramBank bank, uint8 slot) const {
	jassert(slot < banks::numberOfSlotsInBank);
	auto& factoryDataHexStrings{ FactoryProgramDataHexStrings::get() };
	switch (bank)
	{
	case ProgramBank::factory1:
		return factoryDataHexStrings.getBank1()[slot];
	case ProgramBank::factory2:
		return factoryDataHexStrings.getBank2()[slot];
	case ProgramBank::factory3:
		return factoryDataHexStrings.getBank3()[slot];
	case ProgramBank::custom1:
		return customBank1ProgramDataHexStrings.getProperty("pgm" + (String)slot);
	case ProgramBank::custom2:
		return customBank2ProgramDataHexStrings.getProperty("pgm" + (String)slot);
	case ProgramBank::custom3:
		return customBank3ProgramDataHexStrings.getProperty("pgm" + (String)slot);
	default:
		return "error";
	}
}

const String ProgramBanks::extractProgramNameFromDataVector(const std::vector<uint8>& dataVector) {
	String programName{ "" };
	auto data{ dataVector.data() };
	for (auto byte = banks::firstVoiceNameCharByte; byte <= banks::lastVoiceNameCharByte; ++byte) {
		if (byte != banks::ignoredVoiceNamePackByte1 && byte != banks::ignoredVoiceNamePackByte2)
			programName += (String)std::string(1, (char)*(data + byte));
	}
	return programName;
}

void ProgramBanks::storeProgramDataHexStringInCustomBankSlot(String programDataHexString, ProgramBank bank, uint8 slot) {
	jassert(bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3);
	jassert(slot < banks::numberOfSlotsInBank);
	switch (bank)
	{
	case ProgramBank::custom1:
		customBank1ProgramDataHexStrings.setProperty("pgm" + (String)slot, programDataHexString, nullptr);
		break;
	case ProgramBank::custom2:
		customBank2ProgramDataHexStrings.setProperty("pgm" + (String)slot, programDataHexString, nullptr);
		break;
	case ProgramBank::custom3:
		customBank3ProgramDataHexStrings.setProperty("pgm" + (String)slot, programDataHexString, nullptr);
		break;
	default:
		break;
	}
}

void ProgramBanks::addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, ProgramBank bank) {
	jassert(bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3);
	switch (bank)
	{
	case ProgramBank::custom1:
		customBank1ProgramNameStrings.addListener(listener);
		break;
	case ProgramBank::custom2:
		customBank2ProgramNameStrings.addListener(listener);
		break;
	case ProgramBank::custom3:
		customBank3ProgramNameStrings.addListener(listener);
		break;
	default:
		break;
	}
}

void ProgramBanks::removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, ProgramBank bank) {
	jassert(bank == ProgramBank::custom1 || bank == ProgramBank::custom2 || bank == ProgramBank::custom3);
	switch (bank)
	{
	case ProgramBank::custom1:
		customBank1ProgramNameStrings.removeListener(listener);
		break;
	case ProgramBank::custom2:
		customBank2ProgramNameStrings.removeListener(listener);
		break;
	case ProgramBank::custom3:
		customBank3ProgramNameStrings.removeListener(listener);
		break;
	default:
		break;
	}
}

void ProgramBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("pgm", false, true) };
	auto slot{ (uint8)slotString.getIntValue() };
	if (tree.hasType(ID::bank_custom1_VoiceDataHexStrings)) {
		auto programDataHexString{ getProgramDataHexStringFromBankSlot(ProgramBank::custom1, slot) };
		auto programName{ extractProgramNameFromDataVector(RawDataTools::convertHexStringToDataVector(programDataHexString)) };
		customBank1ProgramNameStrings.setProperty(property, programName, nullptr);
	}
	if (tree.hasType(ID::bank_custom2_VoiceDataHexStrings)) {
		auto programDataHexString{ getProgramDataHexStringFromBankSlot(ProgramBank::custom2, slot) };
		auto programName{ extractProgramNameFromDataVector(RawDataTools::convertHexStringToDataVector(programDataHexString)) };
		customBank2ProgramNameStrings.setProperty(property, programName, nullptr);
	}
	if (tree.hasType(ID::bank_custom3_VoiceDataHexStrings)) {
		auto programDataHexString{ getProgramDataHexStringFromBankSlot(ProgramBank::custom3, slot) };
		auto programName{ extractProgramNameFromDataVector(RawDataTools::convertHexStringToDataVector(programDataHexString)) };
		customBank3ProgramNameStrings.setProperty(property, programName, nullptr);
	}
}

XmlElement* ProgramBanks::getStateXml() {
	auto customProgramBanksStateXml{ std::make_unique<XmlElement>(ID::state_VoicesBanks) };
	auto customBank1StateXml{ customBank1ProgramDataHexStrings.createXml() };
	auto customBank2StateXml{ customBank2ProgramDataHexStrings.createXml() };
	auto customBank3StateXml{ customBank3ProgramDataHexStrings.createXml() };
	customBank1StateXml->setTagName(ID::state_CustomVoicesBank1);
	customBank2StateXml->setTagName(ID::state_CustomVoicesBank2);
	customBank3StateXml->setTagName(ID::state_CustomVoicesBank3);
	customProgramBanksStateXml->addChildElement(customBank1StateXml.release());
	customProgramBanksStateXml->addChildElement(customBank2StateXml.release());
	customProgramBanksStateXml->addChildElement(customBank3StateXml.release());
	return customProgramBanksStateXml.release();
}

void ProgramBanks::replaceState(const ValueTree& newState) {
	customBank1ProgramDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank1), nullptr);
	customBank2ProgramDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank2), nullptr);
	customBank3ProgramDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank3), nullptr);
}

ProgramBanks::~ProgramBanks() {
	customBank1ProgramDataHexStrings.removeListener(this);
	customBank2ProgramDataHexStrings.removeListener(this);
	customBank3ProgramDataHexStrings.removeListener(this);
}
