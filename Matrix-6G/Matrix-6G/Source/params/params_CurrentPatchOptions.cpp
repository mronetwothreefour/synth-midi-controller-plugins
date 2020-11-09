#include "params_CurrentPatchOptions.h"

#include "params_Identifiers.h"
#include "../params/params_UnexposedParameters_Facade.h"



CurrentPatchOptions::CurrentPatchOptions(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	currentPatchOptionsTree{ ID::currentPatch_Options }
{
	fillCurrentPatchOptionsTreeWithProperties();
}

void CurrentPatchOptions::fillCurrentPatchOptionsTreeWithProperties() {
	currentPatchOptionsTree.setProperty(ID::currentPatch_Number, (uint8)0, nullptr);
	currentPatchOptionsTree.setProperty(ID::currentPatch_Name, "MATRIX6G", nullptr);
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
	currentPatchOptionsTree.setProperty(ID::currentPatch_Number, newNumber, unexposedParams->undoManager_get());
}

const String CurrentPatchOptions::currentPatchName() {
	return currentPatchOptionsTree.getProperty(ID::currentPatch_Name);
}

void CurrentPatchOptions::setCurrentPatchName(String newName) {
	currentPatchOptionsTree.setProperty(ID::currentPatch_Name, newName, unexposedParams->undoManager_get());
}
