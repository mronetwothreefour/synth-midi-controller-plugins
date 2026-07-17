#include "voices_VoicesBank.h"

#include "voices_Constants.h"
#include "voices_FactoryVoiceDataHexStrings_Singleton.h"
#include "../params/params_Identifiers.h"

using namespace constants;



VoicesBank::VoicesBank() :
	voiceDataHexStrings{ ID::voicesBank }
{
	fillVoiceDataHexStrings();
}

void VoicesBank::fillVoiceDataHexStrings() {
	auto& factoryVoiceDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	auto factoryVoicesBank{ factoryVoiceDataHexStrings.getFactoryVoicesBank() };
	for (uint8 slot = 0; slot != slotOutOfRange(); ++slot) {
		auto voiceDataHexString{ factoryVoicesBank[slot] };
		voiceDataHexStrings.setProperty("voice" + (String)slot, voiceDataHexString, nullptr);
	}
}

int VoicesBank::slotOutOfRange() {
	auto& factoryVoiceDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	return factoryVoiceDataHexStrings.slotOutOfRange();
}

void VoicesBank::addListenerToVoiceDataHexStrings(ValueTree::Listener* listener) {
	voiceDataHexStrings.addListener(listener);
}

void VoicesBank::removeListenerFromVoiceDataHexStrings(ValueTree::Listener* listener) {
	voiceDataHexStrings.removeListener(listener);
}

const String VoicesBank::nameOfVoiceInSlot(uint8 slot) {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	auto voiceDataHexString{ voiceDataHexStrings.getProperty("voice" + (String)slot).toString() };
	auto nameString{ voiceDataHexString.substring(voices::indexOfFirstNameCharInVoiceDataHexString) };
	return nameString;
}

void VoicesBank::setNameOfVoiceInSlot(String newName, uint8 slot) {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	auto oldVoiceDataHexString{ voiceDataHexStrings.getProperty("voice" + (String)slot).toString() };
	auto newVoiceDataHexString{ oldVoiceDataHexString.substring(0, voices::indexOfFirstNameCharInVoiceDataHexString) };
	newVoiceDataHexString.append(newName, voices::maxLengthOfVoiceName);
	voiceDataHexStrings.setProperty("voice" + (String)slot, newVoiceDataHexString, nullptr);
}

const String VoicesBank::getVoiceDataHexStringFromSlot(uint8 slot) const {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	return voiceDataHexStrings.getProperty("voice" + (String)slot).toString();
}

void VoicesBank::storeVoiceDataHexStringInSlot(String voiceDataHexString, uint8 slot) {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	voiceDataHexStrings.setProperty("voice" + (String)slot, voiceDataHexString, nullptr);
}

void VoicesBank::restoreFactoryVoicesBank() {
	fillVoiceDataHexStrings();
}

XmlElement* VoicesBank::getStateXml() {
	auto voicesBankStateXml{ voiceDataHexStrings.createXml() };
	voicesBankStateXml->setTagName(ID::state_VoicesBank);
	return voicesBankStateXml.release();
}

void VoicesBank::replaceState(const ValueTree& newState) {
	voiceDataHexStrings.copyPropertiesAndChildrenFrom(newState, nullptr);
}
