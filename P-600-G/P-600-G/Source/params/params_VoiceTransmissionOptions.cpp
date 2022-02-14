#include "params_VoiceTransmissionOptions.h"

#include "params_Identifiers.h"
#include "params_UnexposedParameters_Facade.h"



VoiceTransmissionOptions::VoiceTransmissionOptions(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	voiceTransmissionOptionsTree{ ID::voiceTx_Options }
{
	fillVoiceTransmissionOptionsTreeWithProperties();
}

void VoiceTransmissionOptions::fillVoiceTransmissionOptionsTreeWithProperties() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_CurrentVoiceNumber, (uint8)0, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)false, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, 500, nullptr);
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank, (bool)false, nullptr);
}

void VoiceTransmissionOptions::addListener(ValueTree::Listener* listener) {
	voiceTransmissionOptionsTree.addListener(listener);
}

void VoiceTransmissionOptions::removeListener(ValueTree::Listener* listener) {
	voiceTransmissionOptionsTree.removeListener(listener);
}

const uint8 VoiceTransmissionOptions::currentVoiceNumber() {
	return (uint8)(int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_CurrentVoiceNumber);
}

void VoiceTransmissionOptions::setCurrentVoiceNumber(uint8 newNumber) {
	jassert(newNumber < 100);
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_CurrentVoiceNumber, newNumber, undoManager);
}

bool VoiceTransmissionOptions::paramChangeEchoesAreNotBlocked() {
	return !(bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_ParamChangeEchoesAreBlocked);
}

void VoiceTransmissionOptions::setParamChangeEchoesAreBlocked() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setParamChangeEchoesAreNotBlocked() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)false, nullptr);
}

const int VoiceTransmissionOptions::voiceTransmitTime() {
	return (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_Time);
}

void VoiceTransmissionOptions::setVoiceTransmitTime(int timeInMilliseconds) {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, timeInMilliseconds, nullptr);
}

bool VoiceTransmissionOptions::incomingVoiceShouldBeSavedInVoicesBank() {
	return (bool)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldBeSavedInVoicesBank() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank, (bool)true, nullptr);
}

void VoiceTransmissionOptions::setIncomingVoiceShouldNotBeSavedInVoicesBank() {
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank, (bool)false, nullptr);
}

XmlElement* VoiceTransmissionOptions::getStateXml() {
	std::unique_ptr<XmlElement> voiceTransmissionOptionsTreeStateXml{ new XmlElement(ID::state_VoiceTransmissionOptions) };
	auto voiceTransmitTime{ (int)voiceTransmissionOptionsTree.getProperty(ID::voiceTx_Time) };
	voiceTransmissionOptionsTreeStateXml->setAttribute(ID::voiceTx_Time, voiceTransmitTime);
	return voiceTransmissionOptionsTreeStateXml.release();
}

void VoiceTransmissionOptions::replaceState(const ValueTree& newState) {
	auto voiceTransmitTime{ newState.getProperty(ID::voiceTx_Time) };
	voiceTransmissionOptionsTree.setProperty(ID::voiceTx_Time, voiceTransmitTime, nullptr);
}
