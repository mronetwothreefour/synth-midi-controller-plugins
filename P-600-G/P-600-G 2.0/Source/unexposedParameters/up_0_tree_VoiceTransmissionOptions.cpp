#include "up_0_tree_VoiceTransmissionOptions.h"

#include "../constants/constants_Identifiers.h"

using namespace P_600_G_Constants;

VoiceTransmissionOptions::VoiceTransmissionOptions() :
	voiceTransmissionOptionsTree{ ID::tree_VoiceTxOptions }
{
	setParamChangesShouldBeTransmitted(true);
	setVoiceTransmitTime(500);
}

const uint8 VoiceTransmissionOptions::currentVoiceNumber() {
	return (uint8)(int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_CurrentVoiceNumber);
}

void VoiceTransmissionOptions::setCurrentVoiceNumber(uint8 newNumber) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_CurrentVoiceNumber, newNumber, nullptr);
}

Value VoiceTransmissionOptions::getCurrentVoiceNumberAsValue() {
	return voiceTransmissionOptionsTree.getPropertyAsValue(ID::voiceTx_CurrentVoiceNumber, nullptr);
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

void VoiceTransmissionOptions::setIncomingVoiceShouldBeStored(const bool shouldBeStored) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeStored, shouldBeStored ? (bool)true : (bool)false, nullptr);
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
