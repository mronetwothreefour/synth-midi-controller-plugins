#include "params_CurrentVoiceOptions.h"

#include "params_Identifiers.h"
#include "params_UnexposedParameters_Facade.h"
#include "..\voices\voices_Constants.h"

using namespace constants;



CurrentVoiceOptions::CurrentVoiceOptions(UnexposedParameters* unexposedParams) :
	unexposedParams{ unexposedParams },
	currentVoiceOptionsTree{ ID::currentVoice_Options }
{
	fillCurrentVoiceOptionsTreeWithProperties();
}

void CurrentVoiceOptions::fillCurrentVoiceOptionsTreeWithProperties() {
	currentVoiceOptionsTree.setProperty(ID::currentVoice_Number, (uint8)0, nullptr);
	currentVoiceOptionsTree.setProperty(ID::currentVoice_Name, voices::basicVoiceNameString, nullptr);
}

void CurrentVoiceOptions::addListener(ValueTree::Listener* listener) {
	currentVoiceOptionsTree.addListener(listener);
}

void CurrentVoiceOptions::removeListener(ValueTree::Listener* listener) {
	currentVoiceOptionsTree.removeListener(listener);
}

const uint8 CurrentVoiceOptions::currentVoiceNumber() {
	return (uint8)(int)currentVoiceOptionsTree.getProperty(ID::currentVoice_Number);
}

void CurrentVoiceOptions::setCurrentVoiceNumber(uint8 newNumber) {
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	currentVoiceOptionsTree.setProperty(ID::currentVoice_Number, newNumber, undoManager);
}

const String CurrentVoiceOptions::currentVoiceName() {
	return currentVoiceOptionsTree.getProperty(ID::currentVoice_Name);
}

void CurrentVoiceOptions::setCurrentVoiceName(String newName) {
	auto undoManager{ unexposedParams->undoManager_get() };
	undoManager->beginNewTransaction();
	currentVoiceOptionsTree.setProperty(ID::currentVoice_Name, newName, undoManager);
}

XmlElement* CurrentVoiceOptions::getStateXml() {
	auto currentVoiceOptionsTreeStateXml{ currentVoiceOptionsTree.createXml() };
	currentVoiceOptionsTreeStateXml->setTagName(ID::state_CurrentVoiceOptions);
	return currentVoiceOptionsTreeStateXml.release();
}

void CurrentVoiceOptions::replaceState(const ValueTree& newState) {
	currentVoiceOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
