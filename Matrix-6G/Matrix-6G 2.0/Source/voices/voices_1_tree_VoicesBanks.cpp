#include "voices_1_tree_VoicesBanks.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"

VoicesBanks::VoicesBanks() :
    factoryVoiceNameStrings{ ID::banks_FactoryVoiceNameStrings },
    customVoiceDataHexStrings{ ID::banks_CustomVoiceDataHexStrings },
    customVoiceNameStrings{ ID::banks_CustomVoiceNameStrings }
{
    for (auto bankNum = (int)VoicesBank::analogSynths_A; bankNum <= (int)VoicesBank::custom_B; ++bankNum) {
        auto bankName{ "bank_" + (String)bankNum };
        ValueTree factoryNamesChildTree{ bankName };
        ValueTree customDataChildTree{ bankName };
        ValueTree customNamesChildTree{ bankName };
        for (auto slotNum = (uint8)0; slotNum < VCS::numberOfSlotsInVoicesBank; ++slotNum) {
            auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
            if (bankNum < (int)VoicesBank::custom_A) {
                auto factoryVoiceDataString{ getVoiceDataHexStringFromBankSlot(VoicesBank{ bankNum }, slotNum) };
                auto factoryVoiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(factoryVoiceDataString)) };
                factoryNamesChildTree.setProperty(slotName, factoryVoiceName, nullptr);
            }
            else {
                customDataChildTree.setProperty(slotName, VCS::basicVoiceDataHexString, nullptr);
                customNamesChildTree.setProperty(slotName, VCS::basicVoiceNameString, nullptr);
            }
        }
    }
    customVoiceDataHexStrings.addListener(this);
}

const String VoicesBanks::nameOfVoiceInBankSlot(const VoicesBank bank, const uint8 slotNum) const {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto bankName{ "bank_" + String((int)bank) };
    auto bankTree{ bank < VoicesBank::custom_A ? factoryVoiceNameStrings.getChildWithName(bankName) : customVoiceNameStrings.getChildWithName(bankName) };
    return bankTree.getProperty("slot_" + String(slotNum).paddedLeft('0', 2));
}

const String VoicesBanks::getVoiceDataHexStringFromBankSlot(const VoicesBank bank, const uint8 slotNum) const {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto bankName{ "bank_" + String((int)bank) };
    auto bankTree{ bank < VoicesBank::custom_A ? factoryVoiceDataHexStrings.tree.getChildWithName(bankName) : customVoiceDataHexStrings.getChildWithName(bankName) };
    return bankTree.getProperty("slot_" + String(slotNum).paddedLeft('0', 2));
}

const String VoicesBanks::extractVoiceNameFromDataVector(const std::vector<uint8>& dataVector) {
    String voiceName{ "" };
    for (auto byte = 0; byte != (2 * VCS::numberOfCharsInVoiceName); byte += 2) {
        auto lsbByteValue{ (uint8)dataVector[byte] };
        auto msbByteValue{ (uint8)dataVector[byte + 1] };
        auto storedASCIIvalue{ uint8(lsbByteValue + (msbByteValue * 16)) };
        if (storedASCIIvalue == RawDataTools::valueForBarSymbol)
            voiceName += "|";
        else {
            RawDataTools::restoreSeventhBitTo_ASCII_Value(storedASCIIvalue);
            voiceName += (String)std::string(1, storedASCIIvalue);
        }
    }
    return voiceName;
}

void VoicesBanks::storeVoiceDataHexStringInCustomBankSlot(const String voiceDataHexString, const VoicesBank bank, const uint8 slotNum) {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    jassert(bank >= VoicesBank::custom_A);
    auto bankTree{ customVoiceDataHexStrings.getChildWithName("bank_" + String((int)bank)) };
    if (bankTree.isValid()) {
        auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
        bankTree.setProperty(slotName, voiceDataHexString, nullptr);
    }
}

Value VoicesBanks::getVoiceNameAsValueForCustomBankSlot(const VoicesBank bank, const uint8 slotNum) {
    jassert(bank >= VoicesBank::custom_A);
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto bankTree{ customVoiceNameStrings.getChildWithName("bank_" + String((int)bank)) };
    auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
    return bankTree.getPropertyAsValue(slotName, nullptr);
}

void VoicesBanks::valueTreePropertyChanged(ValueTree& tree, const Identifier& propertyID) {
    auto propertyName{ propertyID.toString() };
    auto slotString{ propertyName.fromLastOccurrenceOf("slot_", false, true) };
    auto slotNum{ (uint8)slotString.getIntValue() };
    auto bankName{ tree.getType().toString() };
    auto bankNum{ bankName.fromLastOccurrenceOf("bank_", false, false).getIntValue() };
    auto customBank{ VoicesBank{ bankNum } };
    auto voiceDataHexString{ getVoiceDataHexStringFromBankSlot(customBank, slotNum) };
    auto voiceName{ extractVoiceNameFromDataVector(RawDataTools::convertHexStringToDataVector(voiceDataHexString)) };
    auto customNamesTree{ customVoiceNameStrings.getChildWithName(bankName)};
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
