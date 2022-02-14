#include "params_ProgramDataOptions.h"

#include "params_Identifiers.h"
#include "params_UnexposedParameters_Facade.h"



ProgramDataOptions::ProgramDataOptions(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	programDataOptionsTree{ ID::voiceTx_Options }
{
	fillProgramDataOptionsTreeWithProperties();
}

void ProgramDataOptions::fillProgramDataOptionsTreeWithProperties() {
	programDataOptionsTree.setProperty(ID::voiceTx_CurrentVoiceNumber, (uint8)0, nullptr);
	programDataOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)false, nullptr);
	programDataOptionsTree.setProperty(ID::voiceTx_Time, 500, nullptr);
	programDataOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank, (bool)false, nullptr);
}

void ProgramDataOptions::addListener(ValueTree::Listener* listener) {
	programDataOptionsTree.addListener(listener);
}

void ProgramDataOptions::removeListener(ValueTree::Listener* listener) {
	programDataOptionsTree.removeListener(listener);
}

const uint8 ProgramDataOptions::currentProgramNumber() {
	return (uint8)(int)programDataOptionsTree.getProperty(ID::voiceTx_CurrentVoiceNumber);
}

void ProgramDataOptions::setCurrentProgramNumber(uint8 newNumber) {
	jassert(newNumber < 100);
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	programDataOptionsTree.setProperty(ID::voiceTx_CurrentVoiceNumber, newNumber, undoManager);
}

bool ProgramDataOptions::paramChangeEchosAreNotBlocked() {
	return !(bool)programDataOptionsTree.getProperty(ID::voiceTx_ParamChangeEchoesAreBlocked);
}

void ProgramDataOptions::setParamChangeEchosAreBlocked() {
	programDataOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)true, nullptr);
}

void ProgramDataOptions::setParamChangeEchosAreNotBlocked() {
	programDataOptionsTree.setProperty(ID::voiceTx_ParamChangeEchoesAreBlocked, (bool)false, nullptr);
}

const int ProgramDataOptions::programTransmitTime() {
	return (int)programDataOptionsTree.getProperty(ID::voiceTx_Time);
}

void ProgramDataOptions::setProgramTransmitTime(int timeInMilliseconds) {
	programDataOptionsTree.setProperty(ID::voiceTx_Time, timeInMilliseconds, nullptr);
}

bool ProgramDataOptions::incomingPgmDataDumpShouldBeSavedInStorageBank() {
	return (bool)programDataOptionsTree.getProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank);
}

void ProgramDataOptions::setIncomingPgmDataDumpShouldBeSavedInStorageBank() {
	programDataOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank, (bool)true, nullptr);
}

void ProgramDataOptions::setIncomingPgmDataDumpShouldNotBeSavedInStorageBank() {
	programDataOptionsTree.setProperty(ID::voiceTx_IncomingVoiceShouldBeSavedInStorageBank, (bool)false, nullptr);
}

XmlElement* ProgramDataOptions::getStateXml() {
	auto pgmDataOptionsTreeStateXml{ programDataOptionsTree.createXml() };
	pgmDataOptionsTreeStateXml->setTagName(ID::state_VoiceTransmissionOptions);
	return pgmDataOptionsTreeStateXml.release();
}

void ProgramDataOptions::replaceState(const ValueTree& newState) {
	programDataOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
