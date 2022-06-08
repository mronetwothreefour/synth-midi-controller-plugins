#include "voices_1_tree_VoicesBanks.h"

#include "voices_0_singleton_FactoryVoiceDataHexStrings.h"
#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"



VoicesBanks::VoicesBanks() :
	customBank_1_VoiceDataHexStrings{ ID::bank_custom_1_VoiceDataHexStrings },
	customBank_2_VoiceDataHexStrings{ ID::bank_custom_2_VoiceDataHexStrings },
	customBank_3_VoiceDataHexStrings{ ID::bank_custom_3_VoiceDataHexStrings },
	factoryBank_1_VoiceNameStrings{ ID::bank_factory_1_VoiceNameStrings },
	factoryBank_2_VoiceNameStrings{ ID::bank_factory_2_VoiceNameStrings },
	factoryBank_3_VoiceNameStrings{ ID::bank_factory_3_VoiceNameStrings },
	customBank_1_VoiceNameStrings{ ID::bank_custom_1_VoiceNameStrings },
	customBank_2_VoiceNameStrings{ ID::bank_custom_2_VoiceNameStrings },
	customBank_3_VoiceNameStrings{ ID::bank_custom_3_VoiceNameStrings }
{
	fillAllCustomVoiceDataBanks();
	fillAllVoiceNameBanks();
	customBank_1_VoiceDataHexStrings.addListener(this);
	customBank_2_VoiceDataHexStrings.addListener(this);
	customBank_3_VoiceDataHexStrings.addListener(this);
}

void VoicesBanks::fillAllCustomVoiceDataBanks() {
	for (uint8 voiceSlot = 0; voiceSlot != VCS::numberOfSlotsInVoicesBank; ++voiceSlot) {
		customBank_1_VoiceDataHexStrings.setProperty("voice_" + (String)voiceSlot, VCS::basicVoiceDataHexString, nullptr);
		customBank_2_VoiceDataHexStrings.setProperty("voice_" + (String)voiceSlot, VCS::basicVoiceDataHexString, nullptr);
		customBank_3_VoiceDataHexStrings.setProperty("voice_" + (String)voiceSlot, VCS::basicVoiceDataHexString, nullptr);
	}
}

void VoicesBanks::fillAllVoiceNameBanks() {
	String voiceName;
	String voiceDataString;
	for (uint8 voiceSlot = 0; voiceSlot != VCS::numberOfSlotsInVoicesBank; ++voiceSlot) {
		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::factory_1, voiceSlot);
		voiceName = extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataString));
		factoryBank_1_VoiceNameStrings.setProperty("voice_" + (String)voiceSlot, voiceName, nullptr);
		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::factory_2, voiceSlot);
		voiceName = extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataString));
		factoryBank_2_VoiceNameStrings.setProperty("voice_" + (String)voiceSlot, voiceName, nullptr);
		voiceDataString = getVoiceDataHexStringFromBankSlot(VoicesBank::factory_3, voiceSlot);
		voiceName = extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataString));
		factoryBank_3_VoiceNameStrings.setProperty("voice_" + (String)voiceSlot, voiceName, nullptr);
		customBank_1_VoiceNameStrings.setProperty("voice_" + (String)voiceSlot, VCS::basicVoiceNameString, nullptr);
		customBank_2_VoiceNameStrings.setProperty("voice_" + (String)voiceSlot, VCS::basicVoiceNameString, nullptr);
		customBank_3_VoiceNameStrings.setProperty("voice_" + (String)voiceSlot, VCS::basicVoiceNameString, nullptr);
	}
}

const String VoicesBanks::nameOfVoiceInBankSlot(VoicesBank bank, uint8 slot) {
	jassert(slot < VCS::numberOfSlotsInVoicesBank);
	switch (bank) {
	case VoicesBank::factory_1:
		return factoryBank_1_VoiceNameStrings.getProperty("voice_" + (String)slot);
	case VoicesBank::factory_2:
		return factoryBank_2_VoiceNameStrings.getProperty("voice_" + (String)slot);
	case VoicesBank::factory_3:
		return factoryBank_3_VoiceNameStrings.getProperty("voice_" + (String)slot);
	case VoicesBank::custom_1:
		return customBank_1_VoiceNameStrings.getProperty("voice_" + (String)slot);
	case VoicesBank::custom_2:
		return customBank_2_VoiceNameStrings.getProperty("voice_" + (String)slot);
	case VoicesBank::custom_3:
		return customBank_3_VoiceNameStrings.getProperty("voice_" + (String)slot);
	default:
		return "error";
	};
}

const String VoicesBanks::getVoiceDataHexStringFromBankSlot(VoicesBank bank, uint8 slot) const {
	jassert(slot < VCS::numberOfSlotsInVoicesBank);
	auto& factoryDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	switch (bank)
	{
	case VoicesBank::factory_1:
		return factoryDataHexStrings.getBank1()[slot];
	case VoicesBank::factory_2:
		return factoryDataHexStrings.getBank2()[slot];
	case VoicesBank::factory_3:
		return factoryDataHexStrings.getBank3()[slot];
	case VoicesBank::custom_1:
		return customBank_1_VoiceDataHexStrings.getProperty("voice_" + (String)slot);
	case VoicesBank::custom_2:
		return customBank_2_VoiceDataHexStrings.getProperty("voice_" + (String)slot);
	case VoicesBank::custom_3:
		return customBank_3_VoiceDataHexStrings.getProperty("voice_" + (String)slot);
	default:
		return "error";
	}
}

