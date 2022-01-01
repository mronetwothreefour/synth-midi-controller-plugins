#include "params_CurrentProgramOptions.h"

#include "params_Identifiers.h"
#include "params_UnexposedParameters_Facade.h"



CurrentProgramOptions::CurrentProgramOptions(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	currentProgramOptionsTree{ ID::currentProgram_Options }
{
	fillCurrentProgramOptionsTreeWithProperties();
}

void CurrentProgramOptions::fillCurrentProgramOptionsTreeWithProperties() {
	currentProgramOptionsTree.setProperty(ID::currentProgram_Number, (uint8)0, nullptr);
}

void CurrentProgramOptions::addListener(ValueTree::Listener* listener) {
	currentProgramOptionsTree.addListener(listener);
}

void CurrentProgramOptions::removeListener(ValueTree::Listener* listener) {
	currentProgramOptionsTree.removeListener(listener);
}

const uint8 CurrentProgramOptions::currentProgramNumber() {
	return (uint8)(int)currentProgramOptionsTree.getProperty(ID::currentProgram_Number);
}

void CurrentProgramOptions::setCurrentProgramNumber(uint8 newNumber) {
	jassert(newNumber < 100);
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	currentProgramOptionsTree.setProperty(ID::currentProgram_Number, newNumber, undoManager);
}

XmlElement* CurrentProgramOptions::getStateXml() {
	auto currentPatchOptionsTreeStateXml{ currentProgramOptionsTree.createXml() };
	currentPatchOptionsTreeStateXml->setTagName(ID::state_CurrentProgramOptions);
	return currentPatchOptionsTreeStateXml.release();
}

void CurrentProgramOptions::replaceState(const ValueTree& newState) {
	currentProgramOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
