#include "voices_1_tree_VoicesBank.h"

#include "voices_0_tree_FactoryVoiceDataHexStrings.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"
#include "../midi/midi_0_RawDataTools.h"

using namespace P_600_G_Constants;

VoicesBank::VoicesBank() :
    voiceDataHexStrings{ ID::bank_VoiceDataHexStrings }
{
    restoreFactoryVoicesBank();
}

const String VoicesBank::nameOfVoiceInSlot(const uint8 slotNum) const {
    auto dataHexString{ getVoiceDataHexStringFromSlot(slotNum) };
    auto nameString{ dataHexString.substring(VCS::indexOfFirstNameCharInVoiceDataHexString) };
    return nameString;
}

void VoicesBank::setNameOfVoiceInSlot(const String newName, const uint8 slotNum) {
    jassert(newName.length() <= VCS::maxLengthOfVoiceName);
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto dataHexStringWithoutName{ getVoiceDataHexStringWithoutNameFromSlot(slotNum) };
    storeVoiceDataHexStringInSlot(dataHexStringWithoutName + newName, slotNum);
}

const String VoicesBank::getVoiceDataHexStringFromSlot(const uint8 slotNum) const {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    return voiceDataHexStrings.getProperty("slot_" + String(slotNum).paddedLeft('0', 2));
}

const String VoicesBank::getVoiceDataHexStringWithoutNameFromSlot(const uint8 slotNum) const {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
    auto dataHexString{ voiceDataHexStrings.getProperty(slotName).toString()};
    return dataHexString.substring(0, VCS::indexOfFirstNameCharInVoiceDataHexString);
}

void VoicesBank::storeVoiceDataHexStringInSlot(const String voiceDataHexString, const uint8 slotNum) {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
    voiceDataHexStrings.setProperty(slotName, voiceDataHexString, nullptr);
}

Value VoicesBank::getVoiceDataHexStringAsValueForSlot(const uint8 slotNum) {
    jassert(slotNum < VCS::numberOfSlotsInVoicesBank);
    auto slotName{ "slot_" + String(slotNum).paddedLeft('0', 2) };
    return voiceDataHexStrings.getPropertyAsValue(slotName, nullptr);
}

void VoicesBank::restoreFactoryVoicesBank() {
    voiceDataHexStrings.copyPropertiesFrom(factoryVoiceDataHexStrings.tree, nullptr);
}

std::unique_ptr<XmlElement> VoicesBank::getStateXml() {
    auto voicesBankStateXml{ voiceDataHexStrings.createXml() };
    if (voicesBankStateXml != nullptr)
        voicesBankStateXml->setTagName(ID::state_VoicesBank);
    return voicesBankStateXml;
}

void VoicesBank::replaceState(const ValueTree& newState) {
    if (newState.isValid())
        voiceDataHexStrings.copyPropertiesFrom(newState, nullptr);
}