const String VoicesBanks::extractVoiceNameFromDataVector(const std::vector<uint8>& dataVector) {
	String voiceName{ "" };
	auto data{ dataVector.data() };
	for (auto byte = VCS::firstVoiceNameCharByte; byte <= VCS::lastVoiceNameCharByte; ++byte) {
		if (byte != VCS::ignoredVoiceNamePackByte1 && byte != VCS::ignoredVoiceNamePackByte2)
			voiceName += (String)std::string(1, (char)*(data + byte));
	}
	return voiceName;
}

void VoicesBanks::storeVoiceDataHexStringInCustomBankSlot(String voiceDataHexString, VoicesBank bank, uint8 slot) {
	jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
	jassert(slot < VCS::numberOfSlotsInVoicesBank);
	switch (bank)
	{
	case VoicesBank::custom_1:
		customBank_1_VoiceDataHexStrings.setProperty("voice_" + (String)slot, voiceDataHexString, nullptr);
		break;
	case VoicesBank::custom_2:
		customBank_2_VoiceDataHexStrings.setProperty("voice_" + (String)slot, voiceDataHexString, nullptr);
		break;
	case VoicesBank::custom_3:
		customBank_3_VoiceDataHexStrings.setProperty("voice_" + (String)slot, voiceDataHexString, nullptr);
		break;
	default:
		break;
	}
}

void VoicesBanks::addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
	switch (bank)
	{
	case VoicesBank::custom_1:
		customBank_1_VoiceNameStrings.addListener(listener);
		break;
	case VoicesBank::custom_2:
		customBank_2_VoiceNameStrings.addListener(listener);
		break;
	case VoicesBank::custom_3:
		customBank_3_VoiceNameStrings.addListener(listener);
		break;
	default:
		break;
	}
}

void VoicesBanks::removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank == VoicesBank::custom_1 || bank == VoicesBank::custom_2 || bank == VoicesBank::custom_3);
	switch (bank)
	{
	case VoicesBank::custom_1:
		customBank_1_VoiceNameStrings.removeListener(listener);
		break;
	case VoicesBank::custom_2:
		customBank_2_VoiceNameStrings.removeListener(listener);
		break;
	case VoicesBank::custom_3:
		customBank_3_VoiceNameStrings.removeListener(listener);
		break;
	default:
		break;
	}
}

void VoicesBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& property) {
	auto propertyName{ property.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("voice_", false, true) };
	auto slot{ (uint8)slotString.getIntValue() };
	if (tree.hasType(ID::bank_custom_1_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom_1, slot) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		customBank_1_VoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
	if (tree.hasType(ID::bank_custom_2_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom_2, slot) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		customBank_2_VoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
	if (tree.hasType(ID::bank_custom_3_VoiceDataHexStrings)) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom_3, slot) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		customBank_3_VoiceNameStrings.setProperty(property, voiceName, nullptr);
	}
}

XmlElement* VoicesBanks::getStateXml() {
	auto customVoicesBanksStateXml{ std::make_unique<XmlElement>(ID::state_VoicesBanks) };
	auto customBank1StateXml{ customBank_1_VoiceDataHexStrings.createXml() };
	if (customBank1StateXml != nullptr) {
		customBank1StateXml->setTagName(ID::state_CustomVoicesBank_1);
		customVoicesBanksStateXml->addChildElement(customBank1StateXml.release());
	}
	auto customBank2StateXml{ customBank_2_VoiceDataHexStrings.createXml() };
	if (customBank2StateXml != nullptr) {
		customBank2StateXml->setTagName(ID::state_CustomVoicesBank_2);
		customVoicesBanksStateXml->addChildElement(customBank2StateXml.release());
	}
	auto customBank3StateXml{ customBank_3_VoiceDataHexStrings.createXml() };
	if (customBank3StateXml != nullptr) {
		customBank3StateXml->setTagName(ID::state_CustomVoicesBank_3);
		customVoicesBanksStateXml->addChildElement(customBank3StateXml.release());
	}
	return customVoicesBanksStateXml.release();
}

void VoicesBanks::replaceState(const ValueTree& newState) {
	customBank_1_VoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank_1), nullptr);
	customBank_2_VoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank_2), nullptr);
	customBank_3_VoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState.getChildWithName(ID::state_CustomVoicesBank_3), nullptr);
}

VoicesBanks::~VoicesBanks() {
	customBank_3_VoiceDataHexStrings.removeListener(this);
	customBank_2_VoiceDataHexStrings.removeListener(this);
	customBank_1_VoiceDataHexStrings.removeListener(this);
}
