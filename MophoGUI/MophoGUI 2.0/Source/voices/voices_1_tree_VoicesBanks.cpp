#include "voices_1_tree_VoicesBanks.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"



VoicesBanks::VoicesBanks() :
	factoryVoiceNameStrings{ ID::banks_VoiceNameStrings },
	customVoiceDataHexStrings{ ID::banks_VoiceDataHexStrings },
	customVoiceNameStrings{ ID::banks_VoiceNameStrings }
{
	for (auto bankNum = 0; bankNum != 3; ++bankNum) {
		auto bankName{ "bank_" + (String)bankNum };
		auto factoryNameTree{ factoryVoiceNameStrings.getOrCreateChildWithName(bankName, nullptr) };
		auto customDataTree{ customVoiceDataHexStrings.getOrCreateChildWithName(bankName, nullptr) };
		auto customNameTree{ customVoiceNameStrings.getOrCreateChildWithName(bankName, nullptr) };
		for (auto slotNum = (uint8)0; slotNum < VCS::numberOfSlotsInVoicesBank; ++slotNum) {
			auto slotNumString{ (String)slotNum };
			auto slotName{ "slot_" + slotNumString.paddedLeft('0', 3) };
			auto factoryVoiceDataString{ getVoiceDataHexStringFromBankSlot(VoicesBank{ bankNum }, slotNum) };
			auto factoryVoiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(factoryVoiceDataString)) };
			factoryNameTree.setProperty(slotName, factoryVoiceName, nullptr);
			customDataTree.setProperty(slotName, VCS::basicVoiceDataHexString, nullptr);
			customNameTree.setProperty(slotName, VCS::basicVoiceNameString, nullptr);
		}
		customDataTree.addListener(this);
	}
}

const String VoicesBanks::nameOfVoiceInBankSlot(VoicesBank bank, uint8 slotNum) {
	jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
	auto bankNum{ (int)bank % 3 };
	auto bankName{ "bank_" + (String)bankNum };
	auto bankTree{ bank < VoicesBank::custom_1 ? factoryVoiceNameStrings.getChildWithName(bankName) : customVoiceNameStrings.getChildWithName(bankName) };
	auto slotNumString{ (String)slotNum };
	auto slotName{ "slot_" + slotNumString.paddedLeft('0', 3) };
	return bankTree.getProperty(slotName);
}

const String VoicesBanks::getVoiceDataHexStringFromBankSlot(VoicesBank bank, uint8 slotNum) const {
	jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
	auto bankNum{ (int)bank % 3 };
	auto bankName{ "bank_" + (String)bankNum };
	auto bankTree{ bank < VoicesBank::custom_1 ? factoryVoiceDataHexStrings.tree.getChildWithName(bankName) : customVoiceDataHexStrings.getChildWithName(bankName) };
	auto slotNumString{ (String)slotNum };
	auto slotName{ "slot_" + slotNumString.paddedLeft('0', 3) };
	return bankTree.getProperty(slotName);
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

void VoicesBanks::storeVoiceDataHexStringInCustomBankSlot(String voiceDataHexString, VoicesBank bank, uint8 slotNum) {
	jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
	auto bankNum{ (int)bank % 3 };
	auto bankName{ "bank_" + (String)bankNum };
	auto bankTree{ bank < VoicesBank::custom_1 ? factoryVoiceDataHexStrings.tree.getChildWithName(bankName) : customVoiceDataHexStrings.getChildWithName(bankName) };
	auto slotNumString{ (String)slotNum };
	auto slotName{ "slot_" + slotNumString.paddedLeft('0', 3) };
	bankTree.setProperty(slotName, voiceDataHexString, nullptr);
}

void VoicesBanks::addListenerToNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank >= VoicesBank::custom_1);
	auto bankNum{ (int)bank % 3 };
	auto bankName{ "bank_" + (String)bankNum };
	auto bankTree{ bank < VoicesBank::custom_1 ? factoryVoiceDataHexStrings.tree.getChildWithName(bankName) : customVoiceDataHexStrings.getChildWithName(bankName) };
	bankTree.addListener(listener);
}

void VoicesBanks::removeListenerFromNameStringsForCustomBank(ValueTree::Listener* listener, VoicesBank bank) {
	jassert(bank >= VoicesBank::custom_1);
	auto bankNum{ (int)bank % 3 };
	auto bankName{ "bank_" + (String)bankNum };
	auto bankTree{ bank < VoicesBank::custom_1 ? factoryVoiceDataHexStrings.tree.getChildWithName(bankName) : customVoiceDataHexStrings.getChildWithName(bankName) };
	bankTree.removeListener(listener);
}

void VoicesBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) {
	auto propertyName{ propertyID.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("slot_", false, true) };
	auto slotNum{ (uint8)slotString.getIntValue() };
	if (tree.hasType("bank_1")) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom_1, slotNum) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		auto bankTree{ customVoiceNameStrings.getChildWithName("bank_1") };
		bankTree.setProperty(propertyID, voiceName, nullptr);
	}
	if (tree.hasType("bank_2")) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom_2, slotNum) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		auto bankTree{ customVoiceNameStrings.getChildWithName("bank_2") };
		bankTree.setProperty(propertyID, voiceName, nullptr);
	}
	if (tree.hasType("bank_3")) {
		auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(VoicesBank::custom_3, slotNum) };
		auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
		auto bankTree{ customVoiceNameStrings.getChildWithName("bank_3") };
		bankTree.setProperty(propertyID, voiceName, nullptr);
	}
}

std::unique_ptr<XmlElement> VoicesBanks::getStateXml() {
	auto customVoiceDataHexStringsXml{ customVoiceDataHexStrings.createXml() };
	if (customVoiceDataHexStringsXml != nullptr)
		customVoiceDataHexStringsXml->setTagName(ID::state_CustomVoiceDataHexStrings);
	return customVoiceDataHexStringsXml;
}

void VoicesBanks::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		customVoiceDataHexStrings.copyPropertiesAndChildrenFrom(newState, nullptr);
}

VoicesBanks::~VoicesBanks() {
	customVoiceDataHexStrings.getChildWithName("bank_1").removeListener(this);
	customVoiceDataHexStrings.getChildWithName("bank_2").removeListener(this);
	customVoiceDataHexStrings.getChildWithName("bank_3").removeListener(this);
}
