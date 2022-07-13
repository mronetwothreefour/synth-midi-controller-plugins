#include "voices_1_tree_VoicesBanks.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"



VoicesBanks::VoicesBanks() :
	factoryVoiceNameStrings{ ID::banks_FactoryVoiceNameStrings },
	customVoiceDataHexStrings{ ID::banks_CustomVoiceDataHexStrings },
	customVoiceNameStrings{ ID::banks_CustomVoiceNameStrings }
{
	for (auto bankNum = 0; bankNum != 3; ++bankNum) {
		auto bankName{ "bank_" + (String)bankNum };
		ValueTree factoryNamesChildTree{ bankName };
		ValueTree customDataChildTree{ bankName };
		ValueTree customNamesChildTree{ bankName };
		for (auto slotNum = (uint8)0; slotNum < VCS::numberOfSlotsInVoicesBank; ++slotNum) {
			auto slotNumString{ (String)slotNum };
			auto slotName{ "slot_" + slotNumString.paddedLeft('0', 3) };
			auto factoryVoiceDataString{ getVoiceDataHexStringFromBankSlot(VoicesBank{ bankNum }, slotNum) };
			auto factoryVoiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(factoryVoiceDataString)) };
			factoryNamesChildTree.setProperty(slotName, factoryVoiceName, nullptr);
			customDataChildTree.setProperty(slotName, VCS::basicVoiceDataHexString, nullptr);
			customNamesChildTree.setProperty(slotName, VCS::basicVoiceNameString, nullptr);
		}
		factoryVoiceNameStrings.addChild(factoryNamesChildTree, bankNum, nullptr);
		customVoiceDataHexStrings.addChild(customDataChildTree, bankNum, nullptr);
		customVoiceNameStrings.addChild(customNamesChildTree, bankNum, nullptr);
	}
	customVoiceDataHexStrings.addListener(this);
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
	jassert(bank >= VoicesBank::custom_1);
	auto bankNum{ (int)bank % 3 };
	auto bankTree{ customVoiceDataHexStrings.getChild(bankNum) };
	if (bankTree.isValid()) {
		auto slotNumString{ (String)slotNum };
		auto slotName{ "slot_" + slotNumString.paddedLeft('0', 3) };
		bankTree.setProperty(slotName, voiceDataHexString, nullptr);
	}
}

ValueTree VoicesBanks::getVoiceNamesChildTreeForCustomBank(VoicesBank bank) {
	jassert(bank >= VoicesBank::custom_1);
	auto bankNum{ (int)bank % 3 };
	return customVoiceNameStrings.getChild(bankNum);
}

void VoicesBanks::addListenerToCustomVoiceNameStringsTree(ValueTree::Listener* listener) {
	customVoiceNameStrings.addListener(listener);
}

void VoicesBanks::removeListenerFromCustomVoiceNameStringsTree(ValueTree::Listener* listener) {
	customVoiceNameStrings.removeListener(listener);
}

void VoicesBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) {
	auto propertyName{ propertyID.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("slot_", false, true) };
	auto slotNum{ (uint8)slotString.getIntValue() };
	auto bankName{ tree.getType().toString() };
	auto bankNum{ bankName.fromFirstOccurrenceOf("_", false, false).getIntValue() };
	auto customBank{ VoicesBank{ bankNum + 3 } };
	auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(customBank, slotNum) };
	auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
	auto customNamesTree{ customVoiceNameStrings.getChildWithName(bankName) };
	customNamesTree.setProperty(propertyID, voiceName, nullptr);
}

std::unique_ptr<XmlElement> VoicesBanks::getStateXml() {
	auto voicesBanksStateXml{ std::make_unique<XmlElement>(ID::state_VoicesBanks) };

	auto customVoiceDataHexStringsXml{ customVoiceDataHexStrings.createXml() };
	if (customVoiceDataHexStringsXml != nullptr) {
		customVoiceDataHexStringsXml->setTagName(ID::state_CustomVoiceDataHexStrings);
		voicesBanksStateXml->addChildElement(customVoiceDataHexStringsXml.release());
	}

	auto customVoiceNameStringsXml{ customVoiceNameStrings.createXml() };
	if (customVoiceNameStringsXml != nullptr) {
		customVoiceNameStringsXml->setTagName(ID::state_CustomVoiceNameStrings);
		voicesBanksStateXml->addChildElement(customVoiceNameStringsXml.release());
	}

	return voicesBanksStateXml;
}

void VoicesBanks::replaceState(const ValueTree& newState) {
	if (newState.isValid()) {
		auto customVoiceDataHexStringsState{ newState.getChildWithName(ID::state_CustomVoiceDataHexStrings) };
		if (customVoiceDataHexStringsState.isValid())
			customVoiceDataHexStrings.copyPropertiesAndChildrenFrom(customVoiceDataHexStringsState, nullptr);

		auto customVoiceNameStringsState{ newState.getChildWithName(ID::state_CustomVoiceNameStrings) };
		if (customVoiceNameStringsState.isValid())
			customVoiceNameStrings.copyPropertiesAndChildrenFrom(customVoiceNameStringsState, nullptr);
	}
}

VoicesBanks::~VoicesBanks() {
	customVoiceDataHexStrings.removeListener(this);
}
