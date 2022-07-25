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
			auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 3)};
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

const String VoicesBanks::nameOfVoiceInBankSlot(const VoicesBank bank, const uint8 slotNum) const {
	jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
	auto bankName{ "bank_" + String((int)bank % 3) };
	auto bankTree{ bank < VoicesBank::custom_1 ? factoryVoiceNameStrings.getChildWithName(bankName) : customVoiceNameStrings.getChildWithName(bankName) };
	return bankTree.getProperty("slot_" + String(slotNum).paddedLeft('0', 3));
}

const String VoicesBanks::getVoiceDataHexStringFromBankSlot(const VoicesBank bank, const uint8 slotNum) const {
	jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
	auto bankName{ "bank_" + String((int)bank % 3) };
	auto bankTree{ bank < VoicesBank::custom_1 ? factoryVoiceDataHexStrings.tree.getChildWithName(bankName) : customVoiceDataHexStrings.getChildWithName(bankName) };
	return bankTree.getProperty("slot_" + String(slotNum).paddedLeft('0', 3));
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

void VoicesBanks::storeVoiceDataHexStringInCustomBankSlot(const String voiceDataHexString, const VoicesBank bank, const uint8 slotNum) {
	jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
	jassert(bank >= VoicesBank::custom_1);
	auto bankTree{ customVoiceDataHexStrings.getChild((int)bank % 3) };
	if (bankTree.isValid()) {
		auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 3) };
		bankTree.setProperty(slotName, voiceDataHexString, nullptr);
	}
}

Value VoicesBanks::getVoiceNameValueForCustomBankSlot(const VoicesBank bank, const uint8 slotNum) {
	jassert(bank >= VoicesBank::custom_1);
	jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
	auto bankTree{ customVoiceNameStrings.getChild((int)bank % 3) };
	auto slotName{ String(slotNum).paddedLeft('0', 3) };
	return bankTree.getPropertyAsValue(slotName, nullptr);
}

void VoicesBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) {
	auto propertyName{ propertyID.toString() };
	auto slotString{ propertyName.fromLastOccurrenceOf("slot_", false, true) };
	auto slotNum{ (uint8)slotString.getIntValue() };
	auto bankName{ tree.getType().toString() };
	auto bankNum{ bankName.fromLastOccurrenceOf("bank_", false, false).getIntValue() };
	auto customBank{ VoicesBank{ bankNum + 3 } };
	auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(customBank, slotNum) };
	auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
	auto customNamesTree{ customVoiceNameStrings.getChild(bankNum) };
	customNamesTree.setProperty(propertyID, voiceName, nullptr);
}

std::unique_ptr<XmlElement> VoicesBanks::getStateXml() {
	auto voicesBanksStateXml{ std::make_unique<XmlElement>(ID::state_CustomVoicesBanks) };

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
