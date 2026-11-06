#include "params_CurrentPatchOptions.h"

#include "params_Identifiers.h"
#include "params_UnexposedParameters_Facade.h"
#include "../patches/patches_Constants.h"

using namespace constants;



CurrentPatchOptions::CurrentPatchOptions(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	currentPatchOptionsTree{ ID::currentPatch_Options }
{
	fillCurrentPatchOptionsTreeWithProperties();
}

void CurrentPatchOptions::fillCurrentPatchOptionsTreeWithProperties() {
	currentPatchOptionsTree.setProperty(ID::currentPatch_Number, (uint8)0, nullptr);
	currentPatchOptionsTree.setProperty(ID::currentPatch_Name, patches::basicPatchNameString, nullptr);
}

void CurrentPatchOptions::addListener(ValueTree::Listener* listener) {
	currentPatchOptionsTree.addListener(listener);
}

void CurrentPatchOptions::removeListener(ValueTree::Listener* listener) {
	currentPatchOptionsTree.removeListener(listener);
}

const uint8 CurrentPatchOptions::currentPatchNumber() {
	return (uint8)(int)currentPatchOptionsTree.getProperty(ID::currentPatch_Number);
}

void CurrentPatchOptions::setCurrentPatchNumber(uint8 newNumber) {
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	currentPatchOptionsTree.setProperty(ID::currentPatch_Number, newNumber, undoManager);
}

const String CurrentPatchOptions::currentPatchName() {
	return currentPatchOptionsTree.getProperty(ID::currentPatch_Name);
}

void CurrentPatchOptions::setCurrentPatchName(String newName) {
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	currentPatchOptionsTree.setProperty(ID::currentPatch_Name, newName, undoManager);
}

XmlElement* CurrentPatchOptions::getStateXml() {
	auto currentPatchOptionsTreeStateXml{ currentPatchOptionsTree.createXml() };
	currentPatchOptionsTreeStateXml->setTagName(ID::state_CurrentPatchOptions);
	return currentPatchOptionsTreeStateXml.release();
}

void CurrentPatchOptions::replaceState(const ValueTree& newState) {
	currentPatchOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
