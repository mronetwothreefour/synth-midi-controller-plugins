#include "up_0_tree_VoiceTransmissionOptions.h"

#include "../constants/constants_Identifiers.h"

VoiceTransmissionOptions::VoiceTransmissionOptions() :
	voiceTransmissionOptionsTree{ ID::tree_VoiceTxOptions }
{
	setParamChangesShouldBeTransmitted(true);
	setVoiceTransmitTime(300);
	setIncomingVoiceShouldNotBeStored();
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_CustomBankToStoreVoiceIn, (int)VoicesBank::customA, nullptr);
}

const bool VoiceTransmissionOptions::paramChangesShouldBeTransmitted() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_TransmitParamChanges) == true;
}

void VoiceTransmissionOptions::setParamChangesShouldBeTransmitted(const bool shouldBeTransmitted) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_TransmitParamChanges, shouldBeTransmitted ? (bool)true : (bool)false, nullptr);
}

const int VoiceTransmissionOptions::voiceTransmitTime() {
	return (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_Time);
}

void VoiceTransmissionOptions::setVoiceTransmitTime(const int timeInMilliseconds) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, timeInMilliseconds, nullptr);
}

const bool VoiceTransmissionOptions::incomingVoiceShouldBeStored() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_IncomingVoiceShouldBeStored) == true;
}

const VoicesBank VoiceTransmissionOptions::bankToStoreIn() {
	return VoicesBank{ (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_CustomBankToStoreVoiceIn) };
}

void VoiceTransmissionOptions::setIncomingVoiceShouldBeStoredInCustomBank(const VoicesBank bank) {
	jassert(bank == VoicesBank::customA || bank == VoicesBank::customB);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeStored, (bool)true, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_CustomBankToStoreVoiceIn, (int)bank, nullptr);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldNotBeStored() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeStored, (bool)false, nullptr);
}

std::unique_ptr<XmlElement> VoiceTransmissionOptions::getStateXml() {
	std::unique_ptr<XmlElement> voiceTransmissionOptionsTreeStateXml{ new XmlElement(ID::state_VoiceTxOptions) };
	if (voiceTransmissionOptionsTreeStateXml != nullptr) {
		voiceTransmissionOptionsTreeStateXml->setAttribute(ID::voiceTx_Time, voiceTransmitTime());
	}
	return voiceTransmissionOptionsTreeStateXml;
}

void VoiceTransmissionOptions::replaceState(const ValueTree& newState) {
	auto voiceTransmitTime{ newState.getProperty(ID::voiceTx_Time) };
	if (!voiceTransmitTime.isVoid())
		voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, voiceTransmitTime, nullptr);
}
