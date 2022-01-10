#include "params_ProgramDataOptions.h"

#include "params_Identifiers.h"
#include "params_UnexposedParameters_Facade.h"



ProgramDataOptions::ProgramDataOptions(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	programDataOptionsTree{ ID::pgmData_Options }
{
	fillCurrentProgramOptionsTreeWithProperties();
}

void ProgramDataOptions::fillCurrentProgramOptionsTreeWithProperties() {
	programDataOptionsTree.setProperty(ID::pgmData_CurrentProgramNumber, (uint8)0, nullptr);
	programDataOptionsTree.setProperty(ID::pgmData_ParamChangeEchosAreBlocked, (bool)false, nullptr);
	programDataOptionsTree.setProperty(ID::pgmData_ProgramTransmitTime, 300, nullptr);
}

void ProgramDataOptions::addListener(ValueTree::Listener* listener) {
	programDataOptionsTree.addListener(listener);
}

void ProgramDataOptions::removeListener(ValueTree::Listener* listener) {
	programDataOptionsTree.removeListener(listener);
}

const uint8 ProgramDataOptions::currentProgramNumber() {
	return (uint8)(int)programDataOptionsTree.getProperty(ID::pgmData_CurrentProgramNumber);
}

void ProgramDataOptions::setCurrentProgramNumber(uint8 newNumber) {
	jassert(newNumber < 100);
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	programDataOptionsTree.setProperty(ID::pgmData_CurrentProgramNumber, newNumber, undoManager);
}

bool ProgramDataOptions::paramChangeEchosAreNotBlocked() {
	return !(bool)programDataOptionsTree.getProperty(ID::pgmData_ParamChangeEchosAreBlocked);
}

void ProgramDataOptions::setParamChangeEchosAreBlocked() {
	programDataOptionsTree.setProperty(ID::pgmData_ParamChangeEchosAreBlocked, (bool)true, nullptr);
}

void ProgramDataOptions::setParamChangeEchosAreNotBlocked() {
	programDataOptionsTree.setProperty(ID::pgmData_ParamChangeEchosAreBlocked, (bool)false, nullptr);
}

const int ProgramDataOptions::programTransmitTime() {
	return (int)programDataOptionsTree.getProperty(ID::pgmData_ProgramTransmitTime);
}

void ProgramDataOptions::setProgramTransmitTime(int timeInMilliseconds) {
	programDataOptionsTree.setProperty(ID::pgmData_ProgramTransmitTime, timeInMilliseconds, nullptr);
}

XmlElement* ProgramDataOptions::getStateXml() {
	auto pgmDataOptionsTreeStateXml{ programDataOptionsTree.createXml() };
	pgmDataOptionsTreeStateXml->setTagName(ID::state_PgmDataOptions);
	return pgmDataOptionsTreeStateXml.release();
}

void ProgramDataOptions::replaceState(const ValueTree& newState) {
	programDataOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
