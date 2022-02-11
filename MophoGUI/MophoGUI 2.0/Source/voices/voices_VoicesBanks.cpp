#include "voices_VoicesBanks.h"

#include "voices_Constants.h"
#include "voices_FactoryVoiceDataHexStrings_Singleton.h"
#include "../midi/midi_RawDataTools.h"
#include "../params/params_Identifiers.h"

using namespace constants;



VoicesBanks::VoicesBanks() :
	customBank1VoiceDataHexStrings{ ID::bank_custom1_VoiceDataHexStrings },
	customBank2VoiceDataHexStrings{ ID::bank_custom2_VoiceDataHexStrings },
	customBank3VoiceDataHexStrings{ ID::bank_custom3_VoiceDataHexStrings },
	factoryBank1VoiceNameStrings{ ID::bank_factory1_VoiceNameStrings },
	factoryBank2VoiceNameStrings{ ID::bank_factory2_VoiceNameStrings },
	factoryBank3VoiceNameStrings{ ID::bank_factory3_VoiceNameStrings },
	customBank1VoiceNameStrings{ ID::bank_custom1_VoiceNameStrings },
	customBank2VoiceNameStrings{ ID::bank_custom2_VoiceNameStrings },
	customBank3VoiceNameStrings{ ID::bank_custom3_VoiceNameStrings }
{
	fillAllCustomVoiceDataBanks();
	fillAllVoiceNameBanks();
	customBank1VoiceDataHexStrings.addListener(this);
	customBank2VoiceDataHexStrings.addListener(this);
	customBank3VoiceDataHexStrings.addListener(this);
}

void VoicesBanks::fillAllCustomVoiceDataBanks() {
	for (uint8 voiceSlot = 0; voiceSlot != banks::numberOfSlotsInBank; ++voiceSlot) {
		customBank1VoiceDataHexStrings.setProperty("voice" + (String)voiceSlot, banks::basicVoiceDataHexString, nullptr);
		customBank2VoiceDataHexStrings.setProperty("voice" + (String)voiceSlot, banks::basicVoiceDataHexString, nullptr);
		customBank3VoiceDataHexStrings.setProperty("voice" + (String)voiceSlot, banks::basicVoiceDataHexString, nullptr);
	}
}

void VoicesBanks::fillAllVoiceNameBanks() {
	String voiceName;
	String voiceDataString;
	for (uint8 voiceSlot = 0; voiceSlot != banks::numberOfSlotsInBank; ++voiceSlot) {
		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::factory1, voiceSlot);
		voiceName = extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataString));
		factoryBank1VoiceNameStrings.setProperty("voice" + (String)voiceSlot, voiceName, nullptr);
		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::factory2, voiceSlot);
		voiceName = extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataString));
		factoryBank2VoiceNameStrings.setProperty("voice" + (String)voiceSlot, voiceName, nullptr);
		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::factory3, voiceSlot);
		voiceName = extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataString));
		factoryBank3VoiceNameStrings.setProperty("voice" + (String)voiceSlot, voiceName, nullptr);
		customBank1VoiceNameStrings.setProperty("voice" + (String)voiceSlot, banks::basicVoiceNameString, nullptr);
		customBank2VoiceNameStrings.setProperty("voice" + (String)voiceSlot, banks::basicVoiceNameString, nullptr);
		customBank3VoiceNameStrings.setProperty("voice" + (String)voiceSlot, banks::basicVoiceNameString, nullptr);
	}
}

const String VoicesBanks::nameOfVoiceInBankSlot(VoicesBank bank, uint8 slot) {
	jassert(slot < banks::numberOfSlotsInBank);
	switch (bank) {
	case VoicesBank::factory1:
		return factoryBank1VoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::factory2:
		return factoryBank2VoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::factory3:
		return factoryBank3VoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::custom1:
		return customBank1VoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::custom2:
		return customBank2VoiceNameStrings.getProperty("voice" + (String)slot);
	case VoicesBank::custom3:
		return customBank3VoiceNameStrings.getProperty("voice" + (String)slot);
	default:
		return "error";
	};
}

