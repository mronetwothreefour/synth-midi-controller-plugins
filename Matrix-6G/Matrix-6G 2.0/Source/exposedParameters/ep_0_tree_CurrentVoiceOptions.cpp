#include "ep_0_tree_CurrentVoiceOptions.h"

#include "../constants/constants_Identifiers.h"
#include "../constants/constants_Voices.h"

using namespace Matrix_6G_Constants;

CurrentVoiceOptions::CurrentVoiceOptions(UndoManager* undoManager) :
    currentVoiceOptionsTree{ ID::tree_CurrentVoiceOptions },
    undoManager{ undoManager }
{
    currentVoiceOptionsTree.setProperty(ID::currentVoice_Number, (uint8)0, nullptr);
    currentVoiceOptionsTree.setProperty(ID::currentVoice_Name, VCS::basicVoiceNameString, nullptr);
}

const String CurrentVoiceOptions::currentVoiceName() {
    return currentVoiceOptionsTree.getProperty(ID::currentVoice_Name);
}

void CurrentVoiceOptions::setCurrentVoiceName(String newName) {
    undoManager->beginNewTransaction();
    currentVoiceOptionsTree.setProperty(ID::currentVoice_Name, newName, undoManager);
}

const uint8 CurrentVoiceOptions::currentVoiceNumber() {
    return (uint8)(int)currentVoiceOptionsTree.getProperty(ID::currentVoice_Number);
}

void CurrentVoiceOptions::setCurrentVoiceNumber(uint8 newNumber) {
    undoManager->beginNewTransaction();
    currentVoiceOptionsTree.setProperty(ID::currentVoice_Number, newNumber, undoManager);
}

Value CurrentVoiceOptions::getCurrentVoicePropertyAsValue(const Identifier propertyID) {
    return currentVoiceOptionsTree.getPropertyAsValue(propertyID, nullptr);
}

XmlElement* CurrentVoiceOptions::getStateXml() {
    auto currentVoiceOptionsTreeStateXml{ currentVoiceOptionsTree.createXml() };
    if (currentVoiceOptionsTreeStateXml != nullptr)
        currentVoiceOptionsTreeStateXml->setTagName(ID::state_CurrentVoiceOptions);
    return currentVoiceOptionsTreeStateXml.release();
}

void CurrentVoiceOptions::replaceState(const ValueTree& newState) {
    if (newState.isValid())
        currentVoiceOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
