#include "params_VoiceTransmissionOptions.h"

#include "params_Identifiers.h"



VoiceTransmissionOptions::VoiceTransmissionOptions() :
	voiceTransmissionOptionsTree{ ID::midi_Options }
{
	fillVoiceTransmissionOptionsTreeWithProperties();
}

void VoiceTransmissionOptions::fillVoiceTransmissionOptionsTreeWithProperties() {
	voiceTransmissionOptionsTree.setProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankA, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankB, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::midi_VoiceTransmitTime, 300, nullptr);
}

void VoiceTransmissionOptions::addListener(ValueTree::Listener* listener) {
	voiceTransmissionOptionsTree.addListener(listener);
}

void VoiceTransmissionOptions::removeListener(ValueTree::Listener* listener) {
	voiceTransmissionOptionsTree.removeListener(listener);
}

bool VoiceTransmissionOptions::incomingVoiceShouldBeSavedInCustomBankA() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankA);
}

bool VoiceTransmissionOptions::incomingVoiceShouldBeSavedInCustomBankB() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankB);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldBeSavedInCustomBankA() {
	voiceTransmissionOptionsTree.setProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankA, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldBeSavedInCustomBankB() {
	voiceTransmissionOptionsTree.setProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankB, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldNotBeSavedInCustomBank() {
	voiceTransmissionOptionsTree.setProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankA, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::midi_IncomingVoiceShouldBeSavedInCustomBankB, (bool)false, nullptr);
}

bool VoiceTransmissionOptions::paramChangeEchosAreNotBlocked() {
	return !(bool)voiceTransmissionOptionsTree.getProperty(ID::midi_ParamChangeEchosAreBlocked);
}

void VoiceTransmissionOptions::setParamChangeEchosAreBlocked() {
	voiceTransmissionOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setParamChangeEchosAreNotBlocked() {
	voiceTransmissionOptionsTree.setProperty(ID::midi_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

const int VoiceTransmissionOptions::voiceTransmitTime() {
	return (int)voiceTransmissionOptionsTree.getProperty(ID::midi_VoiceTransmitTime);
}

void VoiceTransmissionOptions::setVoiceTransmitTime(int timeInMilliseconds) {
	voiceTransmissionOptionsTree.setProperty(ID::midi_VoiceTransmitTime, timeInMilliseconds, nullptr);
}

XmlElement* VoiceTransmissionOptions::getStateXml() {
	std::unique_ptr<XmlElement> voiceTransmissionOptionsTreeStateXml{ new XmlElement(ID::state_PatchTransmissionOptions) };
	auto voiceTransmitTime{ (int)voiceTransmissionOptionsTree.getProperty(ID::midi_VoiceTransmitTime) };
	voiceTransmissionOptionsTreeStateXml->setAttribute(ID::midi_VoiceTransmitTime, voiceTransmitTime);
	return voiceTransmissionOptionsTreeStateXml.release();
}

void VoiceTransmissionOptions::replaceState(const ValueTree& newState) {
	auto voiceTransmitTime{ newState.getProperty(ID::midi_VoiceTransmitTime) };
	voiceTransmissionOptionsTree.setProperty(ID::midi_VoiceTransmitTime, voiceTransmitTime, nullptr);
}
