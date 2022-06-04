#include "up_tree_RandomizationOptions.h"

#include "../constants/constants_ExposedParameters.h"
#include "../constants/constants_Identifiers.h"
#include "../exposedParameters/ep_singleton_InfoForExposedParameters.h"

using namespace MophoConstants;



RandomizationOptions::RandomizationOptions()
{
	setTransmitMethodIsSysEx();

	auto& info{ InfoForExposedParameters::get() };
	for (auto paramIndex = (uint8)0; paramIndex != EP::numberOfExposedParams; ++paramIndex) {
		randomizationOptionsTree.addChild(ValueTree{ info.IDfor(paramIndex), {}, { ValueTree{ ID::rndm_AllowedChoices } } }, paramIndex, nullptr);
		setUnlocked(paramIndex);
		auto& info{ InfoForExposedParameters::get() };
		auto numberOfChoices{ info.numberOfChoicesFor(paramIndex) };
		for (auto choiceNum = (uint8)0; choiceNum != numberOfChoices; ++choiceNum)
			allowChoiceFor(choiceNum, paramIndex);
		if (numberOfChoices == 2)
			setRepeatChoicesAreAllowedFor(paramIndex);
		else
			setRepeatChoicesAreForbiddenFor(paramIndex);
	}
}





void RandomizationOptions::addListenerToChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.addListener(listener);
}

void RandomizationOptions::removeListenerFromChildTreeForParam(ValueTree::Listener* listener, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.removeListener(listener);
}




const bool RandomizationOptions::transmitMethodIsNRPN() {
	return ((bool)randomizationOptionsTree.getProperty(ID::rndm_TransmitMethod) == transmitNRPN);
}

const bool RandomizationOptions::transmitMethodIsSysEx() {
	return ((bool)randomizationOptionsTree.getProperty(ID::rndm_TransmitMethod) == transmitSysEx);
}

void RandomizationOptions::setTransmitMethodIsNRPN() {
	randomizationOptionsTree.setProperty(ID::rndm_TransmitMethod, transmitNRPN, nullptr);
}

void RandomizationOptions::setTransmitMethodIsSysEx() {
	randomizationOptionsTree.setProperty(ID::rndm_TransmitMethod, transmitSysEx, nullptr);
}




const bool RandomizationOptions::isLocked(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamLockStatus) == locked);
}

const bool RandomizationOptions::isUnlocked(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_ParamLockStatus) == unlocked);
}

void RandomizationOptions::setLocked(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.setProperty(ID::rndm_ParamLockStatus, locked, nullptr);
}

void RandomizationOptions::setUnlocked(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.setProperty(ID::rndm_ParamLockStatus, unlocked, nullptr);
}




const bool RandomizationOptions::choiceIsAllowedFor(uint8 choiceNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == true;
}

const bool RandomizationOptions::choiceIsForbiddenFor(uint8 choiceNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	return ((bool)allowedChoices.hasProperty("choice_" + (String)choiceNum)) == false;
}

void RandomizationOptions::allowChoiceFor(uint8 choiceNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.setProperty("choice_" + (String)choiceNum, (bool)true, nullptr);
}

void RandomizationOptions::forbidChoiceFor(uint8 choiceNum, uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	auto allowedChoices{ paramTree.getChildWithName(ID::rndm_AllowedChoices) };
	allowedChoices.removeProperty("choice_" + (String)choiceNum, nullptr);
}




const bool RandomizationOptions::repeatChoicesAreAllowedFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoices) == allowed);
}

const bool RandomizationOptions::repeatChoicesAreForbiddenFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return ((bool)paramTree.getProperty(ID::rndm_RepeatChoices) == forbidden);
}

void RandomizationOptions::setRepeatChoicesAreAllowedFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.setProperty(ID::rndm_RepeatChoices, allowed, nullptr);
}

void RandomizationOptions::setRepeatChoicesAreForbiddenFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	paramTree.setProperty(ID::rndm_RepeatChoices, forbidden, nullptr);
}




const bool RandomizationOptions::onlyOneChoiceIsAllowedFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return (paramTree.getNumProperties() == 1);
}

const bool RandomizationOptions::moreThanOneChoiceIsAllowedFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return (paramTree.getNumProperties() > 1);
}

const bool RandomizationOptions::noChoiceIsAllowedFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return (paramTree.getNumProperties() == 0);
}

const bool RandomizationOptions::atLeastOneChoiceIsAllowedFor(uint8 paramIndex) {
	auto& info{ InfoForExposedParameters::get() };
	auto paramTree{ randomizationOptionsTree.getChildWithName(info.IDfor(paramIndex)) };
	return (paramTree.getNumProperties() > 0);
}

XmlElement* RandomizationOptions::getStateXml() {
	auto randomizationOptionsTreeStateXml{ randomizationOptionsTree.createXml() };
	if (randomizationOptionsTreeStateXml != nullptr)
		randomizationOptionsTreeStateXml->setTagName(ID::state_RandomizationOptions);
	return randomizationOptionsTreeStateXml.release();
}

void RandomizationOptions::replaceState(const ValueTree& newState) {
	if (newState.isValid())
		randomizationOptionsTree.copyPropertiesAndChildrenFrom(newState, nullptr);
}
