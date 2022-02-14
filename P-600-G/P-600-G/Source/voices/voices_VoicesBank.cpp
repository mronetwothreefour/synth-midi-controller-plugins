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
	auto& factoryPgmDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	auto factoryPgmDataBank{ factoryPgmDataHexStrings.getFactoryVoicesBank() };
	for (uint8 pgmSlot = 0; pgmSlot != slotOutOfRange(); ++pgmSlot) {
		auto pgmDataHexString{ factoryPgmDataBank[pgmSlot] };
		voiceDataHexStrings.setProperty("pgm" + (String)pgmSlot, pgmDataHexString, nullptr);
	}
}

int VoicesBank::slotOutOfRange() {
	auto& factoryPgmDataHexStrings{ FactoryVoiceDataHexStrings::get() };
	return factoryPgmDataHexStrings.slotOutOfRange();
}

void VoicesBank::addListenerToVoiceDataHexStrings(ValueTree::Listener* listener) {
	voiceDataHexStrings.addListener(listener);
}

void VoicesBank::removeListenerFromVoiceDataHexStrings(ValueTree::Listener* listener) {
	voiceDataHexStrings.removeListener(listener);
}

const String VoicesBank::nameOfVoiceInSlot(uint8 slot) {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	auto pgmDataHexString{ voiceDataHexStrings.getProperty("pgm" + (String)slot).toString() };
	auto nameString{ pgmDataHexString.substring(voices::indexOfFirstNameCharInVoiceDataHexString) };
	return nameString;
}

void VoicesBank::setNameOfVoiceInSlot(String newName, uint8 slot) {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	auto oldPgmDataHexString{ voiceDataHexStrings.getProperty("pgm" + (String)slot).toString() };
	auto newPgmDataHexString{ oldPgmDataHexString.substring(0, voices::indexOfFirstNameCharInVoiceDataHexString) };
	newPgmDataHexString.append(newName, voices::maxLengthOfVoiceName);
	voiceDataHexStrings.setProperty("pgm" + (String)slot, newPgmDataHexString, nullptr);
}

const String VoicesBank::getVoiceDataHexStringFromSlot(uint8 slot) const {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	return voiceDataHexStrings.getProperty("pgm" + (String)slot).toString();
}

void VoicesBank::storeVoiceDataHexStringInSlot(String pgmDataHexString, uint8 slot) {
	jassert(slot < voices::numberOfSlotsInVoicesBank);
	voiceDataHexStrings.setProperty("pgm" + (String)slot, pgmDataHexString, nullptr);
}

void VoicesBank::restoreFactoryPgmData() {
	fillVoiceDataHexStrings();
}

XmlElement* VoicesBank::getStateXml() {
	auto pgmDataBankStateXml{ voiceDataHexStrings.createXml() };
	pgmDataBankStateXml->setTagName(ID::state_VoicesBank);
	return pgmDataBankStateXml.release();
}

void VoicesBank::replaceState(const ValueTree& newState) {
	voiceDataHexStrings.copyPropertiesAndChildrenFrom(newState, nullptr);
}