const String VoicesBanks::getVoiceDataHexStringFromBankSlot(VoicesBank bank, uint8 slot) const {
	jassert(slot < banks::numberOfSlotsInBank);
	auto& factoryDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	switch (bank)
	{
	case VoicesBank::factory1:
		return factoryDataHexStrings.getBank1()[slot];
	case VoicesBank::factory2:
		return factoryDataHexStrings.getBank2()[slot];
	case VoicesBank::factory3:
		return factoryDataHexStrings.getBank3()[slot];
	case VoicesBank::custom1:
		return customBank1VoiceDataHexStrings.getProperty("voice" + (String)slot);
	case VoicesBank::custom2:
		return customBank2VoiceDataHexStrings.getProperty("voice" + (String)slot);
	case VoicesBank::custom3:
		return customBank3VoiceDataHexStrings.getProperty("voice" + (String)slot);
	default:
		return "error";
	}
}

const String VoicesBanks::extractVoiceNameFromDataVector(const std::vector<uint8>& dataVector) {
	String voiceName{ "" };
	auto data{ dataVector.data() };
	for (auto byte = banks::firstVoiceNameCharByte; byte <= banks::lastVoiceNameCharByte; ++byte) {
		if (byte != banks::ignoredVoiceNamePackByte1 && byte != banks::ignoredVoiceNamePackByte2)
			voiceName += (String)std::string(1, (char)*(data + byte));
	}
	return voiceName;
}

void VoicesBanks::storeVoiceDataHexStringInCustomBankSlot(String voiceDataHexString, VoicesBank bank, uint8 slot) {
	jassert(bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3);
	jassert(slot < banks::numberOfSlotsInBank);
	switch (bank)
	{
	case VoicesBank::custom1:
		customBank1VoiceDataHexStrings.setProperty("voice" + (String)slot, voiceDataHexString, nullptr);
		break;
	case VoicesBank::custom2:
		customBank2VoiceDataHexStrings.setProperty("voice" + (String)slot, voiceDataHexString, nullptr);
		break;
	case VoicesBank::custom3:
		customBank3VoiceDataHexStrings.setProperty("voice" + (String)slot, voiceDataHexString, nullptr);
		break;
	default:
		break;
	}
}

void VoicesBanks::addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3);
	switch (bank)
	{
	case VoicesBank::custom1:
		customBank1VoiceNameStrings.addListener(listener);
		break;
	case VoicesBank::custom2:
		customBank2VoiceNameStrings.addListener(listener);
		break;
	case VoicesBank::custom3:
		customBank3VoiceNameStrings.addListener(listener);
		break;
	default:
		break;
	}
}

void VoicesBanks::removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank == VoicesBank::custom1 || bank == VoicesBank::custom2 || bank == VoicesBank::custom3);
	switch (bank)
	{
	case VoicesBank::custom1:
		customBank1VoiceNameStrings.removeListener(listener);
		break;
	case VoicesBank::custom2:
		customBank2VoiceNameStrings.removeListener(listener);
		break;
	case VoicesBank::custom3:
		customBank3VoiceNameStrings.removeListener(listener);
		break;
	default:
		break;
	}
}

void VoicesBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("voice", false, true) };
	auto slot{ (uint8)slotString.getIntValue() };
	if (tree.hasType(ID::bank_custom1_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom1, slot) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		customBank1VoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
	if (tree.hasType(ID::bank_custom2_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom2, slot) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		customBank2VoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
	if (tree.hasType(ID::bank_custom3_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom3, slot) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		customBank3VoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
}

XmlElement* VoicesBanks::getStateXml() {
	auto customVoicesBanksStateXml{ std::make_unique<XmlElement>(ID::state_VoicesBanks) };
	auto customBank1StateXml{ customBank1VoiceDataHexStrings.createXml() };
	auto customBank2StateXml{ customBank2VoiceDataHexStrings.createXml() };
	auto customBank3StateXml{ customBank3VoiceDataHexStrings.createXml() };
	customBank1StateXml->setTagName(ID::state_CustomVoicesBank1);
	customBank2StateXml->setTagName(ID::state_CustomVoicesBank2);
	customBank3StateXml->setTagName(ID::state_CustomVoicesBank3);
	customVoicesBanksStateXml->addChildElement(customBank1StateXml.release());
	customVoicesBanksStateXml->addChildElement(customBank2StateXml.release());
	customVoicesBanksStateXml->addChildElement(customBank3StateXml.release());
	return customVoicesBanksStateXml.release();
}

void VoicesBanks::replaceState(const ValueTree& newState) {
	customBank1VoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank1), nullptr);
	customBank2VoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank2), nullptr);
	customBank3VoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank3), nullptr);
}

VoicesBanks::~VoicesBanks() {
	customBank1VoiceDataHexStrings.removeListener(this);
	customBank2VoiceDataHexStrings.removeListener(this);
	customBank3VoiceDataHexStrings.removeListener(this);
}
